#ifndef __XLGL_LINUX_X11_WINDOW_H__
#define __XLGL_LINUX_X11_WINDOW_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <X11/Xlib.h>
#include <GL/glx.h>

typedef struct {
    Window      win;
    GLXContext  glcontext;
    Atom        wmDeleteMessage;
    int32_t     width;
    int32_t     height;
    int         close;
} XLGLWindow;

#ifdef __XLGL_CORE__
#include <XLGL/xlgltypes.h>

XLGLWindow* _xlglBuildCreateNewWindow(char* title, 
        int32_t width, int32_t height, XLGLWindowAttributes att);
void _xlglBuildDestroyWindow(XLGLWindow* window);
#endif /* __XLGL_CORE__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_LINUX_X11_WINDOW_H__ */
