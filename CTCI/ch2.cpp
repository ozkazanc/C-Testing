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
		std::cout << std::endl;
		// Q4 ================================================================================================
		std::vector<std::list<int>> as{ { 2,7,0 },{9,9},{1,1,1,1},{1,2,3},{9,1},{5,7} };
		std::vector<std::list<int>> bs{ { 3,4,1 },{1,0},{1,1,1,1},{1,2,3},{0,7},{5,7} };
		for (unsigned int i = 0; i < as.size(); i++) {
			std::cout << "Adding " << as[i] << " and " << bs[i] << " equals " << AddLinkedLists(as[i], bs[i]) << '\n';
		}
		std::cout << std::endl;
		// Q5 ================================================================================================
		std::vector<std::list<char>> palindromes{ {'t','a','c','o','c','a','t'}, {'p','o','p'},{'a','b','b','a'},{'s','u','p'},{'h','e','l','l','o'} };
		for (const auto& elem : palindromes)
			std::cout << elem << " is " << (Palindrome(elem) ? "palindrome!" : "not a palindrome") << '\n';
		std::cout << std::endl;
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

		// If we get an index that is larger than the size of the list
		// return first element
		if (k >= list.size()) return *list.begin();
		
		std::list<int>::const_iterator cur = list.begin();
		auto trail(cur);
		
		// Advance the current pointer by k elements
		// to create a gap of k elements
		std::advance(cur, k);

		// Advance both elements
		// When current is pointing to the last element
		// trailing pointer will point to the kth to the last element
		while (cur != --list.end()) {
			trail++;
			cur++;
		}
		return *trail;

		// O(n) time, where n is the length of the linked list
		// O(1) space, we only traverse the linked list
	}

	void DeleteMiddleNode(std::list<int>& list, int node) {
		if (node >= list.size()) return;
		
		// Advance the current pointer to the node
		auto cur = list.begin();
		std::advance(cur, node);

		// If we are given the last element, we cannot solve this problem
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

	int sumLists(const std::list<int>& a, const std::list<int>& b, std::list<int>& result) {
		if (a.empty()) return 0;
		auto it1 = a.begin();
		auto it2 = b.begin();
		
		int sum = *it1 + *it2;

		// Sum the rest of the list to check if there will be a carry bit
		sum += sumLists(std::list<int>(++it1, a.end()), std::list<int>(++it2, b.end()), result);

		result.push_front(sum % 10);
		
		// Return if the carry bit.
		// Carry bit will be on if the sum adds up to more than 9
		return sum / 10;
	}

	std::list<int> AddLinkedLists(std::list<int> a, std::list<int> b) {

		// LSD-First =========================================================

		// Pad 0s at the end to make lengths equal.
		//if (a.size() > b.size()) b.insert(b.end(), a.size() - b.size(), 0);
		//else if (b.size() > a.size()) a.insert(a.end(), b.size() - a.size(), 0);

		//std::list<int> result;
		//int carry = 0;
		//for (auto it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
		//	int sum = *it1 + *it2 + carry;
		//	
		//	// Carry bit will be on if the sum adds up to more than 9
		//	// which will be added next iteration
		//	carry = sum / 10;
		//	result.push_back(sum % 10);
		//}
		//// If the carry bit is on after the loop is done
		//// we need to add a new digit
		//if (carry) result.push_back(carry);

		//return result;

		// O(n) time, where n is the length of the list which is the number of digits of the represented number
		// O(n) space, same as time analysis since we need to create a new list containing the same amount of digits
		
		// MSD-First =========================================================
		
		// Pad 0s at the front to make lengths equal.
		if (a.size() > b.size()) b.insert(b.begin(), a.size() - b.size(), 0);
		else if (b.size() > a.size()) a.insert(a.begin(), b.size() - a.size(), 0);

		std::list<int> result;
		
		// If there is a carry bit push digit 1 in front
		if (sumLists(a, b, result))
			result.push_front(1);
		
		return result;

		// O(n) time, where n is the number of elements and since we are touching every element in the lists once
		// O(n) space, since we are going to make n recursive calls to sumList function for each element in the list.
	}

	bool Palindrome(const std::list<char>& list) {
		// Solution 1 - Reverse and Compare
		std::list<char> rev;
		
		//rev.reverse();
		for (const auto& elem : list)
			rev.push_front(elem);

		return rev == list;

		// O(n) time, where n is the size of the list we need to push all the elements to the front to create the reversed list
		// O(n) space, since we create a temp reversed list

		// Solution 2 - Iterative
		// Set 2 pointers slow/fast. Push to a stack from slow pointer,
		// When fast is null, slow will be in the middle where we can start comparing.

		// Solution 3 - Recursive
		// Check recursively the first and the last elements to see if they are equal
		// tacocat -> Palindrome(t(a(c(o)c)a)t)



		return false;
	}

	int Intersect(const std::list<int>& a, const std::list<int>& b) {
		return 0;
	}

	int LoopBeginning(const std::list<int>& list) {
		return 0;
	}

}