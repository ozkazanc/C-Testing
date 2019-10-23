#include "ch1.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include "LevenshteinDistance.h"
namespace CTCI {

	void Ch1_Main() {
	// Q1 ================================================================================================
		std::vector<std::string> uniques{ "palindrome", "exceptions", "esteem", "fake" };
		for (const auto& elem : uniques)
			std::cout << elem << " is " << (IsUnique(elem) ? "unique!" : " not unique") << '\n';
		std::cout << std::endl;
	// Q2 ================================================================================================
		std::vector<std::string> perm1{ "asdf", "net", "tur", "hello", "preference" };
		std::vector<std::string> perm2{ "fdsa", "ten", "fur", "hewlo", "rfeeercnep" };
		for (size_t i = 0; i < perm1.size(); i++) {
			std::cout << perm1[i] << " and " << perm2[i] << " are " << (CheckPermutation(perm1[i], perm2[i]) ? "perms!" : " not perms") << '\n';
		}
		std::cout << std::endl;
	// Q3 ================================================================================================
		std::vector<std::string> urls{ "     hi    ", "hello", "you are welcome", "testing 1 ", " " };
		for (const auto& elem : urls)
			std::cout << elem << " turned into: " << URLify(elem, (int)elem.length()) << '\n';
		std::cout << std::endl;
	// Q4 ================================================================================================
		std::vector<std::string> palindromes{ "taco cat", "hello", "never odd or even", "odd", "yeshhes", "eyes" };
		for (const auto& elem : palindromes)
			std::cout << elem << (PermutationPalindrome(elem) ? " can" : " cannot") << " be a palindrome\n";
		std::cout << std::endl;
	// Q5 ================================================================================================
		for (size_t i = 0; i < perm1.size(); i++) {
			std::cout << perm1[i] << " and " << perm2[i] << " are " << (OneAway(perm1[i], perm2[i]) ? "one away!" : " not one away") << '\n';
		}
		std::cout << std::endl;
	// Q6 ================================================================================================

	}

	bool IsUnique(const std::string& str) {
		// Assume that the string consists of only 'a'.. 'z'
		int32_t bitflag = 0;	//could have used std::bitset<32>
		for (int i = 0; i < str.length(); i++) {
			int offset = str[i] - 'a';
			if (bitflag & (1 << offset))
				return false;
			else
				bitflag |= 1 << offset;
		}
		return true;
		
		// O(n) time, where n is the length of the array
		// O(1) space, only using 2 ints though space depends on the number of characters
		// to represent. If a character is stored in n bits, then there are 2^n possible characters
		// and therefore we would need 2^n bits to represent each character.

		// For no extra space
		// 1- We could have sorted the array in place with bubble or heap sort 
		// and then check if there are any duplicates. O(n^2) | O(n log n) time
		// 2 - We could have done nested loops, and checked every char with the entire string. O(n^2) time
	}

	bool CheckPermutation(const std::string& a, const std::string& b) {
		// If their lenghts are different, they cannot be permutations of one another
		if (a.length() != b.length()) return false;

		// Xor operation will cancel the same characters; so if every character in string a
		// appears in string b, then xor will return 0
		int32_t xor_ = 0;
		for (size_t i = 0; i < a.length(); i++){
			xor_ = a[i] ^ b[i] ^ xor_;
		}
		return xor_ == 0;

		// O(n) time, where n is the lenght of the longer string
		// O(1) space, a single 32 bit int value to accomodate Unicode chars (UTF-32)
		// just need the same number of bits required to store the character 
		// if character set is ASCII then a char (1 Byte) would do.
	}

	std::string URLify(const std::string& src, int length) {
		std::vector<char> temp;
		for (size_t i = 0; i < src.length(); i++) {
			if (src[i] == ' ') {
				temp.push_back('%');
				temp.push_back('2');
				temp.push_back('0');
			}
			else {
				temp.push_back(src[i]);
			}
		}
		return std::string(temp.begin(), temp.end());

		// O(n) time, where n is the lenght of the string
		// O(n) space, where n is the lenght of the string
	}

	inline bool IsEven(int n) { return n % 2 == 0; }
	std::string EliminateSpaces(const std::string& src) {
		std::vector<char> temp;
		for (size_t i = 0; i < src.length(); i++) {
			if (!std::isspace(src[i]))
				temp.push_back(src[i]);
		}
		return std::string(temp.begin(), temp.end());
	}

	bool PermutationPalindrome(const std::string& src) {
		// We do not wanr to take spaces into account
		std::string temp = EliminateSpaces(src);

		// Make a hash table of character to its count
		std::unordered_map<char, int> charCount;
		for (size_t i = 0; i < temp.length(); i++) {
			charCount[temp[i]]++;
		}
		
		bool oddFound(IsEven((int)temp.length()) ? 1 : 0);
		for (const auto& elem : charCount) {
			if (!IsEven(elem.second)) {
				// If we find a second odd numbered letter return false
				if (oddFound)	return false;
				else oddFound = true;
			}
		}
		return true;

		// Can be done using a bitset to toggle bits, 1 if odd, 0 if even and check if there is only 1 bit set.
		// O(n) time, where n is the length of the string
		// O(n) space, same as time analysis
	}


	bool OneAway(const std::string& a, const std::string& b) {
		return LevenshteinDistance::CalculateLevenshtein(a, b) < 2;

		//Levenshtein distance is an algorithm that calculates the number of edits between 2 strings
		// O(n * m) time, where n and m are the respective lenght of the strings
		// O(n * m) space, same as time analysis
	}
}