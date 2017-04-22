#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, in1,    ,               sensorPotentiometer)
#pragma config(Sensor, in4,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, in5,    LiftPot,        sensorPotentiometer)
#pragma config(Sensor, in6,    Selector,       sensorPotentiometer)
#pragma config(Sensor, in7,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  RQuad,          sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  LQuad,          sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  PowerExpander,  sensorDigitalIn)
#pragma config(Motor,  port2,           RLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RPEXLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RDrive,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RClaw,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LClaw,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LPEXLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LLift,         tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2);
#pragma competitionControl(Competition);
#include "Vex_Competition_Includes.c";
/*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*/

#define NUMAUTONS 5

int x = 0;

#include "preauton/lcd.h"
#include "preauton/lcd.c"

#include "drive/drive.h"
#include "drive/functions.c"

#include "PID/PID.h"
#include "PID/PID.c"

#include "auton/auton.h"
#include "auton/baseFunctions.c"
#include "auton/clawFunctions.c"
#include "auton/liftFunctions.c"
#include "auton/autons.c"

void pre_auton() {
	calibrate();

	//startTask(autonSelect);
}

int finalAuton = -1;
task autonomous() {
/*
	1.) Find height needed to pull stars
	2.) test pullStars
	3.) get 3 edge star hoard to work
	4.) position for center
	5.) get 4 center star hoard to work
	*/
//hoard(LEFT);
//dump();
	cubeScore(LEFT);
}


task usercontrol() {
	startTask(lift); //in PID.c
	bool closeToggle;

	closeToggle = false;
	PIDToggle = false;

	while (true) {
		// arcade drive
		moveDrive((vexRT[Ch3] + vexRT[Ch1]), (vexRT[Ch3] - vexRT[Ch1]));

		// claw code
		if (vexRT[Btn8R])
			closeToggle = true;
		if (vexRT[Btn5U] || vexRT[Btn5D] || vexRT[Btn8L])
			closeToggle = false;

		if (closeToggle) {
			moveClaw(20, CLOSED);
		} else {
			if (vexRT[Btn5U]) {
				moveClaw(127, OPEN);
			} else if (vexRT[Btn5D]) {
				moveClaw(127, CLOSED);
			} else {
				moveClaw(0, OPEN);
			}
		}


		if (vexRT[Btn7D]) {
			zeroEncoders();
		}

		if (vexRT[Btn7R]) {
			closeToggle = false;
			PIDToggle = false;
		}
		wait1Msec(20);
	}
}
// 680 - lift down state, position needed for turns
