#pragma once
#include <memory>

template <class T>
class ListNode {
public:
	ListNode() = default;
	ListNode(T obj) {
		next = prev = nullptr;
		value = obj;
	}
	~ListNode() = default;

	operator T() { return value; }

	ListNode *next, *prev;
	T value;
};

