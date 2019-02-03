#include <Facade/HomeTheaterFacade.h>

HomeTheaterFacade::HomeTheaterFacade(Amplifier *amp, Tuner *tuner,
                                     DvdPlayer *dvd, CdPlayer *cd,
                                     Projector *projector,
                                     TheaterLights *lights, Screen *screen,
                                     PopcornPopper *popper) {
  this->amp = amp;
  this->tuner = tuner;
  this->dvd = dvd;
  this->cd = cd;
  this->projector = projector;
  this->lights = lights;
  this->screen = screen;
  this->popper = popper;
}

void HomeTheaterFacade::watchMovie(std::string movie) {
  std::cout << "Get ready to watch a movie...\n";
  popper->on();
  popper->pop();
  lights->dim(10);
  screen->down();
  projector->on();
  projector->wideScreenMode();
  amp->on();
  amp->setDvd(dvd);
  amp->setSurroundSound();
  amp->setVolume(5);
  dvd->on();
  dvd->play(movie);
}

void HomeTheaterFacade::endMovie() {
  std::cout << "Shutting movie theater down...\n";
  popper->off();
  lights->on();
  screen->up();
  projector->off();
  amp->off();
  dvd->stop();
  dvd->eject();
  dvd->off();
}

void HomeTheaterFacade::listenToCd(std::string cdTitle) {
  std::cout << "\nGet ready for an audiopile experience...\n";
  lights->on();
  amp->on();
  amp->setVolume(5);
  amp->setCd(cd);
  amp->setStereoSound();
  cd->on();
  cd->play(cdTitle);
}

void HomeTheaterFacade::endCd() {
  std::cout << "Shutting down CD...\n";
  amp->off();
  amp->setCd(cd);
  cd->eject();
  cd->off();
}

void HomeTheaterFacade::listenToRadio(double frequency) {
  std::cout << "\nTuning the airwaves...\n";
  tuner->on();
  tuner->setFrequency(frequency);
  amp->on();
  amp->setVolume(5);
  amp->setTuner(tuner);
}

void HomeTheaterFacade::endRadio() {
  std::cout << "Shutting down the tuner...\n";
  tuner->off();
  amp->off();
}
