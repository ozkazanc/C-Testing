#include "StringLiterals.h"

namespace StringLiterals {
	void Main() {
		char t1[] = "test1\
		hello\
		world";


		const char t2[] = "test2"
			"Hey"
			"You";

		wchar_t t3[] = LR"xyz(test3
			Hello!
	Yes
				You":-)"
	)xyz";

		t1[0] = 'g';

		LOG(t1);
		LOG(sizeof(t1), "size of t1:");
		LINE;
		LOG(t2);
		LOG(sizeof(t2), "size of t2:");
		LINE;
		LOG(t3);
		LOG(sizeof(t3), "size of t3:");
		LINE;
		LOG(sizeof(int*), "size of int* ");

	}
}