#define __XLGL_CORE__
#include <X11/Xlib.h>
#include "globals.h"
#include "events.h"

void _xlglBuildCheckEvents(XLGLWindow* window) {
    // Use the XPending so we can have ASynchronous event handling
    if (XPending(display)) {
        XEvent event;
        XNextEvent(display, &event);

        switch (event.type) {
            case ClientMessage: {
                if (event.xclient.data.l[0] == window->wmDeleteMessage){ 
                    window->close = 1; 
                }
                break;
            }
            case ConfigureNotify: {
                XConfigureEvent xce = event.xconfigure;
                if (xce.width  != window->width ||
                    xce.height != window->height) {
                    window->width  = xce.width;
                    window->height = xce.height;
                }
                break;
            }
            // Not needed?...
            default: break;
        }
    }
}

int _xlglBuildRequestedClose(XLGLWindow* window) {
    return window->close;
}
