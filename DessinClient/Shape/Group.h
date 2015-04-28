#ifndef __GROUP_H__
#define __GROUP_H__

#include <vector>
#include "Shape.h"
#include "visitor/ShapeVisitor.h"

using std::vector;

/**
 * Groupe est une forme géométrique composée. Elle est composée d'une ou plusieurs formes géométriques (simples ou composées) disjointes. 
 * Une forme ne peut pas appartenir simultanément à plusieurs groupes.
 * On suppose qu'il n'y a jamais d'intersection entre les pièces créées
 * pour un group, le couleur ca sert a rien, on utilise son propre couleur pour toutes les sous formes
 */
class Group : public Shape {
private:
	/** le vecteur garde les forms qui font partie de cette forme */
	vector< Shape* > shapes;
public:
	/** constructeur qui cree un group sans sous forme**/
	Group() {}
	
	/**
	 * ajoute une forme dans ce group comme sous forme
	 * @param la forme à ajouter
	 */
	bool addShape( Shape* shape );

	/**
	 * supprimer une forme de ce groupe
	 * @param la forme à supprimer
	 */
	void removeShape( Shape* shape );

	/**
	 * retourne l'index si l'on trouve la forme dans shapes, sinon retourne -1; 
	 * @param shape Shape* le but qu'on souhaite trouver
	 */
	int findShape( const Shape* shape );

	/**
	 * @retour le somme de sous formes de ce group
	 */
	inline int getShapeCount() const { return shapes.size(); }

	/**
     * Translate toutes les sous formes avec le vecteur donné
     * @param le vecteur à translate
     */	
	virtual void translate( Vec2 vec ) override;

	/**
	 * Une homothétie est définie par un point invariant et par un rapport d'homothétie,
	 * pour un group, va faire une homothétie pour toutes les sous formes
	 * @param point le center pour cette homothétie
	 * @radio radio pour cette homothétie
	 */
	virtual void homothetic( Point point, double ratio ) override;

	/**
	 * Faire une rotation pour ce group par l'angle(en radians) autour du point donné
	 * pour un group, fait rotation pour toutes les sous formes
     * @param center le centre de la rotation
     * @param angle l'angle à rotater (en radians).
     */
	virtual void rotate( Point center, double angle ) override;

	/**
     * Converti ce group comme un string
	 * @result Le string acquis
     */
	virtual string toString() override;

	/**
     * Calcule L'aire de ce group
	 * L'aire d'un groupe est la somme des aires des formes qui 
	 * la composent puisque celles-ci sont toutes disjointes.
	 * @result L'aire de ce group
     */
	virtual double calArea() override;

	/**
	 * un interface pour realiser le Visitor Pattern Dessign
	 * @param visitor Le visitor
     */
	virtual void accept( ShapeVisitor* visitor ) override { visitor->visitGroup( *this ); }
};
#endif	//__GROUP_H__