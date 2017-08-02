#include "iodefine.h"

void Station_Simulator( int _nStationNo )
{
	int		nCommStatus;
	int		nReadData, nReadData2;
	int		nStatus;

	if ( _nStationNo == 5 )
	{
		WRITE_DIGITAL( D_PM_LL_PurgeState , 2 , &nCommStatus );
		WRITE_DIGITAL( D_LL_Door_Ctrl , LLDOR_CLOSE_STS , &nCommStatus );
		WRITE_DIGITAL( D_LL_Door_Sts , LLDOR_CLOSE_STS , &nCommStatus );
		WRITE_DIGITAL( D_LL_Door_Seal_Vac_Ctrl , 1/*ON*/ , &nCommStatus );	
		WRITE_DIGITAL( D_Chuck6_UP_Ctrl , 0 , &nCommStatus );
		WRITE_DIGITAL( D_Chuck6_DN_Ctrl , 1 , &nCommStatus );
		WRITE_DIGITAL( D_PM_LL_PurgeState , 0 , &nCommStatus );
	}
	else
	{
		WRITE_DIGITAL( D_Chuck1_UP_Ctrl + _nStationNo , 0/*DN*/ , &nCommStatus );
	}

	WRITE_DIGITAL( D_Chuck1_Pos_Sts + _nStationNo , 2/*DN*/ , &nCommStatus );
 
	while ( TRUE )
	{
		//	STATION 06
		//////////////////////////////////////////////////////////////////////////
		if ( _nStationNo == 5 )
		{
			nReadData = READ_DIGITAL( D_LL_Door_Ctrl , &nCommStatus );
			nStatus	  = READ_DIGITAL( D_LL_Door_Sts , &nCommStatus );
			if ( nReadData != nStatus )
			{
				WRITE_DIGITAL( D_LL_Door_Sts , LLDOR_UNKNOWN_STS , &nCommStatus );
				_sleep(1000);
				if ( nStatus == 1 )	WRITE_ANALOG( A_O2LevelRead , 12.0 , &nCommStatus );
				WRITE_DIGITAL( D_LL_Door_Sts , nReadData , &nCommStatus );
			}

			nReadData = READ_DIGITAL( D_Chuck6_UP_Ctrl , &nCommStatus );
			nReadData2= READ_DIGITAL( D_Chuck6_DN_Ctrl , &nCommStatus );
			nStatus	  = READ_DIGITAL( D_Chuck6_Pos_Sts , &nCommStatus );
			if (((nStatus == 1/*UP*/) != ((nReadData == 1) && (nReadData2 == 0))) || 
				((nStatus == 2/*DN*/) != ((nReadData == 0) && (nReadData2 == 1))))
			{
				WRITE_DIGITAL( D_Chuck6_Pos_Sts , 0/*NONE*/ , &nCommStatus );
				_sleep(1000);
				if		((nReadData == 1) && (nReadData2 == 0))	WRITE_DIGITAL( D_Chuck6_Pos_Sts , 1/*UP*/ , &nCommStatus );
				else if ((nReadData == 0) && (nReadData2 == 1))	WRITE_DIGITAL( D_Chuck6_Pos_Sts , 2/*DOWN*/ , &nCommStatus );
				else											WRITE_DIGITAL( D_Chuck6_Pos_Sts , 0/*NONE*/ , &nCommStatus );
			}
			//D_Stg6_Wfr_Sns_Sts
			//D_Stg6_Wfr_Sns_Vac
			if (READ_DIGITAL(D_Stg6_Wfr_Sns_Vac, &nCommStatus) == 1)
				WRITE_DIGITAL(D_Stg6_Wfr_Sns_Sts, 1, &nCommStatus);
			if (READ_DIGITAL(D_Stg6_Wfr_Sns_Vac, &nCommStatus) == 0)
				WRITE_DIGITAL(D_Stg6_Wfr_Sns_Sts, 0, &nCommStatus);
		}
		else
		{
			nReadData = READ_DIGITAL( D_Chuck1_UP_Ctrl + _nStationNo , &nCommStatus );
			nStatus	  = READ_DIGITAL( D_Chuck1_Pos_Sts + _nStationNo , &nCommStatus );
			if (((nStatus == 1/*UP*/) != (nReadData == 1/*UP*/)) || 
				((nStatus == 2/*DN*/) != (nReadData == 0/*DN*/)))
			{
				WRITE_DIGITAL( D_Chuck1_Pos_Sts + _nStationNo , 0/*NONE*/ , &nCommStatus );
				_sleep(1000);
				if ( nReadData == 1 )	WRITE_DIGITAL( D_Chuck1_Pos_Sts + _nStationNo , 1/*UP*/ , &nCommStatus );
				else					WRITE_DIGITAL( D_Chuck1_Pos_Sts + _nStationNo , 2/*DOWN*/ , &nCommStatus );
			}
		}

		_sleep(10);
		if ( g_bTHREAD_END )	break;
	}
	return;
}

//////////////////////////////////////////////////////////////////////////
//
//	Pressure_Simulator
//
//////////////////////////////////////////////////////////////////////////
void Pressure_Simulator()
{
	int		nCommStatus, nOldAPCCtrlMode=-1, nAPCCtrlMode=0, nOldLLAPCCtrlMode=-1, nLLAPCCtrlMode=0;
	double	dPress_Vent=0, dvp, dr;
	BOOL	bGenevaBOption;

	int		nC1_P, nC2_P;

	if (g_SimulateConvectrons)
	{
		WRITE_ANALOG(A_Convect_Press, 765000, &nCommStatus);
		WRITE_ANALOG(A_Convect_2_Press, 765001, &nCommStatus);
	}

	bGenevaBOption = (READ_DIGITAL(D_GenevaBOption, &nCommStatus) == 1);

	while ( TRUE )
	{
		nAPCCtrlMode = READ_DIGITAL( D_Prcs_APC_Ctrl_Mode , &nCommStatus );
		if ( nOldAPCCtrlMode != nAPCCtrlMode )
		{
			_sleep(500);
			nOldAPCCtrlMode = nAPCCtrlMode;
		}
		switch( nAPCCtrlMode )	// 0:Control, 1:Close, 2:Open
		{
			case 1 :
				WRITE_ANALOG( A_Prcs_APC_Vv_Position , 0 , &nCommStatus );
				WRITE_DIGITAL( D_Prcs_APC_Close_Vv_Sts , 1 , &nCommStatus );
				WRITE_DIGITAL( D_Prcs_APC_Open_Vv_Sts , 0 , &nCommStatus );
				break;
			case 2 :
				WRITE_ANALOG( A_Prcs_APC_Vv_Position , 100 , &nCommStatus );
				WRITE_DIGITAL( D_Prcs_APC_Open_Vv_Sts , 1 , &nCommStatus );
				WRITE_DIGITAL( D_Prcs_APC_Close_Vv_Sts , 0 , &nCommStatus );
				break;		
			case 0:
				dvp = READ_ANALOG(A_Prcs_APC_SetPoint, &nCommStatus);
				WRITE_ANALOG(A_Prcs_APC_Press_Read, dvp, &nCommStatus);
				WRITE_ANALOG(A_Prcs_APC_Vv_Position, 10, &nCommStatus);
				WRITE_DIGITAL(D_Prcs_APC_Open_Vv_Sts, 0, &nCommStatus);
				WRITE_DIGITAL(D_Prcs_APC_Close_Vv_Sts, 0, &nCommStatus);
				break;
		}
		
		nLLAPCCtrlMode = READ_DIGITAL( D_LL_APC_Ctrl_Mode , &nCommStatus );
		if ( nOldLLAPCCtrlMode != nLLAPCCtrlMode )
		{
			_sleep(500);
			nOldLLAPCCtrlMode = nLLAPCCtrlMode;
		}
		switch( nLLAPCCtrlMode )	// 0:Control, 1:Close, 2:Open
		{
			case 1 :
				WRITE_ANALOG( A_LL_APC_Vv_Position , 0 , &nCommStatus );
				WRITE_DIGITAL( D_LL_APC_Close_Vv_Sts , 1 , &nCommStatus );
				WRITE_DIGITAL( D_LL_APC_Open_Vv_Sts , 0 , &nCommStatus );
				break;
				
			case 2 :
				WRITE_ANALOG( A_LL_APC_Vv_Position , 100 , &nCommStatus );
				WRITE_DIGITAL( D_LL_APC_Open_Vv_Sts , 1 , &nCommStatus );
				WRITE_DIGITAL( D_LL_APC_Close_Vv_Sts , 0 , &nCommStatus );
				break;		
			case 0 :
				if ( READ_DIGITAL( D_LL_APC_Set_Type , &nCommStatus ) == 0 )	// 0:Pressure, 1:Position
				{
					dvp = READ_ANALOG( A_LL_APC_SetPoint , &nCommStatus );
					WRITE_ANALOG( A_LL_APC_Press_Read , dvp , &nCommStatus );
					WRITE_ANALOG( A_LL_APC_Vv_Position , 10 , &nCommStatus );
				}
				else/*if( READ_DIGITAL( D_LL_APC_Set_Type , &nCommStatus ) == 1 )*/
				{
					dvp = READ_ANALOG( A_LL_APC_SetPoint , &nCommStatus );
					WRITE_ANALOG( A_LL_APC_Press_Read , 2000 , &nCommStatus );
					WRITE_ANALOG( A_LL_APC_Vv_Position , dvp , &nCommStatus );
				}
				WRITE_DIGITAL( D_Prcs_APC_Open_Vv_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_Prcs_APC_Close_Vv_Sts , 0 , &nCommStatus );
				break;
		}

		nC1_P = nC2_P = 0;
		if ( READ_DIGITAL( D_VacHeat_Vac_Vv , &nCommStatus ) == 1 ) {	WRITE_DIGITAL( D_VacHeat_Vac_Vv_Sts , 1/*OPEN*/ , &nCommStatus );	nC1_P -= 1; }
		else {															WRITE_DIGITAL( D_VacHeat_Vac_Vv_Sts , 0/*CLOSE*/ , &nCommStatus );	 }
		if (!bGenevaBOption)
		{
			if ( READ_DIGITAL( D_VacHeat_Vent_Vv , &nCommStatus ) == 1 ){	WRITE_DIGITAL( D_VacHeat_Vent_Vv_Sts , 1/*OPEN*/ , &nCommStatus );	nC1_P += 2; }
			else {															WRITE_DIGITAL( D_VacHeat_Vent_Vv_Sts , 0/*CLOSE*/ , &nCommStatus );	 }
		}
		else	// GenevaB
		{
			if ( READ_DIGITAL( D_Bubbler2_DlvryVv_Sts , &nCommStatus ) == 1 )
				nC1_P += 2;
		}

		if ( nC1_P != 0 ) 
		{
			dr = READ_ANALOG( A_Convect_Press , &nCommStatus );
			if ( (nC1_P < 0) && (dr > 0.004) )
			{
				if (g_SimulateConvectrons)
					WRITE_ANALOG(A_Convect_Press, (pow(10, log10((dr / 1000)) + ((double)nC1_P * 0.1))) * 1000, &nCommStatus);
			}

			if ( (nC1_P > 0) && (dr < 760000) ) 
			{
				if ( dr <= 0 ) 
					dr = 10;
				if (g_SimulateConvectrons)
					WRITE_ANALOG(A_Convect_Press, (pow(10, log10((dr / 1000)) + ((double)nC1_P * 0.1))) * 1000, &nCommStatus);
				dr = READ_ANALOG( A_Convect_Press , &nCommStatus );
				if ( dr > 760000 && g_SimulateConvectrons) 
					WRITE_ANALOG( A_Convect_Press , 750000 , &nCommStatus );
			}
		}
		
		dr = READ_ANALOG( A_Convect_Press , &nCommStatus );
		if ( dr >= 740000 )		WRITE_DIGITAL( D_VacHeat_ATM_Sensor , 0 , &nCommStatus );
		else					WRITE_DIGITAL( D_VacHeat_ATM_Sensor , 1 , &nCommStatus );
				
		if ( bGenevaBOption )
		{
			if ( READ_DIGITAL( D_VacHeat_VacIsoB_Vv , &nCommStatus ) == 1 ) {	WRITE_DIGITAL( D_VacHeat_VacIsoB_Sts , 1/*OPEN*/ , &nCommStatus );	nC2_P -= 1; }
			else {																WRITE_DIGITAL( D_VacHeat_VacIsoB_Sts , 0/*CLOSE*/ , &nCommStatus );	 }
			if ( READ_DIGITAL( D_VacHeat_GasIsoB_Vv , &nCommStatus ) == 1 ){	WRITE_DIGITAL( D_VacHeat_GasIsoB_Sts , 1/*OPEN*/ , &nCommStatus );	nC2_P += 2; }
			else {																WRITE_DIGITAL( D_VacHeat_GasIsoB_Sts , 0/*CLOSE*/ , &nCommStatus );	 }

			if ( nC2_P != 0 ) 
			{
				dr = READ_ANALOG( A_Convect_2_Press , &nCommStatus );
				if ( (nC2_P < 0) && (dr > 0.004) )
				{
					if (g_SimulateConvectrons)
						WRITE_ANALOG( A_Convect_2_Press , ( pow( 10 , log10( ( dr / 1000 ) ) + ( (double) nC2_P * 0.1 ) ) ) * 1000 , &nCommStatus );
				}

				if ( (nC2_P > 0) && (dr < 760000) ) 
				{
					if ( dr <= 0 ) 
						dr = 10;
					if (g_SimulateConvectrons)
						WRITE_ANALOG(A_Convect_2_Press, (pow(10, log10((dr / 1000)) + ((double)nC2_P * 0.1))) * 1000, &nCommStatus);
					dr = READ_ANALOG( A_Convect_2_Press , &nCommStatus );
					if ( dr > 760000 && g_SimulateConvectrons) 
						WRITE_ANALOG( A_Convect_2_Press , 750000 , &nCommStatus );
				}
			}
		}
				
		_sleep(100);
		if ( g_bTHREAD_END )	break;
	}
	return;
}

//////////////////////////////////////////////////////////////////////////
//
//	AutoFill_Simulator
//
//////////////////////////////////////////////////////////////////////////
void AutoFill_Simulator()
{
	int		nCommStatus;
	int		nLowRetryCount=0, nHighRetryCount=0;
	double	dLowOnCount = 0.0;

	while ( TRUE )
	{
		if (READ_DIGITAL(D_Bubbler_Fill_Vv, &nCommStatus) == 1)
		{
			if (READ_DIGITAL(D_Bubbler_Low_Lvl, &nCommStatus) == 0)
			{
				if (nLowRetryCount > 500)
				{
					WRITE_DIGITAL(D_Bubbler_Low_Lvl, 1, &nCommStatus);
					nLowRetryCount = 0;
				}
				else
					nLowRetryCount++;
			}
			else if (READ_ANALOG(A_ContBubbler_Level, &nCommStatus) < 5.0)
			{
				if (nLowRetryCount > 500)
				{
					WRITE_ANALOG(A_ContBubbler_Level, 5.0, &nCommStatus);
					nLowRetryCount = 0;
				}
				else
					nLowRetryCount++;
			}
			else
			{
				if (READ_DIGITAL(D_Bubbler_High_Lvl, &nCommStatus) == 1)
				{
					if (nLowRetryCount > 1000)
					{
						WRITE_DIGITAL(D_Bubbler_High_Lvl, 0, &nCommStatus);
						nLowRetryCount = 0;
						nHighRetryCount = 0;
					}
					else
						nLowRetryCount++;
				}
				else
				{
					if (READ_DIGITAL(D_Bubbler_HighLmt_Lvl, &nCommStatus) == 1)
					{
						if (nLowRetryCount > 500)
						{
							WRITE_DIGITAL(D_Bubbler_HighLmt_Lvl, 0, &nCommStatus);
							WRITE_DIGITAL(D_Bubbler_Leak_Sts, 0, &nCommStatus);
							nLowRetryCount = 0;
						}
						else
							nLowRetryCount++;
					}
				}
			}
			
		}
		else
		{
			nLowRetryCount = 0;
			if ((READ_DIGITAL(D_Bubbler_High_Lvl, &nCommStatus) == 0) &&
				(READ_DIGITAL(D_Bubbler_Bypass_Vv, &nCommStatus) == 1) && (READ_DIGITAL(D_Bubbler_FeedVv_Sts, &nCommStatus) == 1) &&
				(READ_DIGITAL(D_Bubbler_DlvryVv_Sts, &nCommStatus) == 1))
			{
				if (nHighRetryCount > 1500)
				{
					WRITE_DIGITAL(D_Bubbler_High_Lvl, 1, &nCommStatus);
					nHighRetryCount = 0;
				}
				else
					nHighRetryCount++;
			}
			else
				nHighRetryCount = 0;

			if ((READ_DIGITAL(D_Bubbler_High_Lvl, &nCommStatus) == 1) && (READ_DIGITAL(D_Bubbler_Low_Lvl, &nCommStatus) == 1) &&
				(READ_DIGITAL(D_Bubbler_Bypass_Vv, &nCommStatus) == 1) && (READ_DIGITAL(D_Bubbler_FeedVv_Sts, &nCommStatus) == 1) &&
				(READ_DIGITAL(D_Bubbler_DlvryVv_Sts, &nCommStatus) == 1))
			{
				if (dLowOnCount > 360000)
				{
					WRITE_DIGITAL(D_Bubbler_Low_Lvl, 0, &nCommStatus);
					dLowOnCount = 0;
				}
				else
					dLowOnCount++;
			}
			else
				dLowOnCount = 0;
		}
			
		_sleep(10);
		if ( g_bTHREAD_END )	break;
	}
	return;
}
