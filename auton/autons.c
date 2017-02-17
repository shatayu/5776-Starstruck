void backFenceLeft() {
	//deploy
	//startTask(deploy);
	//move(150, BACKWARD);
	//while (SensorValue[LiftPot] > 800) wait1Msec(20);

	// pick up 3 center back stars
	clawState(OPEN);
	move(1000, FORWARD);
	brake(FORWARD);
	clawState(CLOSED);
	wait1Msec(250);
	autonLiftUp(1800);
	startTask(autonHold);

	// line up with fence
	move(1050, BACKWARD);
	brake(BACKWARD);
	rotate(90, CLOCKWISE);

	// fence push
	stopTask(autonHold);
	startTask(launch);
	move(800, BACKWARD);
	clawState(OPEN);
	move(300, BACKWARD);
	moveDrive(-127, -127); // ram into fence
	wait1Msec(300);
	moveDrive(0, 0);
	stopTask(launch);
	move(200, FORWARD);
	brake(FORWARD);
	autonLiftDown(760);

	// rotate to cube, grab cube
	rotate(76, COUNTERCLOCKWISE); // test constant
	move(850, FORWARD);
	brake(FORWARD);// test how long it takes for lift to come down
	clawState(CLOSED);

	// dump cube
	rotate(70, CLOCKWISE);
	autonLiftUp(1800);
	startTask(launch);
	move(300, BACKWARD);
	brake(BACKWARD);
	clawState(OPEN);
	move(200, BACKWARD);
	brake(BACKWARD);
	moveDrive(-127, -127);
	wait1Msec(300);
	moveDrive(0, 0);
	move(200, FORWARD);
	brake(FORWARD);
	wait1Msec(700);
	stopTask(launch);
}

//void backFenceLeft() {
//	// deploy
//	stopTask(lift);
//	startTask(deploy);
//	move(150, BACKWARD);

//	// initial back star grab
//	clawState(OPEN);
//	while (SensorValue[LiftPot] > 800) wait1Msec(20);
//	move(1150, FORWARD);
//	clawState(CLOSED);
//	wait1Msec(400);
//	autonLiftUp(1600);
//	startTask(autonHold);
//	move(1200, BACKWARD);

//	//fence push
//	rotate(85, CLOCKWISE, 70);
//	stopTask(autonHold);
//	move(400, BACKWARD);
//	//wait1Msec(1500);
//	startTask(launch);
//	move(400, BACKWARD);
//	clawState(OPEN);
//	move(300, BACKWARD);
//	moveDrive(-100, -100);
//	wait1Msec(600);
//	moveDrive(0, 0);
//	wait1Msec(200);
//	stopTask(launch);

//	// cube grab
//	startTask(reset);
//	move(100, FORWARD);
//	rotate(79, COUNTERCLOCKWISE); // angle robot toward cube
//	move(900, FORWARD);
//	clawState(CLOSED);
//	stopTask(reset);

//	// cube score
//	rotate(76, CLOCKWISE);
//	startTask(launch);
//	move(200, BACKWARD);
//	clawState(OPEN);
//	move(200, FORWARD);
