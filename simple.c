/* This is a simple project that will call
 * functions from an external DLL */


#include <cvirte.h>    /* Needed if linking in external compiler; harmless otherwise */
#include <formatio.h>
#include <userint.h>
#include "mydll.h"

int status;
char message[80];

int main (int argc, char *argv[])
{
    if (InitCVIRTE (0, argv, 0) == 0)    /* Needed if linking in external compiler; harmless otherwise */
        return -1;    /* out of memory */
    
  
	/* Tell the dll to run it's user interface */
    Longitudinaldis= -0.4;
	Lateraldis= 0.0; 
	Verticaldis= -1.0;  
	ptich= 20;    
	roll= 10;
	yaw= 16;  
	lone=1;    
	ltwo=1;    
	lthree=1;    
	lfour=1;    
	lfive=1;    
	lsix=1;    
		
    RunDllUI();
	
    return 0;
}

