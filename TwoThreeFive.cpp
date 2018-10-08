 #include "TwoThreeFive.hpp"

TwoThreeFive::TwoThreeFive(int taille,int c,int m):jeu2048(taille,taille,m){
	
	
	for (int i=0; i < taille*taille; i++){
            
            if((*grid[(i/taille)*taille+(i%taille)]).getValue()!=0){
                (*grid[(i/row)*row+(i%columns)]).setValue(((rand()%(columns))?((rand()%(columns)?2:5)):3));
                
            }
            
        }
        


 }
 
 TwoThreeFive::~TwoThreeFive(){}
 
 void TwoThreeFive::newCase(){
	vector<int> vector;
	for(int i=0; i<row;i++)
		for(int j=0;j<row;j++)
			if((*grid[i*columns+j]).getValue()==0)
				vector.push_back(columns * i+j);
        if(vector.size()>0){
	int pos1=vector[generateRandomValue(vector.size())];
	
		  (*grid[pos1/row*row+pos1%columns]).setValue(rand()%(6-2) +2);

        }
}