#define __XLGL_CORE__
#include "globals.h"
#include "context.h"

void _xlglBuildSwapBuffers(XLGLWindow* window) {
    eglSwapBuffers(window->display, window->win);
}
