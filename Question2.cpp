#include <iostream>
#include <iomanip>
using namespace std;

class TransitCard {
private:
    double balance;
    bool isActiveTrip;

public:
    TransitCard(double initialBalance) : balance(initialBalance), isActiveTrip(false) {}

    void tapIn() {
        if (isActiveTrip) {
            cout << "Error: Already on an active trip!" << endl;
        } else if (balance < 2.50) {
            cout << "Error: Insufficient balance. Minimum $2.50 required." << endl;
        } else {
            isActiveTrip = true;
            cout << "Tap-in successful." << endl;
        }
    }

    void tapOut() {
        if (!isActiveTrip) {
            cout << "Error: Cannot tap out, no active trip!" << endl;
        } else {
            balance -= 2.50;
            isActiveTrip = false;
            cout << fixed << setprecision(2);
            cout << "Tap-out successful. Remaining balance: $" << balance << endl;
        }
    }

    TransitCard& operator-=(double penalty) {
        balance -= penalty;
        if (balance < 0) balance = 0;
        cout << fixed << setprecision(2);
        cout << "Penalty of $" << penalty << " applied. Remaining balance: $" << balance << endl;
        return *this;
    }

    bool operator!() const {
        return balance == 0.0;
    }

    double getBalance() const { return balance; }
};

int main() {
    TransitCard card(5.00);
    card.tapIn();
    card.tapIn();
    card.tapOut();
    card.tapOut();
    if (!card) {
        cout << "Empty!" << endl;
    }

    cout << "\n--- Testing -= penalty operator ---" << endl;
    TransitCard card2(10.00);
    card2 -= 5.00;

    return 0;
}
