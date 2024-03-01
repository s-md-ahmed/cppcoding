#include <iostream>

using namespace std;

class COMPLEX {
private:
    int real;
    int imag;

public:
    // Function to set values for a complex number
    void setValues(int r, int i) {
        real = r;
        imag = i;
    }

    // Function to add an integer to a complex number
    COMPLEX ADD(int a) {
        COMPLEX result;
        result.real = real + a;
        result.imag = imag;
        return result;
    }

    // Function to add two complex numbers
    COMPLEX ADD(const COMPLEX& s2) {
        COMPLEX result;
        result.real = real + s2.real;
        result.imag = imag + s2.imag;
        return result;
    }

    // Function to display a complex number
    void display() {
        cout << real << "+" << imag<<"i" << endl;
    }
};

int main() {
    COMPLEX c1;
    c1.setValues(3, 4);

    COMPLEX c2;
    c2.setValues(1, 2);

    // Adding an integer to a complex number
    COMPLEX result1 = c1.ADD(5);

    // Adding two complex numbers
    COMPLEX result2 = c1.ADD(c2);

    // Displaying results
    cout << "Result 1: ";
    result1.display();

    cout << "Result 2: ";
    result2.display();

    return 0;
}