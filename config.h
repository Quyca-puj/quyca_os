#ifndef ROBOT_CONFIG_H_
#define ROBOT_CONFIG_H_

enum ConfigOptions {
  SPEED,
  SPEED_OFFSET_RIGHT,
  SPEED_OFFSET_LEFT,
};

class RobotConfig {
	int config[3];
public:
	RobotConfig();
	void setDefaults();
	int get(ConfigOptions co);
	void set(ConfigOptions co, int new_value);
};

extern RobotConfig config;
#endif
