#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include "jdc.hpp"

template <typename T>
struct point{
	T y;
	T x;
};

struct sprite{
	char** data;
	int row;
	int col;
};

class Screen{
	public:
		char** screen;

		Screen(int row, int col){
			this->col = col;
			this->row = row;

			this->screen = new char*[row];
			for (int i=0; i<row; i++){
				this->screen[i] = new char[col];
			}
		};

		~Screen(){
			for (int i=0; i<row; i++){
				delete this->screen[i];
			}
			delete this->screen;
		};

		void background(){
			for (int i=0; i<row; i++){
				for (int y=0; y<col; y++){
					if (y%2 && i%2) this->screen[i][y] = 'X';
					else if (!(i%2) && !(y%2)) this->screen[i][y] = 'X';
					else this->screen[i][y] = 'O';
					//this->screen[i][y] = 'X';
				}
			}
		};

		void display(){
			std::cout << "\033[1;48;5;22m" << std::endl;
			for (int i=0; i<row; i++){
				for (int y=0; y<col; y++){
					std::cout << this->screen[i][y];
				}
				std::cout << std::endl;
			}
			std::cout << "\033[0m" << std::endl;
		}

		void addCard(point<int> p, carte c){
			this->screen[p.x][p.y] = '+';
			this->screen[p.x][p.y+3] = '+';
			this->screen[p.x+2][p.y+3] = '+';
			this->screen[p.x+2][p.y] = '+';

			this->screen[p.x][p.y+1] = '-';
			this->screen[p.x][p.y+2] = '-';
			this->screen[p.x+2][p.y+1] = '-';
			this->screen[p.x+2][p.y+2] = '-';

			this->screen[p.x+1][p.y] = '|';
			this->screen[p.x+1][p.y+3] = '|';

			this->screen[p.x+1][p.y+1] = JDC::valeur(c);
			this->screen[p.x+1][p.y+2] = JDC::couleur(c);
		};

		//void addSprite(point<int> p, sprite s){};

		int ligne(){
			return this->row;
		}

		int colone(){
			return this->col;
		}
	private:
		int row;
		int col;
};

#endif
