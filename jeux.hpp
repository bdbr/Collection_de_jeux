#ifndef JEU
#define JEU

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cstring>


#include "case.hpp"

template <class T>
class jeux{
protected:
	Case<T>** grid;
	int row;
        int columns;
        const int mode;



public:
	
	
jeux(int n,int c,int m):grid(new Case<int>*[n*c]),row(n),columns(c),mode(m){}

~jeux(){
        for(int i = 0;i<row*columns;i++)
        delete grid[i];
     delete[] grid;
     

}

void affichage()const{

        for(int i=0;i<row;i++){
			
                for(int j=0;j<columns;j++){
                    cout << (*grid[i*columns+j])<< " ";
                }
                cout <<endl;
			
	}
	cout <<"----------------------------------------"<<endl;

}
	
	int generateRandomValue(int n){

	return rand()%n;
}
	virtual bool aGagner()const=0;
        virtual bool aPerdu()const=0;
    
         virtual void play()=0;
        virtual char randomMove() = 0;
    
    

};

#endif
