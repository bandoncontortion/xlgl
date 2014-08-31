#ifndef __XLGL_WINDOWS_LOGGING_H__
#define __XLGL_WINDOWS_LOGGING_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <stdlib.h>
void _xlglWinMsgBox(char* title, char* msg, unsigned int opts);
    // Freeing tmp causes errors
#define _buildLOGI(__format, ...) \
        char* tmp = (char*)calloc(1, sizeof(char*)); \
        sprintf(tmp, __format, __VA_ARGS__); \
        _xlglWinMsgBox("INFO", tmp, MB_ICONINFORMATION | MB_OK);

#define _buildLOGW(__format, ...) \
        char* tmp = (char*)calloc(1, sizeof(char*)); \
        sprintf(tmp, __format, __VA_ARGS__); \
        _xlglWinMsgBox("WARN", tmp, MB_ICONWARNING | MB_OK);

#define _buildLOGE(__format, ...) \
        char* tmp = (char*)calloc(1, sizeof(char*)); \
        sprintf(tmp, __format, __VA_ARGS__); \
        _xlglWinMsgBox("WARN", tmp, MB_ICONERROR | MB_OK);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_WINDOWS_LOGGING_H__ */
