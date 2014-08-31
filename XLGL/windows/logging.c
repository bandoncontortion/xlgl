#include "logging.h"
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
void _xlglWinMsgBox(char* title, char* msg, unsigned int opts) {
    MessageBox(NULL, msg, title, opts);
}
#ifdef __cplusplus
}
#endif /* __cplusplus */
