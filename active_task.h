#ifndef ACTIVE_TASK_H_
#define ACTIVE_TASK_H_

#include <Arduino.h>
#include "RobotConstants.h"
#include "action.h"

class ActiveTask
{
public:
    ActionType command;
    int ack;
    ActiveTask(ActionType command, int ack);
    ActiveTask();
};

#endif
