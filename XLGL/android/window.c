#define __XLGL_CORE__
#define XLGL_APP_NAME "XLGL Android Window Header"
#include <stdlib.h>

#include <android_native_app_glue.h>

#include <XLGL/xlgltypes.h>

#include "globals.h"
#include "window.h"
#include "tokens.h"
#include "logging.h"

XLGLWindow* _xlglBuildCreateNewWindow(char* title, 
        int32_t width, int32_t height, XLGLWindowAttributes att) {
    XLGLWindow* window;
    window = calloc(1, sizeof(XLGLWindow));
        if (app->window == NULL) {
        _buildLOGE("Couldn't create a new window!");
        return NULL;
    }

    userWinAtt = att;
    EGLint      num_configs,
                format;
    EGLConfig   config;

    window->display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    eglInitialize(window->display, 0, 0);
    eglChooseConfig(window->display, (int[]){
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT, 
        XLGL_RED_SIZE, att.red_bits,
        XLGL_GREEN_SIZE, att.green_bits,
        XLGL_BLUE_SIZE, att.blue_bits,
        XLGL_ALPHA_SIZE, att.alpha_bits,
        XLGL_DEPTH_SIZE, att.depth_bits,
        XLGL_STENCIL_SIZE, att.stencil_bits,
        XLGL_NONE
    }, &config, 1, &num_configs);
    eglGetConfigAttrib(window->display, config, EGL_NATIVE_VISUAL_ID, &format);

    ANativeWindow_setBuffersGeometry(app->window, 0, 0, format);

    window->win = eglCreateWindowSurface(window->display, config, 
            app->window, NULL);
    window->glcontext = eglCreateContext(window->display, config, 
            NULL, NULL);

    if (eglMakeCurrent(window->display, window->win, window->win, 
                window->glcontext) == EGL_FALSE) {
        _buildLOGE("Unable to eglMakeCurrent");
        return NULL;
    }

    eglQuerySurface(window->display, window->win, EGL_WIDTH, 
            &window->width);
    eglQuerySurface(window->display, window->win, EGL_HEIGHT, 
            &window->height);
    window->state.angle = 0;
    return window;
}

void _xlglBuildDestroyWindow(XLGLWindow* window) {
    if (window->display != EGL_NO_DISPLAY) {
        eglMakeCurrent(window->display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        if (window->glcontext != EGL_NO_CONTEXT) {
            eglDestroyContext(window->display, window->glcontext);
        }
        if (window->win != EGL_NO_SURFACE) {
            eglDestroySurface(window->display, window->win);
        }
        eglTerminate(window->display);
    }
    animating = 0;
    window->display = EGL_NO_DISPLAY;
    window->glcontext = EGL_NO_CONTEXT;
    window->win = EGL_NO_SURFACE;
    /*
     * Don't set this to close on Destroy!
     * Android treats applications differently than most operating systems.
     * On Android when you hit the home button or exit in any way the app
     * will stay in memory until another application replaces it.
     * What does this mean? This means the application will STILL be in 
     * the loop even after exiting as long as the user hasn't opened too
     * many applications since the last event sent to the app.
     * So setting this variable to '1' on android will do nothing but 
     * cause an error when the user reopens the application. Android will
     * try to act like nothing happened (but will supply new information
     * with the window etc) and continue in the loop. If This is set to
     * 1 and the loop ends in memory then depending on how the user-
     * programs their application after the loop the application could 
     * either glitch and give a 2.X themed surface or completely glitch 
     * out with errors.
     * 
     * TL;DR; Don't change the close value or else you will have errors
     */
    //window->close = 1;
}
