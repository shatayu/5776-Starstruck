void cubeScore() {
	/* move forward to grab cube */
	//startTask(deploy);
	//wait1Msec(0); // TUNE TIME TO ACCOUNT FOR DEPLOY
	move(3300, FORWARD);
	brake(FORWARD);
	//stopTask(deploy);

	/* grab stars */
	startTask(velocityCloseClaw);
	wait1Msec(500);
	autonLiftUp(1100);
	startTask(autonHold);

	move(3300, BACKWARD);
	brake(BACKWARD);
	encoderRotate(1150, CLOCKWISE);

	/* dump stars */
	move(5100, BACKWARD);
	stopTask(autonHold);
	stopTask(velocityCloseClaw);
	startTask(liftLaunch);
	move(300, BACKWARD);
	startTask(openClaw);
	moveDrive(-127, -127);
	wait1Msec(1000);
	moveDrive(0, 0);
	stopTask(openClaw);
	stopTask(liftLaunch);
	//autonLiftDown(1250);

	/* get cube */
	//rotate(70, COUNTERCLOCKWISE);
	//move(1000, FORWARD);
	//brake(FORWARD);
	//startTask(velocityCloseClaw);
	//wait1Msec(500);
	//autonLiftUp(1800);
	//rotate(70, CLOCKWISE);

	///* dump cube */
	//move(200, BACKWARD);
	//startTask(liftLaunch);
	//move(300, BACKWARD);
	//startTask(openClaw);
	//move(100, FORWARD);
}
