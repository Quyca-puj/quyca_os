#ifndef TASK_LIST_H_
#define TASK_LIST_H_

#include "RobotConstants.h"
#include "utils.h"
#include "task.h"
#include "active_task.h"


class TaskList
{
public:
    int pendingTasks;
    ActiveTask* runningTasks[PARALLEL_CUSTOM_SIZE];
    TaskList();
    void addNewTask(Task* task);
    int searchAck(ActionType command);
    void removeTask(ActionType task);
};

#endif
