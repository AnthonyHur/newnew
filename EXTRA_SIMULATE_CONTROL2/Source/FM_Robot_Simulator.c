#include "iodefine.h"

/************************************************************************

	EFEM_Robot_Simulator( void* arg )

************************************************************************/
void EFEM_Robot_Simulator( void* _pArg )
{
	int		nCommStatus;
	int		nServoSts;
	int		nTransArmSet, nTransPosSts[2];

	WRITE_DIGITAL( D_FMRB_INIT , -1 , &nCommStatus );
	WRITE_DIGITAL( D_FMRB_SERVO , -1 , &nCommStatus );
	WRITE_DIGITAL( D_TRANS_PICK , -1 , &nCommStatus );
	WRITE_DIGITAL( D_TRANS_PLACE , -1 , &nCommStatus );
	WRITE_DIGITAL( D_TRANS_PREPICK , -1 , &nCommStatus );
	WRITE_DIGITAL( D_TRANS_PREPLACE , -1 , &nCommStatus );

	WRITE_DIGITAL( D_ROBOT_Init_Status , RB_INIT_OK_STS , &nCommStatus );
	WRITE_DIGITAL( D_ROBOT_Task_Status , NORMAL_STS , &nCommStatus );
	WRITE_DIGITAL( D_ROBOT_Run_Status , 0/*IDLE*/ , &nCommStatus );
	WRITE_DIGITAL( D_ROBOT_Servo_Status , TURN_ON_SERVO , &nCommStatus );

	WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
	WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
	
	while ( TRUE )
	{
		WRITE_DIGITAL( D_ROBOT_Run_Status , 0 , &nCommStatus ); // Idle

		nServoSts = READ_DIGITAL( D_FMRB_SERVO , &nCommStatus );
		if ( nServoSts >= 0 )
		{
			WRITE_DIGITAL( D_ROBOT_Servo_Status , nServoSts , &nCommStatus );
			WRITE_DIGITAL( D_FMRB_SERVO , -1 , &nCommStatus );
		}
		
		if ( READ_DIGITAL( D_ROBOT_Servo_Status , &nCommStatus ) == TURN_ON_SERVO )
		{
			// Home
			if		( READ_DIGITAL( D_FMRB_INIT , &nCommStatus ) >= 0 )		//  0 : Set
			{
				WRITE_DIGITAL( D_ROBOT_Run_Status , 1 , &nCommStatus );	 // Running
				_sleep(3000);
				WRITE_DIGITAL( D_ROBOT_Init_Status , RB_INIT_OK_STS , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Task_Status , NORMAL_STS , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_RETRACT , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Run_Status , 0 , &nCommStatus );	 // Idle
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_FMRB_INIT , -1 , &nCommStatus );	// Dummy
			}

			// Map
			if( ( g_RobotType == GENMARK ) && ( READ_DIGITAL( D_MAPPING , &nCommStatus ) >= 1 ) )			 // 0 : Set
			{   
				WRITE_DIGITAL( D_ROBOT_Run_Status , 1 , &nCommStatus );	 // Running
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_EXTEND , &nCommStatus );
				_sleep( 3000 );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_RETRACT , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Run_Status , 0 , &nCommStatus );	 // Idle
				WRITE_DIGITAL( D_MAPPING , 0 , &nCommStatus );
			}
			
			nTransArmSet = READ_DIGITAL( D_TRANS_PICK , &nCommStatus );		
			if ( nTransArmSet >= 0 )							// 0: MODE_ARM_ALL, 1: MODE_ARM_TOP, 2: MODE_ARM_BOTTOM
			{
				WRITE_DIGITAL( D_ROBOT_Run_Status , 1 , &nCommStatus );		// Running
				nTransPosSts[0] = READ_DIGITAL( D_U_SRC_POSITION , &nCommStatus );
				nTransPosSts[1] = READ_DIGITAL( D_L_SRC_POSITION , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , nTransPosSts[nTransArmSet-1] , &nCommStatus );
				Sleep( 2000 );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_EXTEND , &nCommStatus );
				if		( nTransArmSet == 1 )	WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_PRESNT , &nCommStatus );
				else if ( nTransArmSet == 2 )	WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_PRESNT , &nCommStatus );
				else
				{
					WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_PRESNT , &nCommStatus );
					WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_PRESNT , &nCommStatus );
				}
				Sleep( 2000 );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_RETRACT , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Run_Status , 0 , &nCommStatus );		// Idle
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_TRANS_PICK , -1 , &nCommStatus );			// Dummy
			}
			
			nTransArmSet = READ_DIGITAL( D_TRANS_PREPICK , &nCommStatus );		
			if ( nTransArmSet >= 0 )							// 0: MODE_ARM_ALL, 1: MODE_ARM_TOP, 2: MODE_ARM_BOTTOM
			{
				WRITE_DIGITAL( D_ROBOT_Run_Status , 1 , &nCommStatus );		// Running
				nTransPosSts[0] = READ_DIGITAL( D_U_SRC_POSITION , &nCommStatus );
				nTransPosSts[1] = READ_DIGITAL( D_L_SRC_POSITION , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , nTransPosSts[nTransArmSet-1] , &nCommStatus );
				Sleep( 2000 );
				WRITE_DIGITAL( D_ROBOT_Run_Status , 0 , &nCommStatus );		// Idle
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_TRANS_PREPICK , -1 , &nCommStatus );			// Dummy
			}
			
			nTransArmSet = READ_DIGITAL( D_TRANS_PLACE , &nCommStatus );		
			if ( nTransArmSet >= 0 )							// 0: MODE_ARM_ALL, 1: MODE_ARM_TOP, 2: MODE_ARM_BOTTOM
			{
				WRITE_DIGITAL( D_ROBOT_Run_Status , 1 , &nCommStatus );		// Running
				nTransPosSts[0] = READ_DIGITAL( D_U_TGT_POSITION , &nCommStatus );
				nTransPosSts[1] = READ_DIGITAL( D_L_TGT_POSITION , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , nTransPosSts[nTransArmSet-1] , &nCommStatus );
				Sleep( 2000 );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_EXTEND , &nCommStatus );
				if		( nTransArmSet == 1 )	WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
				else if ( nTransArmSet == 2 )	WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
				else
				{
					WRITE_DIGITAL( D_Upper_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
					WRITE_DIGITAL( D_Lower_Wafer_Status , RB_WFR_ABSENT , &nCommStatus );
				}
				Sleep( 2000 );
				WRITE_DIGITAL( D_ROBOT_Arm_Pos_Sts , RB_RETRACT , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Run_Status , 0 , &nCommStatus );		// Idle
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_TRANS_PLACE , -1 , &nCommStatus );			// Dummy
			}
			
			nTransArmSet = READ_DIGITAL( D_TRANS_PREPLACE , &nCommStatus );		
			if ( nTransArmSet >= 0 )							// 0: MODE_ARM_ALL, 1: MODE_ARM_TOP, 2: MODE_ARM_BOTTOM
			{
				WRITE_DIGITAL( D_ROBOT_Run_Status , 1 , &nCommStatus );		// Running
				nTransPosSts[0] = READ_DIGITAL( D_U_TGT_POSITION , &nCommStatus );
				nTransPosSts[1] = READ_DIGITAL( D_L_TGT_POSITION , &nCommStatus );
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , nTransPosSts[nTransArmSet-1] , &nCommStatus );
				Sleep( 2000 );
				WRITE_DIGITAL( D_ROBOT_Run_Status , 0 , &nCommStatus );		// Idle
				WRITE_DIGITAL( D_ROBOT_Arm_Stg_Sts , 0 , &nCommStatus );
				WRITE_DIGITAL( D_TRANS_PREPLACE , -1 , &nCommStatus );			// Dummy
			}
		}
		else
		{
			WRITE_DIGITAL( D_ROBOT_Init_Status , RB_NO_INIT_STS , &nCommStatus );
			WRITE_DIGITAL( D_ROBOT_Task_Status , ALARM_STS , &nCommStatus );
		}

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
	
	WRITE_DIGITAL( D_PreAlignerRunSts , ALN_IDLE_STS , &nCommStatus );
	WRITE_DIGITAL( D_PreAlignerVacSts , ALN_VAC_OFF , &nCommStatus );
	WRITE_DIGITAL( D_PreAlignerOKSts , ALN_NO_ALIGN , &nCommStatus );
	WRITE_DIGITAL( D_PreAlignStart , -1 , &nCommStatus );
	WRITE_DIGITAL( D_PreAlign_VacOnOff , -1 , &nCommStatus );

	WRITE_ANALOG( A_PreAlign_X_OffSet , 0.0 , &nCommStatus );
	WRITE_ANALOG( A_PreAlign_Y_OffSet , 0.0 , &nCommStatus );
	WRITE_ANALOG( A_PreAlign_AngleSts , 0.0 , &nCommStatus );
	
	while ( TRUE )
	{
		WRITE_DIGITAL( D_PreAlignerRunSts , ALN_IDLE_STS , &nCommStatus );

		nVacOffOn = READ_DIGITAL( D_PreAlign_VacOnOff , &nCommStatus );
		if( nVacOffOn >= 0 )
		{
			WRITE_DIGITAL( D_PreAlignerRunSts , ALN_RUN_STS , &nCommStatus );
			_sleep(1000);

			if ( READ_DIGITAL( D_CTC_PM5_Wafer_Status , &nCommStatus ) > 0 )
			{
				WRITE_DIGITAL( D_PreAlignerVacSts , nVacOffOn , &nCommStatus );
			}

			WRITE_DIGITAL( D_PreAlign_VacOnOff , -1 , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerRunSts , ALN_IDLE_STS , &nCommStatus );
		}

		if ( READ_DIGITAL( D_PreAlignStart , &nCommStatus ) >= 0 )	// 0 : Set
		{
			WRITE_ANALOG( A_PreAlign_AngleSts , 0.0 , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerOKSts , ALN_NO_ALIGN , &nCommStatus );
			dAngleValue = READ_ANALOG( A_PreAlign_AngleSet , &nCommStatus );

			WRITE_DIGITAL( D_PreAlignerRunSts , ALN_RUN_STS , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerVacSts , ALN_VAC_ON , &nCommStatus );
			_sleep(3000);
			WRITE_ANALOG( A_PreAlign_AngleSts , dAngleValue , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerOKSts , ALN_OK_ALIGN , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerVacSts , ALN_VAC_OFF , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignStart , -1 , &nCommStatus );
			WRITE_DIGITAL( D_PreAlignerRunSts , ALN_IDLE_STS , &nCommStatus );
		}

		_sleep(100);
		
		if ( g_bTHREAD_END )	break;
	}
	_endthreadex(0);
	return;
}