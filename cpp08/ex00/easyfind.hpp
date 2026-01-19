#pragma once

#include <iostream>

template <typename T>
bool	easyfind( T cnt, int find ) {

	typename T::iterator	i = std::find(cnt.begin(), cnt.end(), find);

	if (i == cnt.end())
		return false;
	return true;
}
