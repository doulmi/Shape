#ifndef __CERCLE_READER_H__
#define __CERCLE_READER_H__

#include "ShapeReaderChain.h"
 
/**
 * Pour le chargement d'une forme à partir d'un fichier au format *.txt, 
 * les différents cas possibles de formes soient distingués par une mise 
 * en oeuvre du Design Pattern Chain Of Responsibility.
 * C'est le reader spécial pour traiter le cercle
 */
class CercleReaderChain : public ShapeReaderChain {
public:
	/** 
	 * Charger une forme à partir d'un fichier
	 * @param type Comme un ShapeType, cela représent quelle forme qu'on veut charger
	 * @param params Les données disponibles pour charger une forme
	 * @param startI Le premier indexation qu'on utilse 
	 * @return une forme qu'on charge
	 */
	virtual Shape* read( int type, double* params,int* startI ) override;
private:
};


#endif	//__CERCLE_READER_H__
