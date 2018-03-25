/* A simple example of using a uir in a dll created both in cvi or an
 * external compiler.
 */

/* Include files needed to compile DLL */
#include <windows.h>
#include "cviogl.h"
#include <ansi_c.h>
#include <cvirte.h>     /* needed if linking DLL in external compiler; harmless otherwise */
#include <userint.h>
#include "dlluir.h"

#include "openGL_helper.h"

static long int status = 0;
static int lightVal = 0, panelHandle;
static int lightVal2=0;
double Rec=0;
double numberLongd[500] = {0};
double numberLated[500] =  {0};
double numberVercad[500] = {0};
double numberpitchd[500]= {0};
double numberrolld[500] = {0};
double numberyawd[500]= {0};   

double scale_min = -2;
double scale_max = 2;

int rear = 0;

double display [6]={0};

double DLLEXPORT kao=4;   
double DLLEXPORT Longitudinaldis;
double DLLEXPORT Lateraldis; 
double DLLEXPORT Verticaldis;  
double DLLEXPORT ptich;    
double DLLEXPORT roll;
double DLLEXPORT yaw;  
double DLLEXPORT lone;    
double DLLEXPORT ltwo;    
double DLLEXPORT lthree;    
double DLLEXPORT lfour;    
double DLLEXPORT lfive;    
double DLLEXPORT lsix;    

int j;   
double count =0.00; 
int flag = 0;


///openGL
float Tran_X;
float Tran_Y; 
float Tran_Z; 

static int OpenglCtrl = 0;
void OpenglCtrlInit(void);   
void OpenglCtrlDispose(void);
int CVICALLBACK OGLCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2); 


double find_six_max(double num1,double num2,double num3,double num4,double num5,double num6)
{
	return -1;
}

void OpenglCtrlInit(void)
{
	OpenglCtrl = OpenGLControlInit (panelHandle, PANEL_PICTURE);
	InstallCtrlCallback (panelHandle, OpenglCtrl, OGLCallback, 0); 
	OGLRefreshGraph (panelHandle, OpenglCtrl);  
}

void OpenglCtrlDispose(void)
{   
	OGLDiscardCtrl (panelHandle, OpenglCtrl); 

}

int CVICALLBACK OGLCallback (int panel, int control, int event, 
	void *callbackData, int eventData1, int eventData2) 
{ 

	switch (event) 
	{ 
		case OGLEVENT_REFRESH:
			RenderImage(0);
			break; 
	} 

	return 0; 

}

///end OpenGL

BOOL __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
     /* The DllMain function is called when ever the DLL is loaded and    */
     /* unloaded. Place Initialization code for the DLL in this function. */
    if (fdwReason == DLL_PROCESS_ATTACH) {
        /* Place any initialization which needs to be done when the DLL */
        /* is loaded here. */
        if (InitCVIRTE (hinstDLL, 0, 0) == 0)       /* needed if linking DLL in external compiler; harmless otherwise */
            return 0;   /* out of memory */
            status = 100;
    } else if (fdwReason == DLL_PROCESS_DETACH) {
        /* Place any clean-up which needs to be done when the DLL */
        /* is unloaded here. */
        CloseCVIRTE ();     /* needed if linking DLL in external compiler; harmless otherwise */
    }
    /* return FALSE to abort if initialization fails */
    return TRUE;
}

BOOL __stdcall DllEntryPoint (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    return DllMain(hinstDLL, fdwReason, lpvReserved);
}
  
void DLLEXPORT RunDllUI (void)
{
    /* Call this function from the appropriate place in your code */
    /* to load and display startup panels.                        */

    panelHandle = LoadPanelEx (0, "dlluir.uir", PANEL, __CVIUserHInst);
	OpenglCtrlInit();
    DisplayPanel (panelHandle);
	
   	RunUserInterface ();
} 

int CVICALLBACK CloseUICallback (int panel, int control, int event,
        void *callbackData, int eventData1, int eventData2)
{
    switch (event) {
        case EVENT_COMMIT:
            HidePanel(panelHandle);
			
            DiscardPanel(panelHandle);
            QuitUserInterface(0);
            break;
    }
    return 0;
}

int CVICALLBACK panelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	if (event == EVENT_CLOSE)
		QuitUserInterface (0);
	return 0;
}

long int DLLEXPORT __stdcall MyDLLStdcallFunction(LPSTR buffer)
{
     MessageBox(NULL, buffer, "DLL MessageBox called from MyDLLStdcallFunction", MB_OK);
     status = 200;
     return  (status);
}


long int DLLEXPORT MyDLLCdeclFunction(LPSTR buffer)
{
     MessageBox(NULL, buffer, "DLL MessageBox called from MyDLLCdeclFunction", MB_OK);
     status = 300;
     return  (status);
}

int openGl_count = 0;
int CVICALLBACK timer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK: 
			

			if (flag==1)
			{
				Tran_X = Longitudinaldis * 0.8;
				Tran_Y = -Lateraldis * 0.6;
				Tran_Z =  (- Verticaldis + 0.8) * 0.5;
				OpenGL_SetRoll(-ptich);  
				OpenGL_SetYaw(-yaw);  
				OpenGL_SetPitch(roll); 
				OGLRefreshGraph (panelHandle, OpenglCtrl);      
			
			numberLongd[rear] = Longitudinaldis;
			numberLated[rear] =  Lateraldis;
			numberVercad[rear] = Verticaldis;
			numberpitchd[rear]= ptich;
			numberrolld[rear] = roll;
			numberyawd[rear]= yaw;   
				
		   display[0]=Longitudinaldis;
		   display[1]=Lateraldis;
		   display[2]=Verticaldis;
		   display[3]= ptich;
		   display[4]=roll;
		   display[5]=yaw;
		   
			//SetCtrlVal(panelHandle,PANEL_NUMERIC_2,kao);
			SetCtrlVal(panelHandle,PANEL_LongitudinalDis,Longitudinaldis); 
			SetCtrlVal(panelHandle,PANEL_LateralDis,Lateraldis);          
			SetCtrlVal(panelHandle,PANEL_VerticalDis,Verticaldis);          
		    SetCtrlVal(panelHandle,PANEL_Ptich,ptich);          
		    SetCtrlVal(panelHandle,PANEL_Roll,roll);          
			SetCtrlVal(panelHandle,PANEL_Yaw,yaw);          
			SetCtrlVal(panelHandle,PANEL_L1,lone);          
			SetCtrlVal(panelHandle,PANEL_L2,ltwo);          
			SetCtrlVal(panelHandle,PANEL_L3,lthree);          
			SetCtrlVal(panelHandle,PANEL_L4,lfour);          
			SetCtrlVal(panelHandle,PANEL_L5,lfive);          
			SetCtrlVal(panelHandle,PANEL_L6,lsix);  
			
			//DeleteGraphPlot(panel,PANEL_GRAPH_3,-1,VAL_IMMEDIATE_DRAW);
			//RefreshGraph(panel,PANEL_GRAPH_3);//,-1,VAL_IMMEDIATE_DRAW);  
			//PlotY (panel, PANEL_GRAPH_3, numberLongd, 50, VAL_DOUBLE, VAL_THIN_LINE, VAL_SOLID_SQUARE, VAL_SOLID, 1, VAL_RED); 
		//	PlotY (panel, PANEL_GRAPH_3, numberLated, 50, VAL_DOUBLE, VAL_THIN_LINE, VAL_SOLID_SQUARE, VAL_SOLID, 1, VAL_BLUE);  
			
			PlotStripChart(panel,PANEL_STRIPCHART,display,6,0,0,VAL_DOUBLE);
			SetTraceAttributeEx(panel,PANEL_STRIPCHART,1,ATTR_TRACE_LG_TEXT,"X");
			SetTraceAttributeEx(panel,PANEL_STRIPCHART,2,ATTR_TRACE_LG_TEXT,"Y");
			SetTraceAttributeEx(panel,PANEL_STRIPCHART,3,ATTR_TRACE_LG_TEXT,"Z");
			SetTraceAttributeEx(panel,PANEL_STRIPCHART,4,ATTR_TRACE_LG_TEXT,"ROLL");
			SetTraceAttributeEx(panel,PANEL_STRIPCHART,5,ATTR_TRACE_LG_TEXT,"PITCH");
			SetTraceAttributeEx(panel,PANEL_STRIPCHART,6,ATTR_TRACE_LG_TEXT,"YAW");   
			//PlotStripChart(panel,PANEL_STRIPCHART,numberpitchd,50,0,2,VAL_DOUBLE); 
			//PlotStripChartPoint(panel,PANEL_STRIPCHART,numberLongd[0]);  
			//PlotStripChartPoint(panel,PANEL_STRIPCHART,numberpitchd[0]);  
		//	PlotStripChartPoint(panel,PANEL_STRIPCHART,numberrolld[0]);  
			//PlotStripChartPoint(panel,PANEL_STRIPCHART,numberyawd[0]);  
		    //PlotY (panel, PANEL_GRAPH_3, numberVercad, 50, VAL_DOUBLE, VAL_THIN_LINE, VAL_SOLID_SQUARE, VAL_SOLID, 1, VAL_GREEN);
			//PlotY (panel, PANEL_GRAPH_3, numberpitchd, 50, VAL_DOUBLE, VAL_CONNECTED_POINTS, VAL_SOLID_SQUARE, VAL_SOLID, 1, VAL_MAGENTA);
			//PlotY (panel, PANEL_GRAPH_3, numberrolld, 50, VAL_DOUBLE, VAL_CONNECTED_POINTS, VAL_SOLID_SQUARE, VAL_SOLID, 1, VAL_CYAN);  
			//PlotY (panel, PANEL_GRAPH_3, numberyawd, 50, VAL_DOUBLE, VAL_CONNECTED_POINTS, VAL_SOLID_SQUARE, VAL_SOLID, 1, VAL_YELLOW);  
			}
			break;
	}
	return 0;
}

int CVICALLBACK OnclickBtOK (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			flag=1;
			break;
	}
	return 0;
}

int CVICALLBACK OnclickBtEsc (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			OpenglCtrlDispose();
			HidePanel(panelHandle);
            DiscardPanel(panelHandle);
            QuitUserInterface(0);

			break;
	}
	return 0;
}
