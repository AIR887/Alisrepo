#include <iostream>

using namespace std;

int main(){
    string name;
    char handedness;
    short age;
    long phoneNumber;

    cout << "Enter your name: " << endl;
    getline(cin, name);

    cout << "Enter your dominant hand (L/R/A): " << endl;
    cin >> handedness;

    cout << "Enter your age : " << endl;
    cin >> age;

    cout << "Enter your phone number: " << endl;
    cin >> phoneNumber;

    cout << "Name: " << name << endl;
    cout << "Handedness: " << handedness << endl;
    cout << "Age: " << age << endl;
    cout << "Phone number: " << phoneNumber << endl;
}