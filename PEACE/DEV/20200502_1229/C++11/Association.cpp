#include <iostream>
#include <vector>
#include <string>
#include <functional>

class Patient;

class Doctor
{
private:
    std::string m_Name;
    std::vector<std::reference_wrapper<const Patient>> m_Patients {};
public:
    Doctor(const std::string & name) : m_Name {name}
    {}
    ~Doctor() {}
    const std::string& getName() const { return m_Name; }
    void addPatient(Patient & patient);
    friend std::ostream& operator<<(std::ostream & out, const Doctor & doctor);
};

class Patient
{
private:
    std::string m_Name;
    std::vector<std::reference_wrapper<const Doctor>> m_Doctors {};
public:
    Patient(const std::string & name) : m_Name {name}
    {}
    ~Patient() {}
    const std::string& getName() const { return m_Name; }
    void addDoctor(const Doctor & doctor);
    friend std::ostream& operator<<(std::ostream & out, const Patient & patient);
};

// Doctor
void Doctor::addPatient(Patient & patient) {
    m_Patients.push_back(patient);
    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream & out, const Doctor & doctor) {
    if (doctor.m_Patients.empty()) {
        out << doctor.m_Name << " has no patients right now\n";
        return out;
    }
    out << doctor.m_Name << "is seeing patients: ";
    for (const auto & patient: doctor.m_Patients){
        out << patient.get().getName() << ' ';
    }
    return out;
}

// Patient
void Patient::addDoctor(const Doctor & doctor) {
    m_Doctors.push_back(doctor);
}

std::ostream& operator<<(std::ostream & out, const Patient & patient) {
    if (patient.m_Doctors.empty()) {
		out << patient.getName() << " has no doctors right now";
		return out;
	}
 
	out << patient.m_Name << " is seeing doctors: ";
	for (const auto& doctor : patient.m_Doctors)
		out << doctor.get().getName() << ' ';
 
	return out;
}

int main(int argc, char const *argv[])
{
    Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };
 
	Doctor james{ "James" };
	Doctor scott{ "Scott" };
 
	james.addPatient(dave);
 
	scott.addPatient(dave);
	scott.addPatient(betsy);
 
	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';
    return 0;
}
