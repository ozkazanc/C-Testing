#include <iostream>
#include "Timer.h"

#include "Tests/ConsoleColor.h"
#include "Tests/ExceptionHandlingTest.h"
#include "Tests/SimpleClass.h"
#include "Tests/StringLiterals.h"
#include "Tests/TimedButtonPressed.h"
#include "Tests/UnionTypePunning.h"
#include "Tests/RegularExpressionsTest.h"

#include "Algorithms/Knapsack.h"
#include "Algorithms/LevenshteinDistance.h"

#include "Containers/MyString.h"
#include "Containers/LinkedList.h"
#include "Containers/Stack.h"
#include "Containers/Trie.h"

#include "CTCI/ch1.h"
#include "CTCI/ch2.h"
#include "CTCI/ch3.h"

int main() {
	// Start the timer
	Timer timer;

	// Uncomment the main function of the appropriate test you want to run!
	//======================================================================
	
	//ConsoleColor::Main();
	//ExceptionHandlingTest::Main();
	//SimpleClass::Main();
	//StringLiterals::Main();
	//TimedButtonPressed::Main();
	//UnionTypePunning::Main();
	RegularExpressionsTest::Main();

	//Knapsack::Main();
	//LevenshteinDistance::Main();

	//MyString::Main();
	//LinkedListTest::Main();
	//StackTesting::Main();
	//TrieTest::Main();

	//CTCI::Ch1_Main();
	//CTCI::Ch2_Main();
	//CTCI::Ch3_Main();

	
	//======================================================================

	// Get the final time
	std::cout << std::endl;
	double time = timer.Elapsed();
	std::cout << time << " s" << std::endl;
	std::cout << 1000 * time << " ms" << std::endl;
	
	// Wait to observe the console
	std::cin.get();
	return 0;
}