#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in2,    ,               sensorAnalog)
#pragma config(Sensor, in3,    ClawPot,        sensorPotentiometer)
#pragma config(Sensor, in4,    LiftPot,        sensorPotentiometer)
#pragma config(Sensor, in5,    Gyro,           sensorGyro)
#pragma config(Sensor, in6,    Selector,       sensorPotentiometer)
#pragma config(Sensor, in7,    PowerExpander,  sensorAnalog)
#pragma config(Sensor, dgtl1,  ClawSolenoid,   sensorDigitalOut)
#pragma config(Sensor, dgtl2,  Transmission,   sensorDigitalOut)
#pragma config(Sensor, dgtl9,  RQuad,          sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LQuad,          sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  REncoder,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  LEncoder,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           LDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           LPEXLift,      tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port4,           LLift,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LClaw,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RClaw,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           RPEXLift,      tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port9,           RDrive,        tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2);
#pragma competitionControl(Competition);
#include "Vex_Competition_Includes.c";
/*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*/

int v;

#include "preauton/lcd.h"
#include "preauton/lcd.c"

#include "drive/drive.h"
#include "drive/toggle.h"
//#include "drive/controls.c"
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
	//SensorType[in2] = sensorGyro;
}

task autonomous() {
cubeScore();
cubeScore1();
}

task usercontrol() {
	//startTask(controls);
	startTask(lift);

	while (true) {
		SensorType[in2] = sensorGyro;
		// arcade drive
		moveDrive(vexRT[Ch3] + vexRT[Ch1], 0.8*(vexRT[Ch3] - vexRT[Ch1]));

		// claw control
		if (vexRT[Btn5U] && vexRT[Btn5D]) {
			stopTask(velocityCloseClaw);
			moveClaw(30, CLOSED); // stall torque
		} else if (vexRT[Btn5U]) {
			stopTask(velocityCloseClaw);
			moveClaw(127, OPEN); // open
		} else if (vexRT[Btn5D]) {
			stopTask(velocityCloseClaw);
			moveClaw(127, CLOSED); // close
		} else {
			moveClaw(0, OPEN);
		}

		wait1Msec(20);
	}
}
// 680 - lift down state, position needed for turns
