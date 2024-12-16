#include <iostream>
#include "mark.h"

using namespace std;

int main() {
    Mark m1, m2;

    cin >> m1;
    m1.setLastRow();
    cout << m1;

    m1.displayLastRow();
    cout << "Average of diagonal: " << double(m1) << endl; // operator double use

    // Compare matrices
    cin >> m2;
    m2.setLastRow();
    Mark mMin = min(m1, m2);
    cout << "Matrix with minimum comparison result:\n";
    mMin.displayLastRow();

    cout << "after m1-- ";
    m1--;
    cout << m1;
    m1.displayLastRow();

    // index access
    int index;
    cout << "which element you want access in last row in B for second object?:";
    cin >> index;
    cout << "Element values is " << m2[index] << endl;

    //system("pause");
    return 0;
}
