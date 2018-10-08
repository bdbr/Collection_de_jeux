
#include "taquin.hpp"

using namespace std;
taquin::taquin(int n,int c,int m):jeux(n,c,m){
    std::vector<int> it;
    for(int i=0;i<n*c;i++){
        it.push_back(i);
        //grid[i] = new Case();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<c;j++){
            	
            
            int x = (rand() % it.size());
            int v = it.at(x);
            grid[i*c+j] = new Case<int>(v);
            it.erase(it.begin()+x);
            if(v==0){
                posX = i;
                posY = j;
            }
        }
        
    }
    
    
}


bool  taquin::deplacer(char a){
    switch(a){
        case 'k':
            if(posX==row-1)
                return false;
            grid[posX*columns+posY]->setValue(grid[(posX+1)*columns+posY]->getValue());
            grid[(posX+1)*columns+posY]->setValue(0);
            posX = posX+1;
            return true;
         case 'i':
            if(posX==0)
                return false;
            grid[posX*columns+posY]->setValue(grid[(posX-1)*columns+posY]->getValue());
            grid[(posX-1)*columns+posY]->setValue(0);
            posX = posX-1;
            return true;
         case 'l':
            if(posY==columns-1)
                return false;
            grid[posX*columns+posY]->setValue(grid[posX*columns+posY+1]->getValue());
           grid[posX*columns+posY+1]->setValue(0);
            posY = posY+1;
            return true;
        case 'j':
            if(posY==0)
                return false;
            grid[posX*columns+posY]->setValue(grid[posX*columns+posY-1]->getValue());
            grid[posX*columns+posY-1]->setValue(0);
            posY = posY-1;
            return true;
        default:
            return false;
    }
    
}

char taquin::randomMove(){
    char t[4]= {'j','i','k','l'};
    int r = std::rand() % 4;
    return t[r];
    
}
bool taquin::aGagner()const{
    int cpt=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<columns;j++){
            if(grid[i*row+j]->getValue()!=cpt){
                return false;
            }
            if(i==columns-1&&j==columns-1&&grid[i*columns+j]->getValue()==0){
                return true;
            }
            cpt++;
        }
    }
    return true;
    
}
bool taquin::aPerdu()const{return false;}
 void taquin::play(){
    while(true){
        if(aGagner())
            break;
        char input;
        if(mode==1){
         input=getchar();
        cout<< "Pour vous deplacer une case 'j', 'k', 'l'ou 'i':"<<endl;
                    cin>>input;
                    deplacer(input);
        
        }else{
             input = randomMove();
             deplacer(input);
            
        }
        
        affichage();
        
        
    }
}
taquin::~taquin(){}


