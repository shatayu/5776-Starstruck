float getVelocity() {
	int a = SensorValue[ClawPot];
	wait1Msec(20);
	int b = SensorValue[ClawPot];

	return (b - a)/20.0 * 1000;
}

task velocityCloseClaw() {
	 //while velocity is above stallVelocity close very quickly - once velocity is below it means that claw has closed on objects
	float stallVelocity = 10;
	while (fabs(getVelocity()) > stallVelocity) {
		moveClaw(127, CLOSED);
		wait1Msec(20);
	}

	// apply small amounts of power to keep objects in claw
	int stallTorque = 30;
	while (true) {
		moveClaw(stallTorque, CLOSED);
		wait1Msec(20);
	}

}

task halfOpenClaw() {
	int halfOpenAngle = 1400; // TUNE CONSTANT LATER
	while (SensorValue[ClawPot] < halfOpenAngle) {
		moveClaw(127, CLOSED);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(halfOpenClaw);
}

task openClaw() {
	int openAngle = 2800; // TUNE CONSTANT LATER
	while (SensorValue[ClawPot] < openAngle) {
		moveClaw(127, OPEN);
		wait1Msec(20);
	}
	moveClaw(0, OPEN)
	stopTask(openClaw);
}
