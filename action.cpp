#import "action.h"

ActionType Action::str_to_enum(String str) {

  ActionType ret = ActionType::UNKNOWN_ACTION;

  if (str.equals("emotions"))
	ret = ActionType::EMOTION_STR;
  else if (str.equals("s_emotions"))
	ret = ActionType::EMOTION_SWITCH;
  else if (str.equals("off_emotions"))
	ret = ActionType::EMOTION_OFF;

  else if (str.equals("very_happy"))
	ret = ActionType::EMOTION_VERYHAPPY;
  else if (str.equals("happy"))
	ret = ActionType::EMOTION_HAPPY;
  else if (str.equals("neutral"))
	ret = ActionType::EMOTION_NEUTRAL;
  else if (str.equals("sad"))
	ret = ActionType::EMOTION_SAD;
  else if (str.equals("very_sad"))
	ret = ActionType::EMOTION_VERYSAD;
  else if (str.equals("angry"))
	ret = ActionType::EMOTION_ANGRY;
  else if (str.equals("sick"))
	ret = ActionType::EMOTION_SICK;
  else if (str.equals("surprised"))
	ret = ActionType::EMOTION_SURPRISED;
  else if (str.equals("off"))
	ret = ActionType::EMOTION_STOP;

  else if (str.equals("forward"))
	ret = ActionType::MVT_FORWARD;
  else if (str.equals("left"))
	ret = ActionType::MVT_LEFT;
  else if (str.equals("right"))
	ret = ActionType::MVT_RIGHT;
  else if (str.equals("t_forward"))
	ret = ActionType::MVT_TIMEDFORWARD;
  else if (str.equals("t_reverse"))
	ret = ActionType::MVT_TIMEDREVERSE;
  else if (str.equals("t_left"))
	ret = ActionType::MVT_TIMEDLEFT;
  else if (str.equals("t_right"))
	ret = ActionType::MVT_TIMEDRIGHT;
  else if (str.equals("roll"))
	ret = ActionType::MVT_ROLL;
  else if (str.equals("reverse_roll"))
	ret = ActionType::MVT_REVERSEROLL;
  else if (str.equals("stop_all"))
	ret = ActionType::BASIC_STOP_ALL;

  else if (str.equals("stop_mvt"))
	ret = ActionType::BASIC_STOP_MVT;
  else if (str.equals("calibration"))
	ret = ActionType::BASIC_CALIB;
  else if (str.equals("connect"))
	ret = ActionType::BASIC_CONNECT;
  else if (str.equals("offset_izq"))
	ret = ActionType::CFG_OFFSET_IZQ;
  else if (str.equals("offset_der"))
	ret = ActionType::CFG_OFFSET_DER;
  return ret;
}

bool Action::isConfig(ActionType command) {
  return CFG_OFFSET_DER == command
	  || CFG_OFFSET_IZQ == command;
}

bool Action::isMovement(ActionType command) {
  return MVT_FORWARD == command
	  || MVT_LEFT == command
	  || MVT_RIGHT == command
	  || MVT_ROLL == command
	  || MVT_REVERSEROLL == command
	  || isMvtTimed(command);
}

bool Action::isMvtTimed(ActionType command) {
  return MVT_TIMEDFORWARD == command
	  || MVT_TIMEDREVERSE == command
	  || MVT_TIMEDLEFT == command
	  || MVT_TIMEDRIGHT == command;
}

bool Action::isEmotion(ActionType command) {
  return EMOTION_STR == command
	  || EMOTION_SWITCH == command
	  || EMOTION_OFF == command;
}

bool Action::isBasic(ActionType command) {
  return BASIC_STOP_ALL == command
	  || BASIC_CALIB == command
	  || BASIC_STOP_MVT == command
	  || BASIC_CONNECT == command;
}

bool Action::isCustom(ActionType command) {
  // return command.equals() || command.equals()...;
  return false;
}
