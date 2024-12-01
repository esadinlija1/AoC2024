#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

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

    std::unordered_map<int, int> freqMap;
    for (int num : list2) {
        freqMap[num]++;
    }

    int similarity_score=0;

    for(int num : list1){
        similarity_score+=num*freqMap[num];
    }

    std::cout<<similarity_score;


    return 0;
}

