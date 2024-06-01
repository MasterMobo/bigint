#pragma once

#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <vector>

class BigInt
{
	public:
		/* 
			The data type to represent each digit.
			The bigger the type, the more each digit can store.
			Ex: unsigned long long int can store 64 bits in each digit.

			Should be kept unchanged. But if needed, 
			make sure that BaseType is big enough to represent the radix.
		*/
		typedef unsigned long long int BaseType;

	private:
		// TODO: Change this to little endian to help with addition and substraction
		/*
			Vector containing all the digits in big-endian fashion.
			Ex: 0x456 is represented as [4, 5, 6]

			No leading zeros. I.e, [0, 0, 1, 3] is not accepted.
		*/
		std::vector<BaseType> digits;

		/*
			The radix (or base) of the number. 
			CAN NOT be bigger than maximum value of BaseType.
		*/
		BaseType radix;

		/*
			The sign of the number.

			1 for Positive or Zero
			-1 for Negative

			Will be positive by default.
		*/
		signed char sign = 1;

		void addDigits(BigInt::BaseType n1, BigInt::BaseType n2, BigInt::BaseType& sum, int& carry, BigInt::BaseType radix);
		

	public:
		BigInt();
		BigInt(BaseType radix);
		BigInt(std::vector<BaseType>, BaseType radix);
		BigInt(std::string s, BaseType radix);
		// TODO: add destructor

		std::string toString();

		std::vector<BaseType> getDigits();

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