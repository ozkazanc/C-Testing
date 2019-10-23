#pragma once
#include <string>


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


	void Ch1_Main();
}