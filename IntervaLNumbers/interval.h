#pragma once
#include "resources.h"

class Interval {
private:
	double pocz, kon;
public:
	Interval();
	Interval(double);
	Interval(double,double);
	Interval operator+(const Interval& obj) const;
	Interval operator-(const Interval& obj) const;
	Interval operator*(const Interval& obj) const;
	Interval operator/(const Interval& obj) const;
	Interval funkcja(const Interval& obj);
	Interval pochodna(const Interval& obj);
	Interval pochodna2(const Interval& obj);
	Interval sieczne(double a, double b);
	Interval newton();
	Interval bisekcja();
	void wypisz();
};