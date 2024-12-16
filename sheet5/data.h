// This ensures the file’s content is included only once per translation unit.
#ifndef MYHEADER_H // if not defiened:  (if not defined): Checks if a unique macro (e.g., MYHEADER_H) is already defined.
#define MYHEADER_H // #define: If the macro isn’t defined, it defines it, ensuring the code between the #ifndef and #endif is only included once.

#include <iostream> // Include iostream for cin, cout, istream, and ostream
using namespace std; // Use the standard namespace

class Data {
private:
    double A[20], B[20];
    int n;

public:
    Data() : n(0) {} // initializing list

    // Operator >> (Input A elements)
    friend istream& operator>>(istream& in, Data& obj) 
    {
        cout << "Enter number of elements (<=20): ";
        in >> obj.n;
        cout << "Enter " << obj.n << " elements for A: ";
        for (int i = 0; i < obj.n; i++) 
            in >> obj.A[i];
        
        return in; // return 'in' allow chaining (e.g., cin >> obj >> anotherObj).
    }

    // Function to set B based on formula
    void setB() 
    {
        for (int i = 0; i < n; i++) 
        {
            B[i] = 0;
            for (int j = 0; j <= i; j++) 
                B[i] += (n - i + j) / ((A[j] == 0)? 1: A[j]); // Adjust if A[j] == 0
            // small hint remove the () around (A[j] == 0? 1: A[j] and you will discover a new error ;)

        }
    }

    // Operator << (Output A elements)
    friend ostream& operator<<(ostream& out, const Data& obj) {
        out << "Elements of A: ";
        for (int i = 0; i < obj.n; i++) {
            out << obj.A[i] << " ";
        }
        out << endl;
        return out;
    }

    // Operator [] (Access B)
    double operator[](int index) const {
        if (index >= 0 && index < n) return B[index];
        throw out_of_range("Index out of bounds"); // optianal no need to add it
    }

    // Operator double() - Average of A
    operator double() const // make sure that double operator will not change values
    {
        double sum = 0;
        for (int i = 0; i < n; i++) sum += A[i];
        return sum / n;
    }

    // Prefix and Postfix operators for A and reset B
    Data operator++() // prefix
    { 
        for (int i = 0; i < n; i++) A[i]++; setB();
        return *this; 
    }

    Data operator++(int) // postfix
    {
        Data temp = *this;
        for (int i = 0; i < n; i++) 
        A[i]++;
        setB();
        return temp;
    } // (int) is used by compiler to make it determine which is prefix and postfix

    Data operator-=(double number) 
    {
        for (int i = 0; i < n; i++) 
            A[i] -= number;
        setB();
        return *this;
    } 

    // Operator >= (Compare B arrays)
    bool operator>=(const Data& obj) const {
        for (int i = 0; i < n; i++) {
            if (B[i] < obj.B[i]) return false;
        }
        return true;
    }

    // Friend function to compare two objects and return max
    friend Data max(const Data& a, const Data& b) 
    {
        return (a >= b? a : b);
    }

    // Display B elements
    void displayB() const 
    {
        cout << "Elements of B: ";
        for (int i = 0; i < n; i++) cout << B[i] << " ";
        cout << endl;
    }
};
#endif // Ends the conditional check.