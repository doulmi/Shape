#ifndef __NO_COPYABLE_H__
#define __NO_COPYABLE_H__

/**
 * Les sub-classes de ce classe ne peut pas étre copier
 */
class NoCopyable {
protected:
	/** Contruit un NoCopyable */
	NoCopyable() {}

	/** Le destruicteur */
	~NoCopyable() {}
private:
	/** Interdit d'appeler le constructeur de recopie */
	NoCopyable( const NoCopyable& );

	/** Interdit d'appeler operator= */ 
	NoCopyable& operator=( const NoCopyable& );
};

#endif	//__NO_COPYABLE_H__