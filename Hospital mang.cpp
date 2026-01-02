
#include <iostream>
#include <vector>
using namespace std;

// Enum for department
enum Department {
    CARDIOLOGY,
    NEUROLOGY,
    ORTHOPEDICS,
    GENERAL
};

// Convert enum to string
string getDepartmentName(Department d) {
    switch (d) {
        case CARDIOLOGY: return "Cardiology";
        case NEUROLOGY: return "Neurology";
        case ORTHOPEDICS: return "Orthopedics";
        default: return "General";
    }
}

// ------------------ Patient Class ------------------
class Patient {
private:
    int patientID;
    string name;
    int age;
    string disease;

public:
    Patient(int id, string n, int a, string d)
        : patientID(id), name(n), age(a), disease(d) {}

    int getID() const {
        return patientID;
    }

    void display() const {
        cout << "Patient ID : " << patientID << endl;
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
        cout << "Disease    : " << disease << endl;
        cout << "-----------------------------\n";
    }
};

// ------------------ Doctor Class ------------------
class Doctor {
private:
    int doctorID;
    string name;
    Department department;

public:
    Doctor(int id, string n, Department d)
        : doctorID(id), name(n), department(d) {}

    int getID() const {
        return doctorID;
    }

    void display() const {
        cout << "Doctor ID  : " << doctorID << endl;
        cout << "Name       : " << name << endl;
        cout << "Department : " << getDepartmentName(department) << endl;
        cout << "-----------------------------\n";
    }
};

// ------------------ Hospital Class ------------------
class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;

public:
    void addPatient() {
        int id, age;
        string name, disease;

        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Disease: ";
        getline(cin, disease);

        patients.emplace_back(id, name, age, disease);
        cout << "Patient added successfully!\n";
    }

    void addDoctor() {
        int id, deptChoice;
        string name;

        cout << "Enter Doctor ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Select Department:\n";
        cout << "0. Cardiology\n1. Neurology\n2. Orthopedics\n3. General\n";
        cin >> deptChoice;

        doctors.emplace_back(id, name, static_cast<Department>(deptChoice));
        cout << "Doctor added successfully!\n";
    }

    void displayPatients() const {
        if (patients.empty()) {
            cout << "No patients found.\n";
            return;
        }
        for (const auto &p : patients) {
            p.display();
        }
    }

    void displayDoctors() const {
        if (doctors.empty()) {
            cout << "No doctors found.\n";
            return;
        }
        for (const auto &d : doctors) {
            d.display();
        }
    }

    void searchPatient() const {
        int id;
        cout << "Enter Patient ID to search: ";
        cin >> id;

        for (const auto &p : patients) {
            if (p.getID() == id) {
                p.display();
                return;
            }
        }
        cout << "Patient not found!\n";
    }
};

// ------------------ Main Function ------------------
int main() {
    Hospital hospital;
    int choice;

    do {
        cout << "\n====== Hospital Management System ======\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Display All Patients\n";
        cout << "4. Display All Doctors\n";
        cout << "5. Search Patient\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: hospital.addPatient(); break;
            case 2: hospital.addDoctor(); break;
            case 3: hospital.displayPatients(); break;
            case 4: hospital.displayDoctors(); break;
            case 5: hospital.searchPatient(); break;
            case 6: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
