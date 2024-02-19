#include "resources.h"

Interval::Interval() { pocz = 0, kon = 0; }
Interval::Interval(double x) { pocz = x - epsilon, kon = x + epsilon; }
Interval::Interval(double p, double k) { pocz = p, kon = k; }

Interval Interval::operator+(const Interval& i) const {
	return Interval(pocz + i.pocz, kon + i.kon);
}

Interval Interval::operator-(const Interval& i) const {
	return Interval(pocz - i.kon, kon - i.pocz);
}

Interval Interval::operator*(const Interval& i) const {
	double a = pocz * i.pocz;
	double b = pocz * i.kon;
	double c = kon * i.pocz;
	double d = kon * i.kon;

	return Interval(std::min(std::min(a, b), std::min(c, d)),
		std::max(std::max(a, b), std::max(c, d)));
}

Interval Interval::operator/(const Interval& i) const {
	if (i.pocz <= 0.0 && i.kon >= 0.0) {
		std::cerr << "Przedzial zawiera zero" << std::endl;
		exit(EXIT_FAILURE);
	}
	double a = pocz / i.pocz;
	double b = pocz / i.kon;
	double c = kon / i.pocz;
	double d = kon / i.kon;

	return Interval(std::min(std::min(a, b), std::min(c, d)),
		std::max(std::max(a, b), std::max(c, d)));
	return Interval();
}

Interval Interval::funkcja(const Interval& x) {
	return Interval(9, 9) * x * x - Interval(10, 10) * x - Interval(9, 9);
}

Interval Interval::pochodna(const Interval& x) {
	return Interval(18,18) * x - Interval(10,10);
}

Interval Interval::pochodna2(const Interval& x) {
	return Interval(18, 18);
}

Interval Interval::sieczne(double a, double b) {
	Interval a(a);
	Interval b(b);


}

void Interval::wypisz() {
	std::cout << "[" << pocz << "," << kon << "]" << std::endl;
}