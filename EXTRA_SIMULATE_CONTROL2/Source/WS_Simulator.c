#include "iodefine.h"

//////////////////////////////////////////////////////////////////////////
//
//	WetStation_Simulator
//
//////////////////////////////////////////////////////////////////////////
void WetStation_Simulator(int _nWSNo)
{
	int		nCommStatus;
	int		nReadData;
	int		nArmLeaveHome = 0, nArm_Pos_Sts = UNKNOWN_POS;
	int		nOld_DiscCtrl = DISC_STOP_CTRL;
	int		nStatus;

	
	WRITE_ANALOG(A_WS1_Flow_Sensor + _nWSNo, 200.0, &nCommStatus);
	WRITE_DIGITAL(D_WS1_DefinePos_0 + _nWSNo, -1, &nCommStatus);

	WRITE_DIGITAL(D_WS1_RunSts + _nWSNo, 0/*IDLE*/, &nCommStatus);
	WRITE_DIGITAL(D_WS1_ServoSts + _nWSNo, 0/*On*/, &nCommStatus);
	WRITE_DIGITAL(D_WS1_Control + _nWSNo, DISC_NONE, &nCommStatus);
	WRITE_DIGITAL(D_WS1_Motor_Amp + _nWSNo, 1, &nCommStatus);

	WRITE_DIGITAL(D_WS1_Door_Ctrl + _nWSNo, 2/*Close*/, &nCommStatus);
	WRITE_DIGITAL(D_WS1_Door_Sts + _nWSNo, 2/*Close*/, &nCommStatus);
	WRITE_DIGITAL(D_WS1_Pin_Ctrl + _nWSNo, 2/*Down*/, &nCommStatus);
	
	WRITE_DIGITAL(D_WS1_Drain_Lvl_Sts + _nWSNo, 1/*Normal*/, &nCommStatus);
	WRITE_DIGITAL(DI_WS1_Liq_empty + _nWSNo, 1/*Normal*/, &nCommStatus);

	WRITE_DIGITAL(Bulkfill_Leak, 1/*Normal*/, &nCommStatus);
	WRITE_DIGITAL(WS_Bulk_Fill_level, 1/*Normal*/, &nCommStatus);
	

	WRITE_ANALOG(WS_Fac_Vac, -650, &nCommStatus);
	WRITE_ANALOG(WS_N2, 95, &nCommStatus);
	WRITE_ANALOG(WS_CDA, 95, &nCommStatus);


	while (TRUE)
	{
		//	Door Control
		nReadData = READ_DIGITAL(D_WS1_Door_Ctrl + _nWSNo, &nCommStatus);
		nStatus = READ_DIGITAL(D_WS1_Door_Sts + _nWSNo, &nCommStatus);
		if (nReadData != nStatus)
		{
			WRITE_DIGITAL(D_WS1_Door_Sts + _nWSNo, LLDOR_UNKNOWN_STS, &nCommStatus);
			_sleep(2000);
			WRITE_DIGITAL(D_WS1_Door_Sts + _nWSNo, nReadData, &nCommStatus);
		}

		//	Arm Control

		WRITE_DIGITAL(D_WS1_Arm_Home_Sts + _nWSNo, !(READ_DIGITAL(D_WS1_ArmHome + _nWSNo, &nCommStatus)), &nCommStatus);
		WRITE_DIGITAL(D_WS1_Arm_Pos_Sts + _nWSNo, READ_DIGITAL(D_WS1_Arm_Pos_Ctrl + _nWSNo, &nCommStatus), &nCommStatus);


		//	Chemicals
		nReadData = READ_DIGITAL(D_WS1_ACID_Flow + _nWSNo, &nCommStatus);
		WRITE_DIGITAL(D_WS1_ACID_Flow_Sts + _nWSNo, nReadData, &nCommStatus);
		nReadData = READ_DIGITAL(D_WS1_DI_Flow + _nWSNo, &nCommStatus);
		WRITE_DIGITAL(D_WS1_DI_Flow_Sts + _nWSNo, nReadData, &nCommStatus);

		nReadData = READ_DIGITAL(D_WS1_N2_Blow + _nWSNo, &nCommStatus);
		WRITE_DIGITAL(D_WS1_N2_Blow_Sts + _nWSNo, nReadData, &nCommStatus);


		if (READ_DIGITAL(D_WS1_N2_Blow_Sts + _nWSNo, &nCommStatus) == TURN_ON)
		{
		    nReadData = (int)READ_ANALOG(AO_WS1_Gas + _nWSNo, &nCommStatus);
		    WRITE_ANALOG(AI_WS1_Gas + _nWSNo, nReadData, &nCommStatus);
		}
		else
		{
		    WRITE_ANALOG(AI_WS1_Gas + _nWSNo, 0, &nCommStatus);
		}

		nReadData = READ_DIGITAL(WS_CO2_Flow, &nCommStatus);
		WRITE_DIGITAL(WS_CO2_Flow_Sts, nReadData, &nCommStatus);

		if (READ_DIGITAL(WS_CO2_Flow_Sts, &nCommStatus) == TURN_ON)
		{
		    nReadData = (int)READ_ANALOG(AO_CO2_Gas, &nCommStatus);
		    WRITE_ANALOG(AI_CO2_Gas, nReadData, &nCommStatus);
		}
		else
		{
		    WRITE_ANALOG(AI_CO2_Gas, 0, &nCommStatus);
		}

		nReadData = READ_DIGITAL(D_WS1_HIDI_Flow + _nWSNo, &nCommStatus);
		WRITE_DIGITAL(D_WS1_HIDI_Flow_Sts + _nWSNo, nReadData, &nCommStatus);
		nReadData = READ_DIGITAL(D_WS1_Back_Side + _nWSNo, &nCommStatus);
		WRITE_DIGITAL(D_WS1_Back_Side_Sts + _nWSNo, nReadData, &nCommStatus);



		//	Vacuum
		nReadData = READ_DIGITAL(D_WS1_Grip_On + _nWSNo, &nCommStatus);
		nStatus = READ_DIGITAL(D_WS1_Grip_On_Sts + _nWSNo, &nCommStatus);
		if (nReadData != nStatus)
		{
			_sleep(1000);
			WRITE_DIGITAL(D_WS1_Grip_On_Sts + _nWSNo, nReadData, &nCommStatus);
		}

		//	Pin
		nReadData = READ_DIGITAL(D_WS1_Pin_Ctrl + _nWSNo, &nCommStatus);
		nStatus = READ_DIGITAL(D_WS1_Pin_Sts + _nWSNo, &nCommStatus);
		if (nReadData != nStatus)
		{
			_sleep(1000);
			WRITE_DIGITAL(D_WS1_Pin_Sts + _nWSNo, nReadData, &nCommStatus);
		}

		//	Disc Motion
		//////////////////////////////////////////////////////////////////////////
		nReadData = READ_DIGITAL(D_WS1_Servo + _nWSNo, &nCommStatus);
		nStatus = READ_DIGITAL(D_WS1_ServoSts + _nWSNo, &nCommStatus);
		if (nReadData == nStatus)
		{
			_sleep(500);
			if (nReadData == 0)	WRITE_DIGITAL(D_WS1_ServoSts + _nWSNo, 1, &nCommStatus);
			else				WRITE_DIGITAL(D_WS1_ServoSts + _nWSNo, 0, &nCommStatus);
		}
		nReadData = READ_DIGITAL(D_WS1_MotionMode + _nWSNo, &nCommStatus); 
		nStatus = READ_DIGITAL(D_WS1_PosModeSts + _nWSNo, &nCommStatus);
		if (nReadData != nStatus)
		{
			_sleep(500);
			WRITE_DIGITAL(D_WS1_PosModeSts + _nWSNo, nReadData, &nCommStatus);
		}
		nReadData = READ_DIGITAL(D_WS1_ContMode + _nWSNo, &nCommStatus);
		nStatus = READ_DIGITAL(D_WS1_ContModeSts + _nWSNo, &nCommStatus);
		if (nReadData != nStatus)
		{
			_sleep(500);
			WRITE_DIGITAL(D_WS1_ContModeSts + _nWSNo, nReadData, &nCommStatus);
		}
		nReadData = READ_DIGITAL(D_WS1_DefinePos_0 + _nWSNo, &nCommStatus);
		if (nReadData >= 0)
		{
			_sleep(500);
			WRITE_ANALOG(A_WS1_Pos_Read + _nWSNo, 0.0, &nCommStatus);
			WRITE_DIGITAL(D_WS1_HomeSts + _nWSNo, 1/*On*/, &nCommStatus);
			WRITE_DIGITAL(D_WS1_DefinePos_0 + _nWSNo, -1, &nCommStatus);
		}

		if (READ_DIGITAL(D_WS1_ServoSts + _nWSNo, &nCommStatus) == 0/*ON*/)
		{
			nReadData = READ_DIGITAL(D_WS1_Control + _nWSNo, &nCommStatus);
			if (nReadData == DISC_HOME_CTRL)
			{
#pragma region Chuck Disc Motion (HOME)
				WRITE_ANALOG(A_WS1_Pos_Read + _nWSNo, 0, &nCommStatus);
				WRITE_ANALOG(A_WS1_Velocity + _nWSNo, 0.0, &nCommStatus);
				WRITE_ANALOG(A_WS1_Vel_Read + _nWSNo, 0.0, &nCommStatus);
				WRITE_DIGITAL(D_WS1_AtStation + _nWSNo, TURN_ON, &nCommStatus);
				WRITE_DIGITAL(D_WS1_HomeSts + _nWSNo, TURN_ON, &nCommStatus);
				WRITE_DIGITAL(D_WS1_RunSts + _nWSNo, 0/*IDLE*/, &nCommStatus);
				WRITE_DIGITAL(D_WS1_Control + _nWSNo, DISC_NONE, &nCommStatus);
#pragma endregion Chuck Disc Motion (HOME)

			}
			else if (nReadData == DISC_MOVE_CTRL)
			{
			    if (READ_DIGITAL(D_WS1_ContModeSts + _nWSNo, &nCommStatus) == 1)
			    {
				WS_Disc_Continuous_Simul(_nWSNo);
			    }
			    WRITE_DIGITAL(D_WS1_Control + _nWSNo, DISC_NONE, &nCommStatus);
			}
			else if (nReadData == DISC_STOP_CTRL)
			{
				WRITE_DIGITAL(D_WS1_Control + _nWSNo, DISC_NONE, &nCommStatus);
				WRITE_DIGITAL(D_WS1_RunSts + _nWSNo, 0/*IDLE*/, &nCommStatus);
				WRITE_ANALOG(A_WS1_Velocity + _nWSNo, 0, &nCommStatus);
				WRITE_ANALOG(A_WS1_Vel_Read + _nWSNo, 0, &nCommStatus);
			}
			else if (nReadData == DISC_TEACH_CTRL)
			{
				WRITE_ANALOG(A_WS1_Pos_Read + _nWSNo, 0.0, &nCommStatus);
				WRITE_DIGITAL(D_WS1_Control + _nWSNo, DISC_NONE, &nCommStatus);
			}
		}
		else
		{
			WRITE_DIGITAL(D_WS1_HomeSts + _nWSNo, 0/*OFF*/, &nCommStatus);
			WRITE_DIGITAL(D_WS1_RunSts + _nWSNo, 0/*IDLE*/, &nCommStatus);
		}

		_sleep(10);
		if (g_bTHREAD_END)	break;
	}
	_endthreadex(0);
	return;
}

//////////////////////////////////////////////////////////////////////////
//
//	WS_Disc_Continuous_Simul
//
//////////////////////////////////////////////////////////////////////////
void WS_Disc_Continuous_Simul(int _nWSNo)
{
	int		nCommStatus;
	double	dTargetVelocity, dCurrentVelocity;
	double	dStart_Area, dFinishArea;
	BOOL	bOnlyOne1 = TRUE;
	g_bChuck_Disc_STOP[_nWSNo] = FALSE;
	g_bChuck_Disc_ESTOP[_nWSNo] = FALSE;

	WRITE_DIGITAL(D_WS1_RunSts + _nWSNo, 1/*RUN*/, &nCommStatus);
	WRITE_DIGITAL(D_WS1_HomeSts + _nWSNo, TURN_OFF, &nCommStatus);
	WRITE_DIGITAL(D_WS1_AtStation + _nWSNo, TURN_OFF, &nCommStatus);

	dCurrentVelocity = fabs(READ_ANALOG(A_WS1_Vel_Read + _nWSNo, &nCommStatus));

	while (TRUE)
	{

		dTargetVelocity = fabs(READ_ANALOG(A_WS1_Velocity + _nWSNo, &nCommStatus));	//0~2500RPM
		g_bGO_signal = FALSE;

		if (dTargetVelocity > dCurrentVelocity)
		{
			if (bOnlyOne1)
			{
				dStart_Area = dCurrentVelocity + (dTargetVelocity - dCurrentVelocity) / 10;
				dFinishArea = dTargetVelocity - (dTargetVelocity - dCurrentVelocity) / 10;
				bOnlyOne1 = FALSE;
			}
			if (dStart_Area >= dCurrentVelocity)
				dCurrentVelocity += 1;
			else if (dFinishArea <= dCurrentVelocity)
			{
				dCurrentVelocity += 1;
				if (dTargetVelocity < dCurrentVelocity)
				{
					dCurrentVelocity = dTargetVelocity;
				}
			}
			else
				dCurrentVelocity += 50;
			WRITE_ANALOG(A_WS1_Vel_Read + _nWSNo, dCurrentVelocity, &nCommStatus);
		}
		else if (dTargetVelocity < dCurrentVelocity)
		{
			if (bOnlyOne1)
			{
				dStart_Area = dCurrentVelocity - (dCurrentVelocity - dTargetVelocity) / 10;
				dFinishArea = dTargetVelocity + (dCurrentVelocity - dTargetVelocity) / 10;
				bOnlyOne1 = FALSE;
			}
			if (dStart_Area <= dCurrentVelocity)
				dCurrentVelocity -= 1;
			else if (dFinishArea >= dCurrentVelocity)
			{
				dCurrentVelocity -= 1;
				if (dTargetVelocity > dCurrentVelocity)
				{
					dCurrentVelocity = dTargetVelocity;
				}
			}
			else{
			    dCurrentVelocity -= 50;
			}
			WRITE_ANALOG(A_WS1_Vel_Read + _nWSNo, dCurrentVelocity, &nCommStatus);
		}
	
		_sleep(10);
		if (dCurrentVelocity == 0 || READ_DIGITAL(D_WS1_Control + _nWSNo, &nCommStatus) == DISC_STOP_CTRL)
		{
			WRITE_DIGITAL(D_WS1_RunSts + _nWSNo, 0/*IDLE*/, &nCommStatus);
			break;
		}
		if (dCurrentVelocity == dTargetVelocity)
		{
		    break;
		}
	}
	return;
}