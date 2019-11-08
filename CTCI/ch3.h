#pragma once

#include <array>
#include "../Core.h"

// Stacks and Queues
// Problems from Chapter 3 of Cracking the Coding Interview, 6th Edition
namespace CTCI {

	// Single array to implement 3 stacks
	template<typename T, int N>
	class ArrayStack {
	public:
		ArrayStack<T, N>()
		:	m_FTop(0),
			m_SStack(N / 3),
			m_STop(0),
			m_TStack(2 * N / 3),
			m_TTop(0)
		{}

		void Push(int stackNum, T x) {
			switch (stackNum) 
			{
				case 1: 
				{
					array[m_FTop] = x;
					m_FTop++;
					break;
				}
				case 2:
				{
					array[m_STop + m_SStack] = x;
					m_STop++;
					break;
				}
				case 3:
				{
					array[m_TTop + m_TStack] = x;
					m_TTop++;
					break;
				}
			}
		}

		void Pop(int stackNum) {
			switch (stackNum)
			{
				case 1:
				{
					m_FTop--;
					break;
				}
				case 2:
				{
					m_STop--;
					break;
				}
				case 3:
				{
					m_TTop--;
					break;
				}
			}
		}

		T Peek(int stackNum) {
			switch (stackNum)
			{
				case 1:		return array[m_FTop - 1];
				case 2:		return array[m_STop + m_SStack - 1];
				case 3:		return array[m_TTop + m_TStack - 1];
			}
		}

		bool IsEmpty(int stackNum) {
			switch (stackNum)
			{
				case 1:		return m_FTop == 0;
				case 2:		return m_STop == 0;
				case 3:		return m_TTop == 0;
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const ArrayStack<T, N>& arr) {
			os << "The first stack:\n";
			for (int i = 0; i < N; i++) {
				if (i == N / 3)			 os << "\n\nThe second stack:\n";
				else if (i == 2 * N / 3) os << "\n\nThe third stack:\n";

				os << arr.array[i] << " ";
			}
			os << '\n';
			return os;
		}

	private:

		std::array<T, N> array;
		int m_FTop;
		int m_SStack;
		int m_STop;
		int m_TStack;
		int m_TTop;

	};

	// A stack that has a O(1) min function that returns the minimum element

	// Stack of plates where if the number of elements go over a MAX_THRESHOLD
	// push the nex element into a new stack

	// Implement a queue with 2 stacks

	// Sort a stack by only using 1 more stack

	// Animal Shelter, create a data structures to maintain a system where
	// People can only adopt the oldest cat, dog or animal(cats and dogs).
	// They can choose the kind of animal they want but they cannot specifically
	// pick an element (i.e. 3 queues)

	void Ch3_Main();
}
