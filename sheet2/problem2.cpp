/*
Write a program contains :
1.a function to return the factorial of a given positive integer number 
        (check if the given number negative convert it).
2.the structure Series that has data members: a (float), X[20] (float), S[20] (double) ,
        n ( number of array’s elements) and contain function members :
            2.1.function to read data members and set the elements of S such that each
                element from k = 0 to i Si = iCk xi * (a {power} (i - k)) for i=0, ..,n-1 by using factorial
            2.2.function, a function to return the maximum number in S.
            2.3.function to display data members X, S in tabular form. 
3.main function : 
    3.1.define two objects of Series and display the difference between max values for them.
    3.2.compare between them and display the object with max value.
*/
#include <iostream>
#include <cmath>

using namespace std;

int fact(int number);

struct series
{
    float a, X[20];
    double S[20] = {0};
    int n;
    void scan()
    {
        cout << "Enter how much numbers in the sereis :";
        cin >> n;
        cout << "Enter constant 'a' :";
        cin >> a;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter X "<< i << " value :";
            cin>>X[i];

            // calculate S value from the {formula} 
            for (int k = 0; k < i; k++)
            {
                // iCk = fact(i) / fact(i-k) * fact(k) // توافيق
                 S[i] += (fact(i)/fact(i-k) * fact(k))  * X[i] * pow(a,i - k); // calculate S array values
            }
        }        
    }

    void print() // my style in print tabuler form
    {
        // \t add 4 spaces
        cout<< "\tX\t" << "\tS\t\n";
        for (int i = 0; i < n; i++)
            cout << X[i] <<"\t\t" <<S[i]<<endl;
    };
    
    double max()
    {
        double max = S[0];
        for (int i = 1; i < n; i++)
            if (max < S[i])
                max = S[i];
        return max;
    };
};


int main()
{
    series first, seconed;
    first.scan();
    seconed.scan();
 
    cout << "Diffrence between max values is " << abs(first.max() - seconed.max()) << endl;
    if (first.max() > seconed.max())
        first.print();
    else 
        seconed.print();
    
    //system("pause");
    return 0;
}

int fact(int number)
{
    number = (number < 0)? -number: number; // ternary if statement

    int factorail = 1;
    while (number > 0)
    {
        factorail *= number;
        number--;
    }
    return factorail;
}