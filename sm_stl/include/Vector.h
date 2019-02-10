#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <string>
#include <iostream>

namespace sm_stl {

    template <typename T>
    class Vector {
        public:
        Vector(size_t size = 10) : size(size), buffer(new T[size])
        {
            std::cout << TAG << "Constructor!. size = " << size <<  ", buffer addr. = " << buffer << "\n";
        }
        ~Vector() {
            std::cout << TAG << "Destructor!. deleting buffer addr. = " << buffer << "\n";
            delete [] buffer;
        }
        private:
            std::string TAG = "[Vector] ";
            std::size_t size;
            T *buffer;
    };
}

#endif /* __VECTOR_H__ */
