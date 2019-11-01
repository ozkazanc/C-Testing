#include "ch2.h"

#include <unordered_map>
#include <algorithm>
#include <functional>

namespace CTCI {
	void Ch2_Main() {
		// Q1 ================================================================================================
		std::vector<std::list<int>> dups{ { 1,1,2,3,4,5,3,2,6,6 },{},{1,1,1,1},{1,2,3,4,5},{2,1,1,2} };
		std::cout << dups << '\n';
		std::for_each(dups.begin(), dups.end(), RemoveDuplicates);
		std::cout << "After removing duplicates\n";
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
			std::cout << "After deleting " << middle[i] << " index\n";
			DeleteMiddleNode(lists3[i], middle[i]);
			std::cout << lists3[i] << '\n';
		}
		std::cout << std::endl;
		// Q4 ================================================================================================
		std::vector<std::list<int>> partition{ { 1,1,2,3,4,5,3,2,6,6 },{7,2,8,1,9,5,3,4,7},{1,8,1,1},{1,2,9,4,5},{7,1,6,2} };
		std::cout << partition << '\n';
		std::for_each(partition.begin(), partition.end(), std::bind(Partition, std::placeholders::_1, 5));
		std::cout << "After partition with value 5\n";
		std::cout << partition << std::endl;
		// Q5 ================================================================================================
		std::vector<std::list<int>> as{ { 2,7,0 },{9,9},{1,1,1,1},{1,2,3},{9,1},{5,7} };
		std::vector<std::list<int>> bs{ { 3,4,1 },{1,0},{1,1,1,1},{1,2,3},{0,7},{5,7} };
		for (unsigned int i = 0; i < as.size(); i++) {
			std::cout << "Adding " << as[i] << " and " << bs[i] << " equals " << AddLinkedLists(as[i], bs[i]) << '\n';
		}
		std::cout << std::endl;
		// Q6 ================================================================================================
		std::vector<std::list<char>> palindromes{ {'t','a','c','o','c','a','t'}, {'p','o','p'},{'a','b','b','a'},{'s','u','p'},{'h','e','l','l','o'}, {'a'},{'t','t','o','t','t' } };
		for (const auto& elem : palindromes)
			std::cout << elem << " is " << (Palindrome(elem) ? "palindrome!" : "not a palindrome") << '\n';
		std::cout << std::endl;
		// Q7 ================================================================================================
		std::vector<std::list<int>> ll{ { 2,7,0 },{9,9},{1,2,3,4},{6,2,3},{9,1},{5,7} };
		std::vector<std::list<int>> sl{ { 3,4 },{9},{1,3,4},{9,1,3},{0,7},{5,7} };
		for (unsigned int i = 0; i < ll.size(); i++) {
			std::cout << "Intersecting " << ll[i] << " and " << sl[i] << " equals " << Intersect(ll[i], sl[i]) << '\n';
		}
		std::cout << std::endl;
		// Q8 ================================================================================================
		std::vector<std::list<int>> loops{ { 2,7,0,2,7,0,2,7,0,2,7,0,2,7,0 },{9,9,9,9,9,9,9,9,9},
										{1,2,3,2,3,2,3,2,3,2,3},{1,2,3,4,5,6,7,8,9,7,8,9,7,8,9,7,8,9,7,8,9,7,8,9},{9,1,2,3,4,3,4,3,4,3,4,3,4,3,4} };
		for (const auto& elem : loops)
			std::cout << elem << " has a loop starting at node " << LoopBeginning(elem) << '\n';
		std::cout << std::endl;
		
		std::cout << "Chapter 2 questions are completed!" << std::endl;
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

	void Partition(std::list<int>& list, int x) {
		std::list<int> smaller;
		std::list<int> larger;

		for (const auto& elem : list) {
			if (elem < x)	smaller.push_back(elem);
			else			larger.push_back(elem);
		}

		// Concatinate smaller and larger lists
		smaller.insert(smaller.end(), larger.begin(), larger.end());

		// Swap the new list with the old one
		list.swap(smaller);

		// O(n) time, where n is the number of elements, we loop to check each element to see if they are smaller or larger than partition value
		// O(n) space, we create a temp list to hold the partition while we are looping the original list.
	}


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
		//std::list<char> rev;
		//
		////rev.reverse();
		//for (const auto& elem : list)
		//	rev.push_front(elem);

		//return rev == list;

		// O(n) time, where n is the size of the list we need to push all the elements to the front to create the reversed list
		// O(n) space, since we create a temp reversed list

		// Solution 2 - Iterative
		// Set 2 pointers slow/fast. Push to a stack from slow pointer,
		// When fast is null, slow will be in the middle where we can start comparing.

		bool palindrome = true;
		std::vector<int> stack;
		for (auto it = list.begin(), fst_it = list.begin(); it != list.end(); ) {

			// Push onto stack as long as fast pointer has not reached the end yet.
			if (fst_it != list.end()) {
				stack.push_back(*it);
				it++;
				
				fst_it++;
				// If we reach the end of the list by incrementing once, we do not want to increment it again
				// Also it means that the size of the list is odd, which is why we pop the "middle" node since it does not affect symmetry
				if (fst_it == list.end()) {
					stack.pop_back();
					continue;
				}
				fst_it++;
			}
			// Slow pointer will in the middle and we can compare what we have left with what is in the stack
			// Pop
			else {
				palindrome &= *it == stack.back();
				stack.pop_back();
				it++;
			}
		}
		return palindrome;

		// O(n) time, where n is the number of elements in the list, we loop through the list once
		// O(n) space, we use a stack and push half the elements onto the stack.

		// Solution 3 - Recursive
		// Check recursively the first and the last elements to see if they are equal
		// tacocat -> Palindrome(t(a(c(o)c)a)t)
		
		//if (list.size() == 1 || list.size() == 0) return true;

		//std::list<char> temp(list);		
		//temp.pop_front();
		//temp.pop_back();

		//return list.front() == list.back() && Palindrome(temp);

		// O(n) time, where n is the lenght of the linked list since we copy the list once and recurse through it.
		// O(n^2) space, we are pushing a copy of the list on the stack for every recursive call, copy size is n, n recursive calls -> n^2 space
	}

	// Disclaimer
	// These next 2 questions are about the address of the linked lists and how they are laid out in memory.
	// However, since std::list does not allow you to create improper linked lists (with cycles),
	// there is no easy way to write test cases for them to check the correctness of these functions.
	// Therefore I will use unique int values as if they are representing the node ids of the linked list
	// The data stored in the linked lists will "act" as the address of the linked list

	// Even though the linked lists are not correctly represented, the algorithms implemented
	// explain and implement clearly what needs to be done in order to achieve desired functionality.

	// Eg. 1->2->3->4->5 and 9->8->3 lists "intersect" at node 3. 
	// (Even though only the data they contain are the same and the actual linked list in memory do NOT intersect)

	// Eg. 1->2->3->2->3->2->3->2 list has a loop starting at node 2.
	// (Even though only the data they contain are looping and the actual linked list in memory does NOT have a loop)
	// The reason for the extra nodes at the end after loop is to simulate the effect of the loop as well as giving
	// std::list iterator enough time to realize that there is a loop in the list.

	int Intersect(const std::list<int>& a, const std::list<int>& b) {
		
		// Find lengths of 2 lists and the difference of lengths m - lenght of list 1
		// Move	to the kth elemnt of the longer list			 n - lenght of list 2
		// Then move 1 node at a time with both pointers		 k = m - n difference in leght									
		// Where they meet will be the intersecting node

		auto it1 = a.begin();
		auto it2 = b.begin();

		if (a.size() > b.size()) std::advance(it1, a.size() - b.size());
		else if (b.size() > a.size()) std::advance(it2, b.size() - a.size());
		
		while (it1 != a.end() || it2 != b.end()) {
			if (*it1 == *it2) return *it1;
			it1++;
			it2++;
		}

		return -1;

		// O(n) time, where n is #elements in the list, we loop over the list
		// O(1) space, no extra space needed
	}

	int LoopBeginning(const std::list<int>& list) {
		/*
		----------------------------+--------x------+	
					m				|	k			|	x : where the fast and slow pointer meet for the first time
									|				|	m : number of elements until the beginning of the loop
									|				|	n : size of the loop
									|				|	k : number of elements from the beginning of the loop to x
									+---------------+
											n
			Fast pointer moves 2 times as fast as slow pointer

			Therefore:

			Distance covered by fast pointer = 2 * Distance covered by the slow pointer
			(m + n*x + k) = 2 * (m + n*y + k) where x is the number of completed loops for the fast pointer
													y is the number of completed loops for the slow pointer

			Rearranging: m + k = n * (x- 2y)		meaning that m + k is a multiple of n!

			So to get the starting node of the loop
			1- Move m nodes from the meeting point
			2- Move m nodes from head

			Set both pointers to move 1 node at a time and reset one of them to the head node
			After moving both of them for m nodes they will meet again, and where they meet will be the beginning of the loop

		*/
		auto it_Slow = list.begin();
		auto it_Fast = list.begin();

		// Move slow 1 node, and fast 2 nodes until they meet for the first time 
		while (*it_Slow != *it_Fast || it_Slow == list.begin()) {
			std::advance(it_Slow, 1);
			std::advance(it_Fast, 2);
		}

		// Reset slow to the head
		it_Slow = list.begin();

		// Move both pointers 1 node at a time
		// Both pointers will meet again at the node that is the start of the loop
		while (*it_Slow != *it_Fast) {
			std::advance(it_Slow, 1);
			std::advance(it_Fast, 1);
		}

		return *it_Slow;
	}

}