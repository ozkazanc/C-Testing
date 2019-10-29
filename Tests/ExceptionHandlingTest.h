#pragma once

#include <iostream>
#include <exception>

namespace ExceptionHandlingTest {

	class Fraction {
	private:
		int denominator;
		int numerator;

	public:

		Fraction(int num, int den)
			:numerator(num), denominator(den)
		{
			if (denominator == 0)
				throw std::runtime_error("Denominator cannot be 0!");
		}

		friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
			os << frac.numerator << "/" << frac.denominator << '\n';
			return os;
		}

	};
	void Main();
}