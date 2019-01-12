#include <Facade/CdPlayer.h>

CdPlayer::CdPlayer(std::string description, Amplifier *amplifier)
{
    this->description = description;
    this->amplifier = amplifier;
}

void CdPlayer::on()
{
    std::cout << description << " on\n";
}

void CdPlayer::off()
{
    std::cout << description << " off\n";
}

void CdPlayer::eject()
{
    title = "";
    std::cout << description << " eject\n";
}

void CdPlayer::play(std::string title)
{
    this->title = title;
    currentTrack = 0;
    std::cout << description << " playing \"" << title << "\"\n";
}

void CdPlayer::play(int track)
{
    if (title == "") {
        std::cout << description <<  " can't play track " 
            << currentTrack << ", no cd inserted\n";
    } else {
        currentTrack = track;
        std::cout << description << " playing track " << currentTrack << "\n";
    }
    
}


void CdPlayer::stop()
{
    currentTrack = 0;
    std::cout << description << " stopped\n";
}

void CdPlayer::pause()
{
    std::cout << description << " paused \"" << title << "\"\n";
}

std::string CdPlayer::toString()
{
    return description;
}
