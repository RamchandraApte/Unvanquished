/*
===========================================================================

Unvanquished GPL Source Code
Copyright (C) 2014 Unvanquished Developers

This file is part of the Unvanquished GPL Source Code (Unvanquished Source Code).

Unvanquished Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Unvanquished Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Unvanquished Source Code.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#ifndef DEFEREDFREEING_COMPONENT_H_
#define DEFEREDFREEING_COMPONENT_H_

#include "../CBSEBackend.h"
#include "../CBSEComponents.h"

class DeferedFreeingComponent: public DeferedFreeingComponentBase {

	public:
		/** A logical point in time when an entity shall be freed. */
		typedef enum {
			DONT_FREE,
			FREE_AFTER_GROUP_THINKING,
			FREE_AFTER_ALL_THINKING,
		} freeTime_t;

		// ///////////////////// //
		// Autogenerated Members //
		// ///////////////////// //

		/**
		 * @brief Default constructor of the DeferedFreeingComponent.
		 * @param entity The entity that owns the component instance.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		DeferedFreeingComponent(Entity &entity);

		/**
		 * @brief Handle the FreeAt message.
		 * @param freeTime
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		void HandleFreeAt(int freeTime);

		// /////////////////// //
		// Handwritten Members //
		// /////////////////// //

		/**
		 * @return When to free the parent entity.
		 * @todo Make it return freeTime_t as soon as messages support arbitrary parameters.
		 */
		int GetFreeTime();

	private:
		// /////////////////// //
		// Handwritten Members //
		// /////////////////// //

		int freeTime; /**< When the entity shall be freed. @todo Use freeTime_t */
};

#endif // DEFEREDFREEING_COMPONENT_H_
