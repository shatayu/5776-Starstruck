// use claw to knock stars off fence
PID holdPID;
task autonHold() {
	// 0 for when off
	// 0.01 for claw open
	// 0.015 for claw closed
	holdPID.kp = 0.4;
	holdPID.ki = 0.1;
	holdPID.dead = 10;
	holdPID.iCap = 10;
	holdPID.tCap = 15;

	holdPID.set = SensorValue[LiftPot];

	while (true) {
		if(SensorValue[LiftPot] > 900){
			holdPID.cur = SensorValue[LiftPot];
			calcPID(holdPID);
		}else{
			holdPID.power = 0;
			holdPID.integral = 0;
		}
		moveLift(holdPID.power);
		wait1Msec(20);
	}
}

void supportBlue (int direction) {
	deploy();

	clawState(OPEN);
	move(1310, FORWARD);
	wait1Msec(150);
	clawState(CLOSED);
	wait1Msec(150);
	autonLiftUp(1800);
	startTask(autonHold);
	move(1650, BACKWARD);
	rotate(90, COUNTERCLOCKWISE * direction);
	move(1900, BACKWARD); // test distance
	stopTask(autonHold);

	moveLift(127);
	while (SensorValue[LiftPot] < 2300) {
		wait1Msec(20);
	}
	clawState(OPEN);
	while (SensorValue[LiftPot] < 2600) {
		wait1Msec(20);
	}

	moveLift(0);
	startTask(autonHold);
	move(800, FORWARD);
	stopTask(autonHold);

	//rotate(135, CLOCKWISE * direction);
	//move(700, BACKWARD);
	//hang();
}



// pick up cube and knock it over central fence, knocking stars with it
void cubeScore (int direction) {
	rotate(90, direction * CLOCKWISE);
	autonLiftDown(LIFT_DOWN);
	move(POSTFENCE_TO_CUBE_1, FORWARD);
	clawState(CLOSED);
	autonLiftUp(LIFT_CUBE_SCORE/5); // just enough to have cube not drag on ground - change denominator if need be
	move(POSTFENCE_TO_CUBE_2, FORWARD);
	rotate(90, direction * CLOCKWISE);
	move(CUBE_TO_FENCE, BACKWARD);
	autonLiftUp(4 * LIFT_CUBE_SCORE/5); // release cube - lift whatever distance wasn't lifted initially
	clawState(OPEN); // not sure if auton release works; test
}
