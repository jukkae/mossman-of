#include "wrapAround.hpp"

int wrapAround(int i, int max) {
	auto mod = i % max;
	return mod < 0 ? max + mod : mod;
}
