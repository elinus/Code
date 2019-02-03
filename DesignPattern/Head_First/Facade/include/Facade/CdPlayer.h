#ifndef __CDPLAYER_H__
#define __CDPLAYER_H__

#include <Facade/Amplifier.h>
#include <iostream>
#include <string>

class Amplifier;

class CdPlayer {
public:
  CdPlayer(std::string description, Amplifier *amplifier);
  void on();
  void off();
  void eject();
  void play(std::string title);
  void play(int track);
  void stop();
  void pause();
  std::string toString();

private:
  std::string description;
  int currentTrack;
  Amplifier *amplifier;
  std::string title;
};

#endif /* __CDPLAYER_H__ */
