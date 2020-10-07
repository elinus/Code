#include <iostream>
using namespace std;

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
		cout << "PoweredDevice: " << power << '\n';
    }
};
 
class Scanner: virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power)
    {
		cout << "Scanner: " << scanner << '\n';
    }
};
 
class Printer: virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power)
    {
		cout << "Printer: " << printer << '\n';
    }
};
 
class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : PoweredDevice(power), Scanner(scanner, power), Printer(printer, power)
    {}
};

int main(int argc, char const *argv[])
{
    Copier copier(1, 2, 3);
    return 0;
}
