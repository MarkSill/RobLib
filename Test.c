#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop, reversed)

#include "Lib.h"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*--------------------------------------------------------------------------------------------------------*\
|*                                                                                                        *|
|*                                    - Tetrix Simple Tank Drive -                                        *|
|*                                          ROBOTC on Tetrix                                              *|
|*                                                                                                        *|
|*  This program allows you to drive a robot via remote control using the ROBOTC Debugger.                *|
|*  This particular method uses "Tank Drive" where each side is controlled individually like a tank.      *|
|*                                                                                                        *|
|*                                        ROBOT CONFIGURATION                                             *|
|*    NOTES:                                                                                              *|
|*                                                                                                        *|
|*    MOTORS & SENSORS:                                                                                   *|
|*    [I/O Port]              [Name]              [Type]              [Description]                       *|
|*    Port D                  motorD              12V                 Right motor                         *|
|*    Port E                  motorE              12V                 Left motor                          *|
\*---------------------------------------------------------------------------------------------------4246-*/

#include "JoystickDriver.c"

task main()
{
	//setup RobLib
	struct arrayInt driveMotors;
	int arr1[2] = {motorD, motorE};
	driveMotors.array = arr1;
	struct arrayInt turnrMotors;
	int arr2[2] = {motorE, motorD};
	turnrMotors.array = arr2;
	struct arrayInt turnlMotors;
	turnlMotors.array = arr2;
	setup(driveMotors, 2, turnrMotors, turnlMotors, 2, true);

	while(true)                            // Infinite loop:
	{
		getJoystickSettings(joystick);

		moveAll(50);
		wait10Msec(100);
		rstopAll();
		wait10Msec(50);
		turn(DIR_LEFT, 100);
		wait10Msec(10);
		rstopAll();
		wait10Msec(200);
	}
}
