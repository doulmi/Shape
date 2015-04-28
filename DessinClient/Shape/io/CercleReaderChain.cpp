#include "CercleReaderChain.h"
#include "../ShapeType.h"
#include "../Shape.h"
#include "../Cercle.h"
#include <iostream>
using namespace std;

Shape* CercleReaderChain::read( int type, double* params, int* startI ) {
	if ( type == static_cast<int>( ShapeType::CERCLE ) ) {
		try {
			double centerX = params[ *startI + 1 ];
			double centerY = params[ *startI + 2 ];
			double radius = params[ *startI + 3 ];
			int color = static_cast<int>( params[ *startI + 4 ] );
			*startI += 5;

			return new Cercle( Point( centerX, centerY ), radius );
		} catch( runtime_error e ) {
			cerr << "Erreur de format" << endl;
			return NULL;
		}
	} else {
		return this->successor->read( type, params, startI );
	}
}