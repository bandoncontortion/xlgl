#define __XLGL_CORE__
#include <windows.h>
#include "globals.h"
#include "init.h"

LRESULT APIENTRY WndProc(HWND hWnd, UINT message, WPARAM wParam, 
            LPARAM lParam) {
    switch (message) {
        case WM_DESTROY:
            close = 1;
            return 0;
        case WM_SIZE:
            /* track window size changes */
            //if (hGLRC) {
                //winWidth = (int) LOWORD(lParam);
                //winHeight = (int) HIWORD(lParam);
                //resize();
                return 0;
            //}
        case WM_PAINT: {
            PAINTSTRUCT ps;
            BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
            return 0;
        }
        break;
        case WM_CHAR:
            /* handle keyboard input
            switch ((int)wParam) {
                case VK_ESCAPE:
                    DestroyWindow(hWnd);
                    return 0;
                default:
                    break;
            }
            */
            break;
        default: break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int _xlglBuildInit() {
    WNDCLASS wndClass;
    /* register window class */
    wndClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = GetModuleHandle(NULL);
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = GetStockObject(BLACK_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = _xlglClassName;
    RegisterClass(&wndClass);
    return 1;
}

void _xlglBuildClose() {
    PostQuitMessage(0);
}
