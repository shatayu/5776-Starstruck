struct Controls {
	int leftDrive;
	int rightDrive;
	int liftUp;
	int liftDown;
	int liftLimit;
	int transmission;
	int claw;
	int hang;
};

Controls c;

task initializeControls {
	while (true) {
		// arcade drive
		c.leftDrive = vexRT[Ch3] + vexRT[Ch1];
		c.rightDrive = vexRT[Ch3] - vexRT[Ch1];

		// tank drive
		//c.leftDrive = vexRT[Ch2];
		//c.rightDrive = vexRT[Ch3];

		c.liftUp = vexRT[Btn6U];
		c.liftDown = vexRT[Btn6D];
		c.claw = vexRT[Btn5D];
		c.hang = vexRT[Btn8R];

		wait1Msec(20);
	}
}
