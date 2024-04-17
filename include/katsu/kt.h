/*
 * kt.h
 */


#ifndef __KT_H__
#define __KT_H__

#include <katsu/types.h>
#include <katsu/audio.h>
#include <katsu/video.h>
#include <katsu/gfx.h>
#include <katsu/joypad.h>

/*Error codes*/
#define KT_OK					0x00000000u
#define KT_ERROR_NO_WINDOW		0x00000001u
#define KT_ERROR_NO_JOYPAD		0x00000002u
#define KT_ERROR_NO_AUDIO		0x00000003u


enum KtExitCode {
	KT_EXIT,
	KT_EXIT_CANCEL,
	KT_EXIT_MALX_CODES
};

typedef u32 (*KTExitFunc)(u32 status);

/*Main Katsun functions*/
u32 kt_Init(void);
void kt_ExitFuncSet(KTExitFunc func);
void kt_Exit(u32 exit_code);
void kt_Poll(void);
void kt_Draw(void);




#endif /*__KT_H__*/