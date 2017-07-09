#pragma once
#include <map>

enum eBlackboardDataType {
	type_float,
	type_int,
	type_char,
	type_bool,
	type_pointer
};

struct BlackboardData {
	eBlackboardDataType type;

	union {
		float floatVal;
		int intVal;
		char charVal;
		bool boolVal;
		void* pointerVal;
	};
};

class Blackboard {
public:
	enum eBlackboardID {};

	BlackboardData getEntry(eBlackboardID _id);

	std::map<eBlackboardID, BlackboardData> m_entries;
};