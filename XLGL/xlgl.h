#ifndef __XLGL_H__
#define __XLGL_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <XLGL/xlgltypes.h>
#include <XLGL/xlglinit.h>
#include <XLGL/xlglwindow.h>
#include <XLGL/xlglcontext.h>
#include <XLGL/xlglevents.h>
#include <XLGL/xlgltokens.h>
#include <XLGL/xlgllogging.h>
#include <XLGL/xlglandroid.h>

/*
 * Android uses a different entry-point than other operating systems
 * This is probably bad practice but is needed for android support 
 * without requiring the user-programmer to need two entry points
 */
#if defined(__ANDROID__)
#   include <android_native_app_glue.h>
void android_main(struct android_app* s) { 
    xlglSetAndroidInit(s);
    main(0, NULL);
}
/*
 * If the user is programming for Windows we set the entry point to
 * the C Standard entry point
 */
#elif defined(_MSC_VER) || defined(_WIN32)
#   pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
#endif /* __XLGL_H__ */
