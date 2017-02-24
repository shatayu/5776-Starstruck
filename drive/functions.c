/*
Low-level, basic way to power drive motors.

@param left: the amount of power to give to the left side motors
@param right: the amount of power to give to the right side motors
*/
void moveDrive (int left, int right) {
	motor[LDrive] = left;
	motor[RDrive] = right;
}

/*
Low-level, basic way to power lift

@param power: how much power to give to the lift
@param direction: which direction to move the lift (UP or DOWN)
*/
void moveLift (int power) {
	motor[LLift] = power;
	motor[LPEXLift] = power;
	motor[RLift] = power;
	motor[RPEXLift] = power;
}

/*
Low-level, basic way to power claw motors

@param power: the amount of power to give to the claw
@param direction: whether to open or close the claw;
*/
void moveClaw (int power, int direction) {
	motor[LClaw] = power * direction;
	motor[RClaw] = power * direction;
}
