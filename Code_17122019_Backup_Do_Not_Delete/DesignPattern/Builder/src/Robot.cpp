#include "Robot.h"

void Robot::setRobotHead(std::string head) { robotHead = head; }

std::string Robot::getRobotHead() { return robotHead; }

void Robot::setRobotTorso(std::string torso) { robotTorso = torso; }

std::string Robot::getRobotTorso() { return robotTorso; }

void Robot::setRobotArms(std::string arms) { robotArms = arms; }

std::string Robot::getRobotArms() { return robotArms; }

void Robot::setRobotLegs(std::string legs) { robotLegs = legs; }

std::string Robot::getRobotLegs() { return robotLegs; }
