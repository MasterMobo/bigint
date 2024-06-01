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

		void addDigits(BigInt::BaseType n1, BigInt::BaseType n2, BigInt::BaseType& sum, int& carry, BigInt::BaseType radix);
		

	public:
		BigInt();
		BigInt(BaseType radix);
		BigInt(std::vector<BaseType>, BaseType radix);
		BigInt(std::string s, BaseType radix);
		// TODO: add destructor

		std::vector<BaseType> getDigits();

		static std::vector<BaseType> fromString(std::string s);
		void display();

		// Operations
		BigInt operator+(const BigInt& other);

		// Comparisons
		bool operator==(const BigInt& other);
		bool operator!=(const BigInt& other);
		bool operator>(const BigInt& other);
		bool operator>=(const BigInt& other);
		bool operator<(const BigInt& other);
		bool operator<=(const BigInt& other);

};

#endif