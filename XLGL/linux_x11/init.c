#define __XLGL_CORE__
#include <X11/Xlib.h>
#include "globals.h"
#include "init.h"

int _xlglBuildInit() {
    // Open a new display connection and make sure it isn't NULL
    if ((display = XOpenDisplay(NULL)) == NULL) return 0;
    return 1;
}

void _xlglBuildClose() {
    XCloseDisplay(display);
}
