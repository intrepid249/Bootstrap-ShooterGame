#pragma once

template <class T>
class StackNode {
public:
	StackNode() = default;
	StackNode(T _data) {
		data = _data;
		next = last = nullptr;
	}
	~StackNode() = default;

	T* next, prev;
	T data;
};

template <class T>
class Stack {
public:
	Stack() {}

	void push() {}

	void pop() {}

	StackNode<T>* prev() {}

	StackNode<T>* end() {}

	unsigned int size();

private:
	StackNode<T>* top, current;
	unsigned int m_size;
};