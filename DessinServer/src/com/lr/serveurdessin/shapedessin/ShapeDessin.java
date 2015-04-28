package com.lr.serveurdessin.shapedessin;

import java.awt.Graphics;

/**
 * Une chaîne de Responsabilité(COR en anglais) pour dessiner les formes
 * @author samuel
 *
 */
public abstract class ShapeDessin {
	/** Le successeur **/
	protected ShapeDessin successor = null;
	
	/** Le prédécesseur **/
	protected ShapeDessin predecessor = null;
	
	/**
	 * Prendre la tête de cette COR
	 * @return La tête de ceete COR
	 */
	public ShapeDessin getHead() {
		ShapeDessin head = this;
		while ( head.predecessor != null ) {
			head = head.predecessor;
		}
		return head;
	}
	
	/**
	 * Mettre à jour le successeur 
	 * @param successor
	 */
	public void setSuccessor( ShapeDessin successor ) {
		this.successor = successor;
	}
	
	/**
	 * Mettre à jour le prédécesseur
	 * @param predecessor
	 */
	public void setPredecessor( ShapeDessin predecessor ) {
		this.predecessor = predecessor;
	}

	/**
	 * Méthode principal pour dessiner les formes 
	 * @param type Le type de forme
	 * @param params Le data pour dessiner un forme
	 * @param startI L'indexation commencé pour dessiner ce forme
	 * @param g le Graphics
	 */
	public abstract void draw( int type, String[] params, int[] startI, Graphics g );
}
