#include "ch1.h"
#include <iostream>
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
		std::vector<std::string> compression{ "abbccccccca", "heeeello", "never odd or even", "odd", "yeshhees", "eeeyes", "ssss" };
		for (const auto& elem : compression)
			std::cout << elem << " turned into: " << StringCompression(elem) << '\n';
		std::cout << std::endl;
	// Q7 ================================================================================================
		std::vector<std::vector<int>> mat90{{1 , 2, 3, 4, 5},
											{6 , 7, 8, 9,10},
											{11,12,13,14,15},
											{16,17,18,19,20},
											{21,22,23,24,25} };
		PrintMatrix(mat90);
		RotateMatrix90Degrees(mat90);
		std::cout << std::endl;
		PrintMatrix(mat90);
		std::cout << std::endl;
	// Q8 ================================================================================================
	// Q9 ================================================================================================

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
		
		// ============== Hash Table Solution ===================================================
		/*

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

		*/

		// ============= Bitset solution by toggling ===============================================

		int32_t bitflag = 0;

		for (size_t i = 0; i < src.length(); i++) {
			// Don't count space characters
			if (std::isspace(src[i])) continue;
			int offset = src[i] - 'a';

			// Toggle the corresponding bit
			bitflag ^= 1 << offset;
		}
		// If all characters in the string are even numbered bitflag will be 0,
		// If only one character is odd numbered (bitflag & (bitflag - 1)) will be 0.
		// ex.
		// bitflag					=  00100000
		// bitflag - 1				=  00011111
		// bitflag & (bitflag - 1)	=  00000000 iff there is exactly 1 bit set. 

		// Think of it like getting rid of a digit. The only way to get rid of a digit 
		// from a number which has n digits is by substracting 1 
		// is if the original number is the smallest number which has n digits.
		// ex.
		// 100 (3 digits) - 1 = 99 (2 digits)
		return bitflag == 0 || (bitflag & (bitflag - 1)) == 0;

		// O(n) time, where n is the length of the string
		// O(2^n) space, where n is the number of bits used to store a character.
	}

	bool OneAway(const std::string& a, const std::string& b) {
		return LevenshteinDistance::CalculateLevenshtein(a, b) < 2;

		//Levenshtein distance is an algorithm that calculates the number of edits between 2 strings
		// O(n * m) time, where n and m are the respective lenght of the strings
		// O(n * m) space, same as time analysis
	}

	std::string StringCompression(const std::string& src) {
		std::vector<char> comp;

		// Keep track of the last seen character and count how many times it was seen
		char lastSeen = src[0];
		int count = 0;

		for (size_t i = 0; i < src.length(); i++) {
			if (lastSeen == src[i]) count++;
			else {
				comp.push_back(lastSeen);
				comp.push_back(char('0' + count));

				// Change the last seen character, count is already one since itself counts as the first
				lastSeen = src[i];
				count = 1;
			}
		}
		// Do not forget to push back the last element
		comp.push_back(lastSeen);
		comp.push_back(char('0' + count));

		std::string res(comp.begin(), comp.end());
		return src.length() > res.length() ? res : src;

		// O(n) time, where n is the length of the string
		// O(n) space, same as time analysis
	}
	
	void PrintMatrix(const std::vector<std::vector<int>>& mat) {
		for (const auto& row : mat) {
			for (const auto& col : row)
				std::cout << col;
			std::cout << '\n';
		}
	}

	void RotateMatrix90Degrees(std::vector<std::vector<int>>& mat){
		unsigned int N = mat.size();
		// Rotate the inner layers
		for (unsigned int x = 0; x < N / 2; x++) {
			for (unsigned int y = x; y < N - 1 - x; y++) {

				// Rotate in 4's
				int temp = mat[x][y];
				mat[x][y] = mat[y][N - 1 - x];
				mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];
				mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];
				mat[N - 1 - y][x] = temp;
			}
		}
		return;

		// O(n^2) time, where n is the size of the matrix
		// O(1) space, no additional space is neededs
	}

	void ZeroMatrix(std::vector<std::vector<int>>& matrix){
	
	}

	bool StringRotation(const std::string& a, const std::string& b){
		return false;
	}
}