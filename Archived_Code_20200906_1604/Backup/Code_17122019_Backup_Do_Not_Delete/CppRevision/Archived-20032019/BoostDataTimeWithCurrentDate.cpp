#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main() {

  // Initializing Date object with today's in Local Time Zone
  boost::gregorian::date todaysDateInLocalTZ =
      boost::gregorian::day_clock::local_day();

  // Printing complete Date object on console
  std::cout << "Date in System's Time Zone= " << todaysDateInLocalTZ << '\n';

  // Initializing Date object with today's in UTC Time Zone
  boost::gregorian::date todaysDateInUtcTZ =
      boost::gregorian::day_clock::universal_day();

  // Printing complete Date object on console
  std::cout << "Date in UTC Time Zone = " << todaysDateInUtcTZ << '\n';
}
