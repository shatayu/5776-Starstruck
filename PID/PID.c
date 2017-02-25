// calculates PID values at a given point
void calcPID(PID tPID) {
	int error;
	int sign;
	int proportion;

	error = tPID.set - tPID.cur;
	if (fabs(error) > tPID.dead) {
		proportion = error * tPID.kp;

		tPID.integral += error * tPID.ki;
		sign = sgn(tPID.integral);
		tPID.integral = (fabs(tPID.integral) > tPID.iCap) ? sign * tPID.iCap : tPID.integral;

		tPID.power = proportion + tPID.integral;
		sign = sgn(tPID.power);
		tPID.power = (fabs(tPID.power) > tPID.tCap) ? (sign * tPID.tCap) : tPID.power;
	}
}


bool buff = false;
PID liftHoldPID;

/*
manages lift control, activates PID when lift is not moving up or down and PID is on
*/
task lift() {
	bool PIDToggle = false;

	liftHoldPID.kp = 0.4;
	liftHoldPID.ki = 0.1;
	liftHoldPID.dead = 10;
	liftHoldPID.iCap = 10;
	liftHoldPID.tCap = 15;


	//2770 parallel
	while (true) {
		if (vexRT[Btn6D])
			PIDToggle = false;
		if (vexRT[Btn6U])
			PIDToggle = true;

		if (vexRT[Btn6U]) {
			moveLift(127);
			buff = true;
			} else if (vexRT[Btn6D]) {
			moveLift(-127);
			buff = true;
			} else {
			if (buff) {
				liftHoldPID.set = SensorValue[LiftPot];
			}

			buff = false;

			if(SensorValue[LiftPot] > 900 && PIDToggle){
				liftHoldPID.cur = SensorValue[LiftPot];
				calcPID(liftHoldPID);
				}else{
				liftHoldPID.power = 0;
				liftHoldPID.integral = 0;
			}
			moveLift(liftHoldPID.power);
		}

		wait1Msec(20);
	}
}

PID holdPID;

/*
Holds lift at position it is in at time of task starting.
*/
task autonHold() {
	holdPID.kp = 0.4;
	holdPID.ki = 0.1;
	holdPID.dead = 10;
	holdPID.iCap = 10;
	holdPID.tCap = 15;

	holdPID.set = SensorValue[LiftPot];

	while (true) {
		if(SensorValue[LiftPot] > 900){
			holdPID.cur = SensorValue[LiftPot];
			calcPID(holdPID);
			} else {
			holdPID.power = 0;
			holdPID.integral = 0;
		}
		moveLift(holdPID.power);
		wait1Msec(20);
	}
}
