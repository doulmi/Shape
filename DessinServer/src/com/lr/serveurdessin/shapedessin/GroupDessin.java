package com.lr.serveurdessin.shapedessin;

import java.awt.Graphics;

/**
* Une cellule de COR de dessiner, spécial pour dessiner un group 
* @author samuel
*
*/
public class GroupDessin extends ShapeDessin {
	
	/**
	 * Méthode principal pour dessiner un group
	 * @param type Le type de forme
	 * @param params Le data pour dessiner un group
	 * @param startI L'indexation commencé pour dessiner ce group
	 * @param g le Graphics
	 */
	@Override
	public void draw( int type, String[] params, int[] startI, Graphics g ) {
		if( type == ShapeType.GROUP.getId() ) {
			int start = startI[ 0 ];
			int shapeCount = Integer.valueOf( params[ start + 1 ].trim() );
			
			//avancer startI, un pour le type group, un pour le sum des formes
            startI[ 0 ] += 2;

			ShapeDessin head = this.getHead();
			//dessiner tous les formes dans ce group
			for ( int i = 0; i < shapeCount; i++ ) {
				int subType = Integer.parseInt( params[ startI[0] ].trim() );
				head.draw( subType, params, startI, g );
			}
		}
	}
}
