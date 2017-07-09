#include <iostream>

struct BlackboardDataType {
	union {
		float f;
		char* c;
		int i;
		long l;
		short s;
	};
};

#include <map>

class Blackboard {
public:
	enum class BlackboardMessage { INFO };

	static Blackboard* getInstance() {
		static Blackboard* inst = new Blackboard();
		return inst;
	}

	~Blackboard() = default;

	void postMessage(BlackboardMessage msgType, BlackboardDataType) {}

private:
	Blackboard();

	std::map<BlackboardMessage, BlackboardDataType> m_messageBoard;
};


auto main(int argc, char **argv) -> int {

}