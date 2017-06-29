#pragma once
#ifndef _USE_MATH_UTILS
#include <algorithm>
#endif // _USE_MATH_UTILS

namespace instanceof {
	template <typename Base, typename T>
	inline bool instanceof(const T*) {
		return std::is_base_of<Base, T>::value;
	}
}

namespace math_utils {
	template <typename T>
	T clamp(T _val, T _min, T _max) {
		return std::max(_min, std::min(_val, _max));
	}

	// TODO: Why does distanceOf give a LNK2005 "Already defined in AISeekState.obj" error
	static float distanceOf(Vector2<float> p1, Vector2<float> p2) {
		Vector2<float> dir = p2 - p1;
		return sqrt(dir.x * dir.x + dir.y * dir.y);
	}
}