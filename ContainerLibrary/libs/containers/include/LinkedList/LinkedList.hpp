#pragma once
#include <memory>
#include <iostream>
#include <assert.h>


/* With assistance from Sebastian Toy*/
template <class T>
class LinkedList {

	struct ListNode {
		ListNode() = default;
		ListNode(T obj) : value(obj) {}
		~ListNode() = default;

		ListNode *next = nullptr, *prev = nullptr;
		T value;
	};

	struct Iterator {
		Iterator() = default;
		Iterator(ListNode* _node) : m_node(_node) {}

		Iterator& operator =(const Iterator& o) {
			(*this).m_node = o.m_node;
			return *this;
		}

		/** Prefix decrement*/
		Iterator& operator --() {
			m_node = m_node->prev;
			return *this;
		}
		/** Postfix decrement*/
		Iterator& operator --(int) {
			Iterator result(*this);
			++(*this);
			return *this;
		}

		/** Prefix increment*/
		Iterator& operator ++() {
			m_node = m_node->next;
			return *this;
		}
		/** Postfix increment*/
		Iterator& operator ++(int) {
			Iterator result(*this);
			++(*this);
			return *this;
		}

		/** Stepped increment*/
		Iterator& operator +(int amount) {
			for (int i = 0; i < amount; i++)
				m_node = m_node->next;
			return *this;
		}
		/** Stepped decrement*/
		Iterator& operator -(int amount) {
			for (int i = 0; i < amount; i++)
				m_node = m_node->prev;
			return *this;
		}

		// Check for sentinel node
		bool operator ==(Iterator _iter) {
			return m_node == _iter.m_node;
		}
		bool operator !=(Iterator _iter) {
			return m_node != _iter.m_node;
		}

		// Free memory
		void eraseNode() {
			delete m_node;
			m_node = nullptr;
		}
		
		/** Dereference*/
		T& operator *() {
			return m_node->value;
		}

		ListNode *m_node = nullptr;
	};

public:

	LinkedList() {
		m_size = 0;
		first = last = nullptr;
	}
	~LinkedList() {
		erase(begin(), end());
	}

	/** Overload default copy constructor to use deep copying to preserve memory*/
	LinkedList(LinkedList &o) {
		deep_copy(o);
	}
	/** Overload default copy assignment to use deep copying to preserve memory*/
	LinkedList& operator =(LinkedList &o) {
		deep_copy(o);
		return *this;
	}

	void deep_copy(LinkedList &o) {
		// Free up memory if list hasn't been initialised previously
		if (first)
			erase(begin(), end());

		// Create new list from old values
		for (auto val : o)
			push_back(val);
	}

	/** Append an item to the end of the container*/
	void push_back(const T& item) {
		// Increase the size of the container
		m_size++;

		// Construct the data object
		ListNode *obj = new ListNode(item);

		// Populate the first item in the list
		if (first == nullptr) first = last = obj;

		// Set the iterator pointers for non-empty list
		else  {
			last->next = obj;
			obj->prev = last;
			last = obj;
		}
	}
	/** Remove the back element of the container*/
	void pop_back() {
		assert(first != nullptr && "Null memory referenced - container empty");

		erase(last);
	}

	/** Append an item to the front of the container*/
	void push_front(const T& item) {
		// Increase the size of the container
		m_size++;

		// Construct the data object
		ListNode *obj = new ListNode(item);

		// Populate the first item in the list
		if (first == nullptr) first = last = obj;

		// Set the iterator pointers for non-empty list
		else (last != obj) {
			first->prev = obj;
			obj->next = first;
			first = obj;
		}
	}
	/** Remove the front element of the container*/
	void pop_front() {
		assert(first != nullptr && "Null memory referenced - container empty");

		erase(first);
	}

	/** Remove the item at the specified position in memory*/
	Iterator erase(Iterator _iter) {
		assert(_iter != nullptr && "Null memory referenced");

		// Decrease the size of the container
		m_size--;

		Iterator nextPos = _iter;
		++nextPos;
		// Remove links only if they exist
		ListNode *nextNode = _iter.m_node->next, *prevNode = _iter.m_node->prev;

		if (nextNode)
			nextNode->prev = prevNode;
		else // erasing last node
			last = prevNode;

		if (prevNode)
			prevNode->next = nextNode;
		else // erasing first node
			first = nextNode;

		// Clear allocated memory
		_iter.eraseNode();
		return nextPos;
	}
	/** Remove items in specified range*/
	Iterator erase(Iterator _min, Iterator _max) {
		Iterator current = _min;
		while (current != _max)
			current = erase(current);
		return current;
	}

	/** Insert an item ad the specified index*/
	void insert(const T& item, unsigned int index = size()) {
		assert(index >= 0 && "Index out of bounds ( cannot have negative index )");
		assert(index <= m_size && "Index out of bounds ( cannot exceed size of container )");

		ListNode *obj = new ListNode(item);
		if (first == nullptr) first = obj;
		if (last == nullptr) last = obj;

		ListNode *current = first;

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

		auto iter = Iterator(first);
		for (unsigned int i = 0; i < index; ++i) {
			iter++;
		}
		return *iter;
	}

	/** Return the address of the first element of the container*/
	Iterator begin() { return Iterator(first); }
	/** Return the address past the last element of the container*/
	Iterator end() { return Iterator(nullptr); }

	bool empty() { return m_size == 0; }
	unsigned int size() { return m_size; }

private:
	ListNode *first = nullptr, *last = nullptr;
	unsigned int m_size;
};

