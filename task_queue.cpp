#include "task_queue.h"

bool TaskQueue::isEmpty(){
  return pendingTasks < 1 ;
}

TaskQueue::TaskQueue(){
  pendingTasks = 0;
}

void TaskQueue::push(Task task){
  runningTasks[pendingTasks] = task;
  pendingTasks++;
}

Task* TaskQueue::peekPrevious(){
  return &runningTasks[0];
}

Task TaskQueue::pop(){
  Task task = runningTasks[0];

  for (int i = 0; i < pendingTasks; i++)
  {
    runningTasks[i] = runningTasks[i + 1];
  }

  pendingTasks--;

  return task;
}
