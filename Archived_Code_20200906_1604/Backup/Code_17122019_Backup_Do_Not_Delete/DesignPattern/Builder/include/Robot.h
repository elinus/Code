#ifndef __ROBOT_H__
#define __ROBOT_H__

#include "RobotPlan.h"
#include <string>

class Robot : public RobotPlan {
public:
  void setRobotHead(std::string head) override;
  std::string getRobotHead();
  void setRobotTorso(std::string torso) override;
  std::string getRobotTorso();
  void setRobotArms(std::string arms) override;
  std::string getRobotArms();
  void setRobotLegs(std::string legs) override;
  std::string getRobotLegs();

private:
  std::string robotHead;
  std::string robotTorso;
  std::string robotArms;
  std::string robotLegs;
};

#endif /* __ROBOT_H__ */
