#include "task_list.h"

TaskList::TaskList()
{
  pendingTasks = 0;
}

void TaskList::addNewTask(Task *task)
{
  runningTasks[pendingTasks] = new ActiveTask(task->command, task->ack);
  pendingTasks++;
}

int TaskList::searchAck(ActionType command)
{
  for (int i = 0; i < pendingTasks; i++)
  {
    STprint("searchACK");
    STprint(runningTasks[i]->command);
    STprint(command);
    STprint(runningTasks[i]->command == command);
    if (runningTasks[i]->command == command)
    {
      return runningTasks[i]->ack;
    }
  }
  return -1;
}

void TaskList::removeTask(ActionType task)
{
  int pos = 0;
  for (int i = 0; i < pendingTasks; i++)
  {
    if (runningTasks[i]->command == task)
    {
      pos = i;
    }
  }
  delete(runningTasks[pos]);
  for (int i = pos; i < pendingTasks; i++)
  {
    runningTasks[i] = runningTasks[i + 1];
  }
  pendingTasks--;
}
