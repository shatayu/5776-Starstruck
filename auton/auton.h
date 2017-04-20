// drive constants
#define FORWARD 1
#define BACKWARD -1
#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1

void calibrate();
void zeroEncoders();
void move (int ticks, int direction, int speed = 100);
void rotate (float degrees, int direction, int speed = 80);
void brake (int direction);
void autonLiftUp (int angle);
void autonLiftDown (int angle);

float getVelocity();

task halfOpenClaw();
task openClaw();
task liftLaunch();


//void backFenceLeft();
