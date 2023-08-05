#ifndef CARTE_HPP
#define CARTE_HPP

enum VCarte{
	II = 2,
	III,
	IV,
	V,
	VI,
	VII,
	VIII,
	IX,
	T,
	J,
	Q,
	K,
	A,
};

enum CCarte{
	PIC,
	CARREAU,
	COEUR,
	TREFLE,
};

struct carte{
	VCarte valeur;
	CCarte couleur;
};

#endif
