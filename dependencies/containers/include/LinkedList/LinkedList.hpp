#pragma once
#include <memory>
#include <iostream>
#include <assert.h>


/* With assistance from Jack Hunt*/
template <class T>
class LinkedList {

	template <class T>
	class ListNode {
	public:
		ListNode() = default;
		ListNode(T obj) {
			value = obj;
		}
		~ListNode() = default;

		// Overload the typecast operator so that the ListNode can act as the object itself
		operator T() { return value; }

		ListNode *next, *prev;
		T value;
	};

public:
	typedef ListNode<T>* iterator;
	typedef const ListNode<T>* const_iterator;

	LinkedList() {
		m_size = 0;
		first = last = nullptr;
	}
	~LinkedList() {
	}

	/** Append an item to the end of the container*/
	void push_back(const T& item) {
		// Increase the size of the container
		m_size++;

		// Construct the data object
		ListNode<T> *obj = new ListNode<T>(item);
		//obj->value = item;

		if (first == nullptr) first = obj;
		if (last == nullptr) last = obj;

		// Set the iterator pointers
		if (last != obj) {
			last->next = obj;
			obj->prev = last;

			last = obj;
		}
	}
	/** Remove the last element of the container*/
	void pop_back() {
		// Reset the iterator pointers
		if (last != first) last->prev->next = nullptr;
		if (last == first) first = nullptr;
		// Remove the element
		last = last->prev;
		delete last->next;
		m_size--;
	}

	/** Remove the item at the specified index*/
	void erase(unsigned int index) {
		assert(index >= 0 && "Index out of bounds ( cannot have negative index )");
		assert(index <= m_size && "Index out of bounds ( cannot exceed size of container )");

		if (index >= m_size || index < 0) return;

		// Decrease the size of the container
		m_size--;

		ListNode<T> *current = first;
		// Iterate through the list to get the item to remove
		for (unsigned int i = 0; i < index; ++i) {
			if (current->next == nullptr) return;
			current = current->next;
		}

		// If the item is in the middle of the list
		if (current->prev != nullptr && current->next != nullptr) {
			current->next->prev = current->prev;
			current->prev->next = current->next;
			delete current;
			return;
		}

		// If the item is at the beginning of the list
		if (current->prev == nullptr && current->next != nullptr) {
			current->next->prev = nullptr;
			delete current;
			return;
		}

		// If the item is at the end of the list
		if (current->prev != nullptr && current->next == nullptr) {
			current->prev->next = nullptr;
			delete current;
			return;
		}
	}
	/** Insert an item ad the specified index*/
	void insert(const T& item, unsigned int index = size()) {
		assert(index >= 0 && "Index out of bounds ( cannot have negative index )");
		assert(index <= m_size && "Index out of bounds ( cannot exceed size of container )");

		ListNode<T> *obj = new ListNode<T>(item);
		if (first == nullptr) first = obj;
		if (last == nullptr) last = obj;

		ListNode<T> *current = first;

		// Iterate through the list to get the item to shift
		for (unsigned int i = 0; i < (index); i++) {
			if (current->next == nullptr) return;
			current = current->next;
		}

		// Reset the first or last pointers if inserting at beginning or end of the list
		if (current->prev != nullptr)
			current->prev->next = obj;
		else
			first = obj;
		if (current->next == nullptr)
			last = obj;
		// Shift to make space for the new item
		obj->prev = current->prev;
		obj->next = current;
		current->prev = obj;

		// Increase the size of the container
		m_size++;
	}

	T operator [](unsigned int index) {
		assert(index >= 0 && "Index out of bounds ( cannot have negative index )");
		assert(index <= m_size && "Index out of bounds ( cannot exceed size of container )");

		ListNode<T> *current = first;
		for (unsigned int i = 0; i < index; ++i) {
			current = current->next;
		}
		return current->value;
	}

	/// ITERATOR FUNCTIONS
	iterator next() {
		current = current->next;

		return current;
	}
	iterator prev() {
		if (current == nullptr) return nullptr;

		if (current->prev == nullptr) return nullptr;
		current = current->prev;

		return current;
	}

	/** Return the address of the first element of the container*/
	ListNode<T>* begin() { current = first; return first; }
	/** Return the address past the last element of the container*/
	ListNode<T>* end() { return last->next; }

	bool empty() { return m_size == 0; }
	unsigned int size() { return m_size; }

private:
	ListNode<T> *first, *last, *current;
	T value;
	unsigned int m_size;
};

