#pragma once

#include <stdexcept>

namespace wasp::math {

	void throwIfZero(int i, const std::string& message = "int is zero!") {
		if (i == 0) {
			throw std::runtime_error{ message };
		}
	}
	void throwIfZero(float f, const std::string& message = "float is zero!") {
		if (f == 0.0f) {
			throw std::runtime_error{ message };
		}
	}
}