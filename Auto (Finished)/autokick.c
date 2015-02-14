#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed, driveLeft, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     star,          tmotorTetrix, openLoop, driveRight)
#pragma config(Motor,  mtr_S1_C2_1,     right,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     lift,          tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//Made by Taylor. Cuz he's awesome.

#include "JoystickDriver.c"

task main()
{
	waitForStart();
	while(nMotorEncoder(lift) < 7555)
	{
		motor[lift] = 100;
	}
	motor[star] = 25;
	wait10Msec(100);
	motor[star] = 0;
	motor[left] = 75;
	motor[right] = 75;
	wait10Msec(400);
	motor[left] = 0;
	motor[right] = 0;
	int i = 0;
	while(i <= 6)
	{
		motor[left] = 100;
		motor[right] = -100;
		wait10Msec(50);
		motor[left] = -100;
		motor[right] = 100;
		wait10Msec(50);
		i = i + 1;
	}
}
