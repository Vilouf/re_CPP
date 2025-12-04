#include "Point.hpp"

float sign(Point p1, Point p2, Point p3)
{
    return	(p1.GetXvalue() - p3.GetXvalue()) * 
			(p2.GetYvalue() - p3.GetYvalue()) - 
			(p2.GetXvalue() - p3.GetXvalue()) * 
			(p1.GetYvalue() - p3.GetYvalue());
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {

	float d1, d2, d3;
    bool has_neg, has_pos;
	Fixed	test(0);

	test++;
    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    has_neg = (d1 < test.toFloat()) || (d2 < test.toFloat()) || (d3 < test.toFloat());
    has_pos = (d1 > -test.toFloat()) || (d2 > -test.toFloat()) || (d3 > -test.toFloat());

    return !(has_neg && has_pos);
}