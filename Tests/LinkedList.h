#pragma once

#include <iostream>
#include <memory>

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

	~LinkedList() 
	{
		Node* cur = head;
		while (cur != nullptr) {
			Node* temp = cur;
			cur = cur->next;
			delete temp;
		}
	}

	LinkedList(const LinkedList<T>& copy) 
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

	LinkedList<T>& operator=(LinkedList<T> rhs) 
	{
		swap(*this, rhs);
		return *this;
	}

	// Add initializer_list constructor

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