#ifndef ACTION_H_
#define ACTION_H_

#include <Arduino.h>
#include "RobotConstants.h"

enum ActionType {
};

class Action {
public:
	static bool isConfig(String command);
	static bool isMovement(String command);
	static bool isMvtTimed(String command);
	static bool isEmotion(String command);
	static bool isBasic(String command);
	static bool isCustom(String command);
};

#endif
