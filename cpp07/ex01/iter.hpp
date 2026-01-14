#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T *array, const size_t len, F f) {

	if (array) {

		for (size_t i = 0; i < len; i++)
			f(array[i]);
	}
}
