/*
Low-level basic way to power drive motors.

@param left: the amount of power to give to the left side motors
@param right: the amount of power to give to the right side motors
*/
void moveDrive (int left, int right) {
	motor[FLDrive] = left;
	motor[BLDrive] = left;
	motor[LDrive] = left;
	motor[FRDrive] = right;
	motor[BRDrive] = right;
	motor[RDrive] = right;
}

/*
Low-level, basic way to power lift

@param speed: how much power to give to the lift
*/
void moveLift (int speed) {
	motor[LLift] = speed;
	motor[RLift] = speed;
}

/*
Low-level, basic way to assign the claw a state

@param state: the state of the claw (OPEN/CLOSED)
*/
void clawState (int state) {
	SensorValue[ClawSolenoid] = state;
}

/*
Low-level, bsaic way to assign the transmission a state

@param state: the state of the transmission (ENGAGED/DISENGAGED)
*/
void transmissionState (int state) {
	SensorValue[Transmission] = state;
}
