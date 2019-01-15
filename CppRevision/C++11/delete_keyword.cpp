/* @link: https://thispointer.com/c11-c14-delete-keyword-and-deleted-functions-with-use-cases-examples/
 * @notes: 
    - Deleting compiler generated functions like copy constructor, assignment operators, move constructor, move assignment operator and default constructor.
    - Deleting member functions to prevent data loss conversions
    - Restrict Object creation on Heap by deleting new operator for class
    - Delete specific template specilaizations
    ------------------------------------------
    - Private member functions can be called from other member functions, whereas, deleted functions can not be called even from other member functions.
    - Deleted functions exists in name lookup, if compiler finds a function is deleted then it will not lookup for other matching functions based on type lookups, hence prevents unneccesary data loss and bugs.
 * */

#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person(string name, int age) : name(name), age(age)
        {}
        Person(string, double age) = delete;
        Person(string, char age) = delete;
        Person(const Person &other) = delete;
        Person & operator = (const Person &other) = delete;
        void print()
        {
            cout << __func__ << endl;
            cout << "NAME: " << name << ", AGE: " << age << endl;
        }
        friend ostream & operator << (ostream &out, const Person &p);
        void * operator new (size_t) = delete;
};


ostream & operator << (ostream &out, const Person &p)
{
    out << __func__ << ": ";
    out << "NAME: " << p.name;
    out << ", AGE: " << p.age << endl;
    return out;
}

template<typename T>
class Complex {
    public:
        Complex(T r = 0, T i = 0): real(i), imag(i) {}
        Complex(double r, double i) = delete;
        void printComplex()
        {
            cout << "Real       : " << this->real << endl;
            cout << "Imaginary  : " << this->imag << endl;
        }
    private:
        T real;
        T imag;
};

int main (int argc, char *argv[])
{
    Person pO1("elinus", 14);
    cout << pO1;

    //Person pO2(pO1); // error: use of deleted function ‘Person::Person(const Person&)
    Person pO3("aks", 20);
    pO3.print();
    //pO3 = pO1; // error: use of deleted function ‘Person& Person::operator=(const Person&)'
    //Person pO4("p4", 1.1); // error: use of deleted function ‘Person::Person(std::__cxx11::string, double)’
    //Person pO5("p5", 's'); // error: use of deleted function ‘Person::Person(std::__cxx11::string, char)’
    //Person *pO6 = new Person("p6", 14); //  error: use of deleted function ‘static void* Person::operator new(size_t)’
    
    // Complex<double> c1; // error: ‘Complex<T>::Complex(double, double) [with T = double]’ cannot be overloaded
    //c1.printComplex();
    return 0;
}

