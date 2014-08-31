#ifndef __XLGL_WINDOWS_INIT_H__
#define __XLGL_WINDOWS_INIT_H__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * __XLGL_CORE__ is used to make only the core library files include 
 * these functions
 * This is used for libraries or operating systems that have specific
 * init calls that the user needs to program (look at android/init.c for
 * an example)
 */
#ifdef __XLGL_CORE__
int  _xlglBuildInit();
void _xlglBuildClose();
#endif /* __XLGL_CORE__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __XLGL_WINDOWS_INIT_H__ */
