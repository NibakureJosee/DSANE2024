#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//using of node in linked list beacuse we are using linked list and linked list is made up of nodes
//node is a structure that contains data and a pointer to the next node
struct Patient {
    int patient_id;
    string name;
    string dob;
    string gender;
};

// Structure for dorctor to store doctor details
struct Doctor {
    int doctor_id;
    string name;
    string specialization;
};

// structure for appointment to store appointment details
struct Appointment {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
};

// Node structure for linked list of patients in the hospital information system
struct PatientNode {
    Patient data;
    PatientNode* next;
};

// Node structure for linked list of doctors in the hospital information system
struct DoctorNode {
    Doctor data;
    DoctorNode* next;
};

struct AppointmentNode {
    Appointment data;
    AppointmentNode* next;
};

// linked lists head pointers for patients, doctors and appointments
PatientNode* patientsHead = nullptr;
DoctorNode* doctorsHead = nullptr;
AppointmentNode* appointmentsHead = nullptr;

// function to create a new patient
PatientNode* createPatientNode(int id, string fname, string dob, string gender) {
    PatientNode* newNode = new PatientNode();
    newNode->data.patient_id = id;
    newNode->data.name = fname;
    newNode->data.dob = dob;
    newNode->data.gender = gender;
    newNode->next = nullptr;
    return newNode;
}

// function to create a new doctor
DoctorNode* createDoctorNode(int id, string fname, string specialization) {
    DoctorNode* newNode = new DoctorNode();
    newNode->data.doctor_id = id;
    newNode->data.name = fname;
    newNode->data.specialization = specialization;
    newNode->next = nullptr;
    return newNode;
}

// function to create a new appointment
AppointmentNode* createAppointmentNode(int appt_id, int pat_id, int doc_id, string appt_date) {
    AppointmentNode* newNode = new AppointmentNode();
    newNode->data.appointment_id = appt_id;
    newNode->data.patient_id = pat_id;
    newNode->data.doctor_id = doc_id;
    newNode->data.appointment_date = appt_date;
    newNode->next = nullptr;
    return newNode;
}

// function to register a new patient in the hospital information system
void registerPatient() {
    cout<<"PATIENT REGISTRATION"<<endl;
    cout<<"______________________________ "<<endl;
    int id;
    string fname, dob, gender;
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin >> fname;
    cout << "DOB: ";
    cin >> dob;
    cout << "Gender: ";
    cin >> gender;

    PatientNode* newNode = createPatientNode(id, fname, dob, gender);
    newNode->next = patientsHead;
    patientsHead = newNode;
    cout << "Patient registered successfully." << endl;
}

// function to register a new doctor
void registerDoctor() {
    cout<<"DOCTOR REGISTRATION"<<endl;
    cout<<"______________________________ "<<endl;
    int id;
    string fname, specialization;
    cout <<"ID: ";
    cin >> id;
    cout <<"Name: ";
    cin >> fname;
    cout <<"Specialization: ";
    cin >> specialization;

    DoctorNode* newNode = createDoctorNode(id, fname, specialization);
    newNode->next = doctorsHead;
    doctorsHead = newNode;
    cout << "Doctor registered successfully." << endl;
}

// Function to check if a patient exists
bool patientExists(int id) {
    PatientNode* current = patientsHead;
    while (current != nullptr) {
        if (current->data.patient_id == id) return true;
        current = current->next;
    }
    return false;
}

// Function to check if a doctor exists
bool doctorExists(int id) {
    DoctorNode* current = doctorsHead;
    while (current != nullptr) {
        if (current->data.doctor_id == id) return true;
        current = current->next;
    }
    return false;
}

// Function to register a new appointment
void registerAppointment() {
    cout<<"APPOINTMENT REGISTRATION"<<endl;
    cout<<"______________________________ "<<endl;
    int appt_id, pat_id, doc_id;
    string appt_date;
    cout << "ID: ";
    cin >> appt_id;
    cout << "P_ID: ";
    cin >> pat_id;
    cout << "D_ID: ";
    cin >> doc_id;
    cout << "Date: ";
    cin >> appt_date;

    if (!patientExists(pat_id)) {
        cout << "Error: Patient ID does not exist." << endl;
        return;
    }
    if (!doctorExists(doc_id)) {
        cout << "Error: Doctor ID does not exist." << endl;
        return;
    }

    AppointmentNode* newNode = createAppointmentNode(appt_id, pat_id, doc_id, appt_date);
    newNode->next = appointmentsHead;
    appointmentsHead = newNode;
    cout << "Appointment registered successfully." << endl;
}

// function to display patients
void displayPatients() {
    PatientNode* current = patientsHead;
    if (current == nullptr) {
        cout << "No patients found." << endl;
        return;
    }
    while (current != nullptr) {
        cout << "Patient ID: " << current->data.patient_id << ", Name: " << current->data.name << ", DOB: " << current->data.dob << ", Gender: " << current->data.gender << endl;
        current = current->next;
    }
}

// function to display doctors
void displayDoctors() {
    DoctorNode* current = doctorsHead;
    if (current == nullptr) {
        cout << "No doctors found." << endl;
        return;
    }
    while (current != nullptr) {
        cout << "Doctor ID: " << current->data.doctor_id << ", Name: " << current->data.name << ", Specialization: " << current->data.specialization << endl;
        current = current->next;
    }
}

// function to display appointments
void displayAppointments() {
    AppointmentNode* current = appointmentsHead;
    if (current == nullptr) {
        cout << "No appointments found." << endl;
        return;
    }
    while (current != nullptr) {
        cout << "Appointment ID: " << current->data.appointment_id << ", Patient ID: " << current->data.patient_id << ", Doctor ID: " << current->data.doctor_id << ", Date: " << current->data.appointment_date << endl;
        current = current->next;
    }
}

// main menu function
void menu() {
    int choice;
    do {
        cout << " Menu:"<<endl;
        cout << "1. Register a Patient" << endl;
        cout << "2. Register a Doctor" << endl;
        cout << "3. Register an Appointment" << endl;
        cout << "4. Display Patients" << endl;
        cout << "5. Display Doctors" << endl;
        cout << "6. Display Appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                registerDoctor();
                break;
            case 3:
                registerAppointment();
                break;
            case 4:
                displayPatients();
                break;
            case 5:
                displayDoctors();
                break;
            case 6:
                displayAppointments();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}

// main function
int main() {
    menu();
    return 0;
}


