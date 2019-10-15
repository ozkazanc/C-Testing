#include "ConsoleColor.h"
#include <iostream>
#include <Windows.h>

namespace ConsoleColor {

	void Main() {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		unsigned char k;
		// you can loop k higher to see more color choices
		for (k = 0; k < 255; k++)
		{
			// pick the colorattribute k you want
			SetConsoleTextAttribute(hConsole, k);
			std::cout << (unsigned int)k << " I want to be nice today!" << std::endl;
		}

		std::cout << k << " It's sweet!" << std::endl;
	}
}