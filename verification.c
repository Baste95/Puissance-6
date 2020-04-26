#include "plateau.h"

int alignerM1 = ALIGNER - 1;
//Verification

int match_nul(Plateau_t plateau){
  for(int ligne = 0; ligne < plateau.ligne; ligne++)
    for(int colonne = 0; colonne < plateau.colonne; colonne++)
      if(plateau.tab[ligne][colonne] == '~')
	return 0;
  return 1;
}

int horizontal(Plateau_t plateau, char c){//Ligne de 6 pions
  int compteur, i;
  for(int ligne = 0; ligne < plateau.ligne; ligne++)
    for(int colonne = alignerM1; colonne < plateau.colonne; colonne++){
      compteur = 0;
      for(i = 0; i < ALIGNER; i++){
	if(plateau.tab[ligne][colonne - i] == c)
	  compteur++;
	else
	  break;
	if(compteur == ALIGNER)
	  return 1;
      }
    }
  return 0;
}


int vertical(Plateau_t plateau, char c){ //Colonne de 6 pions 
  int compteur, i;
  for(int colonne = 0; colonne < plateau.colonne; colonne++)
    for(int ligne = alignerM1; ligne < plateau.ligne; ligne++){
      compteur = 0;
      for(i = 0; i < ALIGNER; i++){
	if(plateau.tab[ligne - i][colonne] == c)
	  compteur++;
	else
	  break;
	if(compteur == ALIGNER)
	  return 1;
      }
    }
  return 0;
}


int rec_ligne(Plateau_t plateau, char c){ //Rectangle où une ligne == ALLIGNER/2 pions && ALLIGNER doit etre paire
  int compteur;
  if(ALIGNER % 2)
    return 0;
  for(int ligne = 0; ligne < plateau.ligne - 1; ligne++)
    for(int colonne = ALIGNER/2  - 1; colonne < plateau.colonne; colonne++){
      compteur = 0;
      for (int i = 0; i < ALIGNER / 2; i++){
	if(plateau.tab[ligne+1][colonne-i] == c && plateau.tab[ligne][colonne-i] == c)
	  compteur += 2;
	else
	  break;
	if(compteur == ALIGNER)
	  return 1;
      }
    }
  return 0;
}

int rec_colonne(Plateau_t plateau, char c){ //Rectangle où une colonne == 3 pions && ALLIGNER doit etre paire
  int compteur;
  if(ALIGNER % 2)
    return 0;
   for(int colonne = 0; colonne < plateau.colonne - 1; colonne++)
     for(int ligne = ALIGNER/2  - 1; ligne < plateau.ligne; ligne++){
       compteur = 0;
       for (int i = 0; i < ALIGNER / 2; i++){
	 if(plateau.tab[ligne-i][colonne+1] == c && plateau.tab[ligne-i][colonne] == c)
	   compteur += 2;
	 else
	   break;
	if(compteur == ALIGNER)
	  return 1;
       }
     }
   return 0;
}

// Les fonctions rec_ligne et rec_colonne on été faite en plus 

int l_verification2(Plateau_t plateau, char c){  //Vérification d'un l avec une ligne de al_m3 et une collone de 3
  int compteur;
  int passe;
  int al_m3 = ALIGNER - 3;
  for(int ligne = 0; ligne < plateau.ligne; ligne++){
    for(int colonne = al_m3; colonne < plateau.colonne; colonne++){
      passe = 1;
      compteur = al_m3;
      while(passe){
	if(compteur < 0){
	  if(ligne > 1){
	    if(plateau.tab[ligne-1][colonne-al_m3] == c && plateau.tab[ligne-2][colonne-al_m3] == c)
	      return 1;
	    if(plateau.tab[ligne-1][colonne] == c && plateau.tab[ligne-2][colonne] == c)
	      return 1;
	  }
	  if(ligne < plateau.ligne-2){
	      if(plateau.tab[ligne+1][colonne-al_m3] == c && plateau.tab[ligne+2][colonne-al_m3] == c)
	      return 1;
	    if(plateau.tab[ligne+1][colonne] == c && plateau.tab[ligne+2][colonne] == c)
	      return 1;
	  }
	  passe = 0;
	}
	else if(plateau.tab[ligne][colonne-compteur] == c)
	  compteur--;
	else
	  passe = 0;
      }
    }
  }
  return 0;
}

int l_verification(Plateau_t plateau, char c){  //Vérification d'un l avec une ligne de 3 et une collone de al_m3
  int compteur;
  int passe;
  int al_m3 = ALIGNER - 3;
  for(int colonne= 0; colonne < plateau.colonne; colonne++){
    for(int ligne = al_m3; ligne < plateau.ligne; ligne++){
      passe = 1;
      compteur = al_m3;
      while(passe){
	if(compteur < 0){
	  if(colonne > 1){
	    if(plateau.tab[ligne-al_m3][colonne-1] == c && plateau.tab[ligne-al_m3][colonne-2] == c)
	      return 1;
	    if(plateau.tab[ligne][colonne-1] == c && plateau.tab[ligne][colonne-2] == c)
	      return 1;
	  }
	  if(colonne < plateau.colonne-2){
	      if(plateau.tab[ligne-al_m3][colonne+1] == c && plateau.tab[ligne-al_m3][colonne+2] == c)
	      return 1;
	    if(plateau.tab[ligne][colonne+1] == c && plateau.tab[ligne][colonne+2] == c)
	      return 1;
	  }
	  passe = 0;
	}
	else if(plateau.tab[ligne-compteur][colonne] == c)
	  compteur--;
	else
	  passe = 0;
      }
    }
  }
  return 0;
} 

int gagner(Plateau_t plateau, char c){
  if(vertical(plateau,c) || horizontal(plateau,c) || rec_ligne(plateau,c) ||
     rec_colonne(plateau,c) || l_verification(plateau,c) || l_verification2(plateau,c))  //Véréfication de chaque condition
    return 1;
  return 0;
}
