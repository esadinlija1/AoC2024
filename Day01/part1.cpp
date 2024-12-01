#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    std::ifstream inputFile("C:/Users/Korisnik/CLionProjects/AoC2024/Day01/input.txt"); // Open the file
    if (!inputFile) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::vector<int> list1;
    std::vector<int> list2;
    std::string line;

    // Read the file line by line
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int left, right;

        // Extract two integers from the line
        if (iss >> left >> right) {
            list1.push_back(left);
            list2.push_back(right);
        } else {
            std::cerr << "Error: Malformed line in file: " << line << std::endl;
        }
    }

    inputFile.close(); // Close the file

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    std::cout<<list1.size()<<std::endl;
    std::cout<<list2.size()<<std::endl;


    int distance=0;

    for(int i=0;i<list1.size();i++){
        distance+=std::abs(list1[i] - list2[i]);
    }

    std::cout<<distance;


    return 0;
}


//
