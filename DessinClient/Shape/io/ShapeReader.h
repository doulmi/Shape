#ifndef __CADRE_SHAPE_READER_H__
#define __CADRE_SHAPE_READER_H__

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Shape;
class ShapeReaderChain;

/**
 * Un class pour charger les donnees des formes à partir d'un fichier disque au format *.txt
 */
class ShapeReader {
public:
	/**
	 * Construit un shapeReader avec le nom de fichier à charger
	 * @param infileName Le nom de fichier à charger
	 */
	explicit ShapeReader( const string& infileName );

	/** 
	 * Destructeur
	 */
	~ShapeReader();

	/** 
	 * charger une forme à partir de ce fichier donne 
	 * @return La forme qu'on charger à partir de ce fichier 
	 */
	Shape* read();
private:
	/** L'entrée */
	ifstream infile;
};

#endif	//__CADRE_SHAPE_READER_H__