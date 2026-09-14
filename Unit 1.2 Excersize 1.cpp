#include <iostream>

using namespace std;

int main()
{
    int intMin = INT_MIN;
    int intMax = INT_MAX;

    unsigned int unsignedIntMin = 0;
    unsigned int unsignedIntMax = 0;
    unsignedIntMax -= 1;

    short shortMin = SHRT_MIN;
    short shortMax = SHRT_MAX;

    unsigned short unsignedShortMin = 0;
    unsigned short unsignedShortMax = 0;
    unsignedShortMax -= 1;

    long longMin = LONG_MIN;
    long longMax = LONG_MAX;

    unsigned long unsignedLongMin = 0;
    unsigned long unsignedLongMax = 0;
    unsignedLongMax -= 1;
    
    cout << "Int minimum: " << intMin << endl;
    cout << "Int maximum: " << intMax << endl;

    cout << "Unsigned int minimum: " << unsignedIntMin << endl;
    cout << "Unsigned int maximum: " << unsignedIntMax << endl;

    cout << "Short minimum: " << shortMin << endl;
    cout << "Short maximum: " << shortMax << endl;

    cout << "Unsigned short minimum: " << unsignedShortMin << endl;
    cout << "Unsigned short maximum: " << unsignedShortMax << endl;

    cout << "Long minimum: " << longMin << endl;
    cout << "Long maximum: " << longMax << endl;

    cout << "Unsigned long minimum: " << unsignedLongMin << endl;
    cout << "Unsigned long maximum: " << unsignedLongMax << endl;


}