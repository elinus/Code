#include <iostream>
#include <vector>

struct Sample {
    Sample() {
        std::cout << "[" << this << "] Constructor of Sample class" << std::endl; 
    };
    Sample(const Sample & other) {
        std::cout << "[" << this << "] Copy constructor of Sample class" << std::endl; 
    }
    Sample & operator = (const Sample & other) {

        std::cout << "[" << this << "] Assignment operator of Sample class" << std::endl; 
    }
};

int main (int argc, char *argv[]) {
    
    std::vector<Sample> vSample;
    
    std::cout << "Capacity: " << vSample.capacity() << "\n";
    std::cout << "Size: " << vSample.size() << "\n";
    
    int capacity = vSample.capacity();
    for (int i = 0; i < capacity+1; i++) {
        vSample.push_back(Sample());
    }

    std::cout << "Capacity: " << vSample.capacity() << "\n";
    std::cout << "Size: " << vSample.size() << "\n";
    
    capacity = vSample.capacity();
    for (int i = 0; i < capacity+1; i++) {
        std::cout << "{{-->>\n";
        vSample.push_back(Sample());
        std::cout << "<<--}}\n";
    }

    std::cout << "Capacity: " << vSample.capacity() << "\n";
    std::cout << "Size: " << vSample.size() << "\n";
    
    capacity = vSample.capacity();
    for (int i = 0; i < capacity+1; i++) {
        vSample.push_back(Sample());
    }

    std::cout << "Capacity: " << vSample.capacity() << "\n";
    std::cout << "Size: " << vSample.size() << "\n";
    
    return 0;
}

