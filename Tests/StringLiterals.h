#include <iostream>
#include <string>

// Played around with string literals and escape sequences
// differrent ways to store strings. (char*, wchar_t, std::string, raw, unicode, etc.)
namespace StringLiterals{

	#define LINE std::cout << std::endl

	template <typename T>
	void LOG(T value, const std::string msg = "") { std::cout << msg << value << std::endl; }
	
	void Main();

}