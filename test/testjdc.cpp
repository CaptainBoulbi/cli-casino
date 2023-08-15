#include <iostream>
#include "jdc.hpp"

int main(){
	JDC jdc;
	jdc.init();

	jdc.shuffle();
	jdc.display();
	jdc.shuffle();
	jdc.display();
    
	carte c = jdc.top();
	std::cout << "c : " << c.valeur << '+' << c.couleur << std::endl;
	std::cout << jdc.length() << std::endl;
	c = jdc.pop();
	std::cout << "c : " << c.valeur << '+' << c.couleur << std::endl;
	std::cout << jdc.length() << std::endl;
    
	c = jdc.get(0);
	std::cout << "c : " << c.valeur << '+' << c.couleur << std::endl;
	std::cout << jdc.length() << std::endl;
    
	jdc.display();
	std::cout << jdc.length() << std::endl;
    
	jdc.push({K, COEUR});
	jdc.display();
	std::cout << jdc.length() << std::endl;
    
	c = jdc.get(0);
	std::cout << "bottom = " << jdc.valeur(c) << jdc.couleur(c) << std::endl;
	c = jdc.get(2);
	std::cout << "2 = " << jdc.valeur(c) << jdc.couleur(c) << std::endl;
    
	c = jdc.top();
	std::cout << "top = " << jdc.valeur(c) << jdc.couleur(c) << std::endl;
	//std::cout << jdc.couleur(jdc.top()).length() << std::endl;

	//std::cout << "\033[1;48;5;22m" << std::endl;
	//for (int y=0; y<52; y++){
	//	std::string* ss = jdc.ascii(jdc.get(y));
	//	for (int i=0; i<3; i++){
	//		std::cout << "\033[1;48;5;22;38;5;235m" << ss[i] << std::endl;
	//	}
	//}
	//std::cout << "\033[0m" << std::endl;
	
	return 0;
}
