#include "iodefine.h"

void Screen_Nav_Info( int _nNo ) 
{
	if ( _nNo == -1 )
	{
		if ( !KWIN_DIALOG_DRIVER_UNLOADING() ) MessageBeep(100);
	}
	return;
}

void Event_Message_Received()
{
	int				nParameterLengh , nLoop_Count, nLoadPort;
	char*			pcParameter;
	char			cSet_Data[MAX_PARAMETER_DATA][MAX_PARAMETER_LENGTH] = {0,};
	char			cSeparate_Data[DEFAULT_STRING] = {0,} , cSeparate_Tail[DEFAULT_STRING] = {0,};
	Module_Status	msResult;
	
	//------------------------------------------------------------------
	// Initialize
	//------------------------------------------------------------------
	ZeroMemory( cSet_Data , sizeof(cSet_Data) );
	ZeroMemory( cSeparate_Data , sizeof(cSeparate_Data) );	ZeroMemory( cSeparate_Tail , sizeof(cSeparate_Tail) );
	msResult = SYS_SUCCESS;
	
	pcParameter = PROGRAM_EVENT_READ();
	nParameterLengh = strlen( pcParameter );
	pcParameter[ nParameterLengh ] = 0x00;	
	
	LogMsgWrite( "FUNCTION" , "[START] [EXTRA_O2_TEST-EVENT] %s" , pcParameter );
	
	if ( nParameterLengh <= 0 )
	{
		LogMsgWrite("FUNCTION", "[ END ] [EXTRA_O2_TEST-EVENT] RECEIVE DATA IS NULL");
		return;
	}
	
	//------------------------------------------------------------------
	// Parameter Data Separate
	//	
	//	cSet_Data[0]
	//	SET_S(F) or SET_S2(F) or SET_S3(F) or SET_S4(F)
	//	SET_A(F) or SET_A2(F) or SET_A3(F) or SET_A4(F)
	//	SET_D(F) or SET_D2(F) or SET_D3(F) or SET_D4(F)
	//	CLEAR(F) or CLEAR2(F) or CLEAR3(F) or CLEAR4(F)
	//------------------------------------------------------------------
	for ( nLoop_Count = 0 ; nLoop_Count < MAX_PARAMETER_DATA ; nLoop_Count++ )
	{
		STR_SEPERATE( pcParameter , cSeparate_Data , cSeparate_Tail , DEFAULT_STRING );
		strcpy( cSet_Data[nLoop_Count] , cSeparate_Data );
		
		if ( strlen( cSeparate_Tail ) == 0 )	break;
		pcParameter = cSeparate_Tail;
	}
	
	if ( (cSet_Data[0][5] >= '1') && (cSet_Data[0][5] <= '4') )
		nLoadPort = cSet_Data[0][5] - '1';
	else
		nLoadPort = LOADPORT01;
	
	if		( STRNCMP_L( cSet_Data[0] , "CLEAR" , strlen("CLEAR") ) )
	{
		if ( !Change_Cluster_Recipe( nLoadPort , CLEAR_OPTION ) )	printf( "---> Change_Cluster_Recipe Error - %s\n" , cSet_Data[0] );
	}
	else if ( STRNCMP_L( cSet_Data[0] , "SET_S" , strlen("SET_S") ) )
	{
		if (Check_Recipe_State(nLoadPort))
		{
			if (!Change_Cluster_Recipe(nLoadPort, SET_S_OPTION))	printf("---> Change_Cluster_Recipe Error - %s\n", cSet_Data[0]);
		}
		else
		{
			printf("---> Recipe State Error - %s\n", cSet_Data[0]);
		}
	}
	else if ( STRNCMP_L( cSet_Data[0] , "SET_A" , strlen("SET_A") ) )
	{
		if (Check_Recipe_State(nLoadPort))
		{
			if (!Change_Cluster_Recipe(nLoadPort, SET_A_OPTION))	printf("---> Change_Cluster_Recipe Error - %s\n", cSet_Data[0]);
		}
		else
		{
			printf("---> Recipe State Error - %s\n", cSet_Data[0]);
		}
	}
	else if ( STRNCMP_L( cSet_Data[0] , "SET_D" , strlen("SET_D") ) )
	{
		if ( !Change_Cluster_Recipe( nLoadPort , SET_D_OPTION ) )	printf( "---> Change_Cluster_Recipe Error - %s\n" , cSet_Data[0] );
	}
	else	printf( "---> Change_Cluster_Recipe Error - %s\n" , cSet_Data[0] );
	
	LogMsgWrite( "FUNCTION" , "[ END ] [EXTRA_O2_TEST-EVENT] SUCCESS" );
	
	return;
}

BOOL Program_Init_Code()
{
	int nCommStatus;
	g_nJobStartMode = READ_DIGITAL( D_JobStartMode , &nCommStatus );
	return TRUE;
}

void Program_Enter_Code()
{
	if ( !KWIN_DIALOG_DRIVER_LOADING() ) MessageBeep(100);
}
