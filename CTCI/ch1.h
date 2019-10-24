#pragma once
#include <string>
#include <vector>

// Problems from Chapter 1 of Cracking the Coding Interview, 6th Edition
namespace CTCI {

	// Given a string, determine if it has all unique characters
	bool IsUnique(const std::string& str);
	
	// Given 2 strings check is they are permuatations of one another
	bool CheckPermutation(const std::string& a, const std::string& b);

	// Given a string and its true lenghtr replace all spaces(' ') with "%20",
	// assume you have enough space at the end of string as buffer
	std::string URLify(const std::string& src, int lenght);

	// Given a string, determine if the string is a permutation of a palindrome
	bool PermutationPalindrome(const std::string& src);

	// Given 2 string, determine if the number of edits you'd need to make to one of them
	// to turn into the other one is less than 1.
	bool OneAway(const std::string& a, const std::string& b);

	// Given a string of characters from 'a' .. 'z', compress it by the number of occurrences of characters
	// Return the original string if the length of the compressed string is higher than the length og the original string.
	// ex. "aabccca" -> "a2b1c3a1"
	std::string StringCompression(const std::string& src);


	void PrintMatrix(const std::vector<std::vector<int>>& mat);
	// Rotate a matrix by 90 in place
	void RotateMatrix90Degrees(std::vector<std::vector<int>>& matrix);

	// If an element in the given matrix is 0, set the entire row and column to also 0.
	void ZeroMatrix(std::vector<std::vector<int>>& matrix);

	// By only calling a function isSubstring(), determine if the 2 given strings are rotations of one another
	// ex. waterbottle and terbottlewa are rotations
	bool StringRotation(const std::string& a, const std::string& b);

	void Ch1_Main();
}