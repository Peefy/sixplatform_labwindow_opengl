#include <cvidef.h>
          /*    Here are the function prototypes suitable for including in a
                program which uses the dll. */

extern long int DLLIMPORT __stdcall MyDLLStdcallFunction(char * dummycharname);
extern long int DLLIMPORT __stdcall MyDLLCdeclFunction(char * dummycharname);
extern void DLLIMPORT _stdcall RunDllUI (void);

extern double DLLIMPORT Longitudinaldis;
extern double DLLIMPORT Lateraldis; 
extern double DLLIMPORT Verticaldis;  
extern double DLLIMPORT ptich;    
extern double DLLIMPORT roll;
extern double DLLIMPORT yaw;  
extern double DLLIMPORT lone;    
extern double DLLIMPORT ltwo;    
extern double DLLIMPORT lthree;    
extern double DLLIMPORT lfour;    
extern double DLLIMPORT lfive;    
extern double DLLIMPORT lsix;    


