#include "bigint/utils.h"

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

    // All zeros
    if (firstNonZero == -1) return "0";

    return s.substr(firstNonZero, s.length() - firstNonZero);
}

std::vector<BigInt::BaseType> pruneTrailingZeros(std::vector<BigInt::BaseType> v) {
    int firstNonZero = -1;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] != 0) {
            firstNonZero = i;
            break;
        }
    }

    // No leading zeros
    if (firstNonZero == v.size() - 1) return v;

    // All zeros
    if (firstNonZero == -1) {
        firstNonZero = 1;
    };

    // Source: https://stackoverflow.com/a/421615
    std::vector<BigInt::BaseType> newVec(v.begin(), v.begin() + firstNonZero);

    return newVec;
}