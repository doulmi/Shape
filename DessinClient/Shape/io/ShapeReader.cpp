#include "ShapeReader.h"
#include "ShapeReaderChain.h"
#include "SegmentReaderChain.h"
#include "CercleReaderChain.h"
#include "PolygonReaderChain.h"
#include "GroupReaderChain.h"
#include "../ShapeType.h"
#include <memory>

ShapeReader::ShapeReader( const string& infileName ) : infile( infileName ) {
	if ( !infile.is_open() ) {
		cerr << cerr << "erreur: ne peut pas ouvrir fichier d'entrée: " << infileName << endl;
		exit( -1 );
	}
}

Shape* ShapeReader::read() {
	double* params;
	vector< double > paramsList;
	
	double tmp = 0.0;
	while (	infile >> tmp ) {
		paramsList.push_back( tmp );
	} 

	params = new double[ paramsList.size() ];
	for ( int i = 0; i < paramsList.size(); i ++ ) {
		params[ i ] = paramsList[ i ];
	}
	int type = static_cast<int>( params[ 0 ] );
	int* pStartI = new int(0);

	SegmentReaderChain segReader;
	CercleReaderChain cerReader;
	PolygonReaderChain polReader;
	GroupReaderChain gReader;

	segReader.setSuccessor( &cerReader );
	cerReader.setPredecessor( &segReader );

	cerReader.setSuccessor( &polReader );
	polReader.setPredecessor( &cerReader );

	polReader.setSuccessor( &gReader );
	gReader.setPredecessor( &polReader );

	Shape* s =  segReader.read( type, params, pStartI );
	delete pStartI;
	delete[] params;

	return s; 
}

ShapeReader::~ShapeReader() {
	infile.close();
	infile.clear();
}