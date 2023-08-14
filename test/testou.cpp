#include <iostream>
#include <unistd.h>
#include <cmath>

int main(){
	int size = 21;
	char** s = new char*[size];
	for (int i=0; i<size; i++){
		s[i] = new char[size];
	}

	float x, y;
	for (float i=0; i<2*3.14; i+=0.1){
		x = (std::cos(i)+1) * 10;
		y = (std::sin(i)+1) * 10;
		std::cout << "cos : " << x << " sin : " << y << std::endl;
		std::cout << (int)x << ';' << (int)y << std::endl;
		s[(int)x][(int)y] = '@';
	}

	for (int i=0; i<size; i++){
		for (int y=0; y<size; y++){
			if (!s[i][y]) std::cout << ' ';
			std::cout << s[i][y];
		}
		std::cout << std::endl;
	}

	return 0;
}
