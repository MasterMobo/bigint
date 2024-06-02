#include "utils.h"

#include <string>

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