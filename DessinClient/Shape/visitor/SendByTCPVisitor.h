#ifndef __SEND_BY_TCP_VISITOR_H__
#define __SEND_BY_TCP_VISITOR_H__

#include "ShapeVisitor.h"
#include "../SocketClient.h"

/**
 * Pour realiser le Visitor Dessign Pattern
 * Ce visitor envoyer les donnees des formes à dessiner par le protocol TCP/IP
 */
class SendByTCPVisitor : public ShapeVisitor {
public:
	/** 
	 * Spécial pour traiter le segment
	 * @param visitSegment Le segment à traiter
	 */
	virtual void visitSegment( Segment& visitSegment );

	/** 
	 * Spécial pour traiter le cercle
	 * @param visitSegment Le cercle à traiter
	 */
	virtual void visitCercle( Cercle& visitCercle );

	/** 
	 * Spécial pour traiter le polygon
	 * @param visitSegment Le polygon à traiter
	 */
	virtual void visitPolygon2D( Polygon2D& visitPolygon2D );

	/** 
	 * Spécial pour traiter le group
	 * @param visitSegment Le group à traiter
	 */
	virtual void visitGroup( Group& visitGroup );
private:
};


#endif __SEND_BY_TCP_VISITOR_H__



