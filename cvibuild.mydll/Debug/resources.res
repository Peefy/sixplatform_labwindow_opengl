        ��  ��                  �       �� ��     0 	        <?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0" />�      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                 ?                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 b 0   4 
  C o m p a n y N a m e     W i c r o s o f t   L   F i l e D e s c r i p t i o n     m y d l l   ( D e b u g   x 8 6 )   (   F i l e V e r s i o n     1 . 0   ,   I n t e r n a l N a m e   m y d l l   X   L e g a l C o p y r i g h t   C o p y r i g h t   ? W i c r o s o f t   2 0 1 7   < 
  O r i g i n a l F i l e n a m e   m y d l l . d l l   @   P r o d u c t N a m e     W i c r o s o f t   m y d l l   ,   P r o d u c t V e r s i o n   1 . 0   D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�]
  X   C V I D L L P R O T O T Y P E S   C V I D L L E X P O R T S         0 	        int CloseUICallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int DllEntryPoint(struct HINSTANCE__ *hinstDLL, unsigned long fdwReason, void *lpvReserved);
int DllMain(struct HINSTANCE__ *hinstDLL, unsigned long fdwReason, void *lpvReserved);
void DrawBall(float radius, float red, float blue, float green);
void DrawBanFormThreePoints(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
void DrawCubeWithColor(float length, float r, float b, float g);
void DrawCylinder(float baseRadius, float height);
void DrawCylinderWithTwoColors(float baseRadius, float heightBlue, float heightWhite);
void DrawCylinderWithTwoPoints(float x1, float y1, float z1, float x2, float y2, float z2, float blueHeight, float baseRadius, int isJudgeAngleY);
void DrawSolidBoxWithColor(float a, float b, float c, float red, float blue, float green);
void GetCenterPointFromThreePoints(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float *center_x, float *center_y, float *center_z);
long MyDLLCdeclFunction(char *buffer) __declspec(dllexport);
long MyDLLStdcallFunction(char *buffer) __declspec(dllexport);
void MyFrameDisplayWithRotate();
int OGLCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int OnclickBtEsc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int OnclickBtOK(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int OpenGLControlInit(int panelHandle, int pictureBox);
void OpenGL_SetPitch(double angle);
void OpenGL_SetRoll(double angle);
void OpenGL_SetYaw(double angle);
void OpenglCtrlDispose();
void OpenglCtrlInit();
void PointRotatef(float angle, float x, float y, float z, float old_x, float old_y, float old_z, float *new_x, float *new_y, float *new_z);
void PointRotatef_X(float angle, float old_x, float old_y, float old_z, float *new_x, float *new_y, float *new_z);
void PointRotatef_Y(float angle, float old_x, float old_y, float old_z, float *new_x, float *new_y, float *new_z);
void PointRotatef_Z(float angle, float old_x, float old_y, float old_z, float *new_x, float *new_y, float *new_z);
void PointTrans_XYZ(float dis_x, float dis_y, float dis_z, float old_x, float old_y, float old_z, float *new_x, float *new_y, float *new_z);
void RenderImage(int fastFlag);
void RunDllUI() __declspec(dllexport);
int panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int timer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
            �� ��     0	                                        