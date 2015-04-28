#ifndef __MATH_UTIL_H__

#define __MATH_UTIL_H__
#include <cmath>

/** Le minimum limit pour comparer deux double */
const double MIN_LIMIT = 0.01f;

/**
 * converti l'angle signé donné en degré en radians
 * @param x l'angle signé donné en degré
 * @return l'angle signé donné en radians
 */
inline double deg2Rad( double x ) {
	return x * 0.0174532925f;
}

/**
 * converti l'angle signé donné en radians en degre 
 * @param x l'angle signé donné en radians 
 * @return l'angle signé donné en degre 
 */
inline double rad2Deg( double x ) {
	return x * 57.29577951f;
}

/**
 * comparer deux double
 * @param x un double 
 * @param y un double
 * @return vrai si x égal à y, sinon faux
 */
inline bool doubleEQL( double x, double y ) {
	return abs( x - y ) < MIN_LIMIT;
}

/**
 * Calcule le déterminant pour  | a11 a12 |
 *								| a21 a22 |
 */
inline double det( double a11, double a12, double a21, double a22 ) {
	return a11 * a22 - a12 * a21;
}

#endif	//__MATH_UTIL_H__