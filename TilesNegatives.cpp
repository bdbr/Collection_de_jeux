
#include "TilesNegatives.hpp"


jeu2048NEGATIVE::jeu2048NEGATIVE(int taille,int c,int m):jeu2048(taille,taille,m){
    
    for (int i=0; i < taille*taille; i++){
            
        if((*grid[(i/taille)*taille+(i%taille)]).getValue()!=0){
            (*grid[i/row*row+i%columns]) = rand()%2?-2:2?4:-4;
            //(*grid[(i/row)*row+(i%columns)]).setValue((*grid[(i/row)*row+(i%columns)]).getValue()*((rand()%(taille))?-1:1));
                
        }
            
    }
	
}
 
jeu2048NEGATIVE::~jeu2048NEGATIVE(){}


bool jeu2048NEGATIVE::testMove(char input)const{
   
	switch(input){
 		case 'u':
			for(int j=0;j<columns;j++){
				for(int i=0; i<row;i++){
					if(i==0){
                                          
						if((*grid[i*columns+j]).getValue()==0)
							return true;
					}
					else{

						if((*grid[i*columns+j]).getValue()==0 || (*grid[i*columns+j]).getValue()==(*grid[(i-1)*columns+j]).getValue()
                                                    ||(*grid[i*columns+j]).getValue()==-(*grid[(i-1)*columns+j]).getValue()
                                                )
							return true;
					}
				}

			}
			return false;
			case 'l':
				for(int i=0;i<row;i++){
					for(int j=0; j<columns; j++){
						if(j==0){
						if((*grid[i*columns+j]).getValue()==0)
							return true;
					}
					else{

						if((*grid[i*columns+j]).getValue()==0|| (*grid[i*columns+j]).getValue()==(*grid[i*columns+(j-1)]).getValue()
                                                    ||-(*grid[i*columns+j]).getValue()==(*grid[i*columns+(j-1)]).getValue()
                                                )
							return true;
					}
				}
			}
				return false;
			case 'd':

			for(int j=0;j<columns;j++){
					for(int i=row-1; i>-1; i--){
						if(i==row-1){
						if((*grid[i*columns+j]).getValue()==0)
							return true;
					}
					else{

						if((*grid[i*columns+j]).getValue()==0|| (*grid[i*columns+j]).getValue()==(*grid[(i+1)*columns+j]).getValue()
                                                    || (*grid[i*columns+j]).getValue()==-(*grid[(i+1)*columns+j]).getValue()
                                                )
							return true;
					}
				}
			}
				return false;

			case 'r':

			for(int i=0;i<row;i++){
					for(int j=columns-1; j>-1; j--){
						if(j==columns-1){
						if((*grid[i*columns+j]).getValue()==0)
							return true;
					}
					else{

						if((*grid[i*columns+j]).getValue()==0|| (*grid[i*columns+j]).getValue()==(*grid[i*columns+(j+1)]).getValue()
                                                    ||(*grid[i*columns+j]).getValue()==-(*grid[i*columns+(j+1)]).getValue()
                                                )
							return true;
					}
				}
			}
				return false;
				default:
				return false;
	}
}
void jeu2048NEGATIVE::up(){
        bool move = false;
	 for(int j=0;j<columns;j++)
		{
			nFusion=0;
			for(int i=0;i<row;i++)
			{
                while(true)
				{

					if(i == 0) 
                       	break;     


                        if((*grid[i*columns+j]).getValue() == -(*grid[(i-1)*columns+j]).getValue() && (*grid[i*columns+j]).getValue() !=0 && nFusion <= maxFusion){
                        (*grid[(i-1)*columns+j]).setValue(0);
                        (*grid[i*columns+j]).setValue(0);
                        nFusion++;
                         move = true;
                    }

                    else if((*grid[i*columns+j]).getValue() == (*grid[(i-1)*columns+j]).getValue() && (*grid[i*columns+j]).getValue() !=0 && nFusion <= maxFusion){
                        (*grid[(i-1)*columns+j]).setValue((*grid[(i-1)*columns+j]).getValue() + (*grid[i*columns+j]).getValue());
                        (*grid[i*columns+j]).setValue(0);
                        nFusion++;
                         move = true;
                    }
                    else { 
                        if ((*grid[i*columns+j]).getValue() !=0 && (*grid[(i-1)*columns+j]).getValue() == 0){ ///If the cell above is empty
                            (*grid[(i-1)*columns+j]).setValue((*grid[i*columns+j]).getValue());
                            (*grid[i*columns+j]).setValue(0);
                            move = true;
                            i--;

                        }
                        else 
                            break;
					}
					
				}
				
			}
		}
		if(move)
                    newCase();

	
}


void jeu2048NEGATIVE:: left(){
        bool move=false;
	for(int i=0;i<row;i++)
		{
			for(int j=0;j<columns;j++)
			{
				while(true)
				{
					if(j==0)
						break;


					if((*grid[i*columns+j]).getValue() == -(*grid[i*columns+(j-1)]).getValue() && (*grid[i*columns+j]).getValue() !=0 && nFusion <= maxFusion){
                    (*grid[i*columns+(j-1)]).setValue(0);
                    (*grid[i*columns+j]).setValue(0);
                    nFusion++;
                     move = true;
                    }

                    else if((*grid[i*columns+j]).getValue() == (*grid[i*columns+(j-1)]).getValue() && (*grid[i*columns+j]).getValue() !=0 && nFusion <= maxFusion){
                        (*grid[i*columns+(j-1)]).setValue((*grid[i*columns+(j-1)]).getValue() + (*grid[i*columns+j]).getValue());
                        (*grid[i*columns+j]).setValue(0);
                        nFusion++;
                         move = true;
                    }
                    else { 
                        if ((*grid[i*columns+j]).getValue() !=0 && (*grid[i*columns+(j-1)]).getValue() == 0){ ///If the cell above is empty
                            (*grid[i*columns+(j-1)]).setValue((*grid[i*columns+j]).getValue());
                            (*grid[i*columns+j]).setValue(0);
                        
                            j--;
                                move = true;
                            }
                        else 
                            break;

			}
		}
	}
    }
    if(move)
        newCase();

	
}

    
void jeu2048NEGATIVE::down(){
        bool move = false;
        for(int j=0;j<columns;j++){
		nFusion=0;
		for(int i=row-1;i>-1;i--){
                    while(true){
                      

			if(i==row-1)
                                break;
                        
			       if((*grid[i*columns+j]).getValue() == -(*grid[(i+1)*columns+j]).getValue() && (*grid[i*columns+j]).getValue() !=0 && nFusion <= maxFusion){
                    (*grid[(i+1)*columns+j]).setValue(0);
                    (*grid[i*columns+j]).setValue(0);
                    nFusion++;
                     move = true;
                    }

                    else if((*grid[i*columns+j]).getValue() == (*grid[(i+1)*columns+j]).getValue() && (*grid[i*columns+j]).getValue() !=0 && nFusion <= maxFusion){
                        (*grid[(i+1)*columns+j]).setValue((*grid[(i+1)*columns+j]).getValue() + (*grid[i*columns+j]).getValue());
                        (*grid[i*columns+j]).setValue(0);
                        nFusion++;
                         move = true;
                    }
                    else { 
                        if ((*grid[i*columns+j]).getValue() !=0 && (*grid[(i+1)*columns+j]).getValue() == 0){ ///If the cell above is empty
                            (*grid[(i+1)*columns+j]).setValue((*grid[i*columns+j]).getValue());
                            (*grid[i*columns+j]).setValue(0);
                        
                            i++;
                                move = true;
                            }
                        else 
                            break;

                        }
					
                    }
				
                }
        }
        if(move)
            newCase();
}

void jeu2048NEGATIVE::right(){
    bool move = false;
 for(int i=0;i<row;i++)
		{
			nFusion=0;
			for(int j=row-1;j>-1;j--)
			{
                while(true)
				{

					if(j==row-1)
						break;
				
					if((*grid[i*columns+j]).getValue() == -(*grid[i*columns+(j+1)]).getValue() && (*grid[i*columns+j]).getValue() !=0 && nFusion <= maxFusion){
                    (*grid[i*columns+(j+1)]).setValue(0);
                    (*grid[i*columns+j]).setValue(0);
                    nFusion++;
                     move = true;
                    }

                    else if((*grid[i*columns+j]).getValue() == (*grid[i*columns+(j+1)]).getValue() && (*grid[i*columns+j]).getValue() !=0 && nFusion <= maxFusion){
                        (*grid[i*columns+(j+1)]).setValue((*grid[i*columns+(j+1)]).getValue() + (*grid[i*columns+j]).getValue());
                        (*grid[i*columns+j]).setValue(0);
                        nFusion++;
                         move = true;
                    }
                    else { 
                        if ((*grid[i*columns+j]).getValue() !=0 && (*grid[i*columns+(j+1)]).getValue() == 0){ ///If the cell above is empty
                            (*grid[i*columns+(j+1)]).setValue((*grid[i*columns+j]).getValue());
                            (*grid[i*columns+j]).setValue(0);
                        
                            j++;
                                move = true;
                            }
                        else 
                            break;
					}
					
				}
				
			}
		}
		if(move)
                    newCase();
}



void jeu2048NEGATIVE::newCase(){
	vector<int> vector;
	for(int i=0; i<row;i++)
		for(int j=0;j<row;j++)
			if((*grid[i*columns+j]).getValue()==0)
				vector.push_back(columns * i+j);
        if(vector.size()>0){
            int pos1=vector[generateRandomValue(vector.size())];
            (*grid[pos1/row*row+pos1%columns]).setValue(rand()%2?-2:2?4:-4);
}
        }
    
	


 
