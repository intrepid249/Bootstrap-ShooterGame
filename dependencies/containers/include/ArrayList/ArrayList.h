#pragma once
#include <memory>
#include <assert.h>

template <class T>
class ArrayList {
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	ArrayList() : m_capacity(0), m_size(0) {}
	~ArrayList() {}

	/** Append an item to the end of the container*/
	void push_back(T item) {
		// If we have reached capacity, expand to fit new elements
		if (m_size == m_capacity)
			reserve();

		// Append a new item to the end of the list and update the size
		data[m_size++] = item;
	}

	/** Remove the last element of the list and remove it*/
	void pop_back() {
		data[m_size--] = T();
	}

	/** Insert an item at the specified index*/
	void insert_at(unsigned int _index, T item) {
		
		// If we have reached capacity, expand to fit new elements
		if (m_size == m_capacity)
			reserve();

		// Shift elements to make room for the new item
		T *temp(new T[m_capacity]);
		for (unsigned int i = _index; i < m_capacity - 1; ++i)
			temp[i + 1] = data[i];
		data[_index] = item;
		for (unsigned int i = _index + 1; i < m_capacity; ++i)
			data[i] = temp[i];
		delete[] temp;

		// Append a new item to the specified index and update the size
		data[_index] = item;
		m_size++;
	}

	/** Remove the item at the specified index*/
	void erase_at(unsigned int _index) {
		// Shift elements to remove the item at the index
		for (unsigned int i = _index + 1; i < m_capacity; ++i)
			data[i - 1] = data[i];

		// Update the size
		m_size--;
	}

	/** Reserve space for new items by increasing the capacity and allocating new memory*/
	void reserve(unsigned int _capacity = 10) {
		m_capacity += _capacity;
		T *newData(new T[m_capacity]);
		memcpy(newData, data, sizeof(T) * m_size);
		data = newData;
	}

	T& operator [](unsigned int _index) {
		return data[_index];
	}

	T& get(T* _iter) {
		return (*_iter);
	}

	unsigned int size() { return m_size; }

	iterator begin() { return &data[0]; }
	const_iterator begin() const { return &data[0]; }
	iterator end() { return &data[m_size]; }
	const_iterator end() const { return &data[m_size]; }

private:
	unsigned int m_capacity, m_size;
	T *data;
};

