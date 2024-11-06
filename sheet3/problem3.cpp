/*
Write a program contains: 
two classes Ser1, Ser2. 
Class Ser1 has:
    data members SX[30] (float) , x[30] (float), n (number of elements), 
    a function to read data members and to set the elements of SX such that each SXi is equal to the formula for i=0,.., n-1, 
    a function to return max element in SX
    a function to display data members.
    
Class Ser2 has: 
    data members: SY[30](float), y[30] (float), m (number of elements), 
    a function to read data members and to set the elements of SY such that each SYi is equal to for i=0,..,m-1, 
    a function to return the max element in SY, 
    a function to display data members. 

These classes contain: 
    a friend function to compares between max elements for two given objects of two classes, and display the max object.
    a friend function to return the following average <formula> where SX and SY are data members for the given two objects.

In main function define two objects of two classes, and apply all functions on them.
*/
#include <iostream>
#include <cmath>

using namespace std;

class Ser2;

class Ser1
{
    float SX[30], x[30];
    int n = 0;
    
public:
    void read()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter values for x: ";
            cin >> x[i];
            SX[i] = 0;

            // calculate sumation for the each element in SX
            for(int j = 0; j <= i; j++)
                SX[i] += (j + i)/(pow(x[j], 2) + i + 1);
        }
    };

    float max()
    {
        float max = SX[0];
        
        for (int i = 1; i < n; i++)
            if (max < SX[i])
                max = SX[i];
        return max;
    };

    void display()
    {
        cout << "\tx value\t" << "\tSX value\t" << endl;

        for (int i = 0; i < n; i++)
            cout << x[i] << "\t\t" << SX[i] << endl;
    };

    friend void compare(Ser1 X, Ser2 Y);
    friend double average(Ser1 X, Ser2 Y);
};

class Ser2
{
    float SY[30], y[30];
    int m = 0;
    
public:
    void read()
    {
        cout << "Enter number of elements: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cout << "Enter values for x: ";
            cin >> y[i];
            SY[i] = 0;

            // calculate sumation for the each element in SX
            for(int j = 0; j <= i; j++)
                SY[i] += (j + i)/(pow(y[j], 3) + i + 1);
        }
    };

    float max()
    {
        float max = SY[0];
        
        for (int i = 1; i < m; i++)
            if (max < SY[i])
                max = SY[i];
        return max;
    };

    void display()
    {
        cout << "\ty value\t" << "\tSY value\t" << endl;

        for (int i = 0; i < m; i++)
            cout << y[i] << "\t\t" << SY[i] << endl;
    };

    friend void compare(Ser1 X, Ser2 Y);
    friend double average(Ser1 X, Ser2 Y);
};

int main()
{
    Ser1 X;
    Ser2 Y;

    X.read();
    Y.read();

    cout << "Average value: " << average(X, Y) << endl;

    compare(X, Y);
    return 0;
}

// note this is procdure
void compare(Ser1 X, Ser2 Y)
{
    if (X.max() > Y.max())
        X.display();
    else if (X.max() < Y.max())
        Y.display();
    else 
        cout << "both have the same max value\a!" << endl;
}

double average(Ser1 X, Ser2 Y)
{
    return (X.SX[0] + X.SX[X.n - 1] + Y.SY[0] + Y.SY[Y.m - 1]) / 4;
}

