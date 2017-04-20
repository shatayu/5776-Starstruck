void basicAuton () {
	move(2000, BACKWARD);
	startTask(liftLaunch); // starts autonHold upon completion
	move(3000, BACKWARD);
	//startTask(openClaw);
	move(500, BACKWARD);

	moveDrive(-127, -127);
	wait1Msec(500);
	moveDrive(-127, -127);
	brake(BACKWARD);

	wait1Msec(500);
	moveDrive(1000, FORWARD);
	brake(FORWARD);
}

void cubeScore (int direction) {
	/* grab cube */
	move(2000, FORWARD);
	brake(FORWARD);
	rotate(87, COUNTERCLOCKWISE * direction);

	move(500, BACKWARD);
	brake(BACKWARD);
	move(500, FORWARD);
	move(3000, FORWARD);
	brake(FORWARD);
	// stop deploy
	closeClaw(3100, 3000);
	moveClaw(20, CLOSED);
	autonLiftUp(1600);
	startTask(autonHold);
	rotate(87, COUNTERCLOCKWISE * direction);

	/* dump over fence */
	// 3000 total distance from cube to fence
	move(1250, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch); // starts autonHold upon completion
	move(1000, BACKWARD);
	startTask(openClaw);
	move(550, BACKWARD);

	moveDrive(-127, -127);
	wait1Msec(400);
	moveDrive(0, 0);
	brake(BACKWARD);

	/* bring down */
	stopTask(autonHold);
	stopTask(liftLaunch);
	autonLiftDown(1000);
}

void stars() {
	/* move forward and grab stars */
	move(5000, FORWARD);
	closeClaw(3100, 3000);
	autonLiftUp(1600);
	startTask(autonHold);

	/* go back and dump stars */
	move(1000, BACKWARD, 70);
	brake(BACKWARD);
	move(1000, FORWARD);
	move(1250, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch); // starts autonHold upon completion
	move(1000, BACKWARD);
	startTask(openClaw);
	move(550, BACKWARD);

	moveDrive(-127, -127);
	wait1Msec(400);
	moveDrive(0, 0);
	brake(BACKWARD);

	/* bring down */
	stopTask(autonHold);
	stopTask(liftLaunch);
	autonLiftDown(1000);
}

void hoardHangR() {

	move(2000, FORWARD);
	startTask(liftLaunch); // starts task autonHold
	//startTask(openClaw);
	brake(FORWARD);
	startTask(velocityCloseClaw);
	wait1Msec(500);
	resetLift();

	// go back and hang
	move(800, BACKWARD);
	rotate(45, COUNTERCLOCKWISE);
	move(200, BACKWARD);

	moveDrive(-127, -127);
	wait1Msec(500);
	moveDrive(0, 0);

	//hang();
}
