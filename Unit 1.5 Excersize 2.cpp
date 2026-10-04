#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int size1;
    int size2;

    cout << "How many numbers are in the first vector? ";
    cin >> size1;

    vector<int> vector1(size1);

    cout << "Enter the numbers for the first vector:\n";

    for (int i = 0; i < size1; i++)
    {
        cin >> vector1[i];
    }

    cout << "How many numbers are in the second vector? ";
    cin >> size2;

    vector<int> vector2(size2);

    cout << "Enter the numbers for the second vector:\n";

    for (int i = 0; i < size2; i++)
    {
        cin >> vector2[i];
    }

    vector<int> mergedVector = vector1;

    mergedVector.insert(mergedVector.end(), vector2.begin(), vector2.end());

    sort(mergedVector.begin(), mergedVector.end());

    cout << "Sorted merged vector: ";

    for (int i = 0; i < mergedVector.size(); i++)
    {
        cout << mergedVector[i] << " ";
    }
} 