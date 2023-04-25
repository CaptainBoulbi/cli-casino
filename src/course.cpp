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

enum CCouleur{
	trefle,
	pique,
	coeur,
	carreau,
};

struct carte{
	CValeur valeur;
	CCouleur couleur;
};

void printCarte(const carte& c){
	switch (c.valeur){
		case II:
			std::cout << '2';
			break;
		case III:
			std::cout << '3';
			break;
		case IV:
			std::cout << '4';
			break;
		case V:
			std::cout << '5';
			break;
		case VI:
			std::cout << '6';
			break;
		case VII:
			std::cout << '7';
			break;
		case VIII:
			std::cout << '8';
			break;
		case IX:
			std::cout << '9';
			break;
		case X:
			std::cout << "10";
			break;
		case J:
			std::cout << 'J';
			break;
		case Q:
			std::cout << 'Q';
			break;
		case K:
			std::cout << 'K';
			break;
		case A:
			std::cout << 'A';
			break;
		default:
			std::cout << '?';
			break;
	}
	switch (c.couleur){
		case trefle:
			std::cout << 't';
			break;
		case pique:
			std::cout << 'p';
			break;
		case carreau:
			std::cout << 'k';
			break;
		case coeur:
			std::cout << 'c';
			break;
		default:
			std::cout << '?';
			break;
	}
}

int main(){
	carte jc[52];
	
	int x = 0;
	for (int i=0; i<4; i++){
		for (int y=0; y<13; y++){
			jc[x].valeur = CValeur(y);
			jc[x].couleur = CCouleur(i);
			x++;
		}
	}

	printCarte(jc[0]);
	for (int i=1; i<52; i++){
		if (!(i%13)){
			std::cout << std::endl;
		}else{
			std::cout << " - ";
		}
		printCarte(jc[i]);
	}
	std::cout << std::endl;

	return 0;
}
