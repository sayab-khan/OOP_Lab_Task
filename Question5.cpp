#include <iostream>
using namespace std;

class CinemaRow {
private:
    bool* seats;
    int numSeats;

public:
    CinemaRow(int n) : numSeats(n) {
        seats = new bool[numSeats];
        for (int i = 0; i < numSeats; i++) {
            seats[i] = false;
        }
        cout << "Cinema row with " << numSeats << " seats created." << endl;
    }

    void bookSeat(int index) {
        if (index < 0 || index >= numSeats) {
            cout << "Error: Seat index " << index << " is out of bounds." << endl;
        } else if (seats[index]) {
            cout << "Error: Seat " << index << " is already booked." << endl;
        } else {
            seats[index] = true;
            cout << "Seat " << index << " booked successfully." << endl;
        }
    }

    bool operator[](int index) const {
        if (index < 0 || index >= numSeats) {
            cout << "Error: Index out of bounds." << endl;
            return false;
        }
        return seats[index];
    }

    ~CinemaRow() {
        delete[] seats;
        cout << "Row memory freed." << endl;
    }
};

int main() {
    CinemaRow row(5);
    row.bookSeat(2);
    row.bookSeat(2);
    row.bookSeat(8);
    cout << "Is seat 2 booked? " << (row[2] ? "Yes" : "No") << endl;

    return 0;
}
