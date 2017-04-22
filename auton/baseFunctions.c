/*
Calibrates gyroscope in pre-auton. Includes button interrupt in case robot restarts during drive.
*/
void calibrate() {
 //Completely clear out any previous sensor readings by setting the port to "sensorNone"
 SensorType[in7] = sensorNone;
 wait1Msec(1000);
 //Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
 SensorType[in7] = sensorGyro;
 wait1Msec(2000);
}

/*
zeros encoder values
*/
void zeroEncoders () {
	SensorValue[LQuad] = 0;
	SensorValue[RQuad] = 0;
}

/*
Basic function to move straight in auton. Includes deceleration curve.

@param ticks: the number of encoder ticks to move
@param direction: FORWARD/BACKWARD, the direction in which to move.
@param speed: the amount of power to apply to each motor (optional, default 100).
*/

void move (int ticks, int direction, int speed) {
	int BRAKE_SPEED = 50;
	int BRAKE_TIME = 40;

	zeroEncoders();

	int left = abs(SensorValue[LQuad]);
	int right = abs(SensorValue[RQuad]);

	int start = nPgmTime;

	moveDrive(direction * speed, direction * speed);

	while ((left < 0.7 * ticks) && (right < 0.7 * ticks)) {
		left = abs(SensorValue[LQuad]);
		right = abs(SensorValue[RQuad]);

		if(nPgmTime - start > 5000) break;

		wait1Msec(20);
	}

	speed /= 3; // first deceleration

	while ((left < ticks) && (right < ticks)) {
		left = abs(SensorValue[LQuad]);
		right = abs(SensorValue[RQuad]);

		wait1Msec(20);
	}

	moveDrive(0, 0);
}


void moveKill (int ticks, int direction, int killTime, int speed) {
	int BRAKE_SPEED = 50;
	int BRAKE_TIME = 40;
	int timeElapsed = 0;
	zeroEncoders();

	int left = abs(SensorValue[LQuad]);
	int right = abs(SensorValue[RQuad]);
	int time = 0;

	moveDrive(direction * speed, direction * speed);

	while ((left < 0.7 * ticks) && (right < 0.7 * ticks) && time < killTime) {
		left = abs(SensorValue[LQuad]);
		right = abs(SensorValue[RQuad]);

		wait1Msec(20);
		time += 20;
	}

	speed /= 3; // first deceleration

	while ((left < ticks) && (right < ticks) && time < killTime) {
		left = abs(SensorValue[LQuad]);
		right = abs(SensorValue[RQuad]);

		wait1Msec(20);
		time += 20;
	}

	moveDrive(0, 0);
}

/*
Basic function to do a point turn.

@param degrees: the number of degrees to turn
@param direction: the direction in which to turn (CLOCKWISE/COUNTERCLOCKWISE)
@param speed: the amount of power to give each motor (default 80)
*/
void rotate (float degrees, int direction, int speed) {
	int DECEL_ANGLE = 30;
	int BRAKE_SPEED = 30;

	SensorValue[Gyro] = 0;
	while(abs(SensorValue[Gyro]) < (degrees -  DECEL_ANGLE) * 10) {
		moveDrive((direction * speed), (-direction * speed));
		wait1Msec(20);
	}

	// decelerate down to 30% of original speed
	while (abs(SensorValue[Gyro]) < degrees * 10) {
		moveDrive((0.6 * direction * speed), (0.6 * -direction * speed));
		wait1Msec(20);
	}

	// brake
	moveDrive((-direction * BRAKE_SPEED), (direction * BRAKE_SPEED));
	wait1Msec(100);
	zeroEncoders();
	moveDrive(0, 0);
}

void encoderRotate (int ticks, int direction) {
	zeroEncoders();
	while (abs(SensorValue[RQuad]) < 0.8 * ticks && abs(SensorValue[LQuad]) < 0.8 * ticks) {
		moveDrive(127 * direction, -127 * direction);
		wait1Msec(20);
	}

	while (abs(SensorValue[RQuad]) < ticks && abs(SensorValue[LQuad]) < ticks) {
		moveDrive(70 * direction, -70 * direction);
		wait1Msec(20);
	}

	moveDrive(-30 * direction, 30 * direction);
	wait1Msec(50);
	moveDrive(0, 0);
}

void brake(int direction) {
	moveDrive(-30 * direction, -30 * direction);
	wait1Msec(50);
	moveDrive(0, 0);
}
