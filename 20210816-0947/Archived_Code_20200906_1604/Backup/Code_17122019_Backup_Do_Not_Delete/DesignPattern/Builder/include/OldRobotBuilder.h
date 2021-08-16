#ifndef __OLDROBOTBUILDER_H__
#define __OLDROBOTBUILDER_H__

#include "RobotBuilder.h"

class OldRobotBuilder : public RobotBuilder {
public:
  OldRobotBuilder();
  ~OldRobotBuilder() override;
  void buildRobotHead() override;
  void buildRobotTorso() override;
  void buildRobotArms() override;
  void buildRobotLegs() override;
  Robot *getRobot() override;

public:
  Robot *robot;
};

#endif /* __OLDROBOTBUILDER_H__ */
