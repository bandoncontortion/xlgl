#define __XLGL_CORE__
#include "globals.h"
#include "events.h"

void _xlglBuildCheckEvents(XLGLWindow* window) {
    /*
     * Check for events on windows asynchronously
     */
    if (PeekMessage(&window->msg, NULL, 0, 0, PM_REMOVE) == TRUE) {
        TranslateMessage(&window->msg);
        DispatchMessage(&window->msg);
    }
    if (close == 1) {
        window->close = 1;
        close = 0;
    }
}

int _xlglBuildRequestedClose(XLGLWindow* window) {
    return window->close;
}
