#include <iostream>
#include <vector>
using namespace std;

void inputMatrix(vector<vector<int> >& matrix, int rows, int cols) {
    cout << "Enter the elements of the matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(const vector<vector<int> >& matrix, int rows, int cols) {
    cout << "Matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(const vector<vector<int> >& a, const vector<vector<int> >& b, vector<vector<int> >& c, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(const vector<vector<int> >& a, const vector<vector<int> >& b, vector<vector<int> >& c, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(const vector<vector<int> >& a, const vector<vector<int> >& b, vector<vector<int> >& c, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int m, n, o, p, choice;
    cout << "Choose operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n";
    cin >> choice;

    cout << "Enter rows and columns for matrix A (m * n): ";
    cin >> m >> n;
    vector<vector<int> > a(m, vector<int>(n));
    inputMatrix(a, m, n);

    cout << "Enter rows and columns for matrix B (o * p): ";
    cin >> o >> p;
    vector<vector<int> > b(o, vector<int>(p));

    if (choice != 3) {
        if (m != o || n != p) {
            cout << "Matrix operation not possible due to incompatible sizes." << endl;
            return 0;
        }
    }
    
    inputMatrix(b, o, p);
    vector<vector<int> > c(m, vector<int>(n));

    switch (choice) {
    case 1:
        addMatrices(a, b, c, m, n);
        displayMatrix(c, m, n);
        break;
    case 2:
        subtractMatrices(a, b, c, m, n);
        displayMatrix(c, m, n);
        break;
    case 3:
        if (n != o) {
            cout << "Multiplication not possible due to incompatible sizes." << endl;
            return 0;
        }
        c.resize(m, vector<int>(p));
        multiplyMatrices(a, b, c, m, n, p);
        displayMatrix(c, m, p);
        break;
    default:
        cout << "Invalid choice." << endl;
    }
    return 0;
}
