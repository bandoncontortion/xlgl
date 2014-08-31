#ifndef __XLGL_ANDROID_GLOBALS_H__
#define __XLGL_ANDROID_GLOBALS_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __XLGL_CORE__
#   include <android_native_app_glue.h>
#   include <XLGL/xlgltypes.h>
extern int animating;
extern struct android_app* app;
extern XLGLWindowAttributes userWinAtt;
#endif /* __XLGL_CORE__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_ANDROID_GLOBALS_H__ */
