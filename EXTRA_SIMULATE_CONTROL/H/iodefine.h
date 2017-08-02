#ifndef IODEFINE_H
#define IODEFINE_H

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include <math.h>

#include <Kutlstr.h>
#include <Kutltime.h>

#include "cimseqnc.h"

#include <Common/VC/CommonEnums.h>
#include <Common/VC/CommonSessionInfo.h>
#include <Common/VC/CommonIOMethods.h>

extern SessionInfo gSessionInfo;

typedef enum {

	/////////////////////////////
	D_OpticalLeakUsage			,
	D_IonizerUsage				,
	D_Bubbler_Type				,
	D_Bubbler_Auto_Fill			,
	D_Cont_Bubbler_Sensor_Usage	,
	D_Bubbler2_Usage			,
	D_FADetectorUsage			,
	D_PM_Module_Type			,
	D_Aligner2Type,

	D_CTC_PM1_Wafer_Status		,
	D_CTC_PM1_Wafer_Status2		,
	D_CTC_PM1_Wafer_Status3		,
	D_CTC_PM1_Wafer_Status4		,
	D_CTC_PM1_Wafer_Status5		,
	D_CTC_PM1_Wafer_Status6		,
	D_CTC_PM5_Wafer_Status		,
	D_CTC_PM8_Wafer_Status,


	/////////////////////////////
	D_EFEM_SIDEDOOR				,


	/////////////////////////////
	D_PORT1_Run_Status			,
	D_PORT2_Run_Status			,
	D_PORT3_Run_Status			,
	D_PORT1_CarrStatus			,
	D_PORT2_CarrStatus			,
	D_PORT3_CarrStatus			,
	D_PORT1_DoorStatus			,
	D_PORT2_DoorStatus			,
	D_PORT3_DoorStatus			,
	D_PORT1_ClampStatus			,
	D_PORT2_ClampStatus			,
	D_PORT3_ClampStatus			,
	D_PORT1_DockStatus			,
	D_PORT2_DockStatus			,
	D_PORT3_DockStatus			,
	D_PORT1_INIT_STATUS			,
	D_PORT2_INIT_STATUS			,
	D_PORT3_INIT_STATUS			,
	S_PORT1_MAP_DATA			,
	S_PORT2_MAP_DATA			,
	S_PORT3_MAP_DATA			,

	D_PORT1_Control				,
	D_PORT2_Control				,
	D_PORT3_Control				,

	D_PORT1_CanMap,
	D_PORT2_CanMap,
	D_PORT3_CanMap,

	D_LP_Carrier_Capacity,

	/////////////////////////////

	D_AMHS1_PV_LREQ				,
	D_AMHS2_PV_LREQ				,
	D_AMHS3_PV_LREQ				,
	D_AMHS1_PV_UREQ				,
	D_AMHS2_PV_UREQ				,
	D_AMHS3_PV_UREQ				,
	D_AMHS1_PV_READY			,
	D_AMHS2_PV_READY			,
	D_AMHS3_PV_READY			,
	D_AMHS1_PV_HO_AVBL			,
	D_AMHS2_PV_HO_AVBL			,
	D_AMHS3_PV_HO_AVBL			,
	D_AMHS1_PV_ES				,
	D_AMHS2_PV_ES				,
	D_AMHS3_PV_ES				,

	D_AMHS1_AV_VALID			,
	D_AMHS2_AV_VALID			,
	D_AMHS3_AV_VALID			,
	D_AMHS1_AV_CS_0				,
	D_AMHS2_AV_CS_0				,
	D_AMHS3_AV_CS_0				,
	D_AMHS1_AV_CS_1				,
	D_AMHS2_AV_CS_1				,
	D_AMHS3_AV_CS_1				,
	D_AMHS1_AV_TR_REQ			,
	D_AMHS2_AV_TR_REQ			,
	D_AMHS3_AV_TR_REQ			,
	D_AMHS1_AV_BUSY				,
	D_AMHS2_AV_BUSY				,
	D_AMHS3_AV_BUSY				,
	D_AMHS1_AV_COMPT			,
	D_AMHS2_AV_COMPT			,
	D_AMHS3_AV_COMPT			,
	D_AMHS1_AV_CONT				,
	D_AMHS2_AV_CONT				,
	D_AMHS3_AV_CONT				,

	D_Light_Curtain_Sts			,

	A_AMHS_TP1_TIMEOUT			,
	A_AMHS_TP2_TIMEOUT			,
	A_AMHS_TP3_TIMEOUT			,
	A_AMHS_TP4_TIMEOUT			,
	A_AMHS_TP5_TIMEOUT			,
	A_AMHS_TP6_TIMEOUT			,

	D_AMHS1_SIMULATION_LOAD		,
	D_AMHS2_SIMULATION_LOAD		,
	D_AMHS3_SIMULATION_LOAD		,

	D_CTC_FA_STATUS_AGV_CM1		,
	D_CTC_FA_STATUS_AGV_CM2		,
	D_CTC_FA_STATUS_AGV_CM3		,

	D_PORT1_AMHSModeSts			,
	D_PORT2_AMHSModeSts			,
	D_PORT3_AMHSModeSts			,


	/////////////////////////////
	D_FMRB_INIT					,
	D_FMRB_HOME,
	D_FMRB_SERVO				,
	D_FMRB_SPEED				,
	D_ROBOT_Init_Status			,
	D_ROBOT_Task_Status			,
	D_ROBOT_Run_Status			,
	D_ROBOT_Servo_Status		,
	D_Upper_Wafer_Status		,
	D_Lower_Wafer_Status		,
	D_ROBOT_Arm_Pos_Sts			,
	D_ROBOT_Arm_Stg_Sts			,
	D_TRANS_PICK				,
	D_TRANS_PLACE				,
	D_TRANS_PREPICK				,
	D_TRANS_PREPLACE			,
	D_U_SRC_POSITION			,
	D_L_SRC_POSITION			,
	D_U_TGT_POSITION			,
	D_L_TGT_POSITION			,
	D_RobotMotionState,
	D_RobotMotionCompleteAck,
	D_AlignerMotionCompleteAck,

	/////////////////////////////
	D_PreAlignerRunSts			,
	D_PreAlignerVacSts			,
	D_PreAlignerVacValveSts,
	D_PreAlignerOKSts			,
	D_PreAlignStart				,
	D_PreAlign_VacOnOff			,
	A_PreAlign_X_OffSet			,
	A_PreAlign_Y_OffSet			,
	A_PreAlign_AngleSts			,
	A_PreAlign_AngleSet			,
	//MILARA
	D_PreAlignerInitSts			,
	D_PreAlignerServoSts		,
	D_PreAlignerInit			,
	D_AlignerMotionState,

	/////////////////////////////

	D_PM_LL_PurgeState			,
	D_LL_Door_Ctrl				,
	D_LL_Door_Sts				,

	D_LL_Ring_Seal_Vac_Ctrl		,
	D_LL_Ring_Seal_Vac_Sts		,
	D_LL_Door_Seal_Vac_Ctrl		,
	D_LL_Door_Seal_Vac_Sts		,
	D_LL_Evacuate_Vv			,
	D_LL_Evacuate_Vv_Sts		,
	D_LL_Purge_Vv				,
	D_LL_Purge_Vv_Sts			,

	A_Ring_Seal					,
	A_Door_Seal					,

	/////////////////////////////
	D_Bubbler_ManualVvSts		,
	D_Bubbler_LowLmt_Lvl		,
	D_Bubbler_Low_Lvl			,
	D_Bubbler_High_Lvl			,
	D_Bubbler_HighLmt_Lvl		,
	D_Bubbler_Leak_Sts			,
	D_Bubbler_LeakOptcSts		,
	D_Bubbler2_ManualVvSts		,
	D_Bubbler2_LowLmt_Lvl		,
	D_Bubbler2_Low_Lvl			,
	D_Bubbler2_High_Lvl			,
	D_Bubbler2_HighLmt_Lvl		,
	D_Bubbler2_Leak_Sts			,
	D_Bubbler2_LeakOptcSts		,
	D_Chmbr_Lock_Vv				,
	D_Chmbr_Lock_Vv_Sts			,
	D_PM_Cover_Sts				,
	D_Fac_PCW_Flow_Sts			,
	A_Fac_PCW_Flow_Rate			,
	D_Fac_VAC_Press_Sts			,
	A_Fac_Vacuum_Press			,
	D_Fac_CDA_Press_Sts			,
	A_Fac_CDA_Press				,
	D_Gas_Box_Door_Sts			,
	D_Process_Exhst_Sts			,
	A_Process_Exhst_Press		,
	D_Gas_Box_Exhst_Sts			,
	A_Gas_Box_Exhst_Press		,
	D_Cabinet_Exhst_Sts			,
	A_Cabinet_Exhst_Press		,
	D_Water_Leak				,
	D_Bulkfill_SupplyRun		,
	D_Bulkfill_SupplyReady		,
	D_Chuck1_LT_LimitTemp		,
	D_Chuck2_LT_LimitTemp		,
	D_Chuck3_LT_LimitTemp		,
	D_Chuck4_LT_LimitTemp		,
	D_Insul1_LT_LimitTemp		,
	D_Insul2_LT_LimitTemp		,
	D_Insul3_LT_LimitTemp		,
	D_Insul4_LT_LimitTemp		,
	D_Elbow1_LT_LimitTemp		,
	D_Elbow2_LT_LimitTemp		,
	D_Elbow3_LT_LimitTemp		,
	D_Elbow4_LT_LimitTemp		,
	D_Bublr1_LT_LimitTemp		,
	D_Bublr2_LT_LimitTemp		,
	D_Chuck1_LT_TC_Broken		,
	D_Chuck2_LT_TC_Broken		,
	D_Chuck3_LT_TC_Broken		,
	D_Chuck4_LT_TC_Broken		,
	D_Insul1_LT_TC_Broken		,
	D_Insul2_LT_TC_Broken		,
	D_Insul3_LT_TC_Broken		,
	D_Insul4_LT_TC_Broken		,
	D_Elbow1_LT_TC_Broken		,
	D_Elbow2_LT_TC_Broken		,
	D_Elbow3_LT_TC_Broken		,
	D_Elbow4_LT_TC_Broken		,
	D_Bublr1_LT_TC_Broken		,
	D_Bublr2_LT_TC_Broken		,
	D_WS_Leak_Sensor			,
	D_Hi_DI_Res_Meter			,
	A_WS_Hi_DI_Pressure			,
	D_WS1_Drain_Lvl_Sts			,
	D_WS2_Drain_Lvl_Sts			,
	D_Scrubber_Warning			,
	D_Scrubber_Trouble			,
	D_Scrubber_Treatmentable	,
	D_Ionizer_Status			,

	D_O2_Sample_Vv				,
	D_O2_Sample_Vv_Sts			,
	A_O2LevelRead				,

	A_N2_Press_Transducer		,
	A_N2_Purge_Press_Transducer	,
	A_ContBubbler_Level			,
	A_ContBubbler2_Level		,
	D_ContBubbler_Refill		,
	A_O2_Press_Transducer		,

	D_Stg1_Wfr_Sns_Vac			,
	D_Stg2_Wfr_Sns_Vac			,
	D_Stg3_Wfr_Sns_Vac			,
	D_Stg4_Wfr_Sns_Vac			,
	D_Stg5_Wfr_Sns_Vac			,
	D_Stg6_Wfr_Sns_Vac			,

	D_Stg1_Wfr_Sns_Sts			,
	D_Stg2_Wfr_Sns_Sts			,
	D_Stg3_Wfr_Sns_Sts			,
	D_Stg4_Wfr_Sns_Sts			,
	D_Stg5_Wfr_Sns_Sts			,
	D_Stg6_Wfr_Sns_Sts			,

	D_Chuck1_UP_Ctrl			,
	D_Chuck2_UP_Ctrl			,
	D_Chuck3_UP_Ctrl			,
	D_Chuck4_UP_Ctrl			,
	D_Chuck5_UP_Ctrl			,
	D_Chuck6_UP_Ctrl			,
	D_Chuck6_DN_Ctrl			,

	D_Chuck1_Pos_Sts			,
	D_Chuck2_Pos_Sts			,
	D_Chuck3_Pos_Sts			,
	D_Chuck4_Pos_Sts			,
	D_Chuck5_Pos_Sts			,
	D_Chuck6_Pos_Sts			,

	D_VacHeat_Vac_Vv			,
	D_VacHeat_Vac_Vv_Sts		,
	D_VacHeat_Exhst_Vv			,
	D_VacHeat_Exhst_Vv_Sts		,
	D_VacHeat_Vent_Vv			,
	D_VacHeat_Vent_Vv_Sts		,
	D_VacHeat_PrcGasISOSts		,
	D_VacHeat_ExhstISOSts		,
	D_VacHeat_VacIsoB_Sts		,
	D_VacHeat_VacIsoB_Vv		,
	D_VacHeat_GasIsoB_Sts		,
	D_VacHeat_GasIsoB_Vv		,

	D_Cool_LowPurgeVv			,
	D_Cool_LowPurgeVvSts		,

	D_FA_Gas_Detect_Fail		,
	D_FA_Gas_Leak_Warning		,
	D_FA_Gas_Leak_Alarm			,

	D_Bubbler_Door				,
	D_Gas_Leak_Alarm			,

	D_FA_Valve_Spill			,

	A_Fac_PCW_Inlet_Temp		,
	A_Fac_PCW_Outlet_Temp		,

	/*
	D_WS_Fac_DI_Sts				,
	D_WS_Fac_ACID_Sts			,
	D_WS_Fac_HIDI_Sts			,
	D_WS_ACID_Avail				,
	

	WS1_Exhaust_Flow,
	WS2_Exhaust_Flow,
	*/
	D_Bubbler_Fill_Vv			,
	D_Bubbler2_Fill_Vv			,

	/////////////////////////////
	D_Bubbler_Bypass_Vv			,
	D_Bubbler_Vent_Vv			,
	D_Bubbler_Feed_Vv			,
	D_Bubbler_FeedVv_Sts		,
	D_Bubbler_Dlvry_Vv			,
	D_Bubbler_DlvryVv_Sts		,
	D_Bubbler2_Vent_Vv			,
	D_Bubbler2_Feed_Vv			,
	D_Bubbler2_FeedVv_Sts		,
	D_Bubbler2_Dlvry_Vv			,
	D_Bubbler2_DlvryVv_Sts		,

	D_FA_Line_Vent_Vv			,
	D_FA_Line_Vent_Sts			,
	D_FA2_Line_Vent_Vv			,
	D_FA2_Line_Vent_Sts			,

	D_PM_Odometer_FA_Need		,
	D_Bubbler_Exhst_Sts			,

	/////////////////////////////
	D_Chuck1_Heater_Pwr			,
	D_Chuck2_Heater_Pwr			,
	D_Chuck3_Heater_Pwr			,
	D_Chuck4_Heater_Pwr			,

	D_Chuck1_Heater_PwrSts		,
	D_Chuck2_Heater_PwrSts		,
	D_Chuck3_Heater_PwrSts		,
	D_Chuck4_Heater_PwrSts		,

	A_Chuck1_Temp_Set			,
	A_Chuck2_Temp_Set			,
	A_Chuck3_Temp_Set			,
	A_Chuck4_Temp_Set			,

	A_Chuck1_Temp_Mnt			,
	A_Chuck2_Temp_Mnt			,
	A_Chuck3_Temp_Mnt			,
	A_Chuck4_Temp_Mnt			,
	A_Chuck5_Temp_Mnt			,

	D_Insul1_Heater_Pwr			,
	D_Insul2_Heater_Pwr			,
	D_Insul3_Heater_Pwr			,
	D_Insul4_Heater_Pwr			,

	D_Insul1_Heater_PwrSts		,
	D_Insul2_Heater_PwrSts		,
	D_Insul3_Heater_PwrSts		,
	D_Insul4_Heater_PwrSts		,

	A_Insul1_Temp_Set			,
	A_Insul2_Temp_Set			,
	A_Insul3_Temp_Set			,
	A_Insul4_Temp_Set			,

	A_Insul1_Temp_Mnt			,
	A_Insul2_Temp_Mnt			,
	A_Insul3_Temp_Mnt			,
	A_Insul4_Temp_Mnt			,

	D_Elbow1_Heater_Pwr			,
	D_Elbow2_Heater_Pwr			,
	D_Elbow3_Heater_Pwr			,
	D_Elbow4_Heater_Pwr			,

	D_Elbow1_Heater_PwrSts		,
	D_Elbow2_Heater_PwrSts		,
	D_Elbow3_Heater_PwrSts		,
	D_Elbow4_Heater_PwrSts		,

	A_Elbow1_Temp_Set			,
	A_Elbow2_Temp_Set			,
	A_Elbow3_Temp_Set			,
	A_Elbow4_Temp_Set			,

	A_Elbow1_Temp_Mnt			,
	A_Elbow2_Temp_Mnt			,
	A_Elbow3_Temp_Mnt			,
	A_Elbow4_Temp_Mnt			,

	D_Bublr1_Heater_Pwr			,
	D_Bublr2_Heater_Pwr			,

	D_Bublr1_Heater_PwrSts		,
	D_Bublr2_Heater_PwrSts		,

	A_Bublr1_Temp_Set			,
	A_Bublr2_Temp_Set			,

	A_Bublr1_Temp_Mnt			,
	A_Bublr2_Temp_Mnt			,

	A_ProfileTC_Temp_Mnt		,


	/////////////////////////////
	D_Disc_ServoSts				,
	D_Disc_Servo				,
	D_Disc_HomeSts				,
	D_Disc_HomSnsActv			,
	D_Disc_RunSts				,
	D_Disc_Motor_Amp			,
	D_Disc_AtStation			,
	A_Disc_Pos_Read				,
	A_Disc_Pos_Degree			,

	D_Disc_MotionMode			,
	D_Disc_PosModeSts			,
	A_Disc_Distance				,
	D_Disc_Control				,


	/////////////////////////////
	A_MFC1_Monitor				,
	A_MFC2_Monitor				,
	A_MFC3_Monitor				,
	A_MFC4_Monitor				,
	A_MFC5_Monitor				,
	A_MFC6_Monitor				,
	A_MFC1_Set					,
	A_MFC2_Set					,
	A_MFC3_Set					,
	A_MFC4_Set					,
	A_MFC5_Set					,
	A_MFC6_Set					,
	D_Gas1_Vv					,
	D_Gas2_Vv					,
	D_Gas3_Vv					,
	D_Gas4_Vv					,
	D_Gas5_Vv					,
	D_Gas6_Vv					,


	/////////////////////////////

	D_Prcs_APC_Ctrl_Mode		,
	D_Prcs_APC_Close_Vv_Sts		,
	D_Prcs_APC_Open_Vv_Sts		,
	D_Prcs_APC_Set_Type			,
	A_Prcs_APC_Vv_Position		,
	A_Prcs_APC_Press_Read		,
	A_Prcs_APC_SetPoint			,

	D_LL_APC_Ctrl_Mode			,
	D_LL_APC_Close_Vv_Sts		,
	D_LL_APC_Open_Vv_Sts		,
	D_LL_APC_Set_Type			,
	A_LL_APC_Vv_Position		,
	A_LL_APC_Press_Read			,
	A_LL_APC_SetPoint			,

	A_Convect_Press				,
	A_Convect_2_Press,
	S_Convect_Revision,
	D_VacHeat_ATM_Sensor,

	
	D_WS1_Door_Sts,
	D_WS2_Door_Sts,
	D_WS1_Door_Ctrl,
	D_WS2_Door_Ctrl,
	D_WS1_Arm_Pos_Sts,
	D_WS2_Arm_Pos_Sts,
	D_WS1_Arm_Pos_Ctrl,
	D_WS2_Arm_Pos_Ctrl,
	D_WS1_Arm_Home_Sts,
	D_WS2_Arm_Home_Sts,
	D_WS1_ArmHome,
	D_WS2_ArmHome,

	D_WS1_ACID_Flow_Sts,
	D_WS2_ACID_Flow_Sts,
	D_WS1_DI_Flow_Sts,
	D_WS2_DI_Flow_Sts,
	D_WS1_N2_Blow_Sts,
	D_WS2_N2_Blow_Sts,
	D_WS1_HIDI_Flow_Sts,
	D_WS2_HIDI_Flow_Sts,
	D_WS1_Back_Side_Sts,
	D_WS2_Back_Side_Sts,
	D_WS1_ACID_Flow,
	D_WS2_ACID_Flow,
	D_WS1_DI_Flow,
	D_WS2_DI_Flow,
	D_WS1_N2_Blow,
	D_WS2_N2_Blow,
	D_WS1_HIDI_Flow,
	D_WS2_HIDI_Flow,
	D_WS1_Back_Side,
	D_WS2_Back_Side,

	A_WS1_Flow_Sensor,
	A_WS2_Flow_Sensor,

	D_WS1_Grip_On,
	D_WS2_Grip_On,
	D_WS1_Grip_On_Sts,
	D_WS2_Grip_On_Sts,

	D_WS1_Pin_Ctrl,
	D_WS2_Pin_Ctrl,
	D_WS1_Pin_Sts,
	D_WS2_Pin_Sts,

	D_WS1_RunSts,
	D_WS2_RunSts,
	D_WS1_HomeSts,
	D_WS2_HomeSts,
	D_WS1_PosModeSts,
	D_WS2_PosModeSts,
	D_WS1_ContModeSts,
	D_WS2_ContModeSts,
	D_WS1_ServoSts,
	D_WS2_ServoSts,
	D_WS1_Pos_Error,
	D_WS2_Pos_Error,
	D_WS1_AtStation,
	D_WS2_AtStation,
	D_WS1_Motor_Amp,
	D_WS2_Motor_Amp,
	D_WS1_MotionMode,
	D_WS2_MotionMode,
	D_WS1_ContMode,
	D_WS2_ContMode,
	D_WS1_Control,
	D_WS2_Control,
	D_WS1_Servo,
	D_WS2_Servo,
	D_WS1_DefinePos_0,
	D_WS2_DefinePos_0,
	A_WS1_Pos_Read,
	A_WS2_Pos_Read,
	A_WS1_Vel_Read,
	A_WS2_Vel_Read,
	A_WS1_Distance,
	A_WS2_Distance,
	A_WS1_Velocity,
	A_WS2_Velocity,

	D_AutoCalibration_Run		,

	// D_IO_Driver_Loding			,
	D_MAPPING					,
	//D_FM_ROBOT_TYPE				,
	D_Bulkfill_Error			,

	AI_WS1_Gas,
	AI_WS2_Gas,
	AO_WS1_Gas,
	AO_WS2_Gas,

	DI_WS1_Liq_empty,
	DI_WS2_Liq_empty,

	WS_CO2_Flow,
	WS_CO2_Flow_Sts,
	AI_CO2_Gas,
	AO_CO2_Gas,

	Bulkfill_Leak,
	WS_Bulk_Fill_level,

	WS_Fac_Vac,
	WS_N2,
	WS_CDA,

	//Frame aligner
	//disc State
	D_FrameAligner_RunSts,
	D_FrameAligner_ServoSts,
	S_FrameAligner_ErrText,
	D_FrameAligner_Online,
	D_FrameAligner_HomingState,
	D_FrameAligner_AlignmentState,
	D_FrameAligner_AlignCompleteAck,
	A_FrameAligner_Pos_Degree,
	D_FrameAligner_LastAlState,
	D_FrameAligner_MotionState,
	D_FrameAligner_MotionCompleteAck,
	D_FrameAligner_NotchFound,

	//Commands
	D_FrameAligner_Initialize,
	D_FrameAligner_Align,
	D_FrameAligner_Stop,
	D_FrameAligner_MoveToZero,
	//Festo inputs
	D_FrameA_CDA_Input,
	D_FrameA_FingersEngagedState,
	D_FrameA_FingersDisengagedState,
	D_FrameA_BackSensorState,
	D_FrameA_LeftSensorState,
	D_FrameA_RightSensorState,
	D_FrameA_FrontSensorState,
	D_FrameA_WaferPresent,
	//D_FrameA_FingersIn,
	//D_FrameA_FingersOut,
	//Festo outputs	
	D_FrameA_SV1_FingersEngage,
	D_FrameA_SV2_FingersDisengage,

	D_LP_Wafer_Size,
	D_Wafer_Size,
	D_Adapter_Ring,
	D_Carrier_Tray_Sns1,
	D_Carrier_Tray_Sns2,

	D_GenevaBOption,
	D_Conv_Purge_Vv_Sts			,
	D_Conv2_Purge_Vv_Sts		,

    D_VacPump_Exh_IO			,
    D_Smoke_Detector_Sts		,
    D_PD_Box_DC_Fan_Sts			,
    D_PM_ELT_Box_DC_Fan_Sts		,
    D_Ionizer2_Sts				,
	A_CDA_Pressure_Ionizer1		,
	A_CDA_Pressure_Ionizer2		,

	D_PM_Press_Units			,
	D_VAC_ONOFF,



} IOPointIndex;

BOOL		g_bGO_signal;
BOOL		g_bTHREAD_END, g_bChuck_Disc_STOP[2], g_bChuck_Disc_ESTOP[2];
HANDLE		g_hLoadPortThread[3], g_hAMHSThread[3], g_hRobotThread, g_hAlignerThread, g_hFrAlignerThread, g_hStationThread[6];
HANDLE		g_hDiscMotionThread, g_hPressThread, g_hAutoFillThread, g_hWetStationThread[2];

/************************************************************************

	Enum

************************************************************************/
typedef enum { LoadPort1, LoadPort2, LoadPort3, LoadPort4 } LOADPORT_No;
typedef enum { SIM_NONE , UNLOAD , LOAD } AMHS_SIM_LOAD;
typedef enum { LP_COMFAIL_STS , LP_IDLE_STS , LP_RUN_STS , LP_ERR_STS } LPx_RUNSTS;
typedef enum { CARR_UNKNOWN_STS , CARR_ABSENT_STS , CARR_PRESENT_STS } LPx_CARRSTS;
typedef enum { DOOR_UNKNOWN_STS , DOOR_CLOSE_STS , DOOR_OPEN_STS } LPx_DOORSTS;
typedef enum { CLMP_UNKNOWN_STS , CLMP_UNCLAMP_STS , CLMP_CLAMP_STS } LPx_CLAMPSTS;
typedef enum { DOCK_UNKNOWN_STS , UNDOCKED_STS , DOCKED_STS } LPx_DOCKSTS;
typedef enum { LP_NO_INIT_STS , LP_INIT_OK_STS }LPx_INITSTS;
typedef enum { LLDOR_UNKNOWN_STS , LLDOR_OPEN_STS , LLDOR_CLOSE_STS } LL_DOORSTS;
typedef enum { LP_HOME , LP_LOAD , LP_UNLOAD , LP_CLAMP , LP_UNCLAMP , LP_CLOSE , LP_OPEN, LP_UNLOAD_AND_MAP } LPx_CONTROL;
typedef enum { RB_INIT_OK_STS , RB_NO_INIT_STS }ROBOT_INITSTS;
typedef enum { RB_WFR_ABSENT , RB_WFR_PRESNT } ROBOT_WAFER_STS;
typedef enum { RB_RETRACT , RB_EXTEND } ROBOT_ARM_POS;
typedef	enum { TURN_OFF_SERVO , TURN_ON_SERVO } FM_ROBOT_SERVO;
typedef enum { ALARM_STS , NORMAL_STS } ALRAM_NORMAL_STS;
typedef enum { AMHS_OFF , AMHS_ON } AMHS_SIGNAL;
typedef enum { AMHS_MANUAL , AMHS_AUTO } AMHS_MAN_AUTO;
typedef enum { ALN_IDLE_STS , ALN_RUN_STS } ALIGN_RUN_STS;
typedef enum { ALN_NO_ALIGN , ALN_OK_ALIGN , ALN_ERR_ALIGN } ALIGN_OK_STS;
typedef enum { ALN_INIT_COMPLETE, ALN_NeedINIT  } ALIGN_INIT_STS;
typedef enum { ALN_VAC_OFF , ALN_VAC_ON } ALIGN_VAC_STS;
typedef enum { DISC_HOME_CTRL , DISC_MOVE_CTRL , DISC_STOP_CTRL , DISC_ESTOP_CTRL , DISC_TEACH_CTRL, DISC_NONE } DISC_CTRL;
typedef enum { TURN_OFF, TURN_ON } TURN_OFFON;
typedef enum { UNKNOWN_POS, CENTRE_POS, EDGE_POS } ARM_POS_STS;
typedef enum { MANUAL_BUBBLER, AUTOFILL_BUBBLER } BUBBLER_TYPE;

void ServiceSimulateFlags();
extern int g_SimulateConvectrons;

void EFEM_Robot_Simulator( void* _pArg );
void Aligner_Simulator( void* _pArg );
void FrAligner_Simulator(void* _pArg);
void Disc_Motion_Simulator( void* _pArg );
void LoadPort_Simulator( int _nLP );
void AMHS_Simulator( int _nLP );
void Pressure_Simulator();
void AutoFill_Simulator();
void Utilities_Simulator();
void Station_Simulator( int _nStationNo );
void WetStation_Simulator(int _nWSNo);
void WS_Disc_Continuous_Simul(int _nWSNo);

#endif






