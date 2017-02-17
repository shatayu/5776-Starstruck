// drive constants
#define FORWARD 1
#define BACKWARD -1
#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1

// lift constants
#define UP 1
#define DOWN -1

// claw constants
#define OPEN 0
#define CLOSED 1

// transmission constants
#define ENGAGED 1
#define DISENGAGED 0

void calibrate();
void zeroEncoders();
void move (int ticks, int direction, int speed = 100);
void rotate (float degrees, int direction, int speed = 80);
//void swing (float degrees, int LPower, int RPower);
void brake(int direction);
void autonLiftUp (int angle);
void autonLiftDown (int angle);
task deploy();

void backFenceLeft();
