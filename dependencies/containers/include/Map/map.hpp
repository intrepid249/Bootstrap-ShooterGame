#pragma once
#include <ArrayList\ArrayList.hpp>
#include "Pair.hpp"

template <class Key, class Val>
class Map {
public:
	class Pair {
	public:
		Pair() = default;
		Pair(const Key& _key) : first(_key), second() {}

		Pair(const Key& _key, const Val& _val) : first(_key), second(_val) {}

		~Pair() {}

		explicit operator Val() { return second; }

		Key first;
		Val second;
	};

	typedef Pair* iterator;
	typedef const Pair* const_iterator;

	Map() {}
	~Map() {}

	Val& operator [] (const Key &_key){
		Pair *iter = find(_key);
		if (iter != end())
			return (*iter).second;
		
		return insertDefault(_key).second;
	}

	void clear() {
		m_elements.clear();
	}

	bool empty() { return m_elements.empty(); }
	unsigned int size() { return m_elements.size(); }

	// TODO: Binary search algorithm?
	iterator find(const Key &_key) {
		for (iterator iter = m_elements.begin(); iter != m_elements.end(); iter++) {
			if ((*iter).first == _key)
				return iter;
		}
		return end();
	}
	const_iterator find() const {
		for (iterator iter = m_elements.begin(); iter != m_elements.end(); iter++) {
			if ((*iter).first == _key)
				return iter;
		}
		return end();
	}

	iterator begin() { return &m_elements[0]; }
	const_iterator begin() const { return &m_elements[0]; }
	iterator end() { return &m_elements[size()]; }
	const_iterator end() const { return &m_elements[size()]; }

protected:
	Pair& insertDefault(const Key &_key) {
		m_elements.push_back(Pair(_key));
		return m_elements.back();
	}
public:
	ArrayList<Pair> m_elements;
};