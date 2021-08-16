#include "OldRobotBuilder.h"
#include "Robot.h"
#include "RobotBuilder.h"
#include "RobotEngineer.h"
#include <iostream>

int main() {
  RobotBuilder *oldStyleRobot = new OldRobotBuilder();
  auto *robotEngineer = new RobotEngineer(oldStyleRobot);
  robotEngineer->makeRobot();
  Robot *firstRobot = robotEngineer->getRobot();
  std::cout << "Robot Built" << std::endl;
  std::cout << "Robot Head Type: " << firstRobot->getRobotHead() << std::endl;
  std::cout << "Robot Torso Type: " << firstRobot->getRobotTorso() << std::endl;
  std::cout << "Robot Arms Type: " << firstRobot->getRobotArms() << std::endl;
  std::cout << "Robot Legs Type: " << firstRobot->getRobotLegs() << std::endl;
  return 0;
}
