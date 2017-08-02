#ifndef IODEFINE_H
#define IODEFINE_H

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include <io.h>

#include <KutlFile.h>
#include <Kutlstr.h>
#include <Kutltime.h>
#include <kutlgui.h>

#include "cimseqnc.h"
#include <Common/VC/CommonLog.h>

//////////////////////////////////////////////////////////////////////////
//
// IO LIST
//
//////////////////////////////////////////////////////////////////////////
typedef enum {
	S_SCHEDULER				,
	S_GEM_CONTROL			,
	D_CTC_MAIN_CONTROL		,
	D_CTC_MAIN_CONTROL2		,
	D_CTC_MAIN_CONTROL3		,
	D_CTC_MAIN_CONTROL4		,
	S_CTC_MID_READ			,
	S_CTC_MID_READ2			,
	S_CTC_MID_READ3			,
	S_CTC_MID_READ4			,
	S_CTC_JID_READ			,
	S_CTC_JID_READ2			,
	S_CTC_JID_READ3			,
	S_CTC_JID_READ4			,

	S_CTC_SELECT_CLUSTER	,
	S_CTC_SELECT_CLUSTER2	,
	S_CTC_SELECT_CLUSTER3	,
	S_CTC_SELECT_CLUSTER4	,

	S_CTC_CLUSTER01_RECIPE	,
	S_CTC_CLUSTER02_RECIPE	,
	S_CTC_CLUSTER03_RECIPE	,
	S_CTC_CLUSTER04_RECIPE	,
	S_CTC_CLUSTER05_RECIPE	,
	S_CTC_CLUSTER06_RECIPE	,
	S_CTC_CLUSTER07_RECIPE	,
	S_CTC_CLUSTER08_RECIPE	,
	S_CTC_CLUSTER09_RECIPE	,
	S_CTC_CLUSTER10_RECIPE	,
	S_CTC_CLUSTER11_RECIPE	,
	S_CTC_CLUSTER12_RECIPE	,
	S_CTC_CLUSTER13_RECIPE	,
	S_CTC_CLUSTER14_RECIPE	,
	S_CTC_CLUSTER15_RECIPE	,
	S_CTC_CLUSTER16_RECIPE	,
	S_CTC_CLUSTER17_RECIPE	,
	S_CTC_CLUSTER18_RECIPE	,
	S_CTC_CLUSTER19_RECIPE	,
	S_CTC_CLUSTER20_RECIPE	,
	S_CTC_CLUSTER21_RECIPE	,
	S_CTC_CLUSTER22_RECIPE	,
	S_CTC_CLUSTER23_RECIPE	,
	S_CTC_CLUSTER24_RECIPE	,
	S_CTC_CLUSTER25_RECIPE	,

	S_CTC_CLUSTER01_RECIPE2	,
	S_CTC_CLUSTER02_RECIPE2	,
	S_CTC_CLUSTER03_RECIPE2	,
	S_CTC_CLUSTER04_RECIPE2	,
	S_CTC_CLUSTER05_RECIPE2	,
	S_CTC_CLUSTER06_RECIPE2	,
	S_CTC_CLUSTER07_RECIPE2	,
	S_CTC_CLUSTER08_RECIPE2	,
	S_CTC_CLUSTER09_RECIPE2	,
	S_CTC_CLUSTER10_RECIPE2	,
	S_CTC_CLUSTER11_RECIPE2	,
	S_CTC_CLUSTER12_RECIPE2	,
	S_CTC_CLUSTER13_RECIPE2	,
	S_CTC_CLUSTER14_RECIPE2	,
	S_CTC_CLUSTER15_RECIPE2	,
	S_CTC_CLUSTER16_RECIPE2	,
	S_CTC_CLUSTER17_RECIPE2	,
	S_CTC_CLUSTER18_RECIPE2	,
	S_CTC_CLUSTER19_RECIPE2	,
	S_CTC_CLUSTER20_RECIPE2	,
	S_CTC_CLUSTER21_RECIPE2	,
	S_CTC_CLUSTER22_RECIPE2	,
	S_CTC_CLUSTER23_RECIPE2	,
	S_CTC_CLUSTER24_RECIPE2	,
	S_CTC_CLUSTER25_RECIPE2	,

	S_CTC_CLUSTER01_RECIPE3	,
	S_CTC_CLUSTER02_RECIPE3	,
	S_CTC_CLUSTER03_RECIPE3	,
	S_CTC_CLUSTER04_RECIPE3	,
	S_CTC_CLUSTER05_RECIPE3	,
	S_CTC_CLUSTER06_RECIPE3	,
	S_CTC_CLUSTER07_RECIPE3	,
	S_CTC_CLUSTER08_RECIPE3	,
	S_CTC_CLUSTER09_RECIPE3	,
	S_CTC_CLUSTER10_RECIPE3	,
	S_CTC_CLUSTER11_RECIPE3	,
	S_CTC_CLUSTER12_RECIPE3	,
	S_CTC_CLUSTER13_RECIPE3	,
	S_CTC_CLUSTER14_RECIPE3	,
	S_CTC_CLUSTER15_RECIPE3	,
	S_CTC_CLUSTER16_RECIPE3	,
	S_CTC_CLUSTER17_RECIPE3	,
	S_CTC_CLUSTER18_RECIPE3	,
	S_CTC_CLUSTER19_RECIPE3	,
	S_CTC_CLUSTER20_RECIPE3	,
	S_CTC_CLUSTER21_RECIPE3	,
	S_CTC_CLUSTER22_RECIPE3	,
	S_CTC_CLUSTER23_RECIPE3	,
	S_CTC_CLUSTER24_RECIPE3	,
	S_CTC_CLUSTER25_RECIPE3	,

	S_CTC_CLUSTER01_RECIPE4	,
	S_CTC_CLUSTER02_RECIPE4	,
	S_CTC_CLUSTER03_RECIPE4	,
	S_CTC_CLUSTER04_RECIPE4	,	
	S_CTC_CLUSTER05_RECIPE4	,
	S_CTC_CLUSTER06_RECIPE4	,
	S_CTC_CLUSTER07_RECIPE4	,
	S_CTC_CLUSTER08_RECIPE4	,
	S_CTC_CLUSTER09_RECIPE4	,
	S_CTC_CLUSTER10_RECIPE4	,
	S_CTC_CLUSTER11_RECIPE4	,
	S_CTC_CLUSTER12_RECIPE4	,
	S_CTC_CLUSTER13_RECIPE4	,
	S_CTC_CLUSTER14_RECIPE4	,
	S_CTC_CLUSTER15_RECIPE4	,
	S_CTC_CLUSTER16_RECIPE4	,
	S_CTC_CLUSTER17_RECIPE4	,
	S_CTC_CLUSTER18_RECIPE4	,
	S_CTC_CLUSTER19_RECIPE4	,
	S_CTC_CLUSTER20_RECIPE4	,
	S_CTC_CLUSTER21_RECIPE4	,
	S_CTC_CLUSTER22_RECIPE4	,
	S_CTC_CLUSTER23_RECIPE4	,
	S_CTC_CLUSTER24_RECIPE4	,
	S_CTC_CLUSTER25_RECIPE4	,

	D_JobStartMode			,

	D_CTC_select1_slot1		,
	D_CTC_select1_slot2		,
	D_CTC_select1_slot3		,
	D_CTC_select1_slot4		,
	D_CTC_select1_slot5		,
	D_CTC_select1_slot6		,
	D_CTC_select1_slot7		,
	D_CTC_select1_slot8		,
	D_CTC_select1_slot9		,
	D_CTC_select1_slot10	,
	D_CTC_select1_slot11	,
	D_CTC_select1_slot12	,
	D_CTC_select1_slot13	,
	D_CTC_select1_slot14	,
	D_CTC_select1_slot15	,
	D_CTC_select1_slot16	,
	D_CTC_select1_slot17	,
	D_CTC_select1_slot18	,
	D_CTC_select1_slot19	,
	D_CTC_select1_slot20	,
	D_CTC_select1_slot21	,
	D_CTC_select1_slot22	,
	D_CTC_select1_slot23	,
	D_CTC_select1_slot24	,
	D_CTC_select1_slot25	,

	D_CTC_select2_slot1		,
	D_CTC_select2_slot2		,
	D_CTC_select2_slot3		,
	D_CTC_select2_slot4		,
	D_CTC_select2_slot5		,
	D_CTC_select2_slot6		,
	D_CTC_select2_slot7		,
	D_CTC_select2_slot8		,
	D_CTC_select2_slot9		,
	D_CTC_select2_slot10	,
	D_CTC_select2_slot11	,
	D_CTC_select2_slot12	,
	D_CTC_select2_slot13	,
	D_CTC_select2_slot14	,
	D_CTC_select2_slot15	,
	D_CTC_select2_slot16	,
	D_CTC_select2_slot17	,
	D_CTC_select2_slot18	,
	D_CTC_select2_slot19	,
	D_CTC_select2_slot20	,
	D_CTC_select2_slot21	,
	D_CTC_select2_slot22	,
	D_CTC_select2_slot23	,
	D_CTC_select2_slot24	,
	D_CTC_select2_slot25	,

	D_CTC_select3_slot1		,
	D_CTC_select3_slot2		,
	D_CTC_select3_slot3		,
	D_CTC_select3_slot4		,
	D_CTC_select3_slot5		,
	D_CTC_select3_slot6		,
	D_CTC_select3_slot7		,
	D_CTC_select3_slot8		,
	D_CTC_select3_slot9		,
	D_CTC_select3_slot10	,
	D_CTC_select3_slot11	,
	D_CTC_select3_slot12	,
	D_CTC_select3_slot13	,
	D_CTC_select3_slot14	,
	D_CTC_select3_slot15	,
	D_CTC_select3_slot16	,
	D_CTC_select3_slot17	,
	D_CTC_select3_slot18	,
	D_CTC_select3_slot19	,
	D_CTC_select3_slot20	,
	D_CTC_select3_slot21	,
	D_CTC_select3_slot22	,
	D_CTC_select3_slot23	,
	D_CTC_select3_slot24	,
	D_CTC_select3_slot25	,

	D_CTC_select4_slot1		,
	D_CTC_select4_slot2		,
	D_CTC_select4_slot3		,
	D_CTC_select4_slot4		,
	D_CTC_select4_slot5		,
	D_CTC_select4_slot6		,
	D_CTC_select4_slot7		,
	D_CTC_select4_slot8		,
	D_CTC_select4_slot9		,
	D_CTC_select4_slot10	,
	D_CTC_select4_slot11	,
	D_CTC_select4_slot12	,
	D_CTC_select4_slot13	,
	D_CTC_select4_slot14	,
	D_CTC_select4_slot15	,
	D_CTC_select4_slot16	,
	D_CTC_select4_slot17	,
	D_CTC_select4_slot18	,
	D_CTC_select4_slot19	,
	D_CTC_select4_slot20	,
	D_CTC_select4_slot21	,
	D_CTC_select4_slot22	,
	D_CTC_select4_slot23	,
	D_CTC_select4_slot24	,
	D_CTC_select4_slot25	,

	D_CTC_PM1M_CONTROL		,

	D_CTC_TA_Wafer_Status	,
	D_CTC_PM5_Wafer_Status	,
	D_CTC_PM1_Wafer_Status	,
	D_CTC_PM1_Wafer_Status2	,
	D_CTC_PM1_Wafer_Status3	,
	D_CTC_PM1_Wafer_Status4	,
	D_CTC_PM1_Wafer_Status5	,
	D_CTC_PM1_Wafer_Status6	,

	D_CTC_TA_Wafer_Source	,
	D_CTC_PM5_Wafer_Source	,
	D_CTC_PM1_Wafer_Source	,
	D_CTC_PM1_Wafer_Source2	,
	D_CTC_PM1_Wafer_Source3	,
	D_CTC_PM1_Wafer_Source4	,
	D_CTC_PM1_Wafer_Source5	,
	D_CTC_PM1_Wafer_Source6	,

	D_O2Test_Run_Sts		,
	D_O2Test_Run_Sts2		,
	D_O2Test_Run_Sts3		,
	D_O2_Sample_Vv			,
	D_O2_Sample_Vv_Sts		,
	D_O2Level_Monitoring	,
	D_O2LevelCheck_Save		,

} IOPointIndex;

//////////////////////////////////////////////////////////////////////////
//
//	ENUMERATION
//
//////////////////////////////////////////////////////////////////////////
typedef enum { LOADPORT01 , LOADPORT02 , LOADPORT03 , LOADPORT04 } LOADPORTNO;
typedef enum { CLEAR_OPTION , SET_S_OPTION , SET_A_OPTION , SET_D_OPTION } RECIPE_SET_OPTION;
typedef enum { RELEASE=1	, MAINTENANCE=2 } MODULE_STATUS;
enum { Idle , Running , Pausing , Paused , Aborting , Disable , Waiting , WaitHandOff };
enum { PORT1 , PORT2 , PORT3 , PORT4 };
enum { EQ_OFFL , ATTP_ONL , HOST_OFFL , LOCAL , REMOTE };
enum { MANUAL, AUTO };
enum JOBSTARTMODE{ REVERSE, SEMI };
enum { CLOSE, OPEN };
typedef enum { MNTR_PAUSE, MNTR_START, MNTR_RESUME } MONITOR_SET;
enum { UNUSE, USE };

//////////////////////////////////////////////////////////////////////////
//
//	DEFINITION
//
//////////////////////////////////////////////////////////////////////////
#define     MAX_Wafer_IO_COUNT				8
#define		MAX_SLOT						25
#define		MAX_PARAMETER_DATA				16
#define		MAX_PARAMETER_LENGTH			32
#define		MAX_STRING_SIZE					64
#define		DEFAULT_STRING					128
#define		MAXIMUM_STRING					256
#define		MID_STR_LEN						1024
#define		MAX_STR_LEN						2048

#define		DRIVER_LOG_DIRECTORY			".\\History\\Schedule"

//////////////////////////////////////////////////////////////////////////
//
//	GLOBAL VARIABLE
//
//////////////////////////////////////////////////////////////////////////
int g_nJobStartMode;
int g_nBublrUsage;

//////////////////////////////////////////////////////////////////////////
//
//	FUNCTION DECLARATION
//
//////////////////////////////////////////////////////////////////////////
BOOL Change_Cluster_Recipe( int _nLotid , int _nOption );
BOOL Get_Whether_SmartEES_is_Connected();
BOOL Check_Whether_Slot_is_Selected( int _nSelect_Slot , BOOL *_pbSel_Slot );
Module_Status Confirm_Wafer_In_PM( int _nData ); 
BOOL Read_Bubbler_OnOff_From_Recipe(char* _pcProcessRecipe);
BOOL Kor_CLUSTER_Open(char* _cCluster_Recipe, char* _cProcess_Recipe, char *_pcErrorMessage, HWND _hDlg);
BOOL Check_Recipe_State(int _nLoadPort);

#endif


