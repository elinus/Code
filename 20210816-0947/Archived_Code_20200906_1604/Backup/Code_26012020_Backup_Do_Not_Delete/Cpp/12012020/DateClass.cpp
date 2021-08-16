#include <iostream>

class DateClass {
    private:
        int mDay;
        int mMonth;
        int mYear;
    public:
        void setDate(int day, int month, int year) {
            mDay = day;
            mMonth = month;
            mYear = year;
        }

        void print() {
            std::cout << mDay << "/" << mMonth << "/" << mYear << "\n";
        }

        void copyFrom(const DateClass& other) {
            mDay = other.mDay;
            mMonth = other.mMonth;
            mYear = other.mYear;
        }
};

int main (int argc, char *argv[]) {
    DateClass date;
    date.setDate(24, 10, 2015);
    date.print();

    DateClass copy;
    copy.copyFrom(date);
    copy.print();

    return 0;
}

