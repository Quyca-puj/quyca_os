#ifndef ACTION_H_
#define ACTION_H_

#include <Arduino.h>
#include "RobotConstants.h"

enum ActionType {
	BASIC_STOP_ALL,
	BASIC_CALIB,
	BASIC_STOP_MVT,
	BASIC_CONNECT,

	MVT_FORWARD,
	MVT_LEFT,
	MVT_RIGHT,
	MVT_ROLL,
	MVT_REVERSEROLL,
	MVT_TIMEDFORWARD,
	MVT_TIMEDREVERSE,
	MVT_TIMEDLEFT,
	MVT_TIMEDRIGHT,

	EMOTION_STR,
	EMOTION_SWITCH,
	EMOTION_OFF,
	EMOTION_VERYHAPPY,
	EMOTION_HAPPY,
	EMOTION_NEUTRAL,
	EMOTION_SAD,
	EMOTION_VERYSAD,
	EMOTION_ANGRY,
	EMOTION_SICK,
	EMOTION_SURPRISED,
	EMOTION_STOP,

	CFG_OFFSET_DER,
	CFG_OFFSET_IZQ,

	UNKNOWN_ACTION

};

class Action {
public:
	static bool isConfig(ActionType command);
	static bool isMovement(ActionType command);
	static bool isMvtTimed(ActionType command);
	static bool isEmotion(ActionType command);
	static bool isBasic(ActionType command);
	static bool isCustom(ActionType command);
	static ActionType str_to_enum(String str);
};

#endif
