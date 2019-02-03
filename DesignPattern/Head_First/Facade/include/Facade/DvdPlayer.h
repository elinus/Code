#ifndef __DVDPLAYER_H__
#define __DVDPLAYER_H__

#include <Facade/Amplifier.h>
#include <iostream>
#include <string>

class Amplifier;

class DvdPlayer {
public:
  DvdPlayer(std::string description, Amplifier *amplifier);
  void on();
  void off();
  void eject();
  void play(std::string movie);
  void play(int track);
  void stop();
  void pause();
  void setTwoChannelAudio();
  void setSurroundAudio();
  std::string toString();

private:
  std::string description;
  int currentTrack;
  Amplifier *amplifier;
  std::string movie;
};

#endif /* __DVDPLAYER_H__ */
