typedef struct {
	int lift;
	int LDrive;
	int RDrive;
	int liftUp;
	int liftDown;
	int clawOpen;
	int clawClosed;
	int PIDOn;
	int PIDOff;
} Controls;

Controls c;

bool partnerControl = false;

task controls() {
	while (true) {
		if (!partnerControl) {
			c.LDrive = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch3Xmtr2] + vexRT[Ch1Xmtr2];
			c.RDrive = vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch2Xmtr2] - vexRT[Ch1Xmtr2];
			c.liftUp = (vexRT[Btn5U] || vexRT[Btn5UXmtr2]);
			c.liftDown = (vexRT[Btn5D] || vexRT[Btn5DXmtr2]);
			c.clawOpen = (vexRT[Btn6U] || vexRT[Btn6UXmtr2]);
			c.clawClosed = (vexRT[Btn6D] || vexRT[Btn6DXmtr2]);
			c.PIDOn = (vexRT[Btn7U] || vexRT[Btn7UXmtr2]);
			c.PIDOff = (vexRT[Btn7D] || vexRT[Btn7DXmtr2]);
		} else {
			c.LDrive = vexRT[Ch3] + vexRT[Ch1];
			c.RDrive = vexRT[Ch3] - vexRT[Ch1];
			c.liftUp = vexRT[Btn5U];
			c.liftDown = vexRT[Btn5D];
			c.clawOpen = vexRT[Btn6U];
			c.clawClosed = vexRT[Btn6D];
			c.PIDOn = vexRT[Btn7U];
			c.PIDOff = vexRT[Btn7D];
		}

		if (vexRT[Btn7L])
			partnerControl = true;

		if (vexRT[Btn7R])
			partnerControl = false;

		wait1Msec(20);
	}
}
