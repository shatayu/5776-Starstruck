/*
- first starL to get 3 center back stars (leaves in front of left fence facing backwards)
- run preloadRun 3 times (leaves in front of left fence facing backwards)
- centerStars gets 3 center front stars and front right star, dumps (leaves in front of center fence facing backwards)
- centerCube dumps cube (leaves in front of center fence facing backwards)
- rightCube gets back right star and right cube, dumps over right side fence
*/

void starL () {
	// deploy

	move(1000, FORWARD); // grab 3 center back stars
	brake(FORWARD);
	startTask(velocityCloseClaw);
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
	startTask(liftLaunch);
	move(300, BACKWARD);
	stopTask(velocityCloseClaw);

	startTask(openClaw);
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
