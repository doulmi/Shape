package com.lr.serveurdessin.shapedessin;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

/**
* une cellule de COR de dessiner, spécial pour dessiner un cercle 
* @author samuel
*
*/
public class CercleDessin extends ShapeDessin {
	
	/**
	 * Méthode principal pour dessiner un cercle
	 * @param type Le type de forme
	 * @param params Le data pour dessiner un cercle
	 * @param startI L'indexation commencé pour dessiner ce cercle
	 * @param g le Graphics
	 */
	@Override
	public void draw( int type, String[] params, int[] startI, Graphics g ) {
		if ( type == ShapeType.CERCLE.getId() ) {
			int start = startI[ 0 ];
			double centerX = Double.parseDouble( params[ start + 1 ].trim() );
			double centerY = Double.parseDouble( params[ start + 2 ].trim() );
			double radius = Double.parseDouble( params[ start + 3 ].trim() );
			int color = Integer.parseInt( params[ start + 4 ].trim() );

			//avancer startI par le params count
			startI[ 0 ] += 5;
			
			Graphics2D g2 = (Graphics2D)g;
			Color origColor = g2.getColor();

			g2.setColor( Color3.getColorById( color ) );
			
			double leftUpperX = centerX - radius;
			double leftUpperY = centerY - radius;
			Ellipse2D ellipse = new Ellipse2D.Double( leftUpperX, leftUpperY, radius, radius );
			g2.draw( ellipse );
			
			g2.setColor( origColor );
		} else {
            this.successor.draw( type, params, startI, g );
		}
	} 
}