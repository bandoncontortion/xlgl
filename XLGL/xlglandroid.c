#ifdef __ANDROID__
#   define __XLGL_CORE__
#   include "android/globals.h"
#   undef __XLGL_CORE__
#endif
#include "xlglwindow.h"
#include "xlglandroid.h"

void xlglAndroidSetupSavedState(XLGLWindow* window) {
#ifdef __ANDROID__
    app->userData = window;

    if (app->savedState != NULL) {
        // We are starting with a previous saved state; restore from it.
        window->state = *(struct saved_state*)app->savedState;
    }
#endif
}
