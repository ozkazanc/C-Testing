#include "RegularExpressionsTest.h"

#include <iostream>
#include <regex>
#include <string>

namespace RegularExpressionsTest {
	void Main() {
		std::string str = R"( This is a string to search. I'm testing regular expressions in c++
It's very useful in designing a compiler, and user input checking and what not. Nice to learn more about it!)";

		// All words starting with 'c'
		//std::regex re("\\sc[a-z\\+]*");
		//std::string ans("c++, compiler, checking");

		// All words ending with 'ing' with capturing additional info
		std::regex re("([a-z]*)(ing)\\s");
		std::string ans("string, testing, designing, checking");

		// All 2 letter words
		//std::regex re("\\s[a-zA-Z]{2}[\\s!\)]");
		//std::string ans("is, to, in, in, to, it");

		auto matches_begin = std::sregex_iterator(str.begin(), str.end(), re);
		auto matches_end = std::sregex_iterator();

		std::cout << "Found "
				  << std::distance(matches_begin, matches_end)
				  << " matching words:\n";

		for (std::sregex_iterator i = matches_begin; i != matches_end; i++) {
			std::smatch m = *i;
			
			std::cout << "Captured ";
			for (std::size_t i = 0; i < m.size(); i++)	 std::cout << i << "-" << m[i] << " ";
			
			std::string match_str = m.str();
			std::cout << "\nMatch "<< match_str << "\n\n";
		}

		std::cout << "Result should be " << ans << std::endl;
	}
}