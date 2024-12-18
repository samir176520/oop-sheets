#include <iostream>
#include <cmath>

using namespace std;

class Base
{
protected:
    int B[30];
    int n;
public:
    void set()
    {
        cout << "Enter number of elements (n <= 30): ";
        cin >> n;

        cout << (n == 0? "": "Enter the following numbers (integars): ");
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

    virtual int fact()
    {
        int factorial = 1, max_num = max();
        for (int i = 2; i <= max_num; i++)
            factorial *= i;
        return factorial;
    }
    
    void display()
    {
        cout << "Factorial of max number: " << fact() << endl;
    }



};

class Drive1 : virtual public Base
{
protected:

    long int D1[30];

public: 
    void set()
    {
        for (int i = 0; i < n; i++)
        {
            
            if (B[i] % 2 == 0)
                    D1[i] = B[i] * (B[i] + 1) * (2 * B[i] + 1) / 6 ; // calculate summation for i ^ 2
            else
                    D1[i] = pow(B[i] * (B[i] + 1) /2 , 2); // calculate summation for i ^ 3 
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

    int fact()
    {
        int factorial = 1, max_num = max();
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
        for (int i = 0; i < n; i++)
        {
            D2[i] = 1; // multiblication start with one
            int temp = (B[i] == 0? 1: B[i]); // condattion in sheet to make multiplicton done

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

    int fact()
    {
        int factorial = 1, max_num = max();
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
            // D (D0 is max element in B, D1 is max element in D1, and D2 is the max element in D2),
            D[i] = Base::max();
            if (i + 1 < n)
                D[i + 1] = Drive1::max();

            if (i + 2 < n)
                D[i + 1] = Drive2::max();
        }
    }

    int fact()
    {
        int summation = 0;
        // get sum for all elements of D
        for (int i =0; i < n; i++)
            summation += D[i];

        int factorial = 1;
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

    Base *arr[3] = {&obj, &obj1, &obj2} ;
    

    arr[1]->Base::set(); // access the base to intialize first
    for (int i = 2; i > 0; i--)
        arr[i]->set(); // move to initialize items before items
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Fact value for Drive-" << i << " class: " << arr[i]->fact() << endl; // print fact for each one
        cout << "Max in Drive-" << i << " class: " << arr[i]->max() << endl;          // print each max for each class
    }

    arr[0]->display(); // 0, 1, 2 any thing no matter 


    // system ("pause");
    return 0;
          
}