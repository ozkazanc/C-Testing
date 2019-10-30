#include <iostream>
#include <string>

// Writing my own basic string class to
// test move semantics and copy-and-swap idiom

namespace MyString{

	class MyString{
	public:
		MyString(const std::string& src = "")
			:str(nullptr), length(0) 
		{
			std::cout << "In default constructor: " << this << std::endl;

			length = (unsigned int)src.length();
			str = new char[length + 1];

			memcpy(str, src.c_str(), length);
			str[length] = '\0';
		}

		~MyString() 
		{
			std::cout << "In destructor: " << this << std::endl;
			delete[] str;
		}

		MyString(const MyString& copy)
		{
			std::cout << "In copy constructor: " << this << std::endl;
			
			length = copy.length;
			str = new char[copy.length + 1];

			memcpy(str, copy.str, length);
			str[length] = '\0';
		}

		MyString(MyString&& rvalue) noexcept
			:MyString()
		{
			std::cout << "In move constructor: from: " << &rvalue << " to: " << this << std::endl;
			swap(*this, rvalue);
		}

		MyString& operator=(MyString rhs)
		{
			std::cout << "In assignment operator: " << this << std::endl;
			swap(*this, rhs);

			return *this;
		}

		friend void swap(MyString& a, MyString& b) noexcept
		{
			std::cout << "Swapping: " << &a << " and " << &b << std::endl;
			
			using std::swap;
			swap(a.str, b.str);
			swap(a.length, b.length);
		}

		friend const MyString operator+(const MyString& lhs, const MyString& rhs)
		{
			return MyString(std::string(lhs.str) + std::string(rhs.str));
		}

		friend std::ostream& operator<<(std::ostream& out, const MyString& str_)
		{
			out << "In: " << &str_;
			out << "\tData: " << str_.str << "\tlength: " << str_.length << '\n';
			return out;
		}

	private:
		char* str;
		unsigned int length;
	};

	void Main();

}
