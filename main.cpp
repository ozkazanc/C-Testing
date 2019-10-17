#include <iostream>
#include "Timer.h"

#include "ConsoleColor.h"
#include "SimpleClass.h"
#include "MyString.h"
#include "StringLiterals.h"
#include "TimedButtonPressed.h"
#include "UnionTypePunning.h"

#include "Knapsack.h"
#include "LevenshteinDistance.h"

int main() {
	// Start the timer
	Timer timer;

	// Uncomment the main function of the appropriate test you want to run!
	//======================================================================
	
	//ConsoleColor::Main();
	//SimpleClass::Main();
	MyString::Main();
	//StringLiterals::Main();
	//TimedButtonPressed::Main();
	//UnionTypePunning::Main();
	//Knapsack::Main();
	//LevenshteinDistance::Main();

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