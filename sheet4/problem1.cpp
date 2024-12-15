/*1. Write a program contains a class Data that has data members:
    D[30] (int), F[30] (double), n(number of elements). 
This class contains the following:
     i. Function to return the value of aCb for two given positive integer numbers (if not convert them).
    ii. Function to read data members D, n.
   iii. Function to set the elements of F such that each Fi is equal to for i=0 ,.., n-1 ( Dk ≠ 0 if not increase it by one) .
    iv. Function to return the sum of elements of F.
     v. Function to display the data members in table form.
    vi. Operators: +, constant + (increase each element of D by this constant, and set the elements of F for the returned object).
   vii. Operators: < (compare only the sum of elements of F),!= (compare only D).
  viii. A friend function to compare between two objects (sum of elements of F for two objects), and to return max sum.
In main function, define several objects and apply all functions and operators on them.
*/
#include <iostream>

using namespace std;

float factorial(int number);

class Data
{
    int D[30];
    double F[30];
    int n;

public: // methods
    float positive(int a, int b)
    {
        a = (a < 0)? -a : a; // ensure numbers is positive
        b = (b < 0)? -b : b;
        
        return factorial(a) / (factorial(((a - b) < 0)? -(a - b): (a - b)) * float(factorial(b)));
    };

    void read()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter [" << i + 1 << "] number: ";
            cin >> D[i];
        }
        set();
    };

    void set()
    {
        int temp;

        for (int i = 0; i < n; i++)
        {
            temp = D[i];
            temp = (temp > 0)? temp : (temp == 0)? 1 : -temp; // nested ternary condation {we doing some good work here <3}
            for (int j = 0; j <= i + 1; j++)
                F[i] =  positive(i, j) * temp ;
        }
    };

    double sum()
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += F[i];

        return sum;
    };

    void display()
    {
        cout << "\tData\t\tFormula\n";
        for (int i = 0; i < n; i++)
            cout << D[i] << "\t\t" << F[i] << endl;
    };

    // Operators: +, constant + (increase each element of D by this constant, and set the elements of F for the returned object).
    Data operator+(Data object)
    {
       if (n > object.n)
       {
           for (int i = 0; i < object.n; i++)
               D[i] += object.D[i];
           set();
           return *this;  // 'this' return pointer of this class, * is derefrence operator {return values stored in memory} 
       }
       else if (n < object.n)
       {
           for (int i = 0; i < n; i++)
               object.D[i] += D[i];
           object.set();
           return object;
       }
       else{
           for (int i = 0; i < n; i++)
               object.D[i] += D[i];
           object.set();
           return object;
       }
    };

    friend Data operator+(int number, const Data &object)
    {
        Data sum;
        for (int i = 0; i < object.n; i++)
            sum.D[i] = object.D[i] + number;
        sum.n = object.n;
        sum.set();
        return sum;  
    };

     // Operators: < (compare only the sum of elements of F),!= (compare only D).
    bool operator<(Data object)
    {
        if (sum() < object.sum())
            return true;
        else
            return false;
    }

    bool operator!=(Data object)
    {
        if (object.n == n)
            return false;

        else if (object.n > n)
        {
            for (int i = 0; i < n; i++)
                if (D[i] == object.D[i])
                    return false;
        }
        else
        {
            for (int i = 0; i < object.n; i++)
                if (D[i] == object.D[i])
                    return false;
        }
        return true;
    };

   

};

int main()
{
    Data first, seconed, sum;
    first.read();
    seconed.read();

    if (first != seconed)
        sum = first + seconed;
    else
        cout << "they are the same!\n";

    int number;
    cout << "Enter positive number to start comparison: ";
    cin >> number;

    first = number + first;
    if (sum < first)
        cout << "Good choice!\n";
    else
    {
        cout << "still sum is greater after add number";
        sum.display();
    }
    // system("pause");
    return 0;
}

float factorial(int number) // let's do same recursive edition
{
    // base case
    if (number == 0 || number == 1)
        return 1;
    else
        return number * factorial(number - 1); // pre will takecare of all stuff
}


