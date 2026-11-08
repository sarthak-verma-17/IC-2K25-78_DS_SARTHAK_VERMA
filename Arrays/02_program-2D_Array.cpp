// 2d array 
#include <iostream>
using namespace std;

class Array2D {
    int arr[10][10], rows, cols;

public:
    void input() {
        cout << "Enter rows and columns: ";
        cin >> rows >> cols;

        cout << "Enter elements:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> arr[i][j];
    }

    void insert() {
        int r, c, value;
        cout << "Enter row, column and value: ";
        cin >> r >> c >> value;

        arr[r][c] = value;
    }

    void deleteElement() {
        int r, c;
        cout << "Enter row and column to delete: ";
        cin >> r >> c;

        arr[r][c] = 0;
    }

    void search() {
        int value;
        cout << "Enter value to search: ";
        cin >> value;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] == value) {
                    cout << "Element found at [" << i << "][" << j << "]\n";
                    return;
                }
            }
        }

        cout << "Element not found\n";
    }

    void rotate() {
        int temp[10][10];

        // Clockwise rotation
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp[j][rows - 1 - i] = arr[i][j];

        int oldRows = rows;
        rows = cols;
        cols = oldRows;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                arr[i][j] = temp[i][j];
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Array2D a;

    a.input();

    cout << "\nOriginal Array:\n";
    a.display();

    a.insert();
    cout << "\nAfter Insert:\n";
    a.display();

    a.deleteElement();
    cout << "\nAfter Delete:\n";
    a.display();

    a.search();

    a.rotate();
    cout << "\nAfter Rotation:\n";
    a.display();

    return 0;
}