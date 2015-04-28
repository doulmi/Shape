#ifndef __SHAPE_READER_H__
#define __SHAPE_READER_H__

#include <vector>
#include "../io/Nocopyable.h"

using std::vector;

class Shape;

/**
 * Pour le chargement d'une forme à partir d'un fichier au format *.txt, 
 * les différents cas possibles de formes soient distingués par une mise 
 * en oeuvre du Design Pattern Chain Of Responsibility.
 * C'est le père de tous les readerChain, c'est un class abstract
 */
class ShapeReaderChain : public NoCopyable {
protected:
	/** Le successeur */
	ShapeReaderChain* successor;
	/** Le predécesseur */
	ShapeReaderChain* predecessor;

public:
	/** Construit une ShapeReaderChaine sans successeur ni predécesseur */
	ShapeReaderChain() : successor( NULL ), predecessor( NULL ) {}

	/** 
	 * Mettre à jour le successeur
	 * @param s le nouveau successeur
	 */
	inline void setSuccessor( ShapeReaderChain* s ) { this->successor = s; }

	
	/** 
	 * Mettre à jour le predécesseur
	 * @param s le nouveau predécesseur
	 */
	inline void setPredecessor( ShapeReaderChain* p ) { this->predecessor = p; }

	/** 
	 * Charger une forme à partir d'un fichier
	 * @param type Comme un ShapeType, cela représent quelle forme qu'on veut charger
	 * @param params Les données disponibles pour charger une forme
	 * @param startI Le premier indexation qu'on utilse 
	 * @return une forme qu'on charge
	 */
	virtual Shape* read( int type, double* params, int* startI ) = 0;

	/**
	 * Trouver la tête de cette Chaine de responsabilité
	 * @return La tête de cette Chaine de responsabilité
	 */
	ShapeReaderChain* head() {
		ShapeReaderChain* head = this;
		while ( head->predecessor != NULL ){
			head = head->predecessor;
		}
		return head;
	}
};

#endif	//__SHAPE_READER_H__