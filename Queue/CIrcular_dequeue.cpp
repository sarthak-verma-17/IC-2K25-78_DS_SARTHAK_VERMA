
// Circular Dequeue implementation in C++ using arrays
#include <iostream>
using namespace std;

class Deque {
    static const int SIZE = 4;
    int a[SIZE], f, r, n;

public:
    Deque() {
        f = -1;
        r = -1;
    }

    void insert_r();
    void insert_f();
    void delete_f();
    void delete_r();
    void display();
};

void Deque::insert_r() {
    if ((f == 0 && r == SIZE - 1) || (f == r + 1)) {
        cout << "Queue overflow";
    }
    else {
        cout << "Enter data: ";
        cin >> n;

        if (f == -1) {
            f = 0;
            r = 0;
        }
        else {
            r = (r + 1) % SIZE;
        }

        a[r] = n;
    }
}

void Deque::delete_f() {
    if (f == -1) {
        cout << "Queue underflow";
    }
    else {
        n = a[f];
        cout << "Deleted element: " << n;

        if (f == r) {
            f = -1;
            r = -1;
        }
        else {
            f = (f + 1) % SIZE;
        }
    }
}

void Deque::insert_f() {
    if ((f == 0 && r == SIZE - 1) || (f == r + 1)) {
        cout << "Queue is full";
    }
    else {
        cout << "Enter data: ";
        cin >> n;

        if (f == -1) {
            f = 0;
            r = 0;
        }
        else if (f == 0) {
            f = SIZE - 1;
        }
        else {
            f = f - 1;
        }

        a[f] = n;
    }
}

void Deque::delete_r() {
    if (f == -1) {
        cout << "Queue underflow";
    }
    else {
        n = a[r];
        cout << "Deleted element: " << n;

        if (f == r) {
            f = -1;
            r = -1;
        }
        else if (r == 0) {
            r = SIZE - 1;
        }
        else {
            r = r - 1;
        }
    }
}

void Deque::display() {
    if (f == -1) {
        cout << "Queue has no element";
    }
    else {
        cout << "Deque elements: ";

        for (int i = f; ; i = (i + 1) % SIZE) {
            cout << a[i] << " ";

            if (i == r) {
                break;
            }
        }
    }
}

int main() {
    Deque dq;
    int choice;
    char c;

    do {
        cout << "\n\n1. Insert Rear";
        cout << "\n2. Insert Front";
        cout << "\n3. Delete Rear";
        cout << "\n4. Delete Front";
        cout << "\n5. Display";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dq.insert_r();
                break;

            case 2:
                dq.insert_f();
                break;

            case 3:
                dq.delete_r();
                break;

            case 4:
                dq.delete_f();
                break;

            case 5:
                dq.display();
                break;

            default:
                cout << "Invalid choice";
        }

        cout << "\n\nYou want to continue (y/n): ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}