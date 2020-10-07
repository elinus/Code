#include <iostream>

class Date {
    private:
        int mYear { 2000 };
        int mMonth { 1 };
        int mDay { 1 };
    public:
        Date() = default;
        Date(int year, int month, int day) {
            mYear = year;
            mMonth = month;
            mDay = day;
        }
};

int main (int argc, char *argv[]) {
    Date d1;
    Date d2 { 2015, 10, 24 };
    return 0;
}

