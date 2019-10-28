#include "ch2.h"

#include <unordered_map>
#include <algorithm>

namespace CTCI {
	void Ch2_Main() {
		// Q1 ================================================================================================
		std::vector<std::list<int>> dups{ { 1,1,2,3,4,5,3,2,6,6 },{},{1,1,1,1},{1,2,3,4,5},{2,1,1,2} };
		std::cout << dups << '\n';
		std::for_each(dups.begin(), dups.end(), RemoveDuplicates);
		std::cout << dups << std::endl;
		// Q2 ================================================================================================
		
		// Q3 ================================================================================================
		
		// Q4 ================================================================================================
		
		// Q5 ================================================================================================
		
		// Q6 ================================================================================================
		
		// Q7 ================================================================================================
		
		// Q8 ================================================================================================
		
	}
	void RemoveDuplicates(std::list<int>& list) {
		
		// Put all the elements into a hash map with a count
		// if count > 1 then delete the element
		std::unordered_map<int, int> count;
		for (auto it = list.begin(); it != list.end(); it++) {
			int numCount = ++count[*it];
			if (numCount > 1) {
				it = list.erase(it);
				it--;
			}
		}
		//std::cout << count << '\n';

		// O(n) time, where n is the length of the linked list
		// O(n) space, same as time analysis since we create a map of n elements.

		// We could improve the space complexity to O(1) by implementing nested loops,
		// and checking all elements with one another but that makes time complexity O(n^2)

		// Note: Inserting and accessing hash table is O(1)
		// Deleting from linked list is O(n) (although, since we use std::list it is actually O(1))
		// They do not change the time complexity
	}

	int KthToTheLast(const std::list<int>& list) {
		return 0;
	}

	void DeleteMiddleNode(int node) {

	}

	// Partition

	std::list<int> AddLinkedLists(const std::list<int>& a, const std::list<int>& b) {
		return a;
	}

	bool Palindrome(const std::list<int>& list) {
		return false;
	}

	int Intersect(const std::list<int>& a, const std::list<int>& b) {
		return 0;
	}

	int LoopBeginning(const std::list<int>& list) {
		return 0;
	}

}