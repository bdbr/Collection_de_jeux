#ifndef JEU2048V2
#define JEU2048V2

#define ID_JEU2048V2 4



#include "jeu2048.hpp"


class TwoThreeFive:public  jeu2048{

public:
	
	
    TwoThreeFive(int,int,int);
    virtual ~TwoThreeFive();
    virtual void newCase();
    

};


#endif
