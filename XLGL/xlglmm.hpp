/*
 * This is just a small header to make C++ programming seem a little 
 * more "native"
 */
#ifndef __XLGLMM_HPP__
#define __XLGLMM_HPP__
#include <XLGL/xlgl.h>
namespace XLGL {
    typedef XLGLWindow              Window;
    typedef XLGLWindowAttributes    WindowAttributes;
    // BEGIN xlglandroid.h
    void AndroidSetupSavedState(Window* window) {
        xlglAndroidSetupSavedState(window);
    }
    // END xlglandroid.h
    // BEGIN xlglcontext.h
    void SwapBuffers(Window* window) {
        xlglSwapBuffers(window);
    }
    // END xlglcontext.h
    // BEGIN xlglevents.h
    void CheckEvents(Window* window) {
        xlglCheckEvents(window);
    }
    int RequestedClose(Window* window) {
        return xlglRequestedClose(window);
    }
    // END xlglevents.h
    // BEGIN xlglinit.h
    int Init() {
        return xlglInit();
    }
    void Close() {
        xlglClose();
    }
    // END xlglinit.h
    // BEGIN xlglwindow.h
    Window* CreateNewWindow(char* title, 
            int32_t width, int32_t height, WindowAttributes att) {
        return xlglCreateNewWindow(title, width, height, att);
    }
    void DestroyWindow(Window* window) {
        xlglDestroyWindow(window);
    }
    // END xlglwindow.h
}
#endif /* __XLGLMM_HPP__ */
