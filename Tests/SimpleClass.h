#include <iostream>
#include <string>

// Wrote a basic class and overwrote the compiler generated ctors and dtors
// to observe how they work and when they are called
namespace SimpleClass{

	class NamedObject{
	public:
		~NamedObject(){ std::cout << "In destructor" << std::endl; }

		NamedObject(const std::string& name, const int& value)
			:nameValue(name), objectValue(value) {
			std::cout << "In default constructor" << std::endl;
		}

		/*NamedObject(const NamedObject<T> &rhs){
		this->nameValue = rhs.nameValue;
		this->objectValue = rhs.objectValue;
		std::cout << "In copy constructor" << std::endl;
		}*/

		NamedObject(const NamedObject &rhs)
			:nameValue(rhs.nameValue), objectValue(rhs.objectValue) {
			std::cout << "In copy constructor" << std::endl;
		}
		NamedObject& operator=(const NamedObject &rhs){
			this->nameValue = rhs.nameValue;
			this->objectValue = rhs.objectValue;
			std::cout << "In assignment operator" << std::endl;
			return *this;
		}

		const char& operator[](const std::size_t position) const{
			return this->nameValue[position];
		}

		void print() const{
			std::cout << "Object is " << this << std::endl;
			std::cout << "Name is " << this->nameValue << std::endl;
			std::cout << "Value is " << this->objectValue << std::endl;
			std::cout << std::endl;
		}
	private:
		std::string nameValue;
		int objectValue;
	};

	void Main();
}