#include <iostream>
using namespace std;

class Elevator {
private:
    int currentFloor;
    double currentWeight;
    const double maxWeight;

public:
    Elevator(int floor = 1, double weight = 0.0)
        : currentFloor(floor), currentWeight(weight), maxWeight(500.0) {}

    Elevator& loadPassenger(double weight) {
        if (currentWeight + weight > maxWeight) {
            cout << "Error: Weight exceeds 500.0kg. Passenger rejected." << endl;
        } else {
            currentWeight += weight;
            cout << "Passenger loaded. Current weight: " << currentWeight << "kg" << endl;
        }
        return *this;
    }

    Elevator& goToFloor(int floor) {
        if (floor < 1 || floor > 10) {
            cout << "Error: Floor " << floor << " is out of bounds." << endl;
        } else {
            currentFloor = floor;
            cout << "Moving to floor " << currentFloor << endl;
        }
        return *this;
    }

    bool operator==(const Elevator& other) const {
        return currentFloor == other.currentFloor;
    }

    int getFloor() const { return currentFloor; }

    ~Elevator() {
        cout << "Elevator powering down at floor " << currentFloor << "." << endl;
    }
};

int main() {
    Elevator e1(1, 0);
    e1.loadPassenger(400.0).loadPassenger(150.0).goToFloor(5).goToFloor(12);

    cout << "\n--- Testing == operator ---" << endl;
    Elevator e2(5, 0);
    e2.goToFloor(5);
    if (e1 == e2)
        cout << "Both elevators are on the same floor." << endl;
    else
        cout << "Elevators are on different floors." << endl;

    return 0;
}
