/*
A library for easily creating ROBOTC programs for your robot.
Originally created by Caleb Jeppesen.

Licensed under MIT (see LICENSE).
*/

bool turn_act_as_drive = true;

bool const DIR_RIGHT = true;
bool const DIR_LEFT = false;

int motors[];
int tright[];
int tleft[];

void setup(int drive[], int turnl[], int turnr[], bool turndrive) {
	turn_act_as_drive = turndrive;
	motors = drive;
	tleft = turnl;
	tright = turnr;
}

void moveAll(int value) {
	for (int i = 0; i < length(motors); i++) {
		motor[motors[i]] = value;
	}
	if (turn_act_as_drive) {
		for (int i = 0; i < length(tright); i++) {
			motor[tright[i]] = value;
		}
		for (int i = 0; i < length(rleft); i++) {
			motor[rleft[i]] = value;
		}
	}
}

void stopAll() {
	moveAll(0);
}

void turn(bool dir, int value) {
	if (dir) {
		for (int i = 0; i < length(tright); i++) {
			motor[tright[i]] = value;
		}
		for (int i = 0; i < length(rleft); i++) {
			motor[tleft[i]] = -value;
		}
	} else {
		for (int i = 0; i < length(tright); i++) {
			motor[tright[i]] = -value;
		}
		for (int i = 0; i < length(tleft); i++) {
			motor[tleft[i]] = value;
		}
	}
}

void move(int mtr, int value) {
	motor[mtr] = value;
}

int length(int[] array) {
	return (sizeof(array)/sizeof(*array));
}