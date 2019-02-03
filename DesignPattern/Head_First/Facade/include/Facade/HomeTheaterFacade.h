#ifndef __HOMETHEATERFACADE_H__
#define __HOMETHEATERFACADE_H__

#include <Facade/Amplifier.h>
#include <Facade/CdPlayer.h>
#include <Facade/DvdPlayer.h>
#include <Facade/PopcornPopper.h>
#include <Facade/Projector.h>
#include <Facade/Screen.h>
#include <Facade/TheaterLights.h>
#include <Facade/Tuner.h>
#include <iostream>
#include <string>

class HomeTheaterFacade {
public:
  HomeTheaterFacade(Amplifier *amp, Tuner *tuner, DvdPlayer *dvd, CdPlayer *cd,
                    Projector *projector, TheaterLights *lights, Screen *screen,
                    PopcornPopper *popper);
  void watchMovie(std::string movie);
  void endMovie();
  void listenToCd(std::string cdTitle);
  void endCd();
  void listenToRadio(double frequency);
  void endRadio();

private:
  Amplifier *amp;
  Tuner *tuner;
  DvdPlayer *dvd;
  CdPlayer *cd;
  Projector *projector;
  TheaterLights *lights;
  Screen *screen;
  PopcornPopper *popper;
};

#endif /* __HOMETHEATERFACADE_H__ */
