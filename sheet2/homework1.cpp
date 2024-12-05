/*Write a program contains a structure Date that has data members:
        d(int), m(int) , y(int), 
        a function to read data members,  
        a function to display data members in date format . 
It contains the structure Student that has data members:
    name (string), BD (Date), G[7] (float) (seven student’s grades). 
It contains 
    a function to read data member, 
    a function to return the average of student’s grades, 
    a function to display data members. 
In main function, 
    define an array of n Student, 
    read this array, 
    and display only the students with min and max averages.
*/

#include <iostream>

#define limit 75

using namespace std;

struct date
{
    int d, m, y;

    void read()
    {
        cout << "Enter date values (format: d m y): ";
        cin >> d >> m >> y; 
    };

    void display()
    {
        cout << d << '-' << m << '-' << y; 
    };
};

struct student
{
private:
     string name;
     date   DB;
     float  G[7];

public:
     void read()
     {
        cout << "Enter student name: ";
        cin >> name;

        for (int i = 0; i < 7; i++)
        {
            cout << "Enter subject [" <<  i + 1 << "]: ";
            cin >> G[i];
        }

        DB.read();
     };

     float average()
     {
        float sum = 0;

        for (int i = 0; i < 7; i++)
            sum += G[i];
        
        return sum / 7;
     }

     void display()
     {
        cout << name << '\t';
        DB.display();
        cout << endl;
        
        cout << "subjects: \t";

        for (int i = 0; i < 7; i++)
            cout << G[i] << '\t';
        cout << endl;
     };
};

int  limits(float arr[], int n, int op); // function to get inedx of min or max accourding to op values {max = 1, min = 0}

int main()
{
    student arr[50];
    int n;
    float average[50];
    // display only the students with min and max averages.

    cout << "Enter students number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr[i].read();
        average[i] = arr[i].average();
    }

    for (int i = 0; i < limit; i++) // for style issues
        cout << '#';
    cout << endl;

    arr[limits(average, n, 1)].display(); // 1 for maximum
    arr[limits(average, n, 0)].display(); // 0 for minimum
    
    for (int i = 0; i < limit; i++) // for style issues
        cout << '#';
    cout << endl;

    //system("pause");
    return 0;
}

int limits(float arr[], int n, int op)
{
    int temp = 0; // could be minimum number index or max number index
    switch (op)
    {
    case 1:
        
        for (int i = 1; i < n; i++)
            if (arr[temp] < arr[i])
                temp = i;
        break;

    case 0:
        for (int i = 1; i < n; i++)
            if (arr[temp] > arr[i])
                temp = i;
        break;
    }
    return temp;

    //some notes for switch//
    // declare a variable between curly bracis of case statment does not allowed 
    //"error like this"
    /*homework1.cpp:116:10: error: jump to case label
      116 |     case 0:
          |          ^
    homework1.cpp:110:13: note:   crosses initialization of ‘int max_index’*/
}