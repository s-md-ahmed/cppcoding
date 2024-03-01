#include <iostream>
#include <string>
using namespace std;

class STUDENT {
private:
    string USN;
    string Name;
    float Marks[3];

public:
    void readData() {
        cout << "Enter USN: ";
        cin >> USN;
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter marks in 3 tests: ";
        for (int i = 0; i < 3; i++) {
            cin >> Marks[i];
        }
    }

    float calculateAverage() {
        // Sort the marks in descending order
        for (int i = 0; i < 2; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (Marks[i] < Marks[j]) {
                    float temp = Marks[i];
                    Marks[i] = Marks[j];
                    Marks[j] = temp;
                }
            }
        }
        // Calculate average of two better marks
        return (Marks[0] + Marks[1]) / 2.0;
    }

    void printData() {
        cout << "USN: " << USN << endl;
        cout << "Name: " << Name << endl;
    }
};

int main() {
    const int N = 10;
    STUDENT students[N];

    // Read data for each student
    for (int i = 0; i < N; i++) {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        students[i].readData();
    }

    // Calculate and print average marks for each student
    cout << "\nAverage marks of students:" << endl;
    for (int i = 0; i < N; i++) {
        float avgMarks = students[i].calculateAverage();
        students[i].printData();
        cout << "Average Marks: " << avgMarks << endl;
    }

    return 0;
}
