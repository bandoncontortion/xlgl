#define __XLGL_CORE__
#include <windows.h>
#include "globals.h"
#include "context.h"

void _xlglBuildSwapBuffers(XLGLWindow* window) {
    SwapBuffers(window->hDC);
}
