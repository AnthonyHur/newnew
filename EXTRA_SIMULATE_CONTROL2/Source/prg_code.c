/************************************************************************

	Header

************************************************************************/
#include "iodefine.h"

/************************************************************************

	IO

************************************************************************/
IO_Name_String_Map IO_STR_Map_Table[] = {

	//	Option
	//////////////////////////////////////////////////////////////////////////
	{ "OpticalLeakUsage"		, _K_D_IO	,	D_OpticalLeakUsage			,	0	} ,
	{ "IonizerUsage"			, _K_D_IO	,	D_IonizerUsage				,	0	} ,
	{ "Bubbler2_Usage"			, _K_D_IO	,	D_Bubbler2_Usage			,	0	} ,
	{ "FADetectorUsage"			, _K_D_IO	,	D_FADetectorUsage			,	0	} ,
	{ "PM_Module_Type"			, _K_D_IO	,	D_PM_Module_Type			,	0	} ,

	{ "CTC.PM1_Wafer_Status"	, _K_D_IO	,	D_CTC_PM1_Wafer_Status		,	0	} ,
	{ "CTC.PM1_Wafer_Status2"	, _K_D_IO	,	D_CTC_PM1_Wafer_Status2		,	0	} ,
	{ "CTC.PM1_Wafer_Status3"	, _K_D_IO	,	D_CTC_PM1_Wafer_Status3		,	0	} ,
	{ "CTC.PM1_Wafer_Status4"	, _K_D_IO	,	D_CTC_PM1_Wafer_Status4		,	0	} ,
	{ "CTC.PM1_Wafer_Status5"	, _K_D_IO	,	D_CTC_PM1_Wafer_Status5		,	0	} ,
	{ "CTC.PM1_Wafer_Status6"	, _K_D_IO	,	D_CTC_PM1_Wafer_Status6		,	0	} ,
	{ "CTC.PM5_Wafer_Status"	, _K_D_IO	,	D_CTC_PM5_Wafer_Status		,	0	} ,
	
	//	Interlock °ü·Ã
	//////////////////////////////////////////////////////////////////////////
	{ "EFEM_SIDEDOOR"			, _K_D_IO	,	D_EFEM_SIDEDOOR				,	0	} ,

	//	LoadPort
	//////////////////////////////////////////////////////////////////////////
	{ "PORT1_Run_Status"		, _K_D_IO	,	D_PORT1_Run_Status			,	0	} ,
	{ "PORT2_Run_Status"		, _K_D_IO	,	D_PORT2_Run_Status			,	0	} ,
	{ "PORT3_Run_Status"		, _K_D_IO	,	D_PORT3_Run_Status			,	0	} ,
	{ "PORT1_CarrStatus"		, _K_D_IO	,	D_PORT1_CarrStatus			,	0	} ,
	{ "PORT2_CarrStatus"		, _K_D_IO	,	D_PORT2_CarrStatus			,	0	} ,
	{ "PORT3_CarrStatus"		, _K_D_IO	,	D_PORT3_CarrStatus			,	0	} ,
	{ "PORT1_DoorStatus"		, _K_D_IO	,	D_PORT1_DoorStatus			,	0	} ,		// Close Open Unknown
	{ "PORT2_DoorStatus"		, _K_D_IO	,	D_PORT2_DoorStatus			,	0	} ,
	{ "PORT3_DoorStatus"		, _K_D_IO	,	D_PORT3_DoorStatus			,	0	} ,	
	{ "PORT1_ClampStatus"		, _K_D_IO	,	D_PORT1_ClampStatus			,	0	} ,
	{ "PORT2_ClampStatus"		, _K_D_IO	,	D_PORT2_ClampStatus			,	0	} ,
	{ "PORT3_ClampStatus"		, _K_D_IO	,	D_PORT3_ClampStatus			,	0	} ,
	{ "PORT1_DockStatus"		, _K_D_IO	,	D_PORT1_DockStatus			,	0	} ,
	{ "PORT2_DockStatus"		, _K_D_IO	,	D_PORT2_DockStatus			,	0	} ,
	{ "PORT3_DockStatus"		, _K_D_IO	,	D_PORT3_DockStatus			,	0	} ,
	{ "PORT1_INIT_STATUS"		, _K_D_IO	,	D_PORT1_INIT_STATUS			,	0	} ,
	{ "PORT2_INIT_STATUS"		, _K_D_IO	,	D_PORT2_INIT_STATUS			,	0	} ,
	{ "PORT3_INIT_STATUS"		, _K_D_IO	,	D_PORT3_INIT_STATUS			,	0	} ,
	{ "PORT1_MAP_DATA"			, _K_S_IO	,	S_PORT1_MAP_DATA			,	0	} ,
	{ "PORT2_MAP_DATA"			, _K_S_IO	,	S_PORT2_MAP_DATA			,	0	} ,
	{ "PORT3_MAP_DATA"			, _K_S_IO	,	S_PORT3_MAP_DATA			,	0	} ,

	{ "PORT1_Control"			, _K_D_IO	,	D_PORT1_Control				,	0	} ,
	{ "PORT2_Control"			, _K_D_IO	,	D_PORT2_Control				,	0	} ,
	{ "PORT3_Control"			, _K_D_IO	,	D_PORT3_Control				,	0	} ,

	//	AMHS
	//////////////////////////////////////////////////////////////////////////
	// DO : PASSIVE(EQ) => ACTIVE(OHT)
	{ "AMHS1_LREQ"				, _K_D_IO	,	D_AMHS1_PV_LREQ				,	0	} ,
	{ "AMHS2_LREQ"				, _K_D_IO	,	D_AMHS2_PV_LREQ				,	0	} ,
	{ "AMHS3_LREQ"				, _K_D_IO	,	D_AMHS3_PV_LREQ				,	0	} ,
	{ "AMHS1_UREQ"				, _K_D_IO	,	D_AMHS1_PV_UREQ				,	0	} ,
	{ "AMHS2_UREQ"				, _K_D_IO	,	D_AMHS2_PV_UREQ				,	0	} ,
	{ "AMHS3_UREQ"				, _K_D_IO	,	D_AMHS3_PV_UREQ				,	0	} ,
	{ "AMHS1_READY"				, _K_D_IO	,	D_AMHS1_PV_READY			,	0	} ,
	{ "AMHS2_READY"				, _K_D_IO	,	D_AMHS2_PV_READY			,	0	} ,
	{ "AMHS3_READY"				, _K_D_IO	,	D_AMHS3_PV_READY			,	0	} ,
	{ "AMHS1_HO_AVBL"			, _K_D_IO	,	D_AMHS1_PV_HO_AVBL			,	0	} ,
	{ "AMHS2_HO_AVBL"			, _K_D_IO	,	D_AMHS2_PV_HO_AVBL			,	0	} ,
	{ "AMHS3_HO_AVBL"			, _K_D_IO	,	D_AMHS3_PV_HO_AVBL			,	0	} ,
	{ "AMHS1_ES"				, _K_D_IO	,	D_AMHS1_PV_ES				,	0	} ,
	{ "AMHS2_ES"				, _K_D_IO	,	D_AMHS2_PV_ES				,	0	} ,
	{ "AMHS3_ES"				, _K_D_IO	,	D_AMHS3_PV_ES				,	0	} ,
	// DI : ACTIVE(OHT) => PASSIVE(EQ)
	{ "AMHS1_VALID"				, _K_D_IO	,	D_AMHS1_AV_VALID			,	0	} ,
	{ "AMHS2_VALID"				, _K_D_IO	,	D_AMHS2_AV_VALID			,	0	} ,
	{ "AMHS3_VALID"				, _K_D_IO	,	D_AMHS3_AV_VALID			,	0	} ,
	{ "AMHS1_CS_0"				, _K_D_IO	,	D_AMHS1_AV_CS_0				,	0	} ,
	{ "AMHS2_CS_0"				, _K_D_IO	,	D_AMHS2_AV_CS_0				,	0	} ,
	{ "AMHS3_CS_0"				, _K_D_IO	,	D_AMHS3_AV_CS_0				,	0	} ,
	{ "AMHS1_CS_1"				, _K_D_IO	,	D_AMHS1_AV_CS_1				,	0	} ,
	{ "AMHS2_CS_1"				, _K_D_IO	,	D_AMHS2_AV_CS_1				,	0	} ,
	{ "AMHS3_CS_1"				, _K_D_IO	,	D_AMHS3_AV_CS_1				,	0	} ,
	{ "AMHS1_TR_REQ"			, _K_D_IO	,	D_AMHS1_AV_TR_REQ			,	0	} ,
	{ "AMHS2_TR_REQ"			, _K_D_IO	,	D_AMHS2_AV_TR_REQ			,	0	} ,
	{ "AMHS3_TR_REQ"			, _K_D_IO	,	D_AMHS3_AV_TR_REQ			,	0	} ,
	{ "AMHS1_BUSY"				, _K_D_IO	,	D_AMHS1_AV_BUSY				,	0	} ,
	{ "AMHS2_BUSY"				, _K_D_IO	,	D_AMHS2_AV_BUSY				,	0	} ,
	{ "AMHS3_BUSY"				, _K_D_IO	,	D_AMHS3_AV_BUSY				,	0	} ,
	{ "AMHS1_COMPT"				, _K_D_IO	,	D_AMHS1_AV_COMPT			,	0	} ,
	{ "AMHS2_COMPT"				, _K_D_IO	,	D_AMHS2_AV_COMPT			,	0	} ,
	{ "AMHS3_COMPT"				, _K_D_IO	,	D_AMHS3_AV_COMPT			,	0	} ,
	{ "AMHS1_CONT"				, _K_D_IO	,	D_AMHS1_AV_CONT				,	0	} ,
	{ "AMHS2_CONT"				, _K_D_IO	,	D_AMHS2_AV_CONT				,	0	} ,
	{ "AMHS3_CONT"				, _K_D_IO	,	D_AMHS3_AV_CONT				,	0	} ,
	
	{ "Light_Curtain_Sts"		, _K_D_IO	,	D_Light_Curtain_Sts			,	0	} ,
	
	{ "AMHS_TP1"				, _K_A_IO	,	A_AMHS_TP1_TIMEOUT			,	0	} ,
	{ "AMHS_TP2"				, _K_A_IO	,	A_AMHS_TP2_TIMEOUT			,	0	} ,
	{ "AMHS_TP3"				, _K_A_IO	,	A_AMHS_TP3_TIMEOUT			,	0	} ,
	{ "AMHS_TP4"				, _K_A_IO	,	A_AMHS_TP4_TIMEOUT			,	0	} ,
	{ "AMHS_TP5"				, _K_A_IO	,	A_AMHS_TP5_TIMEOUT			,	0	} ,
	{ "AMHS_TP6"				, _K_A_IO	,	A_AMHS_TP6_TIMEOUT			,	0	} ,

	{ "AMHS1_SIMULATION_LOAD"	, _K_D_IO	,	D_AMHS1_SIMULATION_LOAD		,	0	} ,
	{ "AMHS2_SIMULATION_LOAD"	, _K_D_IO	,	D_AMHS2_SIMULATION_LOAD		,	0	} ,
	{ "AMHS3_SIMULATION_LOAD"	, _K_D_IO	,	D_AMHS3_SIMULATION_LOAD		,	0	} ,

	{ "CTC.FA_STATUS_AGV_CM1"	, _K_D_IO	,	D_CTC_FA_STATUS_AGV_CM1		,	0	} ,
	{ "CTC.FA_STATUS_AGV_CM2"	, _K_D_IO	,	D_CTC_FA_STATUS_AGV_CM2		,	0	} ,
	{ "CTC.FA_STATUS_AGV_CM3"	, _K_D_IO	,	D_CTC_FA_STATUS_AGV_CM3		,	0	} ,

	{ "PORT1_AMHSModeSts"		, _K_D_IO	,	D_PORT1_AMHSModeSts			,	0	} ,
	{ "PORT2_AMHSModeSts"		, _K_D_IO	,	D_PORT2_AMHSModeSts			,	0	} ,
	{ "PORT3_AMHSModeSts"		, _K_D_IO	,	D_PORT3_AMHSModeSts			,	0	} ,

	//	Robot
	//////////////////////////////////////////////////////////////////////////
	{ "FMRB_INIT"				, _K_D_IO	,	D_FMRB_INIT					,	0	} ,	
	{ "FMRB_SERVO"				, _K_D_IO	,	D_FMRB_SERVO				,	0	} ,	
	{ "ROBOT_Init_Status"		, _K_D_IO	,	D_ROBOT_Init_Status			,	0	} ,	
	{ "ROBOT_Task_Status"		, _K_D_IO	,	D_ROBOT_Task_Status			,	0	} ,
	{ "ROBOT_Run_Status"		, _K_D_IO	,	D_ROBOT_Run_Status			,	0	} ,
	{ "ROBOT_Servo_Status"		, _K_D_IO	,	D_ROBOT_Servo_Status		,	0	} ,
	{ "Upper_Wafer_Status"		, _K_D_IO	,	D_Upper_Wafer_Status		,	0	} ,
	{ "Lower_Wafer_Status"		, _K_D_IO	,	D_Lower_Wafer_Status		,	0	} ,
	{ "ROBOT_Arm_Pos_Sts"		, _K_D_IO	,	D_ROBOT_Arm_Pos_Sts			,	0	} ,
	{ "ROBOT_Arm_Stg_Sts"		, _K_D_IO	,	D_ROBOT_Arm_Stg_Sts			,	0	} ,
	{ "TRANS_PICK"				, _K_D_IO	,	D_TRANS_PICK				,	0	} ,
	{ "TRANS_PLACE"				, _K_D_IO	,	D_TRANS_PLACE				,	0	} ,
	{ "TRANS_PREPICK"			, _K_D_IO	,	D_TRANS_PREPICK				,	0	} ,
	{ "TRANS_PREPLACE"			, _K_D_IO	,	D_TRANS_PREPLACE			,	0	} ,
	{ "U_SRC_POSITION"			, _K_D_IO	,	D_U_SRC_POSITION			,	0	} ,
	{ "L_SRC_POSITION"			, _K_D_IO	,	D_L_SRC_POSITION			,	0	} ,
	{ "U_TGT_POSITION"			, _K_D_IO	,	D_U_TGT_POSITION			,	0	} ,
	{ "L_TGT_POSITION"			, _K_D_IO	,	D_L_TGT_POSITION			,	0	} ,
	
	//	Aligner
	//////////////////////////////////////////////////////////////////////////
	{ "PreAlignerRunSts"		, _K_D_IO	,	D_PreAlignerRunSts			,	0	} ,
	{ "PreAlignerVacSts"		, _K_D_IO	,	D_PreAlignerVacSts			,	0	} ,
	{ "PreAlignerOKSts"			, _K_D_IO	,	D_PreAlignerOKSts			,	0	} ,
	{ "PreAlignStart"			, _K_D_IO	,	D_PreAlignStart				,	0	} ,
	{ "PreAlign_VacOnOff"		, _K_D_IO	,	D_PreAlign_VacOnOff			,	0	} ,
	{ "PreAlign_X_OffSet"		, _K_A_IO	,	A_PreAlign_X_OffSet			,	0	} ,
	{ "PreAlign_Y_OffSet"		, _K_A_IO	,	A_PreAlign_Y_OffSet			,	0	} ,
	{ "PreAlign_AngleSts"		, _K_A_IO	,	A_PreAlign_AngleSts			,	0	} ,
	{ "PreAlign_AngleSet"		, _K_A_IO	,	A_PreAlign_AngleSet			,	0	} ,

	//{ "PreAlignerInitSts"		, _K_D_IO	,	D_PreAlignerInitSts			,	0	} ,
	//{ "PreAlignerServoSts"		, _K_D_IO	,	D_PreAlignerServoSts		,	0	} ,
	//{ "PreAlignerInit"			, _K_D_IO	,	D_PreAlignerInit			,	0	} ,


	//	LoadLock
	//////////////////////////////////////////////////////////////////////////
 	
	{ "PM_LL_PurgeState"		, _K_D_IO	,	D_PM_LL_PurgeState			,	0	} ,
 	{ "LL_Door_Ctrl"			, _K_D_IO	,	D_LL_Door_Ctrl				,	0	} ,
 	{ "LL_Door_Sts"				, _K_D_IO	,	D_LL_Door_Sts				,	0	} ,
 	
 	{ "LL_Ring_Seal_Vac_Ctrl"	, _K_D_IO	,	D_LL_Ring_Seal_Vac_Ctrl		,	0	} ,
 	{ "LL_Ring_Seal_Vac_Sts"	, _K_D_IO	,	D_LL_Ring_Seal_Vac_Sts		,	0	} ,
 	{ "LL_Door_Seal_Vac_Ctrl"	, _K_D_IO	,	D_LL_Door_Seal_Vac_Ctrl		,	0	} ,
 	{ "LL_Door_Seal_Vac_Sts"	, _K_D_IO	,	D_LL_Door_Seal_Vac_Sts		,	0	} ,
 	{ "LL_Evacuate_Vv"			, _K_D_IO	,	D_LL_Evacuate_Vv			,	0	} ,
	{ "LL_Evacuate_Vv_Sts"		, _K_D_IO	,	D_LL_Evacuate_Vv_Sts		,	0	} ,
 	{ "LL_Purge_Vv"				, _K_D_IO	,	D_LL_Purge_Vv				,	0	} ,
 	{ "LL_Purge_Vv_Sts"			, _K_D_IO	,	D_LL_Purge_Vv_Sts			,	0	} ,

 	{ "Ring_Seal"				, _K_A_IO	,	A_Ring_Seal					,	0	} ,
 	{ "Door_Seal"				, _K_A_IO	,	A_Door_Seal					,	0	} ,

	//	Utilities
	//////////////////////////////////////////////////////////////////////////
	{ "Bubbler_ManualVvSts"		, _K_D_IO	,	D_Bubbler_ManualVvSts		,	0	} ,
	{ "Bubbler_LowLmt_Lvl"		, _K_D_IO	,	D_Bubbler_LowLmt_Lvl		,	0	} ,
	{ "Bubbler_Low_Lvl"			, _K_D_IO	,	D_Bubbler_Low_Lvl			,	0	} ,
	{ "Bubbler_High_Lvl"		, _K_D_IO	,	D_Bubbler_High_Lvl			,	0	} ,
	{ "Bubbler2_Low_Lvl"		, _K_D_IO	,	D_Bubbler2_Low_Lvl			,	0	} ,
	{ "Bubbler2_High_Lvl"		, _K_D_IO	,	D_Bubbler2_High_Lvl			,	0	} ,
	{ "Bubbler_HighLmt_Lvl"		, _K_D_IO	,	D_Bubbler_HighLmt_Lvl		,	0	} ,
	{ "Bubbler_Leak_Sts"		, _K_D_IO	,	D_Bubbler_Leak_Sts			,	0	} ,
	{ "Bubbler_LeakOptcSts"		, _K_D_IO	,	D_Bubbler_LeakOptcSts		,	0	} ,
	{ "Bubbler2_LowLmt_Lvl"		, _K_D_IO	,	D_Bubbler2_LowLmt_Lvl		,	0	} ,
	{ "Bubbler2_HighLmt_Lvl"	, _K_D_IO	,	D_Bubbler2_HighLmt_Lvl		,	0	} ,
	{ "Bubbler2_Leak_Sts"		, _K_D_IO	,	D_Bubbler2_Leak_Sts			,	0	} ,
	{ "Bubbler2_LeakOptcSts"	, _K_D_IO	,	D_Bubbler2_LeakOptcSts		,	0	} ,
	{ "Chmbr_Lock_Vv"			, _K_D_IO	,	D_Chmbr_Lock_Vv				,	0	} ,	// Lock / Unlock
	{ "Chmbr_Lock_Vv_Sts"		, _K_D_IO	,	D_Chmbr_Lock_Vv_Sts			,	0	} ,	// Unlock / Lock
	{ "PM_Cover_Sts"			, _K_D_IO	,	D_PM_Cover_Sts				,	0	} ,
	{ "Fac_PCW_Flow_Sts"		, _K_D_IO	,	D_Fac_PCW_Flow_Sts			,	0	} ,
	{ "Fac_PCW_Flow_Rate"		, _K_A_IO	,	A_Fac_PCW_Flow_Rate			,	0	} ,
	{ "Fac_VAC_Press_Sts"		, _K_D_IO	,	D_Fac_VAC_Press_Sts			,	0	} ,
	{ "Fac_Vacuum_Press"		, _K_A_IO	,	A_Fac_Vacuum_Press			,	0	} ,
	{ "Fac_CDA_Press_Sts"		, _K_D_IO	,	D_Fac_CDA_Press_Sts			,	0	} ,
	{ "Fac_CDA_Press"			, _K_A_IO	,	A_Fac_CDA_Press				,	0	} ,
	{ "Gas_Box_Door_Sts"		, _K_D_IO	,	D_Gas_Box_Door_Sts			,	0	} ,
	{ "Process_Exhst_Sts"		, _K_D_IO	,	D_Process_Exhst_Sts			,	0	} ,
	{ "Process_Exhst_Press"		, _K_A_IO	,	A_Process_Exhst_Press		,	0	} ,
	{ "Gas_Box_Exhst_Sts"		, _K_D_IO	,	D_Gas_Box_Exhst_Sts			,	0	} ,
	{ "Gas_Box_Exhst_Press"		, _K_A_IO	,	A_Gas_Box_Exhst_Press		,	0	} ,
	{ "Cabinet_Exhst_Sts"		, _K_D_IO	,	D_Cabinet_Exhst_Sts			,	0	} ,
	{ "Cabinet_Exhst_Press"		, _K_A_IO	,	A_Cabinet_Exhst_Press		,	0	} ,
	{ "Water_Leak"				, _K_D_IO	,	D_Water_Leak				,	0	} ,
	{ "Bulkfill_SupplyRun"		, _K_D_IO	,	D_Bulkfill_SupplyRun		,	0	} ,
	{ "Bulkfill_SupplyReady"	, _K_D_IO	,	D_Bulkfill_SupplyReady		,	0	} ,
	{ "Chuck1_LT_LimitTemp"		, _K_D_IO	,	D_Chuck1_LT_LimitTemp		,	0	} ,
	{ "Chuck2_LT_LimitTemp"		, _K_D_IO	,	D_Chuck2_LT_LimitTemp		,	0	} ,
	{ "Chuck3_LT_LimitTemp"		, _K_D_IO	,	D_Chuck3_LT_LimitTemp		,	0	} ,
	{ "Chuck4_LT_LimitTemp"		, _K_D_IO	,	D_Chuck4_LT_LimitTemp		,	0	} ,
	{ "Insul1_LT_LimitTemp"		, _K_D_IO	,	D_Insul1_LT_LimitTemp		,	0	} ,
	{ "Insul2_LT_LimitTemp"		, _K_D_IO	,	D_Insul2_LT_LimitTemp		,	0	} ,
	{ "Insul3_LT_LimitTemp"		, _K_D_IO	,	D_Insul3_LT_LimitTemp		,	0	} ,
	{ "Insul4_LT_LimitTemp"		, _K_D_IO	,	D_Insul4_LT_LimitTemp		,	0	} ,
	{ "Elbow1_LT_LimitTemp"		, _K_D_IO	,	D_Elbow1_LT_LimitTemp		,	0	} ,
	{ "Elbow2_LT_LimitTemp"		, _K_D_IO	,	D_Elbow2_LT_LimitTemp		,	0	} ,
	{ "Elbow3_LT_LimitTemp"		, _K_D_IO	,	D_Elbow3_LT_LimitTemp		,	0	} ,
	{ "Elbow4_LT_LimitTemp"		, _K_D_IO	,	D_Elbow4_LT_LimitTemp		,	0	} ,
	{ "Bublr1_LT_LimitTemp"		, _K_D_IO	,	D_Bublr1_LT_LimitTemp		,	0	} ,
	{ "Bublr2_LT_LimitTemp"		, _K_D_IO	,	D_Bublr2_LT_LimitTemp		,	0	} ,
	{ "Chuck1_LT_TC_Broken"		, _K_D_IO	,	D_Chuck1_LT_TC_Broken		,	0	} ,
	{ "Chuck2_LT_TC_Broken"		, _K_D_IO	,	D_Chuck2_LT_TC_Broken		,	0	} ,
	{ "Chuck3_LT_TC_Broken"		, _K_D_IO	,	D_Chuck3_LT_TC_Broken		,	0	} ,
	{ "Chuck4_LT_TC_Broken"		, _K_D_IO	,	D_Chuck4_LT_TC_Broken		,	0	} ,
	{ "Insul1_LT_TC_Broken"		, _K_D_IO	,	D_Insul1_LT_TC_Broken		,	0	} ,
	{ "Insul2_LT_TC_Broken"		, _K_D_IO	,	D_Insul2_LT_TC_Broken		,	0	} ,
	{ "Insul3_LT_TC_Broken"		, _K_D_IO	,	D_Insul3_LT_TC_Broken		,	0	} ,
	{ "Insul4_LT_TC_Broken"		, _K_D_IO	,	D_Insul4_LT_TC_Broken		,	0	} ,
	{ "Elbow1_LT_TC_Broken"		, _K_D_IO	,	D_Elbow1_LT_TC_Broken		,	0	} ,
	{ "Elbow2_LT_TC_Broken"		, _K_D_IO	,	D_Elbow2_LT_TC_Broken		,	0	} ,
	{ "Elbow3_LT_TC_Broken"		, _K_D_IO	,	D_Elbow3_LT_TC_Broken		,	0	} ,
	{ "Elbow4_LT_TC_Broken"		, _K_D_IO	,	D_Elbow4_LT_TC_Broken		,	0	} ,
	{ "Bublr1_LT_TC_Broken"		, _K_D_IO	,	D_Bublr1_LT_TC_Broken		,	0	} ,
	{ "Bublr2_LT_TC_Broken"		, _K_D_IO	,	D_Bublr2_LT_TC_Broken		,	0	} ,
	{ "WS_Leak_Sensor"			, _K_D_IO	,	D_WS_Leak_Sensor			,	0	} ,
	{ "Hi_DI_Res_Meter"			, _K_D_IO	,	D_Hi_DI_Res_Meter			,	0	} ,
	{ "WS_Hi_DI_Pressure"		, _K_A_IO	,	A_WS_Hi_DI_Pressure			,	0	} ,
	{ "WS1_Drain_Lvl_Sts"		, _K_D_IO	,	D_WS1_Drain_Lvl_Sts			,	0	} ,
	{ "WS2_Drain_Lvl_Sts"		, _K_D_IO	,	D_WS2_Drain_Lvl_Sts			,	0	} ,
	{ "Scrubber_Warning"		, _K_D_IO	,	D_Scrubber_Warning			,	0	} ,
	{ "Scrubber_Trouble"		, _K_D_IO	,	D_Scrubber_Trouble			,	0	} ,
	{ "Scrubber_Treatmentable"	, _K_D_IO	,	D_Scrubber_Treatmentable	,	0	} ,
	{ "Ionizer_Status"			, _K_D_IO	,	D_Ionizer_Status			,	0	} ,
	
	{ "O2_Sample_Vv"			, _K_D_IO	,	D_O2_Sample_Vv				,	0	} ,
	{ "O2_Sample_Vv_Sts"		, _K_D_IO	,	D_O2_Sample_Vv_Sts			,	0	} ,
	{ "O2LevelRead"				, _K_A_IO	,	A_O2LevelRead				,	0	} ,

	{ "N2_Press_Transducer"		, _K_A_IO	,	A_N2_Press_Transducer		,	0	} ,
	{ "N2_Purge_Press_Transducer" , _K_A_IO	,	A_N2_Purge_Press_Transducer	,	0	} ,
	{ "ContBubbler_Level"		, _K_A_IO	,	A_ContBubbler_Level			,	0	} ,
	{ "O2_Press_Transducer"		, _K_A_IO	,	A_O2_Press_Transducer		,	0	} ,

 	{ "Stg1_Wfr_Sns_Vac"		, _K_D_IO	,	D_Stg1_Wfr_Sns_Vac			,	0	} ,
	{ "Stg2_Wfr_Sns_Vac"		, _K_D_IO	,	D_Stg2_Wfr_Sns_Vac			,	0	} ,
 	{ "Stg3_Wfr_Sns_Vac"		, _K_D_IO	,	D_Stg3_Wfr_Sns_Vac			,	0	} ,
	{ "Stg4_Wfr_Sns_Vac"		, _K_D_IO	,	D_Stg4_Wfr_Sns_Vac			,	0	} ,
	{ "Stg5_Wfr_Sns_Vac"		, _K_D_IO	,	D_Stg5_Wfr_Sns_Vac			,	0	} ,
	{ "Stg6_Wfr_Sns_Vac"		, _K_D_IO	,	D_Stg6_Wfr_Sns_Vac			,	0	} ,
	
	{ "Stg1_Wfr_Sns_Sts"		, _K_D_IO	,	D_Stg1_Wfr_Sns_Sts			,	0	} ,
	{ "Stg2_Wfr_Sns_Sts"		, _K_D_IO	,	D_Stg2_Wfr_Sns_Sts			,	0	} ,
	{ "Stg3_Wfr_Sns_Sts"		, _K_D_IO	,	D_Stg3_Wfr_Sns_Sts			,	0	} ,
	{ "Stg4_Wfr_Sns_Sts"		, _K_D_IO	,	D_Stg4_Wfr_Sns_Sts			,	0	} ,
	{ "Stg5_Wfr_Sns_Sts"		, _K_D_IO	,	D_Stg5_Wfr_Sns_Sts			,	0	} ,
	{ "Stg6_Wfr_Sns_Sts"		, _K_D_IO	,	D_Stg6_Wfr_Sns_Sts			,	0	} ,

 	{ "Chuck1_UP_Ctrl"			, _K_D_IO	,	D_Chuck1_UP_Ctrl			,	0	} ,
	{ "Chuck2_UP_Ctrl"			, _K_D_IO	,	D_Chuck2_UP_Ctrl			,	0	} ,
	{ "Chuck3_UP_Ctrl"			, _K_D_IO	,	D_Chuck3_UP_Ctrl			,	0	} ,
	{ "Chuck4_UP_Ctrl"			, _K_D_IO	,	D_Chuck4_UP_Ctrl			,	0	} ,
	{ "Chuck5_UP_Ctrl"			, _K_D_IO	,	D_Chuck5_UP_Ctrl			,	0	} ,
	{ "Chuck6_UP_Ctrl"			, _K_D_IO	,	D_Chuck6_UP_Ctrl			,	0	} ,
	{ "Chuck6_DN_Ctrl"			, _K_D_IO	,	D_Chuck6_DN_Ctrl			,	0	} ,

	{ "Chuck1_Pos_Sts"			, _K_D_IO	,	D_Chuck1_Pos_Sts			,	0	} ,
	{ "Chuck2_Pos_Sts"			, _K_D_IO	,	D_Chuck2_Pos_Sts			,	0	} ,
	{ "Chuck3_Pos_Sts"			, _K_D_IO	,	D_Chuck3_Pos_Sts			,	0	} ,
	{ "Chuck4_Pos_Sts"			, _K_D_IO	,	D_Chuck4_Pos_Sts			,	0	} ,
	{ "Chuck5_Pos_Sts"			, _K_D_IO	,	D_Chuck5_Pos_Sts			,	0	} ,
	{ "Chuck6_Pos_Sts"			, _K_D_IO	,	D_Chuck6_Pos_Sts			,	0	} ,
 	
 	{ "VacHeat_Vac_Vv"			, _K_D_IO	,	D_VacHeat_Vac_Vv			,	0	} ,
	{ "VacHeat_Vac_Vv_Sts"		, _K_D_IO	,	D_VacHeat_Vac_Vv_Sts		,	0	} ,
 	{ "VacHeat_Exhst_Vv"		, _K_D_IO	,	D_VacHeat_Exhst_Vv			,	0	} ,
	{ "VacHeat_Exhst_Vv_Sts"	, _K_D_IO	,	D_VacHeat_Exhst_Vv_Sts		,	0	} ,
 	{ "VacHeat_Vent_Vv"			, _K_D_IO	,	D_VacHeat_Vent_Vv			,	0	} ,
	{ "VacHeat_Vent_Vv_Sts"		, _K_D_IO	,	D_VacHeat_Vent_Vv_Sts		,	0	} ,
	{ "VacHeat_PrcGasISOSts"	, _K_D_IO	,	D_VacHeat_PrcGasISOSts		,	0	} ,
	{ "VacHeat_ExhstISOSts"		, _K_D_IO	,	D_VacHeat_ExhstISOSts		,	0	} ,
	{ "VacHeat_VacIsoB_Sts"		, _K_D_IO	,	D_VacHeat_VacIsoB_Sts		,	0	} ,
	{ "VacHeat_VacIsoB_Vv"		, _K_D_IO	,	D_VacHeat_VacIsoB_Vv		,	0	} ,
	{ "VacHeat_GasIsoB_Sts"		, _K_D_IO	,	D_VacHeat_GasIsoB_Sts		,	0	} ,
	{ "VacHeat_GasIsoB_Vv"		, _K_D_IO	,	D_VacHeat_GasIsoB_Vv		,	0	} ,
 	
 	{ "Cool_LowPurgeVv"			, _K_D_IO	,	D_Cool_LowPurgeVv			,	0	} ,
 	{ "Cool_LowPurgeVvSts"		, _K_D_IO	,	D_Cool_LowPurgeVvSts		,	0	} ,

	{ "FA_Gas_Detect_Fail"		, _K_D_IO	,	D_FA_Gas_Detect_Fail		,	0	} ,
	{ "FA_Gas_Leak_Warning"		, _K_D_IO	,	D_FA_Gas_Leak_Warning		,	0	} ,
	{ "FA_Gas_Leak_Alarm"		, _K_D_IO	,	D_FA_Gas_Leak_Alarm			,	0	} ,
	
	{ "Bubbler_Door"			, _K_D_IO	,	D_Bubbler_Door				,	0	} ,
	{ "Gas_Leak_Alarm"			, _K_D_IO	,	D_Gas_Leak_Alarm			,	0	} ,

	{ "FA_Valve_Spill"			, _K_D_IO	,	D_FA_Valve_Spill			,	0	} ,

	{ "Fac_PCW_Inlet_Temp"		, _K_A_IO	,	A_Fac_PCW_Inlet_Temp		,	0	},
	{ "Fac_PCW_Outlet_Temp"		, _K_A_IO	,	A_Fac_PCW_Outlet_Temp		,	0	},

	/*
	{ "WS_Fac_DI_Sts"			, _K_D_IO	,	D_WS_Fac_DI_Sts				,	0	},
	{ "WS_Fac_ACID_Sts"			, _K_D_IO	,	D_WS_Fac_ACID_Sts			,	0	},
	{ "WS_Fac_HIDI_Sts"			, _K_D_IO	,	D_WS_Fac_HIDI_Sts			,	0	},
	{ "WS_ACID_Avail"			, _K_D_IO	,	D_WS_ACID_Avail				,	0	},
	

	{ "WS1_Exhaust_Flow"		, _K_D_IO	,	WS1_Exhaust_Flow			,	0	},
	{ "WS2_Exhaust_Flow"		, _K_D_IO	,	WS2_Exhaust_Flow			,	0	},
	*/
	{ "Bubbler_Fill_Vv"			, _K_D_IO	,	D_Bubbler_Fill_Vv			,	0	},
	

	//	Bubbler
	//////////////////////////////////////////////////////////////////////////
	{ "Bubbler_Bypass_Vv"		, _K_D_IO	,	D_Bubbler_Bypass_Vv			,	0	} ,
 	{ "Bubbler_Vent_Vv"			, _K_D_IO	,	D_Bubbler_Vent_Vv			,	0	} ,
 	{ "Bubbler_Feed_Vv"			, _K_D_IO	,	D_Bubbler_Feed_Vv			,	0	} ,
	{ "Bubbler_FeedVv_Sts"		, _K_D_IO	,	D_Bubbler_FeedVv_Sts		,	0	} ,
 	{ "Bubbler_Dlvry_Vv"		, _K_D_IO	,	D_Bubbler_Dlvry_Vv			,	0	} ,
	{ "Bubbler_DlvryVv_Sts"		, _K_D_IO	,	D_Bubbler_DlvryVv_Sts		,	0	} ,
 	{ "Bubbler2_Vent_Vv"		, _K_D_IO	,	D_Bubbler2_Vent_Vv			,	0	} ,
 	{ "Bubbler2_Feed_Vv"		, _K_D_IO	,	D_Bubbler2_Feed_Vv			,	0	} ,
	{ "Bubbler2_FeedVv_Sts"		, _K_D_IO	,	D_Bubbler2_FeedVv_Sts		,	0	} ,
 	{ "Bubbler2_Dlvry_Vv"		, _K_D_IO	,	D_Bubbler2_Dlvry_Vv			,	0	} ,
	{ "Bubbler2_DlvryVv_Sts"	, _K_D_IO	,	D_Bubbler2_DlvryVv_Sts		,	0	} ,

 	{ "FA_Line_Vent_Vv"			, _K_D_IO	,	D_FA_Line_Vent_Vv			,	0	} ,
	{ "FA_Line_Vent_Sts"		, _K_D_IO	,	D_FA_Line_Vent_Sts			,	0	} ,
 	{ "FA2_Line_Vent_Vv"		, _K_D_IO	,	D_FA2_Line_Vent_Vv			,	0	} ,
	{ "FA2_Line_Vent_Sts"		, _K_D_IO	,	D_FA2_Line_Vent_Sts			,	0	} ,

	{ "PM_Odometer_FA_Need"		, _K_D_IO	,	D_PM_Odometer_FA_Need		,	0	} ,
	{ "Bubbler_Exhst_Sts"		, _K_D_IO	,	D_Bubbler_Exhst_Sts			,	0	} ,

	//	Temperature
	//////////////////////////////////////////////////////////////////////////
 	{ "Chuck1_Heater_Pwr"		, _K_D_IO	,	D_Chuck1_Heater_Pwr			,	0	} ,
	{ "Chuck2_Heater_Pwr"		, _K_D_IO	,	D_Chuck2_Heater_Pwr			,	0	} ,
	{ "Chuck3_Heater_Pwr"		, _K_D_IO	,	D_Chuck3_Heater_Pwr			,	0	} ,
	{ "Chuck4_Heater_Pwr"		, _K_D_IO	,	D_Chuck4_Heater_Pwr			,	0	} ,

	{ "Chuck1_Heater_PwrSts"	, _K_D_IO	,	D_Chuck1_Heater_PwrSts		,	0	} ,
	{ "Chuck2_Heater_PwrSts"	, _K_D_IO	,	D_Chuck2_Heater_PwrSts		,	0	} ,
	{ "Chuck3_Heater_PwrSts"	, _K_D_IO	,	D_Chuck3_Heater_PwrSts		,	0	} ,
	{ "Chuck4_Heater_PwrSts"	, _K_D_IO	,	D_Chuck4_Heater_PwrSts		,	0	} ,

 	{ "Chuck1_Temp_Set"			, _K_A_IO	,	A_Chuck1_Temp_Set			,	0	} ,
	{ "Chuck2_Temp_Set"			, _K_A_IO	,	A_Chuck2_Temp_Set			,	0	} ,
	{ "Chuck3_Temp_Set"			, _K_A_IO	,	A_Chuck3_Temp_Set			,	0	} ,
	{ "Chuck4_Temp_Set"			, _K_A_IO	,	A_Chuck4_Temp_Set			,	0	} ,

	{ "Chuck1_Temp_Mnt"			, _K_A_IO	,	A_Chuck1_Temp_Mnt			,	0	} ,
	{ "Chuck2_Temp_Mnt"			, _K_A_IO	,	A_Chuck2_Temp_Mnt			,	0	} ,
	{ "Chuck3_Temp_Mnt"			, _K_A_IO	,	A_Chuck3_Temp_Mnt			,	0	} ,
	{ "Chuck4_Temp_Mnt"			, _K_A_IO	,	A_Chuck4_Temp_Mnt			,	0	} ,
	{ "Chuck5_Temp_Mnt"			, _K_A_IO	,	A_Chuck5_Temp_Mnt			,	0	} ,

 	{ "Insul1_Heater_Pwr"		, _K_D_IO	,	D_Insul1_Heater_Pwr			,	0	} ,
	{ "Insul2_Heater_Pwr"		, _K_D_IO	,	D_Insul2_Heater_Pwr			,	0	} ,
	{ "Insul3_Heater_Pwr"		, _K_D_IO	,	D_Insul3_Heater_Pwr			,	0	} ,
	{ "Insul4_Heater_Pwr"		, _K_D_IO	,	D_Insul4_Heater_Pwr			,	0	} ,

	{ "Insul1_Heater_PwrSts"	, _K_D_IO	,	D_Insul1_Heater_PwrSts		,	0	} ,
	{ "Insul2_Heater_PwrSts"	, _K_D_IO	,	D_Insul2_Heater_PwrSts		,	0	} ,
	{ "Insul3_Heater_PwrSts"	, _K_D_IO	,	D_Insul3_Heater_PwrSts		,	0	} ,
	{ "Insul4_Heater_PwrSts"	, _K_D_IO	,	D_Insul4_Heater_PwrSts		,	0	} ,

 	{ "Insul1_Temp_Set"			, _K_A_IO	,	A_Insul1_Temp_Set			,	0	} ,
	{ "Insul2_Temp_Set"			, _K_A_IO	,	A_Insul2_Temp_Set			,	0	} ,
	{ "Insul3_Temp_Set"			, _K_A_IO	,	A_Insul3_Temp_Set			,	0	} ,
	{ "Insul4_Temp_Set"			, _K_A_IO	,	A_Insul4_Temp_Set			,	0	} ,

	{ "Insul1_Temp_Mnt"			, _K_A_IO	,	A_Insul1_Temp_Mnt			,	0	} ,
	{ "Insul2_Temp_Mnt"			, _K_A_IO	,	A_Insul2_Temp_Mnt			,	0	} ,
	{ "Insul3_Temp_Mnt"			, _K_A_IO	,	A_Insul3_Temp_Mnt			,	0	} ,
	{ "Insul4_Temp_Mnt"			, _K_A_IO	,	A_Insul4_Temp_Mnt			,	0	} ,

 	{ "Elbow1_Heater_Pwr"		, _K_D_IO	,	D_Elbow1_Heater_Pwr			,	0	} ,
	{ "Elbow2_Heater_Pwr"		, _K_D_IO	,	D_Elbow2_Heater_Pwr			,	0	} ,
	{ "Elbow3_Heater_Pwr"		, _K_D_IO	,	D_Elbow3_Heater_Pwr			,	0	} ,
	{ "Elbow4_Heater_Pwr"		, _K_D_IO	,	D_Elbow4_Heater_Pwr			,	0	} ,

	{ "Elbow1_Heater_PwrSts"	, _K_D_IO	,	D_Elbow1_Heater_PwrSts		,	0	} ,
	{ "Elbow2_Heater_PwrSts"	, _K_D_IO	,	D_Elbow2_Heater_PwrSts		,	0	} ,
	{ "Elbow3_Heater_PwrSts"	, _K_D_IO	,	D_Elbow3_Heater_PwrSts		,	0	} ,
	{ "Elbow4_Heater_PwrSts"	, _K_D_IO	,	D_Elbow4_Heater_PwrSts		,	0	} ,

 	{ "Elbow1_Temp_Set"			, _K_A_IO	,	A_Elbow1_Temp_Set			,	0	} ,
	{ "Elbow2_Temp_Set"			, _K_A_IO	,	A_Elbow2_Temp_Set			,	0	} ,
	{ "Elbow3_Temp_Set"			, _K_A_IO	,	A_Elbow3_Temp_Set			,	0	} ,
	{ "Elbow4_Temp_Set"			, _K_A_IO	,	A_Elbow4_Temp_Set			,	0	} ,

	{ "Elbow1_Temp_Mnt"			, _K_A_IO	,	A_Elbow1_Temp_Mnt			,	0	} ,
	{ "Elbow2_Temp_Mnt"			, _K_A_IO	,	A_Elbow2_Temp_Mnt			,	0	} ,
	{ "Elbow3_Temp_Mnt"			, _K_A_IO	,	A_Elbow3_Temp_Mnt			,	0	} ,
	{ "Elbow4_Temp_Mnt"			, _K_A_IO	,	A_Elbow4_Temp_Mnt			,	0	} ,

 	{ "Bublr1_Heater_Pwr"		, _K_D_IO	,	D_Bublr1_Heater_Pwr			,	0	} ,
	{ "Bublr2_Heater_Pwr"		, _K_D_IO	,	D_Bublr2_Heater_Pwr			,	0	} ,

	{ "Bublr1_Heater_PwrSts"	, _K_D_IO	,	D_Bublr1_Heater_PwrSts		,	0	} ,
 	{ "Bublr2_Heater_PwrSts"	, _K_D_IO	,	D_Bublr2_Heater_PwrSts		,	0	} ,

	{ "Bublr1_Temp_Set"			, _K_A_IO	,	A_Bublr1_Temp_Set			,	0	} ,
 	{ "Bublr2_Temp_Set"			, _K_A_IO	,	A_Bublr2_Temp_Set			,	0	} ,

	{ "Bublr1_Temp_Mnt"			, _K_A_IO	,	A_Bublr1_Temp_Mnt			,	0	} ,
	{ "Bublr2_Temp_Mnt"			, _K_A_IO	,	A_Bublr2_Temp_Mnt			,	0	} ,

	{ "ProfileTC_Temp_Mnt"		, _K_A_IO	,	A_ProfileTC_Temp_Mnt		,	0	} ,

	//	Disc Motion
	//////////////////////////////////////////////////////////////////////////
	{ "Disc_ServoSts"			, _K_D_IO	,	D_Disc_ServoSts				,	0	} ,
	{ "Disc_Servo"				, _K_D_IO	,	D_Disc_Servo				,	0	} ,
	{ "Disc_HomeSts"			, _K_D_IO	,	D_Disc_HomeSts				,	0	} ,
	{ "Disc_HomSnsActv"			, _K_D_IO	,	D_Disc_HomSnsActv			,	0	} ,
	{ "Disc_RunSts"				, _K_D_IO	,	D_Disc_RunSts				,	0	} ,
	{ "Disc_Motor_Amp"			, _K_D_IO	,	D_Disc_Motor_Amp			,	0	} ,
	{ "Disc_AtStation"			, _K_D_IO	,	D_Disc_AtStation			,	0	} ,
	{ "Disc_Pos_Read"			, _K_A_IO	,	A_Disc_Pos_Read				,	0	} ,
	{ "Disc_Pos_Degree"			, _K_A_IO	,	A_Disc_Pos_Degree			,	0	} ,
	
	{ "Disc_MotionMode"			, _K_D_IO	,	D_Disc_MotionMode			,	0	} ,
	{ "Disc_PosModeSts"			, _K_D_IO	,	D_Disc_PosModeSts			,	0	} ,
	{ "Disc_Distance"			, _K_A_IO	,	A_Disc_Distance				,	0	} ,
	{ "Disc_Control"			, _K_D_IO	,	D_Disc_Control				,	0	} ,

	//	MFC
	//////////////////////////////////////////////////////////////////////////
	{ "MFC1_Monitor"			, _K_A_IO	,	A_MFC1_Monitor				,	0	} ,
	{ "MFC2_Monitor"			, _K_A_IO	,	A_MFC2_Monitor				,	0	} ,
	{ "MFC3_Monitor"			, _K_A_IO	,	A_MFC3_Monitor				,	0	} ,
	{ "MFC4_Monitor"			, _K_A_IO	,	A_MFC4_Monitor				,	0	} ,
	{ "MFC5_Monitor"			, _K_A_IO	,	A_MFC5_Monitor				,	0	} ,
	{ "MFC6_Monitor"			, _K_A_IO	,	A_MFC6_Monitor				,	0	} ,
	{ "MFC1_Set"				, _K_A_IO	,	A_MFC1_Set					,	0	} ,
	{ "MFC2_Set"				, _K_A_IO	,	A_MFC2_Set					,	0	} ,
	{ "MFC3_Set"				, _K_A_IO	,	A_MFC3_Set					,	0	} ,
	{ "MFC4_Set"				, _K_A_IO	,	A_MFC4_Set					,	0	} ,
	{ "MFC5_Set"				, _K_A_IO	,	A_MFC5_Set					,	0	} ,
	{ "MFC6_Set"				, _K_A_IO	,	A_MFC6_Set					,	0	} ,
	{ "Gas1_Vv"					, _K_D_IO	,	D_Gas1_Vv					,	0	} ,
	{ "Gas2_Vv"					, _K_D_IO	,	D_Gas2_Vv					,	0	} ,
	{ "Gas3_Vv"					, _K_D_IO	,	D_Gas3_Vv					,	0	} ,
	{ "Gas4_Vv"					, _K_D_IO	,	D_Gas4_Vv					,	0	} ,
	{ "Gas5_Vv"					, _K_D_IO	,	D_Gas5_Vv					,	0	} ,
	{ "Gas6_Vv"					, _K_D_IO	,	D_Gas6_Vv					,	0	} ,

	//	APC
	//////////////////////////////////////////////////////////////////////////
	
	{ "Prcs_APC_Ctrl_Mode"		, _K_D_IO	,	D_Prcs_APC_Ctrl_Mode		,	0	} ,
	{ "Prcs_APC_Close_Vv_Sts"	, _K_D_IO	,	D_Prcs_APC_Close_Vv_Sts		,	0	} ,
	{ "Prcs_APC_Open_Vv_Sts"	, _K_D_IO	,	D_Prcs_APC_Open_Vv_Sts		,	0	} ,
	{ "Prcs_APC_Set_Type"		, _K_D_IO	,	D_Prcs_APC_Set_Type			,	0	} ,
	{ "Prcs_APC_Vv_Position"	, _K_A_IO	,	A_Prcs_APC_Vv_Position		,	0	} ,
	{ "Prcs_APC_Press_Read"		, _K_A_IO	,	A_Prcs_APC_Press_Read		,	0	} ,
	{ "Prcs_APC_SetPoint"		, _K_A_IO	,	A_Prcs_APC_SetPoint			,	0	} ,

	{ "LL_APC_Ctrl_Mode"		, _K_D_IO	,	D_LL_APC_Ctrl_Mode			,	0	} ,
	{ "LL_APC_Close_Vv_Sts"		, _K_D_IO	,	D_LL_APC_Close_Vv_Sts		,	0	} ,
	{ "LL_APC_Open_Vv_Sts"		, _K_D_IO	,	D_LL_APC_Open_Vv_Sts		,	0	} ,
	{ "LL_APC_Set_Type"			, _K_D_IO	,	D_LL_APC_Set_Type			,	0	} ,
	{ "LL_APC_Vv_Position"		, _K_A_IO	,	A_LL_APC_Vv_Position		,	0	} ,
	{ "LL_APC_Press_Read"		, _K_A_IO	,	A_LL_APC_Press_Read			,	0	} ,
	{ "LL_APC_SetPoint"			, _K_A_IO	,	A_LL_APC_SetPoint			,	0	} ,

	{ "Convect_Press"			, _K_A_IO	,	A_Convect_Press				,	0	} ,
	{ "Convect_2_Press", _K_A_IO, A_Convect_2_Press, 0 },
	{ "Convect_Revision", _K_S_IO, S_Convect_Revision, 0 },
	{ "VacHeat_ATM_Sensor", _K_D_IO, D_VacHeat_ATM_Sensor, 0 },

	//	Wet Station
	//////////////////////////////////////////////////////////////////////////
	{ "WS1_Door_Sts"			, _K_D_IO, D_WS1_Door_Sts					, 0 },
	{ "WS2_Door_Sts"			, _K_D_IO, D_WS2_Door_Sts					, 0 },
	{ "WS1_Door_Ctrl"			, _K_D_IO, D_WS1_Door_Ctrl					, 0 },
	{ "WS2_Door_Ctrl"			, _K_D_IO, D_WS2_Door_Ctrl					, 0 },

	{ "WS1_Arm_Pos_Sts"			, _K_D_IO, D_WS1_Arm_Pos_Sts				, 0 },
	{ "WS2_Arm_Pos_Sts"			, _K_D_IO, D_WS2_Arm_Pos_Sts				, 0 },
	{ "WS1_Arm_Pos_Ctrl"		, _K_D_IO, D_WS1_Arm_Pos_Ctrl				, 0 },
	{ "WS2_Arm_Pos_Ctrl"		, _K_D_IO, D_WS2_Arm_Pos_Ctrl				, 0 },
	{ "WS1_Arm_Home_Sts"		, _K_D_IO, D_WS1_Arm_Home_Sts				, 0 },
	{ "WS2_Arm_Home_Sts"		, _K_D_IO, D_WS2_Arm_Home_Sts				, 0 },
	{ "WS1_ArmHome"			, _K_D_IO, D_WS1_ArmHome				, 0 },
	{ "WS2_ArmHome"			, _K_D_IO, D_WS2_ArmHome				, 0 },

	{ "WS1_ACID_Flow_Sts"		, _K_D_IO, D_WS1_ACID_Flow_Sts				, 0 },
	{ "WS2_ACID_Flow_Sts"		, _K_D_IO, D_WS2_ACID_Flow_Sts				, 0 },
	{ "WS1_DI_Flow_Sts"			, _K_D_IO, D_WS1_DI_Flow_Sts				, 0 },
	{ "WS2_DI_Flow_Sts"			, _K_D_IO, D_WS2_DI_Flow_Sts				, 0 },
	{ "WS1_N2_Blow_Sts"			, _K_D_IO, D_WS1_N2_Blow_Sts				, 0 },
	{ "WS2_N2_Blow_Sts"			, _K_D_IO, D_WS2_N2_Blow_Sts				, 0 },
	{ "WS1_HIDI_Flow_Sts"		, _K_D_IO, D_WS1_HIDI_Flow_Sts				, 0 },
	{ "WS2_HIDI_Flow_Sts"		, _K_D_IO, D_WS2_HIDI_Flow_Sts				, 0 },
	{ "WS1_Back_Side_Sts"		, _K_D_IO, D_WS1_Back_Side_Sts, 0 },
	{ "WS2_Back_Side_Sts"		, _K_D_IO, D_WS2_Back_Side_Sts				, 0 },
	{ "WS1_ACID_Flow"			, _K_D_IO, D_WS1_ACID_Flow					, 0 },
	{ "WS2_ACID_Flow"			, _K_D_IO, D_WS2_ACID_Flow					, 0 },
	{ "WS1_DI_Flow"				, _K_D_IO, D_WS1_DI_Flow					, 0 },
	{ "WS2_DI_Flow"				, _K_D_IO, D_WS2_DI_Flow					, 0 },
	{ "WS1_N2_Blow"				, _K_D_IO, D_WS1_N2_Blow					, 0 },
	{ "WS2_N2_Blow"				, _K_D_IO, D_WS2_N2_Blow					, 0 },
	{ "WS1_HIDI_Flow"			, _K_D_IO, D_WS1_HIDI_Flow					, 0 },
	{ "WS2_HIDI_Flow"			, _K_D_IO, D_WS2_HIDI_Flow					, 0 },
{ "WS1_Back_Side", _K_D_IO, D_WS1_Back_Side, 0 },
	{ "WS2_Back_Side", _K_D_IO, D_WS2_Back_Side, 0 },

	{ "WS1_Flow_Sensor"			, _K_A_IO, A_WS1_Flow_Sensor				, 0 },
	{ "WS2_Flow_Sensor"			, _K_A_IO, A_WS2_Flow_Sensor				, 0 },

	{ "WS1_Grip_On"				, _K_D_IO, D_WS1_Grip_On					, 0 },
	{ "WS2_Grip_On"				, _K_D_IO, D_WS2_Grip_On					, 0 },
	{ "WS1_Grip_On_Sts"			, _K_D_IO, D_WS1_Grip_On_Sts				, 0 },
	{ "WS2_Grip_On_Sts"			, _K_D_IO, D_WS2_Grip_On_Sts				, 0 },

	{ "WS1_Pin_Ctrl"			, _K_D_IO, D_WS1_Pin_Ctrl					, 0 },
	{ "WS2_Pin_Ctrl"			, _K_D_IO, D_WS2_Pin_Ctrl					, 0 },
	{ "WS1_Pin_Sts"				, _K_D_IO, D_WS1_Pin_Sts					, 0 },
	{ "WS2_Pin_Sts"				, _K_D_IO, D_WS2_Pin_Sts					, 0 },

	{ "WS1_RunSts"				, _K_D_IO, D_WS1_RunSts						, 0 },
	{ "WS2_RunSts"				, _K_D_IO, D_WS2_RunSts						, 0 },
	{ "WS1_HomSnsActv"			, _K_D_IO, D_WS1_HomeSts					, 0 },
	{ "WS2_HomSnsActv",			_K_D_IO, D_WS2_HomeSts,						0 },
	{ "WS1_PosModeSts"			, _K_D_IO, D_WS1_PosModeSts					, 0 },
	{ "WS2_PosModeSts"			, _K_D_IO, D_WS2_PosModeSts					, 0 },
	{ "WS1_ContModeSts"			, _K_D_IO, D_WS1_ContModeSts				, 0 },
	{ "WS2_ContModeSts"			, _K_D_IO, D_WS2_ContModeSts				, 0 },
	{ "WS1_ServoSts"			, _K_D_IO, D_WS1_ServoSts					, 0 },
	{ "WS2_ServoSts"			, _K_D_IO, D_WS2_ServoSts					, 0 },
	{ "WS1_Pos_Error"			, _K_D_IO, D_WS1_Pos_Error					, 0 },
	{ "WS2_Pos_Error"			, _K_D_IO, D_WS2_Pos_Error					, 0 },
	{ "WS1_AtStation"			, _K_D_IO, D_WS1_AtStation					, 0 },
	{ "WS2_AtStation"			, _K_D_IO, D_WS2_AtStation					, 0 },
	{ "WS1_Motor_Amp"			, _K_D_IO, D_WS1_Motor_Amp					, 0 },
	{ "WS2_Motor_Amp"			, _K_D_IO, D_WS2_Motor_Amp					, 0 },
	{ "WS1_MotionMode"			, _K_D_IO, D_WS1_MotionMode					, 0 },
	{ "WS2_MotionMode"			, _K_D_IO, D_WS2_MotionMode					, 0 },
	{ "WS1_ContMode"			, _K_D_IO, D_WS1_ContMode					, 0 },
	{ "WS2_ContMode"			, _K_D_IO, D_WS2_ContMode					, 0 },
	{ "WS1_Control"				, _K_D_IO, D_WS1_Control					, 0 },
	{ "WS2_Control"				, _K_D_IO, D_WS2_Control					, 0 },
	{ "WS1_Servo"				, _K_D_IO, D_WS1_Servo						, 0 },
	{ "WS2_Servo"				, _K_D_IO, D_WS2_Servo						, 0 },
	{ "WS1_DefinePos_0"			, _K_D_IO, D_WS1_DefinePos_0				, 0 },
	{ "WS2_DefinePos_0"			, _K_D_IO, D_WS2_DefinePos_0				, 0 },
	{ "WS1_Pos_Read"			, _K_A_IO, A_WS1_Pos_Read					, 0 },
	{ "WS2_Pos_Read"			, _K_A_IO, A_WS2_Pos_Read					, 0 },
	{ "WS1_Vel_Read"			, _K_A_IO, A_WS1_Vel_Read					, 0 },
	{ "WS2_Vel_Read"			, _K_A_IO, A_WS2_Vel_Read					, 0 },
	{ "WS1_Distance"			, _K_A_IO, A_WS1_Distance					, 0 },
	{ "WS2_Distance"			, _K_A_IO, A_WS2_Distance					, 0 },
	{ "WS1_Velocity"			, _K_A_IO, A_WS1_Velocity					, 0 },
	{ "WS2_Velocity"			, _K_A_IO, A_WS2_Velocity					, 0 },

	//	ETC
	//////////////////////////////////////////////////////////////////////////
	{ "AutoCalibration_Run"		, _K_D_IO	,	D_AutoCalibration_Run		,	0	} ,

	{ "IO_Driver_Loding"		, _K_D_IO	,	D_IO_Driver_Loding			,	0	} ,
	{ "MAPPING"					, _K_D_IO	,	D_MAPPING					,	0	} ,
	{ "RobotType"				, _K_D_IO	,	D_FM_ROBOT_TYPE				,	0	} ,

	{ "FM_FFU_RPM", _K_A_IO, A_FM_FFU_RPM, 0 },	
	{ "FM_FFU_PRESS", _K_A_IO, A_FM_FFU_PRESS, 0 },	
	{ "EFEM_FFU_STATUS",	_K_D_IO		,	D_EFFM_FFU_STATUS, 0 },	
	{ "Bulkfill_Error"			, _K_D_IO	,	D_Bulkfill_Error			,	0	} ,
	
	{ "AI_WS1_Gas", _K_A_IO, AI_WS1_Gas, 0 },
	{ "AI_WS2_Gas", _K_A_IO, AI_WS2_Gas, 0 },
	{ "AO_WS1_Gas", _K_A_IO, AO_WS1_Gas, 0 },
	{ "AO_WS2_Gas", _K_A_IO, AO_WS2_Gas, 0 },
	
	{ "DI_WS1_Liq_empty", _K_D_IO, DI_WS1_Liq_empty, 0 },
	{ "DI_WS2_Liq_empty", _K_D_IO, DI_WS2_Liq_empty, 0 },

	{ "WS_CO2_Flow",     _K_D_IO, WS_CO2_Flow, 0 },
	{ "WS_CO2_Flow_Sts", _K_D_IO, WS_CO2_Flow_Sts, 0 },

	{ "AI_CO2_Gas", _K_A_IO, AI_CO2_Gas, 0 },
	{ "AO_CO2_Gas", _K_A_IO, AO_CO2_Gas, 0 },

	{ "Bulkfill_Leak", _K_D_IO, Bulkfill_Leak, 0 },
	{ "WS_Bulk_Fill_level", _K_D_IO, WS_Bulk_Fill_level, 0 },

	{ "WS_Fac_Vac", _K_A_IO, WS_Fac_Vac, 0 },
	{ "WS_N2", _K_A_IO, WS_N2, 0 },
	{ "WS_CDA", _K_A_IO, WS_CDA, 0 },

	{ "LP_Wafer_Size", _K_D_IO, D_LP_Wafer_Size, 0 },
	{ "Adapter_Ring", _K_D_IO, D_Adapter_Ring, 0 },
	{ "Carrier_Tray_Sns1", _K_D_IO, D_Carrier_Tray_Sns1, 0 },
	{ "Carrier_Tray_Sns2", _K_D_IO, D_Carrier_Tray_Sns2, 0 },
	{ "GenevaBOption", _K_D_IO, D_GenevaBOption, 0 },

	""
};

/************************************************************************

	Program_Main

************************************************************************/
Module_Status Program_Main()
{
	int			nCommStatus;
	int			nReadData, nIndex;
	double		dr , dl;
	// MI 185: 2015-07-24: Brian M.  commenting out unused variables here to remove build warnings.
	//unsigned	uRobot_SimulatorThreadID, uAligner_SimluatorThreadID, uDiscMotion_SimluatorThreadID;
	unsigned	uLoadPort_SimulatorThreadID[3]={0,}, uStation_SimluatorThreadID;
	unsigned	uAMHS_SimulatorThreadID[3]={0,}, uPress_SimluatorThreadID, uAutFill_SimluatorThreadID;
	unsigned	uWS_SimluatorThreadID[2] = { 0, };

	printf("ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR\n");
	printf("##                                                            ###\n");
	printf("##     [ERROR] SIMULATION TEST 2 NO LONGER SUPPORTED          ###\n");
	printf("##                                                            ###\n");
	printf("ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR\n");

	return SYS_ABORTED;

	//if ( READ_DIGITAL( D_IO_Driver_Loding , &nCommStatus ) != 0 )	return SYS_SUCCESS;

	/*printf("###################################################################\n");
	printf("##                                                              ###\n");
	printf("##                  [WARNING] SIMULATION TEST  2                 ###\n");
	printf("##                                                              ###\n");	
	printf("###################################################################\n");*/

	Utilities_Simulator();

	ServiceSimulateFlags();

	g_bTHREAD_END = FALSE;
				//g_hLoadPortThread[LoadPort1] = (HANDLE)_beginthreadex( NULL, 0, (void *)LoadPort_Simulator, (void*)LoadPort1, 0, &uLoadPort_SimulatorThreadID[LoadPort1] );
				//g_hLoadPortThread[LoadPort2] = (HANDLE)_beginthreadex( NULL, 0, (void *)LoadPort_Simulator, (void*)LoadPort2, 0, &uLoadPort_SimulatorThreadID[LoadPort2] );
				//g_hLoadPortThread[LoadPort3] = (HANDLE)_beginthreadex( NULL, 0, (void *)LoadPort_Simulator, (void*)LoadPort3, 0, &uLoadPort_SimulatorThreadID[LoadPort3] );
				//if ((g_hLoadPortThread[LoadPort1] == NULL) || (g_hLoadPortThread[LoadPort2] == NULL) || (g_hLoadPortThread[LoadPort3] == NULL))
				//{
				//	printf("[ERROR] LoadPort_Simulator Thread is not created.\n");
				//	return SYS_ABORTED;
				//}

				//g_hAMHSThread[LoadPort1] = (HANDLE)_beginthreadex( NULL, 0, (void *)AMHS_Simulator, (void*)LoadPort1, 0, &uAMHS_SimulatorThreadID[LoadPort1] );
				//g_hAMHSThread[LoadPort2] = (HANDLE)_beginthreadex( NULL, 0, (void *)AMHS_Simulator, (void*)LoadPort2, 0, &uAMHS_SimulatorThreadID[LoadPort2] );
				//g_hAMHSThread[LoadPort3] = (HANDLE)_beginthreadex( NULL, 0, (void *)AMHS_Simulator, (void*)LoadPort3, 0, &uAMHS_SimulatorThreadID[LoadPort3] );
				//if ((g_hAMHSThread[LoadPort1] == NULL) || (g_hAMHSThread[LoadPort2] == NULL) || (g_hAMHSThread[LoadPort3] == NULL))
				//{
				//	printf("[ERROR] AMHS_Simulator Thread is not created.\n");
				//	return SYS_ABORTED;
				//}

	/*			g_hRobotThread = (HANDLE)_beginthreadex( NULL, 0, (void *)EFEM_Robot_Simulator, NULL, 0, &uRobot_SimulatorThreadID );
				if ( g_hRobotThread == NULL )
				{
					printf("[ERROR] Robot_Simulator Thread is not created.\n");
					return SYS_ABORTED;
				}

				g_hAlignerThread = (HANDLE)_beginthreadex( NULL, 0, (void *)Aligner_Simulator, NULL, 0, &uAligner_SimluatorThreadID );
				if ( g_hAlignerThread == NULL )
				{
					printf("[ERROR] Aligner_Simulator Thread is not created.\n");
					return SYS_ABORTED;
				}*/

	/*			g_hDiscMotionThread = (HANDLE)_beginthreadex( NULL, 0, (void *)Disc_Motion_Simulator, NULL, 0, &uDiscMotion_SimluatorThreadID );
				if ( g_hDiscMotionThread == NULL )
				{
					printf("[ERROR] TempCtrl_Simulator Thread is not created.\n");
					return SYS_ABORTED;
				}
	*/
	g_hPressThread = (HANDLE)_beginthreadex( NULL, 0, (void *)Pressure_Simulator, NULL, 0, &uPress_SimluatorThreadID );
	if ( g_hPressThread == NULL )
	{
		printf("[ERROR] Pressure_Simulator Thread is not created.\n");
		return SYS_ABORTED;
	}

	g_hAutoFillThread = (HANDLE)_beginthreadex( NULL, 0, (void *)AutoFill_Simulator, NULL, 0, &uAutFill_SimluatorThreadID );
	if ( g_hAutoFillThread == NULL )
	{
		printf("[ERROR] AutoFill_Simulator Thread is not created.\n");
		return SYS_ABORTED;
	}

	if (READ_DIGITAL(D_PM_Module_Type, &nCommStatus) == 1/*WetStation*/)
	{
		g_hWetStationThread[0] = (HANDLE)_beginthreadex(NULL, 0, (void *)WetStation_Simulator, (void*)0, 0, &uWS_SimluatorThreadID[0]);
		g_hWetStationThread[1] = (HANDLE)_beginthreadex(NULL, 0, (void *)WetStation_Simulator, (void*)1, 0, &uWS_SimluatorThreadID[1]);
		if ((g_hWetStationThread[0] == NULL) || (g_hWetStationThread[0] == NULL))
		{
			printf("[ERROR] WetStation_Simulator Thread is not created.\n");
			return SYS_ABORTED;
		}
	}

	g_hStationThread[0] = (HANDLE)_beginthreadex( NULL, 0, (void *)Station_Simulator, (void*)0, 0, &uStation_SimluatorThreadID );
	g_hStationThread[1] = (HANDLE)_beginthreadex( NULL, 0, (void *)Station_Simulator, (void*)1, 0, &uStation_SimluatorThreadID );
	g_hStationThread[2] = (HANDLE)_beginthreadex( NULL, 0, (void *)Station_Simulator, (void*)2, 0, &uStation_SimluatorThreadID );
	g_hStationThread[3] = (HANDLE)_beginthreadex( NULL, 0, (void *)Station_Simulator, (void*)3, 0, &uStation_SimluatorThreadID );
	g_hStationThread[4] = (HANDLE)_beginthreadex( NULL, 0, (void *)Station_Simulator, (void*)4, 0, &uStation_SimluatorThreadID );
	g_hStationThread[5] = (HANDLE)_beginthreadex( NULL, 0, (void *)Station_Simulator, (void*)5, 0, &uStation_SimluatorThreadID );
	if ((g_hStationThread[0] == NULL) || (g_hStationThread[1] == NULL) || (g_hStationThread[2] == NULL) ||
		(g_hStationThread[3] == NULL) || (g_hStationThread[4] == NULL) || (g_hStationThread[5] == NULL))
	{
		printf("[ERROR] Station_Simulator Thread is not created.\n");
		return SYS_ABORTED;
	}

 	while ( TRUE )
 	{
		ServiceSimulateFlags();

		//==========================================================================================
		// Chamber & O2 (PMºÎ)
		nReadData = READ_DIGITAL( D_Chmbr_Lock_Vv , &nCommStatus );
		if ( nReadData == 0 )	WRITE_DIGITAL( D_Chmbr_Lock_Vv_Sts , 1 , &nCommStatus );
		else					WRITE_DIGITAL( D_Chmbr_Lock_Vv_Sts , 0 , &nCommStatus );

		nReadData = READ_DIGITAL( D_O2_Sample_Vv , &nCommStatus );
		WRITE_DIGITAL( D_O2_Sample_Vv_Sts , nReadData , &nCommStatus );

		nReadData = READ_DIGITAL( D_VacHeat_Exhst_Vv , &nCommStatus );
		WRITE_DIGITAL( D_VacHeat_Exhst_Vv_Sts , nReadData , &nCommStatus );
		
		nReadData = READ_DIGITAL( D_Cool_LowPurgeVv , &nCommStatus );
		WRITE_DIGITAL( D_Cool_LowPurgeVvSts , nReadData , &nCommStatus );	

		//==========================================================================================
		// LoadLock
		nReadData = READ_DIGITAL( D_LL_Ring_Seal_Vac_Ctrl , &nCommStatus );
		WRITE_DIGITAL( D_LL_Ring_Seal_Vac_Sts , nReadData , &nCommStatus );		
		if (nReadData)		WRITE_ANALOG( A_Ring_Seal , -615.0 , &nCommStatus );
		else				WRITE_ANALOG( A_Ring_Seal ,    0.0 , &nCommStatus );

		nReadData = READ_DIGITAL( D_LL_Door_Seal_Vac_Ctrl , &nCommStatus );
		WRITE_DIGITAL( D_LL_Door_Seal_Vac_Sts , nReadData , &nCommStatus );	
		if (nReadData)		WRITE_ANALOG( A_Door_Seal , -615.0 , &nCommStatus );
		else				WRITE_ANALOG( A_Door_Seal ,    0.0 , &nCommStatus );

		nReadData = READ_DIGITAL( D_LL_Evacuate_Vv , &nCommStatus );
		WRITE_DIGITAL( D_LL_Evacuate_Vv_Sts , nReadData , &nCommStatus );		

		nReadData = READ_DIGITAL( D_LL_Purge_Vv , &nCommStatus );
		WRITE_DIGITAL( D_LL_Purge_Vv_Sts , nReadData , &nCommStatus );	

		nReadData = READ_DIGITAL( D_LP_Wafer_Size, &nCommStatus );
		if (nReadData == 2)	// 2 = 400mm
		{
			WRITE_DIGITAL( D_Adapter_Ring , 0 , &nCommStatus );	
			WRITE_DIGITAL( D_Carrier_Tray_Sns1 , 0 , &nCommStatus );	
			WRITE_DIGITAL( D_Carrier_Tray_Sns2 , 0 , &nCommStatus );	
		}
		else
		{
			WRITE_DIGITAL( D_Adapter_Ring , 1 , &nCommStatus );	
			WRITE_DIGITAL( D_Carrier_Tray_Sns1 , 1 , &nCommStatus );	
			WRITE_DIGITAL( D_Carrier_Tray_Sns2 , 1 , &nCommStatus );	
		}

		//==========================================================================================
		// Wafer Vacuum Sensor
		for ( nIndex = 0 ; nIndex < 6 ; nIndex++ )
		{
			nReadData = READ_DIGITAL( D_Stg1_Wfr_Sns_Vac + nIndex , &nCommStatus );
			if ( READ_DIGITAL( D_CTC_PM1_Wafer_Status + nIndex , &nCommStatus ) > 0 )
				WRITE_DIGITAL( D_Stg1_Wfr_Sns_Sts + nIndex , nReadData , &nCommStatus );		
		}

		//==========================================================================================
		// Bubbler
		nReadData = READ_DIGITAL( D_Bubbler_Feed_Vv , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler_FeedVv_Sts , nReadData , &nCommStatus );

		nReadData = READ_DIGITAL( D_Bubbler_Dlvry_Vv , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler_DlvryVv_Sts , nReadData , &nCommStatus );

		nReadData = READ_DIGITAL( D_Bubbler2_Feed_Vv , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler2_FeedVv_Sts , nReadData , &nCommStatus );

		nReadData = READ_DIGITAL( D_Bubbler2_Dlvry_Vv , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler2_DlvryVv_Sts , nReadData , &nCommStatus );

		nReadData = READ_DIGITAL( D_FA_Line_Vent_Vv , &nCommStatus );
		WRITE_DIGITAL( D_FA_Line_Vent_Sts , nReadData , &nCommStatus );

		nReadData = READ_DIGITAL( D_FA2_Line_Vent_Vv , &nCommStatus );
		WRITE_DIGITAL( D_FA2_Line_Vent_Sts , nReadData , &nCommStatus );

		//==========================================================================================
		// Chuck Temp
		for ( nIndex = 0 ; nIndex < 4 ; nIndex++ )
		{
			nReadData = READ_DIGITAL( D_Chuck1_Heater_Pwr + nIndex , &nCommStatus );
			WRITE_DIGITAL( D_Chuck1_Heater_PwrSts + nIndex , nReadData , &nCommStatus );
			dr = READ_ANALOG( A_Chuck1_Temp_Mnt + nIndex , &nCommStatus );
			dl = READ_ANALOG( A_Chuck1_Temp_Set + nIndex , &nCommStatus );
			if ( nReadData == 1 )
			{
				if ( dl >= 23.5 )
				{
					if		( dl < dr ) 	WRITE_ANALOG( A_Chuck1_Temp_Mnt + nIndex , dr - 0.003 , &nCommStatus );
					else if ( dl >= dr ) 	WRITE_ANALOG( A_Chuck1_Temp_Mnt + nIndex , dr + 0.005 , &nCommStatus );
				}
				else if	( dl < dr )
				{
					if ( dr >= 23.5 )	WRITE_ANALOG( A_Chuck1_Temp_Mnt + nIndex , dr - 0.003 , &nCommStatus );
				}
			}
			else
			{
				if		( 23.5 < dr )	WRITE_ANALOG( A_Chuck1_Temp_Mnt + nIndex , dr - 0.003 , &nCommStatus );
				else if ( 23.5 >= dr )	WRITE_ANALOG( A_Chuck1_Temp_Mnt + nIndex , dr + 0.005 , &nCommStatus );
			}
		}

		dr = READ_ANALOG( A_Chuck5_Temp_Mnt , &nCommStatus );
		if		( 17.5 < dr )	WRITE_ANALOG( A_Chuck5_Temp_Mnt , dr - 0.003 , &nCommStatus );
		else if ( 17.5 >= dr )	WRITE_ANALOG( A_Chuck5_Temp_Mnt , dr + 0.005 , &nCommStatus );

		if ( READ_DIGITAL( D_AutoCalibration_Run , &nCommStatus ) == 0 )
		{
			//==========================================================================================
			// Insulation Temp.
			for ( nIndex = 0 ; nIndex < 4 ; nIndex++ )
			{
				nReadData = READ_DIGITAL( D_Insul1_Heater_Pwr + nIndex , &nCommStatus );
				WRITE_DIGITAL( D_Insul1_Heater_PwrSts + nIndex , nReadData , &nCommStatus );
				dr = READ_ANALOG( A_Insul1_Temp_Mnt + nIndex , &nCommStatus );
				dl = READ_ANALOG( A_Insul1_Temp_Set + nIndex , &nCommStatus );
				if ( nReadData == 1 )
				{
					if ( dl >= 20.5 )
					{
						if		( dl < dr ) 	WRITE_ANALOG( A_Insul1_Temp_Mnt + nIndex , dr - 0.02 , &nCommStatus );
						else if ( dl >= dr ) 	WRITE_ANALOG( A_Insul1_Temp_Mnt + nIndex , dr + 0.01 , &nCommStatus );
					}
					else if	( dl < dr )
					{
						if ( dr >= 20.5 )	WRITE_ANALOG( A_Insul1_Temp_Mnt + nIndex , dr - 0.02 , &nCommStatus );
					}
				}
				else
				{
					if		( 20.5 < dr )	WRITE_ANALOG( A_Insul1_Temp_Mnt + nIndex , dr - 0.02 , &nCommStatus );
					else if ( 20.5 >= dr )	WRITE_ANALOG( A_Insul1_Temp_Mnt + nIndex , dr + 0.01 , &nCommStatus );
				}
			}

			//==========================================================================================
			// Elbow1 Temp.
			for ( nIndex = 0 ; nIndex < 4 ; nIndex++ )
			{
				nReadData = READ_DIGITAL( D_Elbow1_Heater_Pwr + nIndex , &nCommStatus );
				WRITE_DIGITAL( D_Elbow1_Heater_PwrSts + nIndex , nReadData , &nCommStatus );
				dr = READ_ANALOG( A_Elbow1_Temp_Mnt + nIndex , &nCommStatus );
				dl = READ_ANALOG( A_Elbow1_Temp_Set + nIndex , &nCommStatus );
				if ( nReadData == 1 )
				{
					if ( dl >= 20.5 )
					{
						if		( dl < dr ) 	WRITE_ANALOG( A_Elbow1_Temp_Mnt + nIndex , dr - 0.02 , &nCommStatus );
						else if ( dl >= dr ) 	WRITE_ANALOG( A_Elbow1_Temp_Mnt + nIndex , dr + 0.01 , &nCommStatus );
					}
					else if	( dl < dr )
					{
						if ( dr >= 20.5 )	WRITE_ANALOG( A_Elbow1_Temp_Mnt + nIndex , dr - 0.02 , &nCommStatus );
					}
				}
				else
				{
					if		( 20.5 < dr )	WRITE_ANALOG( A_Elbow1_Temp_Mnt + nIndex , dr - 0.02 , &nCommStatus );
					else if ( 20.5 >= dr )	WRITE_ANALOG( A_Elbow1_Temp_Mnt + nIndex , dr + 0.01 , &nCommStatus );
				}
			}
		}
		else
		{
			//==========================================================================================
			//	Temp. Compensation
			for ( nIndex = 0 ; nIndex < 4 ; nIndex++ )
			{
				if ( READ_DIGITAL( D_CTC_PM1_Wafer_Status + nIndex , &nCommStatus ) > 0 )
				{
					nReadData = READ_DIGITAL( D_Chuck1_Heater_Pwr + nIndex , &nCommStatus );
					dl = READ_ANALOG( A_Chuck1_Temp_Set + nIndex , &nCommStatus );

					if ( nReadData == 1 )
					{
						if ( dl >= 20.5 )
						{
							dr = READ_ANALOG( A_ProfileTC_Temp_Mnt , &nCommStatus );
							if ( dl < dr )	WRITE_ANALOG( A_ProfileTC_Temp_Mnt , dr - 0.09 , &nCommStatus );
							else			WRITE_ANALOG( A_ProfileTC_Temp_Mnt , dr + 0.07 , &nCommStatus );
							dr = READ_ANALOG( A_Insul1_Temp_Mnt , &nCommStatus );
							if ( dl < dr )	WRITE_ANALOG( A_Insul1_Temp_Mnt , dr - 0.05 , &nCommStatus );
							else			WRITE_ANALOG( A_Insul1_Temp_Mnt , dr + 0.01 , &nCommStatus );
							dr = READ_ANALOG( A_Insul2_Temp_Mnt , &nCommStatus );
							if ( dl < dr )	WRITE_ANALOG( A_Insul2_Temp_Mnt , dr - 0.01 , &nCommStatus );
							else			WRITE_ANALOG( A_Insul2_Temp_Mnt , dr + 0.05 , &nCommStatus );
							dr = READ_ANALOG( A_Insul3_Temp_Mnt , &nCommStatus );
							if ( dl < dr )	WRITE_ANALOG( A_Insul3_Temp_Mnt , dr - 0.03 , &nCommStatus );
							else			WRITE_ANALOG( A_Insul3_Temp_Mnt , dr + 0.03 , &nCommStatus );
							dr = READ_ANALOG( A_Insul4_Temp_Mnt , &nCommStatus );
							if ( dl < dr )	WRITE_ANALOG( A_Insul4_Temp_Mnt , dr - 0.02 , &nCommStatus );
							else			WRITE_ANALOG( A_Insul4_Temp_Mnt , dr + 0.01 , &nCommStatus );
							dr = READ_ANALOG( A_Elbow1_Temp_Mnt , &nCommStatus );
							if ( dl < dr )	WRITE_ANALOG( A_Elbow1_Temp_Mnt , dr - 0.03 , &nCommStatus );
							else			WRITE_ANALOG( A_Elbow1_Temp_Mnt , dr + 0.05 , &nCommStatus );
							dr = READ_ANALOG( A_Elbow2_Temp_Mnt , &nCommStatus );
							if ( dl < dr )	WRITE_ANALOG( A_Elbow2_Temp_Mnt , dr - 0.02 , &nCommStatus );
							else			WRITE_ANALOG( A_Elbow2_Temp_Mnt , dr + 0.02 , &nCommStatus );
						}
						else
						{
							if ( dr >= 20.5 )
							{
								WRITE_ANALOG( A_ProfileTC_Temp_Mnt , dr - 0.09 , &nCommStatus );
								WRITE_ANALOG( A_Insul1_Temp_Mnt , dr - 0.05 , &nCommStatus );
								WRITE_ANALOG( A_Insul2_Temp_Mnt , dr - 0.01 , &nCommStatus );
								WRITE_ANALOG( A_Insul3_Temp_Mnt , dr - 0.01 , &nCommStatus );
								WRITE_ANALOG( A_Insul4_Temp_Mnt , dr - 0.03 , &nCommStatus );
								WRITE_ANALOG( A_Elbow1_Temp_Mnt , dr - 0.03 , &nCommStatus );
								WRITE_ANALOG( A_Elbow2_Temp_Mnt , dr - 0.02 , &nCommStatus );
							}
						}
					}
					else
					{
						dr = READ_ANALOG( A_ProfileTC_Temp_Mnt , &nCommStatus );
						if ( 20.5 < dr )	WRITE_ANALOG( A_ProfileTC_Temp_Mnt , dr - 0.09 , &nCommStatus );
						else				WRITE_ANALOG( A_ProfileTC_Temp_Mnt , dr + 0.07 , &nCommStatus );

						dr = READ_ANALOG( A_Insul1_Temp_Mnt , &nCommStatus );
						if ( 20.5 < dr )	WRITE_ANALOG( A_Insul1_Temp_Mnt , dr - 0.05 , &nCommStatus );
						else				WRITE_ANALOG( A_Insul1_Temp_Mnt , dr + 0.01 , &nCommStatus );

						dr = READ_ANALOG( A_Insul2_Temp_Mnt , &nCommStatus );
						if ( 20.5 < dr )	WRITE_ANALOG( A_Insul2_Temp_Mnt , dr - 0.01 , &nCommStatus );
						else				WRITE_ANALOG( A_Insul2_Temp_Mnt , dr + 0.05 , &nCommStatus );

						dr = READ_ANALOG( A_Insul3_Temp_Mnt , &nCommStatus );
						if ( 20.5 < dr )	WRITE_ANALOG( A_Insul3_Temp_Mnt , dr - 0.01 , &nCommStatus );
						else				WRITE_ANALOG( A_Insul3_Temp_Mnt , dr + 0.07 , &nCommStatus );

						dr = READ_ANALOG( A_Insul4_Temp_Mnt , &nCommStatus );
						if ( 20.5 < dr )	WRITE_ANALOG( A_Insul4_Temp_Mnt , dr - 0.03 , &nCommStatus );
						else				WRITE_ANALOG( A_Insul4_Temp_Mnt , dr + 0.05 , &nCommStatus );

						dr = READ_ANALOG( A_Elbow1_Temp_Mnt , &nCommStatus );
						if ( 20.5 < dr )	WRITE_ANALOG( A_Elbow1_Temp_Mnt , dr - 0.03 , &nCommStatus );
						else				WRITE_ANALOG( A_Elbow1_Temp_Mnt , dr + 0.02 , &nCommStatus );

						dr = READ_ANALOG( A_Elbow2_Temp_Mnt , &nCommStatus );
						if ( 20.5 < dr )	WRITE_ANALOG( A_Elbow2_Temp_Mnt , dr - 0.03 , &nCommStatus );
						else				WRITE_ANALOG( A_Elbow2_Temp_Mnt , dr + 0.03 , &nCommStatus );
					}
				}
			}
		}
		

		// Bubbler1 Temp.
		nReadData = READ_DIGITAL( D_Bublr1_Heater_Pwr , &nCommStatus );
		WRITE_DIGITAL( D_Bublr1_Heater_PwrSts , nReadData , &nCommStatus );
		dr = READ_ANALOG( A_Bublr1_Temp_Mnt , &nCommStatus );
		dl = READ_ANALOG( A_Bublr1_Temp_Set , &nCommStatus );
		if ( nReadData == 1 ) 
		{
			if ( dl >= 20.5 )
			{
				if		( dl < dr ) 	WRITE_ANALOG( A_Bublr1_Temp_Mnt , dr - 0.01 , &nCommStatus );
				else if ( dl >= dr ) 	WRITE_ANALOG( A_Bublr1_Temp_Mnt , dr + 0.02 , &nCommStatus );
			}
			else if	( dl < dr )
			{
				if ( dr >= 20.5 )	WRITE_ANALOG( A_Bublr1_Temp_Mnt , dr - 0.01 , &nCommStatus );
			}
		}
		else
		{
			if		( 20.5 < dr )	WRITE_ANALOG( A_Bublr1_Temp_Mnt , dr - 0.01 , &nCommStatus );
			else if ( 20.5 >= dr )	WRITE_ANALOG( A_Bublr1_Temp_Mnt , dr + 0.02 , &nCommStatus );
		}
		
		// Bubbler1 Temp.
		nReadData = READ_DIGITAL( D_Bublr2_Heater_Pwr , &nCommStatus );
		WRITE_DIGITAL( D_Bublr2_Heater_PwrSts , nReadData , &nCommStatus );
		dr = READ_ANALOG( A_Bublr2_Temp_Mnt , &nCommStatus );
		dl = READ_ANALOG( A_Bublr2_Temp_Set , &nCommStatus );
		if ( nReadData == 1 )
		{
			if ( dl >= 20.5 )
			{
				if		( dl < dr ) 	WRITE_ANALOG( A_Bublr2_Temp_Mnt , dr - 0.02 , &nCommStatus );
				else if ( dl >= dr ) 	WRITE_ANALOG( A_Bublr2_Temp_Mnt , dr + 0.01 , &nCommStatus );
			}
			else if	( dl < dr )
			{
				if ( dr >= 20.5 )	WRITE_ANALOG( A_Bublr2_Temp_Mnt , dr - 0.02 , &nCommStatus );
			}
		}
		else
		{
			if		( 20.5 < dr )	WRITE_ANALOG( A_Bublr2_Temp_Mnt , dr - 0.02 , &nCommStatus );
			else if ( 20.5 >= dr )	WRITE_ANALOG( A_Bublr2_Temp_Mnt , dr + 0.01 , &nCommStatus );
		}

		//	MFC
		//////////////////////////////////////////////////////////////////////////
		for ( nIndex = 0 ; nIndex < 6 ; nIndex++ )
		{
			dl = READ_ANALOG( A_MFC1_Set + nIndex , &nCommStatus );
			if ( READ_DIGITAL( D_Gas1_Vv + nIndex , &nCommStatus ) == 1 )	WRITE_ANALOG( A_MFC1_Monitor + nIndex , dl , &nCommStatus );
			else															WRITE_ANALOG( A_MFC1_Monitor + nIndex , 0 , &nCommStatus );
		}

		dr = READ_ANALOG( A_O2LevelRead , &nCommStatus );
		if ( READ_DIGITAL( D_O2_Sample_Vv_Sts , &nCommStatus ) == 1 )
		{
			if		( 8.4 < dr ) 	WRITE_ANALOG( A_O2LevelRead , dr - 0.5 , &nCommStatus );
			else if ( 8.4 >= dr ) 	WRITE_ANALOG( A_O2LevelRead , dr + 0.5 , &nCommStatus );
		}
		else
		{
			if		( 1.1 < dr ) 	WRITE_ANALOG( A_O2LevelRead , dr - 0.3 , &nCommStatus );
			else if ( 1.1 >= dr ) 	WRITE_ANALOG( A_O2LevelRead , dr + 0.3 , &nCommStatus );
		}

	
 		Sleep( 1 ); 
 	}// while( TRUE )

	return SYS_SUCCESS;
}


void ServiceSimulateFlags()
{
	static int serviceHoldoffCounter = 0;
	static int startupServiceCounter = 100;

	int serviceNow = 1;
	int nCommStatus = 0;

	if (serviceHoldoffCounter > 0)
	{
		serviceHoldoffCounter--;
		return;
	}
	else if (startupServiceCounter > 0)
		startupServiceCounter--;
	else
		serviceHoldoffCounter = 100;

	if (g_SimulateConvectrons)
	{
		char buf[256] = "";
		READ_STRING(S_Convect_Revision, buf, &nCommStatus);
		if (buf[0])
			g_SimulateConvectrons = 0;
	}
}

int g_SimulateConvectrons = 1;
