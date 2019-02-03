#include <Facade/Amplifier.h>
#include <Facade/Tuner.h>
#include <Facade/DvdPlayer.h>
#include <Facade/CdPlayer.h>
#include <Facade/Projector.h>
#include <Facade/TheaterLights.h>
#include <Facade/Screen.h>
#include <Facade/PopcornPopper.h>
#include <Facade/HomeTheaterFacade.h>

int main (int argc, char *argv[])
{

    Amplifier *amp = new Amplifier("Top-O-Line Amplifier");
    Tuner *tuner = new Tuner("Top-O-Line AM/FM Tuner", amp);
    DvdPlayer *dvd = new DvdPlayer("Top-O-Line DVD Player", amp);
    CdPlayer *cd = new CdPlayer("Top-O-Line CD Player", amp);
    Projector *projector = new Projector("Top-O-Line Projector", dvd);
    TheaterLights *lights = new TheaterLights("Theater Ceiling Lights");
    Screen *screen = new Screen("Theater Screen");
    PopcornPopper *popper = new PopcornPopper("Popcorn Popper");

    auto *homeTheater = new HomeTheaterFacade(amp, 
            tuner, dvd, cd, projector, lights, screen, popper);

    homeTheater->watchMovie("Raiders of the Lost Ark");
    homeTheater->endMovie();

    // Test other methods
    //homeTheater->listenToCd("Galib Gazals");
    //homeTheater->endCd();
    //homeTheater->listenToRadio(99.99);
    //homeTheater->endRadio();

    return 0;
}
