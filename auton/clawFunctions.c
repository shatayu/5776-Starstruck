float getVelocity() {
	int a = SensorValue[ClawPot];
	wait1Msec(50);
	int b = SensorValue[ClawPot];

	return (b - a)/50.0 * 2500;
}

int v;
task velocityCloseClaw() {
		//nSchedulePriority = 10;
		moveClaw(127, CLOSED);
		 //while velocity is above stallVelocity close very quickly - once velocity is below it means that claw has closed on objects
		float stallVelocity = 10;
		while (fabs(getVelocity()) > stallVelocity) {
			//v = getVelocity();
			v = 10;
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

task openClaw() {
	int openAngle = 1337; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] < openAngle) {
		moveClaw(127, OPEN);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(openClaw);
}
