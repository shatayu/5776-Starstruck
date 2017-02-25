int k = 0;

void supportAuton() {
	/* grab stars */
	startTask(deploy);
	move(3000, FORWARD);
	startTask(velocityCloseClaw);
	wait1Msec(500);
	autonLiftUp(2000);
	startTask(autonHold);
	move(3000, BACKWARD);

	/* dump */
	rotate(90, CLOCKWISE);
	move(3000, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch);
	wait1Msec(500);
	startTask(openClaw);
}

void cubeScore() {
	/* grab cube */
	startTask(deploy);
	move(2000, FORWARD);
	brake(FORWARD);
	rotate(90, COUNTERCLOCKWISE);
	k = 2;
	stopTask(deploy);
	move(3400, FORWARD);
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

	///* wing push */
	//move(200, FORWARD);
	//wait1Msec(100);
	//move(200, BACKWARD);

	///* star grab */
	//stopTask(autonHold);
	//autonLiftDown(750);
	//move(1000, FORWARD);
	//brake(FORWARD);
	//startTask(velocityCloseClaw);
	//wait1Msec(500);
	//autonLiftUp(1500);
	//startTask(autonHold);

	///* star dump */
	//move(500, BACKWARD);
	//startTask(liftLaunch); // starts autonHold task
	//move(500, BACKWARD);
	//stopTask(velocityCloseClaw);
	//startTask(openClaw);
	//moveDrive(-127, -127);
	//wait1Msec(300);
	//moveDrive(0, 0);

	//// move forward
	//move(300, FORWARD);
	//stopTask(autonHold);
}

void support() {
	/* star grab */
	startTask(deploy);
	wait1Msec(0); // tune for deploy
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
