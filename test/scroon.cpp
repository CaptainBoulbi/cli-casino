#include <iostream>
#include <unistd.h>
#include "screen.hpp"
#include "jdc.hpp"

int main(){
	int row = 5;
	int col = 11;
	Screen s(row, col);
	s.display();
	sleep(1);

	JDC jdc;
	jdc.init();
	jdc.shuffle();
    
	point<int> p = {0, 0};
	s.addCard(p, jdc.top());
	s.display();
	sleep(1);

	s.background();
	s.display();
	sleep(1);
    
	p = {col-4, row-3};
	s.addCard(p, CARTERETOURNE);
	s.display();
	sleep(1);

	return 0;
}
