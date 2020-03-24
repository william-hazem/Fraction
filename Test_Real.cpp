#include "Real.cpp"
#include "header\\Real.hpp"

#include<cstdlib>
#include<iomanip>

using std::cout;
using std::endl;
using std::setprecision;
using std::cin;


int main()
{
    /* Testing the ctor with two parameters */
    Real a (2), b(2,3);

    /* Testing the ctor with float parameter */
    Real c = 0.5;

    /* Testing the overheader - ostream */
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << endl;

    /* Testing some operations */
    cout << "a + b = " << a + b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "c * 2 = " << c * 2 << endl;
    cout << "c - 1 = " << c - 1 << endl;
    cout << "a + 1 + b = " << a + 1 + b << endl;
    
    cout << endl;

    /* Testing the overheader - istream */
    Real d;
    cout << "Enter with a number, you can you this expression too 1/2 (numerator/denominator)." << endl;
    cin >> d;
    cout << "d = " << d << endl;

    system("pause");
    return 1;
}