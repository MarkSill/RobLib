RobLib
======

A library meant for making ROBOTC programs more easily.

Functions
====
void setup(struct intArray drive, int numDrive, struct intArray turnl, struct intArray turnr, int numTurn, bool turndrive):
Setups the library using specified parameters.

void moveAll(int value):
Turns drive motors with the specified speed. Also moves turn motors if turn_acts_as_drive (turndrive) is true.

void rstopAll():
Stops all motors (stopAll seems to be used by ROBOTC).

void move(int mtr, int value):
Moves the specified motor with the specified value.

void moveServo(int srv, int pos):
Moves the specified servo to the specified position.

void setDebug(bool newVal):
Sets the debug variable to the new value.

void invertBool(bool &toInvert):
Inverts the given boolean.

void debugmsg(char *msg):
Sends a message to the output stream.

Usage
====
See the wiki for usage.
