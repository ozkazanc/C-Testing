#include "TimedButtonPressed.h"

namespace TimedButtonPressed {

	void Main() {
		bool pressed = false;
		int timer = 5;
		double counter = timer;
		std::cout << "You have " << timer << " seconds to press the 'F' key." << std::endl;
		//for (int k = 0; k < 4; k++)
		//	std::cout << ("\x27\x25\x26\Q")[k] << std::endl;
		//std::cout << " " << std::endl;
		while (true) {
			int i = 0;
			while (counter > 0)
			{
				std::cout << "\rTime remaining: " << std::setw(2) << std::setprecision(1) << std::fixed << counter << std::flush;
				// Rotating characters
				std::cout << ' ' << "-\\|/"[i % 4] << std::flush;

				Sleep(100);
				// Check if the "F" key was pressed
				pressed = (0x8000 & GetAsyncKeyState(0x46)) != 0;
				if (pressed) {
					std::cout << "\nNice job!" << std::endl;
					counter = timer + 0.1;
				}
				counter -= 0.1;
				i++;
			}
			std::cout << "\nYou missed it" << std::endl;
			counter = timer;
		}

	}
}