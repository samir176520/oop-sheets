/*Write a program contains: 
1.function to accept an integer number and display its reverse  
2.function to return the number of digits in a given number 
3.function to accept two numbers and multiply the first number by itself the number of times indicated by the second
number. 
In main function, define two integer numbers, and apply all functions on them.
*/
#include <iostream>
#include <cmath>

using namespace std;

void reverse(int number);

int lenth(int number);

int calc(int num, int power);

int main(void)
{
    int first, seconed;
    cout << "Enter first number :";
    cin >> first;
    cout << "Enter seconed number :";
    cin >> seconed;
    reverse(first);
    reverse(seconed);

    cout << "lenth of first is  "<< lenth(first) << endl;  
    cout << "lenth of seconed is  "<< lenth(seconed) << endl;

    cout << "first power seconed is "<< calc(seconed, first) << endl;  
    cout << "seconed power first is "<< calc(first, seconed) << endl;

    return 0;
}


//function to accept an integer number and display its reverse
void reverse(int number)
{
    int reversed_num = 0, digit;
    while (number)
    {
        // get the digit in begain 
        digit = number % 10;
        reversed_num = reversed_num * 10 + digit;
        number /= 10;        
    }
    cout << "revesed  is "<< reversed_num << endl;
}

// function to return the number of digits in a given number 
int lenth(int number)
{
    int counter = 0;
    
    do
    {
        counter++;
        number /= 10;
    }
    while (number);

    return counter;
}

// function to accept two numbers and multiply the first number by itself the number of times indicated by the second number. 
int calc(int num, int power)
{
    if (num == 0 && power == 0)
        cout << "Invaild value: both power and num can't be 0.\a\n";
        
        return pow(num, power);
}