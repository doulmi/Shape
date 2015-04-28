#include "PolygonReaderChain.h"
#include "../ShapeType.h"
#include "../Shape.h"
#include "../Polygon2D.h"
#include <vector>
#include <iostream>
using namespace std;

Shape* PolygonReaderChain::read( int type, double* params, int* startI ) {
	if ( type == static_cast<int>( ShapeType::POLYGON2D ) ) {
		int start = *startI;
		try {
			int pointCount = static_cast<int>( params[ start + 1 ] );
			vector<double> xpoints( pointCount ); 
			vector<double> ypoints( pointCount );

			for( int i = 0; i < pointCount; i ++ ) {
				int ipx = ( i + 1 ) * 2;
				xpoints[ i ] = params[ start + ipx ];
				ypoints[ i ] = params[ start + ipx + 1 ];
			}
			int color = static_cast<int>( params[ start + pointCount * 2 + 1 ] );	

			*startI += 2 + pointCount * 2;
			return new Polygon2D( xpoints, ypoints );
		} catch( std::runtime_error e ) {
			cerr << "Erreur de format" << endl;
			return NULL;
		}
	} else {
		return this->successor->read( type, params, startI );
	}
}