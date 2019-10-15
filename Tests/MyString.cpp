#include "MyString.h"
#include <utility>

namespace MyString {
	void Main() {
		std::string hello = "Hello";
		std::string world = "World";
		std::string move = "Move";


		MyString s(hello);

		MyString p;
		p = MyString(world);

		MyString m = MyString(move);
		MyString c(p);

		std::cout << std::endl;
		MyString sp = s + p;
		std::cout << sp << std::endl;

		std::cout << s << p << m << c << std::endl;

		MyString n = std::move(s);
		m = p;

		std::cout << std::endl;
		std::cout << s << p << m << c << n << std::endl;

		std::cout << std::endl;
		std::cout << "Size of char*: " << sizeof(char*) << std::endl;
		std::cout << "Size of unsigned int: " << sizeof(unsigned int) << std::endl;
		std::cout << "Size of MyString: " << sizeof(MyString) << std::endl;

		std::cout << std::endl;
		MyString arr[5];
		std::cout << "Size of arr: " << sizeof(arr) << std::endl;

	}
}