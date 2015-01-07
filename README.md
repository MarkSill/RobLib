RobLib
======

A library meant for making ROBOTC programs more easily.

Functions
====
`void setup(struct intArray drive, int numDrive, struct intArray turnl, struct intArray turnr, int numTurn, bool turndrive)`:
Setups the library using specified parameters.

`void moveAll(int value)`:
Turns drive motors with the specified speed. Also moves turn motors if turn_acts_as_drive (turndrive) is true.

`void rstopAll()`:
Stops all motors (stopAll seems to be used by ROBOTC).

`void move(int mtr, int value)`:
Moves the specified motor with the specified value.

`void setupServos(arrayInt servoss, arrayInt defaults, int size)`:
Sets up the servos for use.

`void moveServo(int srv, int pos)`:
Moves the specified servo to the specified position.

`void incrementServo(int srv, bool dir)`:
Increments (or decrements) the specified servo.

`void resetServos()`:
Resets the servos to their default positions.

`void resetServo(int srv)`:
Resets the specified servo to its default position.

`void setDebug(bool newVal)`:
Sets the debug variable to the new value.

`void invertBool(bool &toInvert)`:
Inverts the given boolean.

`void debugmsg(char *msg)`:
Sends a message to the output stream.

Usage
====
See the wiki for usage.
