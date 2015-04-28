#include <iostream>
#include <cassert>
#include "util/Vec2.h"
#include "util/MathUtil.h"
#include "Segment.h"
#include "Cercle.h"
#include "Polygon2D.h"
#include "Group.h"
#include <string>
#include <vector>
#include "visitor/SendByTCPVisitor.h"
#include "io/ShapeWriter.h"
#include "io/ShapeReader.h"

void testVec2();
void testSegment();
void testCercle();
void testPolygon2D();
void testGroup();
void testWriter();
void testReader();
void testAll();

using std::string;
using std::vector;
int main() {
	testAll();
	getchar();
	return 0;
}

/**
 * Teste toutes les fonctions
 */
void testAll() {
	//testVec2();
	//testSegment();
	//testCercle();
	//testPolygon2D();
	testGroup();
	//testWriter();
	//testReader();
}

/**
 * Teste l'ecture à partir d'un fichier au format *.txt
 */
void testReader() {
	string outfile("./seg5.txt");
	ShapeReader sr1( outfile );

	Segment* seg1 = static_cast<Segment*>( sr1.read() );
	if ( seg1 != NULL ) {
		cout << seg1->toString() << endl;
		delete seg1;
	}

	outfile = "./cer5.txt";
	ShapeReader sr2( outfile );

	Cercle* cer1 = static_cast<Cercle*>( sr2.read() );
	if ( cer1 != NULL ) {
		cout << cer1->toString() << endl;
		delete cer1;
	}

	outfile = "./p5.txt";
	ShapeReader sr3( outfile );
	Polygon2D* pol1 = static_cast<Polygon2D*>( sr3.read() );
	if ( pol1 != NULL ) {
		cout << pol1->toString() << endl;
		delete pol1;
	}

	outfile = "./group5.txt";
	ShapeReader sr4( outfile );
	Group* g1 = static_cast<Group*>( sr4.read() );
	if ( g1 != NULL ) {
		cout << g1->toString() << endl;
		delete g1;
	}
}

/**
 * Teste l'écriture en fichier au format *.txt
 */
void testWriter() {
	Segment seg5( Point( 100.0f, 100.0f ), Point( 200.0f, 200.0f ) );
	Cercle cer5( Point( 150, 150 ), 50 );
	Polygon2D p5( Point( 100.0f, 0.0f ) );
	p5.lineTo( Point( 200.0f, 0.0f ) );
	p5.lineTo( Point( 200.0f, 100.0f ) );
	p5.lineTo( Point( 100.0f, 100.0f ) );

	Group g5;
	g5.addShape( &seg5 );
	g5.addShape( &cer5 );
	g5.addShape( &p5 );
	
	//Teste Segment Reader et Writer
	string outfile("./seg5.txt");
	ShapeWriter shapeWriter( outfile );
	shapeWriter.saveToFile( &seg5 );

	outfile = "./cer5.txt";
	ShapeWriter sw2( outfile );
	sw2.saveToFile( &cer5 );

	outfile = "./p5.txt";
	ShapeWriter sw3( outfile );
	sw3.saveToFile( &p5 );

	outfile = "./group5.txt";
	ShapeWriter sw4( outfile );
	sw4.saveToFile( &g5 );
}

/** 
 * Teste les fonctions du group
 */
void testGroup() {
	Group g1;

	assert( doubleEQL( g1.calArea(), 0.0f ) );

	Polygon2D pp1( Point( 0.0f, 0.0f ) );
	pp1.lineTo( Point( 1.0f, 0.0f ) );
	pp1.lineTo( Point( 1.0f, 1.0f ) );
	pp1.lineTo( Point( 0.0f, 1.0f ) );
	g1.addShape( &pp1 );
	
	assert( ! g1.addShape( &pp1 ) );
	assert( pp1.getIsInGroup() );
	assert( g1.getShapeCount() == 1 );
	assert( doubleEQL( g1.calArea(), pp1.calArea() ) );

	Cercle pc1( Point( 3.0f, 3.0f ), 2 );
	g1.addShape( &pc1 );
	assert( pc1.getIsInGroup() );
	assert( g1.getShapeCount() == 2 );
	assert( doubleEQL( g1.calArea(), pp1.calArea() + pc1.calArea() ) );
	
	Group g2;
	assert( ! g2.addShape( &pc1 ) );

	Segment ps1( Point( 0, 0 ), Point( 4, 4 ) );
	g2.addShape( &ps1 );
	g1.addShape( &g2 );
	assert( g1.getShapeCount() == 3 );
	assert( g2.getShapeCount() == 1 );
	assert( g2.calArea() == 0 );

	Segment s5( Point( 100, 100 ), Point( 200, 200 ) );
	Cercle c5( Point( 150, 150 ), 50 );

	Polygon2D p5( Point( 100.0f, 0.0f ) );
	p5.lineTo( Point( 200.0f, 0.0f ) );
	p5.lineTo( Point( 200.0f, 100.0f ) );
	p5.lineTo( Point( 100.0f, 100.0f ) );

	Group g3;
	g3.addShape( &s5 );
	g3.addShape( &c5 );
	g3.addShape( &p5 );
	SendByTCPVisitor visitor;
	g3.accept( &visitor );

	g3.homothetic( Point::ZERO, 2 );
	g3.accept( &visitor );

	g3.rotate( Point::ZERO, 20 );
	g3.accept( &visitor );

	g3.translate( Vec2( 50, 50 ) );
	g3.accept( &visitor );
}

/** 
 * Teste les fonctions du polygone
 */
void testPolygon2D() {
	Polygon2D p( Point( 0.0f, 0.0f ) );
	p.lineTo( Point( 1.0f, 1.0f ) );
	p.lineTo( Point( 1.0f, 2.0f ) );
	p.lineTo( Point( 2.0f, 1.0f ) );

	assert( p.getPoints().size() == 4 );

	//teste la translation
	Polygon2D p2( p );
	p.translate( Vec2( 1.0f, 2.0f ) );
	vector< Point > points = p.getPoints();
	assert( points.size() == 4 );

	vector< Point > points2 = p2.getPoints();
	int size = points.size();
	for ( int i = 0; i < size; i ++ ) {
		assert( doubleEQL( points[ i ].x, points2[ i ].x + 1 ) );	
		assert( doubleEQL( points[ i ].y, points2[ i ].y + 2 ) );	
	}

	//teste l'homoretique
	Polygon2D p3( p );
	p.homothetic( Point( 1.0f, 0.0f ), 2 );
	vector< Point > points3 = p.getPoints();
	vector< Point > points4 = p3.getPoints();
	for ( int i = 0; i < size; i ++ ) {
		assert( doubleEQL( points3[ i ].x , ( points4[ i ].x - 1 ) * 2 + 1 ) );
		assert( doubleEQL( points3[ i ].y, points4[ i ].y * 2 ) );
	}

	//teste la rotation
	Polygon2D p4( Point( 1.0f, 0.0f ) );
	p4.lineTo( Point( 2.0f, 0.0f ) );
	p4.lineTo( Point( 2.0f, 1.0f ) );
	p4.lineTo( Point( 1.0f, 1.0f ) );

	assert( doubleEQL( p4.calArea(), 1.0f ) );

	p4.rotate( Point::ZERO, deg2Rad(90));
	vector< Point > points5 = p4.getPoints();
	assert( doubleEQL( points5[ 0 ].x, 0.0f ) );
	assert( doubleEQL( points5[ 0 ].y, 1.0f ) );
	
	assert( doubleEQL( points5[ 1 ].x, 0.0f ) );
	assert( doubleEQL( points5[ 1 ].y, 2.0f ) );

	assert( doubleEQL( points5[ 2 ].x, -1.0f ) );
	assert( doubleEQL( points5[ 2 ].y, 2.0f ) );

	assert( doubleEQL( points5[ 3 ].x, -1.0f ) );
	assert( doubleEQL( points5[ 3 ].y, 1.0f ) );
	assert( doubleEQL( p4.calArea(), 1.0f ) );
	std::cout << p4.toString() << std::endl;
	assert( p4.toString() == "2 4 0 1 0 2 -1 2 -1 1 1" );

	p4.rotate( Point::ZERO, deg2Rad( -90 ) );
	
	assert( doubleEQL( p4.calArea(), 1.0f ) );

	Polygon2D p5( Point( 100.0f, 0.0f ) );
	p5.lineTo( Point( 200.0f, 0.0f ) );
	p5.lineTo( Point( 200.0f, 100.0f ) );
	p5.lineTo( Point( 100.0f, 100.0f ) );

	SendByTCPVisitor* visitor = new SendByTCPVisitor();
	p5.accept( visitor );

	p5.homothetic( Point::ZERO, 2 );
	p5.accept( visitor );

	p5.rotate( Point( 100.0f, 0.0f ), deg2Rad( 10 ) );
	p5.accept( visitor );

	p5.translate( Vec2( 50, 50  ) );
	p5.accept(visitor);
	delete visitor;
}

/** 
 * Teste les fonctions du cercle
 */
void testCercle() {
	Cercle cercle( Point( 0.0f, 0.0f ), 2 );
	assert( doubleEQL( cercle.calArea(), 2 * 3.14 * cercle.getRadius() * cercle.getRadius() ) );
	assert( ! cercle.getIsInGroup() );
	cercle.setColor( Color::CYAN );
	assert( cercle.getColor() == Color::CYAN );

	//teste la rotation
	cercle.rotate( Point( 2.0f, 2.0f ), deg2Rad( 90.0f ) );
	assert( doubleEQL( cercle.getCenterPoint().x, 4.0f ) );
	assert( doubleEQL( cercle.getCenterPoint().y, 0.0f ) );
	
	//teste l'homothetique
	Cercle cercle2( Point( 0.0f, 0.0f ), 2 );
	double origRadius = cercle.getRadius();
	cercle2.homothetic( Point( 4.0f, 4.0f ), 0.5f );
	assert( doubleEQL( cercle2.getCenterPoint().x, 2.0f ) );
	assert( doubleEQL( cercle2.getCenterPoint().y, 2.0f ) );
	assert( doubleEQL( cercle2.getRadius(), origRadius / 2.0f ) );

	//teste la translation
	origRadius = cercle2.getRadius();
	cercle2.translate( Vec2( 2.0f, 3.0f ) );
	assert( doubleEQL( cercle2.getCenterPoint().x, 4.0f ) );
	assert( doubleEQL( cercle2.getCenterPoint().y, 5.0f ) );
	assert( doubleEQL( cercle2.getRadius(), origRadius ) );

	//teste toString
	assert( cercle2.toString() == string("1 4 5 1 1") );

	Cercle cercle3( Point( 100.0f, 100.0f ), 50 );
	SendByTCPVisitor* visitor = new SendByTCPVisitor();
	cercle3.accept( visitor );

	cercle3.homothetic( Point::ZERO, 2 );
	cercle3.accept( visitor );

	cercle3.rotate( Point::ZERO, deg2Rad( 10 ) );
	cercle3.accept( visitor );

	cercle3.translate( Vec2( 100, 200 ) );
	cercle3.accept( visitor );
	delete visitor;
}

/** 
 * Teste les fonctions du segment
 */
void testSegment() {
	Segment seg( Point( 0.0f, 0.0f ), Point( 4.0f, 4.0f ) );
	Segment seg2( seg );
	assert( seg.calArea() == 0 );

	assert( ! seg.getIsInGroup() );
	assert( seg.getColor() == Color::BLACK );

	//teste la rotation
	seg.rotate( Point( 2.0f, 2.0f ), deg2Rad( 90.0f ) );

	assert( doubleEQL( seg.getSrc().x, 4.0f ) );
	assert( doubleEQL( seg.getSrc().y, 0.0f ) );
	assert( doubleEQL( seg.getDest().x, 0.0f ) );
	assert( doubleEQL( seg.getDest().y, 4.0f ) );

	//teste toString
	assert( seg.toString() == string("0 4 0 0 4 1") );

	//teste la traslation
	seg.translate( Vec2( 1.0f, 2.0f ) );
	assert( doubleEQL( seg.getSrc().x, 5.0f ) );
	assert( doubleEQL( seg.getSrc().y, 2.0f ) );
	assert( doubleEQL( seg.getDest().x, 1.0f ) );
	assert( doubleEQL( seg.getDest().y, 6.0f ) );

	//teste l'homothetique
	seg2.homothetic( Point( 4.0f, 0.0f ), 2 );
	assert( doubleEQL( seg2.getSrc().x, -4.0f ) );
	assert( doubleEQL( seg2.getSrc().y, 0.0f ) );
	assert( doubleEQL( seg2.getDest().x, 4.0f ) );
	assert( doubleEQL( seg2.getDest().y, 8.0f ) );
	
	Segment seg3( Point( 100.0f, 100.0f ), Point( 300.0f, 200.0f ) );
	
	//Teste draw fonction
	SendByTCPVisitor* visitor = new SendByTCPVisitor();
	seg3.accept( visitor );

	seg3.homothetic( Point( 50, 50), 0.5 );
	seg3.accept( visitor );

	seg3.translate( Vec2( 50, 50 ) );
	seg3.accept( visitor );

	seg3.rotate( Point( 100, 100 ), deg2Rad( 45 ) );
	seg3.accept( visitor );
	delete visitor;
}

/** 
 * Teste les fonctions du Vec2
 */
void testVec2() {
	Vec2 v1;
	assert( v1 == Vec2::ZERO );
	assert( v1.isZero() );

	Vec2 v2( 31.0f, 2.0f );
	assert( v2.x == 31.0f );
	assert( v2.y == 2.0f );
	assert( ! v2.isZero() );

	Vec2 v3( v2 );
	assert( v2 == v3 );
	v3.add( v2 );
	assert( v3 == v2 * 2.0f );
	v3.scale(2);
	v2.scale(Point::ZERO, 4.0f);
	assert( v3 == v2 );

	Vec2 v4 = v1 + v2;
	assert( v4.x == v2.x );
	assert( v4.y == v2.y );

	Vec2 v5 = v3 - v2;
	assert( v5.isZero() );
	
	v3.set( 1.0f, 1.0f );
	v2.set( 2.0f, 2.0f );
	v1.set( v2 );
	v2.scale( v3, 2.0f );
	assert( doubleEQL( v2.x, v1.x * 1.5f ) );
	assert( doubleEQL( v2.y, v1.y * 1.5f ) );
	
	v1.rotate(Point::ZERO, deg2Rad( 90.0f ) );
	assert( doubleEQL( v1.x, -2.0f ) );
	assert( doubleEQL( v1.y, 2.0f ) );

	v1.rotate( Point( -2.0f, 0.0f ), deg2Rad( -180.0f ) );
	assert( doubleEQL( v1.x, -2.0f ) );
	assert( doubleEQL( v1.y, -2.0f ) );

}