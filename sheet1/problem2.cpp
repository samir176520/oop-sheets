/*Write a program contains : 
1.function to read two numbers (coordinates of point)
2.function to display two numbers as a point’s format
3.function with four default parameters x1 , y1 and x2 , y2 to return the distance between them ( the first point’s coordinates x1 , y1 , and the second point’s coordinates x2 , y2 ) 
4.function to swap four parameters(swap x1, x2 and y1 , y2). 
In main function, define four numbers (two point’s coordinates), and apply all functions on them.
*/
#include <iostream>
#include <cmath>

using namespace std;

struct point 
{
    // data member are public by defult
    int x, y;

    // function members end with ';'
    void print()
    {
        cout << '(' << x << ", " << y << ')';
    };
        
    void scan()
    {
        cout << "Enter point (in form: x y): ";
        cin >> x >> y;
    };
        
};

////////////////////////////////////////////////////////////////////////////////////
// in this functions it ask for a 4 defult parameters but i do it with my own style
////////////////////////////////////////////////////////////////////////////////////

// here i used call by refrence beacue i will swap values
void swap(point &first, point &seconed);

float distance(point first,point seconed);


int main (void)
{
    point first, seconed;

    first.scan();
    seconed.scan();

    swap(first, seconed);
    cout << "points after swap ";
    first.print();
    cout << ' '; // just for style
    seconed.print();
    cout << endl;
   
    cout << "destance between points equal " << distance(first, seconed) << endl; 

    // system("pause");
    return 0;
}

void swap(point &first, point &seconed)
{
    point temp = {first.x, first.y};
    first = seconed;
    seconed = temp;
}

// function must have '{''}' how ever it's body one line or not
float distance(point first,point seconed)
{
    return sqrt (float(pow(first.x - seconed.x, 2) + pow(first.y - seconed.y, 2)));
}