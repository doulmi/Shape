#include "SendByTCPVisitor.h"
#include "../Segment.h"
#include "../Cercle.h"
#include "../Polygon2D.h"
#include "../Group.h"

void SendByTCPVisitor::visitSegment( Segment& visitSegment ) {
	SocketClient::getInstance()->sendDessinData( visitSegment.toString() );
}

void SendByTCPVisitor::visitCercle( Cercle& visitCercle ) {
	SocketClient::getInstance()->sendDessinData( visitCercle.toString() );
}

void SendByTCPVisitor::visitPolygon2D( Polygon2D& visitPolygon2D ) {
	SocketClient::getInstance()->sendDessinData( visitPolygon2D.toString() );
}

void SendByTCPVisitor::visitGroup( Group& visitGroup ) {
	SocketClient::getInstance()->sendDessinData( visitGroup.toString() );
}