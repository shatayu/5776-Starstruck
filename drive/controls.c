typedef struct {
	int lift;
	int LDrive;
	int RDrive;
	int claw;
	int transmissionOn;
	int transmissionOff;
	int liftUp;
	int liftDown;
	int PIDOn;
	int PIDOff;
} Controls;

Controls c;

bool partnerControl = false;

task controls() {
	while (true) {
		if (!partnerControl) {
			c.LDrive = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch3Xmtr2];
			c.RDrive = vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch2Xmtr2];
			c.claw = (vexRT[Btn5D] || vexRT[Btn5DXmtr2]);
			c.transmissionOn = (vexRT[Btn8U] || vexRT[Btn8UXmtr2]);
			c.transmissionOff = (vexRT[Btn8D] || vexRT[Btn8DXmtr2]);
			c.liftUp = (vexRT[Btn6U] || vexRT[Btn6UXmtr2]);
			c.liftDown = (vexRT[Btn6D] || vexRT[Btn6DXmtr2]);
			c.PIDOn = (vexRT[Btn7U] || vexRT[Btn7UXmtr2]);
			c.PIDOff = (vexRT[Btn7D] || vexRT[Btn7DXmtr2]);
		} else {
			c.LDrive = vexRT[Ch3] + vexRT[Ch1];
			c.RDrive = vexRT[Ch3] - vexRT[Ch1];
			c.claw = vexRT[Btn5D];
			c.transmissionOn = vexRT[Btn8U];
			c.transmissionOff = vexRT[Btn8D];
			c.liftUp = vexRT[Btn6U];
			c.liftDown = vexRT[Btn6D];
			c.PIDOn = vexRT[Btn7U];
			c.PIDOff = vexRT[Btn7D];
		}
		wait1Msec(20);

		if (vexRT[Btn7L])
			partnerControl = true;

		if (vexRT[Btn7R])
			partnerControl = false;
	}
}
