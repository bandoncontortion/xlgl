#ifndef __XLGL_ANDROID_INIT_H__
#define __XLGL_ANDROID_INIT_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <android_native_app_glue.h>
void xlglSetAndroidInit(struct android_app *s);

#ifdef __XLGL_CORE__
int  _xlglBuildInit();
void _xlglBuildClose();
#endif /* __XLGL_CORE__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_ANDROID_INIT_H__ */
