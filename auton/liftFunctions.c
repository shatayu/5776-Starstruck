void autonLiftUp (int angle) {
	stopTask(autonHold);
	int speed = 120;

	while (SensorValue[LiftPot] < angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

void autonLiftDown (int angle) {
	int speed = -120;

	while (SensorValue[LiftPot] > angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

task deploy() {
	autonLiftUp(1900);
	wait1Msec(150);
	clawState(OPEN);
	wait1Msec(150);
	autonLiftDown(750);
	stopTask(deploy);
}

task launch() {
	while (SensorValue[LiftPot] < 2300) {
		moveLift(127);
		wait1Msec(20);
	}
	moveLift(0);
	stopTask(launch);
}

// brings lift down to low position
task reset() {
	while (SensorValue[LiftPot] > 790) {
		moveLift(-127);
		wait1Msec(20);
	}
	moveLift(0);
	stopTask(reset);
}
