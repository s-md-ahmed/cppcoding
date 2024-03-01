#include <iostream>

class Octal {
private:
    int octalValue;

public:
    Octal(int x) : octalValue(x) {}

    Octal operator+(int x) const {
        return Octal(octalValue + x);
    }

    friend std::ostream& operator<<(std::ostream& os, const Octal& oct) {
        os << "Octal value: " << oct.octalValue;
        return os;
    }
};

// Function to convert decimal to octal
int decimalToOctal(int decimalValue) {
    int octalValue = 0, i = 1;
    while (decimalValue != 0) {
        octalValue += (decimalValue % 8) * i;
        decimalValue /= 8;
        i *= 10;
    }
    return octalValue;
}

int main() {
    int userInput;
    std::cout << "Enter an integer: ";
    std::cin >> userInput;

    int octalValue = decimalToOctal(userInput);
    Octal h(octalValue);

    int y;
    std::cout << "Enter another integer: ";
    std::cin >> y;

    Octal result = h + y;

    std::cout << "h: " << h << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "h + y: " << result << std::endl;

    return 0;
}