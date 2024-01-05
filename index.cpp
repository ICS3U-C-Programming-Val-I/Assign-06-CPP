// Copyright (c) 2024 Val I All rights reserved.
//
// Created by: Val I
// Created on: Jan 2, 2024
// This programme asks the user to enter 10 numbers,
// It then asks them for a number that was input
// And it finds what index the number is at.

#include <array>
#include <iostream>
#include <string>
// Initializing  variables and constants
std::string numAddedStr, numToFindStr;
const int MAX_ARRAY_SIZE = 10;

template <size_t N>
int FindIndex(std::array<double, N> arrayOfFloats, double findNum) {
    // Finds and returns the index
    int index = -1;
    for (int counter = 0; counter < MAX_ARRAY_SIZE; ++counter) {
        if (arrayOfFloats[counter] == findNum) {
            index = counter;
            break;
        }
    }
    return index;
}

int main() {
    // Initial greeting/message
    std::cout << "Hello and Welcome!\n";
    std::cout << "Enter numbers and I’ll tell you what index you placed a specific number\n";
    // Initializing array
    std::array<double, MAX_ARRAY_SIZE> arrayOfNumbers;
    // Getting numbers from user
    for (int counter = 0; counter < MAX_ARRAY_SIZE; counter += 1) {
        std::cout << " Enter a number ";
        std::cin >> numAddedStr;
        // Catching errors.
        try {
            double numAdded = std::stod(numAddedStr);
            arrayOfNumbers[counter] = numAdded;
            std::cout << numAdded << " was added \n";
        } catch (std::invalid_argument) {
            std::cout << numAddedStr << " is not a number.\n";
            return 0;
        }
    }
    std::cout << "Enter the number you want to find ";
    std::cin >> numToFindStr;
    try {
        double numToFind = std::stod(numToFindStr);
        int indexFound = FindIndex(arrayOfNumbers, numToFind);
        // Displaying result
        if (indexFound == -1) {
            std::cout << numToFind << " was not input." << "\n";
        } else {
            std::cout << "Index of " << numToFind << ": " << indexFound << "\n";
        }
    } catch (std::invalid_argument) {
        std::cout << numToFindStr << " is not a number. Please check the input.\n" ;
    }
}
