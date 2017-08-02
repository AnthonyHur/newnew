#include "iodefine.h"

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
void Screen_Nav_Info( int _nNo )
{
	int nIndex;
	if ( _nNo == -1 )
	{
		g_bTHREAD_END = TRUE;
					//for ( nIndex = 0 ; nIndex < 3 ; nIndex++ )
					//{
					//	// Waiting for finishing "LoadPort_Simulator" function
					//	WaitForSingleObject( g_hLoadPortThread[nIndex] , INFINITE );
					//	CloseHandle( g_hLoadPortThread[nIndex] );
					//	// Waiting for finishing "AMHS_Simulator" function
					//	WaitForSingleObject( g_hAMHSThread[nIndex] , INFINITE );
					//	CloseHandle( g_hAMHSThread[nIndex] );
					//}
					for (nIndex = 0; nIndex < 6; nIndex++)
		{
			// Waiting for finishing "Station_Simulator" function
			WaitForSingleObject(g_hStationThread[nIndex], INFINITE);
			CloseHandle(g_hStationThread[nIndex]);
		}
		for (nIndex = 0; nIndex < 2; nIndex++)
		{
			// Waiting for finishing "Station_Simulator" function
			WaitForSingleObject(g_hWetStationThread[nIndex], INFINITE);
			CloseHandle(g_hWetStationThread[nIndex]);
		}
				//// Waiting for finishing "EFEM_Robot_Simulator" function
				//WaitForSingleObject( g_hRobotThread , INFINITE );
					//		//CloseHandle( g_hRobotThread );
					//// Waiting for finishing "Aligner_Simulator" function
					//WaitForSingleObject( g_hAlignerThread , INFINITE );
					//CloseHandle( g_hAlignerThread );
					//// Waiting for finishing "DiscMotion_Simulator" function
					//WaitForSingleObject( g_hDiscMotionThread , INFINITE );
					//CloseHandle( g_hDiscMotionThread );
		// Waiting for finishing "Pressure_Simulator" function
		WaitForSingleObject( g_hPressThread , INFINITE );
		CloseHandle( g_hPressThread );
	}
}
//---------------------------------------------------------------------------------------
void Program_Enter_Code() 
{
}
//---------------------------------------------------------------------------------------
void Event_Message_Received() 
{
}
//---------------------------------------------------------------------------------------
BOOL Program_Init_Code() 
{
	int nCommStatus;

	g_RobotType = READ_DIGITAL( D_FM_ROBOT_TYPE , &nCommStatus );
	SYSTEM_KILL_WITH_MESSAGE();
	return TRUE;
}
