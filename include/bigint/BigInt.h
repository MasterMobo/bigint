#pragma once

#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <vector>
#include <climits>

class BigInt
{

	public:
		typedef unsigned long long int BaseType;
		static const int BITS_PER_DIGIT = 32; 
		static const BaseType RADIX = 4294967296; // 2^32 
		static const BaseType MAX_DIGIT_VALUE = RADIX - 1; // 2^32 - 1. The maximum value each digit can hold.

	private:
		// TODO: Change this to little endian to help with addition and substraction
		/*
			Vector containing all the digits in little-endian (reversed) fashion.
			Ex: 0x456 is represented as [6, 5, 4]

			No trailing zeros. I.e, [1, 3, 0 , 0] is not accepted.
		*/
		std::vector<BaseType> digits;

		/*
			The sign of the number.

			1 for Positive or Zero
			-1 for Negative

			Will be positive by default.
		*/
		signed char sign = 1;

		void addDigits(BaseType n1, BaseType n2, BaseType& sum, int& carry);
		

	public:
		BigInt();
		BigInt(std::vector<BaseType>);
		// TODO: add destructor

		// String conversions;
		std::string toRawString();
		static BigInt fromBinString(std::string s);
		std::string toBinString();
		static BigInt fromDecString(std::string s);
		std::string toDecString();
		
		void makePositive();
		void makeNegative();
		void makeZeroSign();
		static std::vector<BaseType> fromString(std::string s);

		// Operations

		// Addition
		BigInt sumAbs(const BigInt& n1, const BigInt& n2);
		BigInt operator+(const BigInt& other);
		BigInt operator+=(const BigInt& other);
		BigInt& operator++(); // Prefix increment
		BigInt operator++(int n);	// Postfix increment

		// Subtraction
		BigInt operator-(const BigInt& other);
		BigInt operator-() const;



		// Comparisons
		signed char compareAbs(const BigInt& n1, const BigInt& n2);
		bool operator==(const BigInt& other);
		bool operator!=(const BigInt& other);
		bool operator>(const BigInt& other);
		bool operator>=(const BigInt& other);
		bool operator<(const BigInt& other);
		bool operator<=(const BigInt& other);
};

#endif