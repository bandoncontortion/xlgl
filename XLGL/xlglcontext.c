#define __XLGL_CORE__
#include "xlglcontext.h"

void xlglSwapBuffers(XLGLWindow* window) {
    _xlglBuildSwapBuffers(window);
}
