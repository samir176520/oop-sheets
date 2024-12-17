#include <iostream>
#include <string>
using namespace std;

struct Course {
    string C_name;
    float Degree;
    int Credit;
};

class Level 
{
protected:
    Course L[5];
public:
    void readData() 
    {
        cout << "Enter details for 5 courses:\n";
        for (int i = 0; i < 5; i++) 
        {
            cout << "Course " << i + 1 << " Name: ";
            cin >> L[i].C_name;
            cout << "Degree: ";
            cin >> L[i].Degree;
            cout << "Credit: ";
            cin >> L[i].Credit;
        }
    }

    void printTable() 
    {
        cout << "Name\tDegree\tCredit\n";
        for (int i = 0; i < 5; i++) 
            cout << L[i].C_name << "\t" << L[i].Degree << "\t" << L[i].Credit << endl;
        
    }
};

class Student : public Level
{
private:
    string name;
    int ID;
    float total_d, total_c;
    char GPA;

    char calculateGPA(float avg) 
    {

        if (avg >= 92) return 'A';
        else if (avg >= 84) return 'B+';
        else if (avg >= 80) return 'B';
        else if (avg >= 75) return 'C+';
        else if (avg >= 65) return 'C';
        else if (avg >= 60) return 'D';
        else return 'F';
    }

public:
    void readStudentData() 
    {
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> ID;

        total_d = 0;
        total_c = 0;

        for (int i = 0; i < 5; i++) 
        {
            total_d += L[i].Degree;
            total_c += L[i].Credit;
        }

        GPA = calculateGPA(total_d / 5);
    }

    void printStudentData() 
    {
        cout << "Name: " << name << "\tID: " << ID << "\tGPA: " << GPA << endl;
    }
};

int main() 
{
    Student students[3];
    for (int i = 0; i < 3; i++) 
    {
        cout << "Enter data for student " << i + 1 << ":\n";
        students[i].readStudentData();
        students[i].readData(); // the beauty of public inhertince ;)
        
    }

    cout << "\nStudent Data:\n";
    for (int i = 0; i < 3; i++) 
        students[i].printStudentData();
    
    //system("pause");
    return 0;
}
