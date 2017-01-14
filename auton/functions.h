void calibrate() {
	 SensorType[Gyro] = sensorNone;
	 wait1Msec(500);

	 SensorType[Gyro] = sensorGyro;
	 wait1Msec(2000);
}

void zeroEncoders () {
	nMotorEncoder[BLDrive] = 0;
	nMotorEncoder[BRDrive] = 0;
}

void move (int ticks, int direction) {
	zeroEncoders();
	int speed = 120;

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
void rotate (float degrees, int direction) {
	int speed = 110;
	int decelAngle = 30;

	SensorValue[Gyro] = 0;
	while(abs(SensorValue[Gyro]) < (degrees -  decelAngle) * 10) {
		moveDrive((direction * speed), (-direction * speed));
		wait1Msec(20);
	}

	while (abs(SensorValue[Gyro]) < degrees * 10) {
		moveDrive((0.5 * direction * speed), (0.5 * -direction * speed));
		wait1Msec(20);
	}

	// brake
	moveDrive((-direction * BRAKE_SPEED), (direction * BRAKE_SPEED));
	wait1Msec(100);
	zeroEncoders();
}

void hang () {
	//liftHang();
	moveDrive(127, 127);
	wait1Msec(250);
	moveLift(-127);
	wait1Msec(250);
	transmissionState(1);
	wait1Msec(1800); // duration of hang

	moveLift(0);

	moveDrive(15, 15); // stall torque
	wait1Msec(700);

	moveDrive(0, 0);
}

/* makes the following assumptions:
-higher gyro value = lift is physically higher
-powering lift with positive number moves it upward, negative number moves it downward
*/

void autonLiftUp (int angle) {
	int speed = 120;
	while (SensorValue[LiftPot] < 0.8 * angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	speed /= 2;
	while (SensorValue[LiftPot] < 0.9 * angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	speed = speed*2/3;
	while (SensorValue[LiftPot] < angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

void autonLiftDown (int angle) {
	int speed = -120;
	while (SensorValue[LiftPot] > 1.2 * angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	speed /= 2;
	while (SensorValue[LiftPot] > 1.1 * angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	speed /= 2;
	while (SensorValue[LiftPot] > angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

void deploy() {
	autonLiftUp(2000);
	clawState(OPEN);
	autonLiftDown(750);
	wait1Msec(500);
	clawState(CLOSED);
}
