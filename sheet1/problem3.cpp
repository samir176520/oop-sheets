/*
Write a program contains : 
1.function to read an array of n integer numbers 
2.function to test a given number prime or not
3.function to test a given number even or not. 
4.Write two versions of overloaded functions, 
    4.1 the first version function returns the average of all prime numbers in a given array. 
    4.2 the second version returns the average of even numbers or the average of odd numbers 
            in a given array according to the value of a given character 
                (‘E’ or ‘e’) or (‘O’ or ‘o’). 
In main function, define an array of m integer numbers, character c, 
    and apply all functions on them.
*/
#include <iostream>

using namespace std;

#define limit 1000 // like define a constant (more related to clean-code)

// prototype more clear and beatifull is it.
void read(int number[],int n);

bool isprime(int number);

bool iseven(int number);

float avarge(int numbers[], int n);

float avarge(int numbers[], int n, char type); // overloading function notice how i used diffrents argumments

int main(void)
{
    int numbers[limit], n;
    char type;
    
    cout << "How much numbers you will input?: ";
    cin >> n;

    cout << "calculate avarge for (e)ven or (o)dd : ";
    cin >> type;

    read(numbers, n);

    cout << "Avarge for prime numbers is " << avarge(numbers, n) << endl;

    cout << "Avarge for your choise is " << avarge(numbers, n, type) << endl;

    // system("pause");
    return 0;
}


void read(int numbers[],int n) // array is call by refrence by defult
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter ["<< i << "] number: ";
        cin >> numbers[i];
    }
}

bool isprime(int number)
{ 
    // prime is a natural numbers has no divisors other than 1 and itself
    if (number <= 0)
        return false;

    // some math done here.......
    for (int i = 2, num = number / 2; i < num; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

bool iseven(int number)
{
    if (number % 2 == 0)
        return true;
    else
        return false;
}

float avarge(int numbers[], int n)
{
    int counter = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (isprime(numbers[i]))
        {
            sum += numbers[i];
            counter++;
        }
    }
    return sum / float(counter);
}

// over loading function note how i used diffrents argumments
float avarge(int numbers[], int n, char type)
{
    int sum = 0, counter = 0;
    switch (type) // switch is more fast than if condations sometime....
    {
    case 'e' :
        for (int i = 0; i < n; i++)
        {
            if (iseven(numbers[i]))
            {
                sum += numbers[i];
                counter++;
            }
        }
        break;

    case 'o' :
        for (int i = 0; i < n; i++)
        {
            if (!iseven(numbers[i]))
            {
                sum += numbers[i];
                counter++;
            }
        }
        break;
    }
    return sum / float(counter); // type-casting is needed (int) / (int) = (int)
}
