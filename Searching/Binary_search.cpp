
// Binary Search 
#include <iostream>
using namespace std;

#define MAX 10

class BS {
    int arr[MAX];

public:
    BS() {
        cout << "Enter array elements in sorted way: ";

        for (int i = 0; i < MAX; i++) {
            cin >> arr[i];
        }
    }

    void Bins(int num);
};

void BS::Bins(int num) {
    int lb = 0, ub = MAX - 1, mid, f = 0;

    while (lb <= ub) {
        mid = (lb + ub) / 2;

        if (arr[mid] == num) {
            f = 1;
            break;
        }
        else if (arr[mid] < num) {
            lb = mid + 1;
        }
        else {
            ub = mid - 1;
        }
    }

    if (f == 1) {
        cout << "Element found at position " << mid + 1;
    }
    else {
        cout << "Element not found";
    }
}

int main() {
    BS b;
    int x;

    cout << "Enter data to search: ";
    cin >> x;

    b.Bins(x);

    return 0;
}