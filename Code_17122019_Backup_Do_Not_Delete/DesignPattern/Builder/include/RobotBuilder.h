#ifndef __ROBOTBUILDER_H__
#define __ROBOTBUILDER_H__

#include "Robot.h"

class RobotBuilder {
public:
  virtual ~RobotBuilder() {}
  virtual void buildRobotHead() = 0;
  virtual void buildRobotTorso() = 0;
  virtual void buildRobotArms() = 0;
  virtual void buildRobotLegs() = 0;
  virtual Robot *getRobot() = 0;
};

#endif /* __ROBOTBUILDER_H__ */
