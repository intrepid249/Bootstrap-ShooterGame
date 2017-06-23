/////////////////////////////////////////////////////////////////////////////////
////		Created By:		Jack McCall and Sebastian Toy
////		Date Created:	31-03-2017
////		Description:	Provides 3 templated functions that
////						can be utilised to load a variety of
////						resource types as either type of smart pointer
////						or a raw pointer.



#pragma once
#include <stdarg.h>
#include "ErrorManager.hpp"
#include <fstream>
#include <ios>
#include <memory>
#include <assert.h>
#include <Map\map.hpp>

template <class T>
class ResourceManager {
public:
	template <typename...Args>
	struct Resource {
		Resource(const char *filename, Args...args) : data(std::unique_ptr<T>(new T(filename, args...))) {}
		~Resource() {}

		std::unique_ptr<T> data;
	};

	// Make a default constructor to allow an instance of the Resource Manager to be created
	ResourceManager() = default;
	~ResourceManager() = default;

	template <typename...Args>
	std::shared_ptr<T> load(int key, const char *filename, Args...args) {
		// Try to open the file to see if it exists
		std::fstream test(filename, std::ios::in);
		assert(test);

		m_resources[key] = new Resource<T>(filename, args...);
		return m_resources[key].data;
	}

	template <typename...Args>
	std::shared_ptr<T> find(int key) {

	}

private:
	Map<int, Resource<T>> m_resources;
};