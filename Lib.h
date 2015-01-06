/*
A library for easily creating ROBOTC programs for your robot.
Originally created by Caleb Jeppesen.

Licensed under MIT (see LICENSE).
*/

//constants
bool const DIR_RIGHT = true;
bool const DIR_LEFT = false;
int const MAX_MOTOR_ARRAY_SIZE = 8;

struct arrayInt {
	int array[MAX_MOTOR_ARRAY_SIZE];
	byte arrays_dont_work_in_robotc;
};

void setup(struct arrayInt drive, struct arrayInt turnl, struct arrayInt turnr, bool turndrive);
void moveAll(int value);
void rstopAll();
void turn(bool dir, int value);
void move(int mtr, int value);

bool turn_acts_as_drive = true;

int motors[MAX_MOTOR_ARRAY_SIZE];
int tright[MAX_MOTOR_ARRAY_SIZE];
int tleft[MAX_MOTOR_ARRAY_SIZE];

void setup(struct arrayInt drive, struct arrayInt turnl, struct arrayInt turnr, bool turndrive) {
	turn_acts_as_drive = turndrive;
	motors = drive.array;
	tleft = turnl.array;
	tright = turnr.array;
}

void moveAll(int value) {
	for (int i = 0; i < MAX_MOTOR_ARRAY_SIZE; i++) {
		motor[motors[i]] = value;
	}
	if (turn_acts_as_drive) {
		for (int i = 0; i < MAX_MOTOR_ARRAY_SIZE; i++) {
			motor[tright[i]] = value;
		}
		for (int i = 0; i < MAX_MOTOR_ARRAY_SIZE; i++) {
			motor[tleft[i]] = value;
		}
	}
}

void rstopAll() {
	moveAll(0);
}

void turn(bool dir, int value) {
	if (dir == DIR_RIGHT) {
		for (int i = 0; i < MAX_MOTOR_ARRAY_SIZE; i++) {
			motor[tright[i]] = value;
		}
		for (int i = 0; i < MAX_MOTOR_ARRAY_SIZE; i++) {
			motor[tleft[i]] = -value;
		}
		} else {
		for (int i = 0; i < MAX_MOTOR_ARRAY_SIZE; i++) {
			motor[tright[i]] = -value;
		}
		for (int i = 0; i < MAX_MOTOR_ARRAY_SIZE; i++) {
			motor[tleft[i]] = value;
		}
	}
}

void move(int mtr, int value) {
	motor[mtr] = value;
}
