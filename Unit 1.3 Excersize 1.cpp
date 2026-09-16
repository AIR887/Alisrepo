#include <iostream>

using namespace std;

int main(){
    string word;
    cout << "Enter a word: " << endl;
    cin >> word;

    if(word.length() == 5){
        cout << "Your word is 5 letters!" << endl;
    }

    else{
        cout << "You did not enter a 5 letter word" << endl;
    }
}

