package com.lr.serveurdessin.shapedessin;

import java.awt.Graphics;

/**
 * Une cha�ne de Responsabilit�(COR en anglais) pour dessiner les formes
 * @author samuel
 *
 */
public abstract class ShapeDessin {
	/** Le successeur **/
	protected ShapeDessin successor = null;
	
	/** Le pr�d�cesseur **/
	protected ShapeDessin predecessor = null;
	
	/**
	 * Prendre la t�te de cette COR
	 * @return La t�te de ceete COR
	 */
	public ShapeDessin getHead() {
		ShapeDessin head = this;
		while ( head.predecessor != null ) {
			head = head.predecessor;
		}
		return head;
	}
	
	/**
	 * Mettre � jour le successeur 
	 * @param successor
	 */
	public void setSuccessor( ShapeDessin successor ) {
		this.successor = successor;
	}
	
	/**
	 * Mettre � jour le pr�d�cesseur
	 * @param predecessor
	 */
	public void setPredecessor( ShapeDessin predecessor ) {
		this.predecessor = predecessor;
	}

	/**
	 * M�thode principal pour dessiner les formes 
	 * @param type Le type de forme
	 * @param params Le data pour dessiner un forme
	 * @param startI L'indexation commenc� pour dessiner ce forme
	 * @param g le Graphics
	 */
	public abstract void draw( int type, String[] params, int[] startI, Graphics g );
}
