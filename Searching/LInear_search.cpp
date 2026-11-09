
// linear search.
#include <iostream>
using namespace std;

#define N 5

class LS {
    int a[N], num;

public:
    LS() {
        cout << "Enter array elements: ";
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
    }

    void search();
    void display();
};

void LS::search() {
    int f = 0, i;

    cout << "Enter data to search: ";
    cin >> num;

    for (i = 0; i < N; i++) {
        if (a[i] == num) {
            f = 1;
            break;
        }
    }

    if (f == 1) {
        cout << "Element found at position " << i + 1;
    }
    else {
        cout << "Element not found";
    }
}

void LS::display() {
    cout << "Array elements are: ";

    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    LS s;
    int choice;
    char c;

    do {
        cout << "\n1. Search";
        cout << "\n2. Display";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.search();
                break;

            case 2:
                s.display();
                break;

            default:
                cout << "Invalid choice";
        }

        cout << "\nDo you want to continue? ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}