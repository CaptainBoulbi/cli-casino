#include <iostream>
#include "screen.hpp"
#include "jdc.hpp"

int main(){
	Screen s(11, 5);
	s.background();
	s.display();

	JDC jdc;
	jdc.init();
	jdc.shuffle();

	point<int> p = {0, 0};
	//sprite card = {jdc.ascii(jdc.top()), 3, 4};
	s.addCard(p, jdc.top());

	//card = {jdc.ascii(NULL), 3};
	p = {0, 12};
	s.addCard(p, jdc.get(0));

	s.display();
}
