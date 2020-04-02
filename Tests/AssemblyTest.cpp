#include "AssemblyTest.h"

#include <stdio.h>
#include <iostream>
namespace AssemblyTest {
	extern "C" int sum(int a, int b) { return a + b; }
	
	void Main() {
		puts("hey");

		int a = 3;
		int b = 5;

		int c;
		c = sum(a, b);
		int d[5] = { 0,0,0,0,0 };
		int e = 10;
		
		std::cout << "a:\t\t" << &a 
				<< "\nb:\t\t" << &b
				<< "\nc:\t\t" << &c 
				<< "\nd_start:\t" << &d[0]
				<< "\nd_end:\t\t" << &d[4] + 1
				<< "\ne:\t\t" << &e 
			<< std::endl;

		//printf("a: %p\nb: %p\nc: %p\nd_start: %p\nd_end: %p\ne: %p\n", &a, &b, &c, &d[0], &d[4] + 1, &e);
		
		// This calls adds 16 to &d[4] not 4 because of pointer arithmetic! (4 * sizeof(int) = 16)
		// std::cout << &d[4] << " + " << sizeof(int) << " = " << &d[4] + sizeof(int);
		b = c;
		
	}
}