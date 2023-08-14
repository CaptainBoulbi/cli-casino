#include <iostream>
#include <unistd.h>
#include <cmath>
#include "screen.hpp"

int main(){
	Screen s(50, 50);
	s.display();
	sleep(1);

	sprite sp = {NULL, 5, 5};
	sp.data = new char*[5];
	for (int i=0; i<5; i++){
		sp.data[i] = new char[5];
		for (int y=0; y<5; y++){
			sp.data[i][y] = '+';
		}
	}

	point<int> p = {22, 22};

	s.addSprite(p, sp);
	s.display();
	sleep(1);

	sprite sp2 = {NULL, 50, 50};
	sp2.data = new char*[50];
	for (int i=0; i<50; i++){
		sp2.data[i] = new char[50];
		for (int y=0; y<50; y+=2){
			sp2.data[i][y] = 'x';
		}
	}

	point<int> p2 = {0, 0};

	s.addSprite(p2, sp2);
	s.display();
	sleep(1);

	sprite sp3 = {NULL, 50, 50};
	sp3.data = new char*[50];
	for (int i=0; i<50; i+=2){
		sp3.data[i] = new char[50];
		sp3.data[i+1] = new char[50];
		for (int y=0; y<50; y++){
			sp3.data[i][y] = 'o';
		}
	}
    
	point<int> p3 = {0, 0};
    
	s.addSprite(p3, sp3);
	s.display();
	sleep(1);

	sprite sp4 = {NULL, 21, 21};
	sp4.data = new char*[21];
	for (int i=0; i<21; i++){
		sp4.data[i] = new char[21];
	}

	float x, y;
	for (float i=0; i<2*3.14; i+=0.1){
		x = (std::cos(i)+1) * 5;
		y = (std::sin(i)+1) * 10;
		sp4.data[(int)x][(int)y] = '@';
	}
    
	point<int> p4 = {14, 2};
    
	s.addSprite(p4, sp4);
	s.display();
	sleep(1);

	sprite sp5 = {NULL, 50, 50};
	sp5.data = new char*[50];
	for (int i=0; i<50; i++){
		sp5.data[i] = new char[50];
		for (int y=0; y<50; y++){
			sp5.data[i][y] = ' ';
		}
	}

	s.addSprite(p2, sp5);
	s.display();
	sleep(1);

	s.addSprite({15, 20}, sp4);
	s.display();
	sleep(1);

	sleep(3);
	return 0;
}
