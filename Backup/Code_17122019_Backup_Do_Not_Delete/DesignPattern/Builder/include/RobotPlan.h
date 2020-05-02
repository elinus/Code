#ifndef __ROBOTPLAN_H__
#define __ROBOTPLAN_H__

#include <string>

class RobotPlan {
public:
  virtual ~RobotPlan() {}
  virtual void setRobotHead(std::string head) = 0;
  virtual void setRobotTorso(std::string torso) = 0;
  virtual void setRobotArms(std::string arms) = 0;
  virtual void setRobotLegs(std::string legs) = 0;
};

#endif /* __ROBOTPLAN_H__ */
