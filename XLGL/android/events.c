#define __XLGL_CORE__
#include "globals.h"
#include "events.h"
#include "window.h"

void _xlglBuildCheckEvents(XLGLWindow* window) {
    int ident;
    int events;
    struct android_poll_source* source;

    // If not animating, we will block forever waiting for events.
    // If animating, we loop until all events are read, then continue
    // to draw the next frame of animation.
    while ((ident = ALooper_pollAll(animating ? 0 : -1, NULL, &events,
            (void**)&source)) >= 0 || !animating) {

        // Process this event.
        if (source != NULL) {
            source->process(app, source);
        }

        // Check if we are exiting.
        if (app->destroyRequested != 0) {
            _xlglBuildDestroyWindow(window);
            return;
        }
    }
    free(source);
}

int _xlglBuildRequestedClose(XLGLWindow* window) {
    return window->close;
}
