#include <iostream>
#include <string>

using namespace std;

class Gadget {
private:
    string name;

public:
    // Default constructor
    Gadget() {
        name = "default";
        cout << "Default Gadget created" << endl;
    }

    // Parameterized constructor
    Gadget(string n) {
        name = n;
        cout << "Gadget " << name << " created" << endl;
    }

    // Destructor
    ~Gadget() {
        cout << "Gadget " << name << " destroyed" << endl;
    }
};

int main() {
    Gadget g1;
    Gadget g2("Alpha");
    Gadget g3("Beta");

    return 0;
}