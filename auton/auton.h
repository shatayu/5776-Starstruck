void backFenceLeft() {
	// deploy
	stopTask(lift);
	startTask(deploy);
	move(150, BACKWARD);

	// initial back star grab
	clawState(OPEN);
	while (SensorValue[LiftPot] > 800) wait1Msec(20);
	move(1150, FORWARD);
	clawState(CLOSED);
	wait1Msec(400);
	autonLiftUp(1600);
	startTask(autonHold);
	move(1200, BACKWARD);

	//fence push
	rotate(85, CLOCKWISE, 70);
	stopTask(autonHold);
	move(400, BACKWARD);
	//wait1Msec(1500);
	startTask(launch);
	move(400, BACKWARD);
	clawState(OPEN);
	move(300, BACKWARD);
	moveDrive(-100, -100);
	wait1Msec(600);
	moveDrive(0, 0);
	wait1Msec(200);
	stopTask(launch);

	// cube grab
	startTask(reset);
	move(100, FORWARD);
	rotate(79, COUNTERCLOCKWISE); // angle robot toward cube
	move(900, FORWARD);
	clawState(CLOSED);
	stopTask(reset);

	// cube score
	rotate(76, CLOCKWISE);
	startTask(launch);
	move(200, BACKWARD);
	clawState(OPEN);
	move(200, FORWARD);
}
