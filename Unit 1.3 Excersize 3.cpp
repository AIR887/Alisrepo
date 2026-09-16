#include <iostream>

using namespace std;

int main()
{
    long double userNumber;
    string numberAsString;

    cout << "Enter a number: ";
    cin >> userNumber;

    numberAsString = to_string(userNumber);

    cout << "Number as a string: " << numberAsString << endl;
    cout << "String length: " << numberAsString.length() << endl;
}
    