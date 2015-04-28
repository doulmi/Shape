#ifndef __SHAPE_VISITOR_H__
#define __SHAPE_VISITOR_H__

class Segment;
class Cercle;
class Polygon2D;
class Group;

/**
 * Pour realiser le Visitor Dessign Pattern
 * C'est le père de tous les visitor pour faire des opération des formes
 */
class ShapeVisitor {
public:
	/** 
	 * Spécial pour traiter le segment
	 * @param visitSegment Le segment à traiter
	 */
	virtual void visitSegment( Segment& visitSegment ) = 0;

	/** 
	 * Spécial pour traiter le cercle
	 * @param visitSegment Le cercle à traiter
	 */
	virtual void visitCercle( Cercle& visitCercle ) = 0;

	/** 
	 * Spécial pour traiter le polygon
	 * @param visitSegment Le polygon à traiter
	 */
	virtual void visitPolygon2D( Polygon2D& visitPolygon2D ) = 0;

	/** 
	 * Spécial pour traiter le group
	 * @param visitSegment Le group à traiter
	 */
	virtual void visitGroup( Group& visitGroup ) = 0;
};

#endif	//__SHAPE_VISITOR_H__