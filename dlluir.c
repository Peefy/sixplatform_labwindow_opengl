#include <cvirte.h>		
#include <userint.h>
#include "dlluir.h"

int InitUIForDLL (void);
void DiscardUIObjectsForDLL (void);

static int panelHandle;

int __stdcall DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
			if (InitCVIRTE (hinstDLL, 0, 0) == 0)		
				return 0;	/* out of memory */
			break;
		case DLL_PROCESS_DETACH:
			if (!CVIRTEHasBeenDetached())		/* Do not call CVI functions if cvirte.dll has already been detached. */
			{
				CloseCVIRTE ();		
			}
			break;
	}

	return 1;
}

int __stdcall DllEntryPoint (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	/* Included for compatibility with Borland */

	 return DllMain (hinstDLL, fdwReason, lpvReserved);
}

int InitUIForDLL (void)
{
	/* Call this function from the appropriate place in your code */
	/* to load and display startup panels.                        */

	if ((panelHandle = LoadPanelEx (0, "dlluir.uir", PANEL, __CVIUserHInst)) < 0)
		return -1;
	DisplayPanel (panelHandle);

	/* Uncomment this call to RunUserInterface or call it from elsewhere */
	/* in your code to begin issuing user interface events to panels     */
	/* RunUserInterface (); */
	return 0;
}

void DiscardUIObjectsForDLL (void)
{
	/* Discard the panels loaded in InitUIForDLL */
	/* Call this function from the appropriate place in your code */
	/* to discard UI objects.                                     */

	if (panelHandle > 0)
	{
		DiscardPanel (panelHandle);
		panelHandle = 0;
	}
}

int CVICALLBACK CloseUICallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK LightSwitchCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK timer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:

			break;
	}
	return 0;
}
