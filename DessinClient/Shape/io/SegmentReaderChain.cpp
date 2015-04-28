#include "SegmentReaderChain.h"
#include "../ShapeType.h"
#include "../Shape.h"
#include "../Segment.h"
#include <iostream>
using namespace std;

Shape* SegmentReaderChain::read( int type, double* params, int* startI ) {
	if ( type == static_cast<int>( ShapeType::SEGMENT ) ) {
		try {
			double x1 = params[ *startI + 1 ];
			double y1 = params[ *startI + 2 ];
			double x2 = params[ *startI + 3 ];
			double y2 = params[ *startI + 4 ];
			int color = static_cast<int>( params[ *startI + 5 ] );
			*startI += 6;

			return new Segment( Point( x1, y1 ), Point( x2, y2 ) );
		} catch( runtime_error e ) {
			cerr << "Erreur de format" << endl;
			return NULL;
		}
	} else {
		return this->successor->read( type, params, startI );
	}
}