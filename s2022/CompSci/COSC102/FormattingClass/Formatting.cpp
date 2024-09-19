#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Java Formatting taught us System.out.format
    // However, formatting with cout is different
    double x = 1020.2345;
    double y = 2040.1111;
    double z = 52.886077;

    cout << setfill('-') << fixed << setprecision(2);
    cout << setw(10) << "Supercalifragilistx" << endl;
    cout << setw(10) << y << endl;
    cout << setw(10) << z << endl;
    // You can see how the formatting can persist as you keep writing cout commands

    // NEED TO KNOW: -> setfill, left, right, setw(), setprecision(), fixed

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << setprecision(1);
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}