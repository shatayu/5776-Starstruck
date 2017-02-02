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

void calcPID(PID tPID);
task lift();
task autonHold();
