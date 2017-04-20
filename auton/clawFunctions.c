float getVelocity() {
	int a = SensorValue[ClawPot];
	wait1Msec(50);
	int b = SensorValue[ClawPot];

	return (b - a)/50.0 * 2500;
}

int v;
task clawStall() {
	while (SensorValue[ClawPot] < 3000) {
		moveClaw(30, CLOSED);
	}
	moveClaw(0, OPEN);
}
task openClaw() {
	int openAngle = 2300; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] > openAngle) {
		moveClaw(127, OPEN);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
	stopTask(openClaw);
}

void openClawF(int sensor, int killTimeMS) {
	int time = 0;
	while (time < killTimeMS && SensorValue[ClawPot] < sensor) {
		moveClaw(127, OPEN);
		wait1Msec(20);
		time += 20;
	}
	moveClaw(0, OPEN);
}

void closeClaw(int sensor, int killTimeMS) {
	int time = 0;
	while (time < killTimeMS && SensorValue[ClawPot] < sensor) {
		moveClaw(127, CLOSED);
		wait1Msec(20);
		time += 20;
	}
	moveClaw(0, CLOSED);
}
