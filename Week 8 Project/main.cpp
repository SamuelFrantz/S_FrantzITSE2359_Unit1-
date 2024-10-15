#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Fraction.h"
#include "findMax.h"

void readFractionsFromFile(const std::string& filename, std::vector<Fraction>& fractions) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    int numerator, denominator;
    while (inputFile >> numerator >> denominator) {
        Fraction frac(numerator, denominator);
        fractions.push_back(frac);
    }
}

void writeResultsToFile(const std::string& filename, const std::vector<std::string>& results) {
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    for (const auto& result : results) {
        outputFile << result << std::endl;
    }
}

int main() {
    std::vector<Fraction> fractions;
    readFractionsFromFile("fractions.txt", fractions);

    std::vector<std::string> results;

    for (size_t i = 0; i < fractions.size(); i += 2) {
        Fraction sum = fractions[i] + fractions[i + 1];

        // Using std::ostringstream for string building
        std::ostringstream oss;
        oss << fractions[i] << " + " << fractions[i + 1] << " = " << sum;
        results.push_back(oss.str());

        if (fractions[i] == fractions[i + 1]) {
            oss.str(""); // clear the stream
            oss << fractions[i] << " is equal to " << fractions[i + 1];
            results.push_back(oss.str());
        } else {
            oss.str(""); // clear the stream
            oss << fractions[i] << " is not equal to " << fractions[i + 1];
            results.push_back(oss.str());
        }
    }

    writeResultsToFile("results.txt", results);

    // Testing the findMax function
    Fraction a(1, 2), b(3, 4);
    Fraction maxFraction = findMax(a, b);
    std::cout << "Max Fraction: " << maxFraction << std::endl;

    return 0;
}
