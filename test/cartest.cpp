#include <iostream>
#include "carte.hpp"

int main(){
	carte c = {III, TREFLE};
	if (c.valeur == 3 && c.couleur == TREFLE) std::cout << "\033[32mOK\033[0m" << std::endl;
	
	return 0;
}
