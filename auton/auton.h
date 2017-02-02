// drive constants
#define FORWARD 1
#define BACKWARD -1
#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1
//#define LEFT 1
//#define RIGHT -1

// lift constants
#define UP 1
#define DOWN -1

// claw constants
#define OPEN 0
#define CLOSED 1

void calibrate();
void zeroEncoders();
//void move (int ticks, int direction);
//void rotate (float degrees, int direction);
void autonLiftUp (int angle);
void autonLiftDown (int angle);
task deploy();

void backFenceLeft();
