#include "UnionTypePunning.h"

namespace UnionTypePunning {
	void Main() {
		storage abc;
		abc.type = Type::CHAR_;
		abc.v.c = 'A';

		int in = 0;
		char ch = '@';
		std::cout << "Type a number or a char: ";
		std::string input;
		std::cin >> input;

		std::cout << in << std::endl;
		
		std::cout << "type1: " << abc.type << std::endl;
		std::cout << "Char: " << abc.v.c << std::endl;
		std::cout << "Int: " << abc.v.i << std::endl;
	}
}