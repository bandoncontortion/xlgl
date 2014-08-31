#ifndef __XLGL_LINUX_X11_LOGGING_H__
#define __XLGL_LINUX_X11_LOGGING_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#define _buildLOGI(__format, ...) \
         printf("[INFO]"XLGL_APP_NAME": "__format"\n", __VA_ARGS__)
#define _buildLOGW(__format, ...) \
         printf("[WARN]"XLGL_APP_NAME": "__format"\n", __VA_ARGS__)
#define _buildLOGE(__format, ...) \
         printf("[ERROR]"XLGL_APP_NAME": "__format"\n", __VA_ARGS__)

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_LINUX_X11_LOGGING_H__ */
