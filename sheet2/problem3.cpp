/*
Write a program contains : 
1.class Data that has data members X[30](float), h(int), T[30]( char), 
    n (number of elements of X, T) contains. 
    1.1.a function to read data members, and to set the elements of T 
        such that each element Ti = ‘Y’ if Xi is divisible by h and ‘N’ otherwise, 
    1.2.a function to return the number of X’s elements that are not
        divisible by h by using T’ s elements, 
    1.3.a function to return the average of all elements of X that are divisible by h 
        by using T’ s elements
    1.4.function to display data members, 
    1.5.a function to compare between the X’s averages for two objects and 
        display the object with max value.
In main function, define two objects of Data class, and apply all functions on them.
*/


#include <iostream>

using namespace std;

#define limit 30

class Data 
{
    float X[limit];
    int h, n;
    char T[limit];

public :
    // constractor to initialize data members in decleration : (int, float, char (; مش احسن مننا)
    Data()
    {
        cout << "Enter how much numbers: ";
        cin >> n;

        // check user input (warrning here do not never ever input charcter to cin >> n) 
        // small tip Ctrl + c will save you 
        while (n <= 0)
        {
            n = 0;
            cout << "Problem3: Invalid value!" << endl 
                << "Enter positive integar from 1 to "<< limit << ": ";
            cin >> n;
        }

        cout << "Enter constant h: ";
        cin >> h;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter X " << i << " value: ";
            cin >> X[i];
            if (int(X[i] + 0.5) % h == 0)
                T[i] = 'Y';
            else
            T[i] = 'N';    
            
        }
    }

    void display()
    {
        cout << "Your constant is " << h << endl;
        cout << "Number of recordes " << n << endl;
        cout << "\tX\t" << "\tT\t"<< endl;
        for (int i =0; i < n; i++)
            cout << X[i] << "\t\t" << T[i] << endl;
    }

    int tracker_f()
    {
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (T[i] == 'F')
                counter++;
        }
        return counter;
    }

    float average()
    {
        float sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (T[i] == 'Y')
                sum += X[i];
        }
        return sum / (n - tracker_f());
    } 

    void compare(Data seconed)
    {
        if (average() > seconed.average())
            display();
        else
            seconed.display();
    }

};

int main()
{
    Data first, seconed;
    cout << "Avarege value for first set of data is " << first.average() << endl;
    cout << "Avarege value for seconed set of data is " << seconed.average() << endl;
    first.compare(seconed);
    return 0;
}
