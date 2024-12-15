#include <iostream>
using namespace std;

int factorial (int number);

class Data 
{
private:
    double D[20], Fact[20];
    int n;

public:
    // Function to read data
    void read() 
    {
        cout << "Enter the number of elements (n <= 20): ";
        cin >> n;
        cout << "Enter " << n << " elements of D: ";
        for (int i = 0; i < n; i++)
            cin >> D[i];
        
        fact_sum();
    }

    // Function to calculate Factorial of each sum
    void fact_sum() 
    {
        for (int i = 0; i < n; i++) 
        {
            Fact[i] = 0;
            for (int j = 0; j <= i; j++)
                Fact[i] += D[i];
            Fact[i] = (Fact[i] < 0)? -Fact[i]: Fact[i];
            Fact[i] = factorial(Fact[i]);
        }
    }

    // Function to display data in table form
    void display() 
    {
        cout << "\tD\t\t" << "\t\tFact\t" << endl;
        for (int i = 0; i < n; i++)
            cout << D[i] << "\t\t\t\t" << Fact[i] << endl;
            
    }

    // Overload + operator to add elements of D
    Data operator+(const Data &obj) 
    {
        Data temp;
    
        temp.n = (n < obj.n)? n : obj.n; // Set n to minimum
        for (int i = 0; i < temp.n; i++) 
            temp.D[i] = D[i] + obj.D[i];
        if (temp.n == n)
        {
            for (int i = n; i < obj.n; i++)
                temp.Fact[i] = obj.Fact[i];
            temp.n = obj.n;
        }
        else
        {
            for (int i = obj.n; i < n; i++)
                temp.Fact[i] = Fact[i];
            temp.n = n;
        }
    
        temp.fact_sum();  // Recalculate Fact
        return temp;
    }

    // Overload <= operator to compare only D
    bool operator<=(const Data &obj) 
    {
        for (int i = 0; i < n; i++) 
        {
            if (D[i] > obj.D[i])
                return false;
        }
        return true;
    }

    // Overload == operator to compare only Fact
    bool operator==(const Data &obj) {
        for (int i = 0; i < n; i++) {
            if (Fact[i] != obj.Fact[i])
                return false;
        }
        return true;
    }

    // Friend function to compare two objects
    friend void compareObjects(Data &a, Data &b);
};

// Compare two objects and display if they are equal
void compareObjects(Data &a, Data &b) {
    if (a == b)
        cout << "The two objects are equal (based on Fact values)." << endl;
    else
        cout << "The two objects are not equal." << endl;
}



int main() {
    Data obj1, obj2, obj3;

    cout << "Enter data for first object:" << endl;
    obj1.read();

    cout << "Enter data for second object:" << endl;
    obj2.read();

    cout << "\nFirst Object Data:" << endl;
    obj1.display();

    cout << "\nSecond Object Data:" << endl;
    obj2.display();

    // Adding objects
    obj3 = obj1 + obj2;
    cout << "Result after adding two objects (D values):" << endl;
    obj3.display();

    // Compare using <= operator
    if (obj1 <= obj2)
        cout << "Object 1 is less than or equal to Object 2 (based on D values).\n" << endl;
    else
        compareObjects(obj1, obj2); // Compare objects using friend function
    // system("pause");
    return 0;
}

int factorial (int number)
{
    if (number == 1 || number == 0)
        return 1;
    else
        return factorial(number - 1) * number;
}
