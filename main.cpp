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

#include "LinkedList.h"
#include "CTCI/ch1.h"
#include <list>
int main() {
	// Start the timer
	Timer timer;

	// Uncomment the main function of the appropriate test you want to run!
	//======================================================================
	
	//ConsoleColor::Main();
	//SimpleClass::Main();
	//MyString::Main();
	//StringLiterals::Main();
	//TimedButtonPressed::Main();
	//UnionTypePunning::Main();
	//Knapsack::Main();
	//LevenshteinDistance::Main();

	//CTCI::Ch1_Main();
	LinkedList<int> list;
	list.PushFront(3);
	std::cout << list.Size() << std::endl;
	std::cout << list.Front() << std::endl;
	std::cout << list.Back() << std::endl;
	std::cout << list << std::endl;
	
	list.Delete(0);
	std::cout << list.Size() << std::endl;
	std::cout << list << std::endl;
	
	list.PushBack(4);
	std::cout << list.Size() << std::endl;
	std::cout << list.Front() << std::endl;
	std::cout << list.Back() << std::endl;
	std::cout << list << std::endl;

	list.PushFront(5);
	list.PushBack(3);
	std::cout << list.Size() << std::endl;
	std::cout << list.Front() << std::endl;
	std::cout << list.Back() << std::endl;
	std::cout << list << std::endl;

	LinkedList<int> list2(list);
	std::cout << list2.Size() << std::endl;
	std::cout << list2.Front() << std::endl;
	std::cout << list2.Back() << std::endl;
	std::cout << list2 << std::endl;

	list.Delete(2);
	std::cout << list.Size() << std::endl;
	std::cout << list.Front() << std::endl;
	std::cout << list.Back() << std::endl;
	std::cout << list << std::endl;

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