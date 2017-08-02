#include "iodefine.h"

#include <Common/VC/CommonLogMethods.c>


char * GetLogSource()
{
	return "O2_TEST";
}
char * GetLogDirectory()
{
	return DRIVER_LOG_DIRECTORY;
}


//////////////////////////////////////////////////////////////////////////
//
//	LogMsgWrite
//
//////////////////////////////////////////////////////////////////////////
// void LogMsgWrite( const char* _pcLogName, const char* _pcLogMsg, ... )
// {
	// char		cTemp[512] = {0,};
	// char		cFile_Name[256] = {0,};
	// char		cPath[MAX_STR_LEN] = {0,};
	
	// va_list		ap;
	// FILE*		pLog_file;
	// SYSTEMTIME	Curtime;
	
	// ZeroMemory( cTemp , sizeof(cTemp) );
	
	// va_start( ap, _pcLogMsg );
	// vsprintf( cTemp, _pcLogMsg, ap );
	// va_end( ap );
	
	// GetLocalTime( &Curtime );
	// sprintf( cPath , "%s\\%s%04d%02d%02d%02d.log" , DRIVER_LOG_DIRECTORY , _pcLogName, Curtime.wYear, Curtime.wMonth, Curtime.wDay, Curtime.wHour );
	// pLog_file = fopen( cPath , "a" );
	
	// if( pLog_file )
	// {
		// fprintf(pLog_file, "%02d:%02d:%02d.%03d\t%s\n", Curtime.wHour, Curtime.wMinute, Curtime.wSecond, Curtime.wMilliseconds, cTemp);
		// fclose(pLog_file);
	// }
// }

//////////////////////////////////////////////////////////////////////////
//
//	Check_Whether_Slot_is_Selected
//
//////////////////////////////////////////////////////////////////////////
BOOL Check_Whether_Slot_is_Selected( int _nSelect_Slot , BOOL *_pbSel_Slot )
{
	int		nCommStatus;
	int		nSlot;
	BOOL	bSelection=FALSE;

	for( nSlot = 0 ; nSlot < MAX_SLOT ; nSlot++ )
	{
		if ( READ_DIGITAL( _nSelect_Slot + nSlot , &nCommStatus ) == 1/*SELECTED*/ )
		{
			_pbSel_Slot[nSlot] = TRUE;
			bSelection = TRUE;
		}
		else	_pbSel_Slot[nSlot] = FALSE;
	}

	return bSelection;
}

//////////////////////////////////////////////////////////////////////////
//
//	Change_Cluster_Recipe
//
//////////////////////////////////////////////////////////////////////////
BOOL Change_Cluster_Recipe( int _nLotid , int _nOption )
{
	char cReadString[MAXIMUM_STRING] = {0,};
	int nIOstart , nCommStatus;
	int nSelect_Slot = 0;
	int nSelect_Cluster = 0;
	int nCluster_Recipe = 0;
	int nSlot = 0;
	BOOL bSel_Slot[MAX_SLOT]={0,};
	
	ZeroMemory( cReadString , sizeof(char) * MAXIMUM_STRING );
	
	switch( _nLotid )
	{
		case LOADPORT01  : 
			nIOstart = S_CTC_CLUSTER01_RECIPE;  
			nSelect_Slot = D_CTC_select1_slot1;
			nSelect_Cluster = S_CTC_SELECT_CLUSTER;
			nCluster_Recipe = S_CTC_CLUSTER01_RECIPE;
			break;
		case LOADPORT02  : 
			nIOstart = S_CTC_CLUSTER01_RECIPE2; 
			nSelect_Slot = D_CTC_select2_slot1;
			nSelect_Cluster = S_CTC_SELECT_CLUSTER2;
			nCluster_Recipe = S_CTC_CLUSTER01_RECIPE2;
			break;
		case LOADPORT03  : 
			nIOstart = S_CTC_CLUSTER01_RECIPE3; 
			nSelect_Slot = D_CTC_select3_slot1;
			nSelect_Cluster = S_CTC_SELECT_CLUSTER3;
			nCluster_Recipe = S_CTC_CLUSTER01_RECIPE3;
			break;
		case LOADPORT04  : 
			nIOstart = S_CTC_CLUSTER01_RECIPE4;
			nSelect_Slot = D_CTC_select4_slot1;
			nSelect_Cluster = S_CTC_SELECT_CLUSTER4;
			nCluster_Recipe = S_CTC_CLUSTER01_RECIPE4;
			break;
		default : return FALSE;
	}
	
	switch( _nOption )
	{
		case SET_S_OPTION : // Set Select Recipe
			if ( !Check_Whether_Slot_is_Selected( nSelect_Slot , bSel_Slot ) )	break;

			for( nSlot = 0 ; nSlot < MAX_SLOT ; nSlot++ )
			{
				if ( bSel_Slot[nSlot] )
				{
					READ_STRING( nSelect_Cluster , cReadString , &nCommStatus );
					if ( strlen( cReadString ) > 0 )
					{
						WRITE_STRING( nCluster_Recipe + nSlot , cReadString , &nCommStatus );
					}
					WRITE_DIGITAL( nSelect_Slot + nSlot , 0 ,&nCommStatus ) ;
				}
			}
			break;
			
		case SET_A_OPTION : // ALL selected recipe
			for ( nSlot = 0 ; nSlot < MAX_SLOT ; nSlot++ )
			{
				READ_STRING( nSelect_Cluster , cReadString , &nCommStatus );
				if ( strlen( cReadString ) > 0 )	WRITE_STRING( nIOstart + nSlot , cReadString , &nCommStatus );
			}
			break;
			
		case SET_D_OPTION : // Set Select Recipe Delete
			for( nSlot = 0 ; nSlot < MAX_SLOT ; nSlot++ )
			{
				if ( READ_DIGITAL( nSelect_Slot + nSlot , &nCommStatus ) == 1/*SELECTED*/ )
				{
					strcpy( cReadString , "" );
					WRITE_STRING( nCluster_Recipe + nSlot , cReadString , &nCommStatus );
					WRITE_DIGITAL( nSelect_Slot + nSlot , 0 ,&nCommStatus ) ;
				}
			}
			break;
			
		case CLEAR_OPTION :
			strcpy( cReadString , "" );
			for ( nSlot = 0 ; nSlot < MAX_SLOT ; nSlot++ )	WRITE_STRING( nIOstart + nSlot , cReadString , &nCommStatus );
			break;
		default :	return FALSE;
	}
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	Confirm_Wafer_In_PM
//
//////////////////////////////////////////////////////////////////////////

Module_Status Confirm_Wafer_In_PM( int _nPort )
{
	int   nIndex, nWafer_Count = 0, nWafer_Status = 0, nLP_Number = 0, nCommStatus = 0;

	for( nIndex = 0 ; nIndex < MAX_Wafer_IO_COUNT ; nIndex++ )
	{
		nWafer_Status = READ_DIGITAL( D_CTC_TA_Wafer_Status + nIndex, &nCommStatus );
		
		if( nWafer_Status > 0) nWafer_Count++;
		
		if( nWafer_Count > 0 ) 
		{
			nLP_Number = ( READ_DIGITAL( D_CTC_TA_Wafer_Source + nIndex, &nCommStatus ) );	
			
			if( _nPort == nLP_Number ) // Compare Port Number & Wafer Source
			{
				return SYS_ABORTED;
			}
			else
			{
				if( nLP_Number == 0 ) // LP1 
				{
					if( READ_DIGITAL( D_CTC_MAIN_CONTROL, &nCommStatus ) == Running )
						return SYS_SUCCESS;	
					else if( READ_DIGITAL( D_CTC_MAIN_CONTROL, &nCommStatus ) == Idle )
						return SYS_ABORTED;
				}
				if( nLP_Number == 1 ) // LP2
				{
					if( READ_DIGITAL( D_CTC_MAIN_CONTROL2, &nCommStatus ) == Running )
						return SYS_SUCCESS;
					else if( READ_DIGITAL( D_CTC_MAIN_CONTROL2, &nCommStatus ) == Idle )
						return SYS_ABORTED;
				}
			}
		}
	}
	return SYS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////
//
//	Read_Bubbler_OnOff_From_Recipe
//
//////////////////////////////////////////////////////////////////////////
BOOL Read_Bubbler_OnOff_From_Recipe(char* _pcProcessRecipe)
{
	HFILE	hFile;
	BOOL	bStepEndFind;
	int		nKill;
	char	cReturn;
	int		nReturn;
	float	fReturn;
	double	dReturn;
	char	cReturn2[256] = { 0, }, cName_return[256] = { 0, };
	char	cType_return;
	char	cProcessRecipePath[256] = { 0, };

	if (strlen(_pcProcessRecipe) <= 0) return TRUE;

	sprintf(cProcessRecipePath, "RECIPE/./Process/PM1/%s", _pcProcessRecipe);
	hFile = _lopen(cProcessRecipePath, OF_READ);

	if (hFile == -1) return FALSE;

	bStepEndFind = FALSE;
	nKill = 0;

	while (!bStepEndFind)
	{
		if (!read_return_form2(hFile, cName_return, &cType_return, &cReturn, &nReturn, &fReturn, &dReturn, cReturn2)) { _lclose(hFile); return FALSE; }

		switch (cType_return)
		{
		case NAME_FORMAT:
			if (strcmp(cName_return, "__&&STEP0_END&&__") == 0)	bStepEndFind = TRUE;
			else												nKill++;
			break;
		case DOUBLE_FORMAT:
			nKill++;
			break;
		case STRING_FORMAT:
			nKill++;
			break;
		case INT_FORMAT:
			if (strcmp(cName_return, "BUBLR_USAGE") == 0) g_nBublrUsage = nReturn;
			else nKill++;
			break;
		default:
			nKill++;
			break;
		}
		if (nKill >= 100)	{ _lclose(hFile);	return TRUE; }
	}

	_lclose(hFile);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	Kor_CLUSTER_Open
//
//////////////////////////////////////////////////////////////////////////
BOOL Kor_CLUSTER_Open(char* _cCluster_Recipe, char* _cProcess_Recipe, char *_pcErrorMessage, HWND _hDlg)
{
	HFILE hFile;
	BOOL StepEndFind, bClusterEmpty = TRUE;
	int  i, j, kill;

	char  cc_return;
	int   ii_return;
	float ff_return;
	char  str_return[1025];
	char  name_return[1025];
	char  type_return;
	char  Buffer[1025];
	char cCluster_Rcp_Path[MAXIMUM_STRING] = { 0, };

	sprintf(cCluster_Rcp_Path, ".\\Recipe\\Cluster\\%s", _cCluster_Recipe);
	if (_cCluster_Recipe == NULL)
	{
		sprintf(_pcErrorMessage, "[ABORTED] Recipe file name is null!!!");
		return FALSE;
	}

	hFile = _lopen(cCluster_Rcp_Path, OF_READ);
	if (hFile == -1)
	{
		sprintf(_pcErrorMessage, "[ABORTED] Recipe file memory is insufficient!!!");
		return FALSE;
	}

	StepEndFind = FALSE;
	kill = 0;
	while (!StepEndFind)
	{
		if (!read_return_form(hFile, name_return, &type_return, &cc_return, &ii_return, &ff_return, str_return))
		{
			_lclose(hFile);
			sprintf(_pcErrorMessage, "[ABORTED] Recipe editor function cannot read a cluster recipe!!!");
			return FALSE;
		}
		switch (type_return)
		{
		case NAME_FORMAT:
			if (STRCMP_L(name_return, "__&&CLUSTER_RECIPE_END&&__")) StepEndFind = TRUE;
			else kill++;
			break;
		case STRING_FORMAT:
			Buffer[0] = name_return[7];
			Buffer[1] = name_return[8];
			Buffer[2] = 0;
			i = atoi(Buffer) - 1;
			Buffer[0] = name_return[11];
			if (name_return[12] == '_') {
				Buffer[1] = 0;
			}
			else {
				Buffer[1] = name_return[12];
				Buffer[2] = 0;
			}

			j = atoi(Buffer) - 1;
			if ((i < 0) || (j < 0) || (i >= 3/*MAX_CLUSTER_DEPTH*/) || (j >= 3/*MAX_PM_CHAMBER_DEPTH*/))
			{
				kill++;
			}
			else {
				name_return[7] = ' ';
				name_return[8] = ' ';
				name_return[11] = ' ';
				if (name_return[12] == '_')
				{
					if (STRCMP_L(name_return, "MODULE_  _P _IN_RECIPE"))
					{
						if (strlen(str_return) > 0)
						{
							bClusterEmpty = FALSE;
							sprintf(_pcErrorMessage, "");
							strcpy(_cProcess_Recipe, str_return);
						}
					}
					else	kill++;
				}
				else	kill++;
			}
			break;

		default:	kill++;
			break;
		}
		//		if ( kill >= 100 )	{ // 2007.06.08
		if (kill >= 10000)	{ // 2007.06.08
			_lclose(hFile);
			sprintf(_pcErrorMessage, "[ABORTED] Recipe editor function cannot read a cluster recipe!!!");
			return FALSE;
		}
	}

	if (bClusterEmpty && (strlen(_pcErrorMessage) <= 0))
	{
		sprintf(_pcErrorMessage, "[ABORTED] Cluster recipe does not include a process recipe!!!");
		return FALSE;
	}

	_lclose(hFile);
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
//
//	Check_Recipe_State
//
//////////////////////////////////////////////////////////////////////////
BOOL Check_Recipe_State(int _nLoadPort)
{
	char cPM_ClusterRecipe[512] = { 0, }, cPM_ProcessRecipe[512] = { 0, }, cErrorMessage[DEFAULT_STRING] = { 0, };
	int	nCommStatus;
	HWND hDlg = NULL;

	hDlg = GetForegroundWindow();
	READ_STRING(S_CTC_SELECT_CLUSTER + _nLoadPort, cPM_ClusterRecipe, &nCommStatus);

	if (strlen(cPM_ClusterRecipe) <= 0)
	{
		sprintf(cErrorMessage, "[ABORTED] Not selected PM process recipe!!!");
		MessageBox(hDlg, cErrorMessage, "ERROR", 0);
		return FALSE;
	}
	else
	{
		if (Kor_CLUSTER_Open(cPM_ClusterRecipe, cPM_ProcessRecipe, cErrorMessage, hDlg))
		{
			if (Read_Bubbler_OnOff_From_Recipe(cPM_ProcessRecipe))
			{
				if (g_nBublrUsage)
				{
					sprintf(cErrorMessage, "[ABORTED] Selected Formic recipe!!!");
					MessageBox(hDlg, cErrorMessage, "ERROR", 0);
					return FALSE;
				}
			}
			else
			{
				sprintf(cErrorMessage, "[ABORTED] Don't read PM process recipe!!!");
				MessageBox(hDlg, cErrorMessage, "ERROR", 0);
				return FALSE;
			}
		}
		else
		{
			MessageBox(hDlg, cErrorMessage, "ERROR", 0);
			return FALSE;
		}
	}

	return TRUE;
}