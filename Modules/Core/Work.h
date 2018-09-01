#define _VEX_Work
enum MotorSetting{preSetFront=0,preSetBack=1,
	preSetLeft=2,preSetRight=3,
	ArmMotorSet=4,HandMotorSet=5,
	specialSet=6};

enum CountingSetting{distance=0,time=1,angle=2};

typedef struct {
	bool motorChange;
	bool armChange;
	bool handChange;
} RobotState;
RobotState this;

typedef struct{
	MotorSetting motorNumber;
	CountingSetting countingSetting;
	int difference;
	bool stayWhenFinish;
	//unit is times
	//From -180 to 180 degree
	//unit is ms
	int specialSet[4];
} MovementUnit;

typedef struct {
	MovementUnit movement[4];//May have error
	int length;
} MovementArray;


//Mike's part
//not finish


/****************************************************/

MovementArray* createNewMovementArray(int length);//May have error
MovementArray* AddToMovementArray(MovementArray *oldArray,MovementUnit newUnit);//May have error
MovementUnit* removeFromMovementArray(MovementArray *oldArray,int place);
void movement(int movement,int *array);
void resetmovement(int movement,int *array);
bool checkmovement(int movement);
task movementOprator();
void preSetFrontMove(int *array);
void preSetBackMove(int *array);
void preSetLeftMove(int *array);
void preSetRightMove(int *array);
void ArmMotorUpSet(int *array);
void ArmMotorDownSet(int *array);
void HandMotorUpSet(int *array);
void HandMotorDownSet(int *array);
void specialSetMove(int *array);
int encoderCounter();
int timeCounter();
int angleCounter();
/********************************************************/

struct _CoreState {
	int memorySize;
	int state;//0 not ready, 1 ready to run, 2 stop by heap full
	int freeMemoryCount;
} coreState;
typedef struct _MemoryUnit {
	MovementUnit data;
	int state;//0 not be used, 1 is using, 2 ready to free
} MemoryUnit;


typedef struct _MemoryArray {
	int size;
	int location;
} MemoryArray;

MemoryUnit heap[MEMORY_SIZE];
void init();
void set(MemoryArray* units, MovementUnit unit, int location);
int malloc(MemoryArray* unit, int size);
int free(MemoryArray* unit);
void recomputingMemorySize();
MemoryUnit null;
MovementArray waittingActions;
MovementArray runningActions;
bool isBusy;
bool startMovement(MovementUnit unit);
void stopMovement(MovementUnit unit);