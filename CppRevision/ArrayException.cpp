#include <iostream>
#include <string>
#include <exception>

class ArrayException : public std::exception {
    private:
        std::string m_error;
    public:
        ArrayException(std::string error)
            : m_error(error)
        {}
        const char* getError() {
            return m_error.c_str();
        }
        const char* what() const noexcept {
            return m_error.c_str();
        }
};

class IntArray {
    private:
        int m_data[3];
    public:
        IntArray() {}
        int getLength() {
            return 3;
        }
        int& operator [](const int index) {
            if (index < 0 || index >= getLength()) {
                throw ArrayException("Invalid Index!");
            }
            return m_data[index];
        }
};

int main(int argc, char const *argv[]) {
    IntArray array;
    try {
        int value = array[5];
    } catch (ArrayException &e) {
        std::cerr << "Exception: " << e.getError() << std::endl;
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

