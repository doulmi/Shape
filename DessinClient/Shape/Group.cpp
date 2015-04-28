#include "Group.h"
#include <sstream>

bool Group::addShape( Shape* shape ){
	if ( shape->getIsInGroup() ) {
		return false;
	}
	shape->setIsInGroup( true );
	shapes.push_back( shape );
	return true;
}

void Group::removeShape( Shape* shape ){
	int index = findShape( shape ); 
	if ( index != -1 ) {
		shapes.erase( shapes.begin() + index );
	}
}

int Group::findShape( const Shape* shape ){
	int size = shapes.size();
	for ( int i = 0; i < size; i ++ ) {
		if ( shape == shapes[ i ] ) {
			return i;
		}
	}
	return -1;
}

void Group::translate( Vec2 vec ) {
	for ( auto it : shapes ) {
		(*it).translate( vec );
	}
}

void Group::homothetic( Point point, double ratio ) {
	for ( auto it : shapes ) {
		(*it).homothetic( point, ratio );
	}
}

void Group::rotate( Point center, double angle ) {
	for ( auto it : shapes ) {
		(*it).rotate( center, angle );
	}
}

string Group::toString() {
	//#params count #group #shape count #first shape #par exemple: segment #color #second shape
	std::ostringstream o;
	int size = getShapeCount();
	o << "3 " << size;

	for ( int i = 0; i < size; i ++ ) {
		o << " " << shapes[ i ]->toString(); 
	}
	o << " " << getColor();
	return o.str();
}

double Group::calArea() {
	double area = 0;
	for ( auto it : shapes ) {
		area += (*it).calArea();	
	}
	return area;
}