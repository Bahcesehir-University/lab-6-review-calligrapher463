#include

#include

#include

#include // toupper için gerekli

using namespace std;

class Student {

private:

string name;

int id;

double gpa;

public:

// ----- Task 1: Constructors & Destructor -----

// TODO 1a: Default constructor

Student() : name("Unknown"), id(0), gpa(0.0) {}

// TODO 1b: Parameterized constructor

Student(string n, int i, double g) : name(n), id(i), gpa(g) {}

// TODO 1c: Copy constructor

Student(const Student& other) {

name = other.name;

id = other.id;

gpa = other.gpa;

}

// TODO 1d: Destructor

~Student() {

cout << "Student " << name << " destroyed" << endl;

}

// ----- Task 2: Getters (Encapsulation) -----

// TODO 2a: Getter for name

string getName() const {

return name;

}

// TODO 2b: Getter for id

int getId() const {

return id;

}

// TODO 2c: Getter for gpa

double getGpa() const {

return gpa;

}

// ----- Task 3: Setters with Validation -----

// TODO 3a: Setter for name

void setName(string n) {

if (!n.empty()) {

name = n;

}

}

// TODO 3b: Setter for GPA

void setGpa(double g) {

if (g >= 0.0 && g <= 4.0) {

gpa = g;

}

}

// ----- Task 4: String Operation -----

// TODO 4: getFormattedName()

string getFormattedName() const {

string upperName = "";

for (char c : name) {

upperName += (char)toupper((unsigned char)c);

}

return upperName;

}

// ----- Task 5: Operator Overloading -----

// TODO 5a: Equality operator (==)

bool operator==(const Student& other) const {

return id == other.id;

}

// TODO 5b: Less-than operator (<)

bool operator<(const Student& other) const {

return gpa < other.gpa;

}

// TODO 5c: Stream insertion operator (<<)

friend ostream& operator<<(ostream& os, const Student& s) {

os << "Student(" << s.name << ", ID: " << s.id << ", GPA: " << s.gpa << ")";

return os;

}

};

// ================================

// STANDALONE FUNCTION

// ================================

// TODO 6: Function Overloading - findBestStudent

// Version 1: İki öğrenci arasında karşılaştırma

Student findBestStudent(const Student& a, const Student& b) {

if (a.getGpa() > b.getGpa()) {

return a;

}

return b;

}

// Version 2: Array içinde en yüksek GPA'lıyı bulma

Student findBestStudent(Student arr[], int size) {

int bestIndex = 0;

for (int i = 1; i < size; i++) {

if (arr[i].getGpa() > arr[bestIndex].getGpa()) {

bestIndex = i;

}

}

return arr[bestIndex];

}
