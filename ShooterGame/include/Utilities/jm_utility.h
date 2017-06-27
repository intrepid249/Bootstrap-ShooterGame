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
}