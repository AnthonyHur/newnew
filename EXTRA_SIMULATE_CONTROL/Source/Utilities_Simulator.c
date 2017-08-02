#include "iodefine.h"

void Utilities_Simulator()
{
	int nCommStatus;

	if ( READ_DIGITAL( D_FADetectorUsage , &nCommStatus ) == 1 )
	{
		WRITE_DIGITAL( D_FA_Gas_Detect_Fail , 1 , &nCommStatus );
		WRITE_DIGITAL( D_FA_Gas_Leak_Warning , 1 , &nCommStatus );
		WRITE_DIGITAL( D_FA_Gas_Leak_Alarm , 1 , &nCommStatus );
	}
	WRITE_DIGITAL( D_Bubbler_Door , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Gas_Leak_Alarm , 1 , &nCommStatus );
	
	WRITE_DIGITAL( D_EFEM_SIDEDOOR , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Chmbr_Lock_Vv_Sts , 1 , &nCommStatus );
	_sleep(1);

	WRITE_DIGITAL( D_Bubbler_ManualVvSts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Bubbler_LowLmt_Lvl , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Bubbler_Low_Lvl	, 1 , &nCommStatus );
	WRITE_DIGITAL( D_Bubbler_High_Lvl	, 1 , &nCommStatus );
	WRITE_DIGITAL( D_Bubbler_HighLmt_Lvl , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Bubbler_Leak_Sts , 1 , &nCommStatus );
	if ( READ_DIGITAL( D_OpticalLeakUsage , &nCommStatus ) == 1 )	WRITE_DIGITAL( D_Bubbler_LeakOptcSts , 1 , &nCommStatus );

	if ( READ_DIGITAL( D_Bubbler2_Usage , &nCommStatus ) == 1 )
	{
		WRITE_DIGITAL( D_Bubbler2_ManualVvSts , 1 , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler2_LowLmt_Lvl , 1 , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler2_Low_Lvl	, 1 , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler2_High_Lvl	, 1 , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler2_HighLmt_Lvl , 1 , &nCommStatus );
		WRITE_DIGITAL( D_Bubbler2_Leak_Sts , 1 , &nCommStatus );
		if ( READ_DIGITAL( D_OpticalLeakUsage , &nCommStatus ) == 1 )	WRITE_DIGITAL( D_Bubbler2_LeakOptcSts , 1 , &nCommStatus );
	}
	WRITE_DIGITAL( D_Chmbr_Lock_Vv_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_PM_Cover_Sts , 1 , &nCommStatus );
	_sleep(1);
	WRITE_DIGITAL( D_Fac_PCW_Flow_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Fac_VAC_Press_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Fac_CDA_Press_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Gas_Box_Door_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Process_Exhst_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Gas_Box_Exhst_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Cabinet_Exhst_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Bubbler_Exhst_Sts , 1 , &nCommStatus );
	WriteDigitalPointByName("Pump_Exhst_Sts", NORMAL_STS);

	WRITE_DIGITAL( D_Water_Leak , 1 , &nCommStatus );
//	WRITE_DIGITAL( D_Bulkfill_SupplyRun , 1 , &nCommStatus );
//	WRITE_DIGITAL( D_Bulkfill_SupplyReady , 1 , &nCommStatus );
	_sleep(1);
	WRITE_DIGITAL( D_Chuck1_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Chuck2_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Chuck3_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Chuck4_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Insul1_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Insul2_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Insul3_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Insul4_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Elbow1_LT_LimitTemp , 0 , &nCommStatus );
	_sleep(1);
	WRITE_DIGITAL( D_Elbow2_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Elbow3_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Elbow4_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Bublr1_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Bublr2_LT_LimitTemp , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Chuck1_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Chuck2_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Chuck3_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Chuck4_LT_TC_Broken , 0 , &nCommStatus );
	_sleep(1);
	WRITE_DIGITAL( D_Insul1_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Insul2_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Insul3_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Insul4_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Elbow1_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Elbow2_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Elbow3_LT_TC_Broken , 0 , &nCommStatus );
	_sleep(1);
	WRITE_DIGITAL( D_Elbow4_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Bublr1_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Bublr2_LT_TC_Broken , 0 , &nCommStatus );
	WRITE_DIGITAL( D_WS_Leak_Sensor , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Hi_DI_Res_Meter , 1 , &nCommStatus );
	WRITE_DIGITAL( D_WS1_Drain_Lvl_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_WS2_Drain_Lvl_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Scrubber_Warning , 0 , &nCommStatus );
	WRITE_DIGITAL( D_Scrubber_Trouble , 0 , &nCommStatus );
	_sleep(1);
	WRITE_DIGITAL( D_Scrubber_Treatmentable , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Ionizer_Status , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Ionizer2_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_Smoke_Detector_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_PD_Box_DC_Fan_Sts , 1 , &nCommStatus );
	WRITE_DIGITAL( D_PM_ELT_Box_DC_Fan_Sts , 1 , &nCommStatus );
	
	WRITE_ANALOG( A_N2_Press_Transducer , 36.0 , &nCommStatus );
	WRITE_ANALOG( A_N2_Purge_Press_Transducer , 75.0 , &nCommStatus );
	WRITE_ANALOG( A_ContBubbler_Level , 5.0 , &nCommStatus );
	WRITE_ANALOG( A_ContBubbler2_Level , 5.0 , &nCommStatus );
	WRITE_ANALOG( A_O2_Press_Transducer , 12.0 , &nCommStatus );
	WRITE_ANALOG( A_CDA_Pressure_Ionizer1 , 0.2 , &nCommStatus );
	WRITE_ANALOG( A_CDA_Pressure_Ionizer2 , 0.2 , &nCommStatus );

	WRITE_ANALOG( A_O2LevelRead , 1.1 , &nCommStatus );
_sleep(1);
	WRITE_ANALOG( A_Chuck1_Temp_Mnt , 23.1 , &nCommStatus );
	WRITE_ANALOG( A_Chuck2_Temp_Mnt , 22.9 , &nCommStatus );
	WRITE_ANALOG( A_Chuck3_Temp_Mnt , 20.2 , &nCommStatus );
	WRITE_ANALOG( A_Chuck4_Temp_Mnt , 23.1 , &nCommStatus );
	WRITE_ANALOG( A_Chuck5_Temp_Mnt , 17.3 , &nCommStatus );
_sleep(1);
	WRITE_ANALOG( A_Insul1_Temp_Mnt , 23.1 , &nCommStatus );
	WRITE_ANALOG( A_Insul2_Temp_Mnt , 25.2 , &nCommStatus );
	WRITE_ANALOG( A_Insul3_Temp_Mnt , 22.3 , &nCommStatus );
	WRITE_ANALOG( A_Insul4_Temp_Mnt , 23.1 , &nCommStatus );
_sleep(1);
	WRITE_ANALOG( A_Elbow1_Temp_Mnt , 19.1 , &nCommStatus );
	WRITE_ANALOG( A_Elbow2_Temp_Mnt , 20.1 , &nCommStatus );
	WRITE_ANALOG( A_Elbow3_Temp_Mnt , 23.1 , &nCommStatus );
	WRITE_ANALOG( A_Elbow4_Temp_Mnt , 22.3 , &nCommStatus );

	WRITE_DIGITAL( D_Light_Curtain_Sts , 1 , &nCommStatus );

	WRITE_ANALOG(A_Fac_PCW_Inlet_Temp, 20, &nCommStatus);
	WRITE_ANALOG(A_Fac_PCW_Outlet_Temp, 25, &nCommStatus);

//	WRITE_DIGITAL( D_FA_Valve_Spill , 1 , &nCommStatus );


	WRITE_DIGITAL(D_Bulkfill_Error, 1, &nCommStatus);
	return;
}
