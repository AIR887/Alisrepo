#include <iostream>

using namespace std;

int main(){
    int number;
    cout << "Enter a number: " << endl;
    cin >> number;

    if(number % 2 == 0 != number >= 0){
        cout << "Good Job!" << endl;
    }
    else{
        cout << "Fail" << endl;
    }
}