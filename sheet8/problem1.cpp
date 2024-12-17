#include <iostream>
#include <cmath>

using namespace std;

class Base
{
protected:
    int B[30];
    char T[30];
    int n;

public:
    void read()
    {
        cout << "Enter how much numbers (n <=30): ";
        cin >>n;
        cout << (n == 0? "": "Enter positive integars!\n"); // just for efficency
        for (int i = 0; i < n; i++)
        {
            cout << "Number-" << i + 1 << ": ";
            cin >> B[i];
        }
    }

    bool isPrime(int number) 
    {
        if (number <= 1) return false; // 0, 1, and negatives are not prime
        if (number == 2) return true;  // 2 is the only even prime number
        if (number % 2 == 0) return false; // Exclude other even numbers
        
        for (int i = 3; i <= sqrt(number); i += 2) // Check odd divisors up to sqrt(number)
            if (number % i == 0)
                return false;

        return true;
    }

    void set()
    {
        for (int i = 0; i < n; i++)
        {
            if (isPrime(B[i]))
                T[i] = 'Y';
            else
                T[i] = 'N';
        }
    }

    virtual long double average()
    {
        double sum = 0, counter = 0;
        for (int i = 0; i < n; i++)
            if (T[i] == 'T')
            {
                counter++;
                sum += B[i];
            }
        return sum / double(counter);
    }
};


class Derive : public Base
{
    long long F[30];
    int h;
public:

    int fact(int number) 
    {
        int result = 1;
        for (int i = 1; i <= number; i++) {
            result *= i;
        }
        return result;
    }

    void read()
    {
        cout << "Enter h constant (integar): ";
        cin >> h;
        
        for (int i = 0; i < n; i++)
            F[i] = fact(B[i]);
    }

    long double average()
    {
        long double sum = 0, counter = 0;
        for (int i = 0; i < n; i++)
            if (F[i] > h)
            {
                counter++;
                sum += F[i];
            }
        return sum / counter;
    }

};

int main()
{
    Derive obj;
    Base *ptr;
    ptr = &obj;

    ptr->read();                                // will call function Base class (kill override (if no virtual!))
    ptr->set();

    long double average_fact = ptr->average();       // will call the function in Derive beacasuse average is virtual

    obj.read();                                 // override will call the read in Derive
    long double average_prime = obj.Base::average(); // will call the function in Base however it's virtual or not
 
    cout << "Average of factorial of numbers Greater than constant is " << average_fact << endl;
    cout << "Average of prime numbers is " << average_prime << endl;

    // system("pause");
    return 0;
}