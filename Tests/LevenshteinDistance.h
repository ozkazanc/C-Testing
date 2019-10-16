#pragma once
#include <string>

// Calculate the levenshtein distance between 2 strings bu using Dynamic Programming
namespace LevenshteinDistance {
	void Main();
	int CalculateLevenshtein(const std::string& str1, const std::string& str2);
}