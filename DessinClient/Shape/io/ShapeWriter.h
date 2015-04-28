#ifndef __SHAPE_WRITER_H__
#define __SHAPE_WRITER_H__

#include <fstream>
#include <string>
#include <iostream>
#include "../Shape.h"

using namespace std;
/**
 * un class pour sauvegarder les donnees des formes en fichier disque au format *.txt
 */
class ShapeWriter {
private:
	/** La sortie */
	ofstream outfile;
public:
	/** 
	 * Construit un shapeWriter avec le nom de fichier qu'on écrit les données
	 * @param outFileName Le nom de fichier qu'on écrit les données dedans
	 */
	explicit ShapeWriter( const string& outFileName );

	/**
	 * déstructeur 
	 */
	~ShapeWriter();

	/**
	 * sauvegarder une forme dans le fichier
	 * @param shape La forme à sauvegarder
	 */
	void saveToFile( Shape* shape );
};

ShapeWriter::ShapeWriter( const string& outFileName ) : outfile( outFileName ) {
	if ( !outfile ) {
		cerr << "erreur: ne peut pas ouvrir fichier de sortie: " << outFileName << endl;
		exit( -1 );
	}
}

ShapeWriter::~ShapeWriter() {
	outfile.close();
	outfile.clear();
}

void ShapeWriter::saveToFile( Shape* shape ) {
	outfile << shape->toString();	
}

#endif	//__SHAPE_WRITER_H__