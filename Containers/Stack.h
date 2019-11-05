#pragma once
#include <list>
#include "../Core.h"		// for printing std::list

template<typename T>
class Stack {

public:
	Stack() {}
	Stack(std::initializer_list<T> list) 
	{
		for (const auto& elem : list)	push(elem);
	}

	T pop() {
		T temp = std::move(stack.back());
		stack.pop_back();
		return temp;
	}

	inline void push(T x) { stack.push_back(x); }
	inline bool empty() const { return stack.empty(); }
	inline T peek() const { return stack.back(); }

	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack_) {
		os << "Stack is: " << stack_.stack;
		return os;
	}

private:
	std::list<T> stack;
};

namespace StackTesting {

	Stack<int> makeStack() { return Stack<int>{1, 2, 3, 4}; }
	void Main() {
		Stack<int> stack{ 1,2,3,4 };
		std::cout << stack;

		int x = stack.peek();
		int* pPeek = &x;

		//const int* pPeek = &makeStack().peek();		//does not compile if peek() returns T

		std::cout << "Peeked " << *pPeek << '\n';

		// Item 28 - Avoid returning "handles" to object internals
		// pPeek dangles if peek() returns const T& so peek() must return T
		// if peek() returns an r-value, the compiler does not even allow taking the address of it 
		// (since it will be destroyed by the end of the statement)
	}
}