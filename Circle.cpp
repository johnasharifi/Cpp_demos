#pragma once

#include <string>

#include "stdafx.h"
#include <cmath>
#include "Circle.h"

Circle::Circle(double _x, double _y, double _r)
{
	cx = _x;
	cy = _y;
	r = _r;
}

Circle::~Circle()
{
}

bool Circle::Contains(double _x, double _y) {
	double dist_sqr = pow(_x - cx, 2) + pow(_y - cy, 2);
	double r_sqr = pow(r, 2);
	return(dist_sqr <= r_sqr);
}

bool Circle::ContainsOrOverlaps(const Circle* c) {
	double dist_sqr = pow(cx - c->cx, 2) + pow(cy - c->cy, 2);
	double r_sum_sqr = pow(r + c->r, 2);
	return(dist_sqr <= r_sum_sqr);
}

Circle::operator std::string()
{
	return("(" + std::to_string(cx) + "," + std::to_string(cy) + "), radius " + std::to_string(r));
}
