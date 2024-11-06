/*
1.class Student that has data members: name (string), age (float), ID (int), count (static variable). 
It contains:
    1.1.function to read data members (find a way to create a student ID number without 
        reading it — put the first ID = 3000.).
    1.2.function to display data members.
    1.3.function to display the count of objects. 
2.In main function define an array of student class, and apply all functions on it. 
3.Add to the previous class data members: seven marks (double), avg (average of marks), 
    3.1.two constructors one with default parameters, and the other copy constructor, 
    3.2.function to display data members (remove static variable). 
4.Rewrite the main function to define several objects, and display them.
*/
#include <iostream>
#include <string>

#define marks_no 7

using namespace std;

class student
{
    string name;
    float  age;
    int ID;
    double marks[marks_no], average = 0;
    static int GID, count;  // keep eyes in this decleration no scope reselution here 
// never forget public it will let a mass of bugs
public:
    // basic constructor
    student ()
    {
        ID = GID;
        GID++;
        count++;
    };

    // copy constructor
    student(student &real)
    {
        // new one will take all detiles from real object
        ID = real.ID;

        name = real.name;
        age = real.age;
        average = real.average;

        for (int i = 0; i < marks_no; i++)
            marks[i] = real.marks[i];
        
        // do a search about this
        //marks = real.marks;
    };

    void display()
    {
        cout << ID << '\t' << name << '\t' << age << endl;

        for (int i = 0; i < marks_no; i++)
            cout << "subject " << i + 1 << " degree: " << marks[i] << endl;
        cout << "Average degree: " << average << endl;
    };

    void read()
    {
        cout << "Enter student name: ";
        cin >> name;
        
        cout << "Enter student age: ";
        cin >> age;

        for (int i = 0; i < marks_no; i++)
        {
            cout << "Enter subject " << i + 1 << ": ";
            cin >> marks[i];
            average += marks[i];
        }
        average /= marks_no * 100;
    };

    void display_count()
    {
        cout << "Students number: " << count << endl;
    };
};

int student :: GID = 3000, student :: count = 0;

int main()
{
    student first, seconed;
    first.read();
    seconed.read();
    student copy1(first);
    
    first.display();
    copy1.display();

    first.display_count();

    return 0;
}
