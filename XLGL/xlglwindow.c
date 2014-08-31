#define __XLGL_CORE__
#include "xlglwindow.h"

XLGLWindow* xlglCreateNewWindow(char* title, 
        int32_t width, int32_t height, XLGLWindowAttributes att) {
    return _xlglBuildCreateNewWindow(title, width, height, att);
}

void xlglDestroyWindow(XLGLWindow* window) {
    _xlglBuildDestroyWindow(window);
}
