#include "bigint/utils.h"

#include <string>

std::string padLeadingZeros(std::string s, int length) {
	/*
		Pad 0's to beginning to statisfy length
		Params:
			s (string): The string to be padded
			length (int): desired length after padding
		Returns: New string padded with 0's
	*/
	if (s.size() == length) return s;

	std::string res = s;

	unsigned int number_of_zeros = length - res.length();
	res.insert(0, number_of_zeros, '0');

	return res;
}