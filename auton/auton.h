void backFenceLeft() {
	stopTask(lift);
	startTask(deploy);
	move(250, BACKWARD);
	clawState(OPEN);
	while (SensorValue[LiftPot] > 800) wait1Msec(20);
	move(1150, FORWARD);
	clawState(CLOSED);
	wait1Msec(400);
	autonLiftUp(1600);
	startTask(autonHold);
	move(1300, BACKWARD);
	rotate(85, CLOCKWISE, 70);
	stopTask(autonHold);
	move(400, BACKWARD);
	startTask(launch);
	move(400, BACKWARD);
	clawState(OPEN);
	move(300, BACKWARD);
	moveDrive(-100, -100);
	wait1Msec(600);
	moveDrive(0, 0);
	wait1Msec(200);
	startTask(reset);
	move(100, FORWARD);
	//rotate(76, COUNTERCLOCKWISE);
	//move(1000, FORWARD);s
	//clawState(CLOSED);
	//rotate(77, CLOCKWISE);
	//startTask(launch);
	//move(200, BACKWARD);
	//clawState(OPEN);
	//move(200, FORWARD);
}

//void cubeScoreLeft() {
//	stopTask(lift);
//	deploy();
//	clawState(OPEN);
//	move(1000, FORWARD);
//	clawState(CLOSED);
//	stopTask(lift);
//	autonLiftUp(1800);
//	startTask(lift);
//	rotate(135, CLOCKWISE);
//	move(800, BACKWARD);
//	stopTask(lift);
//	autonLiftUp(2300);
//	clawState(OPEN);
//	autonLiftUp(2600);
//	wait1Msec(300);
//	autonLiftDown(760);
//	startTask(lift);
//	move(800, FORWARD);
//	clawState(CLOSED);
//	stopTask(lift);
//	autonLiftUp(1200);
//	startTask(lift);
//	move(200, FORWARD);
//	rotate(90, CLOCKWISE);
//	stopTask(lift);
//	autonLiftDown(750);
//	startTask(lift);
//	clawState(OPEN);
//	move(1000, FORWARD);
//	clawState(CLOSED);
//	move(300, BACKWARD);
//	stopTask(lift);
//	autonLiftUp(1500);
//	startTask(lift);
//	rotate(90, COUNTERCLOCKWISE);
//	move(1000, BACKWARD);
//	stopTask(lift);
//	autonLiftUp(2300);
//	clawState(OPEN);
//	autonLiftUp(2600);
//	wait1Msec(300);
//	autonLiftDown(750);
//	startTask(lift);
//	move(800, FORWARD);
//}

//void backFenceRight (int direction) {
//	move(250, BACKWARD);
//	deploy();
//	clawState(OPEN);
//	move(1360, FORWARD);
//	wait1Msec(150);
//	clawState(CLOSED);
//	wait1Msec(300);
//	autonLiftUp(1800);
//	startTask(autonHold);
//	move(1500, BACKWARD);
//	rotate(90, COUNTERCLOCKWISE * direction);
//	move(1900, BACKWARD); // test distance
//	stopTask(autonHold);

//	moveLift(127);
//	while (SensorValue[LiftPot] < 2300) wait1Msec(20);

//	clawState(OPEN);

//	while (SensorValue[LiftPot] < 2600) wait1Msec(20);

//	moveLift(0);

//	startTask(autonHold);
//	move(1000, FORWARD);
//	stopTask(autonHold);

//	//-------

//	wait1Msec(500);
//	autonLiftDown(800);
//	wait1Msec(100);
//	startTask(autonHold);
//	clawState(OPEN);
//	rotate(90, CLOCKWISE); // make sure turn is actually 90 degrees
//	move(1500, FORWARD); // check distance
//	clawState(CLOSED);
//	stopTask(autonHold);
//	autonLiftUp(1800);
//	startTask(autonHold);
//	rotate(90, COUNTERCLOCKWISE); // make sure turn is actually 90 degrees
//	move(950, BACKWARD); // check distance

//	moveLift(127);
//	while (SensorValue[LiftPot] < 2400) wait1Msec(20);
//	clawState(OPEN);
//	while (SensorValue[LiftPot] < 2700) wait1Msec(20);
//	moveLift(0);
//}

//void backFenceLeft (int direction) {
//	move(250, BACKWARD);
//	deploy();
//	clawState(OPEN);
//	move(1360, FORWARD);
//	wait1Msec(150);
//	clawState(CLOSED);
//	wait1Msec(300);
//	autonLiftUp(1800);
//	startTask(autonHold);
//	move(1500, BACKWARD);
//	rotate(90, CLOCKWISE * direction);
//	move(1900, BACKWARD); // test distance
//	stopTask(autonHold);

//	moveLift(127);
//	while (SensorValue[LiftPot] < 2300) wait1Msec(20);

//	clawState(OPEN);

//	while (SensorValue[LiftPot] < 2600) wait1Msec(20);

//	moveLift(0);

//	startTask(autonHold);
//	move(1000, FORWARD);
//	stopTask(autonHold);

//	//-------


//}

//void cubeScoreLeft() {
//		wait1Msec(500);
//	autonLiftDown(800);
//	wait1Msec(100);
//	startTask(autonHold);
//	clawState(OPEN);
//	rotate(87, COUNTERCLOCKWISE); // make sure turn is actually 90 degrees
//	move(1600, FORWARD); // check distance
//	clawState(CLOSED);
//	stopTask(autonHold);
//	autonLiftUp(1800);
//	startTask(autonHold);
//	rotate(90, CLOCKWISE); // make sure turn is actually 90 degrees
//	move(950, BACKWARD); // check distance
//	stopTask(autonHold);
//	moveLift(127);
//	while (SensorValue[LiftPot] < 2400) wait1Msec(20);
//	clawState(OPEN);
//	while (SensorValue[LiftPot] < 2700) wait1Msec(20);
//	moveLift(0);
//	move(800, FORWARD);
//}
