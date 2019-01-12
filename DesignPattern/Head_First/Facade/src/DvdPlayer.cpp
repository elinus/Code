#include <Facade/DvdPlayer.h>

DvdPlayer::DvdPlayer(std::string description, Amplifier *amplifier)
{
    this->description = description;
    this->amplifier = amplifier;
}

void DvdPlayer::on()
{
    std::cout << description << " on\n";
}

void DvdPlayer::off()
{
    std::cout << description << " off\n";
}

void DvdPlayer::eject()
{
    movie = "";
    std::cout << description <<" eject\n";
}

void DvdPlayer::play(std::string movie)
{
    this->movie = movie;
    currentTrack = 0;
    std::cout << description << " playing \"" << movie
        << "\"\n";
}

void DvdPlayer::play(int track)
{
    if (movie == "") {
        std::cout << description << " can't play track " 
            << track << " no dvd inserted\n";
    } else {
        currentTrack = 0;
        std::cout << description << " playing track " 
            << currentTrack << " of \"" << movie << "\"\n";
    }
}

void DvdPlayer::stop()
{
    currentTrack = 0;
    std::cout << description << " stopped \"" 
        << movie << "\"\n";
}


void DvdPlayer::pause()
{
    std::cout << description << " paused \"" 
        << movie << "\"\n";
}

void DvdPlayer::setTwoChannelAudio()
{
    std::cout << description << " set two channel audio\n";
}

void DvdPlayer::setSurroundAudio()
{
    std::cout << description << " set surround audio\n";
}

std::string DvdPlayer::toString(){
    return description;
}
