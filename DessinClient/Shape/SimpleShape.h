#ifndef __SIMPLE_SHAPE_H__
#define __SIMPLE_SHAPE_H__

#include "Shape.h"

class SimpleShape : public Shape {
public:
	SimpleShape() : Shape() {}
	virtual ~SimpleShape() {}
};
#endif	//__SIMPLE_SHAPE_H__