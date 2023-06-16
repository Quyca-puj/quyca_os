#import "action.h"

bool Action::isConfig(String command)
{
	return command.equals(CFG_OFFSET_DER)
		|| command.equals(CFG_OFFSET_IZQ)
		;
}

bool Action::isMovement(String command)
{
  return command.equals(MVT_FORWARD)
	  || command.equals(MVT_LEFT)
	  || command.equals(MVT_RIGHT)
	  || command.equals(MVT_ROLL)
	  || command.equals(MVT_REVERSEROLL)
	  || isMvtTimed(command)
	  ;
}

bool Action::isMvtTimed(String command)
{
  return command.equals(MVT_TIMEDFORWARD)
	  || command.equals(MVT_TIMEDREVERSE)
	  || command.equals(MVT_TIMEDLEFT)
	  || command.equals(MVT_TIMEDRIGHT)
	  ;
}

bool Action::isEmotion(String command)
{
  return command.equals(EMOTION_STR)
	  || command.equals(EMOTION_SWITCH)
	  || command.equals(EMOTION_OFF)
	  ;
}

bool Action::isBasic(String command)
{
  return command.equals(BASIC_STOP_ALL)
	  || command.equals(BASIC_CALIB)
	  || command.equals(BASIC_STOP_MVT)
	  || command.equals(BASIC_CONNECT)
	  ;
}

bool Action::isCustom(String command)
{
  // return command.equals() || command.equals()...;
  return false;
}
