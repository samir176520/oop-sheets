/*Write a program contains:
    a class GCD that has data members: 
        A[30](int), B[30](int), G[30](int), n(number of elements).
    It contains methods:
        function to return the greatest common divisor for two given positive numbers (recursive function)  
        function to read data members, and set the elements of G such that each Gi is the greatest common divisor for Ai and Bi for i=0,..,n-1. It 
        function to display data members in tabular form. 
        This class contains a friend function that returns the average of all elements of G which are greater than 3 for a given object 
        friend function compares between the averages for two given objects and returns the max object. 
    In main function define two objects, and apply all functions on them.
*/
#include <iostream>

#define limit 30

using namespace std;

class GCD
{
    int A[limit], B[limit], G[limit], n;
  
public :
    int gcd(int a,int b)
    {
        if ( b == 0)
            return a;
        else
            return gcd(b, a % b);
    };

    void read()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " element in first array: ";
            cin >> A[i];

            cout << i + 1 << "element in seconed array: ";
            cin >> B[i];

            // ensure that the greatest one is the first
            if (A[i] > B[i])
                G[i] = gcd(A[i], B[i]);
            else
                G[i] = gcd(B[i], A[i]);
        }
    };

    void display()
    {
        cout << "\tA\t" << "\tB\t" << "\tG\t" << endl;
        for (int i = 0; i < n; i++)
            cout << A[i] << "\t\t" << B[i] << "\t\t" << G[i] << endl;

        cout << "Number of elements: " << n << endl;
    };

    friend double average(GCD object)
    {
        double sum = 0;
        int counter = 0;
        for (int i = 0; i < object.n; i++)
            if (object.G[i] > 3)
            {
                sum += object.G[i];
                counter++;
            }
        return sum / counter;
    };

    friend GCD compare(GCD first, GCD second)
    {
        if (average(first) > average(second))
            return first;
        else
            return second;
    };

    // overload function to help me with finding the greatest object after calculate it from the  
    bool operator ==(GCD one)
    {
        if (n != one.n)
            return false;

        for (int i = 0; i < n; i++)
            if (G[i] != one.G[i])
                return false;
        return true;
    };

};

int main()
{
    GCD first, second;

    first.read();
    second.read();

    // my way to use all functions of array
    if (compare(first, second) == first)
        first.display();
    else
        second.display();
    
    return 0;
}
