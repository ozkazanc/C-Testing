#include "Knapsack.h"
#include <iostream>
#include <algorithm>
#include <vector>

#include "../Timer.h"
namespace Knapsack {

	void Main() {
		const int W = 10;
		std::vector<int> weights{ 3,8,6 };
		std::vector<int> values{ 7,8,4 };

		// Create a matrix of (W + 1) rows to (values + 1) columns (Plus 1 to create the column/row of 0's)
		std::vector<std::vector<int>> profits(W + 1, std::vector<int>(values.size() + 1, 0));
		
		// Time the algorithm in a very basic way
		Timer t;
		
		// w - weights, i - items; start from 1
		for (unsigned int w = 1; w < profits.size(); w++) {
			for (unsigned int i = 1; i < profits[i].size(); i++) {

				if ((int)w - weights[i - 1] < 0)		// cannot carry it, item too heavy
					profits[w][i] = profits[w][i - 1];
				
				else	
					profits[w][i] = std::max(profits[w][i - 1], values[i - 1] + profits[(int)w - weights[i - 1]][i - 1]);

			}
		}

		std::cout << "It took " << t.Elapsed()*1000 << " ms" << std::endl;
		std::cout << "Maximum value is " << profits[W][values.size()] << std::endl;
		
		// Print the final profit matrix
		//for (auto i : profits) {
		//	for (int j : i)
		//		std::cout << j;
		//	std::cout << std::endl;
		//}	
	}
}