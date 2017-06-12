#pragma once
#include <memory>

template <class T>
class Stack {
public:
	Stack(unsigned int _capacity = 50) : m_capacity(_capacity), m_size(0) {
		// Allocate and initialise new memory
		reserve(_capacity);
		memset(data, 0, _capacity);
	}
	~Stack() {
		delete[] data;
	}

	/** Reserve space for new items by increasing the capacity and allocating new memory*/
	void reserve(unsigned int _capacity = 10) {
		m_capacity += _capacity;
		T *newData = new T[m_capacity];
		memcpy(newData, data, sizeof(T) * m_size);
		data = newData;
	}

	void push(const T& item) {
		// If we have reached capacity, expand to fit new elements
		if (m_size == m_capacity)
			reserve();

		// Append a new item to the end of the stack and update the size
		data[m_size++] = item;
	}

	/** Remove the last element of the stack*/
	void pop() {
		data[--m_size] = T();
	}

	/** Return the last element of the stack*/
	T& top() { return data[m_size - 1]; }

	bool empty() { return m_size == 0; }
	unsigned int size() { return m_size; }

private:
	T* data;
	unsigned int m_size, m_capacity;
};