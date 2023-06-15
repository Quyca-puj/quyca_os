#ifndef TASK_H_
#define TASK_H_

#include <Arduino.h>
#include "RobotConstants.h"

enum TaskType {
	NONE,
	MOVEMENT,
	EMOTION,
	CUSTOM,
	BASIC,
	CONFIG
};

struct Task
{
    char command[BUFFER_SIZE];
    TaskType type;
    long speed;
    long time;
    long period;
    char emo1[BUFFER_SIZE];
    char emo2[BUFFER_SIZE];
    int ack;

    Task(String command, int ack);
    Task();
};

#endif
