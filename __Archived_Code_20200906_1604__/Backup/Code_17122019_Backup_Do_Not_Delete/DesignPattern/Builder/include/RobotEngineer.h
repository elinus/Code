#ifndef __ROBOTENGINEER_H__
#define __ROBOTENGINEER_H__

#include "Robot.h"
#include "RobotBuilder.h"

class RobotEngineer {
public:
  RobotEngineer(RobotBuilder *robotBuilder);
  Robot *getRobot();
  void makeRobot();

private:
  RobotBuilder *robotBuilder;
};

#endif /* __ROBOTENGINEER_H__ */
