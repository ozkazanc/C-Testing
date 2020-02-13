#include "UnicodeTest.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
namespace UnicodeTesting
{
	void Main() {

		// In order to print unicode literals to the console we also need to change the encoding of console to utf-8 or utf-16.
		char c = '™';			//0x99		1001'1001	153 in ASCII is Ö
		wchar_t wc = L'™';		//0x2122	0010'0001'0010'0010
		char e =  'é';			//0xe9		
		wchar_t we = L'é';		//0x00e9

		std::cout << "Size of char: " << sizeof(c) << std::endl;
		std::cout << "c: "<< c << std::endl;

		std::cout << "Size of wchar_t: " << sizeof(wc) << std::endl;
		std::cout << "wc: "<< wc << std::endl;

		std::cout << "e: " << e << std::endl;
		std::cout << "we: " << we << std::endl;

		auto c0 = 'A';			// char
		auto c1 = u8'A';		// char 
		auto c2 = L'A';			// wchar_t
		auto c3 = u'A';			// char16_t
		auto c4 = U'A';			// char32_t
		auto c5 = '\u0041';			// char
		auto c6 = '\u00e6';			// char16_t
		auto c7 = '\U000000e6';			// char32_t

		std::cout << "hello\u00e6" << std::endl;
		std::cout << "UTF-8 : " << c5 << std::endl;
		
		std::cout << "UTF-16: " << c6 << std::endl;
		std::cout << "UTF-32: " << c7 << std::endl;

		// Multicharacter literals
		auto m0 = 'abcd';		// int, value 0x61626364

		// String literals
		auto s0 = "hello";		// const char*
		auto s1 = u8"hell\u0041o";	// const char*, encoded as UTF-8
		auto s2 = L"hello";		// const wchar_t*
		auto s3 = u"hello";		// const char16_t*, encoded as UTF-16
		auto s4 = U"hello";		// const char32_t*, encoded as UTF-32

		std::cout << "UTF-8 : " << s1 << std::endl;
		

	}



	//void Main() {
	//	// After doing this, we have to call std::wcout and not std::cout
	//	_setmode(_fileno(stdout), _O_U16TEXT);
	//	std::wcout << L"Hello, \u0444!\n";
	//}
}