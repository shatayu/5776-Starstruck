task clawStall() {
	while (SensorValue[ClawPot] < 3000) {
		moveClaw(30, CLOSED);
		wait1Msec(20);
	}
	moveClaw(0, OPEN);
}

task openClaw() {
	int openAngle = 2500; // ACTUAL CONSTANT
	while (SensorValue[ClawPot] > openAngle) {
		moveClaw(127, OPEN);
		wait1Msec(20);
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

task clawBack() {
	int time = 0;
	while (SensorValue[ClawPot] > 1800 && time < 3000) {
		moveClaw(60, OPEN);
		wait1Msec(20);
		time += 20;
	}
	moveClaw(0, OPEN);
	stopTask(clawBack);
}
