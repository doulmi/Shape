package com.lr.serveurdessin.shapedessin;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;

/**
 * une cellule de COR de dessiner, spécial pour dessiner un segment
 * @author samuel
 *
 */
public class SegmentDessin extends ShapeDessin{

	/**
	 * méthode principal pour dessiner un segment
	 * @param type le type de forme
	 * @param params le data pour dessiner un segment
	 * @param startI l'indexation commencé pour dessiner ce segment
	 * @param g le graphics
	 */
	@Override
	public void draw( int type, String[] params, int[] startI, Graphics g ) {
		if( type == ShapeType.SEGMENT.getId() ) {
			int start = startI[ 0 ];
			//préparation : convertir les chaînes caractère aux chiffres
			double x1 = Double.valueOf( params[ start + 1 ].trim() );
			double y1 = Double.valueOf( params[ start + 2 ].trim() );
			double x2 = Double.valueOf( params[ start + 3 ].trim() );
			double y2 = Double.valueOf( params[ start + 4 ].trim() );
			int color = Integer.valueOf( params[ start + 5 ].trim() );
			
			//avancer startI par le params count
			startI[ 0 ] += 6;
			
			//dessiner
			Graphics2D g2 = (Graphics2D)g;
			Color origColor = g2.getColor();

			g2.setColor( Color3.getColorById( color ) );
			Line2D line = new Line2D.Double( x1, y1, x2, y2 );
			g2.draw( line );
			
			g2.setColor( origColor );
		} else {
			this.successor.draw( type, params, startI, g );
		}
	}
}
