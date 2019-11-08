#pragma once
#include <string>

enum {CHAR_SET = 128}; //ascii

class Trie {

private:
	
	bool isLeaf;
	Trie* children[CHAR_SET];

	bool HasChildren() const;

public:

	Trie();

	void Insert(const std::string& str);
	bool Find(const std::string& str) const;
	bool Delete(const std::string& str);
	bool Empty() const;
};

namespace TrieTest {
	void Main();
}
