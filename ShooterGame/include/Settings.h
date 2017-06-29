#pragma once

#pragma region Application Settings
#ifdef _DEBUG
	#define APPTITLE "Endless - (Debug)"
#else
	#define APPTITLE "Endless"
#endif // _DEBUG
#define SCREENWIDTH 1080
#define SCREENHEIGHT 720
#define FULLSCREEN false
#pragma endregion


#pragma region Game State Manager
enum class eGameStateID { SPLASH_STATE, GAME_STATE, PAUSE_STATE, MAIN_MENU_STATE, LOAD_GAME_DATA };
#pragma endregion


#pragma region Menu Settings
struct MPoint {
	int x, y;
};

struct MRECT {
	float x, y, width, height;

	bool intersects(const MRECT &a_other) {
		if (x  < a_other.x - a_other.width || x > a_other.x + a_other.width) return false;
		if (y < a_other.y - a_other.height || y > a_other.y + a_other.height) return false;

		return true;
	}

	bool contains(const MPoint &a_coord) {
		if (a_coord.x < x - width / 2 || a_coord.x > x + width / 2) return false;
		if (a_coord.y < y - height / 2 || a_coord.y > y + height / 2) return false;

		return true;
	}
};
#pragma endregion

namespace grid {
	struct GPoint {
		GPoint() = default;
		GPoint(int _x, int _y) : x(_x), y(_y) {}

		int x, y;

		bool operator == (GPoint &rhs) {
			return (x == rhs.x && y == rhs.y);
		}
		bool operator != (GPoint &rhs) {
			return !(*this == rhs);
		}
	};
}