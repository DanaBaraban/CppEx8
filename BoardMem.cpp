
#include <iostream>
#include "IllegalCharException.cpp"
using namespace std;



class BoardMem {
    public:
    int row; 
    int col;
    char val;

        BoardMem(int row, int col, char val){
            this->row=row;
            this->col=col;
            this->val=val;
        }

        friend ostream& operator << ( ostream& op, const BoardMem& bo){
            op << bo.val; 
            return op; 
        }

        BoardMem& operator = (char c){

            if (c != 'O' && c != '.' && c!= 'X'){
            IllegalCharException ex(c);
            throw ex;
        }

            val = c; 
            return (*this);
        }

        operator char (){
           return val;
        }

        const bool operator == (const char c)const{
            return val == c;
        }

};

