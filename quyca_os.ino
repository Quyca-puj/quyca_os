#include "Robot.h"

bool Robot::isFeasibleCustom(Task *msg)
{
  bool toRet = false;
  /*
    if(msg.command.equals("macro")){
      toRet = motorInactive || isMvtExpropiative;
    } else if (msg.command.equals("t1")){
      toRet = screenInactive || isEmoExpropiative;
    } else if (msg.command.equals("t2")){
      toRet = (screenInactive || isEmoExpropiative) && (motorInactive || isMvtExpropiative;);
    }
  */
  return toRet;
}

void Robot::checkCustomCommands(WiFiClient client)
{
  /*
    if(msg.equals("macro") || (checkStatus && activeMacro)){
      macro();
    }
  */
  return;
}

Robot robot;
bool rec_flag = false;

void setup()
{
  robot.setupRobot(115200, "morado");
}

void loop()
{
  WiFiClient client = wifiServer.available();
  String messages = "";
  if (client)
  {
    while(client.connected())
    {
      while (client.available() > 0)
      {
        char c = client.read();
        messages.concat(c);
        rec_flag = true;
      }

      if (!messages.indexOf(robot.alias) || (messages.equals("") && robot.isInAction()))
      {
        robot.processMsg(messages, !rec_flag);
        messages = "";
        rec_flag = false;
      }
      robot.processTasks(client);
    }
    Serial.println("Client Disconnected");
    client.stop();
  }else if (robot.isInAction()){
    robot.processTasks(client);
  }
}
