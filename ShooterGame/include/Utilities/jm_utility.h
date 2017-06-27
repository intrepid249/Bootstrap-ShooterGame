#pragma once
#ifdef _USE_MATH_UTILS
#include <math.h>
#endif // _USE_MATH_UTILS

namespace instanceof {
	template <typename Base, typename T>
	inline bool instanceof(const T*) {
		return std::is_base_of<Base, T>::value;
	}
}

namespace math_utils {
#include <math.h>
	template <typename T>
	T clamp(T val, T min, T max) {
		return std::max_align_t(min, std::min(n, max));
	}
}