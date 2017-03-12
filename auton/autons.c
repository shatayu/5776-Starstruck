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

	move(1000, FORWARD); // grab 3 center back stars
	brake(FORWARD);
	stopTask(halfOpenClaw);
	startTask(velocityCloseClaw);
	while (SensorValue[ClawPot] > 420) wait1Msec(20); // wait
	autonLiftUp(1500);
	startTask(autonHold);
	move(1000, BACKWARD);
	brake(BACKWARD);

	// rotate, correct
	rotate(90, CLOCKWISE);
	gyroCorrect(90, COUNTERCLOCKWISE);

	// move backwards, dump
	move(500, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch); // starts autonHold
	move(300, BACKWARD);
	stopTask(velocityCloseClaw);
	startTask(openClaw);
	stopTask(autonHold);
	autonLiftDown(750); // down
	stopTask(openClaw);
}

void preloadRun() {
	move(1000, FORWARD);
	brake(FORWARD);
	wait1Msec(500);
	startTask(velocityCloseClaw);
	wait1Msec(500);

	move(500, BACKWARD);
	stopTask(autonHold);
	startTask(liftLaunch); // starts autonHold
	move(300, BACKWARD);
	stopTask(velocityCloseClaw);
	startTask(openClaw);
	stopTask(autonHold);
	autonLiftDown(750); // down
	stopTask(openClaw);
	move(300, FORWARD);
	brake(FORWARD);
}

void centerStars() {
	rotate(90, COUNTERCLOCKWISE);
	move(3000, FORWARD);
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
	gyroCorrect(90, COUNTERCLOCKWISE);
	startTask(openClaw);
	move(1000, FORWARD);
	stopTask(openClaw);


	// Pick up the star first
	startTask(velocityCloseClaw);
	while (isOpen()) delay(20);
	stopTask(velocityCloseClaw);
	autonLiftUp(1000);

	// Move backwards and rotate towards the cube
	move(500, BACKWARD);
	rotate(45, CLOCKWISE);
	gyroCorrect(45, COUNTERCLOCKWISE);
	
	// Obtain cube by first opening and stopping the auton lift
	stopTask(autonTask);
	autonLiftDown(500);
	stopTask(autonHold);
	move(750, FORWARD);

	startTask(velocityCloseClaw);
	while (isOpen()) delay(20);
	stopTask(velocityCloseClaw);

	// Move backward a bit and realign with fence to dump
	move(30, BACKWARD);
	brake(BACKWARD);

	// Move toward fence
	move(500, BACKWARD);
	brake(BACKWARD);
	rotate(45, COUNTERCLOCKWISE);
	gyroCorrect(45, CLOCKWISE);

	// dump
	startTask(liftLaunch);
}
