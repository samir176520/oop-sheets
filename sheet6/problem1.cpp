#include <iostream>
#include <cmath>

using namespace std;

class Data_x
{
    double x[30];
    int y, n;

public: 
    friend istream & operator >>(istream & in, data_x &d)
    {
        in >> d.n >> d.y;
        for (int i = 0; i < d.n; i++)
            in >> d.x[i];
    };

    friend ostream & operator <<(ostream & out, data_x d)
    {
        for (int i = 0; i < d.n; i++)
            out << d.x[i] << endl;
    };

    double sum()
    {
        double sum = 0;
        for(int i = 0; i < n; i++)
            sum += x[i];
        return sum;
    };
};

class Data
{
    
    Data_x A[30];
public:
    void read()
    {
        for(int i = 0; i < 30; i++)
        {
            B[i] = 0;
            for (int j = 0; i < A[i].n; j++)
            {
                if(int(A[i].x[j] + 0.5) % A[i] == 0)
                    B[i] += pow(A[i].x[j], 2);
                else
                    B[i] += pow(A[i].x[j], 3);
            }
        }
    }
}