#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <iostream>
#include "jdc.hpp"
#include <sys/ioctl.h>
#include <termios.h>
//#include <unistd.h>

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
			puts("\033[?1049h\033[H"); // alt screen
			puts("\033[?25l"); // inv cursor
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
			puts("\033[?1049l"); // ~ alt screen
			puts("\033[?25h"); // ~ inv cursor
		};

		void background(){
			for (int i=0; i<row; i++){
				for (int y=0; y<col; y++){
					if (this->screen[i][y]) continue;
					if (y%2 && i%2) this->screen[i][y] = 'X';
					else if (!(i%2) && !(y%2)) this->screen[i][y] = 'X';
					else this->screen[i][y] = 'O';
				}
			}
		};

		void display(){
			puts("\033[2J"); // clear screen
			puts("\033[1;48;5;22m"); // bold + background green

			point<int> coord = this->size();
			coord.x = coord.x/2 - col/2;
			coord.y = coord.y/2 - row/2;
			printf("\033[%d;%dH", coord.y, coord.x);

			for (int i=0; i<row; i++){
				for (int y=0; y<col; y++){
					if (this->screen[i][y]) std::cout << this->screen[i][y];
					else std::cout << ' ';
				}
				printf("\033[%d;%dH", coord.y+i+1, coord.x);
			}
			puts("\033[0m"); // reset
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
		};

		int colone(){
			return this->col;
		};

		static point<int> size(){
			point<int> p;
			struct winsize size;
			ioctl(1, TIOCGWINSZ, &size);
			p.x = size.ws_col;
			p.y = size.ws_row;
			return p;
		};
	private:
		int row;
		int col;
};

#endif
