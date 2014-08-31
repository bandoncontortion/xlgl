#ifndef __XLGL_CONTEXT_H__
#define __XLGL_CONTEXT_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef XLGL_BUILD_LINUX_X11
#   include <XLGL/linux_x11/context.h>
#elif defined(__ANDROID__) 
#   include <XLGL/android/context.h>
#elif defined(XLGL_BUILD_WINDOWS)
#   include <XLGL/windows/context.h>
#endif

void xlglSwapBuffers(XLGLWindow* window);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_CONTEXT_H__ */
