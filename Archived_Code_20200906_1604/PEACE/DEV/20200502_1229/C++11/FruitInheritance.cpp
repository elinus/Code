#include <iostream>
#include <string>

class Fruit {
private:
    std::string m_Name;
    std::string m_Color;
public:
    Fruit(const std::string & name, const std::string & color)
        : m_Name { name }, m_Color { color } 
    {}
    ~Fruit() {}
    const std::string & getName() const {
        return m_Name;
    }
    const std::string & getColor() const {
        return m_Color;
    }
};

class Apple : public Fruit {
private:
    double m_Fiber;
public:
    Apple(const std::string & name, const std::string & color, double fiber)
        : Fruit { name, color }, m_Fiber { fiber }
    {}
    ~Apple() {}
    friend std::ostream& operator<<(std::ostream & out, const Apple & apple) {
        out << "Apple(" << apple.getName() << ", " << apple.getColor() << ", " << apple.m_Fiber << ")";
        return out;
    }
};

class Banana : public Fruit {
private:
    /* data */
public:
    Banana(const std::string & name, const std::string & color)
        : Fruit { name, color }
    {}
    ~Banana(){} 
    friend std::ostream& operator<<(std::ostream & out, const Banana & banana) {
        out << "Banana(" << banana.getName() << ", " << banana.getColor() << ")";
        return out;
    }
};

int main(int argc, char const *argv[]) {
    
    const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';
 
	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';
 
	return 0;
}
