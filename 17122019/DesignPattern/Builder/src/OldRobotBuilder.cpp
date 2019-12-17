#include "OldRobotBuilder.h"

OldRobotBuilder::OldRobotBuilder() { robot = new Robot(); }

OldRobotBuilder::~OldRobotBuilder() { delete robot; }

void OldRobotBuilder::buildRobotHead() { robot->setRobotHead("Tin Head"); }

void OldRobotBuilder::buildRobotTorso() { robot->setRobotTorso("Tin Torso"); }

void OldRobotBuilder::buildRobotArms() {
  robot->setRobotArms("Blowtorch Arms");
}

void OldRobotBuilder::buildRobotLegs() { robot->setRobotLegs("Rollar Skates"); }

Robot *OldRobotBuilder::getRobot() { return robot; }
