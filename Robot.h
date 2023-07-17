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
  long mvtTimer;
  long emotionTimer;
  long emotionPeriod;
  int movementRobot;
  String emotion;
  bool shouldAnswer;
  bool isTimedAction;
  int macroStep;
  String emoSwitch;
  bool motorInactive;
  bool screenInactive;
  TaskList runningMvt;
  TaskList runningEmotions;
  TaskList runningCustoms;
  TaskList runningBasics;
  bool isMvtExpropiative;
  bool isEmoExpropiative;
  WiFiClient returnSock;
  // cppQueue taskQueue = cppQueue(sizeof(Task), QUEUE_SIZE, FIFO, false);
  TaskQueue taskQueue;
private:
  // motors
  bool getMotorsStatus();

  // movement
  bool robotForward();
  bool robotTurn(int dir);
  bool robotTimedMove(int dir);
  bool robotTimedTurn(int dir);
  bool robotStopMovement();
  void robotForeverMove(int dir);

  // faces
  bool readFaces(String msg);
  bool readFaces(String msg, WiFiClient);
  bool switchFaces(String emo1, String emo2, long time, long period);

  // task
  bool isFeasible(Task *msg);
  void classifyTask(Task const& task);
  bool processImmediateTask(Task const& task);
  bool isFeasibleMvt(Task *msg);
  bool isFeasibleEmotion(Task *msg);
  bool isFeasibleCustom(Task *msg);
  void unwrapTask(Task const& task);
  Task *msgToTask(String msg);
  void answerCommand(Task* const& task, WiFiClient client);
  void answerPendingByType(TaskList *list, WiFiClient client);

  // process commands
  void processCommands(WiFiClient client);
  void checkEmotionCommands(WiFiClient client);
  void checkCustomCommands(WiFiClient client);
  void robotBasicCommands(WiFiClient client);
  void checkMotorCommands(WiFiClient client);

  void calibration();
  void connectClient(String returnIP, int returnPort);
  void readCustomVariablesMotors(String msg, WiFiClient client);
  void readCustomVariablesSensors(String msg, WiFiClient client);
  void JointServoMsg(String msg, WiFiClient client);
  bool robotDelay(long time, long *timeElapsed);
  void answerAllPending(WiFiClient client);
  void answerPendingList(TaskList *list, WiFiClient client);
public:
  String ip;
  String alias;
  String activeEmo;
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
