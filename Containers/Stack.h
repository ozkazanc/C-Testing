#pragma once
#include <list>

template<typename T>
class Stack {

public:
	T pop() {
		T temp = std::move(stack.back());
		stack.pop_back();
		return temp;
	}

	inline void push(T x) { stack.push_back(x); }
	inline bool empty() const { return stack.empty(); }
	inline T peek() const { return stack.back(); }

private:
	std::list<T> stack;
};