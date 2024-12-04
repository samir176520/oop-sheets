#include <iostream>

using namespace std;

#define limit 100

void read(int arr[], int &n);
void display(int arr[], int n);
int reverse(int number);
int search(int arr[], int n, int target);
void change(int arr[], int n, int target,int new_num);

int main()
{
    int arr[limit], n, target;

    read(arr, n);

    cout << "Enter element to reverse it: ";
    cin >> target;

    change(arr, n, target, reverse(target));
    display(arr, n);

    //systeam("pause")
    return 0;
}

void read(int arr[], int &n) // should be call by refrence
{
    cout << "enter number of numbers: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " number: ";
        cin >> arr[i];
    }
}
void display(int arr[], int n)
{
    cout << "numbers are....\n";
    for (int i = 0; i < n; i++) // my own style
    {
        while(i < 5 && i < n)
        {
            cout << arr[i] << '\t';
            i++;
        }
        cout << endl;
    }
}

int reverse(int number)
{
    int revNumber = 0, digit = 0;
    while(number != 0)
    {
        digit = number % 10;
        revNumber = revNumber * 10 + digit;
        number /= 10;
    }

    return revNumber;
}

int search(int arr[], int n, int target) // linear search algorithm
{
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

void change(int arr[], int n, int target, int new_num)
{
    arr[search(arr, n, target)] = new_num;
}
