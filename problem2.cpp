/*Write a program contains : 
1.function to read two numbers (coordinates of point)
2.function to display two numbers as a point’s format
3.function with four default parameters x1 , y1 and x2 , y2 to return the distance between them ( the first point’s coordinates x1 , y1 , and the second point’s coordinates x2 , y2 ) 
4.function to swap four parameters(swap x1, x2 and y1 , y2). 
In main function, define four numbers (two point’s coordinates), and apply all functions on them.
*/
#include <iostream>

using namespace std;

struct point 
{
    int x;
    int y;
    void show()
    {
        cout << '(' << x << ", " << y << ')' << endl;
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

point distance(point first,point seconed)
{
    point lenth ;
    lenth.x = unsigned(first.x - seconed.x);
    lenth.y = unsigned(first.y - seconed.y);

    return lenth;
}

int main (void)
{
    point first, seconed;

    first.scan();
    seconed.scan();

    swap(first, seconed);

    first.show();
    seconed.show();

    point lenth = distance(first, seconed);
    cout << "destance between points : \n";
    cout << lenth.x << " for x axis and " <<lenth.y << " for y axis.\n";  
}