#include <iostream>
#include <string>

// Wrote a simple struct containing a union to see how
// variable of different sizes are stored, and how unions work
namespace UnionTypePunning{

	enum Type { INT_, CHAR_ };
	struct storage{
		union Value{
			int i;
			char c;
		} v;
		Type type;
	};

	void Main();
}