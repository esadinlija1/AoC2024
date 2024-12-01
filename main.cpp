#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    std::ifstream inputFile("C:/Users/Korisnik/CLionProjects/AoC2024/input.txt"); // Open the file
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

    std::cout << "List 1: ";
    for (const int& num : list1) {
        std::cout << num << " ";
    }
    std::cout << "\nList 2: ";
    for (const int& num : list2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.