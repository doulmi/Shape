#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "util/Color.h"
#include <string>
#include "util/Vec2.h"

using std::string;
class ShapeVisitor;

/** 
 * un abstract class, le père de toutes les autres formes
 */
class Shape {
private:
	/** le couleur pour dessiner */
	Color color;

	/** si cette forme est dans un group */
	bool isInGroup;

public:
	/**
	 * constructeur qui initialise le color en noir et isIngroup faux
	 */
	Shape() : color( Color::BLACK ), isInGroup( false ) {}

	/**
	 * destructeur
	 */
	virtual ~Shape() {}

	/**
	 * @return vrai si cette forme est dans un group
	 */
	inline bool getIsInGroup() const { return this->isInGroup; }

	/**
	 * Mettre à jour isInGroup
	 * @param nouvel etat de isInGroup
	 */
	inline void setIsInGroup( bool state ) { this->isInGroup = state; }

	/**
	 * @return Le couleur de cette forme
	 */
	inline Color getColor() const { return this->color; }

	/**
	 * Poser le couleur de cette forme en le couleur donné
	 * @param le nouveau couleur de cette forme
	 */
	inline void setColor( Color c ) { this->color = c; }

	/**
     * Translate tous les points avec le vecteur donné
     * @param le vecteur à translate
     */
	virtual void translate( Vec2 vec ) = 0;

	/**
	 * Une homothétie est définie par un point invariant et par un rapport d'homothétie
	 * @param point le center pour cette homothétie
	 * @radio radio pour cette homothétie
	 */
	virtual void homothetic( Point point, double ratio ) = 0;

	/**
     * Faire une rotation pour cette forme par l'angle(en radians) autour du point donné
     * @param center le centre de la rotation
     * @param angle l'angle à rotater (en radians).
     */
	virtual void rotate( Point center, double angle ) = 0;

	/**
     * Converti cette forme comme un string
	 * @result Le string acquis
     */
	virtual string toString() = 0;

	/**
     * Calcule L'aire de cette forme
	 * @result L'aire de cette forme 
     */
	virtual double calArea() = 0;

	/**
	 * un methode pour realiser le Visitor Pattern Dessign
	 * @param visitor Le visitor
     */
	virtual void accept( ShapeVisitor* visitor ) = 0;

};

#endif	//__SHAPE_H__