/*
A library for easily creating ROBOTC programs for your robot.
Originally created by Caleb Jeppesen.

Last updated on 1/6/15.

Licensed under MIT (see file LICENSE).
*/

//constants
bool const DIR_RIGHT = true;
bool const DIR_LEFT = false;
int const MAX_MOTOR_ARRAY_SIZE = 8;

//required for passing arrays through functions, as ROBOTC does not support that for some reason
typedef struct {
	int array[MAX_MOTOR_ARRAY_SIZE];
	byte arrays_dont_work_in_robotc;
} arrayInt;

//function declearations
void setup(arrayInt drive, int numDrive, arrayInt turnl, arrayInt turnr, int numTurn, bool turndrive);
void moveAll(int value);
void rstopAll();
void turn(bool dir, int value);
void move(int mtr, int value);
void setDebug(bool newVal);
void invertBool(bool &toInvert);
void debugmsg(char *msg);

//tells the library if the turn motors also can be used for standard drive
bool turn_acts_as_drive = true;
//debug mode
bool debug = false;
//tells the library how many motors to iterate through
int numDriveMotors;
int numTurnMotors;

//motor arrays
int motors[MAX_MOTOR_ARRAY_SIZE];
int tright[MAX_MOTOR_ARRAY_SIZE];
int tleft[MAX_MOTOR_ARRAY_SIZE];

/**
sets up the library
*/
void setup(arrayInt drive, int numDrive, arrayInt turnl, arrayInt turnr, int numTurn, bool turndrive) {
	if (debug) {
		debugmsg("Setting up motors...");
	}
	turn_acts_as_drive = turndrive;
	numDriveMotors = numDrive;
	motors = drive.array;
	tleft = turnl.array;
	tright = turnr.array;
	numTurnMotors = numTurn;
}

//makes all motors decleared as drive motors move
void moveAll(int value) {
	if (debug) {
		debugmsg("Moving all motors...");
	}
	for (int i = 0; i < numDriveMotors; i++) {
		motor[motors[i]] = value;
	}
	if (turn_acts_as_drive) {
		for (int i = 0; i < numTurnMotors; i++) {
			motor[tright[i]] = value;
		}
		for (int i = 0; i < numTurnMotors; i++) {
			motor[tleft[i]] = value;
		}
	}
}

//stops all motors (stopAll seems to be used by ROBOTC)
void rstopAll() {
	if (debug) {
		debugmsg("Stopping motors...");
	}
	moveAll(0);
}

//makes the turn motors move based on either DIR_RIGHT or DIR_LEFT
void turn(bool dir, int value) {
	if (debug) {
		debugmsg("Turning...");
	}
	if (dir == DIR_RIGHT) {
		for (int i = 0; i < numTurnMotors; i++) {
			motor[tright[i]] = value;
		}
		for (int i = 0; i < numTurnMotors; i++) {
			motor[tleft[i]] = -value;
		}
		} else {
		for (int i = 0; i < numTurnMotors; i++) {
			motor[tright[i]] = -value;
		}
		for (int i = 0; i < numTurnMotors; i++) {
			motor[tleft[i]] = value;
		}
	}
}

//makes the specified motor move
void move(int mtr, int value) {
	if (debug) {
		debugmsg("Moving motor...");
	}
	motor[mtr] = value;
}

//TODO: Better servo support

//moves a servo to specified position
void moveServo(int srv, int pos) {
	if (debug) {
		debugmsg("Setting servo position...");
	}
	servo[srv] = pos;
}

//sets the debug value
void setDebug(bool newVal) {
	if (debug) {
		debugmsg("Disabling debug mode...");
	}
	debug = newVal;
	if (debug) {
		debugmsg("Debug mode active!");
	}
}

//inverts a boolean
void invertBool(bool &toInvert) {
	if (debug) {
		debugmsg("Inverting boolean...");
	}
	toInvert = !toInvert;
}

//mainly for internal use, but can be used if you really want to
void debugmsg(char *msg) {
	//char *t = "[DEBUG]: ";
	writeDebugStreamLine(msg);
}
