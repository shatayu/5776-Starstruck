void cubeScoreLeft() {
	stopTask(lift);
	deploy();
	clawState(OPEN);
	move(1000, FORWARD);
	clawState(CLOSED);
	stopTask(lift);
	autonLiftUp(1800);
	startTask(lift);
	rotate(135, CLOCKWISE);
	move(800, BACKWARD);
	stopTask(lift);
	autonLiftUp(2300);
	clawState(OPEN);
	autonLiftUp(2600);
	wait1Msec(300);
	autonLiftDown(760);
	startTask(lift);
	move(800, FORWARD);
	clawState(CLOSED);
	stopTask(lift);
	autonLiftUp(1200);
	startTask(lift);
	move(200, FORWARD);
	rotate(90, CLOCKWISE);
	stopTask(lift);
	autonLiftDown(750);
	startTask(lift);
	clawState(OPEN);
	move(1000, FORWARD);
	clawState(CLOSED);
	move(300, BACKWARD);
	stopTask(lift);
	autonLiftUp(1500);
	startTask(lift);
	rotate(90, COUNTERCLOCKWISE);
	move(1000, BACKWARD);
	stopTask(lift);
	autonLiftUp(2300);
	clawState(OPEN);
	autonLiftUp(2600);
	wait1Msec(300);
	autonLiftDown(750);
	startTask(lift);
	move(800, FORWARD);
}

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
