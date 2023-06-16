#include "active_task.h"
#include "action.h"

ActiveTask::ActiveTask()
{
  this->command = ActionType::UNKNOWN_ACTION;
  this->ack = -1;
}

ActiveTask::ActiveTask(ActionType command, int ack)
{
  this->command = command;
  this->ack = ack;
}
