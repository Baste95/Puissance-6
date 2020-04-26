#include "plateau.h"

//Jeu

void jeu(void){
  char c;
  Plateau_t plateau = remplir(plateau,LIGNE_PLATEAU,COLONNE_PLATEAU);
  if(ALIGNER > plateau.ligne || ALIGNER > plateau.colonne){
      printf("Le nombre de pions demander à etre allignés est superieur aux lignes et/ou colonnes. Exit!\n");
      exit(1);
    }
  int compteur = 0;
  char tableau[26] = {'X','O','A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','Y','Z'};
  while(!gagner(plateau,c) && !match_nul(plateau)){
    printf("\033[H\033[2J");
    aff(plateau);
    if(compteur > NOMBRE_JOUEUR - 1)
      compteur = 0;
    c = tableau[compteur];
    printf("\nJoueur %c à vous de jouez : ",c);
    int col;
    scanf("%d",&col); // Le programme crash si l'utilisateur rentre autre chose qu'un int
    col--;
    while(!possible(plateau,col) || colonne_complete(plateau,col)){
      if(!possible(plateau,col))
	printf("Erreur la colonne choisit n'existe pas.\nChoissisez une autre colonne :");
      else if(colonne_complete(plateau,col))
	printf("Erreur la colonne choisit est complete.\nChoissisez une autre colonne :");
      scanf("%d",&col);
      col--;
    }
    plateau = insertion(plateau,col,c);
    compteur++;
  }
  printf("\033[H\033[2J");
  aff(plateau);
  if(gagner(plateau,c))
    printf("\nJoueur %c à gagné !!!\n",c);
  else
    printf("Match nul !!!\n");
} 
//La fonction jeu permet de joueur, c'est la fonction mère 

int main(){
  if(ALIGNER < 4){
    printf("Le nombre de pions demander à etre allignés est inferieur à 4. Exit!\n");
    exit(1);
  }
  if(TEST)
    test();
  else
      jeu();
  
  return 0;
}

  
