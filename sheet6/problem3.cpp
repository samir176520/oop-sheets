#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Data1 
{
protected: // we are just growed <3
    string S1;
    double D1[20];
    int a, n;
public:
    void readData1() 
    {
        cout << "Enter S1 (string): ";
        cin >> S1;
        cout << "Enter n (number of elements): ";
        cin >> n;
        cout << "Enter elements of D1: ";
        for (int i = 0; i < n; i++) 
            cin >> D1[i];
        
        cout << "Enter a (integer): ";
        cin >> a;
    }

    double sum1() 
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
            {
                if (/*type casting*/int(D1[j] + 0.5)  % a == 0)
                    sum += pow(D1[j], 2*(j + 1));
                else
                    sum += pow(D1[j], j + 1);
            }
        return sum;
    }

    void display1()
    {
        cout << "string is " << S1 << endl;
        cout << "constant is " << a << endl;

        cout << "elemnts of D1:"<< endl;
        for (int i = 0 ;i < n; i++) // just for style
        {
            cout << D1[i];
            cout << ((i + 1) % 5 == 0 && i != 0? "\n": "  ");
        }   
    }
};

class Data2 
{
protected:
    string S2;
    double D2[20];
    int m, b;
public:
    void readData2() 
    {
        cout << "Enter S2 (string): ";
        cin >> S2;
        cout << "Enter m (number of elements): ";
        cin >> m;
        cout << "Enter elements of D2: ";
        for (int i = 0; i < m; i++) {
            cin >> D2[i];
        }
        cout << endl;
    }

    double sum2() 
    {
        double sum = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j <= i; j++)
            {
                if (D2[j]  > b)
                    sum += pow(D2[j], 2*(j + 1));
                else
                    sum += pow(D2[j], j + 1);
            }
        return sum;
    }

        void display2()
    {
        cout << "string is " << S2 << endl;
        cout << "constant is " << b << endl;

        cout << "elemnts of D1:"<< endl;
        for (int i = 0 ;i < m; i++) // just for style
        {
            cout << D2[i];
            cout << ((i + 1) % 5 == 0 && i != 0?  "\n": "  ");
        } 
        cout << endl;
    }
};

class Data : public Data1, public Data2 
{
private:
    string ND;
    int T_sum;
public:
    void calculateSum() {
        T_sum = sum1() + sum2();
    }

    void display() 
    {
        display1();
        display2();
        cout << "ND: " << ND << ", Total Sum: " << T_sum << endl;
    }
};

int main() 
{
    Data d;
    d.readData1();
    d.readData2();
    d.calculateSum();
    d.display();

    //system("pause");
    return 0;
}
