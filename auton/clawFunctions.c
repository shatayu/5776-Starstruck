task deploya() {
	while (SensorValue[ClawPot] > 800) {
		moveClaw(127, CLOSED);
		wait1Msec(20);
	}
	stopTask(deploya);
}

float getVelocity() {
	int a = SensorValue[ClawPot];
	wait1Msec(20);
	int b = SensorValue[ClawPot];

	return (b - a)/20.0 * 1000;
}

task velocityCloseClaw() {
		//nSchedulePriority = 10;
		 //while velocity is above stallVelocity close very quickly - once velocity is below it means that claw has closed on objects
		float stallVelocity = 10;
		while (fabs(getVelocity()) > stallVelocity) {
			moveClaw(127, CLOSED);
			wait1Msec(20);
		}

		// apply small amounts of power to keep objects in claw
		int stallTorque = 30;
		while (true) {
			if (SensorValue[ClawPot] < 50) {
				moveClaw(0, CLOSED);
			} else {
				moveClaw(stallTorque, CLOSED);
				wait1Msec(20);
			}
		}

}

task halfOpenClaw() {
	int halfOpenAngle = 420; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] < halfOpenAngle) {
		moveClaw(127, OPEN);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(halfOpenClaw);
}

task halfCloseClaw() {
	int halfOpenAngle = 420; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] > halfOpenAngle) {
		moveClaw(127, CLOSED);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(halfOpenClaw);
}

task openClaw() {
	int openAngle = 1337; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] < openAngle) {
		moveClaw(127, OPEN);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(openClaw);
}
