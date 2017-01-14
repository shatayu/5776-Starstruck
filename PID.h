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
