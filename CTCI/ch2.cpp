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
		std::vector<std::list<int>> kth{ { 1,1,2,3,4,5,3,2,6,6 },{1},{1,1,1,1},{1,2,3,4,5},{2,1,1,2},{5,7} };
		std::vector<int> index{ 2, 0, 5, 3, 2, 1 };
		for (unsigned int i = 0; i < index.size(); i++)
			std::cout << index[i] << "th to the last elem is " << KthToTheLast(kth[i], index[i]) << " for " << kth[i] << '\n';
		// Q3 ================================================================================================
		std::vector<std::list<int>> lists3{ { 1,1,2,3,4,5,3,2,6,6 },{1},{1,1,1,1},{1,2,3,4,5},{2,1,1,2},{5,7} };
		std::vector<int> middle{ 2, 0, 5, 3, 2, 0 };
		for (unsigned int i = 0; i < middle.size(); i++) {
			std::cout << lists3[i] << '\n';
			DeleteMiddleNode(lists3[i], middle[i]);
			std::cout << lists3[i] << '\n';
		}
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

	int KthToTheLast(const std::list<int>& list, int k) {
		std::list<int>::const_iterator cur = list.begin();
		auto trail(cur);

		// Advance the current pointer by k elements
		// to create a gap of k elements
		while (cur != list.end() && k > 0) {
			k--;
			cur++;
		}

		// Advance both elements
		// When current is pointing to the last element
		// trailing pointer will point to the kth to the last element
		while (cur != list.end()) {
			trail++;
			cur++;
		}
		return trail == list.begin() ? *trail : *(--trail);

		// O(n) time, where n is the length of the linked list
		// O(1) space, we only traverse the linked list
	}

	void DeleteMiddleNode(std::list<int>& list, int node) {
		auto cur = list.begin();
		
		// Advance the current pointer to the node
		if (node >= list.size()) return;
		std::advance(cur, node);

		// If we are given the last element, we cannot solve this problem
		if (cur == --list.end()) return;

		// Copy the next node into this node
		while (cur != --list.end()) {
			auto temp(cur);
			*cur = *(++temp);
			cur++;
		}

		// Delete the last element
		list.erase(cur);
		return;

		// O(n) time, where n is the size of the list
		// O(1) space, in place algorithm
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