#include "MyString.h"
#include <utility>

namespace MyString {
	void Main() {
		std::string hello = "Hello";
		std::string world = "World";
		std::string move = "Move";

		// Default
		MyString s(hello);

		// Default
		MyString p;

		// Default - Assignment - Destructor
		p = MyString(world);

		// Default
		MyString m = MyString(move);
		
		// Copy
		MyString c(p);

		std::cout << std::endl;
		// Default - Move - Destructor
		MyString sp = s + p;
		std::cout << sp << std::endl;

		// Default - Move - Destructor - Default - Assignment - Destructor
		m = p + s;

		std::cout << s << p << m << c << std::endl;

		// Move
		MyString n = std::move(s);	// s becomes invalid/empty
		
		// Copy - Assignment - Destructor
		m = p;

		std::cout << std::endl;
		std::cout << s << p << m << c << n << std::endl;

		std::cout << std::endl;
		
		// Size of class
		std::cout << "Size of char*: "			<< sizeof(char*)			<< std::endl;
		std::cout << "Size of unsigned int: "	<< sizeof(unsigned int)		<< std::endl;
		std::cout << "Size of MyString: "		<< sizeof(MyString)			<< std::endl;

		std::cout << std::endl;
		MyString arr[5];
		std::cout << "Size of arr: " << sizeof(arr) << std::endl;

		//Destructor x6
	}
}