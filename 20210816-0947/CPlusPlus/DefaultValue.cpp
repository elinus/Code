#include <iostream>
using namespace std;

class Test {
    public:
    int int_;
    bool bool_;
    long long_;
    double double_;
    Test() {
        cout << int_ << " == " << bool_ << " == " << long_ << " == " << double_ << endl;
    }
};

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 20; i++)
        Test test;
    return 0;
}
