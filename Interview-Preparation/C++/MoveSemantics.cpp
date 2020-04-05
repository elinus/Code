#include <iostream>
#include <vector>

class Entity {
    int * mData;
    public:
    Entity() : mData(nullptr) {
        std::cout << "[" << this << "] Default Constructor\n";
    }
    Entity(int data) : mData(new int(data)) { 
        std::cout << "[" << this << "] Patameterized Constructor\n";
    }
    ~Entity() {
        std::cout << "[" << this << "] Destructor\n";
        if (mData) {
            delete mData;
        }
        mData = nullptr;
    }
    Entity(const Entity & other) {
        std::cout << "[" << this << "] Copy Constructor\n";
        mData = new int(*other.mData);
    }
    Entity(Entity && other) {
        std::cout << "[" << this << "] Move Constructor\n";
        mData = other.mData;
        other.mData = nullptr;
    }
    Entity & operator = (const Entity & other) {
        std::cout << "[" << this << "] Assignment Operator\n";
        if (this != &other) {
            mData = new int(*other.mData);
        }
        return *this;
    }
    Entity & operator = (Entity && other) {
        std::cout << "[" << this << "] Move Assignment Operator\n";
        if (this != &other) {
            mData = other.mData;
            other.mData = nullptr;
        }
        return *this;
    }
};

Entity getEntity() {
    Entity entity(14);
    std::cout << "Returning << Entity >> object\n";
    return entity;
}

int main (int argc, char *argv[]) {
    std::vector<Entity> entityVector;
    entityVector.push_back({ getEntity() });

    Entity entObj;
    entObj = getEntity();
    return 0;
}

