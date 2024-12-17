#include <iostream>
using namespace std;

// Base Class: Rectangle
class Rectangle 
{
protected:
    float Dim[10][2];
    int n;
public:
    void read() 
    {
        cout << "Enter number of rectangles (number <= 10): ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter width of rectangle-" << i + 1 << ": ";
            cin >> Dim[i][0];

            cout << "Enter lenth of rectangle-" << i + 1 << ": ";
            cin >> Dim[i][1];
        }
    }
    void print() 
    {
        cout << "Number of rectangles is " << n << endl;
        cout << "Width\t\tlenth\n";
        for (int i =  0; i < n; i++)
        cout << Dim[i][0] << "\t\t" << Dim[i][1] << endl; 
    }

    double area(int i) const 
    {
        return Dim[i][0] * Dim[i][1];
    }
};


class RArea : public Rectangle 
{
protected:
    double RA[10];
public:
    void set() // override function
    {
        for (int i = 0; i < n; i++)
        RA[i] = area(i);
    }

    void print() const // override function
    {
        cout << "Areas: ";
        for (int i = 0; i < n; i++) 
            cout << RA[i] << " ";
        
        cout << endl;
    }
};


class Pvolum : public RArea 
{
private:
    float H[10], V[10];
public:
    void set() 
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter hight-" << i + 1 <<": ";
            cin >> H[i];
            V[i] = H[i] * RA[i];
        }
    }

    void print() // override function
    {

        cout << "Hieght\t\tVolume\n";
        for (int i =  0; i < n; i++)
        cout << H[i] << "\t\t" << V[i] << endl;
    }
};

int main() 
{
    Pvolum shape;
    shape.read();
    shape.RArea::set(); // call function in Class RAea
    shape.set();
    
    shape.Rectangle::print();
    shape.RArea::print();
    shape.Pvolum::print(); // or shape.print() both are the same

    // system("pause");
    return 0;
}

