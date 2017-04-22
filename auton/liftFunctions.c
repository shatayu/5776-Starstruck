/*
Moves lift up until it reaches a specific angle.

@param angle: the angle at which to stop powering the lift.
*/
void autonLiftUp (int angle) {
	while (SensorValue[LiftPot] < angle) {
		moveLift(70);
		wait1Msec(20);
	}
	moveLift(0);
	startTask(autonHold);
	//stopTask(liftLaunch);
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

void autonLiftDownKillTime (int angle, int killTime) {
	int speed = -120;
	int time = 0;
	while (SensorValue[LiftPot] > angle && time < killTime) {
		moveLift(speed);
		wait1Msec(20);
		time += 20;
	}

	moveLift(0);
}


/*
Lifts lift to height appropriate for dumping objects over the side (high) fences.
Made a task to be able to lift for dump while moving.
*/
task liftLaunch() {
	stopTask(autonHold);
	while (SensorValue[LiftPot] < 2350) {
		moveLift(70);
		wait1Msec(20);
	}
	moveLift(0);
	startTask(autonHold);
}

/*
Brings lift down to neutral position. Made task to bring lift down while moving.
*/
task resetLift() {
	stopTask(autonHold);
	int potHeightDown = 900;
	int time = 0;
	while (SensorValue[LiftPot] > potHeightDown && time < 3000) {
		moveLift(-127);
		wait1Msec(20);
		time += 20
	}
	moveLift(0);
	startTask(autonHold);
}
