#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main() {

    // Initializing Date object with 21st March 2016
    boost::gregorian::date dateObj { 2016, 3, 21 };

    // Accessing Day of Month from Date object
    std::cout << "Day of Month = " << dateObj.day() << '\n';

    // Accessing Month from Date object
    std::cout << "Month = " << dateObj.month() << '\n';

    // Accessing Year from Date object
    std::cout << "Year = " << dateObj.year() << '\n';

    // Accessing Day of week from Date object
    std::cout << "Day of Week = " << dateObj.day_of_week() << '\n';

    // Printing complete Date object on console
    std::cout << "Date = " << dateObj << '\n';
}
