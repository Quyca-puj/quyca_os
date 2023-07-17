#include "task.h"
#include "utils.h"

String Task::to_string() const
{
  return
    "Command: " + String(command) +
    " task type: " + type +
    " time: " + time +
    " period: " + period +
    " emo1: " + emo1 +
    " emo2: " + emo2;
}

Task::Task()
{
  this->opt_args = nullptr;
  strcmp(this->command,EMPTY_STRING);
  this->ack = -1;
  strcmp(this->emo1,EMPTY_STRING);
  strcmp(this->emo2,EMPTY_STRING);
  this->speed = -1;
  this->time = -1;
  this->period = -1;
}

Task::Task(String command, int ack)
{
  this->opt_args = nullptr;
  command.toCharArray(this->command, BUFFER_SIZE);
  this->ack = ack;
}

void movementTask(Task* task, String cmd, String* args) {
  task->type = TaskType::MOVEMENT;
  if (args[0].equals(EMPTY_PARAM))
  {
    task->speed = config.get(ConfigOptions::SPEED);
  }
  else
  {
    task->speed = args[0].toInt();
  }
  if (Action::isMvtTimed(cmd))
  {
    task->time = args[1].toInt();
  }
}

void emotionTask(Task* task, String cmd, String* args) {
  task->type = TaskType::EMOTION;
  if (cmd.equals(EMOTION_SWITCH))
  {
    args[0].toCharArray(task->emo1, BUFFER_SIZE);
    args[1].toCharArray(task->emo2, BUFFER_SIZE);
    task->time = args[2].toInt();
    task->period = args[3].toInt();
  }
  else if (cmd.equals(EMOTION_STR))
  {
    args[0].toCharArray(task->emo1, BUFFER_SIZE);
  }
}

void customTask(Task* task, String cmd, String* args, int currentArgs) {
  task->type = TaskType::CUSTOM;
  if (currentArgs > 1)
  {
    if (args[0].equals(EMPTY_PARAM))
    {
      task->speed = config.get(ConfigOptions::SPEED);
    }
    else
    {
      task->speed = args[0].toInt();
    }
  }
}

void basicTask(Task* task, String cmd, String* args) {
  task->type = TaskType::BASIC;
  if (cmd.equals(BASIC_CONNECT))
  {
    task->opt_args = new String[2];
    task->opt_args[0] = args[0];
    task->opt_args[1] = args[1];
  }
}

/**
 * Logica para conversion de comandos a tareas nativas. Incluye identificación de tipo de tarea
 */
Task::Task(String msg)
{
  int tabs{0};
  int currentArgs = 0;
  String args[MAX_ARGS] = {};
  String cmd;

  STprint("nuevo task: " + msg);

  for (char index : msg)
  { // recorrer la cadena
    if (isSpace(index))
    { // separar por espacios
      tabs++;
    }
    else
    {
      switch (tabs)
      {
        case 0: // caso 0 es el id, no se guarda
          break;
        case 1: // caso 1 es el comando
          cmd.concat(index);
          break;
        default: // del 1 en adelante son parametros
          args[tabs - 2].concat(index);
          break;
      }
    }
  }
  currentArgs = tabs - 1;

  if (currentArgs > 0)
  {
    if (Action::isMovement(cmd))
    {
      movementTask(this, cmd, args);
    }
    else if (Action::isEmotion(cmd))
    {
      emotionTask(this, cmd, args);
    }
    else if (Action::isCustom(cmd))
    {
      customTask(this, cmd, args, currentArgs);
    }
    else if (Action::isBasic(cmd))
    {
      basicTask(this, cmd, args);
    }
    else if (Action::isConfig(cmd))
    {
      this->type = TaskType::CONFIG;
      this->opt_args = new String[1];
      this->opt_args[0] = args[0];
    }
    cmd.toCharArray(this->command, BUFFER_SIZE);
    this->ack = args[currentArgs - 1].toInt();
  }

  STprint(this->to_string());
}
