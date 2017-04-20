void basicAuton () {
	move(2000, BACKWARD);
	startTask(liftLaunch); // starts autonHold upon completion
	move(3000, BACKWARD);
	startTask(openClaw);
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
	rotate(90, COUNTERCLOCKWISE * direction);

	// deploy
	move(3000, FORWARD);
	brake(FORWARD);
	// stop deploy
	startTask(velocityCloseClaw);
	wait1Msec(400);
	autonLiftUp(1600);
	startTask(autonHold);
	rotate(90, COUNTERCLOCKWISE * direction);

	/* dump over fence */
	// 3000 total distance from cube to fence
	move(1250, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch); // starts autonHold upon completion
	move(1550, BACKWARD);

	moveDrive(-127, -127);
	wait1Msec(400);
	moveDrive(0, 0);
	brake(BACKWARD);

	stopTask(velocityCloseClaw);
	startTask(openClaw);

	/* bring down */
	stopTask(autonHold);
	stopTask(liftLaunch);
	autonLiftDown(1000);
}

void stars() {
	/* move forward and grab stars */
	move(5000, FORWARD);
	startTask(velocityCloseClaw);
	wait1Msec(500);
	autonLiftUp(1600);
	startTask(autonHold);

	/* go back and dump stars */
	move(1500, BACKWARD, 70);
	move(2000, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch); // starts autonHold upon completion
	move(1300, BACKWARD);

	moveDrive(-127, -127);
	wait1Msec(400);
	moveDrive(0, 0);
	brake(BACKWARD);

	stopTask(velocityCloseClaw);
	startTask(openClaw);

	/* move forward */
	move(1000, FORWARD);
	brake(FORWARD);
	stopTask(liftLaunch);
	stopTask(autonHold);
	autonLiftDown(1600);
}

void hoardHangR() {

	move(2000, FORWARD);
	startTask(liftLaunch); // starts task autonHold
	startTask(openClaw);
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
