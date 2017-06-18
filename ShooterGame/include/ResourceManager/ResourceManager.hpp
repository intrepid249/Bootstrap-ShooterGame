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
	ResourceManager() {}
	~ResourceManager() {}

	template <typename...Args>
	std::shared_ptr<T> load(int key, const char *filename, Args...args) {
		// Try to open the file to see if it exists
		std::fstream test(filename, std::ios::in);
		assert(test);

		m_resources[key] = 
	}

private:
	Map<int, Resource> m_resources;
};

///*
//Function returns an std::unique_ptr specified by the type T when calling the function
//e.g. loadUniqueResource<type>(parameters);
//*/
//template <typename T, typename... Args>
//static std::unique_ptr<T> loadUniqueResource(const char *fileName, Args...args) {
//	// Try to open the file to see if it exists
//	std::fstream test(fileName, std::ios::in);
//	if (!test) {
//		// If the file doesn't exist then output to the console/error file and crash the program
//		char errMsg[256];
//		sprintf_s(errMsg, "Could not find file: %s", fileName);
//		ErrorManager::PrintSystemFail(errMsg); // handles error output and forces a crash
//	}

//	return std::unique_ptr<T>(new T(fileName, args...));
//}



///*
//Function returns an std::shared_ptr specified by the type T when calling the function
//e.g. loadUniqueResource<type>(parameters);
//*/
//template <typename T, typename... Args>
//static std::shared_ptr<T> loadSharedResource(const char *fileName, Args...args) {
//	// Try to open the file to see if it exists
//	std::fstream test(fileName, std::ios::in);
//	if (!test) {
//		// If the file doesn't exist then output to the console/error file and crash the program
//		char errMsg[256];
//		sprintf_s(errMsg, "Could not find file: %s", fileName);
//		ErrorManager::PrintSystemFail(errMsg); // handles error output and forces a crash
//	}

//	return std::make_shared<T>(fileName, args...);
//}



///*
//Function returns a standard raw pointer of type T
//Memory will have to be cleaned up manually
//*/
//template <typename T, typename... Args>
//static T* loadRawResource(const char *fileName, Args...args) {
//	// Try to open the file to see if it exists
//	std::fstream test(fileName, std::ios::in);
//	if (!test) {
//		// If the file doesn't exist then output to the console/error file and crash the program
//		char errMsg[256];
//		sprintf_s(errMsg, "Could not find file: %s", fileName);
//		ErrorManager::PrintSystemFail(errMsg); // handles error output and forces a crash
//	}

//	return new T(fileName, args...);
//}