#include "utils.h"

#include <string>
#include <iostream>

// Source: https://stackoverflow.com/a/11007021

std::string pruneLeadingZeros(std::string s) {
    // Remove leading zeros from a string
    int firstNonZero = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') {
            firstNonZero = i;
            break;
        }
    }

    if (firstNonZero == -1) return "0";

    return s.substr(firstNonZero, s.length() - firstNonZero);
}

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