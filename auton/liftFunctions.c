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
	stopTask(deploy);
}

/*
Lifts lift to height appropriate for dumping objects over the side (high) fences.
Made a task to be able to lift for dump while moving.
*/
task liftLaunch() {
	while (SensorValue[LiftPot] < 2400) {
		moveLift(127);
		wait1Msec(20);
	}
	moveLift(0);
	startTask(autonHold);
	stopTask(liftLaunch);
}

/*
Brings lift down to neutral position. Made task to bring lift down while moving.
*/
void reset() {
	int potHeightDown = 790;
	while (SensorValue[LiftPot] > potHeightDown) {
		moveLift(-50);
		wait1Msec(20);
	}
	moveLift(0);
}
