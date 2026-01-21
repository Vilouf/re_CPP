#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template <typename T>
bool	easyfind( T cnt, int find ) {

	typename T::iterator	i = std::find(cnt.begin(), cnt.end(), find);

	if (i == cnt.end())
		return false;
	return true;
}
