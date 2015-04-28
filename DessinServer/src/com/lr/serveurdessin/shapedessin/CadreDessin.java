package com.lr.serveurdessin.shapedessin;


import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.Toolkit;

import javax.swing.JComponent;
import javax.swing.JFrame;

/**
 * Un JFrame pour dessiner les formes
 * @author samuel
 *
 */
public class CadreDessin extends JFrame {
	
	/** location par défaut **/
	public static final Point DEFAULT_LOCATION;
	/** largeur par défaut **/
	public static final int DEFAULT_WIDTH;
	/** hauteur par défaut **/
	public static final int DEFAULT_HEIGHT;
	
	static  {
		Toolkit toolkit = Toolkit.getDefaultToolkit();
		Dimension size = toolkit.getScreenSize();
		DEFAULT_WIDTH = size.width / 2;
		DEFAULT_HEIGHT = size.height / 2;
		DEFAULT_LOCATION = new Point( size.width * 1 / 4, size.height * 1 / 4 );
	}
	
	/**
	 * constructeur de cette JFrame 
	 * @param title le titre de ce JFrame
	 * @param params les donnés pour dessiner les formes
	 */
	public CadreDessin( String title, String[] params ) {
		this.setTitle( title );
		this.setSize( DEFAULT_WIDTH, DEFAULT_HEIGHT );
		this.setLocation( DEFAULT_LOCATION );
		
		DrawComponent comp = new DrawComponent( params );
		this.add( comp );
	}
}

/**
 * Le JComponent dans le quel qu'on dessine les formes, on utilise son graphics pour dessiner
 * @author doulmi
 *
 */
class DrawComponent extends JComponent {
	/** la première cellule de COR de dessiner **/
	private ShapeDessin firstSd;
	/** les donnés pour dessiner **/
	private String[] params;

	/**
	 * constructeur 
	 * @param params les donnés pour dessiner
	 */
	public DrawComponent( String[] params ) {
		this.params = params;
		this.firstSd = new SegmentDessin();
		ShapeDessin sd2 = new CercleDessin();
		ShapeDessin sd3 = new PolygonDessin();
		ShapeDessin sd4 = new GroupDessin();
	
		//lier tous les cellules de COR de dessiner
		this.firstSd.setSuccessor( sd2 );
		sd2.setPredecessor( this.firstSd );

		sd2.setSuccessor( sd3 );
		sd3.setPredecessor( sd2 );

		sd3.setSuccessor( sd4 );
		sd4.setPredecessor( sd3 );
	}
	
	@Override
	public void paintComponent( Graphics g ) {
		int type = Integer.parseInt( params[0].trim() );
		try {
			int[] startIndex = new int[2]; 
			startIndex[0] = 0;
			this.firstSd.draw( type, params, startIndex, g );
		} catch ( Exception e ) {
			System.out.println( "Le format du data n'est pas correct" );
		}
	}
}

