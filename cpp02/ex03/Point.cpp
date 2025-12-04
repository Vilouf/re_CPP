#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( const float x, const float y ) : _x(x), _y(y) {}

Point::Point( const Point &other ) : _x(other._x), _y(other._y) {}

Point	&Point::operator=( const Point &other ) {

	static Point	ret(other);
	return ret;
}

Point::~Point( void ) {}

Fixed	Point::GetXvalue( void ) const { return _x; }

Fixed	Point::GetYvalue( void ) const { return _y; }