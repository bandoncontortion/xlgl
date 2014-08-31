#define __XLGL_CORE__
#include <stdlib.h>

#include <X11/Xlib.h>
#include <GL/glx.h>

#include <XLGL/xlgltypes.h>

#include "globals.h"
#include "window.h"
#include "logging.h"
#include "tokens.h"

XLGLWindow* _xlglBuildCreateNewWindow(char* title, 
        int32_t width, int32_t height, XLGLWindowAttributes att) {
    XLGLWindow* window;
    window = calloc(1, sizeof(XLGLWindow));
    XVisualInfo             *vi;
    XSetWindowAttributes    swa;

    // Obtain the visual and make sure it isn't NULL
    if ((vi = glXChooseVisual(display, 0, 
    (int[]){
        att.pixel_type, att.doublebuffer, 
        XLGL_RED_SIZE, att.red_bits,
        XLGL_GREEN_SIZE, att.green_bits,
        XLGL_BLUE_SIZE, att.blue_bits,
        XLGL_ALPHA_SIZE, att.alpha_bits,
        GLX_ACCUM_RED_SIZE, att.accum_red_bits,
        GLX_ACCUM_GREEN_SIZE, att.accum_green_bits,
        GLX_ACCUM_BLUE_SIZE, att.accum_blue_bits,
        GLX_ACCUM_ALPHA_SIZE, att.accum_alpha_bits,
        XLGL_DEPTH_SIZE, att.depth_bits,
        GLX_STENCIL_SIZE, att.stencil_bits,
        GLX_AUX_BUFFERS, att.aux_buffers,
        XLGL_NONE
    })) == NULL) return NULL;

    swa.colormap = XCreateColormap(display, 
            DefaultRootWindow(display), vi->visual, AllocNone);
    swa.event_mask = KeyPressMask | StructureNotifyMask;

    window->width  = width;
    window->height = height;
    window->win = XCreateWindow(display, 
            DefaultRootWindow(display), 
            0, 0, 
            width, height, 
            0, vi->depth, InputOutput, vi->visual, 
            CWColormap | CWEventMask, &swa);

    XMapWindow(display, window->win);
    XStoreName(display, window->win, title);

    window->glcontext = glXCreateContext(display, vi, NULL, GL_TRUE);
    glXMakeCurrent(display, window->win, window->glcontext);

    window->wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window->win, &window->wmDeleteMessage, 1);

    XFree(vi);
    window->close = 0;
    return window;
}

void _xlglBuildDestroyWindow(XLGLWindow* window) {
    glXMakeCurrent(display, None, NULL);
    glXDestroyContext(display, window->glcontext);
    XDestroyWindow(display, window->win);
    free(window);
}
