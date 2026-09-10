#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    string fullName;
    char section;
    int seatNumber;

    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Enter your section (A, B, C, or D): ";
    cin >> section;

    cout << "Enter a seat number (1-200): ";
    cin >> seatNumber;

    printf("|-------------------------------|\n");
    printf("|Name: %-25s|\n", fullName.c_str());
    printf("|Section: %-22c|\n", section);
    printf("|Seat: %-25.3d|\n", seatNumber);
    printf("|Price: $%-23d|\n", 83);
    printf("|-------------------------------|\n");
}