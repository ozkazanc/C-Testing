#include "ch3.h"
#include <string>

namespace CTCI {

	void Ch3_Main() {
		// Q1 ================================================================================================
		ArrayStack<std::string, 9> arrayStack;
		arrayStack.Push(1, "my");
		arrayStack.Push(1, "stack");

		arrayStack.Push(2, "first");
		arrayStack.Push(2, "try");

		arrayStack.Push(3, "stack");
		arrayStack.Push(3, "works");
		arrayStack.Push(3, "great");
		std::cout << arrayStack << '\n';

		arrayStack.Pop(2);
		arrayStack.Pop(2);
		arrayStack.Pop(3);
		arrayStack.Pop(1);
		std::cout << "The first stack is " << (arrayStack.IsEmpty(1) ? "empty" : "not empty") << '\n';
		std::cout << "The second stack is " << (arrayStack.IsEmpty(2) ? "empty" : "not empty") << '\n';
		std::cout << "Peeked third stack " << arrayStack.Peek(3) << '\n';
		std::cout << std::endl;
		// Q2 ================================================================================================

		// Q3 ================================================================================================
		// Q4 ================================================================================================
		// Q5 ================================================================================================
		// Q6 ================================================================================================
	}
}