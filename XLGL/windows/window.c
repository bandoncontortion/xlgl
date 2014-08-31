#define __XLGL_CORE__
#include <stdlib.h>

#include <XLGL/xlgltypes.h>

#define GLEW_NO_GLU
#define GLEW_STATIC
#include <GL/glew.h>

#include "globals.h"
#include "window.h"
#include "logging.h"
#include "tokens.h"

void setupPixelFormat(XLGLWindow* window, XLGLWindowAttributes att) {
    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),  /* size */
        1,                              /* version */
        PFD_SUPPORT_OPENGL |
        PFD_DRAW_TO_WINDOW |
        att.doublebuffer,               /* support double-buffering */
        att.pixel_type,                 /* color type */
        att.color_bits,                 /* prefered color depth */
        /* color bits (ignored?) */
        att.red_bits, att.red_shift, att.green_bits, att.green_shift, 
        att.blue_bits, att.blue_shift, att.alpha_bits, att.alpha_shift,
        att.accum_bits,                 /* no accumulation buffer */
        /* accum bits (ignored) */
        att.accum_red_bits, att.accum_green_bits, 
        att.accum_blue_bits, att.accum_alpha_bits,
        att.depth_bits,                 /* depth buffer */
        att.stencil_bits,               /* no stencil buffer */
        att.aux_buffers,                /* no auxiliary buffers */
        PFD_MAIN_PLANE,                 /* main layer */
        0,                              /* reserved */
        0, 0, 0,                        /* no layer, visible, damage masks */
    };
    int pixelFormat;

    pixelFormat = ChoosePixelFormat(window->hDC, &pfd);
    if (pixelFormat == 0) {
        _buildLOGE("%s", "ChoosePixelFormat failed.");
        exit(1);
    }

    if (SetPixelFormat(window->hDC, pixelFormat, &pfd) != TRUE) {
        _buildLOGE("%s", "SetPixelFormat failed.");
        exit(1);
    }
}

void setupPalette(XLGLWindow* window) {
    int pixelFormat = GetPixelFormat(window->hDC);
    PIXELFORMATDESCRIPTOR pfd;
    LOGPALETTE* pPal;
    int paletteSize;

    DescribePixelFormat(window->hDC, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

    if (pfd.dwFlags & PFD_NEED_PALETTE) {
        paletteSize = 1 << pfd.cColorBits;
    } else {
        return;
    }

    pPal = (LOGPALETTE*)
        malloc(sizeof(LOGPALETTE) + paletteSize * sizeof(PALETTEENTRY));
    pPal->palVersion = 0x300;
    pPal->palNumEntries = paletteSize;

    /* build a simple RGB color palette */
    {
        int redMask = (1 << pfd.cRedBits) - 1;
        int greenMask = (1 << pfd.cGreenBits) - 1;
        int blueMask = (1 << pfd.cBlueBits) - 1;
        int i;

        for (i=0; i<paletteSize; ++i) {
            pPal->palPalEntry[i].peRed =
                    (((i >> pfd.cRedShift) & redMask) * 255) / redMask;
            pPal->palPalEntry[i].peGreen =
                    (((i >> pfd.cGreenShift) & greenMask) * 255) / greenMask;
            pPal->palPalEntry[i].peBlue =
                    (((i >> pfd.cBlueShift) & blueMask) * 255) / blueMask;
            pPal->palPalEntry[i].peFlags = 0;
        }
    }

    window->hPalette = CreatePalette(pPal);
    free(pPal);

    if (window->hPalette) {
        SelectPalette(window->hDC, window->hPalette, FALSE);
        RealizePalette(window->hDC);
    }
}

XLGLWindow* _xlglBuildCreateNewWindow(char* title, 
        int32_t width, int32_t height, XLGLWindowAttributes att) {
    XLGLWindow* window;
    window = calloc(1, sizeof(XLGLWindow));
    window->win = CreateWindow(
        _xlglClassName, title,
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
        0, 0, width, height,
        NULL, NULL, GetModuleHandle(NULL), NULL);

    /* initialize OpenGL rendering */
    window->hDC = GetDC(window->win);
    setupPixelFormat(window, att);
    setupPalette(window);
    window->glcontext = wglCreateContext(window->hDC);
    wglMakeCurrent(window->hDC, window->glcontext);

    /* display window */
    ShowWindow(window->win, SW_SHOW);
    glewInit();
    return window;
}

void _xlglBuildDestroyWindow(XLGLWindow* window) {
    if (window->glcontext) {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(window->glcontext);
    }
    if (window->hPalette) {
        DeleteObject(window->hPalette);
    }
    ReleaseDC(window->win, window->hDC);
    free(window);
}
