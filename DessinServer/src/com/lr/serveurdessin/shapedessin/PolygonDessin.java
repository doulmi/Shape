package com.lr.serveurdessin.shapedessin;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Path2D;

/**
* une cellule de COR de dessiner, spécial pour dessiner un polygone 
* @author samuel
*
*/
public class PolygonDessin extends ShapeDessin {
	
	/**
	 * Méthode principal pour dessiner un polygone
	 * @param type Le type de forme
	 * @param params Le data pour dessiner un polygone
	 * @param startI L'indexation commencé pour dessiner ce polygone
	 * @param g le Graphics
	 */
	@Override
	public void draw( int type, String[] params, int[] startI, Graphics g ) {
		if( type == ShapeType.POLYGON.getId() ) {
			int start = startI[ 0 ];
			//préparation : convertir les chaînes caractère aux chiffres
			int pointCount = Integer.valueOf( params[ start + 1 ].trim() );
			double[] xpoints= new double[ pointCount ];
			double[] ypoints = new double[ pointCount ];
			
			for ( int i = 0; i < pointCount; i++ ) {
				int ipx = ( i + 1 ) * 2;
				xpoints[ i ] = Double.valueOf( params[ start + ipx ].trim() );
				ypoints[ i ] = Double.valueOf( params[ start + ipx + 1 ].trim() );
			}
			int color = Integer.valueOf( params[ start + pointCount * 2 + 2 ].trim() );
			
			//avancer startI par le params count
			startI[0] += 3 + pointCount * 2;
			
			//dessiner
			Graphics2D g2 = (Graphics2D)g;
			Color origColor = g2.getColor();
			g2.setColor( Color3.getColorById( color ) );
			
			Path2D polygon = new Path2D.Double();
			polygon.moveTo( xpoints[ 0 ], ypoints[ 0 ] );
			for ( int i = 1; i < pointCount; i ++ ) {
				polygon.lineTo( xpoints[ i ], ypoints[ i ] );
			}
			polygon.closePath();
			
			g2.draw( polygon );
			g2.setColor( origColor );
		} else {
			this.successor.draw( type, params, startI, g );
		}
	}

}
