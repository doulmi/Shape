#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "SimpleShape.h"
#include "visitor/ShapeVisitor.h"
#include <string>

/**
 * La forme de segment 
 */
class Segment : public SimpleShape {
private:
	/** Le départ du segment */
	Point src;

	/** L'extrémité du segment */
	Point dest;
public:
	/**
     * Construit un nouveau segment initialisé aux valeurs spécifiées.
     * @param iSrc Le départ du segment
     * @param iDest L'extrémité du segment
	 */
	explicit Segment( Point iSrc, Point iDest ) : src( iSrc ), dest( iDest ) { }

	/**
	 * destructeur
	 */
	virtual ~Segment() {}

	/**
	 * @return Le départ de ce segment
	 */
	Point getSrc() const { return src; }

	/**
	 * @return L'extrémité de ce segment
	 */
	Point getDest() const { return dest; }	

	/**
	 * @param newSrc met à jour le départ de ce segment au valeur donné
	 */
	void setSrc( Point newSrc ) { this->src.set( newSrc ); }

	/**
	 * @param newDest met à jour l'extrémité de ce segment au valeur donné
	 */
	void setDest( Point newDest ) { this->dest.set( newDest ); }

	/**
     * Translate tous les points avec le vecteur donné
     * @param le vecteur à translate
     */
	virtual void translate( Vec2 vec ) override;

	/**
	 * Une homothétie est définie par un point invariant et par un rapport d'homothétie
	 * @param point le center pour cette homothétie
	 * @radio radio pour cette homothétie
	 */
	virtual void homothetic( Point point, double ratio ) override;

	/**
     * Faire une rotation pour ce segment par l'angle(en radians) autour du point donné
     * @param center le centre de la rotation
     * @param angle l'angle à rotater (en radians).
     */
	virtual void rotate( Point center, double angle ) override;

	/**
     * Converti ce segment comme un string
	 * @result Le string acquis
     */
	virtual string toString() override;

	/**
	 * un methode pour realiser le Visitor Pattern Dessign
	 * @param visitor Le visitor
     */
	virtual void accept( ShapeVisitor* visitor ) override { visitor->visitSegment( *this ); }

	/**
     * L'aire d'un segment est toujours 0
	 * @result 0
     */
	virtual double calArea() override { return 0; }

};
#endif	//__SEGMENT_H__