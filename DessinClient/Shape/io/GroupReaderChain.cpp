#include "PolygonReaderChain.h"
#include "GroupReaderChain.h"
#include "../ShapeType.h"
#include "../Shape.h"
#include "../Group.h"
#include <vector>
#include <iostream>

using namespace std;
Shape* GroupReaderChain::read( int type, double* params, int* startI ) {
	if ( type == static_cast<int>( ShapeType::GROUP ) ) {
		int start = *startI;
		int shapeCount = static_cast<int>( params[ start + 1 ] );

		*startI += 2;

		ShapeReaderChain* head = this->head();
		Group* group = new Group();
		try {
			for ( int i = 0; i < shapeCount; i ++ ) {
				int subType = static_cast<int>( params[ *startI ] );
				group->addShape( head->read( subType, params, startI ) );
			}
		} catch( std::runtime_error e ) {
			cerr << "Erreur de format" << endl;
			delete group;
			return NULL;
		}
		return group;
	} else {
		cerr << "Erreur de format: il y a pas de ce genre de" << endl;
		return NULL;	
	}
}