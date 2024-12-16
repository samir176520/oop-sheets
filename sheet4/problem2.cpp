#include <iostream>

using namespace std;

// Class definition
class Student {
private:
    float SM[10][10];
    int n;

public:
    // Function to read matrix except last column
    void readData() 
    {
        cout << "Enter the size of the matrix (n x n, n <= 10): ";
        cin >> n;
        cout << "Enter elements of the matrix (excluding last column):\n";
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n - 1; j++) 
                cin >> SM[i][j];
        setLastColumn();
    }

    float sum(int i)// return sum of rows
    {
            float sum = 0;
            for (int j = 0; j < n - 1; j++) 
                sum += SM[i][j];
            return sum;
    }

    // Function to set the last column (row sums)
    void setLastColumn() 
    {
        for (int i = 0; i < n; i++) 
        {
            SM[i][n - 1] = sum(i);
        }
    }

    // Function to display matrix
    void displayMatrix() 
    {
        cout << "Matrix (SM):\n";
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
                cout << '\t' << SM[i][j];
            
            cout << endl;
        }
    }

    // Overload * operator to multiply matrix by constant
    Student operator*(float constant) 
    {
        Student temp;
        temp.n = n;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n - 1; j++) 
                temp.SM[i][j] = SM[i][j] * constant;
            
        temp.setLastColumn();
        return temp;
    }

    // Overload == operator (only last column)
    bool operator==(const Student &obj) 
    {
        for (int i = 0; i < n; i++) 
            if (SM[i][n - 1] != obj.SM[i][n - 1])
                return false;
        
        return true;
    }

    // Overload >= operator (only last column)
    bool operator>=(const Student &obj) 
    {
        for (int i = 0; i < n; i++) 
            if (SM[i][n - 1] < obj.SM[i][n - 1])
                return false;
        
        return true;
    }

    // Friend function to compare and display max object
    friend void compareMax(Student &a, Student &b);
};

// Friend function to compare two objects and display max
void compareMax(Student &a, Student &b) {
    cout << "\nComparing two objects (last column):" << endl;
    if (a >= b)
        cout << "First object has greater or equal row sums in the last column." << endl;
    else
        cout << "Second object has greater row sums in the last column." << endl;
}

// Main Function
int main() {
    Student obj1, obj2, result;
    float constant;

    cout << "Enter data for first object:" << endl;
    obj1.readData();

    cout << "\nEnter data for second object:" << endl;
    obj2.readData();

    cout << "\nFirst Object Matrix:" << endl;
    obj1.displayMatrix();

    cout << "\nSecond Object Matrix:" << endl;
    obj2.displayMatrix();

    // Multiplication by constant
    cout << "\nEnter constant to multiply with the matrix: ";
    cin >> constant;
    result = obj1 * constant;

    cout << "\nResult after multiplying first object by constant:" << endl;
    result.displayMatrix();

    // Compare two objects
    compareMax(obj1, obj2);

    return 0;
}
