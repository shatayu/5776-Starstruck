/*
- first L to get 3 center back stars (leaves in front of left fence facing backwards)
- run preloadRun 3 times (leaves in front of left fence facing backwards)
- centerFront dumps 3 center front stars and front right  star (leaves in front of center fence facing backwards)
- centerCubeDump dumps center cube (leaves in front of center fence facing backwards)
- sideCube gets back right star and cube, dumps both
*/

void L () {
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
