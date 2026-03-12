#include <iostream>
using namespace std;

class EspressoMachine {
private:
    int waterLevel;
    int coffeeBeans;
    int id;
    static int counter;

public:
    EspressoMachine(int water, int beans) : waterLevel(water), coffeeBeans(beans) {
        id = ++counter;
        cout << "Machine " << id << " created." << endl;
    }

    EspressoMachine(const EspressoMachine& other) : waterLevel(other.waterLevel), coffeeBeans(other.coffeeBeans) {
        id = ++counter;
        cout << "Machine " << id << " created (copy)." << endl;
    }

    void brew() {
        if (waterLevel < 30 || coffeeBeans < 10) {
            cout << "Refill needed. Cannot brew." << endl;
        } else {
            waterLevel -= 30;
            coffeeBeans -= 10;
            cout << "Brew successful. Remaining -> Water: " << waterLevel << "ml, Beans: " << coffeeBeans << "g" << endl;
        }
    }

    EspressoMachine operator+(const EspressoMachine& other) const {
        return EspressoMachine(waterLevel + other.waterLevel, coffeeBeans + other.coffeeBeans);
    }

    ~EspressoMachine() {
        cout << "Machine " << id << " shutting down." << endl;
    }
};

int EspressoMachine::counter = 0;

int main() {
    EspressoMachine m1(20, 5);
    EspressoMachine m2(20, 10);
    m1.brew();
    EspressoMachine m3 = m1 + m2;
    m3.brew();

    return 0;
}
