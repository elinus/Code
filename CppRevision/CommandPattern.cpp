#include <iostream>

using namespace std;

class Command
{
  public:
    virtual void execute() = 0;
};

class Television
{
  public:
    Television() : volume(0), channel(0) {}
    void turnOn()
    {
        cout << "Television - ON" << endl;
    }
    void turnOff()
    {
        cout << "Television - OFF" << endl;
    }
    void volumeUp()
    {
        cout << "Television volume up:  " << ++volume << endl;
    }
    void volumeDown()
    {
        cout << "Television volume down: " << --volume << endl;
    }
    void channelUp()
    {
        cout << "Television channel up: " << ++channel << endl;
    }
    void channelDown()
    {
        cout << "Television channel down: " << --channel << endl;
    }

  private:
    int volume;
    int channel;
};

class TVOnCommand : public Command
{
  public:
    TVOnCommand(Television &tele) : tv(tele) {}
    virtual void execute()
    {
        tv.turnOn();
    }

  private:
    Television &tv;
};

class TVOffCommand : public Command
{
  public:
    TVOffCommand(Television &tele) : tv(tele) {}
    virtual void execute()
    {
        tv.turnOff();
    }

  private:
    Television &tv;
};

class VolumeUpCommand : public Command
{
  public:
    VolumeUpCommand(Television &tele) : tv(tele) {}
    virtual void execute()
    {
        tv.volumeUp();
    }

  private:
    Television &tv;
};

class VolumeDownCommand : public Command
{
  public:
    VolumeDownCommand(Television &tele) : tv(tele) {}
    virtual void execute()
    {
        tv.volumeDown();
    }

  private:
    Television &tv;
};

class ChannelUpCommand : public Command
{
  public:
    ChannelUpCommand(Television &tele) : tv(tele) {}
    virtual void execute()
    {
        tv.volumeUp();
    }

  private:
    Television &tv;
};

class ChannelDownCommand : public Command
{
  public:
    ChannelDownCommand(Television &tele) : tv(tele) {}
    virtual void execute()
    {
        tv.volumeDown();
    }

  private:
    Television &tv;
};

class TVRemote
{
  public:
    TVRemote(Command &tvOnCommand, Command &tvOffCommand,
             Command &volumeUpCommand, Command &volumeDownCommand,
             Command &channelUpCommand, Command &channelDownCommand)
        : tvOnCommand(tvOnCommand), tvOffCommand(tvOffCommand),
          volumeUpCommand(volumeUpCommand), volumeDownCommand(volumeDownCommand),
          channelUpCommand(channelUpCommand), channelDownCommand(channelDownCommand)
    {
    }
    void tvOn()
    {
        tvOnCommand.execute();
    }

    void tvOff()
    {
        tvOffCommand.execute();
    }

    void volumeUp()
    {
        volumeUpCommand.execute();
    }

    void volumeDown()
    {
        volumeDownCommand.execute();
    }

    void channelUp()
    {
        channelUpCommand.execute();
    }

    void channelDown()
    {
        channelDownCommand.execute();
    }

  private:
    Command &tvOnCommand;
    Command &tvOffCommand;
    Command &volumeUpCommand;
    Command &volumeDownCommand;
    Command &channelUpCommand;
    Command &channelDownCommand;
};

int main()
{
    Television myTV;
    TVOnCommand tvOn(myTV);
    TVOffCommand tvOff(myTV);
    ChannelDownCommand chDwnCmd(myTV);
    ChannelUpCommand chUpCmd(myTV);
    VolumeUpCommand volUpCmd(myTV);
    VolumeDownCommand volDwnCmd(myTV);

    TVRemote remote(volUpCmd, volDwnCmd, chUpCmd, chDwnCmd, tvOn, tvOff);

    remote.tvOn();
    remote.channelUp();
    remote.channelUp();
    remote.channelUp();
    remote.volumeUp();
    remote.volumeUp();
    remote.channelDown();
    remote.volumeDown();
    remote.tvOff();
    return 0;
}