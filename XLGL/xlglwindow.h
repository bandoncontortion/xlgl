#ifndef __XLGL_WINDOW_H__
#define __XLGL_WINDOW_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <inttypes.h>
#include <XLGL/xlgltypes.h>

#ifdef XLGL_BUILD_LINUX_X11
#   include <XLGL/linux_x11/window.h>
#elif defined(__ANDROID__) 
#   include <XLGL/android/window.h>
#elif defined(XLGL_BUILD_WINDOWS)
#   include <XLGL/windows/window.h>
#endif

XLGLWindow* xlglCreateNewWindow(char* title, 
        int32_t width, int32_t height, XLGLWindowAttributes att);
void xlglDestroyWindow(XLGLWindow* window);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_WINDOW_H__ */
