#ifndef __VEC2_H__
#define __VEC2_H__

/**
 * Defines un 2-element double point vecteur.
 */
class Vec2 {
public:
	/** La coordonnée x */
	double x;
	/** La coordonnée y */
	double y;

	/**
	 * Construit un nouveau vecteur initialisé à zéro
	 *
	 */
	Vec2();

	/**
     * Construit un nouveau vecteur initialisé aux valeurs spécifiées.
     * @param iX La coordonnée x.
     * @param iY La coordonnée y.
	 */
	explicit Vec2( const double iX, const double iY );

	/**
     * Construit un nouveau vecteur qui est une copie du vecteur spécifié.
     *
     * @param copy Le vecteur à copier.
     */
	Vec2( const Vec2& copy );

	Vec2& operator=( const Vec2& rhs );

	/**
	 * destructeur
	 */
	~Vec2();

	 /**
     * vérifie si ce vecteur ne contient que de zéro.
     *
     * @return vrai si ce vecteur ne contient que de zero, sinon faux
     */
    bool isZero() const;

    /**
     * La négation de ce vecteur.
     */
    void negate();

	/**
     * Ajoute les éléments du vecteur spécifié pour celui-ci.
     *
     * @param v Le vecteur à ajouter
     */
	void add( const Vec2& v ) ;

	/**
     * Soustrait ce vecteur et le vecteur spécifié que (ce - v)
	 * et stocke le résultat dans ce vecteur.
     *
     * @param v Le vecteur à soustraire.
     */
	void subtract( const Vec2& v );

	/**
     * Définit les éléments de ce vecteur à des valeurs spécifiées.
     *
     * @param xx La nouvelle coordonné x
     * @param yy La nouvelle coordonné y
     */
    void set(double xx, double yy);


	/**
     * Définit les éléments de ce vecteur à des valeurs spécifiées
     *
     * @param v le vecteur à copier
     */
    void set(const Vec2& v);

	/**
     * Calcule la somme de ce vecteur avec le vecteur donné.
     * 
     * Note: cette operation ne modifie pas ce vecteur.
     * 
     * @param v Le vecteur à ajouter.
     * @return Le vecteur de somme.
     */
    inline const Vec2 operator+(const Vec2& v) const;

	 /**
     * Ajoute le vecteur donné à ce vecteur.
     * 
     * @param v Le vecteur à ajouter..
     * @return Ce vecteur, après cette operation
     */
    inline Vec2& operator+=(const Vec2& v);

	/**
     * Calcule la rest de ce vecteur avec le vecteur donné
     * 
     * Note: cette operation ne modifie pas ce vecteur.
     * 
     * @param v Le vecteur à soustraire
     * @return The vector rest.
     */
    inline const Vec2 operator-(const Vec2& v) const;

	/**
     * Soustrait le vecteur donné de ce vecteur.
     * 
     * @param v Le vecteur de soustraire.
     * @return Ce vecteur, après la soustraction produit.
     */
    inline Vec2& operator-=(const Vec2& v);

	 /**
     * Calcule le produit scalaire de ce vecteur avec la valeur donnée.
     * 
     * Note: cette operation ne modifie pas ce vecteur.
     * 
     * @param s le ratio
     * @return le vecteur après cette operation
     */
    inline const Vec2 operator*(double s) const;

	 /**
     * Calcule le produit scalaire de ce vecteur avec la valeur donnée.
     * 
     * @param s le ratio
     * @return ce vecteur après cette operation
     */
    inline Vec2& operator*=(double s);

	/**
     * Verifie si ce vecteur est égal au vecteur donné.
     * 
     * @param v Le vecteur à comparer.
     * 
     * @return Vrai si ce vecteur est égal au vecteur donné, sinon faux
     */
    inline bool operator==(const Vec2& v) const;

    /**
     * Verifie si ce vecteur n'est pas égal au vecteur donné.
     * 
     * @param v Le vecteur à comparer.
     * 
     * @return Vrai si ce vecteur n'est pas égal au vecteur donné, sinon faux 
     */
    inline bool operator!=(const Vec2& v) const;

    /**
     * Faire une rotation pour ce vector par l'angle (en radians) autour du point donne
     * @param center le centre de la rotation
     * @param angle l'angle à rotater (en radians).
     */
    void rotate(const Vec2& center, double angle);

	/**
	 * Une homothétie est définie par un point invariant et par un rapport d'homothétie
	 * @param point le center pour cette homothétie
	 * @radio radio pour cette homothétie
	 */
	void scale( const Vec2& point, double radio );

	/**
	 * Une homothétie est définie par un point invariant et par un rapport d'homothétie
	 * @radio radio pour cette homothétie
	 */
	void Vec2::scale( double radio );

	/** égal à Vec2(0,0) */
	static const Vec2 ZERO;

	/** égal à Vec2(1,1) */
	static const Vec2 ONE;
};


inline Vec2& Vec2::operator=( const Vec2& rhs ) {
	x = rhs.x;
	y = rhs.y;
	return *this;
}

inline const Vec2 Vec2::operator+(const Vec2& v) const
{
	Vec2 result(*this);
	result.add(v);
	return result;
}

inline Vec2& Vec2::operator+=(const Vec2& v)
{
	add(v);
	return *this;
}

inline const Vec2 Vec2::operator-(const Vec2& v) const
{
	Vec2 result(*this);
	result.subtract(v);
	return result;
}

inline Vec2& Vec2::operator-=(const Vec2& v)
{
	subtract(v);
	return *this;
}

inline const Vec2 Vec2::operator*(double s) const
{
	Vec2 result(*this);
	result.scale( Vec2::ZERO, s);
	return result;
}

inline Vec2& Vec2::operator*=(double s) {
	scale( Vec2::ZERO, s);
	return *this;
}

inline bool Vec2::operator==(const Vec2& v) const {
	return x==v.x && y==v.y;
}

inline bool Vec2::operator!=(const Vec2& v) const {
	return x!=v.x || y!=v.y;
}

inline const Vec2 operator*(double x, const Vec2& v) {
	Vec2 result(v);
	result.scale( Vec2::ZERO, x);
	return result;
}

typedef Vec2 Point;
#endif //__VECTOR_H__