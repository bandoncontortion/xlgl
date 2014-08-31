#ifndef __XLGL_INIT_H__
#define __XLGL_INIT_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef XLGL_BUILD_LINUX_X11
#   include <XLGL/linux_x11/init.h>
#elif defined(__ANDROID__) 
#   include <XLGL/android/init.h>
#elif defined(XLGL_BUILD_WINDOWS)
#   include <XLGL/windows/init.h>
#endif

int  xlglInit();
void xlglClose();

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_INIT_H__ */
