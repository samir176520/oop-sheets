#include <iostream>
#include <cmath>

using namespace std;

class Base
{
protected:
    int B[30];
    int n;
public:
    void read()
    {
        cout << "Enter number of elements (n <= 30): ";
        cin >> n;

        cout << (n == 0 ? "" : "Enter the following numbers (integers): ");
        for (int i = 0; i < n; i++)
        {
            cout << "Enter number-" << i + 1 << ": ";
            cin >> B[i];
        }
    }

    int max()
    {
        int max = B[0];
        for (int  i = 1; i < n; i++)
            if (max < B[i])
                max = B[i];
        return max;
    }

    virtual long long fact()
    {
        long long factorial = 1, max_num = max();
        for (int i = 2; i <= max_num; i++)
            factorial *= i;
        return factorial;
    }
    
    void display()
    {
        cout << "Factorial of max number: " << this->fact() << endl;
    }
};

class Drive1 : virtual public Base
{
protected:
    long int D1[30];

public: 
    void set()
    {
        // Don't prompt for input again. Just calculate based on B values.
        for (int i = 0; i < n; i++)
        {
            if (B[i] % 2 == 0)
                D1[i] = (B[i] * (B[i] + 1) * (2 * B[i] + 1)) / 6; // calculate summation for i^2
            else
                D1[i] = pow(B[i] * (B[i] + 1) / 2, 2); // calculate summation for i^3
        }
    }

    int max()
    {
        int max = D1[0];
        for (int  i = 1; i < n; i++)
            if (max < D1[i])
                max = D1[i];
        return max;
    }

    long long fact()
    {
        long long factorial = 1, max_num = max();
        for (int i = 2; i <= max_num; i++)
            factorial *= i;
        return factorial;
    }
};

class Drive2 : virtual public Base
{
protected:
    long int D2[30];

public: 
    void set()
    {
        // Don't prompt for input again. Just calculate based on B values.
        for (int i = 0; i < n; i++)
        {
            D2[i] = 1; // multiplication start with one
            int temp = (B[i] == 0 ? 1 : B[i]); // condition in sheet to make multiplication done

            if (B[i] % 2 == 0)
                for (int j = 1; j < temp; j++)
                    D2[i] *= i * i;
            else
                for (int j = 1; j < temp; j++)
                    D2[i] *= i * i * i;
        }
    }

    int max()
    {
        int max = D2[0];
        for (int  i = 1; i < n; i++)
            if (max < D2[i])
                max = D2[i];
        return max;
    }

    long long fact()
    {
        long long factorial = 1, max_num = max();
        for (int i = 2; i <= max_num; i++)
            factorial *= i;
        return factorial;
    }
};

class Drive : public Drive1, public Drive2
{
protected:
    long int D[30];

public: 
    void set()
    {
        for (int i = 0; i < n; i += 3)
        {
            // D (D0 is max element in B, D1 is max element in D1, and D2 is the max element in D2)
            D[i] = Base::max();
            if (i + 1 < n)
                D[i + 1] = Drive1::max();

            if (i + 2 < n)
                D[i + 2] = Drive2::max(); // Fix: Assign to D[i + 2] instead of D[i + 1]
        }
    }

    long long fact()
    {
        long long summation = 0;
        // get sum for all elements of D
        for (int i = 0; i < n; i++)
            summation += D[i];

        long long factorial = 1;
        for (int i = 2; i <= summation; i++)
            factorial *= i;
        return factorial;
    }
};

int main() 
{
    Drive1 obj1;
    Drive2 obj2;
    Drive obj;
    Base obj_base;

    // Array of pointers to Base class
    Base *arr[4] = {&obj, &obj1, &obj2, &obj_base};


    // Call set() for the first time (only one input prompt for B)
    for (int i = 0; i < 4; i++)
        arr[i]->read(); // Calls Base::set()

    // set all elements for all objects inhertiened
    obj1.set();
    obj2.set();
    obj.set(); // for Drive::set()
    obj.Drive1::set();
    obj.Drive2::set();
    

    // Display results of each fact based on class defiened
    for (int i = 0; i < 4; i++) 
         arr[i]->display();

    return 0;
}
