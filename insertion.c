#include "plateau.h"

//Insertion

int possible(Plateau_t plateau, int colonne){ //Verifie si la colonne demander existe
  if(colonne < 0 || colonne >= plateau.colonne)
    return 0;
  return 1;
}

Plateau_t insertion(Plateau_t plateau,int i,char c){
  for(int ligne = plateau.ligne - 1; ligne >= 0; ligne--){
    if(plateau.tab[ligne][i] == '~'){
      plateau.tab[ligne][i] = c;
      return plateau;
    }
  }
  return plateau;
}

int colonne_complete(Plateau_t plateau,int i){
  for(int ligne = 0; ligne < plateau.ligne; ligne++)
    if(plateau.tab[ligne][i] == '~')
      return 0;
  return 1;
}

