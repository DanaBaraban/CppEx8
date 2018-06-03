#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include "BoardMem.cpp"
#include "IllegalBoardMemException.cpp"

using namespace std;

class Board{
	public:
		int len;	
		int size() const{return len;};
		vector<vector<BoardMem> > board;
		Board();
		Board(int size);
		Board(const Board &b2);
		//BoardMem& operator[](list<int> j);
		//BoardMem& operator[](BoardMem crdn);
		friend ostream& operator<< (ostream& os, const Board& b);
		Board& operator= (char n);
		Board& operator= (Board n);
		//BoardMem & operator[](BoardMem crdn);
		
		BoardMem & operator[](BoardMem const &crdn) ;
		BoardMem operator[](BoardMem const &crdn) const{
			
			int x1 = crdn.row;
			int x2 = crdn.col;
			
			if(x1>=len || x2>=len || x1<0 || x2<0){
				IllegalBoardMemException ie(x1,x2);
				throw ie;
			}
			return this->board[x1][x2];
		}
		
		friend istream &operator>>( istream  &input, Board &D );
		void init(string s);
		
		string draw(int dim);
		struct RGB {
	  uint8_t red, green, blue;
		public:
	  RGB() {}
	  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
		};
		
		private:
		void putpixel(int x, int y, int dim, RGB *ima);
		void drawcircle(int x0, int y0, int radius, int dim, RGB *ima);
		void drawx(int x0, int y0, int radius, int dim, RGB *ima);
		void paint(string filename ,int dim) ;
		
		bool exist(const string& name);
		string fileName (const string& name);

};