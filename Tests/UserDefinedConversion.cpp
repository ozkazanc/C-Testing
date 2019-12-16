#include "UserDefinedConversion.h"
#include <iostream>
#include <cassert>

namespace UserDefinedConversion {
	namespace {
		enum class Result { Lose, Draw, Win };
		struct GameResult {
			Result res;
			explicit operator char() const {
				switch (res) {
					case Result::Lose: return 'L';
					case Result::Draw: return 'D';
					case Result::Win: return 'W';
					default: assert(false); return '\0';
				}
			}
		};
	}

	void Main() {
		GameResult game;
		game.res = Result::Win;
		std::cout << (char)game << std::endl;

		// Implicit conversion is not allowed to due to 'explicit' keyword
		// int y = game;				// does not compile
		// int y = (int)game			// does not compile		
	}
}