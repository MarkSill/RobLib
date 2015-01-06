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

Usage
====
See the wiki for usage.
