package com.lr.serveurdessin.shapedessin;

/**
 * Tous les genres de formes utilisés
 * @author samuel
 *
 */
public enum ShapeType {
	/** le forme segment **/
	SEGMENT( 0 ),

	/** le forme cercle **/
	CERCLE( 1 ),

	/** le forme polygone **/
	POLYGON( 2 ),

	/** le forme group **/
	GROUP( 3 );
	
	private ShapeType( int i ) {
		this.id = i;
	}
	
	/**
	 * @return l'identité de ce forme
	 */
	public int getId() {
		return this.id;
	}
	
	/** l'identité de ce forme **/
	private int id;
}
