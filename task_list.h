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
    Task runningTasks[PARALLEL_CUSTOM_SIZE];

    TaskList();
    void addNewTask(Task const& task);
    int searchAck(String command);
    void removeTask(String task);
    Task pop();
};

#endif
