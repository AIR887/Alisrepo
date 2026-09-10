#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string animalType;
    int startingAmount;
    int currentYear;
    int projectionYear;
    int numberOfYears;
    int projectedPopulation;

    cout << "Enter the type of animal: ";
    getline(cin, animalType);

    cout << "Enter the starting amount of animals: ";
    cin >> startingAmount;

    cout << "Enter the current year: ";
    cin >> currentYear;

    cout << "Enter the projection year: ";
    cin >> projectionYear;

    numberOfYears = projectionYear - currentYear;

    projectedPopulation = startingAmount * pow(2, numberOfYears);

    cout << "Type of animal: " << animalType << endl;
    cout << "Starting amount: " << startingAmount << endl;
    cout << "Current year: " << currentYear << endl;
    cout << "Projection year: " << projectionYear << endl;
    cout << "Projected population: " << projectedPopulation << endl;
}