// This ensures the file’s content is included only once per translation unit.
#ifndef MYHEADER_H // if not defiened:  (if not defined): Checks if a unique macro (e.g., MYHEADER_H) is already defined.
#define MYHEADER_H // #define: If the macro isn’t defined, it defines it, ensuring the code between the #ifndef and #endif is only included once.

#include <iostream> // Include iostream for cin, cout, istream, and ostream
using namespace std; // Use the standard namespace

// class for problem2.cpp
class Mark {
private:
    double M[20][20];
    int n, m; // Dimensions of matrix n rows, m colums

public:
    Mark() : n(0), m(0) {} // initializing list

    // Operator >> (Input elements except last row)
    friend istream& operator>>(istream& in, Mark& obj) 
    {
        cout << "Enter matrix dimensions (rows, columns <= 20): ";
        in >> obj.n >> obj.m;
        cout << "Enter elements of matrix (except last row):\n";
        for (int i = 0; i < obj.n - 1; i++) 
            for (int j = 0; j < obj.m; j++) 
                in >> obj.M[i][j];
            
        return in;
    }

    // Function to set last row elements
    void setLastRow() 
    {
        for (int i = 0; i < m; i++) 
        {
            M[n - 1][i] = 0;
            for (int j = 0; j < n - 1; j++) 
                M[n - 1][i] += M[j][i] / (n - 1);
        }
    }

    // Operator << (Output elements except last row)
    friend ostream& operator<<(ostream& out, const Mark& obj) 
    {
        out << "Matrix elements (except last row):\n";
        for (int i = 0; i < obj.n - 1; i++) 
        {
            for (int j = 0; j < obj.m; j++) 
                out << obj.M[i][j] << " ";
            
            out << endl;
        }
        return out;
    }

    // Operator [] (Access last row)
    double operator[](int index) const 
    {
        if (index >= 0 && index < m) return M[n - 1][index];
        throw out_of_range("Index out of bounds");
    }

    // Operator double() - Average of diagonal elements
    operator double() const 
    {
        double sum = 0;
        for (int i = 0; i < n && i < m; i++) sum += M[i][i];
        return sum / n;
    }

    // --Prefix/postfix += operator

        // Prefix and Postfix operators for A and reset B
    Mark operator--() // prefix
    { 
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m ;j++)
                M[i][j]--; 
        setLastRow();
        return *this; 
    }

    Mark operator--(int) // postfix
    {
        Mark temp = *this;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m ;j++)
                M[i][j]--; 
        setLastRow();
        return temp;
    } // (int) is used by compiler to make it determine which is prefix and postfix

    void operator+=(int x) { for (int i = 0; i < n; i++) M[i][0] += x; }

    // Operator > (Compare matrices)
    bool operator>(const Mark& obj) const {
        return M[0][0] > obj.M[0][0];
    }

    // Friend function to find minimum object
    friend Mark min(const Mark& a, const Mark& b) {
        return (a > b) ? b : a;
    }

    void displayLastRow() const {
        cout << "Last row elements: ";
        for (int i = 0; i < m; i++) cout << M[n - 1][i] << " ";
        cout << endl;
    }
};

#endif //  Ends the conditional check.