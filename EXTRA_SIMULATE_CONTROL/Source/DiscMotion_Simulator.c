#include "iodefine.h"


void Disc_Motion_Simulator( void* _pArg )
{
	int		nCommStatus, nServoSts, nMotionMode, nOldMotionMode=0;
	int		nDiscCtrl;
	double	dDiscPosition, dOldDiscPosition;
	double	dDiscDistance=0.0;

	WRITE_DIGITAL( D_Disc_Servo , TURN_ON , &nCommStatus );
	WRITE_DIGITAL( D_Disc_HomSnsActv, 1/*ON*/, &nCommStatus);
	WRITE_DIGITAL( D_Disc_AtStation , 1/*ON*/ , &nCommStatus );
	WRITE_DIGITAL( D_Disc_RunSts , 0/*IDLE*/ , &nCommStatus );
	WRITE_DIGITAL( D_Disc_ServoSts , 0/*ON*/ , &nCommStatus );
	WRITE_DIGITAL( D_Disc_Control , DISC_STOP_CTRL , &nCommStatus );
	WRITE_DIGITAL( D_Disc_Motor_Amp , 1 , &nCommStatus );

	while ( TRUE )
	{
		nServoSts = READ_DIGITAL( D_Disc_Servo , &nCommStatus );
		if ( nServoSts >= 0 )
		{
			// note that Disc_Servo is OffOn while Disc_ServoSts is OnOff
			if ( nServoSts == 0 )	WRITE_DIGITAL( D_Disc_ServoSts , 1 , &nCommStatus );
			else					WRITE_DIGITAL( D_Disc_ServoSts , 0 , &nCommStatus );
		}

		nMotionMode = READ_DIGITAL( D_Disc_MotionMode , &nCommStatus );
		if ( nOldMotionMode != nMotionMode )
		{
			_sleep(300);
			nOldMotionMode = nMotionMode;
			WRITE_DIGITAL( D_Disc_PosModeSts , nMotionMode , &nCommStatus );
		}

		if ( READ_DIGITAL( D_Disc_ServoSts , &nCommStatus ) == 0/*ON*/ )
		{
			nDiscCtrl = READ_DIGITAL( D_Disc_Control , &nCommStatus );
			if ( nDiscCtrl == DISC_HOME_CTRL )
			{
				WRITE_DIGITAL( D_Disc_RunSts , 1/*RUN*/ , &nCommStatus );
				_sleep(3000);
				WRITE_ANALOG( A_Disc_Pos_Read , 300.0 , &nCommStatus );
				WRITE_ANALOG( A_Disc_Pos_Degree , 0.33 , &nCommStatus );
				_sleep(500);
				WRITE_ANALOG( A_Disc_Pos_Read , 130.0 , &nCommStatus );
				WRITE_ANALOG( A_Disc_Pos_Degree , 0.14 , &nCommStatus );
				_sleep(500);
				WRITE_ANALOG( A_Disc_Pos_Read , -100.0 , &nCommStatus );
				WRITE_ANALOG( A_Disc_Pos_Degree , -0.11 , &nCommStatus );
				_sleep(500);
				WRITE_ANALOG( A_Disc_Pos_Read , 10.0 , &nCommStatus );
				WRITE_ANALOG( A_Disc_Pos_Degree , 0.1 , &nCommStatus );
				_sleep(500);
				WRITE_ANALOG( A_Disc_Pos_Read , 0.0 , &nCommStatus );
				WRITE_ANALOG( A_Disc_Pos_Degree , 0.0 , &nCommStatus );

				WRITE_DIGITAL( D_Disc_HomSnsActv , 1/*ON*/ , &nCommStatus );
				WRITE_DIGITAL( D_Disc_AtStation , 1/*ON*/ , &nCommStatus );
				WRITE_DIGITAL( D_Disc_HomeSts , 1/*ON*/ , &nCommStatus );
				WRITE_DIGITAL( D_Disc_RunSts , 0/*IDLE*/ , &nCommStatus );
				dDiscDistance = 0.0;
				WRITE_DIGITAL( D_Disc_Control , DISC_STOP_CTRL , &nCommStatus );
			}
			else if ( nDiscCtrl == DISC_MOVE_CTRL )
			{
				WRITE_DIGITAL( D_Disc_RunSts , 1/*RUN*/ , &nCommStatus );
				WRITE_DIGITAL( D_Disc_HomSnsActv , 0/*OFF*/ , &nCommStatus );
				WRITE_DIGITAL( D_Disc_HomeSts , 1/*ON*/ , &nCommStatus );
				WRITE_DIGITAL( D_Disc_AtStation , 0/*OFF*/ , &nCommStatus );
				if ( READ_DIGITAL( D_Disc_MotionMode , &nCommStatus ) == 1/*Absolute*/ )
				{
					dDiscDistance = READ_ANALOG( A_Disc_Distance , &nCommStatus );
					if ( dDiscDistance > 0 )
					{
						dDiscPosition = READ_ANALOG( A_Disc_Pos_Read , &nCommStatus );
						WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition+1 , &nCommStatus );
						WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscPosition+1)/900 , &nCommStatus );
						_sleep(1000);
						if ( dDiscDistance > 1 )
						{
							WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition+100 , &nCommStatus );
							WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscPosition+100)/900 , &nCommStatus );
							_sleep(1000);
							WRITE_ANALOG( A_Disc_Pos_Read , dDiscDistance-1000 , &nCommStatus );
							WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscDistance-1000)/900 , &nCommStatus );
							_sleep(500);
							WRITE_ANALOG( A_Disc_Pos_Read , dDiscDistance-500 , &nCommStatus );
							WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscDistance-500)/900 , &nCommStatus );
							_sleep(500);
							WRITE_ANALOG( A_Disc_Pos_Read , dDiscDistance-100 , &nCommStatus );
							WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscDistance-100)/900 , &nCommStatus );
							_sleep(500);
						}
					}
					else
					{
						dDiscPosition = READ_ANALOG( A_Disc_Pos_Read , &nCommStatus );
						WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition-1 , &nCommStatus );
						WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscPosition-1)/900 , &nCommStatus );
						_sleep(1000);
						if ( dDiscDistance < -1 )
						{
							WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition-100 , &nCommStatus );
							WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscPosition-100)/900 , &nCommStatus );
							_sleep(1000);
							WRITE_ANALOG( A_Disc_Pos_Read , dDiscDistance+1000 , &nCommStatus );
							WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscDistance+1000)/900 , &nCommStatus );
							_sleep(500);
							WRITE_ANALOG( A_Disc_Pos_Read , dDiscDistance+500 , &nCommStatus );
							WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscDistance+500)/900 , &nCommStatus );
							_sleep(500);
							WRITE_ANALOG( A_Disc_Pos_Read , dDiscDistance+100 , &nCommStatus );
							WRITE_ANALOG( A_Disc_Pos_Degree , (dDiscDistance+100)/900 , &nCommStatus );
							_sleep(500);
						}
					}
					if ((dDiscDistance == -324000) || (dDiscDistance == 324000))
					{
						WRITE_ANALOG( A_Disc_Pos_Read , 0.0 , &nCommStatus );
						WRITE_ANALOG( A_Disc_Pos_Degree , 0.0 , &nCommStatus );
					}
					else
					{
						WRITE_ANALOG( A_Disc_Pos_Read , dDiscDistance , &nCommStatus );
						WRITE_ANALOG( A_Disc_Pos_Degree , dDiscDistance/900 , &nCommStatus );
					}
				}
				else
				{/*Incremental*/
					dDiscDistance = READ_ANALOG( A_Disc_Distance , &nCommStatus );
					if ( dDiscDistance > 0 )
					{
						dDiscPosition = READ_ANALOG( A_Disc_Pos_Read , &nCommStatus );
						dOldDiscPosition = dDiscPosition;
						dDiscPosition = (int)(dDiscPosition+1)%324000;
						WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
						WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
						_sleep(1000);
						if ( dDiscDistance > 1 )
						{
							if ( dDiscDistance > 100 )
							{
								dDiscPosition = (int)(dDiscPosition+100)%324000;
								WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
								WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
								_sleep(1000);
							}
							if ( dDiscDistance > 1100 )
							{
								dDiscPosition = (int)(dDiscPosition+1000)%324000;
								WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
								WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
								_sleep(500);
							}
							if ( dDiscDistance > 1600 )
							{
								dDiscPosition = (int)(dDiscPosition+500)%324000;
								WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
								WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
								_sleep(500);
							}
							if ( dDiscDistance > 1700 )
							{
								dDiscPosition = (int)(dDiscPosition+100)%324000;
								WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
								WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
								_sleep(500);
							}
							dOldDiscPosition += dDiscDistance;
							dDiscPosition = (int)dOldDiscPosition % 324000;
						}
					}
					else
					{
						dDiscPosition = READ_ANALOG( A_Disc_Pos_Read , &nCommStatus );
						dOldDiscPosition = dDiscPosition;
						dDiscPosition = (int)(dDiscPosition-1)%324000;
						WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
						WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
						_sleep(1000);
						if ( dDiscDistance < -1 )
						{
							if ( dDiscDistance < -100 )
							{
								dDiscPosition = (int)(dDiscPosition-100)%324000;
								WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
								WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
								_sleep(1000);
							}
							if ( dDiscDistance < -1100 )
							{
								dDiscPosition = (int)(dDiscPosition-1000)%324000;
								WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
								WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
								_sleep(500);
							}
							if ( dDiscDistance < -1600 )
							{
								dDiscPosition = (int)(dDiscPosition-500)%324000;
								WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
								WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
								_sleep(500);
							}
							if ( dDiscDistance < -1700 )
							{
								dDiscPosition = (int)(dDiscPosition-100)%324000;
								WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
								WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
								_sleep(500);
							}
							dOldDiscPosition += dDiscDistance;
							dDiscPosition = (int)dOldDiscPosition % 324000;
						}
					}					
					
					WRITE_ANALOG( A_Disc_Pos_Read , dDiscPosition , &nCommStatus );
					WRITE_ANALOG( A_Disc_Pos_Degree , dDiscPosition/900 , &nCommStatus );
				}
				WRITE_DIGITAL( D_Disc_AtStation , 1/*ON*/ , &nCommStatus );
				
				if ( dDiscPosition == 0 )	WRITE_DIGITAL( D_Disc_HomSnsActv , 1/*ON*/ , &nCommStatus );
				else						WRITE_DIGITAL( D_Disc_HomSnsActv , 0/*OFF*/ , &nCommStatus );
				WRITE_DIGITAL( D_Disc_RunSts , 0/*IDLE*/ , &nCommStatus );
				WRITE_DIGITAL( D_Disc_Control , DISC_STOP_CTRL , &nCommStatus );
			}
		}
		else
		{
			WRITE_DIGITAL( D_Disc_HomeSts , 0/*OFF*/ , &nCommStatus );
			WRITE_DIGITAL( D_Disc_RunSts , 0/*IDLE*/ , &nCommStatus );
		}

		_sleep(10);
		if ( g_bTHREAD_END )	break;
	}

	_endthreadex(0);
	return;
}

