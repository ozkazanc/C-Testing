#include "SimpleClass.h"

namespace SimpleClass {
	void Main() {
		std::string newDog("Persephone");
		std::string oldDog("Satch");

		NamedObject p(newDog, 2);
		NamedObject s(oldDog, 36);
		NamedObject f = s;
		NamedObject c(p);
		NamedObject ac(p);


		s = p;
		p.print();
		s.print();
		c.print();
		ac.print();
		std::cout << "String size " << sizeof(oldDog) << std::endl;
		std::cout << "int size " << sizeof(int) << std::endl;
		std::cout << "Class " << sizeof(p) << std::endl;

		// Trying to get around the constness (does not work)
		//char* const pc = &p[0];
		//*pc = 'X';

		s.print();

		p = s;

		std::cout << "After the assignment operator" << std::endl;
		p.print();
		s.print();

	}
}