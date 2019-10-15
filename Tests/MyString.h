#include <iostream>
#include <string>

// Writing my own basic string class to
// test move semantics and copy-and-swap idiom

namespace MyString{

	class MyString{
	public:
		MyString(const std::string& src = "")
			:str(nullptr), length(0) {

			unsigned int len = 0;
			while (src[len] != '\0')
				len++;

			length = len;

			str = new char[length + 1];
			memcpy(str, src.c_str(), length);
			str[length] = '\0';
			std::cout << "In default constructor: " << this << std::endl;
		}

		~MyString() {
			delete[] str;
			std::cout << "In destructor: " << this << std::endl;
		}

		MyString(const MyString& copy){
			length = copy.length;

			str = new char[copy.length + 1];
			memcpy(str, copy.str, length);
			str[length] = '\0';
			std::cout << "In copy constructor: " << this << std::endl;
		}

		MyString(MyString&& rvalue){
			length = rvalue.length;
			str = rvalue.str;
			rvalue.str = nullptr;
			std::cout << "In move constructor: from: " << &rvalue << " to: " << this << std::endl;
		}

		MyString& operator=(MyString rhs){
			std::swap(str, rhs.str);
			std::swap(length, rhs.length);
			std::cout << "In assignment operator: " << this << std::endl;

			return *this;
		}

		friend const MyString operator+(const MyString& lhs, const MyString& rhs){
			MyString n;
			n.length = lhs.length + rhs.length;

			n.str = new char[n.length + 1];
			memcpy(n.str, lhs.str, lhs.length);
			memcpy(&n.str[lhs.length], rhs.str, rhs.length + 1);
			return n;
		}

		friend std::ostream& operator<<(std::ostream& out, const MyString& str_){
			out << "In: " << &str_;
			if (str_.str == nullptr) out << "\tEmpty\n";
			else out << "\tData: " << str_.str << "\tlength: " << str_.length << '\n';
			return out;
		}

	private:
		char* str;
		unsigned int length;
	};


	void Main();

}
