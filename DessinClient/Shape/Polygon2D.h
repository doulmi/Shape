#ifndef __POLYGON_H__

#define __POLYGON_H__

#include <vector>
#include "SimpleShape.h"
#include "visitor/ShapeVisitor.h"
	
using std::vector;

class Polygon2D : public SimpleShape {
private:
	vector< Point > points;
public:
	explicit Polygon2D( Point orig );	
	explicit Polygon2D( vector<double> xpoints, vector<double> ypoinst );
	explicit Polygon2D( vector<Point> points );
	virtual ~Polygon2D();

	vector< Point > getPoints() const { return points; }
	virtual void lineTo( Point nextP );
	virtual void translate( Vec2 vec ) override;
	virtual void homothetic( Point point, double ratio ) override;
	virtual void rotate( Point center, double angle ) override;
	virtual string toString() override;
	virtual double calArea() override;
	virtual void accept( ShapeVisitor* visitor ) override { visitor->visitPolygon2D( *this ); }
};

#endif	//__POLYGON_H__