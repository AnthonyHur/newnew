#include "iodefine.h"
#include <Common/VC/CommonEnums.h>
#include <Common/VC/CommonLog.h>

/************************************************************************

	EFEM_Robot_Simulator( void* arg )

************************************************************************/

#define		DRIVER_LOG_DIRECTORY				".\\History\\Schedule"

char * GetLogSource()
{
	return "Simulator";
}

char * GetLogDirectory()
{
	return DRIVER_LOG_DIRECTORY;
}

void SetRobotBusy()
{
	int nCommStatus;
	LogInfoF("SetRobotMotionInProgress");
	WRITE_DIGITAL(D_ROBOT_Run_Status, 1, &nCommStatus);	 // Running
	WRITE_DIGITAL(D_RobotMotionState, MOTION_IN_PROGRESS, &nCommStatus);
}

void SetRobotMotionComplete()
{
	int nCommStatus;
	LogInfoF("SetRobotMotionComplete");
	WRITE_DIGITAL(D_ROBOT_Run_Status, 0/*IDLE*/, &nCommStatus);
	WRITE_DIGITAL(D_RobotMotionState, MOTION_COMPLETE, &nCommStatus);
	
}

void SetRobotIdle()
{
	int nCommStatus;
	LogInfoF("SetRobotMotionIdle");
	WRITE_DIGITAL(D_RobotMotionState, MOTION_IDLE, &nCommStatus);
}

void SetAlignerBusy()
{
	int nCommStatus;
	WRITE_DIGITAL(D_PreAlignerRunSts, 1, &nCommStatus);	 // Running
	WRITE_DIGITAL(D_AlignerMotionState, MOTION_IN_PROGRESS, &nCommStatus);
}


void SetFrAlignerBusy()
{
	int nCommStatus;
	WRITE_DIGITAL(D_FrameAligner_RunSts, ALN_RUN_STS, &nCommStatus);	 // Running
	WRITE_DIGITAL(D_FrameAligner_MotionState, MOTION_IN_PROGRESS, &nCommStatus);
	LogInfoF("SetFrAlignerBusy - complete");
}

void SetFrAlignerIdle()
{
	int nCommStatus;
	WRITE_DIGITAL(D_FrameAligner_RunSts, ALN_IDLE_STS, &nCommStatus);	 
	WRITE_DIGITAL(D_FrameAligner_MotionState, MOTION_IDLE, &nCommStatus);
	//WRITE_DIGITAL(D_FrameAligner_AlignmentState, 1, &nCommStatus);
	LogInfoF("SetFrAlignerIdle - complete");
}

void SetAlignerMotionComplete()
{
	int nCommStatus;
	WRITE_DIGITAL(D_PreAlignerRunSts, ALN_IDLE_STS, &nCommStatus);
	WRITE_DIGITAL(D_AlignerMotionState, MOTION_COMPLETE, &nCommStatus);
	LogInfoF("SetAlignerMotionComplete - complete");
}


void SetFrAlignerMotionComplete()
{
	int nCommStatus;
	WRITE_DIGITAL(D_FrameAligner_RunSts, ALN_IDLE_STS, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_MotionState, MOTION_COMPLETE, &nCommStatus);
	LogInfoF("SetFrAlignerMotionComplete - complete");
	
}

void SetFrAlignerAlignComplete()
{
	int nCommStatus;
	SetFrAlignerMotionComplete();
	LogInfoF("Setting AlignmentState to 2 (Complete) ");
	WRITE_DIGITAL(D_FrameAligner_AlignmentState, 2, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_LastAlState, 2, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_NotchFound, 1, &nCommStatus);
	LogInfoF("SetFrAlignerAlignComplete - complete");
	

}

void SetAlignerIdle()
{
	int nCommStatus;
	WRITE_DIGITAL(D_PreAlignerRunSts, 0/*IDLE*/, &nCommStatus);
	WRITE_DIGITAL(D_AlignerMotionState, MOTION_IDLE, &nCommStatus);
}


void EFEM_Robot_Simulator( void* _pArg )
{
	int		nCommStatus;
	int		nServoSts;
	int		nTransArmSet, nTransPosSts[2];
	double	dRobotSpeed, dRobotSpeedFactor;

	WRITE_DIGITAL( D_FMRB_INIT , -1 , &nCommStatus );
	WRITE_DIGITAL(D_FMRB_HOME, -1, &nCommStatus);

	WRITE_DIGITAL( D_FMRB_SERVO , TURN_ON_SERVO , &nCommStatus );
	WRITE_DIGITAL( D_TRANS_PICK , 3 , &nCommStatus );
	WRITE_DIGITAL( D_TRANS_PLACE , 3 , &nCommStatus );
	WRITE_DIGITAL( D_TRANS_PREPICK , -1 , &nCommStatus );
	WRITE_DIGITAL( D_TRANS_PREPLACE , -1 , &nCommStatus );
	WRITE_DIGITAL(D_RobotMotionCompleteAck, -1, &nCommStatus);
	

	WRITE_DIGITAL( D_ROBOT_Init_Status , RB_INIT_OK_STS , &nCommStatus );
	WRITE_DIGITAL( D_ROBOT_Task_Status , NORMAL_STS , &nCommStatus );
	SetRobotIdle();
	WRITE_DIGITAL( D_ROBOT_Servo_Status , TURN_ON_SERVO , &nCommStatus );

	WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
	WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
	
	while ( TRUE )
	{
		WRITE_DIGITAL(D_ROBOT_Run_Status, 0/*IDLE*/, &nCommStatus);
		dRobotSpeed = READ_DIGITAL( D_FMRB_SPEED , &nCommStatus );
		dRobotSpeedFactor = (12.1 * pow(dRobotSpeed,-0.56));

		nServoSts = READ_DIGITAL( D_FMRB_SERVO , &nCommStatus );
		if ( ( gSessionInfo.RobotType != SANKYO ) && ( nServoSts >= 0 ) )	// Sankyo robot cannot turn servo on by command
		{
			WRITE_DIGITAL( D_ROBOT_Servo_Status , nServoSts , &nCommStatus );
			WRITE_DIGITAL( D_FMRB_SERVO , TURN_ON_SERVO , &nCommStatus );
		}
		
		if ( READ_DIGITAL( D_ROBOT_Servo_Status , &nCommStatus ) == TURN_ON_SERVO )
		{
			// Home
			if (READ_DIGITAL(D_FMRB_INIT, &nCommStatus) >= 0 || READ_DIGITAL(D_FMRB_HOME, &nCommStatus) >= 0)		//  0 : Set
			{
				SetRobotBusy();
				_sleep(READ_DIGITAL(D_FMRB_INIT, &nCommStatus) >= 0 ? 1000 : 3000);
				WRITE_DIGITAL( D_ROBOT_Init_Status , RB_INIT_OK_STS , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Task_Status , NORMAL_STS , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_RETRACT , &nCommStatus );
				
				SetRobotMotionComplete();
				
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_FMRB_INIT , -1 , &nCommStatus );	// Dummy
				WRITE_DIGITAL(D_FMRB_HOME, -1, &nCommStatus);	// Dummy
			}

			if (READ_DIGITAL(D_VAC_ONOFF, &nCommStatus) >= 0)		//  0 : Set
			{
				SetRobotBusy();
				_sleep(500);
				
				SetRobotMotionComplete();
				WRITE_DIGITAL(D_VAC_ONOFF, -1, &nCommStatus);	// Dummy
				
			}

			if (READ_DIGITAL(D_RobotMotionCompleteAck, &nCommStatus) >= 0)
			{
				SetRobotIdle();
				WRITE_DIGITAL(D_RobotMotionCompleteAck, -1, &nCommStatus);
			}


			// Map
			if( ( gSessionInfo.RobotType == GENMARK ) && ( READ_DIGITAL( D_MAPPING , &nCommStatus ) >= 1 ) )			 // 0 : Set
			{   
				SetRobotBusy();
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_EXTEND , &nCommStatus );
				_sleep( 3000 );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_RETRACT , &nCommStatus );
				SetRobotMotionComplete();
				WRITE_DIGITAL( D_MAPPING , 0 , &nCommStatus );
			}
			
			nTransArmSet = READ_DIGITAL( D_TRANS_PICK , &nCommStatus );		
			if ( nTransArmSet < 3 )							// 0: MODE_ARM_ALL, 1: MODE_ARM_TOP, 2: MODE_ARM_BOTTOM
			{
				SetRobotBusy();
				
				nTransPosSts[0] = READ_DIGITAL( D_U_SRC_POSITION , &nCommStatus );
				nTransPosSts[1] = READ_DIGITAL( D_L_SRC_POSITION , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , nTransPosSts[nTransArmSet-1] , &nCommStatus );
				Sleep( (DWORD)((double)2000 * dRobotSpeedFactor) );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_EXTEND , &nCommStatus );
				if		( nTransArmSet == 1 )	WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_PRESNT , &nCommStatus );
				else if ( nTransArmSet == 2 )	WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_PRESNT , &nCommStatus );
				else
				{
					WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_PRESNT , &nCommStatus );
					WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_PRESNT , &nCommStatus );
				}
				Sleep( (DWORD)((double)2000 * dRobotSpeedFactor) );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_RETRACT , &nCommStatus );
				SetRobotMotionComplete();
				
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_TRANS_PICK , 3 , &nCommStatus );			// Dummy
			}
			
			nTransArmSet = READ_DIGITAL( D_TRANS_PREPICK , &nCommStatus );		
			if ( nTransArmSet >= 0 )							// 0: MODE_ARM_ALL, 1: MODE_ARM_TOP, 2: MODE_ARM_BOTTOM
			{
				SetRobotBusy();
				nTransPosSts[0] = READ_DIGITAL( D_U_SRC_POSITION , &nCommStatus );
				nTransPosSts[1] = READ_DIGITAL( D_L_SRC_POSITION , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , nTransPosSts[nTransArmSet-1] , &nCommStatus );
				Sleep( (DWORD)((double)2000 * dRobotSpeedFactor) );
				SetRobotMotionComplete();
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_TRANS_PREPICK , -1 , &nCommStatus );			// Dummy
			}
			
			nTransArmSet = READ_DIGITAL( D_TRANS_PLACE , &nCommStatus );		
			if ( nTransArmSet < 3 )							// 0: MODE_ARM_ALL, 1: MODE_ARM_TOP, 2: MODE_ARM_BOTTOM
			{
				SetRobotBusy();
				nTransPosSts[0] = READ_DIGITAL( D_U_TGT_POSITION , &nCommStatus );
				nTransPosSts[1] = READ_DIGITAL( D_L_TGT_POSITION , &nCommStatus );

				if (nTransArmSet == 1 || nTransArmSet == 2)
				{
				    WRITE_DIGITAL(D_ROBOT_Arm_Stg_Sts, nTransPosSts[nTransArmSet - 1], &nCommStatus);
				}
				
				Sleep( (DWORD)((double)2000 * dRobotSpeedFactor) );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_EXTEND , &nCommStatus );
				if		( nTransArmSet == 1 )	WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
				else if ( nTransArmSet == 2 )	WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
				else
				{
					WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
					WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
				}
				Sleep( (DWORD)((double)2000 * dRobotSpeedFactor) );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_RETRACT , &nCommStatus );
				SetRobotMotionComplete();
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_TRANS_PLACE , 3 , &nCommStatus );			// Dummy
			}
			
			nTransArmSet = READ_DIGITAL( D_TRANS_PREPLACE , &nCommStatus );		
			if ( nTransArmSet >= 0 )						// 0: MODE_ARM_ALL, 1: MODE_ARM_TOP, 2: MODE_ARM_BOTTOM
			{
				SetRobotBusy();
				nTransPosSts[0] = READ_DIGITAL( D_U_TGT_POSITION , &nCommStatus );
				nTransPosSts[1] = READ_DIGITAL( D_L_TGT_POSITION , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , nTransPosSts[nTransArmSet-1] , &nCommStatus );
				Sleep( (DWORD)((double)2000 * dRobotSpeedFactor) );
				SetRobotMotionComplete();
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_TRANS_PREPLACE , -1 , &nCommStatus );		// Dummy
			}
		}
		else
		{
			WRITE_DIGITAL( D_ROBOT_Init_Status , RB_NO_INIT_STS , &nCommStatus );
			WRITE_DIGITAL( D_ROBOT_Task_Status , ALARM_STS , &nCommStatus );
		}
		WRITE_DIGITAL(D_Wafer_Size, READ_DIGITAL(D_LP_Wafer_Size, &nCommStatus ) , &nCommStatus);
		

		_sleep(10);
		
		if ( g_bTHREAD_END )	break;
	}
	_endthreadex(0);
	return;
}

/************************************************************************

	Aligner_Simulator( void* arg )

************************************************************************/
void Aligner_Simulator( void* _pArg )
{
	int		nCommStatus;
	int		nVacOffOn;
	double	dAngleValue = 0.0;
	
	SetAlignerIdle();
	WRITE_DIGITAL( D_PreAlignerVacSts , ALN_VAC_OFF , &nCommStatus );
	WRITE_DIGITAL( D_PreAlignerOKSts , ALN_NO_ALIGN , &nCommStatus );
	WRITE_DIGITAL( D_PreAlignStart , -1 , &nCommStatus );
	WRITE_DIGITAL( D_PreAlign_VacOnOff , -1 , &nCommStatus );
	WRITE_DIGITAL( D_PreAlignerInit , -1 , &nCommStatus );
	WRITE_DIGITAL( D_PreAlignerServoSts, TURN_ON_SERVO, &nCommStatus );
	WRITE_DIGITAL( D_PreAlignerInitSts, ALN_INIT_COMPLETE, &nCommStatus );
	WRITE_ANALOG( A_PreAlign_X_OffSet , 0.0 , &nCommStatus );
	WRITE_ANALOG( A_PreAlign_Y_OffSet , 0.0 , &nCommStatus );
	WRITE_ANALOG( A_PreAlign_AngleSts , 0.0 , &nCommStatus );
	WRITE_DIGITAL(D_AlignerMotionCompleteAck, -1, &nCommStatus);
	
	while ( TRUE )
	{
		WRITE_DIGITAL(D_PreAlignerRunSts, 0/*IDLE*/, &nCommStatus);

		nVacOffOn = READ_DIGITAL( D_PreAlign_VacOnOff , &nCommStatus );
		if( nVacOffOn >= 0 )
		{
			SetAlignerBusy();
			_sleep(1000);
			
			WRITE_DIGITAL(D_PreAlignerVacValveSts, nVacOffOn, &nCommStatus);

			if ( READ_DIGITAL( D_CTC_PM5_Wafer_Status , &nCommStatus ) > 0 )
			{
				WRITE_DIGITAL( D_PreAlignerVacSts , nVacOffOn , &nCommStatus );
			}
			WRITE_DIGITAL(D_PreAlign_VacOnOff, -1, &nCommStatus);
			SetAlignerMotionComplete();
			
		}

		if (READ_DIGITAL(D_AlignerMotionCompleteAck, &nCommStatus) >= 0)
		{
			SetAlignerIdle();
			WRITE_DIGITAL(D_AlignerMotionCompleteAck, -1, &nCommStatus);
		}

		if ( READ_DIGITAL( D_PreAlignStart , &nCommStatus ) >= 0 )	// 0 : Set
		{
			//WRITE_ANALOG( A_PreAlign_AngleSts , 0.0 , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerOKSts , ALN_NO_ALIGN , &nCommStatus );
			dAngleValue = READ_ANALOG( A_PreAlign_AngleSet , &nCommStatus );

			SetAlignerBusy();
			
			WRITE_DIGITAL( D_PreAlignerVacSts , ALN_VAC_ON , &nCommStatus );
			_sleep(3000);
			WRITE_ANALOG( A_PreAlign_AngleSts , dAngleValue , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerOKSts , ALN_OK_ALIGN , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerVacSts , ALN_VAC_OFF , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignStart , -1 , &nCommStatus );
			SetAlignerMotionComplete();
		}

		if ( READ_DIGITAL( D_PreAlignerInit, &nCommStatus ) >= 0 )	// 0 : Set
		{
			WRITE_ANALOG( A_PreAlign_AngleSts, 0.0, &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerOKSts, ALN_NO_ALIGN, &nCommStatus );
			SetAlignerBusy();
			
			_sleep( 3000 );
			WRITE_DIGITAL( D_PreAlignerServoSts, TURN_ON_SERVO, &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerOKSts, ALN_OK_ALIGN, &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerInit, -1, &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerInitSts, ALN_INIT_COMPLETE, &nCommStatus );
			SetAlignerMotionComplete();
			
		}
		

		_sleep(100);
		
		if ( g_bTHREAD_END )	break;
	}
	_endthreadex(0);
	return;
}


void FrAligner_Simulator(void* _pArg)
{
	int		nCommStatus;
	

	SetAlignerIdle();
	WRITE_DIGITAL(D_FrameAligner_RunSts, 0, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_HomingState, 1, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_MotionState, 0, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_ServoSts, TURN_ON_SERVO, &nCommStatus);
	//WRITE_DIGITAL(D_FrameAligner_HomeSensorActive, 1, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_AlignmentState, 0, &nCommStatus);
	
	
	WRITE_DIGITAL(D_FrameAligner_Online, 1, &nCommStatus);
	

	WRITE_DIGITAL(D_FrameAligner_MotionCompleteAck, -1, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_AlignCompleteAck, -1, &nCommStatus);
	
//	WRITE_DIGITAL(D_FrameA_FingersIn, 0, &nCommStatus);
//	WRITE_DIGITAL(D_FrameA_FingersOut, 0, &nCommStatus);
	//Reset all outputs
	WRITE_DIGITAL(D_FrameA_SV1_FingersEngage, -1, &nCommStatus);
	WRITE_DIGITAL(D_FrameA_SV2_FingersDisengage, -1, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_MoveToZero, -1, &nCommStatus);
	WRITE_DIGITAL(D_FrameAligner_Align, -1, &nCommStatus);
	
	WRITE_DIGITAL(D_FrameAligner_AlignCompleteAck, -1, &nCommStatus);
	
	
	

	WRITE_DIGITAL(D_FrameA_FingersEngagedState, 0, &nCommStatus);
	WRITE_DIGITAL(D_FrameA_SV2_FingersDisengage, 0, &nCommStatus);

	WRITE_DIGITAL(D_FrameA_WaferPresent, 0, &nCommStatus);

	while (TRUE)
	{
		WRITE_DIGITAL(D_FrameAligner_RunSts, 0/*IDLE*/, &nCommStatus);
		//WRITE_DIGITAL(D_FrameAligner_AlignmentState, 0, &nCommStatus);


		if (READ_DIGITAL(D_CTC_PM8_Wafer_Status, &nCommStatus) > 0)
		{
			WRITE_DIGITAL(D_FrameA_WaferPresent, 1, &nCommStatus);
		}
		else
			WRITE_DIGITAL(D_FrameA_WaferPresent, 0, &nCommStatus);


		if (READ_DIGITAL(D_FrameAligner_MotionCompleteAck, &nCommStatus) >= 0)
		{
			LogInfoF("Received D_FrameAligner_MotionCompleteAck");
			SetFrAlignerIdle();
			WRITE_DIGITAL(D_FrameAligner_MotionCompleteAck, -1, &nCommStatus);
		}
		if (READ_DIGITAL(D_FrameAligner_AlignCompleteAck, &nCommStatus) >= 0)
		{
			LogInfoF("Received D_FrameAligner_AlignCompleteAck");
			SetFrAlignerIdle();
			LogInfoF("Setting AlignmentState to 0 (Idle) ");
			WRITE_DIGITAL(D_FrameAligner_AlignmentState, 0, &nCommStatus);
			WRITE_DIGITAL(D_FrameAligner_AlignCompleteAck, -1, &nCommStatus);
		}

		if (READ_DIGITAL(D_FrameAligner_Align, &nCommStatus) >= 0)	// 0 : Set
		{
			LogInfoF("Received D_FrameAligner_Align");
			SetFrAlignerBusy();
			LogInfoF("Setting AlignmentState to 1 (In progress) ");
			WRITE_DIGITAL(D_FrameAligner_AlignmentState, 1, &nCommStatus);  //In progress
			_sleep(2000);
			
			WRITE_DIGITAL(D_FrameAligner_Align, -1, &nCommStatus);
			SetFrAlignerAlignComplete();
			LogInfoF("Align complete");
		}

		if (READ_DIGITAL(D_FrameAligner_Initialize, &nCommStatus) >= 0)	// 0 : Set
		{
			LogInfoF("Received D_FrameAligner_Initialize");
			SetFrAlignerBusy();
			_sleep(2000);
			WRITE_DIGITAL(D_FrameAligner_Initialize, -1, &nCommStatus);
			WRITE_DIGITAL(D_FrameAligner_HomingState, 1, &nCommStatus);
			WRITE_DIGITAL(D_FrameAligner_Online, 1, &nCommStatus);
			
			//WRITE_DIGITAL(D_FrameAligner_InitState, ALN_INIT_COMPLETE, &nCommStatus);
			SetFrAlignerMotionComplete();
			LogInfoF("FrameAligner_Initialize complete");

		}
		if (READ_DIGITAL(D_FrameAligner_MoveToZero, &nCommStatus) >= 0)	// 0 : Set
		{
			LogInfoF("Received D_FrameAligner_MoveToZero");
			SetFrAlignerBusy();
			_sleep(2000);
			SetFrAlignerMotionComplete();
			WRITE_DIGITAL(D_FrameAligner_MoveToZero, -1, &nCommStatus);
			LogInfoF("FrameAligner_MoveToZero - complete");
			

		}

		//Fingers In
		if (READ_DIGITAL(D_FrameA_SV1_FingersEngage, &nCommStatus) == 1)	// Fingers In
		{
			LogInfoF("Received D_FrameA_SV1_FingersEngage 1");
			WRITE_DIGITAL(D_FrameA_FingersEngagedState, 1, &nCommStatus);
			//WRITE_DIGITAL(D_FrameA_FingersIn, 1, &nCommStatus);
			WRITE_DIGITAL(D_FrameA_SV1_FingersEngage, -1, &nCommStatus);
		
		}
		if (READ_DIGITAL(D_FrameA_SV1_FingersEngage, &nCommStatus) == 0)	
		{
			LogInfoF("Received D_FrameA_SV1_FingersEngage 0");
			WRITE_DIGITAL(D_FrameA_FingersEngagedState, 0, &nCommStatus);
			//WRITE_DIGITAL(D_FrameA_FingersIn, 0, &nCommStatus);
			WRITE_DIGITAL(D_FrameA_SV1_FingersEngage, -1, &nCommStatus);
		}

		if (READ_DIGITAL(D_FrameA_SV2_FingersDisengage, &nCommStatus) == 1 )	// // Fingers Out
		{
			LogInfoF("Received D_FrameA_SV2_FingersDisengage 1");
			WRITE_DIGITAL(D_FrameA_FingersDisengagedState, 1, &nCommStatus);
			//WRITE_DIGITAL(D_FrameA_FingersOut, 1, &nCommStatus);
			WRITE_DIGITAL(D_FrameA_SV2_FingersDisengage, -1, &nCommStatus);  //reser it 
		}

		if (READ_DIGITAL(D_FrameA_SV2_FingersDisengage, &nCommStatus) == 0)	// 0 : Set
		{
			LogInfoF("Received D_FrameA_SV2_FingersDisengage 0");
			WRITE_DIGITAL(D_FrameA_FingersDisengagedState, 0, &nCommStatus);
			//WRITE_DIGITAL(D_FrameA_FingersOut, 0, &nCommStatus);
			WRITE_DIGITAL(D_FrameA_SV2_FingersDisengage, -1, &nCommStatus);  //reset it 
		}


		//if (READ_DIGITAL(D_FrameA_BackSensorState, &nCommStatus) == 1)	// 0 : Set
		//{
		//	WRITE_DIGITAL(D_FrameA_WaferPresent, 1, &nCommStatus);
		//}
		//else
		//	WRITE_DIGITAL(D_FrameA_WaferPresent, 0, &nCommStatus);

		_sleep(100);

		if (g_bTHREAD_END)	break;
	}
	_endthreadex(0);
	return;
}