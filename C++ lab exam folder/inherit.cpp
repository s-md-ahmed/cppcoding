#include <iostream>
#include <string>
using namespace std;
class Publication {
protected:
    string title;
public:
    Publication(const string& title) : title(title) {}
    void print() {
        cout << "Title: " << title << endl;
    }
};
class Book : virtual public Publication {
private:
    int accessionNumber;
public:
    Book(const string& title, int accessionNumber) : Publication(title), accessionNumber(accessionNumber) {}
    void print() {
        Publication::print(); // Invoke base class function
        cout << "Accession Number: " << accessionNumber << endl;
    }
};
class Magazine : virtual public Publication {
private:
    int volumeNumber;
public:
    Magazine(const string& title, int volumeNumber) : Publication(title), volumeNumber(volumeNumber) {}
    void print() {
        cout << "Volume Number: " << volumeNumber << endl;
    }
};
class Journal : public Book, public Magazine {
public:
    Journal(const string& title, int accessionNumber, int volumeNumber) : Publication(title), Book(title, accessionNumber), Magazine(title, volumeNumber) {}
    // Resolve ambiguity by specifying which print function to call
    void print() {
        Book::print();
        Magazine::print();
    }
};
int main() {
    Journal IEEEOOP("IEEEOOP", 6813, 5);
    IEEEOOP.print(); // Invokes the print function from both Book and Magazine
    return 0;
}
