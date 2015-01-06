/*
A library for easily creating ROBOTC programs for your robot.
Originally created by Caleb Jeppesen.

Licensed under MIT (see LICENSE).
*/

//constants
bool const DIR_RIGHT = true;
bool const DIR_LEFT = false;
int const MAX_MOTOR_ARRAY_SIZE = 8;

//required for passing arrays through functions, as ROBOTC does not support that for some reason
struct arrayInt {
	int array[MAX_MOTOR_ARRAY_SIZE];
	byte arrays_dont_work_in_robotc;
};

//function declearations
void setup(struct arrayInt drive, struct arrayInt turnl, struct arrayInt turnr, bool turndrive);
void moveAll(int value);
void rstopAll();
void turn(bool dir, int value);
void move(int mtr, int value);

//tells the library if the turn motors also can be used for standard drive
bool turn_acts_as_drive = true;
//tells the library how many motors to iterate through
int numDriveMotors;
int numTurnMotors;

//motor arrays
int motors[MAX_MOTOR_ARRAY_SIZE];
int tright[MAX_MOTOR_ARRAY_SIZE];
int tleft[MAX_MOTOR_ARRAY_SIZE];

//sets up the library
void setup(struct arrayInt drive, int numDrive, struct arrayInt turnl, struct arrayInt turnr, int numTurn, bool turndrive) {
	turn_acts_as_drive = turndrive;
	numDriveMotors = numDrive;
	motors = drive.array;
	tleft = turnl.array;
	tright = turnr.array;
	numTurnMotors = numTurn;
}

//makes all motors decleared as drive motors move
void moveAll(int value) {
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
	moveAll(0);
}

//makes the turn motors move based on either DIR_RIGHT or DIR_LEFT
void turn(bool dir, int value) {
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
	motor[mtr] = value;
}
