#include "Vec2.h"
#include "MathUtil.h"
#include <cmath>

Vec2::Vec2() : x(0.0), y(0.0) {
}

Vec2::Vec2(double iX, double iY) : x(iX), y(iY) {
}

Vec2::Vec2(const Vec2& copy) {
	set(copy);
}

Vec2::~Vec2() {
}

bool Vec2::isZero() const {
	return x == 0.0f && y == 0.0f;
}

void Vec2::add(const Vec2& v) {
	x += v.x;
	y += v.y;
}

void Vec2::subtract(const Vec2& v) {
	x -= v.x;
	y -= v.y;
}

void Vec2::negate() {
	x = -x;
	y = -y;
}


void Vec2::set(double iX, double iY) {
	this->x = iX;
	this->y = iY;
}

void Vec2::set(const Vec2& v) {
	this->x = v.x;
	this->y = v.y;
}

void Vec2::rotate(const Vec2& center, double angle) {
	//			   | cosA -sinA  0 |
	//= | x y 1| x | sinA  cosA  0 |
	//			   |    0     0  1 |
	double sinAngle = sin( angle );
	double cosAngle = cos( angle );

	if ( center.isZero() ) {
		double tempX = x * cosAngle - y * sinAngle;
		y = y * cosAngle + x * sinAngle;
		x = tempX;
	} else {
		//on met point comme l'origine
		double tempX = x - center.x;
		double tempY = y - center.y;

		x = tempX * cosAngle - tempY * sinAngle + center.x;
		y = tempY * cosAngle + tempX * sinAngle + center.y;
	}
	if ( abs(x) < MIN_LIMIT ) {
		x = 0.0f;
	}
	if ( abs(y) < MIN_LIMIT ) {
		y = 0.0f;
	}
}

void Vec2::scale( const Vec2& point, double radio ) {
	if ( point.isZero() ) {
		x *= radio;
		y *= radio;
	} else {
		double tempX = x - point.x;
		double tempY = y - point.y;
		
		x = tempX * radio + point.x;
		y = tempY * radio + point.y;
	}
}

void Vec2::scale( double radio ) {
	x *= radio;
	y *= radio;
}


const Vec2 Vec2::ZERO = Vec2(0.0f, 0.0f);
const Vec2 Vec2::ONE = Vec2(1.0f, 1.0f);