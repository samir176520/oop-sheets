/*
Write a program contains 
1.structure Point that has data members: x, y, z as float. 
2.class Point_3D that has data members: 
    2.1.P[30](Point), N[30] (float), and m(number of elements for P,N). 
This class includes :
    2.2.function to return the norm for a given Point’s object,
    2.3.function to read data members and set the elements of N.
        such that each Ni is the norm of point Pi for i=0, .. , m-1.
    2.4.function to return the distance between the first and last points in P.
    2.5.function to return the max norm in N.
    2.6.function to compare between max norm for two objects and return the max object. 
    2.7.function to return the minimum distance for first and last points for two objects.
    2.8.function to display the data members in tabular form.
3.In main function, define two object of class Point_3D, and apply all functions on them.
*/
#include <cmath>
#include <iostream>

// define some magic numbers
#define no 30
#define limit 100

using namespace std;

struct point
{
    float x,y,z;
};

class point_3D
{
    point P[no];
    float N[no];
    int m;

public :
    float norm(point dot)
    {
        return sqrt(pow(dot.x, 2) + pow(dot.y, 2) + pow(dot.z, 2));
    }

    // i make function of read to be a constructor
    point_3D()
    {
            cout << "Enter how much points: ";
            cin >> m;

        for (int i = 0; i < m; i++)
        {
            cout << "Please enter the coordinates for " << i + 1 <<"st point (format: x y z): ";
            cin >> P[i].x >> P[i].y >> P[i].z;
            N[i] = norm(P[i]);
        }
    }
    
    float distance_first_last()
    {
        return sqrt(pow(P[0].x - P[m].x, 2) + pow(P[0].y - P[m].y, 2) + pow(P[0].z - P[m].z, 2));
    }

    float max_norm()
    {
        float max = N[0];
        for (int i = 1; i < m; i++)
        {
            if (max < N[i])
                max = N[i];
        }
        return max;
    }

    float compare(point_3D seconed)
    {
        if (seconed.max_norm() > max_norm())
            return seconed.max_norm();
        else
            return max_norm();
    }

    float compare_min(point_3D seconed)
    {
        if (seconed.distance_first_last() < distance_first_last())
            return seconed.distance_first_last();
        else
            return distance_first_last();
    }

    void display()
    {
        cout << "Number of points is " << m << endl;

        cout << "\tpoint\t" << "\tnorm_lenth\t" << endl;
        for (int i = 0; i < m; i++)
        {
            cout << i + 1 <<"- (" << P[i].x << ", " << P[i].y << ", " << P[i].z << ')';
            cout << "\t\t";
            cout << N[i] << endl;
        }
    }
};


// feel free to do your own main function this is my style if you look for ideas <3
int main()
{
    /* Becarefull of you open "()" and  didn't but any value 
    between them programe will output alot of errors, 
    open "()" when u only will enter a value
    */
   point_3D first, seconed;

    cout << endl;

    // just for fun ;)
    for (int i = 0; i < limit; i++)
        cout << '=';
    cout << endl;

    cout << "Distance between first and last points in first data-set is " << first.distance_first_last() << endl;
    cout << "Distance between first and last points in seconed data-set is " << seconed.distance_first_last() << endl;
    cout << "Minimum distance between first and seconed data-set is " << first.compare_min(seconed) << endl; 

    if (first.compare(seconed) == first.max_norm() && first.compare(seconed) == seconed.max_norm())
    {
        cout << "both data-sets has the same maximum norm value." << endl;
    }
    else if (first.compare(seconed) == first.max_norm())
    {    
        cout << "First data-set has the maximum norm-value." << endl;
        first.display();
    }
    else
    {
        cout << "Seconed data-set has the maximum norm-value." << endl;
        seconed.display();
    }

    // just for style ;)
    for (int i = 0; i < limit; i++)
        cout << '=';
    cout << endl;

    // system("pause");
    return 0;
}
