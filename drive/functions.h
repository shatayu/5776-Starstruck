
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

void liftHang () {
	int hangAngle = 1600;
	while (SensorValue[LiftPot] < hangAngle) {
		moveLift(127);
	}
}

void unhang () {
	moveDrive(-127, -127);
	wait1Msec(100);
	moveDrive(0, 0);

	transmissionState(0);
	wait1Msec(1000);

	moveDrive(-127, -127);
	moveLift(-127);
	wait1Msec(200);

	moveDrive(0, 0);
	wait1Msec(500);
	moveLift(0);
}
