#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "../Core.h"

// Linked Lists
// Problems from Chapter 2 of Cracking the Coding Interview, 6th Edition
namespace CTCI {
	
	// Given an unsorted singly linked list, remove its duplicate elements
	void RemoveDuplicates(std::list<int>& list);

	// Given a singly linked list, return  the kth to the last element
	int KthToTheLast(const std::list<int>& list, int k);

	// Given only a middle node, delete that node from the linked list
	void DeleteMiddleNode(std::list<int>& list, int node);

	// Given a linked list and a value x, create a partition where all elements less than x
	// are to the left and all elements greater or equal to x are to the right 
	// (elements equal to x do not have to be in the middle)
	// eg. 2->3->6->5->8->2->1->5 value 5
	//	   2->3->2->1->6->5->8->5
	void Partition(std::list<int>& list, int x);

	// Do addition to numbers where numbers are represented as linked list
	// First in  LSD-First (Least Significant Digit)
	// Second in MSD-First (Most Significcan Digit)
	// ex LSD-First,  2 -> 7 and 3 -> 4 -> 1, ie. 72 + 143
	// returns 5 -> 1 -> 2, ie. 215
	// ex MSD-First, 0->7->2 and 1->4->3 equals 2->1->5
	std::list<int> AddLinkedLists(std::list<int> a, std::list<int> b);

	// Given a singly linked list determine if it is a palindrome
	bool Palindrome(const std::list<char>& list);

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

	// Eg. 1->2->3->2 list has a loop starting at node 2.
	// (Even though only the data they contain are looping and the actual linked list in memory does NOT have a loop)
	// The reason for the extra nodes at the end after loop is to simulate the effect of the loop as well as giving
	// std::list iterator enough time to realize that there is a loop in the list.

	// Given 2 lists, determine if they intersect and return the intersecting node
	int Intersect(const std::list<int>& a, const std::list<int>& b);

	// Given a circular linked list (corrupt), return the node at the beginning of the loop
	int LoopBeginning(const std::list<int>& list);

	void Ch2_Main();
}