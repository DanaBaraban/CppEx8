
#include <iostream>
#include <string>
using namespace std;


class IllegalCoordinateException {
    public:

    int cor1; 
    int cor2; 

    IllegalCoordinateException(int i, int j){
        cor1 = i; 
        cor2 = j; 
    }

    string theCoordinate() const{
        return to_string(cor1) +","+  to_string(cor2);
    }
    

};

