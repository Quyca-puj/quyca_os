#ifndef ROBOT_H_
#define ROBOT_H_

#include "nodeWiFi.h"
#include "RobotConstants.h"
#include "motorMovementController.h"
#include "FacesLed.h"
#include "utils.h"
#include "JointExtra.h"
#include "config.h"

#include "wifi_config.h"
#include "task.h"
#include "task_list.h"
#include "task_queue.h"

#include "wifi_config.h"

#include "action.h"

class Robot
{
  RobotConfig rc;

  int currentArgs;
  bool movementCurrentState;
  ActionType command;
  long mvtTimer;
  long emotionTimer;
  long emotionPeriod;
  int movementRobot;
  String arguments[MAX_ARGS];
  ActionType emotion;
  bool shouldAnswer;
  bool isTimedAction;
  int macroStep;
  ActionType emoSwitch;
  bool motorInactive;
  bool screenInactive;
  TaskList runningMvt;
  TaskList runningEmotions;
  TaskList runningCustoms;
  TaskList runningBasics;
  bool isMvtExpropiative;
  bool isEmoExpropiative;
  WiFiClient returnSock;
  int returnPort;
  String returnIP;
  // cppQueue taskQueue = cppQueue(sizeof(Task), QUEUE_SIZE, FIFO, false);
  TaskQueue taskQueue;
private:
  // motors
  bool getMotorsStatus();
  void checkMotorCommands(ActionType msg, bool checkStatus, WiFiClient client);

  // movement
  bool robotForward();
  bool robotTurn(int dir);
  bool robotTimedMove(int dir);
  bool robotTimedTurn(int dir);
  bool robotStopMovement();
  void robotForeverMove(int dir);

  // faces
  bool readFaces(ActionType msg);
  bool readFaces(ActionType msg, WiFiClient);
  bool switchFaces(ActionType emo1, ActionType emo2, long time, long period);

  // task
  bool isFeasible(Task *msg);
  bool isFeasibleMvt(Task *msg);
  bool isFeasibleEmotion(Task *msg);
  bool isFeasibleCustom(Task *msg);
  void unwrapTask(Task *task);
  Task *msgToTask(String msg);
  void answerCommand(TaskList *list, ActionType task, WiFiClient client);
  void answerPendingByType(TaskList *list, WiFiClient client);


  void calibration();
  void connectClient();
  void checkEmotionCommands(ActionType msg, bool checkStatus, WiFiClient client);
  void checkCustomCommands(ActionType msg, bool checkStatus, WiFiClient client);
  void robotBasicCommands(ActionType msg, bool checkStatus, WiFiClient client);
  void readCustomVariablesMotors(String msg, WiFiClient client);
  void readCustomVariablesSensors(String msg, WiFiClient client);
  void JointServoMsg(String msg, WiFiClient client);
  void processCommands(ActionType msg, bool checkStatus, WiFiClient client);
  bool robotDelay(long time, long *timeElapsed);
  void answerAllPending(WiFiClient client);
public:
  String ip;
  String alias;
  ActionType activeEmo;
  long mvtTimeElapsed;
  long emoTimeElapsed;
  long emoAuxTimeElapsed;
  long customTimeElapsed;
  bool inAction;
  bool reverseActive;
  bool forwardActive;
  bool rightActive;
  bool leftActive;
  bool isInAction();
  Robot();
  void setupRobot(int serial, String givenAlias);
  void processMsg(String msg, bool checkStatus);
  void processTasks(bool checkStatus, WiFiClient client);
  bool adelante_atras();
  bool tuntun();
  bool cuadrado();
  bool popurri();
};
#endif
