#include "Cercle.h"
#include <sstream>

void Cercle::translate( Vec2 vec ) {
	centerPoint.add( vec );
}

void Cercle::homothetic( Point point, double ratio ) {
	centerPoint.scale( point, ratio );
	radius *= ratio;
}

void Cercle::rotate( Point center, double angle ) {
	centerPoint.rotate( center, angle );
}

string Cercle::toString() {
	std::ostringstream os;
	os << "1 " << centerPoint.x << " " << centerPoint.y << " " << radius << " " << getColor();
	return os.str();
}
