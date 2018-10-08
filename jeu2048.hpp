#ifndef JEU2048
#define JEU2048

#define ID_JEU2048 2

#include "jeux.hpp"



class jeu2048:public jeux<int>{
protected:
	
        int nFusion;
	int maxFusion;
       



public:
	
	
	jeu2048(int,int,int);
        virtual ~jeu2048();
	virtual void right();
	virtual void left();
	virtual void up();
	virtual void down();
	virtual bool aGagner()const;
        virtual bool aPerdu()const;
        virtual char randomMove();
        virtual void newCase();
        virtual void play();
        bool testMove(char)const;
    

};


#endif
