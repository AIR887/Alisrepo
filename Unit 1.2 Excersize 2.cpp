#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    double number1 = __DBL_MAX__;

    number = number1;

    cout << number << endl;
    cout << number1 << endl;
    //problematic because __DBL_MAX__ holds more value than int
}


