/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */
 
#include "precompiled.h"
#include <Rocket/Core/Lua/Interpreter.h>
#include <Rocket/Core/Lua/Utilities.h>
#include <Rocket/Core/Log.h>
#include <Rocket/Core/String.h>
#include <Rocket/Core/FileInterface.h>
#include <Rocket/Core/Lua/LuaType.h>
#include "LuaDocumentElementInstancer.h"
#include <Rocket/Core/Factory.h>
#include "LuaEventListenerInstancer.h"
#include "Rocket.h"
//the types I made
#include "ContextDocumentsProxy.h"
#include "EventParametersProxy.h"
#include "ElementAttributesProxy.h"
#include "Log.h"
#include "Element.h"
#include "ElementStyleProxy.h"
#include "Document.h"
#include "Colourb.h"
#include "Colourf.h"
#include "Vector2f.h"
#include "Vector2i.h"
#include "Context.h"
#include "Event.h"
#include "ElementInstancer.h"
#include "ElementChildNodesProxy.h"
#include "ElementText.h"
#include "GlobalLuaFunctions.h"
#include "RocketContextsProxy.h"

namespace Rocket {
namespace Core {
namespace Lua {
lua_State* Interpreter::L_ = NULL;
//typedefs for nicer Lua names
typedef Rocket::Core::ElementDocument Document;

void Interpreter::Startup()
{
	if(L_ == NULL)
	{
		Log::Message(Log::LT_INFO, "Loading Lua interpreter");
		L_ = luaL_newstate();
		luaL_openlibs(L_);
	}
    RegisterCoreTypes(L_);
}


void Interpreter::RegisterCoreTypes(lua_State* L)
{
    LuaType<Vector2i>::Register(L);
    LuaType<Vector2f>::Register(L);
    LuaType<Colourf>::Register(L);
    LuaType<Colourb>::Register(L);
    LuaType<Log>::Register(L);
    LuaType<ElementStyleProxy>::Register(L);
    LuaType<Element>::Register(L);
        //things that inherit from Element
        LuaType<Document>::Register(L);
        LuaType<ElementText>::Register(L);
    LuaType<Event>::Register(L);
    LuaType<Context>::Register(L);
    LuaType<LuaRocket>::Register(L);
    LuaType<ElementInstancer>::Register(L);
    //Proxy tables
    LuaType<ContextDocumentsProxy>::Register(L);
    LuaType<EventParametersProxy>::Register(L);
    LuaType<ElementAttributesProxy>::Register(L);
    LuaType<ElementChildNodesProxy>::Register(L);
    LuaType<RocketContextsProxy>::Register(L);
    OverrideLuaGlobalFunctions(L);
    //push the global variable "rocket" to use the "Rocket" methods
    LuaRocketPushrocketGlobal(L);
}



void Interpreter::LoadFile(const String& file)
{
    //use the file interface to get the contents of the script
    Rocket::Core::FileInterface* file_interface = Rocket::Core::GetFileInterface();
    Rocket::Core::FileHandle handle = file_interface->Open(file);
    if(handle == 0) {
        lua_pushfstring(L_, "LoadFile: Unable to open file: %s", file.CString());
        Report(L_);
        return;
    }

    size_t size = file_interface->Length(handle);
    if(size == 0) {
        lua_pushfstring(L_, "LoadFile: File is 0 bytes in size: %s", file.CString());
        Report(L_);
        return;
    }
    char* file_contents = new char[size];
    file_interface->Read(file_contents,size,handle);
    file_interface->Close(handle);

    if(luaL_loadbuffer(L_,file_contents,size,file.CString()) != 0)
        Report(L_); 
    else //if there were no errors loading, then the compiled function is on the top of the stack
    {
        if(lua_pcall(L_,0,0,0) != 0)
            Report(L_);
    }

    delete[] file_contents;
}


void Interpreter::DoString(const Rocket::Core::String& code, const Rocket::Core::String& name)
{
    if(luaL_loadbuffer(L_,code.CString(),code.Length(), name.CString()) != 0)
        Report(L_);
    else
    {
        if(lua_pcall(L_,0,0,0) != 0)
            Report(L_);
    }
}

void Interpreter::LoadString(const Rocket::Core::String& code, const Rocket::Core::String& name)
{
    if(luaL_loadbuffer(L_,code.CString(),code.Length(), name.CString()) != 0)
        Report(L_);
}


void Interpreter::BeginCall(int funRef)
{
    lua_settop(L_,0); //empty stack
    //lua_getref(L_,funRef);
    lua_rawgeti(L_, LUA_REGISTRYINDEX, (int)funRef);
}

bool Interpreter::ExecuteCall(int params, int res)
{
    bool ret = true;
    int top = lua_gettop(L_);
    if(lua_type(L_,top-params) != LUA_TFUNCTION)
    {
        ret = false;
        //stack cleanup
        if(params > 0)
        {
            for(int i = top; i >= (top-params); i--)
            {
                if(!lua_isnone(L_,i))
                    lua_remove(L_,i);
            }
        }
    }
    else
    {
        if(lua_pcall(L_,params,res,0) != 0)
        {
            Report(L_);
            ret = false;
        }
    }
    return ret;
}

void Interpreter::EndCall(int res)
{
    //stack cleanup
    for(int i = res; i > 0; i--)
    {
        if(!lua_isnone(L_,res))
            lua_remove(L_,res);
    }
}

lua_State* Interpreter::GetLuaState() { return L_; }


//From Plugin
int Interpreter::GetEventClasses()
{
    return EVT_BASIC;
}

void Interpreter::OnInitialise()
{
    Startup();
    Factory::RegisterElementInstancer("body",new LuaDocumentElementInstancer())->RemoveReference();
    Factory::RegisterEventListenerInstancer(new LuaEventListenerInstancer())->RemoveReference();
}

void Interpreter::OnShutdown()
{
}

void Interpreter::Initialise()
{
    Rocket::Core::Lua::Interpreter::Initialise(NULL);
}

void Interpreter::Initialise(lua_State *luaStatePointer)
{
	Interpreter *iPtr = new Interpreter();
	iPtr->L_ = luaStatePointer;
	Rocket::Core::RegisterPlugin(iPtr);
}

void Interpreter::Shutdown()
{
	lua_close(L_);
}




}
}
}
