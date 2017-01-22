void backFenceRight (int direction) {
	move(250, BACKWARD);
	deploy();
	clawState(OPEN);
	move(1360, FORWARD);
	wait1Msec(150);
	clawState(CLOSED);
	wait1Msec(300);
	autonLiftUp(1800);
	startTask(autonHold);
	move(1500, BACKWARD);
	rotate(90, COUNTERCLOCKWISE * direction);
	move(1900, BACKWARD); // test distance
	stopTask(autonHold);

	moveLift(127);
	while (SensorValue[LiftPot] < 2300) wait1Msec(20);

	clawState(OPEN);

	while (SensorValue[LiftPot] < 2600) wait1Msec(20);

	moveLift(0);

	startTask(autonHold);
	move(1000, FORWARD);
	stopTask(autonHold);

	//-------

	wait1Msec(500);
	autonLiftDown(800);
	wait1Msec(100);
	startTask(autonHold);
	clawState(OPEN);
	rotate(90, CLOCKWISE); // make sure turn is actually 90 degrees
	move(1500, FORWARD); // check distance
	clawState(CLOSED);
	stopTask(autonHold);
	autonLiftUp(1800);
	startTask(autonHold);
	rotate(90, COUNTERCLOCKWISE); // make sure turn is actually 90 degrees
	move(950, BACKWARD); // check distance

	moveLift(127);
	while (SensorValue[LiftPot] < 2400) wait1Msec(20);
	clawState(OPEN);
	while (SensorValue[LiftPot] < 2700) wait1Msec(20);
	moveLift(0);
}

void backFenceLeft (int direction) {
	move(250, BACKWARD);
	deploy();
	clawState(OPEN);
	move(1360, FORWARD);
	wait1Msec(150);
	clawState(CLOSED);
	wait1Msec(300);
	autonLiftUp(1800);
	startTask(autonHold);
	move(1500, BACKWARD);
	rotate(90, CLOCKWISE * direction);
	move(1900, BACKWARD); // test distance
	stopTask(autonHold);

	moveLift(127);
	while (SensorValue[LiftPot] < 2300) wait1Msec(20);

	clawState(OPEN);

	while (SensorValue[LiftPot] < 2600) wait1Msec(20);

	moveLift(0);

	startTask(autonHold);
	move(1000, FORWARD);
	stopTask(autonHold);

	//-------

	wait1Msec(500);
	autonLiftDown(800);
	wait1Msec(100);
	startTask(autonHold);
	clawState(OPEN);
	rotate(90, COUNTERCLOCKWISE); // make sure turn is actually 90 degrees
	move(1500, FORWARD); // check distance
	clawState(CLOSED);
	stopTask(autonHold);
	autonLiftUp(1800);
	startTask(autonHold);
	rotate(90, CLOCKWISE); // make sure turn is actually 90 degrees
	move(950, BACKWARD); // check distance
	stopTask(autonHold);
	moveLift(127);
	while (SensorValue[LiftPot] < 2400) wait1Msec(20);
	clawState(OPEN);
	while (SensorValue[LiftPot] < 2700) wait1Msec(20);
	moveLift(0);
	move(800, FORWARD);
}
