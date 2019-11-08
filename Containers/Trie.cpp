#include "Trie.h"
#include <iostream>

Trie::Trie()
	:isLeaf(false),
	children{nullptr}
{}

Trie::~Trie() {
	Destroy();
}

void Trie::Insert(const std::string& str) {
	if (str.length() == 0) {
		isLeaf = true;
		return;
	}

	if (children[str[0]] == nullptr) {
		children[str[0]] = new Trie();
	}
	children[str[0]]->Insert(str.substr(1));
}

bool Trie::Find(const std::string& str) const {
	const Trie* cur = this;
	for (int i = 0; i < str.length(); i++) {
		cur = cur->children[str[i]];

		if (cur == nullptr)
			return false;
	}
	return cur->isLeaf;
}

bool Trie::Delete(const std::string& str) {
	if (str.length() == 0) {
		if (HasChildren()) {
			isLeaf = false;
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		if (children[str[0]] &&
			children[str[0]]->Delete(str.substr(1)))
		{
			// Delete the child
			delete children[str[0]];
			children[str[0]] = nullptr;

			if (HasChildren() || isLeaf) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else return 0;
	}
}

bool Trie::HasChildren() const {
	for (int i = 0; i < CHAR_SET; i++) {
		if (children[i] != nullptr)
			return true;
	}
	return false;
}

bool Trie::Empty() const {
	return HasChildren();
}

namespace TrieTest {
	void Main() {
		Trie trie;
		trie.Insert("hello");
		std::cout << trie.Find("hello") << " ";

		trie.Insert("helloworld");
		std::cout << trie.Find("helloworld") << " ";

		std::cout << trie.Find("hell") << " ";

		trie.Insert("hell");
		std::cout << trie.Find("hell") << " ";

		trie.Insert("h");
		std::cout << trie.Find("h") << " ";
		std::cout << std::endl;

		trie.Delete("hello");
		std::cout << trie.Find("hello") << " ";
		std::cout << trie.Find("helloworld") << " ";
		std::cout << trie.Find("hell") << " ";
		std::cout << std::endl;

		trie.Delete("h");
		std::cout << trie.Find("h") << " ";
		std::cout << trie.Find("helloworld") << " ";
		std::cout << trie.Find("hell") << " ";
		std::cout << std::endl;

		trie.Delete("helloworld");
		std::cout << trie.Find("helloworld") << " ";
		std::cout << trie.Find("hell") << " ";
		std::cout << std::endl;

		trie.Delete("hell");
		std::cout << trie.Find("hell") << " ";
		std::cout << std::endl;

		std::cout << trie.Empty() << " ";
		std::cout << trie.Find("h") << " ";
	}
}

void Trie::Destroy() {
	for (int i = 0; i < CHAR_SET; i++) {
		if (children[i]) {
			children[i]->Destroy();
			delete children[i];
			children[i] = nullptr;
		}
	}
}