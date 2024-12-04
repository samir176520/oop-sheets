/*
Write a program :
1.defines two structures Data and Employee. 
    1.1.Date has data members: name (int), age (float), salary (float), tax (float).
    1.2.Employee has data members: E (Data) net_s(float), 
        1.2.1.function to read data members and set the value of the net_s(net salary),
        1.2.2. function to display data members.
2.in this program write a function to swap two Employee objects 
3.In main function, define an array of m Employees, read it, 
    sort it in ascending order according to the value of net_s (use swap function), 
    3.1.compute the difference between the min and max net salaries. 
    3.2.Finally, display the elements of array in a tabular form.
*/
#include <iostream>

#define limit 30 // 30 is a magic number do your resarech :)

using namespace std;

struct Data 
{
    int name;
    float age, salary, tax;

}; 

struct employee 
{
    Data E;
    float net_s;

    void read()
    {
        cout << "Enter the following employee deteils (format: (id-name age salary tax): ";
        cin >> E.name >> E.age >> E.salary >> E.tax;

        // suppose tax in only one number after decimal point 
        net_s = E.salary - (E.salary * E.tax);
    };

    void diplay()
    {
        cout << E.name << "\t\t" << E.age << "\t\t" << E.salary << "\t\t" << E.tax << "\t\t" << net_s << endl;
    };
};

void swap(employee &first, employee &seconed); // call by refrence

void selection_sort(employee arr[], int n);

int main()
{
    employee arr[limit];
    int n;
    cout << "Enter number of employees :";
    cin >> n;
    for (int i = 0; i < n; i++)
        arr[i].read(); 

    selection_sort(arr, n); // here i used "arr" only to insert array pointer
    
    cout << "Difrence between maximum and minimum net salary values is " 
        << arr[n-1].net_s - arr[0].net_s << endl; 
    
    cout << "name\t" << "\tage\t" << "\tsalary\t" << "\ttax\t"<< "\tnet salary\t" << endl;
    for (int i = 0; i < n; i++)
        arr[i].diplay();

    // system("pause");
    return 0;
}


void swap(employee &first, employee &seconed)
{
    employee temp;
    temp = first;
    first = seconed;
    seconed = temp;
}

void selection_sort(employee arr[], int n)
{
    // 1.start from from first element
    // 2.repeat until rise end
        // 3.suppose element is the smallest one  
            // 4.compare it with other and swap minimum value by it place
            // 5.move to next element
            // 6.goto step 2
    int min_index;
    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[min_index].net_s > arr[j].net_s)
                min_index = j;
        swap(arr[i], arr[min_index]);
    }
}
