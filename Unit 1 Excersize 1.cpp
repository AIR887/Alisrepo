#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string fullName;
    char section;
    int seatNumber;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Enter your section (A, B, C, or D): ";
    cin >> section;

    cout << "Enter a seat number (1-200): ";
    cin >> seatNumber;

    cout << "|------------------------------------|" << endl;
    cout << "|Name: " << fullName << endl;
    cout << "|Section: " << section << endl;
    cout << "|Seat: " << seatNumber << endl;
    cout << "|Price: $83" << endl;
    cout << "|------------------------------------|" << endl;
}