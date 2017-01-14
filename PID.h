typedef struct {
	int set;
	int cur;
	float kp;
	float ki;
	float integral;
	int iCap;
	int dead;
	int power;
	int tCap;
} PID;


PID liftHoldPID;

bool buff = false;


void calcPID(PID tPID){
	int error;
	int sign;
	int proportion;

	error = tPID.set - tPID.cur;
	if (fabs(error) > tPID.dead) {
		proportion = error * tPID.kp;

		tPID.integral += error*tPID.ki;
		sign = sgn(tPID.integral);
		tPID.integral = (fabs(tPID.integral)>tPID.iCap) ? sign*tPID.iCap : tPID.integral;

		tPID.power = proportion + tPID.integral;
		sign = sgn(tPID.power);
		tPID.power = (fabs(tPID.power)>tPID.tCap) ? (sign*tPID.tCap) : tPID.power;
	}
}

task lift() {
	bool PIDToggle = false;
	// 0 for when off
	// 0.01 for claw open
	// 0.015 for claw closed
	liftHoldPID.kp = 0.4;
	liftHoldPID.ki = 0.1;
	liftHoldPID.dead = 10;
	liftHoldPID.iCap = 10;
	liftHoldPID.tCap = 15;


	//2770 parallel
	while (true) {
		if (vexRT[Btn7D])
			PIDToggle = false;
		if (vexRT[Btn7U])
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
