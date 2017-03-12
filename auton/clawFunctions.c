#define CLAW_OPEN_STATE 1300
#define CLAW_CLOSE_STATE 800

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
		moveClaw(127, CLOSED);
		wait1Msec(200);
		float stallVelocity = 100;
		while (abs(getVelocity()) > stallVelocity && SensorValue[ClawPot] > 900) {
			datalogAddValue(0, abs(getVelocity());
			moveClaw(127, CLOSED);
			wait1Msec(20);
		}

		// apply small amounts of power to keep objects in claw
		int stallTorque = 30;
		while (true) {
			if (SensorValue[ClawPot] < 900) {
				moveClaw(0, CLOSED);
			} else {
				moveClaw(stallTorque, CLOSED);
				wait1Msec(20);
			}
		}

}

task halfOpenClaw() {
	int halfOpenAngle = 1300; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] < halfOpenAngle) {
		moveClaw(127, OPEN);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(halfOpenClaw);
}

task halfCloseClaw() {
	int halfOpenAngle = 1400; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] > halfOpenAngle) {
		moveClaw(127, CLOSED);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(halfOpenClaw);
}

task openClaw() {
	int openAngle = 2000; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] < openAngle) {
		moveClaw(127, OPEN);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(openClaw);
}

bool isOpen() {
	return SensorValue[ClawPot] > CLAW_OPEN_STATE;
}

void waitUntilClose() {
	while (isOpen()) delay(20);
}


void closeClaw() {
	startTask(velocityCloseClaw);
	int current;
	int currentSpeed = SensorValue[ClawPot];
	delay(20);
	currentSpeed -= SensorValue[ClawPot];
	while (abs(currentSpeed) < 10) {
		current = SensorValue[ClawPot];
		delay(20);
		currentSpeed -= SensorValue[ClawPot];
	}
}
