#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> names = {"Ali", "Bob", "Cam", "David", "Emerson", "Francis", "Gabe"};
    string maximum; 
    string minimum; 

    cout << "Names in reverse order: ";
    for(int i = 0; i < names.size(); i++){
        cout << names[names.size() - i - 1] << " ";
    }

    for (int i = 0; i < names.size(); i++) {
        if (names[i] > maximum) {
            maximum = names[i];
        }
        if (names[i] < minimum) {
            minimum = names[i];
        }
    }

    cout << "\nMaximum element: " << maximum << endl;
    cout << "Minimum element: " << minimum << endl;
}