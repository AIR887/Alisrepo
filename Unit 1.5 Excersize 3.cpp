#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numList = {1, 2, 1, 3, 2}; 
    int duplicateCount = 0;

    
    stable_sort(numList.begin(), numList.end()); //sort the numbers so that same numbers are next to each other


    for (int i = 0; i < numList.size();) { 
        
        int count = 1; 
        
        while (count + i < numList.size() && numList[i] == numList[count + i]) {
            count++; // finds match, increase the group size
        }
        
        //group size is greater than 1,  duplicates exist
        if (count > 1) {
            duplicateCount += count; 
        }
        
        i += count;
    }

    cout << duplicateCount; 
}
