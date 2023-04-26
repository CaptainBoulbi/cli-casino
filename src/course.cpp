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
			std::cout << 'd';
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
			std::cout << 'T';
			break;
		case pique:
			std::cout << 'P';
			break;
		case carreau:
			std::cout << 'K';
			break;
		case coeur:
			std::cout << 'C';
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

	// printCarte(jc[0]);
	// for (int i=1; i<52; i++){
	// 	if (!(i%13)){
	// 		std::cout << std::endl;
	// 	}else{
	// 		std::cout << " - ";
	// 	}
	// 	printCarte(jc[i]);
	// }
	// std::cout << std::endl;

	int nvPalier[4];
	nvPalier[trefle] = 5;
	nvPalier[pique] = 6;
	nvPalier[coeur] = 3;
	nvPalier[carreau] = 4;

	carte cartePalier[5];
	cartePalier[0].valeur = II;
	cartePalier[0].couleur = trefle;
	cartePalier[1].valeur = IV;
	cartePalier[1].couleur = pique;
	cartePalier[2].valeur = J;
	cartePalier[2].couleur = pique;
	cartePalier[3].valeur = X;
	cartePalier[3].couleur = coeur;
	cartePalier[4].valeur = IV;
	cartePalier[4].couleur = carreau;

	std::cout << "👑|";
	if (nvPalier[0]>=6){
		std::cout << "■";
	}else{
		std::cout << "_";
	}

	for (int i=1; i<4; i++){
		if (nvPalier[i]==6){
			std::cout << "_■";
		}else{
			std::cout << "__";
		}
	}
	std::cout << "|" << std::endl;

	for (int i=4; i>0; i--){
		printCarte(cartePalier[i]);
		std::cout << '|';
		for (int y=0; y<4; y++){
			if (nvPalier[y]>=i){
				std::cout << "■|";
			}else{
				std::cout << " |";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "‾‾|T|P|C|K|" << std::endl;

	return 0;
}
