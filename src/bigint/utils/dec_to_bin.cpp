#include "bigint/utils.h"

#include <string>

// Source: https://stackoverflow.com/a/11007021

std::string decDiv2(std::string num) {
    // Divide (string representation of) decimal number by two

    std::string res;
    int additive = 0;

    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';

        res.append(std::to_string(digit/2 + additive));

        additive = digit % 2 == 0 ? 0 : 5;
    }

    return pruneLeadingZeros(res);
}

std::string decToBin(std::string num) {
    // Convert decimal string to binary string
    std::string res = "";
    while (num != "0") {
        int digit = num[num.size() - 1] - '0';

        res.insert(0, digit % 2 == 0 ? "0" : "1");
        num = decDiv2(num);
    }

    return res;
}