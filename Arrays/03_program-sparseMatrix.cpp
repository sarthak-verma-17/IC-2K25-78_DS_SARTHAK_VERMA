
#include <iostream>
using namespace std;

int main() {
    int matrix[10][10], sparse[20][3];
    int rows, cols, k = 1;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }


    sparse[0][0] = rows;
    sparse[0][1] = cols;

    // Convert matrix to triple form
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k - 1;

    // Display triple representation
    cout << "\nSparse Matrix (Triple Representation):\n";
    cout << "Row\tColumn\tValue\n";

    for (int i = 0; i < k; i++) {
        cout << sparse[i][0] << "\t"
             << sparse[i][1] << "\t"
             << sparse[i][2] << endl;
    }

    return 0;
}

//calculator
// using swich case
#include <iostream>
using namespace std;

void inputMatrix(int matrix[10][10], int rows, int cols) {
    cout << "Enter matrix elements:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}


void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}