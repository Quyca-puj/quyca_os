#include "task.h"

Task::Task()
{
  this->command = ActionType::UNKNOWN_ACTION;
  this->ack = -1;
  this->emo1 = ActionType::UNKNOWN_ACTION;
  this->emo2 = ActionType::UNKNOWN_ACTION;
  this->speed = -1;
  this->time = -1;
  this->period = -1;
}

Task::Task(String str_command, int ack)
{
  this->command = Action::str_to_enum(str_command);
  this->ack = ack;
}
