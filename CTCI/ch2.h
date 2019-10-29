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

	// Partition

	// Do addition to numbers where numbers are represented as linked list
	// First in  LSD-First (Least Significant Digit)
	// Second in MSD-First (Most Significcan Digit)
	// ex LSD-First,  2 -> 7 -> 0 and 3 -> 4 -> 1, ie. 72 + 143
	// returns 5 -> 1 -> 2, ie. 215
	// ex MSD-First, 0->7->2 and 1->4->3 equals 2->1->5
	std::list<int> AddLinkedLists(const std::list<int>& a, const std::list<int>& b);

	// Given a singly linked list determine if it is a palindrome
	bool Palindrome(const std::list<int>& list);

	// Given 2 lists, determine if they intersect and return the intersecting node
	int Intersect(const std::list<int>& a, const std::list<int>& b);

	// Given a circular linked list (corrupt), return the node at the beginning of the loop
	int LoopBeginning(const std::list<int>& list);

	void Ch2_Main();
}