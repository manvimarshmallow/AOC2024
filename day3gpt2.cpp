#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    // Replace with your file path or input source
    std::ifstream file("large_input.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    // Regex patterns for mul, do(), and don't()
    std::regex combined_pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");

    // State to track whether mul instructions are enabled
    bool mul_enabled = true;
    long long sum_of_products = 0; // Use long long for large sums

    std::string line;
    while (std::getline(file, line)) { // Process input line by line
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), combined_pattern);
        auto words_end = std::sregex_iterator();

        for (auto it = words_begin; it != words_end; ++it) {
            std::string match = it->str();

            if (match == "do()") {
                // Enable mul instructions
                mul_enabled = true;
            } else if (match == "don't()") {
                // Disable mul instructions
                mul_enabled = false;
            } else {
                // Match mul(integer1, integer2)
                if (mul_enabled) {
                    std::smatch mul_match;
                    if (std::regex_match(match, mul_match, std::regex(R"(mul\((\d+),(\d+)\))"))) {
                        int integer1 = std::stoi(mul_match[1].str());
                        int integer2 = std::stoi(mul_match[2].str());
                        sum_of_products += static_cast<long long>(integer1) * integer2;
                    }
                }
            }
        }
    }

    file.close();

    // Output the result
    std::cout << "Sum of products: " << sum_of_products << std::endl;
    return 0;
}
