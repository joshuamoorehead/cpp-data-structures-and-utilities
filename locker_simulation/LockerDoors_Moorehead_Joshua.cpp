// Copyright Joshua Moorehead 2023
#include <iostream>

int main() {
    // Declaring Variables
    int lockerDoors, passes, indexer, numOfOpen = 0;

    // Getting user input
    std::cout << "Enter the number of locker doors: ";
    std::cin >> lockerDoors;

    std::cout << "Enter the amount of passes: ";
    std::cin >> passes;
    indexer = 1;
    // Algorithm for locker doors
    int*  lockers = new int[lockerDoors]();  // initializes all elements to 0

    for (int i = 0; i < passes; i++) {
        for (int j = indexer-1; j < lockerDoors; j+=indexer) {
            if (lockers[j] == 0) {
                lockers[j] = 1;
            } else if (lockers[j] == 1) {
                lockers[j] = 0;
            }
        }
        indexer++;
    }

    // Display the results
    std::cout << "Results:" << std::endl;
    for (int i = 0; i < lockerDoors; ++i) {
        if (lockers[i] == 1) {
        std::cout << "Locker " << (i + 1) << ": OPEN" << std::endl;
        numOfOpen++;
        }
        if (lockers[i] == 0) {
        std::cout << "Locker " << (i + 1) << ": CLOSED" << std::endl;
        }
    }
    std::cout << "Number of open lockers: " << numOfOpen << std::endl;

    // freeing dynamically allocated array
    delete[] lockers;


    return 0;
}
