#include "utils.h"

#include <string>;
#include <algorithm>;

std::string binToDec(std::string num) {
    // Convert binary string to decimal string
    // Source: https://stackoverflow.com/a/62083923

    // Here we will store the resulting output
    std::string result{};

    // The conversion will also work for other  number bases
    // For base > 10 you need to adapt the creation of the digit at the bottom
    constexpr unsigned int numberBase{ 10 };

    // So, we will perfrom an integer division by 10, until the number is 0
    do {

        // The remainder is the digit that we are interested in
        unsigned int remainder{};
        // Temporary result of integer division
        std::string dividedNumberAsString{};

        // Do the division
        for (const char bit : num) {

            // Calculate the remainder
            remainder = remainder * 2 + (bit - '0');

            // If we have a overflow (e.g. number is bigger than 10)
            if (remainder >= numberBase) {

                // Handle overflow
                remainder -= numberBase;
                // Add character 1 to the "devidedString"
                dividedNumberAsString += "1";
            }
            else {
                dividedNumberAsString += "0";
            }
        } 
        // Now "dividedNumberAsString" as string is the result of the devision by e.g. 10 in binary form
        num = dividedNumberAsString;
        // The remainder is the number that we are interested in
        result.insert(0, 1, '0' + remainder);

        // Continue the loop with the new binary string
    } while (std::count(num.begin(), num.end(), '1'));

    // Show result
    return result;
}