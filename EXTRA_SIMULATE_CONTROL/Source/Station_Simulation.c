#include "iodefine.h"

void ServiceSimulateFlags();

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
	double	dConversionFactor, dPrevConversionFactor;

	int		nC1_P, nC2_P;

	if (g_SimulateConvectrons)
	{
		dConversionFactor = dPrevConversionFactor = READ_DIGITAL( D_PM_Press_Units , &nCommStatus ) ? 1.0 : 1000.0;
		WRITE_ANALOG(A_Convect_Press, 765.0*dConversionFactor, &nCommStatus);
		WRITE_ANALOG(A_Convect_2_Press, 765.1*dConversionFactor, &nCommStatus);
	}

	while ( TRUE )
	{
		dConversionFactor = READ_DIGITAL( D_PM_Press_Units , &nCommStatus ) ? 1.0 : 1000.0;
		if (dConversionFactor != dPrevConversionFactor)
		{
			dPrevConversionFactor = READ_DIGITAL( D_PM_Press_Units , &nCommStatus ) ? 0.001 : 1000.0;  // Convert current display
			dr = READ_ANALOG(A_Convect_Press, &nCommStatus);
			WRITE_ANALOG(A_Convect_Press, dr*dPrevConversionFactor, &nCommStatus);
			dr = READ_ANALOG(A_Convect_2_Press, &nCommStatus);
			WRITE_ANALOG(A_Convect_2_Press, dr*dPrevConversionFactor, &nCommStatus);
			dPrevConversionFactor = dConversionFactor;
		}
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
		if (!gSessionInfo.IsGenevaBOptionInstalled)
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
					WRITE_ANALOG( A_Convect_Press, (pow(10, log10((dr / dConversionFactor)) + ((double) nC1_P * 0.1 ))) * dConversionFactor , &nCommStatus );
			}

			if ( (nC1_P > 0) && (dr < 760 * dConversionFactor) ) 
			{
				if ( dr <= 0 ) 
					dr = 0.01 * dConversionFactor;
				if (g_SimulateConvectrons)
					WRITE_ANALOG( A_Convect_Press, (pow(10, log10((dr / dConversionFactor)) + ((double)nC1_P * 0.1))) * dConversionFactor, &nCommStatus);
				dr = READ_ANALOG( A_Convect_Press , &nCommStatus );
				if ( dr > 760 * dConversionFactor && g_SimulateConvectrons) 
					WRITE_ANALOG( A_Convect_Press , 750 * dConversionFactor , &nCommStatus );
			}
		}
		
		dr = READ_ANALOG( A_Convect_Press , &nCommStatus );
		if ( dr >= 740 * dConversionFactor )		WRITE_DIGITAL( D_VacHeat_ATM_Sensor , 0 , &nCommStatus );
		else										WRITE_DIGITAL( D_VacHeat_ATM_Sensor , 1 , &nCommStatus );
				
		if ( gSessionInfo.IsGenevaBOptionInstalled )
		{
			if ( READ_DIGITAL( D_VacHeat_VacIsoB_Vv , &nCommStatus ) == 1 ) {	WRITE_DIGITAL( D_VacHeat_VacIsoB_Sts , 1/*OPEN*/ , &nCommStatus );	nC2_P -= 1; }
			else {																WRITE_DIGITAL( D_VacHeat_VacIsoB_Sts , 0/*CLOSE*/ , &nCommStatus );	 }
			if ( READ_DIGITAL( D_VacHeat_GasIsoB_Vv , &nCommStatus ) == 0 ){	WRITE_DIGITAL( D_VacHeat_GasIsoB_Sts , 0/*OPEN*/ , &nCommStatus );	nC2_P += 2; }
			else {																WRITE_DIGITAL( D_VacHeat_GasIsoB_Sts , 1/*CLOSE*/ , &nCommStatus );	 }

			if ( nC2_P != 0 ) 
			{
				dr = READ_ANALOG( A_Convect_2_Press , &nCommStatus );
				if ( (nC2_P < 0) && (dr > 0.004) )
				{
					if (g_SimulateConvectrons)
						WRITE_ANALOG( A_Convect_2_Press, (pow(10, log10((dr / dConversionFactor )) + ((double) nC2_P * 0.1 ))) * dConversionFactor , &nCommStatus );
				}

				if ( (nC2_P > 0) && (dr < 760 * dConversionFactor) ) 
				{
					if ( dr <= 0 ) 
						dr = 0.01 * dConversionFactor;
					if (g_SimulateConvectrons)
						WRITE_ANALOG( A_Convect_2_Press, (pow(10, log10((dr / dConversionFactor)) + ((double)nC2_P * 0.1))) * dConversionFactor, &nCommStatus);
					dr = READ_ANALOG( A_Convect_2_Press , &nCommStatus );
					if ( dr > 760 * dConversionFactor && g_SimulateConvectrons) 
						WRITE_ANALOG( A_Convect_2_Press , 750 * dConversionFactor , &nCommStatus );
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
		if ((READ_DIGITAL(D_Bubbler_Fill_Vv, &nCommStatus) == 1) || (gSessionInfo.GenevaBOption && (READ_DIGITAL(D_Bubbler2_Fill_Vv, &nCommStatus) == 1)))
		{
			if ((READ_DIGITAL(D_Bubbler_Low_Lvl, &nCommStatus) == 0) || (gSessionInfo.GenevaBOption && (READ_DIGITAL(D_Bubbler2_Low_Lvl, &nCommStatus) == 0)))
			{
				if (nLowRetryCount > 500)
				{
					WRITE_DIGITAL(D_Bubbler_Low_Lvl, 1, &nCommStatus);
					WRITE_DIGITAL(D_Bubbler2_Low_Lvl, 1, &nCommStatus);
					nLowRetryCount = 0;
				}
				else
					nLowRetryCount++;
			}
			else if ((READ_ANALOG(A_ContBubbler_Level, &nCommStatus) < 5.0) || (gSessionInfo.GenevaBOption && (READ_ANALOG(A_ContBubbler2_Level, &nCommStatus) < 5.0)))
			{
				double dCurrBubblerLevel;
				
				if (READ_DIGITAL(D_Bubbler_Fill_Vv, &nCommStatus) == 1)
				{
					dCurrBubblerLevel = READ_ANALOG(A_ContBubbler_Level, &nCommStatus);
					dCurrBubblerLevel += 0.001;
					if (dCurrBubblerLevel > 5.0)
						dCurrBubblerLevel = 5.0;
					WRITE_ANALOG(A_ContBubbler_Level, dCurrBubblerLevel, &nCommStatus);
				}
				if (gSessionInfo.GenevaBOption && (READ_DIGITAL(D_Bubbler2_Fill_Vv, &nCommStatus) == 1))
				{
					dCurrBubblerLevel = READ_ANALOG(A_ContBubbler2_Level, &nCommStatus);
					dCurrBubblerLevel += 0.001;
					if (dCurrBubblerLevel > 5.0)
						dCurrBubblerLevel = 5.0;
					WRITE_ANALOG(A_ContBubbler2_Level, dCurrBubblerLevel, &nCommStatus);
				}
			}
			else
			{
				if ((READ_DIGITAL(D_Bubbler_High_Lvl, &nCommStatus) == 1) || (gSessionInfo.GenevaBOption && (READ_DIGITAL(D_Bubbler2_High_Lvl, &nCommStatus) == 1)))
				{
					if (nLowRetryCount > 1000)
					{
						WRITE_DIGITAL(D_Bubbler_High_Lvl, 0, &nCommStatus);
						nLowRetryCount = 0;
						nHighRetryCount = 0;
					}
					else
					{
						if ((nLowRetryCount > 800) && gSessionInfo.GenevaBOption && (READ_DIGITAL(D_Bubbler2_High_Lvl, &nCommStatus) == 1))
							WRITE_DIGITAL(D_Bubbler2_High_Lvl, 0, &nCommStatus);
						nLowRetryCount++;
					}
				}
				else
				{
					if ((READ_DIGITAL(D_Bubbler_HighLmt_Lvl, &nCommStatus) == 1) || (gSessionInfo.GenevaBOption && (READ_DIGITAL(D_Bubbler2_HighLmt_Lvl, &nCommStatus) == 1)))
					{
						if (nLowRetryCount > 500)
						{
							WRITE_DIGITAL(D_Bubbler_HighLmt_Lvl, 0, &nCommStatus);
							WRITE_DIGITAL(D_Bubbler_Leak_Sts, 0, &nCommStatus);
							WRITE_DIGITAL(D_Bubbler2_HighLmt_Lvl, 0, &nCommStatus);
							WRITE_DIGITAL(D_Bubbler2_Leak_Sts, 0, &nCommStatus);
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

			if ((READ_DIGITAL(D_Cont_Bubbler_Sensor_Usage, &nCommStatus) == 1) /* && (READ_DIGITAL(D_ContBubbler_Refill, &nCommStatus) == 0) */ )
			{
				double dCurrBubblerLevel;
				
				if ((READ_DIGITAL(D_Bubbler_Bypass_Vv, &nCommStatus) == 1) && (READ_DIGITAL(D_Bubbler_FeedVv_Sts, &nCommStatus) == 1) &&
					(READ_DIGITAL(D_Bubbler_DlvryVv_Sts, &nCommStatus) == 1))
				{
					dCurrBubblerLevel = READ_ANALOG(A_ContBubbler_Level, &nCommStatus);
					dCurrBubblerLevel -= 0.000003;
					if (dCurrBubblerLevel < 0.01)
						dCurrBubblerLevel = 0.01;
					WRITE_ANALOG(A_ContBubbler_Level, dCurrBubblerLevel, &nCommStatus);
				}
				if (READ_DIGITAL(D_Bubbler2_DlvryVv_Sts, &nCommStatus) == 1)
				{
					dCurrBubblerLevel = READ_ANALOG(A_ContBubbler2_Level, &nCommStatus);
					dCurrBubblerLevel -= 0.000003;
					if (dCurrBubblerLevel < 0.01)
						dCurrBubblerLevel = 0.01;
					WRITE_ANALOG(A_ContBubbler2_Level, dCurrBubblerLevel, &nCommStatus);
					if (READ_DIGITAL(D_Bubbler2_High_Lvl, &nCommStatus) == 0)
						WRITE_DIGITAL(D_Bubbler2_High_Lvl, 1, &nCommStatus);
				}
			}
			else if ((READ_DIGITAL(D_Bubbler_High_Lvl, &nCommStatus) == 1) && (READ_DIGITAL(D_Bubbler_Low_Lvl, &nCommStatus) == 1) &&
				(READ_DIGITAL(D_Bubbler_Bypass_Vv, &nCommStatus) == 1) && (READ_DIGITAL(D_Bubbler_FeedVv_Sts, &nCommStatus) == 1) &&
				(READ_DIGITAL(D_Bubbler_DlvryVv_Sts, &nCommStatus) == 1))
			{
				if (dLowOnCount > 360000)
				{
					if (READ_DIGITAL(D_Bubbler2_DlvryVv_Sts, &nCommStatus) == 1)
						WRITE_DIGITAL(D_Bubbler2_Low_Lvl, 0, &nCommStatus);
					else
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
