/*
- starL to get 3 center back stars (leaves in front of left fence facing backwards)
- preloadRun 3 times (leaves in front of left fence facing backwards)
- centerStars gets 3 center front stars and front right star, dumps (leaves in front of center fence facing backwards)
- centerCube dumps cube (leaves in front of center fence facing backwards)
- rightCube gets back right star and right cube, dumps over right side fence
*/

void starL () {
	// deploy
	startTask(halfOpenClaw);

	move(1200, FORWARD); // grab 3 center back stars
	brake(FORWARD);
	stopTask(halfOpenClaw);
	startTask(velocityCloseClaw);
	while (SensorValue[ClawPot] > 1300) wait1Msec(20); // wait
	autonLiftUp(2800);
	startTask(autonHold);
	move(1200, BACKWARD);
	brake(BACKWARD);

	// rotate, correct
	rotate(90, CLOCKWISE);
	//gyroCorrect(90, COUNTERCLOCKWISE);

	// move backwards, dump
	move(1300, BACKWARD);
	brake(BACKWARD);
	wait1Msec(400);
	stopTask(velocityCloseClaw);
	//startTask(launch);
	//while (SensorValue[LiftPot} < 3200) wait1Msec(20);
	//wait1Msec(400):
	stopTask(autonHold):
	autonLiftDown(1600);
}

void preloadRun() {
	startTask(openClaw);
	move(800, FORWARD);
	brake(FORWARD);
	wait1Msec(1500);
	stopTask(openClaw);
	startTask(velocityCloseClaw);
	wait1Msec(1500);

	// move backwards, dump
	move(800, BACKWARD);
	brake(BACKWARD);
	wait1Msec(400);
	//startTask(launch);
	//while (SensorValue[LiftPot} < 3200) wait1Msec(20);
	//wait1Msec(400):
	stopTask(autonHold):
	stopTask(velocityCloseClaw);
	autonLiftDown(1600);
}

void centerStars() {
	startTask(halfCloseClaw);
	//rotate(90, COUNTERCLOCKWISE);
	move(2800, FORWARD);
	brake(FORWARD);
	stopTask(halfCloseClaw);
	startTask(velocityCloseClaw);
	autonLiftUp(2600);
	startTask(autonHold);
	move(1500, BACKWARD);
	brake(BACKWARD);
	rotate(90, CLOCKWISE);
	stopTask(velocityCloseClaw);
	stopTask(autonHold);
	wait1Msec(400);
	//startTask(liftLaunch); // ADD LAUNCH CODE IN HERE
	stopTask(autonHold);
	autonLiftDown(1600);
	wait1Msec(300);
}


/**
 * Starts in neutral position in the middle against the fence opposing fence
 * Should dump the middle cube on the other side
 * End in neutral position in middle
 */
 void centerCube() {
	 startTask(openClaw);
	 delay(1000)
	 move(400, FORWARD);
	 stopTask(openClaw);
	 startTask(velocityCloseClaw);
	 waitUntilClose();
	 autonLiftUp(2600);
	 startTask(autonHold):
	 move(400, BACKWARD);
	 stopTask(autonHold);
	 startTask(launch);
	 // Hopefully have dumped the stuff on other side; move to return to neutral position
	 startTask(autonHold);
	 reset();
 }

/**
* Starts in middle at the fence in base position with claw AWAY from fence
* Target is to get cube and start and dump on far (right) fence
* Should end at right fence
*/
void rightCube() {
	rotate(90, COUNTERCLOCKWISE);
	move(500, FORWARD);
	brake(FORWARD);

	// Rotates to face edges
	rotate(90, CLOCKWISE);
	//gyroCorrect(90, COUNTERCLOCKWISE);
	startTask(openClaw);
	move(1000, FORWARD);
	stopTask(openClaw);


	// Pick up the star first
	startTask(velocityCloseClaw);
	while (isOpen()) delay(20);
	autonLiftUp(1000);

	// Move backwards and rotate towards the cube
	move(500, BACKWARD);
	rotate(45, CLOCKWISE);
	gyroCorrect(45, COUNTERCLOCKWISE);

	// Obtain cube by first opening and stopping the auton lift
	stopTask(autonHold);
	autonLiftDown(500);
	stopTask(velocityCloseClaw);
	stopTask(autonHold);
	startTask(openClaw);
	move(750, FORWARD);
	while (!isOpen()) delay(20);


	startTask(velocityCloseClaw);
	while (isOpen()) delay(20);

	// Move backward a bit and realign with fence to dump
	move(30, BACKWARD);
	brake(BACKWARD);

	// Move toward fence
	move(500, BACKWARD);
	brake(BACKWARD);
	rotate(45, COUNTERCLOCKWISE);
	gyroCorrect(45, CLOCKWISE);

	// dump
	startTask(launch);
}
