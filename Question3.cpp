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

void createGadgets() {
    Gadget g1("Func1");
    Gadget g2("Func2");
}

int main() {
    Gadget gMain1("Main1");
    createGadgets();
    Gadget gMain2("Main2");
    
    return 0;
}