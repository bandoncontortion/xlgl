#define __XLGL_CORE__
#define XLGL_APP_NAME "XLGL Android Init Header"
#include "window.h"
#include "events.h"
#include "globals.h"
#include "init.h"
#include "logging.h"

/*
 * Allow us to pause the code until we can call init code
 */
int not_ready = 1;

void xlglSetAndroidInit(struct android_app *s) {
    app_dummy();
    app = s;
}

int32_t _xlglHandleAndroidInput(struct android_app* app, 
            AInputEvent* event) {
    if (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION) {
        animating = 1;
        //((XLGLWindow*)app->userData)->state.x = AMotionEvent_getX(event, 0);
        //((XLGLWindow*)app->userData)->state.y = AMotionEvent_getY(event, 0);
        return 1;
    }
    if (AKeyEvent_getKeyCode(event) == AKEYCODE_BACK) {
        //xlglDestroyWindow((XLGLWindow*)app->userData);
        return 1;
    }
    return 0;
}

void _xlglHandleAndroidCMD(struct android_app* app, int32_t cmd) {
    switch (cmd) {
        case APP_CMD_SAVE_STATE:
            // The system has asked us to save our current state. Do so.
            app->savedState = malloc(sizeof(struct saved_state));
            *((struct saved_state*)app->savedState) = 
                    ((XLGLWindow*)app->userData)->state;
            app->savedStateSize = sizeof(struct saved_state);
            not_ready = 1;
            break;
        case APP_CMD_INIT_WINDOW:
            if (app->window != NULL) {
                not_ready = 0;
                if ((XLGLWindow*)app->userData != NULL) {
                    XLGLWindow* tmp = _xlglBuildCreateNewWindow("Restart", 0, 0, userWinAtt);
                    ((XLGLWindow*)app->userData)->display = tmp->display;
                    ((XLGLWindow*)app->userData)->win = tmp->win;
                    ((XLGLWindow*)app->userData)->glcontext = tmp->glcontext;
                    ((XLGLWindow*)app->userData)->width = tmp->width;
                    ((XLGLWindow*)app->userData)->height = tmp->height;
                    free(tmp);
                }
            }
            break;
        case APP_CMD_TERM_WINDOW:
            _xlglBuildDestroyWindow((XLGLWindow*)app->userData);
            break;
        case APP_CMD_GAINED_FOCUS: 
            animating = 1;
            break;
        case APP_CMD_LOST_FOCUS:
            animating = 0;
            break;
    }
}

int _xlglBuildInit() {
    app->onAppCmd = _xlglHandleAndroidCMD;
    app->onInputEvent = _xlglHandleAndroidInput;
    while (not_ready) {
        /* Wait until we're ready to load */ 
        _buildLOGI("Waiting for window...");
        _xlglBuildCheckEvents(NULL);
    }
    return 1;
}

void _xlglBuildClose() {
    app->savedState = NULL;
    ANativeActivity_finish(app->activity);
}
