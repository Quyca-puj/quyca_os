#include "task.h"

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

/**
 * Logica para conversion de comandos a tareas nativas. Incluye identificación de tipo de tarea - Va afuera
 */
Task::Task(String msg)
{
  int tabs{0};
  int currentArgs = 0;
  String args[MAX_ARGS] = {};
  String cmd;

  // for (int i = 0; i < MAX_ARGS; i++)
  // { // inicialziacion del arreglo de parametros
  //   args[i] = "";
  // }
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
      this->type = TaskType::MOVEMENT;
      if (args[0].equals(EMPTY_PARAM))
      {
        this->speed = config.get(ConfigOptions::SPEED);
      }
      else
      {
        this->speed = args[0].toInt();
      }
      if (Action::isMvtTimed(cmd))
      {
        this->time = args[1].toInt();
      }
    }
    else if (Action::isEmotion(cmd))
    {
      this->type = TaskType::EMOTION;
      if (cmd.equals(EMOTION_SWITCH))
      {
        args[0].toCharArray(this->emo1, BUFFER_SIZE);
        args[1].toCharArray(this->emo2, BUFFER_SIZE);
        this->time = args[2].toInt();
        this->period = args[3].toInt();
      }
      else if (cmd.equals(EMOTION_STR))
      {
        args[0].toCharArray(this->emo1, BUFFER_SIZE);
      }
    }
    else if (Action::isCustom(cmd))
    {
      this->type = TaskType::CUSTOM;
      if (currentArgs > 1)
      {
        if (args[0].equals(EMPTY_PARAM))
        {
          this->speed = config.get(ConfigOptions::SPEED);
        }
        else
        {
          this->speed = args[0].toInt();
        }
      }
    }
    else if (Action::isBasic(cmd))
    {
      this->type = TaskType::BASIC;
      if (cmd.equals(BASIC_CONNECT))
      {
        this->opt_args = new String[2];
        this->opt_args[0] = args[0];
        this->opt_args[1] = args[1];
      }
    }
    else if (Action::isConfig(cmd))
    {
      this->type = TaskType::CONFIG;
    }
    cmd.toCharArray(this->command, BUFFER_SIZE);
    this->ack = args[currentArgs - 1].toInt();
  }
}
