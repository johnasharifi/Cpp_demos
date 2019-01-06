#pragma once

#include <string>

class Circle
{
private:
	double cx;
	double cy;
	double r;
public:
	Circle(double, double, double);
	~Circle();
	bool Contains(double, double);
	bool ContainsOrOverlaps(const Circle * c);
	explicit operator std::string();
};

