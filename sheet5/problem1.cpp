#include <iostream>
#include "data.h"

using namespace std;

int main() {
    Data d1, d2;

    // Input and set B
    cin >> d1;
    d1.setB();
    cout << d1;
    d1.displayB();

    // Demonstrate average operator
    cout << "Average of A: " << double(d1) << endl;

 

    // Demonstrate prefix increment
    cout << "After ++d1:\n";
    ++d1;
    cout << d1;
    d1.displayB();

    // Compare two objects
    cin >> d2;
    d2.setB();
    cout << "Comparing two objects, max is:\n";
    Data dMax = max(d1, d2);
    dMax.displayB();
    
    // index access
    int index;
    cout << "which element you want access in B for second object?:";
    cin >> index;
    cout << "Element values is " << d1[index] << endl;

    //system("pause");
    return 0;
}