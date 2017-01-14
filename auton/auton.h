// use claw to knock stars off fence
void support (int direction) {
	PID liftPID;
	liftPID.kp = 0.4;
	liftPID.ki = 0.1;
	liftPID.dead = 10;
	liftPID.iCap = 10;
	liftPID.tCap = 15;

	//deploy();

	clawState(OPEN);
	move(1800, FORWARD); // check constant
	clawState(CLOSED);
	move(1800, BACKWARD);
}

// pick up cube and knock it over central fence, knocking stars with it
void cubeScore (int direction) {
	rotate(90, direction * CLOCKWISE);
	autonLiftDown(LIFT_DOWN);
	move(POSTFENCE_TO_CUBE_1, FORWARD);
	clawState(CLOSED);
	autonLiftUp(LIFT_CUBE_SCORE/5); // just enough to have cube not drag on ground - change denominator if need be
	move(POSTFENCE_TO_CUBE_2, FORWARD);
	rotate(90, direction * CLOCKWISE);
	move(CUBE_TO_FENCE, BACKWARD);
	autonLiftUp(4 * LIFT_CUBE_SCORE/5); // release cube - lift whatever distance wasn't lifted initially
	clawState(OPEN); // not sure if auton release works; test
}
