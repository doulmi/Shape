package com.lr.serveurdessin.shapedessin;

import java.awt.Color;

/**
 * les couleurs utilsés dans ce programme, il utilise java.awt.Color dedans
 * @author samuel
 *
 */
public enum Color3 {
	/** le couleur bleu **/
	BLUE( Color.BLUE, 0 ),
	/** le couleur noir **/
	BLACK( Color.BLACK, 1),
	/** le couleur rouge **/
	RED( Color.RED, 2 ),
	/** le couleur vert ,**/
	GREEN( Color.GREEN, 3 ),
	/** le couleur jaune **/
	YELLOW( Color.YELLOW, 4 ),
	/** le couleur cyan **/
	CYAN( Color.CYAN, 5 ) ;

	private Color3( Color c, int id ) {
		this.c = c;
		this.id = id;
	}
	
	/**
	 * 
	 * @param id l'identité d'un couleur
	 * @return le couleur en RGB correspand de cet identité
	 */
	public static Color getColorById( int id ) {
		for ( Color3 value : Color3.values() ) {
			if ( value.id == id ) {
				return value.c;
			}
		}
		return Color3.BLACK.c;
	}
	
	/** le couleur en RGB **/
	Color c;
	
	/** l'identité de ce couleur **/
	int id;
}
