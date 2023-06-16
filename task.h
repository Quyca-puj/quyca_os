#ifndef TASK_H_
#define TASK_H_

#include <Arduino.h>

#include "action.h"
#include "config.h"
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
    ActionType command;
    TaskType type;
    long speed;
    long time;
    long period;
    ActionType emo1;
    ActionType emo2;
    int ack;

    Task(String command, int ack);
    Task();
};

#endif
