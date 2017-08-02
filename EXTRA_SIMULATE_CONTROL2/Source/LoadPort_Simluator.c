#include "iodefine.h"

//////////////////////////////////////////////////////////////////////////
//
//	LoadPort_Simulator
//
//////////////////////////////////////////////////////////////////////////
void LoadPort_Simulator( int _nLP )
{
	int		nCommStatus;
	int		nPORTx_Control = -1;
	char	cMappingData[32]={0,};

	//	LoadPort Initialization
	WRITE_DIGITAL( D_PORT1_Run_Status + _nLP , LP_IDLE_STS , &nCommStatus );
	WRITE_DIGITAL( D_PORT1_CarrStatus + _nLP , CARR_ABSENT_STS , &nCommStatus );
	WRITE_DIGITAL( D_PORT1_DoorStatus + _nLP , DOOR_CLOSE_STS , &nCommStatus );
	WRITE_DIGITAL( D_PORT1_ClampStatus + _nLP , CLMP_UNCLAMP_STS , &nCommStatus );
	WRITE_DIGITAL( D_PORT1_DockStatus + _nLP , UNDOCKED_STS , &nCommStatus );
	WRITE_DIGITAL( D_PORT1_INIT_STATUS + _nLP , LP_INIT_OK_STS , &nCommStatus );

	WRITE_DIGITAL( D_PORT1_Control + _nLP , -1 , &nCommStatus );

	while ( TRUE )
	{
		//LP_HOME , LP_LOAD , LP_UNLOAD , LP_CLAMP , LP_UNCLAMP , LP_CLOSE , LP_OPEN 
		nPORTx_Control = READ_DIGITAL( D_PORT1_Control + _nLP , &nCommStatus );
		if ( nPORTx_Control >= 0 )
		{
			WRITE_DIGITAL( D_PORT1_Run_Status + _nLP , LP_RUN_STS , &nCommStatus );
			if	((nPORTx_Control == LP_CLAMP) || (nPORTx_Control == LP_UNCLAMP))	_sleep(1000);
			else																	_sleep(3000);
			switch ( nPORTx_Control )
			{
				case LP_HOME	:
					WRITE_DIGITAL( D_PORT1_DoorStatus + _nLP , DOOR_CLOSE_STS , &nCommStatus );
					WRITE_DIGITAL( D_PORT1_DockStatus + _nLP , UNDOCKED_STS , &nCommStatus );
					WRITE_DIGITAL( D_PORT1_ClampStatus + _nLP , CLMP_UNCLAMP_STS , &nCommStatus );
					WRITE_DIGITAL( D_PORT1_INIT_STATUS + _nLP , LP_INIT_OK_STS , &nCommStatus );
					break;
				case LP_CLAMP	:	WRITE_DIGITAL( D_PORT1_ClampStatus + _nLP , CLMP_CLAMP_STS , &nCommStatus );	break;
				case LP_UNCLAMP :	WRITE_DIGITAL( D_PORT1_ClampStatus + _nLP , CLMP_UNCLAMP_STS , &nCommStatus );	break;
				case LP_CLOSE	:	WRITE_DIGITAL( D_PORT1_DoorStatus + _nLP , DOOR_CLOSE_STS , &nCommStatus );		break;
				case LP_OPEN	:	WRITE_DIGITAL( D_PORT1_DoorStatus + _nLP , DOOR_OPEN_STS , &nCommStatus );		break;
				case LP_LOAD	:
					WRITE_DIGITAL( D_PORT1_ClampStatus + _nLP , CLMP_CLAMP_STS , &nCommStatus );
					WRITE_DIGITAL( D_PORT1_DockStatus + _nLP , DOCKED_STS , &nCommStatus );
					WRITE_DIGITAL( D_PORT1_DoorStatus + _nLP , DOOR_OPEN_STS , &nCommStatus );
					strcpy( cMappingData , "1111111111111111111111111" );
					WRITE_STRING( S_PORT1_MAP_DATA + _nLP , cMappingData , &nCommStatus );
					break;
				case LP_UNLOAD	:
					WRITE_DIGITAL( D_PORT1_DoorStatus + _nLP , DOOR_CLOSE_STS , &nCommStatus );
					strcpy( cMappingData , "1111111111111111111111111" );
					WRITE_STRING( S_PORT1_MAP_DATA + _nLP , cMappingData , &nCommStatus );
					WRITE_DIGITAL( D_PORT1_DockStatus + _nLP , UNDOCKED_STS , &nCommStatus );
					//WRITE_DIGITAL( D_PORT1_ClampStatus + _nLP , CLMP_UNCLAMP_STS , &nCommStatus );
					break;
				default :	break;

			}
			WRITE_DIGITAL( D_PORT1_Run_Status + _nLP , LP_IDLE_STS , &nCommStatus );
			WRITE_DIGITAL( D_PORT1_Control + _nLP , -1 , &nCommStatus );
		}
		_sleep(200);
		
		if ( g_bTHREAD_END )	break;
	}

	_endthreadex(0);
	return;
}

//////////////////////////////////////////////////////////////////////////
//
//	AMHS_Simulator
//
//////////////////////////////////////////////////////////////////////////
void AMHS_Simulator( int _nLP )
{
	int		nCommStatus;
	int		nSequence, nRetryCount;
	int		nLoadUnload, nAMHSRemote;
	
	//	AMHS Initialization
	WRITE_DIGITAL( D_AMHS1_SIMULATION_LOAD + _nLP , SIM_NONE , &nCommStatus );

	WRITE_DIGITAL( D_AMHS1_PV_LREQ + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_PV_UREQ + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_PV_READY + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_PV_HO_AVBL + _nLP	, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_PV_ES + _nLP			, AMHS_OFF , &nCommStatus );

	WRITE_DIGITAL( D_AMHS1_AV_VALID + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_AV_CS_0 + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_AV_CS_1 + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_AV_TR_REQ + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_AV_BUSY + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_AV_COMPT + _nLP		, AMHS_OFF , &nCommStatus );
	WRITE_DIGITAL( D_AMHS1_AV_CONT + _nLP		, AMHS_OFF , &nCommStatus );

	nSequence = 0;
	nRetryCount = 0;

	while ( TRUE )
	{
		nAMHSRemote = READ_DIGITAL( D_CTC_FA_STATUS_AGV_CM1 + _nLP , &nCommStatus );
		WRITE_DIGITAL( D_PORT1_AMHSModeSts + _nLP , nAMHSRemote , &nCommStatus );

		nLoadUnload = READ_DIGITAL( D_AMHS1_SIMULATION_LOAD + _nLP , &nCommStatus );
		if ( nLoadUnload != SIM_NONE )
		{
			if ((READ_DIGITAL( D_AMHS1_PV_HO_AVBL + _nLP , &nCommStatus ) == AMHS_ON) && (READ_DIGITAL( D_AMHS1_PV_ES + _nLP , &nCommStatus ) == AMHS_ON) )
			{
				switch ( nSequence )
				{
					case 0 :
						printf("HO D_AMHSx_PV_HO_AVBL : ON / D_AMHSx_PV_ES : ON\n");
						_sleep(1000);
						nRetryCount = 0;
						WRITE_DIGITAL( D_AMHS1_AV_CS_0 + _nLP		, AMHS_ON , &nCommStatus );
						WRITE_DIGITAL( D_AMHS1_AV_VALID + _nLP		, AMHS_ON , &nCommStatus );
						printf("D_AMHSx_AV_CS_0 : ON / D_AMHSx_AV_VALID : ON\n");
						nSequence++;
						break;
					case 1 :
						if (((nLoadUnload == LOAD) && (READ_DIGITAL( D_AMHS1_PV_LREQ + _nLP , &nCommStatus ) == AMHS_ON))
							|| ((nLoadUnload == UNLOAD) && (READ_DIGITAL( D_AMHS1_PV_UREQ + _nLP , &nCommStatus ) == AMHS_ON)))
						{
							printf("D_AMHSx_PV_LREQ_UREQ : ON\n");
							_sleep(100);
							WRITE_DIGITAL( D_AMHS1_AV_TR_REQ + _nLP	, AMHS_ON , &nCommStatus );
							printf("D_AMHSx_AV_TR_REQ : ON\n");
							nSequence++;
						}
						break;
					case 2 :
						if ( READ_DIGITAL( D_AMHS1_PV_READY + _nLP , &nCommStatus ) == AMHS_ON )
						{
							printf("D_AMHSx_PV_READY : ON\n");
							_sleep(100);
							WRITE_DIGITAL( D_AMHS1_AV_BUSY + _nLP	, AMHS_ON , &nCommStatus );
							printf("D_AMHSx_AV_BUSY : ON\n");
							nSequence++;
						}
						break;
					case 3 : 
						if ( nRetryCount > 20 )
						{
							if		( nLoadUnload == LOAD )
							{
								WRITE_DIGITAL( D_PORT1_CarrStatus + _nLP , CARR_PRESENT_STS , &nCommStatus );
								printf("D_PORT1_CarrStatus : DETECTION\n");
							}
							else/*if( nLoadUnload == UNLOAD )*/
							{
								WRITE_DIGITAL( D_PORT1_CarrStatus + _nLP , CARR_ABSENT_STS , &nCommStatus );
								printf("D_PORT1_CarrStatus : ABSENT\n");
							}
						}
						else	nRetryCount++;
						if (((nLoadUnload == LOAD) && (READ_DIGITAL( D_AMHS1_PV_LREQ + _nLP , &nCommStatus ) == AMHS_OFF))
							|| ((nLoadUnload == UNLOAD) && (READ_DIGITAL( D_AMHS1_PV_UREQ + _nLP , &nCommStatus ) == AMHS_OFF)))
						{
							printf("D_AMHSx_PV_LREQ_UREQ : OFF\n");
							_sleep(100);
							WRITE_DIGITAL( D_AMHS1_AV_BUSY + _nLP		, AMHS_OFF , &nCommStatus );
							WRITE_DIGITAL( D_AMHS1_AV_TR_REQ + _nLP		, AMHS_OFF , &nCommStatus );
							WRITE_DIGITAL( D_AMHS1_AV_COMPT + _nLP		, AMHS_ON , &nCommStatus );
							printf("D_AMHSx_AV_BUSY : OFF\n");
							printf("D_AMHSx_AV_TR_REQ : OFF\n");
							printf("D_AMHSx_AV_COMPT : ON\n");
							nSequence++;
						}
						break;
					case 4 :
						if ( READ_DIGITAL( D_AMHS1_PV_READY + _nLP , &nCommStatus ) == AMHS_OFF )
						{
							printf("D_AMHSx_PV_READY : OFF\n");
							_sleep(100);
							WRITE_DIGITAL( D_AMHS1_AV_VALID + _nLP		, AMHS_OFF , &nCommStatus );
							WRITE_DIGITAL( D_AMHS1_AV_COMPT + _nLP		, AMHS_OFF , &nCommStatus );
							WRITE_DIGITAL( D_AMHS1_AV_CS_0 + _nLP		, AMHS_OFF , &nCommStatus );
							printf("D_AMHSx_AV_VALID : OFF\n");
							printf("D_AMHSx_AV_COMPT : OFF\n");
							printf("D_AMHSx_AV_CS_0 : OFF\n");
							
							nSequence = 0;
							WRITE_DIGITAL( D_AMHS1_SIMULATION_LOAD + _nLP, SIM_NONE , &nCommStatus );
							_sleep(500);
						}
						break;
				}
			}
			else
			{
				if ( READ_DIGITAL( D_AMHS1_PV_HO_AVBL + _nLP , &nCommStatus ) == AMHS_OFF )
				{
					WRITE_DIGITAL( D_AMHS1_AV_CS_0 + _nLP		, AMHS_OFF , &nCommStatus );
					WRITE_DIGITAL( D_AMHS1_AV_CS_1 + _nLP		, AMHS_OFF , &nCommStatus );
					WRITE_DIGITAL( D_AMHS1_AV_TR_REQ + _nLP		, AMHS_OFF , &nCommStatus );
					WRITE_DIGITAL( D_AMHS1_AV_BUSY + _nLP		, AMHS_OFF , &nCommStatus );
					WRITE_DIGITAL( D_AMHS1_AV_COMPT + _nLP		, AMHS_OFF , &nCommStatus );
					WRITE_DIGITAL( D_AMHS1_AV_CONT + _nLP		, AMHS_OFF , &nCommStatus );
					WRITE_DIGITAL( D_AMHS1_AV_VALID + _nLP		, AMHS_OFF , &nCommStatus );
				}
			}
		}

				
		_sleep(1);
		if ( g_bTHREAD_END )	break;
	}
	
	_endthreadex(0);
	return;
}