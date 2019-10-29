#include "ExceptionHandlingTest.h"

namespace ExceptionHandlingTest {
	void Main() {
		int* p = nullptr;

		try {
			if (!p)
				throw std::runtime_error("p is null");
			*p = 0;
		}
		catch (std::exception& e) {
			std::cerr << "Yo: [ " << e.what() << " ]\n";
		}

		int num = 0;
		int den = 1;

		std::cout << "Enter numerator: ";
		std::cin >> num;
		std::cout << "Enter denominator: ";
		std::cin >> den;
		
		Fraction def(0, 1);
		try {
			Fraction f(num, den);
			using std::swap;
			swap(def, f);
			std::cout << def << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Yo: [ " << e.what() << " ]\n";
		}

	}
}