#include "ch1.h"
#include <iostream>
#include <vector>

namespace CTCI {

	void Ch1_Main() {
		std::vector<std::string> strings{ "palindrome", "exceptions", "esteem", "fake" };

		for (const auto& elem : strings)
			std::cout << elem << " is " << (IsUnique(elem) ? "unique!" : " not unique") << '\n';
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
		return false;
	}

	std::string& URLify(std::string& src, int length) {
		return src;
	}

	bool PermutationPalindrome(const std::string& src) {
		return false;

	}

	bool OneAway(const std::string& a, const std::string& b) {
		return false;

	}
}