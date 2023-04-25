#include <iostream>

enum CValeur{
	II,
	III,
	IV,
	V,
	VI,
	VII,
	VIII,
	IX,
	X,
	J,
	Q,
	K,
	A,
};

struct carte{
	CValeur valeur;
};

int main(){

	CValeur val = A;

	std::cout << val << std::endl;

	return 0;
}
