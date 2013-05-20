; Generated file. Do not edit.
; To update, run src/utils/scan_api.sh

code

equ memset                                -1
equ memcpy                                -2
equ memcmp                                -3
equ strncpy                               -4
equ sin                                   -5
equ cos                                   -6
equ asin                                  -7
equ tanf                                  -8
equ atanf                                 -9
equ atan2                                 -10
equ sqrt                                  -11
equ floor                                 -12
equ ceil                                  -13
equ exp                                   -14
equ trap_SyscallABIVersion                -256
equ trap_Print                            -257
equ trap_Error                            -258
equ trap_Log                              -259
equ trap_Milliseconds                     -260
equ trap_Cvar_Register                    -261
equ trap_Cvar_Update                      -262
equ trap_Cvar_Set                         -263
equ trap_Cvar_VariableStringBuffer        -264
equ trap_Cvar_LatchedVariableStringBuffer -265
equ trap_Cvar_VariableIntegerValue        -266
equ trap_Argc                             -267
equ trap_Argv                             -268
equ trap_Args                             -269
equ trap_LiteralArgs                      -270
equ trap_GetDemoState                     -271
equ trap_GetDemoPos                       -272
equ trap_FS_FOpenFile                     -273
equ trap_FS_Read                          -274
equ trap_FS_Write                         -275
equ trap_FS_FCloseFile                    -276
equ trap_FS_GetFileList                   -277
equ trap_FS_Delete                        -278
equ trap_SendConsoleCommand               -279
equ trap_AddCommand                       -280
equ trap_RemoveCommand                    -281
equ trap_SendClientCommand                -282
equ trap_UpdateScreen                     -283
equ trap_CM_LoadMap                       -284
equ trap_CM_NumInlineModels               -285
equ trap_CM_InlineModel                   -286
equ trap_CM_TempBoxModel                  -287
equ trap_CM_TempCapsuleModel              -288
equ trap_CM_PointContents                 -289
equ trap_CM_TransformedPointContents      -290
equ trap_CM_BoxTrace                      -291
equ trap_CM_TransformedBoxTrace           -292
equ trap_CM_CapsuleTrace                  -293
equ trap_CM_TransformedCapsuleTrace       -294
equ trap_CM_BiSphereTrace                 -295
equ trap_CM_TransformedBiSphereTrace      -296
equ trap_CM_MarkFragments                 -297
equ trap_R_ProjectDecal                   -298
equ trap_R_ClearDecals                    -299
equ trap_S_StartSound                     -300
equ trap_S_StartSoundVControl             -300
equ trap_S_StartSoundEx                   -301
equ trap_S_StartLocalSound                -302
equ trap_S_ClearLoopingSounds             -303
equ trap_S_ClearSounds                    -304
equ trap_S_AddLoopingSound                -305
equ trap_S_AddRealLoopingSound            -306
equ trap_S_StopLoopingSound               -307
equ trap_S_StopStreamingSound             -308
equ trap_S_UpdateEntityPosition           -309
equ trap_S_GetVoiceAmplitude              -310
equ trap_S_GetSoundLength                 -311
equ trap_S_GetCurrentSoundTime            -312
equ trap_S_Respatialize                   -313
equ trap_S_RegisterSound                  -314
equ trap_S_StartBackgroundTrack           -315
equ trap_S_FadeBackgroundTrack            -316
equ trap_S_StartStreamingSound            -317
equ trap_R_LoadWorldMap                   -318
equ trap_R_RegisterModel                  -319
equ trap_R_RegisterSkin                   -320
equ trap_R_GetSkinModel                   -321
equ trap_R_GetShaderFromModel             -322
equ trap_R_RegisterShader                 -323
equ trap_R_RegisterFont                   -324
equ trap_R_ClearScene                     -327
equ trap_R_AddRefEntityToScene            -328
equ trap_R_AddRefLightToScene             -329
equ trap_R_AddPolyToScene                 -330
equ trap_R_AddPolysToScene                -331
equ trap_R_AddPolyBufferToScene           -332
equ trap_R_AddLightToScene                -333
equ trap_R_AddAdditiveLightToScene        -334
equ trap_GS_FS_Seek                       -335
equ trap_R_AddCoronaToScene               -336
equ trap_R_SetFog                         -337
equ trap_R_SetGlobalFog                   -338
equ trap_R_RenderScene                    -339
equ trap_R_SaveViewParms                  -340
equ trap_R_RestoreViewParms               -341
equ trap_R_SetColor                       -342
equ trap_R_SetClipRegion                  -343
equ trap_R_DrawStretchPic                 -344
equ trap_R_DrawRotatedPic                 -345
equ trap_R_DrawStretchPicGradient         -346
equ trap_R_Add2dPolys                     -347
equ trap_R_ModelBounds                    -348
equ trap_R_LerpTag                        -349
equ trap_GetGlconfig                      -350
equ trap_GetGameState                     -351
equ trap_GetCurrentSnapshotNumber         -352
equ trap_GetSnapshot                      -353
equ trap_GetServerCommand                 -354
equ trap_GetCurrentCmdNumber              -355
equ trap_GetUserCmd                       -356
equ trap_SetUserCmdValue                  -357
equ trap_SetClientLerpOrigin              -358
equ trap_MemoryRemaining                  -359
equ trap_Key_IsDown                       -360
equ trap_Key_GetCatcher                   -361
equ trap_Key_SetCatcher                   -362
equ trap_Key_GetKey                       -363
equ trap_Key_GetOverstrikeMode            -364
equ trap_Key_SetOverstrikeMode            -365
equ trap_PC_AddGlobalDefine               -366
equ trap_PC_LoadSource                    -367
equ trap_PC_FreeSource                    -368
equ trap_PC_ReadToken                     -369
equ trap_PC_SourceFileAndLine             -370
equ trap_PC_UnReadToken                   -371
equ trap_S_StopBackgroundTrack            -372
equ trap_RealTime                         -373
equ trap_SnapVector                       -374
equ trap_CIN_PlayCinematic                -375
equ trap_CIN_StopCinematic                -376
equ trap_CIN_RunCinematic                 -377
equ trap_CIN_DrawCinematic                -378
equ trap_CIN_SetExtents                   -379
equ trap_R_RemapShader                    -380
equ trap_GetEntityToken                   -381
equ trap_UI_Popup                         -382
equ trap_UI_ClosePopup                    -383
equ trap_Key_GetBindingBuf                -384
equ trap_Key_SetBinding                   -385
equ trap_Parse_AddGlobalDefine            -386
equ trap_Parse_LoadSource                 -387
equ trap_Parse_FreeSource                 -388
equ trap_Parse_ReadToken                  -389
equ trap_Parse_SourceFileAndLine          -390
equ trap_Key_KeynumToStringBuf            -391
equ trap_S_FadeAllSound                   -392
equ trap_R_inPVS                          -393
equ trap_GetHunkData                      -394
equ trap_R_LoadDynamicShader              -395
equ trap_R_RenderToTexture                -396
equ trap_R_GetTextureId                   -397
equ trap_R_Finish                         -398
equ trap_GetDemoName                      -399
equ trap_R_LightForPoint                  -400
equ trap_S_SoundDuration                  -401
equ trap_R_RegisterAnimation              -402
equ trap_R_CheckSkeleton                  -403
equ trap_R_BuildSkeleton                  -404
equ trap_R_BlendSkeleton                  -405
equ trap_R_BoneIndex                      -406
equ trap_R_AnimNumFrames                  -407
equ trap_R_AnimFrameRate                  -408
equ trap_CompleteCallback                 -409
equ trap_RegisterButtonCommands           -410
equ trap_GetClipboardData                 -411
equ trap_QuoteString                      -412
equ trap_Gettext                          -413
equ trap_R_Glyph                          -414
equ trap_R_GlyphChar                      -415
equ trap_R_UnregisterFont                 -416
equ trap_Pgettext                         -417
equ trap_R_inPVVS                         -418
equ trap_notify_onTeamChange              -419
equ trap_GettextPlural                    -420
equ trap_RegisterVisTest                  -421
equ trap_AddVisTestToScene                -422
equ trap_CheckVisibility                  -423
equ trap_UnregisterVisTest                -424
equ trap_SetColorGrading                  -425
equ trap_CM_DistanceToModel               -426
equ trap_R_ScissorEnable                  -427
equ trap_R_ScissorSet                     -428
