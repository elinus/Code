#include <Facade/HomeTheaterFacade.h>

HomeTheaterFacade::HomeTheaterFacade(Amplifier *amp,
            Tuner *tuner,
            DvdPlayer *dvd,
            CdPlayer *cd,
            Projector *projector,
            TheaterLights *lights,
            Screen *screen,
            PopcornPopper *popper)
{
    this->amp = amp;
    this->tuner = tuner;
    this->dvd = dvd;
    this->cd = cd;
    this->projector = projector;
    this->lights = lights;
    this->screen = screen;
    this->popper = popper;

}

void HomeTheaterFacade::watchMovie(std::string movie)
{
    std::cout << "Get ready to watch a movie\n";
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

void HomeTheaterFacade::endMovie()
{

}

void HomeTheaterFacade::listenToCd(std::string cdTitle)
{

}

void HomeTheaterFacade::endCd()
{

}

void HomeTheaterFacade::listenToRadio(double frequency)
{

}

void HomeTheaterFacade::endRadio()
{

}

