
#include <iostream>
using namespace std;

// Function to input matrix
void inputMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Matrix Addition
void addMatrix() {
    int a[10][10], b[10][10], result[10][10];
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        cout << "Invalid matrix size!\n";
        return;
    }

    cout << "Enter first matrix:\n";
    inputMatrix(a, rows, cols);

    cout << "Enter second matrix:\n";
    inputMatrix(b, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "Result of addition:\n";
    displayMatrix(result, rows, cols);
}

// Matrix multiplication
void multiplyMatrix() {
    int a[10][10], b[10][10], result[10][10] = {0};
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10) {
        cout << "Invalid matrix size!\n";
        return;
    }

    cout << "Enter first matrix:\n";
    inputMatrix(a, r1, c1);

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if (r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10) {
        cout << "Invalid matrix size!\n";
        return;
    }

    if (c1 != r2) {
        cout << "Matrix multiplication is not possible.\n";
        return;
    }

    cout << "Enter second matrix:\n";
    inputMatrix(b, r2, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Result of multiplication:\n";
    displayMatrix(result, r1, c2);
}

// Matrix transpose
void transposeMatrix() {
    int matrix[10][10];
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        cout << "Invalid matrix size!\n";
        return;
    }

    cout << "Enter matrix:\n";
    inputMatrix(matrix, rows, cols);

    cout << "Transpose of matrix:\n";

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Determinant
void determinant() {
    int matrix[10][10];
    int n;

    cout << "Enter order of square matrix (2 or 3): ";
    cin >> n;

    if (n != 2 && n != 3) {
        cout << "Only 2x2 and 3x3 matrices are supported.\n";
        return;
    }

    cout << "Enter matrix:\n";
    inputMatrix(matrix, n, n);

    int det;

    if (n == 2) {
        det = matrix[0][0] * matrix[1][1]
            - matrix[0][1] * matrix[1][0];
    }
    else {
        det = matrix[0][0] * (matrix[1][1] * matrix[2][2]
                - matrix[1][2] * matrix[2][1])
            - matrix[0][1] * (matrix[1][0] * matrix[2][2]
                - matrix[1][2] * matrix[2][0])
            + matrix[0][2] * (matrix[1][0] * matrix[2][1]
                - matrix[1][1] * matrix[2][0]);
    }

    cout << "Determinant = " << det << endl;
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== MATRIX CALCULATOR =====\n";
        cout << "1. Addition\n";
        cout << "2. Multiplication\n";
        cout << "3. Transpose\n";
        cout << "4. Determinant\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addMatrix();
                break;

            case 2:
                multiplyMatrix();
                break;

            case 3:
                transposeMatrix();
                break;

            case 4:
                determinant();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
