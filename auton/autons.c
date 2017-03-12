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
	startTask(halfCloseClaw);
	rotate(90, COUNTERCLOCKWISE);
	gyroCorrect(90, CLOCKWISE);
	move(3000, FORWARD);
	brake(FORWARD);
	stopTask(halfCloseClaw);
	startTask(velocityCloseClaw);
	autonLiftUp(1500);
	startTask(autonHold);
	move(1500, BACKWARD);
	brake(BACKWARD);
	rotate(90, COUNTERCLOCKWISE);
	startTask(liftLaunch); // starts autonHold
	wait1Msec(300);
	startTask(openClaw);
}
