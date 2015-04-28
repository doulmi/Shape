#ifndef  __CERCLE_H__
#define __CERCLE_H__

#include "SimpleShape.h"
#include "visitor/ShapeVisitor.h"
#include <cmath>

/**
 * la forme de cercle
 */
class Cercle : public SimpleShape {
private:
	/** le rayon de ce cercle */
	double radius;

	/** l'orgine de ce cercle */
	Point centerPoint;

public:
	/**
	 * contruit un cercle avec le point central et le rayon donné
	 * @param iCenter L'origine de ce cercle
	 * @param iRadius Le rayon de ce cercle
	 */
	explicit Cercle( Point iCenter, double iRadius ) : centerPoint( iCenter ), radius( iRadius >= 0 ? iRadius : 0 ) {}

	/**
	 * destructeur
	 */
	virtual ~Cercle() {}

	/**
	 * @return L'origine de ce cercle
	 */
	inline Point getCenterPoint() const { return centerPoint; }

	/**
	 * met à jour de l'origine de ce cercle
	 */
	inline void setCenterPoint( Point p ) { centerPoint.set( p ); }

	/**
	 * @return Le rayon de ce cercle
	 */
	inline double getRadius() const { return radius; }

	/**
	 * met à jour du rayon de ce cercle
	 */
	inline void setRadius( double r ) { radius = r; }

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
     * Faire une rotation pour ce cercle par l'angle(en radians) autour du point donné
     * @param center le centre de la rotation
     * @param angle l'angle à rotater (en radians).
     */
	virtual void rotate( Point center, double angle ) override;

	/**
     * Converti ce cercle comme un string
	 * @result Le string acquis
     */
	virtual string toString() override;

	/**
     * Calcule L'aire de ce cercle
	 * @result L'aire de ce cercle
     */
	virtual double calArea() override { return 3.14 * radius * radius; }

	/**
	 * un methode pour realiser le Visitor Pattern Dessign
	 * @param visitor Le visitor
     */
	virtual void accept( ShapeVisitor* visitor ) override { visitor->visitCercle( *this ); }
};

#endif //__CERCLE_H__