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
    int x;
    int y;
    void show()
    {
        cout << '(' << x << ", " << y << ')';
    };
        
    void scan()
    {
        cout << "Enter x value :";
        cin >> x;

        cout << "Enter y value :";
        cin >> y;
    };
        
};

void swap(point &first, point &seconed)
{
    point temp = {first.x, first.y};
    first = seconed;
    seconed = temp;
}

float distance(point first,point seconed)
{
    float lenth ;
    lenth = sqrt (float(pow(first.x - seconed.x, 2) + pow(first.y - seconed.y, 2)));

    return lenth;
}

int main (void)
{
    point first, seconed;

    first.scan();
    seconed.scan();

    swap(first, seconed);
    cout << "points after swap ";
    first.show();
    seconed.show();
    cout << endl;

   
    cout << "destance between points equal " << distance(first, seconed) << endl; 
}
