#ifndef __XLGL_ANDROID_WINDOW_H__
#define __XLGL_ANDROID_WINDOW_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <EGL/egl.h>

struct saved_state {
    float angle;
    int32_t x;
    int32_t y;
};

typedef struct {
    EGLDisplay display;
    EGLSurface win;
    EGLContext glcontext;
    struct saved_state state;
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
#endif /* __XLGL_ANDROID_WINDOW_H__ */
