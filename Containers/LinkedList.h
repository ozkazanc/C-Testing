#pragma once

#include <iostream>

template<typename T>
class LinkedList {

private:

	struct Node {
		T data;
		Node* next;
		Node* prev;

		Node(T data_)
			:data(data_), next(nullptr), prev(nullptr) 
		{}
	};

	Node* head;
	Node* last;
	int size;

public:
	LinkedList()
		:head(nullptr), last(nullptr), size(0)
	{}


	LinkedList(const LinkedList<T>& copy)
		:LinkedList()
	{
		Node* cur = copy.head;
		while (cur != nullptr) {
			PushBack(cur->data);
			cur = cur->next;
		}
	}

	LinkedList(LinkedList<T>&& rhs) 
		:LinkedList()
	{
		swap(*this, rhs);
	}

	LinkedList(std::initializer_list<T> list) 
		:LinkedList()
	{
		for(const auto& elem : list){
			PushBack(elem);
		}
	}

	~LinkedList() 
	{
		Node* cur = head;
		while (cur != nullptr) {
			Node* temp = cur;
			cur = cur->next;
			delete temp;
		}
	}

	LinkedList<T>& operator=(LinkedList<T> rhs) 
	{
		swap(*this, rhs);
		return *this;
	}

	void PushFront(T value)
	{
		Node* pNew = new Node(value);		
		pNew->next = head;

		if (head != nullptr)
			head->prev = pNew;
		else
			last = pNew;

		head = pNew;
		size++;
	}

	void PushBack(T value)
	{
		Node* pNew = new Node(value);
		pNew->prev = last;

		if (last != nullptr)
			last->next = pNew;
		else
			head = pNew;

		last = pNew;
		size++;
	}

	void Delete(int index) 
	{
		Node* cur = head;
		while (cur != nullptr) {
			if (index == 0) {

				// Deleting the first node
				if (cur->prev == nullptr) {
					head = cur->next;
				}
				else {
					cur->prev->next = cur->next;
				}

				// Deleting the last node
				if (cur->next == nullptr) {
					last = cur->prev;
				}
				else {
					cur->next->prev = cur->prev;
				}
				
				delete cur;
				break;
			}
			index--;
			cur = cur->next;
		}
		size--;
	}

	T& operator[](int index) const
	{
		Node* cur = head;
		while (cur != nullptr) {
			if (index == 0) {
				return cur->data;
			}
			index--;
			cur = cur->next;
		}
		return last->data;
	}

	inline int Size() const { return size; }
	inline bool Empty() const { return size == 0; }
	inline T& Front() const { return head->data; }
	inline T& Back() const { return last->data; }

	friend void swap(LinkedList& lhs, LinkedList& rhs) {
		using std::swap;
		swap(lhs.head, rhs.head);
		swap(lhs.last, rhs.last);
		swap(lhs.size, rhs.size);
	}

	friend std::ostream& operator<< (std::ostream& out, const LinkedList& list) {
		out << "The list is: [ ";
		Node* cur = list.head;
		while (cur != nullptr) {
			out << cur->data << " ";
			cur = cur->next;
		}
		out << "]";
		return out;
	}
};
namespace LinkedListTest{
	void Main() {

		std::cout << "Default costruction" << '\n';
		LinkedList<int> list;
		std::cout << "Push front 3 into empty list" << '\n';
		list.PushFront(3);
		std::cout << "Size is " << list.Size() << '\n';
		std::cout << "Front is " << list.Front() << '\n';
		std::cout << "Back is " << list.Back() << '\n';
		std::cout << list << std::endl;

		std::cout << '\n';

		std::cout << "Delete head" << '\n';
		list.Delete(0);
		std::cout << "Size is " << list.Size() << '\n';;
		std::cout << list << std::endl;
		
		std::cout << '\n';

		std::cout << "Push back 4 into empty list" << '\n';
		list.PushBack(4);
		std::cout << "Size is " << list.Size() << '\n';
		std::cout << "Front is " << list.Front() << '\n';
		std::cout << "Back is " << list.Back() << '\n';
		std::cout << list << std::endl;

		std::cout << '\n';

		std::cout << "Push front 5 into non-empty list" << '\n';
		std::cout << "Push front 3 into non-empty list" << '\n';
		list.PushFront(5);
		list.PushBack(3);
		std::cout << "Size is " << list.Size() << '\n';
		std::cout << "Front is " << list.Front() << '\n';
		std::cout << "Back is " << list.Back() << '\n';
		std::cout << list << std::endl; '\n';

		std::cout << '\n';

		std::cout << "Copy costruction" << '\n';
		LinkedList<int> list2(list);
		std::cout << "Size is " << list2.Size() << '\n';
		std::cout << "Front is " << list2.Front() << '\n';
		std::cout << "Back is " << list2.Back() << '\n';
		std::cout << list2 << std::endl;

		std::cout << '\n';

		list.Delete(2);
		std::cout << "Size is " << list.Size() << '\n';
		std::cout << "Front is " << list.Front() << '\n';
		std::cout << "Back is " << list.Back() << '\n';
		std::cout << list << std::endl;

		std::cout << '\n';

		std::cout << "Initializer_list construction" << '\n';
		LinkedList<std::string> list3{ "hello", "world", "son", "what", "up" };
		std::cout << "Size is "		<< list3.Size()		<< '\n';
		std::cout << "Front is "	<< list3.Front()	<< '\n';
		std::cout << "Back is "		<< list3.Back()		<< '\n';
		std::cout << list3 << std::endl;
	}
}