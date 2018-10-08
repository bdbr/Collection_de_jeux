#ifndef JEU2048NEGATIVE
#define JEU2048NEGATIVE

#define ID_JEU2048NEGATIVE 3


#include "jeu2048.hpp"


class jeu2048NEGATIVE:public  jeu2048{

public:
	
	
    jeu2048NEGATIVE(int,int,int);
    virtual ~jeu2048NEGATIVE();
    virtual void newCase();
    virtual void right();
    virtual void left();
    virtual void up();
    virtual void down();
    virtual bool testMove(char)const;

};


#endif
