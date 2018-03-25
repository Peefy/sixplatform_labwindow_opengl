/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_LongitudinalDis            2       /* control type: scale, callback function: (none) */
#define  PANEL_Yaw                        3       /* control type: scale, callback function: (none) */
#define  PANEL_Roll                       4       /* control type: scale, callback function: (none) */
#define  PANEL_Ptich                      5       /* control type: scale, callback function: (none) */
#define  PANEL_VerticalDis                6       /* control type: scale, callback function: (none) */
#define  PANEL_LateralDis                 7       /* control type: scale, callback function: (none) */
#define  PANEL_L5                         8       /* control type: scale, callback function: (none) */
#define  PANEL_L4                         9       /* control type: scale, callback function: (none) */
#define  PANEL_L6                         10      /* control type: scale, callback function: (none) */
#define  PANEL_L3                         11      /* control type: scale, callback function: (none) */
#define  PANEL_L2                         12      /* control type: scale, callback function: (none) */
#define  PANEL_L1                         13      /* control type: scale, callback function: (none) */
#define  PANEL_BTEsc                      14      /* control type: command, callback function: OnclickBtEsc */
#define  PANEL_BTOK                       15      /* control type: command, callback function: OnclickBtOK */
#define  PANEL_TIMER                      16      /* control type: timer, callback function: timer */
#define  PANEL_STRIPCHART                 17      /* control type: strip, callback function: (none) */
#define  PANEL_PICTURE                    18      /* control type: picture, callback function: (none) */


     /* Control Arrays: */

#define  CTRLARRAY                        1

     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK OnclickBtEsc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnclickBtOK(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK timer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
