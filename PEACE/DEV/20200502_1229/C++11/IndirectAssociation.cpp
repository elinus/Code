#include <iostream>
#include <string>

class Car
{
private:
    std::string m_Name;
    int m_Id;
public:
    Car(const std::string & name, int id) : m_Name { name }, m_Id { id } 
    {}
    ~Car() {}
    const std::string& getName() const {
        return m_Name;
    }
    int getId() const {
        return m_Id;
    }
};

class CarLot {
    private:
    static Car s_Cars[4];
    public:
    CarLot() = delete;
    static Car* getCar(int id) {
        for (size_t i = 0; i < 4; i++) {
            if (s_Cars[i].getId() == id) {
                return &(s_Cars[i]);
            }
        }
        return nullptr;
    }
};

Car CarLot::s_Cars[4] { 
    { "Prius", 4 }, 
    { "Corolla", 17 }, 
    { "Accord", 84 }, 
    { "Matrix", 62 } };

class Driver
{
private:
    std::string m_Name;
    int m_CarId;
public:
    Driver(const std::string & name, int car_id) : m_Name { name }, m_CarId { car_id } 
    {}
    ~Driver() {}
    const std::string& getName() const {
        return m_Name;
    }
    int getId() const {
        return m_CarId;
    }
};

int main(int argc, char const *argv[])
{
    Driver driver { "Franz", 17 };
    Car *car { CarLot::getCar(driver.getId()) };
    if (car) {
        std::cout << driver.getName() << " is driving a " << car->getName() << '\n';
    } else {
        std::cout << driver.getName() << " couldn't find his car\n";
    }
    
    return 0;
}
