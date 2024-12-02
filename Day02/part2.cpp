#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

bool isStrictlyIncreasing(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] >= vec[i + 1]) {
            return false;
        }
    }
    return true;
}

bool isStrictlyDecreasing(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] <= vec[i + 1]) {
            return false;
        }
    }
    return true;
}

bool hasValidDifferences(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        int diff = std::abs(vec[i] - vec[i + 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

bool isSafeReport(const std::vector<int>& vec) {
    return hasValidDifferences(vec) && (isStrictlyIncreasing(vec) || isStrictlyDecreasing(vec));
}

bool canBeMadeSafeByRemovingOne(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::vector<int> modifiedVec = vec;
        modifiedVec.erase(modifiedVec.begin() + i); // Remove the i-th element

        // Check if removing this element makes the report safe
        if (isSafeReport(modifiedVec)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> records;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<int> currentList;
        int number;

        while (iss >> number) {
            currentList.push_back(number);
        }

        if (!currentList.empty()) {
            records.push_back(currentList);
        } else {
            std::cerr << "Warning: Skipping malformed or empty line: " << line << std::endl;
        }
    }

    inputFile.close();

    int safeReportsCount = 0;

    for (const auto& record : records) {
        // First check if the report is already safe
        if (isSafeReport(record)) {
            safeReportsCount++;
        }
        // If not safe, check if it can be made safe by removing one level
        else if (canBeMadeSafeByRemovingOne(record)) {
            safeReportsCount++;
        }
    }

    std::cout << "Safe Reports Count: " << safeReportsCount << std::endl;
    return 0;
}

