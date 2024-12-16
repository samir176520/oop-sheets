#include <iostream>
#include <cmath>

using namespace std;

class Data_x
{
    double x[30];
    int y, n;

public: 
    friend istream& operator >>(istream& in, Data_x &d)
    {
        cout <<"Enter Lenth of input (x <= 30): ";
        in >> d.n;
        cout << "Enter constant y: ";
        in >> d.y;
        cout << "Enter " << d.n << " Elements: ";
        for (int i = 0; i < d.n; i++)
            in >> d.x[i];
        return in;
    };

    friend ostream& operator <<(ostream& out, Data_x d) 
    {
        for (int i = 0; i < d.n; i++)
            out << d.x[i] << "  ";
        cout << endl;
        return out;
    };

    double sum()
    {
        double sum = 0;
        for(int i = 0; i < n; i++)
            sum += x[i];
        return sum;
    };

    // like api 
    double operator[](int index)
    {
        return x[index];
    }

    friend class Data; // for access resons
};



class Data
{
    Data_x A[30];
    double B[30];
    

public:
    void read()
    {

        for(int i = 0; i < 30; i++)
        {
            cin >> A[i];
            B[i] = 0;
            for (int j = 0; j < A[i].n; j++)
            {
                if((int(A[i][j] + 0.5) % A[i].y) == 0)
                    B[i] += pow(A[i][j], 2);
                else
                    B[i] += pow(A[i][j], 3);
            }
        }
    }

    friend double sum(Data obj)
    {
        double sum;
        for (int i = 0; i < 30; i++)
            sum += obj.A[i].sum();
        return sum;
    }

    friend double max_sum(Data obj)
    {
        double sum[30];
        for (int i = 0; i < 30; i++)
            sum[i] = obj.A[i].sum();
        
        double max = sum[0];
        for (int i = 1; i < 30; i++)
        {
            if (max < sum[i])
                max = sum[i];
        }
        return max;
    }

    friend void compare(Data first, Data second)
    {
        if (max_sum(first) > max_sum(second))
        {
            cout << "max sum in first element: " << max_sum(first) << endl;
            for (int i = 0; i < 30; i++)
                cout << first.A[i];
        }
        else if (max_sum(first) < max_sum(second))
        {
            cout << "max sum in second element: " << max_sum(second)<< endl;
            for (int i = 0; i < 30; i++)
                cout << first.A[i];
        }
        else 
            cout << "Both are having the same max sum! \a\n";
    }
};

int main()
{
    Data first, second;
    cout << "enter elemnts for first object: \n";
    first.read();
    cout << "enter elemnts for second object: \n";
    second.read();

    if (sum(first) > sum(second))
        cout << "First have the biggest sum!\n";
    else if (sum(first) < sum(second))
        cout << "Second have the biggest sum!\n";
    else
        cout << "Both have the same summation!";
    
    cout << "comparing sum....\n";
    compare(first, second);

    //system("pause");
    return 0;

}