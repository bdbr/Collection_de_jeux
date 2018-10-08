#include "taquin.hpp"
#include "jeu2048.hpp"
#include "TwoThreeFive.hpp"
#include "TilesNegatives.hpp"

using namespace std;
ostream& operator<<(ostream& out,Case<int> c){
    if(c.val<10)
        out <<"  "<< c.val<<" ";
    else if(c.val<100)
        out <<" "<< c.val<<" ";
    else if(c.val<1000)
        out <<" "<< c.val;
    else
        out <<c.val;
    return out;
    return out;
}

int readInt(){
    int x;
    std::cin >> x;
    
    while(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Vous devez entrer un entier!\n";
    std::cin >> x;
    }
    return x;
    
        
    

}

void lancer2048(){
    cout<<"Entrez la taille de la grille: "<<endl;
    
            int n=readInt();

            cout << "Enter 1 pour le mode joueur ou n'importe quel autre nombre pour le mode robot: " << endl;
            int md =readInt();
            
            jeu2048 g(n,n,md);

	    if (md ==1) {
            cout <<"Choisissez u pour effectuer un mouvement vers le haut."<<endl;
            cout <<"Choisissez d pour effectuer un mouvement vers le bas."<<endl;
            cout <<"Choisissez l pour effectuer un mouvement vers la gauche."<<endl;
            cout <<"Choisissez r pour effectuer un mouvement vers la droite."<<endl;
            g.affichage();
          g.play();
        }else {
          g.play();
        }

}

void lancer2048OneTwoThree(){
    cout<<"Entrez la taille de la grille: "<<endl;
    
            int n=readInt();

            cout << "Enter 1 pour le mode joueur ou n'importe quel autre nombre pour le mode robot: " << endl;
            int md =readInt();
            
            TwoThreeFive g(n,n,md);

	    if (md ==1) {
            cout <<"Choisissez u pour effectuer un mouvement vers le haut."<<endl;
            cout <<"Choisissez d pour effectuer un mouvement vers le bas."<<endl;
            cout <<"Choisissez l pour effectuer un mouvement vers la gauche."<<endl;
            cout <<"Choisissez r pour effectuer un mouvement vers la droite."<<endl;
            g.affichage();
          g.play();
        }else {
          g.play();
        }

}

void lancer2048Negative(){
    cout<<"Entrez la taille de la grille: "<<endl;
    
            int n=readInt();

            cout << "Enter 1 pour le mode joueur ou n'importe quel autre nombre pour le mode robot: " << endl;
            int md =readInt();
            
            jeu2048NEGATIVE g(n,n,md);

	    if (md ==1) {
            cout <<"Choisissez u pour effectuer un mouvement vers le haut."<<endl;
            cout <<"Choisissez d pour effectuer un mouvement vers le bas."<<endl;
            cout <<"Choisissez l pour effectuer un mouvement vers la gauche."<<endl;
            cout <<"Choisissez r pour effectuer un mouvement vers la droite."<<endl;
            g.affichage();
          g.play();
        }else {
          g.play();
        }

}


void lancerTaquin(){
    srand(time(0));
    cout<<"Entrez la taille de la grille,\nrow: ";
	  
    int n = readInt();
          
    cout<<"columns: ";
    
    
    int nn = readInt();
    cout << "Enter 1 pour le mode joueur ou n'importe quel autre nombre pour le mode robot: " << endl;
		
    int md = readInt();
    taquin g(n,nn,md);
         	

    if (md ==1) {
        cout <<"Utilisez les touches j,i,k et l pour vous deplacer."<<endl;
        g.affichage();
        g.play();
    }else {
        g.play();
    }
    
}

void choixJeux(){
    int nid;
    while(true){
        cout<<"Bienvenu!\nA quel jeu voulez-vous jouer?"<<endl;
        cout<<ID_TAQUIN<<")taquin"<<endl;
        cout<<ID_JEU2048<<")2048"<<endl;
        cout<<ID_JEU2048NEGATIVE<<")2048 avec valeur negative"<<endl;
        cout<<ID_JEU2048V2<<")2048 avec puissance de 2,3 et 5"<<endl;
        char cid=getchar();
        nid = (int)((char)cid - '0');
          
        if(nid == ID_TAQUIN|| nid == ID_JEU2048||nid==ID_JEU2048V2|| nid==ID_JEU2048NEGATIVE)
                break;
    }
    if(nid==ID_TAQUIN)
        lancerTaquin();
    else if(nid==ID_JEU2048)
        lancer2048();
    else if(nid==ID_JEU2048V2)
        lancer2048OneTwoThree();
     else if(nid==ID_JEU2048NEGATIVE)
        lancer2048Negative();
}

int main(){
    srand(time(0));
    choixJeux();
    
    return 0;
}
