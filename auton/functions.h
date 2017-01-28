void calibrate() {
	 SensorType[in2] = sensorNone;

	 for (int i = 0; i < 25; i++) {
	   if (vexRT[Btn8R])
	     return;

	   wait1Msec(20);
	 }

	 SensorType[in2] = sensorGyro;
	 for (int i = 0; i < 100; i++) {
	   if (vexRT[Btn8R])
	     return;

	   wait1Msec(20);
	 }
}

void zeroEncoders () {
	nMotorEncoder[BLDrive] = 0;
	nMotorEncoder[BRDrive] = 0;
}

void move (int ticks, int direction, int speed = 80) {
	int BRAKE_SPEED = 50;
	int BRAKE_TIME = 40;

	zeroEncoders();

	int left = abs(nMotorEncoder[BLDrive]);
	int right = abs(nMotorEncoder[BRDrive]);

	moveDrive(direction * speed, direction * speed);

	while ((left < 0.7 * ticks) && (right < 0.7 * ticks)) {
		left = abs(nMotorEncoder[BLDrive]);
		right = abs(nMotorEncoder[BRDrive]);

		wait1Msec(10);
	}

	speed /= 3;

	while ((left < ticks) && (right < ticks)) {
		left = abs(nMotorEncoder[BLDrive]);
		right = abs(nMotorEncoder[BRDrive]);

		wait1Msec(10);
	}


	// brake
	moveDrive(-direction * BRAKE_SPEED, -direction * BRAKE_SPEED);
	wait1Msec(BRAKE_TIME);
	moveDrive(0, 0);
}

/* do not rotate less than 20 degrees; decel kicks in at 20 degrees
- turns slightly more than directed
-turning at 84.9 degrees is a 90 degree turn
*/
void rotate (float degrees, int direction, int SPEED = 100) {
	int DECEL_ANGLE = 30;
	int BRAKE_SPEED = 30;

	SensorValue[Gyro] = 0;
	while(abs(SensorValue[Gyro]) < (degrees -  DECEL_ANGLE) * 10) {
		moveDrive((direction * SPEED), (-direction * SPEED));
		wait1Msec(20);
	}

	while (abs(SensorValue[Gyro]) < degrees * 10) {
		moveDrive((0.3 * direction * SPEED), (0.3 * -direction * SPEED));
		wait1Msec(20);
	}

	// brake
	moveDrive((-direction * BRAKE_SPEED), (direction * BRAKE_SPEED));
	wait1Msec(100);
	zeroEncoders();
	moveDrive(0, 0);
}

PID liftPID;

/* makes the following assumptions:
-higher gyro value = lift is physically higher
-powering lift with positive number moves it upward, negative number moves it downward
*/
void autonLiftUp (int angle) {
	stopTask(autonHold);
	int speed = 120;

	while (SensorValue[LiftPot] < angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

void autonLiftDown (int angle) {
	int speed = -120;

	while (SensorValue[LiftPot] > angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

task deploy() {
	autonLiftUp(1900);
	wait1Msec(150);
	clawState(OPEN);
	wait1Msec(150);
	autonLiftDown(750);
	stopTask(deploy);
}


void hang () {
	/*
	-align
	-lift up
	-stop lifting
	-drive forward
	-lift down (while driving forward)
	-engage transmission
	-keep lifting down and driving forward until desired height is reached
	*/
	clearTimer(T1);
	while (time1[T1] < 5000) {
		zeroEncoders();
		while (SensorValue[LiftPot] < 3400) {
			moveLift(127);
		}

		moveDrive(127, 127);
		moveLift(-127);
		while (SensorValue[LiftPot] > 2610) {
			wait1Msec(20);
		}

		transmissionState(1);

		while (SensorValue[LiftPot] > 1400) {
			wait1Msec(20);
		}

		moveLift(0);
		moveDrive(0, 0);
		break;
	}
}

task launch() {
	while (SensorValue[LiftPot] < 2300) {
		moveLift(127);
		wait1Msec(20);
	}
	moveLift(0);
	stopTask(launch);
}

task reset() {
	while (SensorValue[LiftPot] > 750) {
		moveLift(-127);
		wait1Msec(20);
	}
	moveLift(0);
	stopTask(reset);
}
