#include <iostream>
#include <string>
#include <regex>
#include <fstream>

int main() {
    // Replace this with your large input source or file
    std::ifstream file("./large_input.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::string line;
    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    long long sum_of_products = 0; // Use long long for large sums

    while (std::getline(file, line)) { // Process line by line
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto words_end = std::sregex_iterator();

        for (auto it = words_begin; it != words_end; ++it) {
            int integer1 = std::stoi((*it)[1].str());
            int integer2 = std::stoi((*it)[2].str());
            sum_of_products += static_cast<long long>(integer1) * integer2; // Avoid overflow
        }
    }

    file.close();
    std::cout << "Sum of products: " << sum_of_products << std::endl;
    return 0;
}
