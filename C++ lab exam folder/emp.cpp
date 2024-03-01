#include <iostream>
#include <string>
using namespace std;

class EMPLOYEE {
private:
    int Employee_Number;
    string Employee_Name; // Changed to string
    float Basic, DA, IT, Net_Sal;

public:
    void readData() {
        cout << "Enter Employee Number: ";
        cin >> Employee_Number;
        cout << "Enter Employee Name: ";
        cin >> Employee_Name; // Changed from cin>>Employee_Name; to cin>>Employee_Name;
        cout << "Enter Basic Salary: ";
        cin >> Basic;
    }

    void calculateNetSal() {
        DA = 0.52 * Basic;
        float grossSal = Basic + DA;
        IT = 0.30 * grossSal;
        Net_Sal = grossSal - IT;
    }

    void printData() {
        cout << "Employee Number: " << Employee_Number << endl;
        cout << "Employee Name: " << Employee_Name << endl;
        cout << "Basic Salary: " << Basic << endl;
        cout << "DA: " << DA << endl;
        cout << "IT: " << IT << endl;
        cout << "Net Salary: " << Net_Sal << endl;
    }
};

int main() {
    int N;
    cout << "Enter the number of employees: ";
    cin >> N;

    EMPLOYEE employees[N];

    // Read data for each employee
    for (int i = 0; i < N; i++) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        employees[i].readData();
    }

    // Calculate and print net salary for each employee
    for (int i = 0; i < N; i++) {
        employees[i].calculateNetSal();
        cout << "\nDetails for employee " << i + 1 << ":" << endl;
        employees[i].printData();
    }

    return 0;
}
