#include "LevenshteinDistance.h"
#include <iostream>
#include <vector>
#include <algorithm>

namespace LevenshteinDistance {

	void Main() {

		const std::string str1 = "bocok";
		const std::string str2 = "cook";

		int distance = CalculateLevenshtein(str1, str2);

		std::cout << "Levenshtein distance between:" << std::endl 
				  << str1 << " and " << str2 << " is " << distance << std::endl;
	}


	int CalculateLevenshtein(const std::string& str1, const std::string& str2) {
		
		// if we are given an empty string, then the levenshtein distance is equal to the lenght of the other string.
		if (std::min(str1.length(), str2.length()) == 0) return std::min((int)str1.length(), (int)str2.length());

		std::vector<std::vector<int>> lev(str1.length() + 1, std::vector<int>(str2.length() + 1, 0));

		for (unsigned int i = 0; i < lev.size(); i++) {
			for (unsigned int j = 0; j < lev[i].size(); j++) {

				// Populate the first row and column as the number of characters required to make 
				// the given string from an empty string
				if (i == 0) {
					lev[0][j] = j;
					continue;
				}
				if (j == 0) {
					lev[i][0] = i;
					continue;
				}
				
				// Take the minimum of these 4 conditions to calculate the Levenshtein distance

				// lev[i - 1][j] + 1, is for adding a new character
				// lev[i][j - 1] + 1, is for deleting a character
				// lev[i - 1][j - 1] + 1, is for substituting a character
				// lev[i - 1][j - 1] + 0, is when the characters are the same
				
				// Offset the string indices to adjust for adding a new column/row
				lev[i][j] = std::min(std::min(lev[i - 1][j] + 1, lev[i][j - 1] + 1), lev[i - 1][j - 1] + (str1[i - 1] != str2[j - 1] ? 1 : 0));
			}
		}

		// Print the final lev matrix
		for (auto i : lev) {
			for (int j : i)
				std::cout << j;
			std::cout << std::endl;
		}	

		return lev[str1.length()][str2.length()];
	}
}