#include <iostream>
#include <string>

using namespace std;

class Gadget {
private:
    string name;

public:
    Gadget() {
        name = "default";
        cout << "Default Gadget created" << endl;
    }

    Gadget(string n) {
        name = n;
        cout << "Gadget " << name << " created" << endl;
    }

    ~Gadget() {
        cout << "Gadget " << name << " destroyed" << endl;
    }
};

int main() {
    {
        Gadget g1("BlockA1");
        {
            Gadget g2("BlockB1");
            Gadget g3("BlockB2");
        }
        Gadget g4("BlockA2");
    }
    
    return 0;
}