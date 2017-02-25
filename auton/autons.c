void cubeScore() {
	/* grab cube */
	//startTask(deploy);
	move(1000, FORWARD);
	brake(FORWARD);
	rotate(90, COUNTERCLOCKWISE);
	move(1000, FORWARD);
	brake(FORWARD);
	stopTask(deploy);
	startTask(velocityCloseClaw);

	/* dump cube */
	autonLiftUp(1800);
	startTask(autonHold);
	rotate(90, COUNTERCLOCKWISE);
	move(500, BACKWARD);
	stopTask(velocityCloseClaw);
	stopTask(autonHold);
	startTask(liftLaunch); // starts autonHold after usage
	move(500, BACKWARD);
	startTask(openClaw);

	// fence ram
	moveDrive(-127, -127);
	wait1Msec(300);
	moveDrive(0, 0);

	/* wing push */
	move(200, FORWARD);
	wait1Msec(100);
	move(200, BACKWARD);

	/* star grab */
	stopTask(autonHold);
	autonLiftDown(750);
	move(1000, FORWARD);
	brake(FORWARD);
	startTask(velocityCloseClaw);
	wait1Msec(500);

	/* star dump */
	move(500, BACKWARD);
	startTask(liftLaunch); // starts autonHold task
	move(500, BACKWARD);
	stopTask(velocityCloseClaw);
	startTask(openClaw);
	moveDrive(-127, -127);
	wait1Msec(300);
	moveDrive(0, 0);

	// move forward
	move(300, FORWARD);
	stopTask(autonHold);
}
