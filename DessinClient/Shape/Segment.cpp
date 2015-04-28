#include "Segment.h"
#include <sstream>

void Segment::translate( Vec2 vec ) {
	src.add( vec );
	dest.add( vec );
}

void Segment::homothetic( Point point, double ratio ) {
	src.scale( point, ratio );
	dest.scale( point, ratio );
}

void Segment::rotate( Point center, double angle ) {
	src.rotate( center, angle );
	dest.rotate( center, angle );
}

string Segment::toString() {
	std::ostringstream os;

	os << "0 " << src.x << " " << src.y << " " << dest.x << " " << dest.y << " " << getColor();
	return os.str();
}