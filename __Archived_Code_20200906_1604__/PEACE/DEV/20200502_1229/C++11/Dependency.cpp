#include <iostream>

class Point
{
private:
    double m_X, m_Y, m_Z;
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_X { x }, m_Y { y }, m_Z { z }
    {}
    ~Point() {}
    friend std::ostream& operator<<(std::ostream& out, const Point & point) {
        out << "Point(" << point.m_X << ", " << point.m_Y << ", " << point.m_Z << ")\n";
        return out;
    }
};

int main(int argc, char const *argv[])
{
    Point point { 1.0, 2.0, 3.0 };
    std::cout << point;
    return 0;
}
