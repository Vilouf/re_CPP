#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

template <typename T>
class Array {

private:

	T	*_array;
	unsigned int	_size;

public:

	Array() : _array(NULL),  _size(0) {}
	Array( unsigned int n ) : _array(new T[n]), _size(n) {}
	Array( const Array &other ) : _array(new T[other._size]), _size(other._size) {
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	Array	&operator=( const Array &other ) {
		if (this != &other) {
			if (_array)
				delete[] _array;
			_size = other._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = other._array[i];
			}
		}
		return *this;
	}
	~Array() {
		if (_array)
			delete[] _array;
	}

	class InvalidIndexException : public std::exception {
	public:
		virtual const char* what() const throw() { return "Invalid index"; }
	};

	T	&operator[]( int idx ) const {
		if (idx >= 0 && idx < static_cast<int>(_size))
			return _array[idx];
		else
			throw InvalidIndexException();
	}

	unsigned int	size( void ) const { return _size; }
};
