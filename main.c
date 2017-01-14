#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in2,    Gyro,           sensorGyro)
#pragma config(Sensor, in3,    ,               sensorGyro)
#pragma config(Sensor, in4,    LiftPot,        sensorPotentiometer)
#pragma config(Sensor, in6,    ,               sensorGyro)
#pragma config(Sensor, dgtl1,  ClawSolenoid,   sensorDigitalOut)
#pragma config(Sensor, dgtl2,  Transmission,   sensorDigitalOut)
#pragma config(Sensor, I2C_1,  REncoder,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  LEncoder,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           FLDrive,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BLDrive,       tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port4,           FRDrive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           BRDrive,       tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port6,           LLLift,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LRLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           RLLift,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           RRLift,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2);
#pragma competitionControl(Competition);
#include "Vex_Competition_Includes.c";
/*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*/
#include "PID.h"

#include "drive/toggle.h"
#include "drive/functions.h"

#include "auton/constants.h"
#include "auton/functions.h"
#include "auton/auton.h"

void pre_auton() {
	calibrate();
}

task autonomous() {

}

PID liftHoldPID;

bool buff = false;

task lift() {
	bool PIDToggle = false;
	// 0 for when off
	// 0.01 for claw open
	// 0.015 for claw closed
	liftHoldPID.kp = 0.4;
	liftHoldPID.ki = 0.1;
	liftHoldPID.dead = 10;
	liftHoldPID.iCap = 10;
	liftHoldPID.tCap = 15;


	//2770 parallel
	while (true) {
		if (vexRT[Btn7D])
			PIDToggle = false;
		if (vexRT[Btn7U])
			PIDToggle = true;

		if (vexRT[Btn6U]) {
			moveLift(127);
			buff = true;
		} else if (vexRT[Btn6D]) {
			moveLift(-127);
			buff = true;
		} else {
			if (buff) {
				liftHoldPID.set = SensorValue[LiftPot];
			}

			buff = false;

			if(SensorValue[LiftPot] > 900 && PIDToggle){
				liftHoldPID.cur = SensorValue[LiftPot];
				calcPID(liftHoldPID);
			}else{
				liftHoldPID.power = 0;
				liftHoldPID.integral = 0;
			}
			moveLift(liftHoldPID.power);
		}

		wait1Msec(20);
	}
}

task usercontrol() {
	Toggle claw;
	claw.state = 0;
	claw.buffer = 0;

	startTask(lift);

	while (true) {
		// arcade drive
		moveDrive(vexRT[Ch3] + vexRT[Ch1], vexRT[Ch3] - vexRT[Ch1]);

		// tank drive
		// moveDrive(vexRT[Ch3], vexRT[Ch2]);

		// claw
		if (vexRT[Btn5D] && (vexRT[Btn5D] != claw.buffer))  // if button is pressed and it was not pressed before
	   	claw.state = claw.state ? 0 : 1;

		claw.buffer = vexRT[Btn5D];
		clawState(claw.state);

		// transmission
		if (vexRT[Btn8U])
			transmissionState(OPEN);

		if (vexRT[Btn8D])
			transmissionState(CLOSED);

		if (vexRT[Btn8R]){
			stopTask(lift);
			deploy();
			startTask(lift);
		}

		if (vexRT[Btn8L]){
			stopTask(lift);
			autonLift(1200);
			startTask(lift);
		}
		wait1Msec(20);
	}
}
// 680 - lift down state, position needed for turns
