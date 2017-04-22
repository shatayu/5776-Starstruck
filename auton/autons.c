// low height 900
// medium height 1500
// dump height 2500
// max height 3300

void deployworlds(int clawAngle) {
	displayLCDCenteredString(TOP, "DEPLOYING");
	autonLiftUp(2500);
	startTask(autonHold);
	closeClaw(clawAngle, 1500);
	stopTask(autonHold);
	autonLiftDown(800);
	startTask(autonHold);
}

void cubeGrab (int direction) {
	/* grab cube */
	//deployworlds();
	move(2000, FORWARD, 2500);
	brake(FORWARD);

	rotate(88, COUNTERCLOCKWISE * direction);

	move(1400, FORWARD);
	brake(FORWARD);
	// stop deploy
	closeClaw(3900, 1500);
	startTask(clawStall);
	stopTask(autonHold);
	autonLiftUp(1500);
	startTask(autonHold);
}

void dump() {
		///* dump over fence */
	// 3000 total distance from cube to fence
	moveKill(950, BACKWARD, 1500);
	//stopTask(autonHold); moved
	startTask(liftLaunch); // starts autonHold upon completion
	moveKill(350, BACKWARD, 1000);
	stopTask(clawStall);
	startTask(openClaw);
	move(1050, BACKWARD, 2000);

	brake(BACKWARD);

	/* bring down */
	stopTask(autonHold);
	stopTask(liftLaunch);
	autonLiftDown(900);
	startTask(autonHold);
}

void stars() {
	/* move forward and grab stars */
	startTask(openClaw);
	move(5000, FORWARD);
	stopTask(openClaw);
	closeClaw(3900, 2000);
	stopTask(autonHold);
	autonLiftUp(1600);
	startTask(autonHold);

	/* go back and dump stars */
	dump();
}

void cubeScore (int direction) {
	if (direction == 1) {
		displayLCDCenteredString(TOP, "RIGHT CUBE");
	} else {
		displayLCDCenteredString(TOP, "LEFT CUBE");
	}
	deployworlds(2350);
	cubeGrab(direction);
	rotate(88, COUNTERCLOCKWISE * direction);
	dump();
	for (int i = 0; i < 2; i++) stars();
	move(1000, FORWARD);
	brake(FORWARD);
}

/* NOTE: supportL is named as such because of the 'L' pattern it makes, not because it is a left-specific auton */
void supportL (int direction) {
	if (direction == 1) {
		displayLCDCenteredString(TOP, "RIGHT SUPPORTL");
	} else {
		displayLCDCenteredString(TOP, "LEFT SUPPORTL");
	}
	/* grab stars */
	move(500, BACKWARD);
	brake(BACKWARD);
	deployworlds(3100);
	move(500, FORWARD);
	move(6000, FORWARD);
	brake(FORWARD);
	closeClaw(3900, 1500);
	startTask(clawStall);

	/* go back to starting tile */
	stopTask(autonHold);
	autonLiftUp(1500);
	startTask(autonHold);
	move(6000, BACKWARD);
	brake(BACKWARD);

	/* dump stars */
	rotate(88, COUNTERCLOCKWISE * direction);
	move(2000, BACKWARD);
	dump();
}

void pullStars() {
	/* knock edge 3 stars down */
	autonLiftDownKillTime(2500, 1500);
	startTask(resetLift);
	startTask(clawBack);
	move(800, BACKWARD);
	stopTask(resetLift);
	stopTask(clawBack);
}

void hoard(int direction) {
	/* get cube out of the way */
	deployworlds(2600);
	cubeGrab(direction);
	stopTask(autonHold);
	rotate(30, CLOCKWISE * direction);
	startTask(liftLaunch);
	rotate(30, COUNTERCLOCKWISE * direction);
	move(500, FORWARD);
	brake(FORWARD);

	/* bring stars down */
	rotate(90, COUNTERCLOCKWISE * direction);
	autonLiftUp(2600);
	startTask(autonHold);
	moveKill(3000, FORWARD, 2000);
	pullStars();
}
