#pragma once

#ifndef UTILS_H
#define UTILS_H

#include "bigint/BigInt.h"
#include <string>

std::string decToBin(std::string s);
std::string binToDec(std::string s);

std::string pruneLeadingZeros(std::string s);
std::vector<BigInt::BaseType> pruneTrailingZeros(std::vector<BigInt::BaseType> v);
std::string padLeadingZeros(std::string s, int length);

#endif