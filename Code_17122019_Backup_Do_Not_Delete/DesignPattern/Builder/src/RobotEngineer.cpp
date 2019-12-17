#include "RobotEngineer.h"

RobotEngineer::RobotEngineer(RobotBuilder *robotBuilder) {
  this->robotBuilder = robotBuilder;
}

Robot *RobotEngineer::getRobot() { return robotBuilder->getRobot(); }

void RobotEngineer::makeRobot() {
  robotBuilder->buildRobotHead();
  robotBuilder->buildRobotTorso();
  robotBuilder->buildRobotArms();
  robotBuilder->buildRobotLegs();
}
