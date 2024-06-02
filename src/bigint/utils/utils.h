#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <string>

std::string decToBin(std::string s);
std::string binToDec(std::string s);
std::string pruneLeadingZeros(std::string s);
std::string padLeadingZeros(std::string s, int length);

#endif