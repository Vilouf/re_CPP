#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

private:

	Fixed const	_x;
	Fixed const	_y;

public:

	Point();
	Point( const float x, const float y );
	Point( const Point & );
	Point	&operator=( const Point & );
	~Point();

	Fixed	GetXvalue() const;
	Fixed	GetYvalue() const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif