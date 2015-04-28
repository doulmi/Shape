#include "Polygon2D.h"
#include <sstream>
#include "util/MathUtil.h"

Polygon2D::Polygon2D( Point orig ) {
	points.push_back( orig );
}

Polygon2D::Polygon2D( vector<double> xpoints, vector<double> ypoinst ) {
	int size = xpoints.size();
	if ( size > 0 ) {
		points.push_back( Point( xpoints[ 0 ], ypoinst[ 0 ] ) );
		for ( int i = 1; i < size; i ++ ) {
			lineTo( Point( xpoints[ i ], ypoinst[ i ] ) );
		}
	}
}

Polygon2D::Polygon2D( vector<Point> ps ) {
	if ( ! ps.empty() ) {
		points.push_back( ps[ 0 ] );
		for ( Point p : ps ) {
			lineTo( p );
		}
	}
}

Polygon2D::~Polygon2D() {
}

void Polygon2D::lineTo( Point nextP ) {
	points.push_back( nextP );	
}

void Polygon2D::translate( Vec2 vec ) {
	for( Point& p : points ) {
		p.add( vec );
	}
}

void Polygon2D::homothetic( Point point, double ratio ) {
	for( Point& p : points ) {
		p.scale( point, ratio );
	}
}

void Polygon2D::rotate( Point center, double angle ) {
	for( Point& p : points ) {
		p.rotate( center, angle );
	}
}

string Polygon2D::toString() {
	std::ostringstream o;
	//3: typeId, points count, color
	o << "2 " <<  points.size();
	for ( Point p : points ) {
		o << " " << p.x << " " << p.y;
	}
	o << " " << getColor();
	return o.str();
}

double Polygon2D::calArea() {
	double area = 0;
	int pointCount = points.size();
	int i;
	for( i = 0; i< pointCount - 1; i ++ ) {
		area += det( points[ i ].x, points[ i ].y, points[ i + 1 ].x, points[ i + 1 ].y );
	}
	area += det( points[ i ].x, points[ i ].y, points[ 0 ].x, points[ 0 ].y );
	return area / 2;
}