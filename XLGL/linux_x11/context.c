#define __XLGL_CORE__
#include <X11/Xlib.h>
#include "globals.h"
#include "context.h"

void _xlglBuildSwapBuffers(XLGLWindow* window) {
    glXSwapBuffers(display, window->win);
}
