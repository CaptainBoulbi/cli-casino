#include <iostream>
#include "screen.hpp"
#include "jdc.hpp"

int main(){
	int row = 5;
	int col = 11;
	Screen s(row, col);
	s.background();
	s.display();

	JDC jdc;
	jdc.init();
	jdc.shuffle();

	point<int> p = {0, 0};
	s.addCard(p, jdc.top());
	s.display();

	p = {col-4, row-3};
	s.addCard(p, CARTERETOURNE);
	s.display();
}
