#pragma once

#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <vector>

class BigInt
{
public:
    typedef unsigned long long int BaseType;

private:
	std::vector<BaseType> digits;
	BaseType radix;

public:
	BigInt(BaseType radix);
	BigInt(std::vector<BaseType>, BaseType radix);
	BigInt(std::string s, BaseType radix);
    // TODO: add destructor

	std::vector<BaseType> getDigits();

	static std::vector<BaseType> fromString(std::string s);
	void display();

	BigInt operator+(BigInt & other);
};

#endif