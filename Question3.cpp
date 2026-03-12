#include <iostream>
using namespace std;

class DigitalPet {
private:
    int hunger;
    int energy;

public:
    DigitalPet(int h, int e) : hunger(h), energy(e) {}

    DigitalPet& feed() {
        hunger -= 20;
        if (hunger < 0) {
            cout << "Hunger is bounded at 0." << endl;
            hunger = 0;
        }
        return *this;
    }

    DigitalPet& sleep() {
        energy += 30;
        if (energy > 100) {
            cout << "Energy is bounded at 100." << endl;
            energy = 100;
        }
        return *this;
    }

    DigitalPet& operator++() {
        energy -= 10;
        hunger += 10;
        if (energy < 0) energy = 0;
        if (hunger > 100) hunger = 100;
        return *this;
    }

    DigitalPet operator++(int) {
        DigitalPet original = *this;
        energy -= 10;
        hunger += 10;
        if (energy < 0) energy = 0;
        if (hunger > 100) hunger = 100;
        return original;
    }

    void printStats() const {
        cout << "Current Stats -> Hunger: " << hunger << ", Energy: " << energy << endl;
    }

    int getHunger() const { return hunger; }
    int getEnergy() const { return energy; }
};

int main() {
    DigitalPet pet(10, 90);
    pet.feed().sleep();
    pet.printStats();

    cout << "\n--- Testing prefix ++ ---" << endl;
    ++pet;
    pet.printStats();

    cout << "\n--- Testing postfix ++ ---" << endl;
    DigitalPet snapshot = pet++;
    cout << "Snapshot (before hour): ";
    snapshot.printStats();
    cout << "After hour: ";
    pet.printStats();

    return 0;
}
