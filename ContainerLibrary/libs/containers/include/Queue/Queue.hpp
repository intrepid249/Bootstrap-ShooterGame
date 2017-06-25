#pragma once
#include <LinkedList\LinkedList.hpp>
#include <memory>
#include <functional>

template <class T>
class Queue {
public:
	Queue() {}
	Queue(Queue const &) = delete;
	Queue &operator =(Queue const &) = delete;
	Queue(Queue &&o) : m_data(std::move(o.m_data)) {}
	Queue &operator =(Queue &&o) {
		if (this != &o)
			m_data = std::move(o.m_data);
		return *this;
	}
	~Queue() {}

	void push(const T& _item) {
		// Insert an item to the front of the queue
		m_data.insert(_item, 0);
	}
	void pop() {
		assert((size() > 0 && m_data.size() > 0) && "Cannot pop from empty container");
		//m_data.erase(end() - 1);
	}

	/** Return the element at the front of the queue*/
	T front() {
		return m_data[0];
	}
	/** Return the element at the back of the queue*/
	T back() {
		return m_data[size() - 1];
	}

	bool empty() { return m_data.empty(); }
	int size() { return m_data.size(); }

private:
	LinkedList<T> m_data;
};