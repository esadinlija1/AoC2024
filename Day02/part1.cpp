#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
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




int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    std::ifstream inputFile("./input.txt"); // Open the file
    if (!inputFile) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> records; // To store the list of lists
    std::string line;

    // Read the file line by line
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<int> currentList;
        int number;

        // Extract all integers from the line
        while (iss >> number) {
            currentList.push_back(number);
        }

        // Check if the current list is not empty and add it to listOfLists
        if (!currentList.empty()) {
           records.push_back(currentList);
        } else {
            std::cerr << "Error: Malformed or empty line in file: " << line << std::endl;
        }
    }


    inputFile.close();

    for(int i=0;i<records.size();i++){
        for(int j=0;j<records[i].size();j++){

            std::cout<<records[i][j]<<" ";
        }

        std::cout<<std::endl;

    }



    int safeReportsCount=0;

    for(const auto& record : records){
        bool correctDifference=true;
        for(int i=0;i<record.size()-1;i++){
            int diff=std::abs(record[i] - record[i+1]);
            if(diff<1 || diff>3){
                correctDifference=false;
                break;
         }
        }

        bool isIncreasing=isStrictlyIncreasing(record);
        bool isDecreasing=isStrictlyDecreasing(record);

        if(correctDifference==true && (isIncreasing==true || isDecreasing==true)){
            safeReportsCount+=1;
        }

    }

    std::cout<<safeReportsCount;


    return 0;


}