void moveDrive (int left, int right) {
	motor[FLDrive] = left;
	motor[BLDrive] = left;
	motor[LDrive] = left;
	motor[FRDrive] = right;
	motor[BRDrive] = right;
	motor[RDrive] = right;
}

void moveLift (int speed) {
	motor[LLift] = speed;
	motor[RLift] = speed;
}

void clawState (int state) {
	SensorValue[ClawSolenoid] = state;
}

void transmissionState (int state) {
	SensorValue[Transmission] = state;
}
