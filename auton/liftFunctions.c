/*
Moves lift up until it reaches a specific angle.

@param angle: the angle at which to stop powering the lift.
*/
void autonLiftUp (int angle) {
	stopTask(autonHold);
	int speed = 120;

	while (SensorValue[LiftPot] < angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

/*
Moves lift down until it reaches a specific angle.

@param angle: the angle at which to stop powering the lift.
*/
void autonLiftDown (int angle) {
	int speed = -120;

	while (SensorValue[LiftPot] > angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

/*
Deploys claw.
*/
task deploy() {
	autonLiftUp(1900);
	wait1Msec(150);
	clawState(OPEN);
	wait1Msec(150);
	autonLiftDown(750);
	stopTask(deploy);
}

/*
Lifts lift to height appropriate for dumping objects over the side (high) fences.
Made a task to be able to lift for dump while moving.
*/
task launch() {
	while (SensorValue[LiftPot] < 2500) {
		moveLift(127);
		wait1Msec(20);
	}
	//wait1Msec(400);
	moveLift(0);
	stopTask(launch);
}

/*
Brings lift down to neutral position. Made task to bring lift down while moving.
*/
void reset() {
	int potHeightDown = 790;
	while (SensorValue[LiftPot] > potHeightDown) {
		moveLift(-127);
		wait1Msec(20);
	}
	moveLift(0);
}
