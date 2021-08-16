#include <iostream>
 
class Point2D
{
private:
    int m_x;
    int m_y;
 
public:
    Point2D()
        : m_x{ 0 }, m_y{ 0 }
    {}
 
    Point2D(int x, int y)
        : m_x{ x }, m_y{ y }
    {}
 
    friend std::ostream& operator<<(std::ostream & out, const Point2D & point){
        out << '(' << point.m_x << ", " << point.m_y << ')';
        return out;
    }
 
    void setPoint(int x, int y) {
        m_x = x;
        m_y = y;
    }
};

class Creature
{
private:
    std::string m_name;
    Point2D m_location;
 
public:
    Creature(const std::string &name, const Point2D &location)
        : m_name{ name }, m_location{ location }
    {}
 
    friend std::ostream& operator<<(std::ostream & out, const Creature & creature) {
        out << creature.m_name << " is at " << creature.m_location;
        return out;
    }
 
    void moveTo(int x, int y) {
        m_location.setPoint(x, y);
    }
};

int main()
{
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature{ name, { 4, 7 } };
    
    std::cout << creature << '\n';
    int x { 0 }, y { 0 };
    creature.moveTo(x, y);
    std::cout << creature << '\n';
	 
    return 0;
}