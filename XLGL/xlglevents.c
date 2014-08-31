#define __XLGL_CORE__
#include "xlglevents.h"

void xlglCheckEvents(XLGLWindow* window) {
    _xlglBuildCheckEvents(window);
}

int xlglRequestedClose(XLGLWindow* window) {
    return _xlglBuildRequestedClose(window);
}
