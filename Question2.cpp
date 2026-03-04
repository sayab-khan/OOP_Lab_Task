#include<iostream>
#include<string>
using namespace std;
class gadget {
private:
    string name;
public:
    //default constructor
    gadget() {
        name = "default";
        cout << "Default gadget created" << endl;
    }
    //parameterized constructor
    gadget(string n) {
        name = n;
        cout << "gadget " << name << " created" << endl;
    }
    //destructor
    ~gadget() {
        cout << "gadget " << name << " destroyed" << endl;
    }
};

int main() {
    gadget s1("outer 1");
    {
        gadget s2("inner 1");
        gadget s3("inner 2");
    }

    gadget s4("outer 2");
    return 0;
}