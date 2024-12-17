#include <iostream>
#include <string>

using namespace std;

class Program 
{
public:
    string programName, Div[2];
public:
    void read() 
    {
        cout << "Enter name of program : ";
        cin >> programName;

        for (int i = 0; i < 2; i++)
        {
            cout << "Enter Div-" << i + 1 <<" (department name): ";
            cin >> Div[i];
        }             
    }
};


class Div1 : virtual public Program // to inhertince the same copy of program Class "prevent ambigous"
{
protected:
string ND1;  //Division name (string).
string CON1[3];//Array to store course names (string).
float COD1[3]; // Array for course scores (float).
int TCOD1[3];// Total course scores (int).
char GPAC1[3];// GPA results based on a table (char).
float avg; // average of total degrees

public:
    void read() 
    {
        ND1 = Div[0];
        cout << "Enter the following detials for Division-"<<ND1<<"!\n";
        for (int i = 0; i < 3; i++) 
        {
            
            cout << "Enter course-"<<i +  1<<" detials!\n";
            cout << "Name: ";
            cin >> CON1[i];

            cout <<"Score: ";
            cin >> COD1[i];

            cout <<"Total score: ";
            cin >> TCOD1[i];

            avg = Total() / 3 ;

            // Table to assign value of GPAC1
            if (COD1[i] / TCOD1[i] >= 90)
                GPAC1[i] = 'A';
            else if (COD1[i] / TCOD1[i] >= 84)
                GPAC1[i] = 'B+';
            else if (COD1[i] / TCOD1[i] >= 80)
                GPAC1[i] = 'B';
            else if (COD1[i] / TCOD1[i] >= 75)
                GPAC1[i] = 'C+';
            else if (COD1[i] / TCOD1[i] >= 65)
                GPAC1[i] = 'C';
            else if (COD1[i] / TCOD1[i] >= 60)
                GPAC1[i] = 'D';
            else
                GPAC1[i] = 'F';
            
        }
    }

    float Total()
    {
        float total = 0;
        for (int i = 0; i < 3; i++)
        {
            if (GPAC1[i] != 'F')
                total += COD1[i];
        }
        return total;
    }
};


class Div2 : virtual public Program  // to inhertince the same copy of program Class "prevent ambigous"
{
protected:
    string ND2;  //Division name (string).
    string CON2[3];//Array to store course names (string).
    float COD2[3]; // Array for course scores (float).
    int TCOD2[3];// Total course scores (int).
    char GPAC2[3];// GPA results based on a table (char).
    float avg; // average of total degrees
public:
      void read() 
    {
        
        ND2 = Div[1]; 
        cout << "Enter the following detials for Division-"<<ND2<<"!\n";
        
        for (int i = 0; i < 3; i++) 
        {
            cout << "Enter course-"<<i +  1<<" detials!\n";
            cout << "Name: ";
            cin >> CON2[i];

            cout <<"Score: ";
            cin >> COD2[i];

            cout <<"Total score: ";
            cin >> TCOD2[i];

            avg = Total() / 3 ;

            // Table to assign value of GPAC1
            if (COD2[i] / TCOD2[i] >= 90)
                GPAC2[i] = 'A';
            else if (COD2[i] / TCOD2[i] >= 84)
                GPAC2[i] = 'B+';
            else if (COD2[i] / TCOD2[i] >= 80)
                GPAC2[i] = 'B';
            else if (COD2[i] / TCOD2[i] >= 75)
                GPAC2[i] = 'C+';
            else if (COD2[i] / TCOD2[i] >= 65)
                GPAC2[i] = 'C';
            else if (COD2[i] / TCOD2[i] >= 60)
                GPAC2[i] = 'D';
            else
                GPAC2[i] = 'F';
            
        }
    }

    float Total()
    {
        float total = 0;
        for (int i = 0; i < 3; i++)
        {
            if (GPAC2[i] != 'F')
                total += COD2[i];
        }
        return total;
    }
};


class Student : public Div1, public Div2 // Derived Class: Student
{
protected:
    string name;
    int ID;
    float age;
    char GPA;
    float avg;

public:
    void read()
    {
        cout << "Enter the following detials for student!\n";
        cout << "Name: ";
        cin >> name;

        cout << "ID: ";
        cin >> ID;

        cout << "Age: ";
        cin >> age;

        avg = (Div1::avg + Div2::avg) / 2;

            // Table to assign value of GPAC1
            if (avg >= 90)
                GPA = 'A';
            else if (avg >= 84)
                GPA = 'B+';
            else if (avg >= 80)
                GPA = 'B';
            else if (avg >= 75)
                GPA = 'C+';
            else if (avg >= 65)
                GPA = 'C';
            else if (avg >= 60)
                GPA = 'D';
            else
                GPA = 'F'; 
    }

    double Total()
    {
        return Div1::Total() + Div2::Total();
    }

    void display()
    {
        cout << "Student detials.... \n";
        cout << "ID: " << ID << "\tname: " << name << "\tage: " << age  << endl;

        cout << "Program: " << programName /*important of virtual inhertiance*/ << "\tAverage: " << avg << "\t GPA: " << GPA << endl;
        cout << ND1 << "\t\t" <<  ND2;
        cout << "Total Degrees (Div1): " << Div1::Total() << endl;
        cout << "Total Degrees (Div2): " << Div2::Total() << endl;
        cout << "Total Degrees (Overall): " << Div1::Total() + Div2::Total() << endl;
    }
};

int main() 
{
    Student obj;
    obj.Program::read();
    obj.Div1::read();
    obj.Div2::read();
    obj.read();
    obj.display();

    // system("pause"); 
    return 0;
}
