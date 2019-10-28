#pragma once

/*
	Helper Functions for printing out values from commonly used data structures.
*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

///////////////////////////////////////////////////////////////////
// Declarations ///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& l);

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);

template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<T, S>& map);

////////////////////////////////////////////////////////////////////
// Definitions-Implementations /////////////////////////////////////
////////////////////////////////////////////////////////////////////

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << ", ";
	}
	os << "]\n";
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& l)
{
	os << "[";
	int count = 0;
	for (auto it = l.begin(); it != l.end(); it++, count++) {
		os << *it;
		if (count != l.size() - 1)
			os << ", ";
	}
	os << "]\n";
	return os;
}

template <typename T, typename S>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<T, S>& map) {
	for (const auto& elem : map) {
		os << elem.first << " : "
			<< elem.second << '\n';
	}
	return os;
}