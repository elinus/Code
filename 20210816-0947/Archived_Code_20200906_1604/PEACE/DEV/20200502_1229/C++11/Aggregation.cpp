#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Teacher {
    std::string m_Name {};
    public:
    Teacher(const std::string & name) : m_Name { name }
    {}
    const std::string& getName() const {
        return m_Name;
    }
};

class Department {
    std::vector<std::reference_wrapper<const Teacher>> m_Teachers {};
    public:
    Department()
    {}
    void add(const Teacher & teacher) {
        m_Teachers.push_back(teacher);
    }
    friend std::ostream& operator<<(std::ostream & out, const Department & department) {
        out << "Department: ";
        for (auto i : department.m_Teachers) {
            out << i.get().getName() << ' ';
        }
        out << '\n';
        return out;
    }

};

int main(int argc, char const *argv[])
{
    Teacher t1 { "T1" };
    Teacher t2 { "T2" };
    Teacher t3 { "T3" };
    {
        Department department; 
        department.add(t1);
        department.add(t2);
        department.add(t3);
    }
    std::cout << t1.getName() << std::endl;
    std::cout << t2.getName() << std::endl;
    std::cout << t3.getName() << std::endl;
    return 0;
}
