#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Subject;
class Observer {
public:
  virtual ~Observer() = default;
  virtual void Update(Subject &) = 0;
};

class Subject {
public:
  virtual ~Subject() = default;
  void Attach(Observer &o) { observers.push_back(&o); }
  void Detach(Observer &o) {
    observers.erase(remove(observers.begin(), observers.end(), &o));
  }
  void Notify() {
    for (Observer *o : observers) {
      o->Update(*this);
    }
  }

private:
  vector<Observer *> observers;
};

class ClockTimer : public Subject {
public:
  void SetTime(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    Notify();
  }
  int GetHour() const { return hour; }
  int GetMinute() const { return minute; }
  int GetSecond() const { return second; }

private:
  int hour;
  int minute;
  int second;
};

class DigitalClock : public Observer {
public:
  explicit DigitalClock(ClockTimer &s) : subject(s) { subject.Attach(*this); }
  ~DigitalClock() { subject.Detach(*this); }
  void Update(Subject &theChangedSubject) override {
    if (&theChangedSubject == &subject)
      Draw();
  }

  void Draw() {
    int hour = subject.GetHour();
    int minute = subject.GetMinute();
    int second = subject.GetSecond();
    cout << "Digital time is " << hour << ":" << minute << ":" << second
         << endl;
  }

private:
  ClockTimer &subject;
};

class AnalogClock : public Observer {
public:
  explicit AnalogClock(ClockTimer &s) : subject(s) { subject.Attach(*this); }
  ~AnalogClock() { subject.Detach(*this); }
  void Update(Subject &theChangedSubject) override {
    if (&theChangedSubject == &subject)
      Draw();
  }

  void Draw() {
    int hour = subject.GetHour();
    int minute = subject.GetMinute();
    int second = subject.GetSecond();
    cout << "Digital time is " << hour << ":" << minute << ":" << second
         << endl;
  }

private:
  ClockTimer &subject;
};

int main(int argc, char const *argv[]) {
  ClockTimer timer;
  DigitalClock digital_clock(timer);
  AnalogClock analog_clock(timer);
  timer.SetTime(14, 9, 00);
  return 0;
}
