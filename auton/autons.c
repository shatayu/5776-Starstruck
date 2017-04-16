int k = 0;

void block() {
	move(900, BACKWARD);
	startTask(deploy);
	move(900, BACKWARD);
	autonLiftUp(2800);
	startTask(autonHold);
	move(1200, BACKWARD);
	wait1Msec(500);
	move(500, FORWARD);
}

void cubeScore() {
	/* grab cube */
	move(2000, FORWARD);
	brake(FORWARD);
	rotate(90, COUNTERCLOCKWISE);
	move(500, BACKWARD);
	startTask(deploya);
	k = 2;
	stopTask(deploya);
	move(3900, FORWARD);
	brake(FORWARD);
	wait1Msec(300);
	k = 3;
	return;
}

void cubeScore1() {
	///* dump cube */
	startTask(velocityCloseClaw);
	autonLiftUp(1500);

	startTask(autonHold);
	k = 4;
	rotate(85, COUNTERCLOCKWISE);
	k = 5;
	move(1300, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch); // starts autonHold after usage
	move(500, BACKWARD);
	stopTask(velocityCloseClaw);
	startTask(openClaw);
	// fence ram
	moveDrive(-127, -127);
	wait1Msec(300);
	moveDrive(0, 0);

	autonLiftDown(2500);

	/* wing push */
	move(500, FORWARD);
	wait1Msec(100);
	move(500, BACKWARD);

	/* star grab */
	stopTask(autonHold);
	autonLiftDown(400);
	move(2700, FORWARD);
	brake(FORWARD);
	startTask(velocityCloseClaw);
	wait1Msec(500);
	autonLiftUp(1500);
	startTask(autonHold);

	/* star dump */
	move(2000, BACKWARD);
	startTask(liftLaunch); // starts autonHold task
	move(600, BACKWARD);
	stopTask(velocityCloseClaw);
	startTask(openClaw);
	moveDrive(-127, -127);
	wait1Msec(300);
	moveDrive(0, 0);

	// move forward
	move(300, FORWARD);
	stopTask(autonHold);
}

void support() {
	/* star grab */
	startTask(deploy);
	wait1Msec(500); // tune for deploy
	move(1000, FORWARD);
	brake(FORWARD);
	stopTask(deploy);
	startTask(velocityCloseClaw);
	wait1Msec(500);

	/* return to center tile */
	autonLiftUp(1800);
	startTask(autonHold);
	move(1000, BACKWARD);
	brake(BACKWARD);
	rotate(90, COUNTERCLOCKWISE);

	/* dump */
	move(500, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch);
	move(500, BACKWARD);
	stopTask(velocityCloseClaw);
	startTask(openClaw);

	moveDrive(-127, -127);
	wait1Msec(300);
	moveDrive(127, 127);

	/* wing push */
	move(200, FORWARD);
	brake(FORWARD);
	wait1Msec(200);
	move(200, BACKWARD);
}
