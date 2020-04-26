#include "plateau.h"

void test(void){
  int passe;
  printf("Tapez 1: Test automatique.\nTapez 2: Test libre.\nTapez 3: Quitter\n");
  scanf("%d",&passe);
  while(passe != 1 && passe != 2 && passe != 3){
    printf("Erreur valeur rentrée ! Rééssayer\n");
    scanf("%d",&passe);
  }
  if(passe == 1)
    test_automatique();
  else if(passe == 2)
    test_libre();
  else
    return;
}

void test_automatique(void){
  Plateau_t plateau = remplir(plateau,LIGNE_PLATEAU,COLONNE_PLATEAU);
  printf("\033[H\033[2J");
  if(plateau.ligne < ALIGNER && plateau.colonne < ALIGNER){
    printf("Erreur! Le nombre de pions demandé à être alligner est superieur aux lignes et colonnes demandé\n");
    test();
  }
  if(plateau.colonne < ALIGNER)
    printf("Le nombre de pions demandé à être alligner est inferieure au nombre de colonnes. Le test horizontal n'aura pas lieu.\n");
  else
    horizontal_test(plateau);
  sleep(2);
  if(plateau.ligne < ALIGNER)
    printf("Le nombre de pions demandé à être alligner est inferieure au nombre de lignes. Le test vertical n'aura pas lieu.\n");
  else
    vertical_test(plateau);
  sleep(2);
  if(ALIGNER % 2)
    printf("Le nombre de pions à aligner n'est pas paire, les tests pour les rectangles n'auront pas lieu.\n");
  else{
    rec_ligne_test(plateau);
    sleep(2);
    rec_colonne_test(plateau);
  }
  sleep(2);
  test_l_v1(plateau);
  sleep(2);
  test_l_v2(plateau);
  test();
}

void horizontal_test(Plateau_t plateau){
  char c = 'O';
  printf("Debut du test Horizontal.\n");
  sleep(2);
  for(int ligne = 0; ligne < plateau.ligne; ligne++){
    for(int colonne = ALIGNER - 1; colonne < plateau.colonne; colonne++){
      formater(plateau);
      for(int i = 0; i < ALIGNER; i++)
	plateau.tab[ligne][colonne - i] = c;
      if(!horizontal(plateau,c)){
	aff(plateau);
	printf("Erreur! La verification horizontale à échoué. Retour au menu test.\n");
	test();
      }
    }
  }
  printf("Le test est réussi.\n");
}

void vertical_test(Plateau_t plateau){
  char c = 'O';
  printf("Debut du test Vertical.\n");
  sleep(2);
  for(int colonne = 0; colonne< plateau.colonne; colonne++){
    for(int ligne = ALIGNER - 1; ligne < plateau.ligne; ligne++){
      formater(plateau);
      for(int i = 0; i < ALIGNER; i++)
	plateau.tab[ligne - i][colonne] = c;
      if(!vertical(plateau,c)){
	aff(plateau);
	printf("Erreur! La verification horizontale à échoué. Retour au menu test.\n");
	test();
      }
    }
  }
  printf("Le test est réussi.\n");
}

void rec_ligne_test(Plateau_t plateau){
  char c = 'O';
  printf("Debut du test Rectangle en ligne (largeur > hauteur).\n");
  sleep(2);
  for(int ligne = 0; ligne < plateau.ligne - 1; ligne++){
    for(int colonne = ALIGNER/2  - 1; colonne < plateau.colonne; colonne++){
      formater(plateau);
      for (int i = 0; i < ALIGNER / 2; i++)
	plateau.tab[ligne][colonne-i] = plateau.tab[ligne+1][colonne-i] = c;
      if(!rec_ligne(plateau,c)){
	aff(plateau);
	printf("Erreur! La verification Rectangle en ligne à échoué. Retour au menu test.\n");
	test();
      }
    }
  }
  printf("Le test est réussi.\n");
}

void rec_colonne_test(Plateau_t plateau){
  char c = 'O';
  printf("Debut du test Rectangle en colonne (hauteur > ligne).\n");
  sleep(2);
  for(int colonne = 0; colonne < plateau.colonne - 1; colonne++){
    for(int ligne = ALIGNER/2  - 1; ligne < plateau.ligne; ligne++){
      formater(plateau);
      for (int i = 0; i < ALIGNER / 2; i++)
	plateau.tab[ligne-i][colonne+1] =  plateau.tab[ligne-i][colonne] = c;
      if(!rec_colonne(plateau,c)){
	aff(plateau);
	printf("Erreur! La verification Rectangle en ligne à échoué. Retour au menu test.\n");
	test();
      }
    }
  }
  printf("Le test est réussi.\n");
}

void test_l_v1(Plateau_t plateau){
  char c = 'O';
  int al_m3 = ALIGNER - 3;
  printf("Début du test L v1 (colonne avec ALLIGNER - 2).\n");
  sleep(2);
  for(int colonne= 0; colonne < plateau.colonne; colonne++){
    for(int ligne = al_m3; ligne < plateau.ligne; ligne++){
      formater(plateau);
      for(int i = 0; i < ALIGNER - 2; i++)
	plateau.tab[ligne-i][colonne] = c;
      if(colonne > 1){
	plateau.tab[ligne-al_m3][colonne-1] = plateau.tab[ligne-al_m3][colonne-2] = c;
	if(!l_verification(plateau,c)){
	  aff(plateau);
	  printf("Erreur! La verification en L à échoué. Retour au menu test.\n");
	  test();
	}
	plateau.tab[ligne-al_m3][colonne-1] = plateau.tab[ligne-al_m3][colonne-2] = '~';
	plateau.tab[ligne][colonne-1] = plateau.tab[ligne][colonne-2] = c;
	if(!l_verification(plateau,c)){
	  aff(plateau);
	  printf("Erreur! La verification en L à échoué. Retour au menu test.\n");
	  test();
	}
	plateau.tab[ligne][colonne-1] = plateau.tab[ligne][colonne-2] = '~';
      }
      if(colonne < plateau.colonne-2){
	plateau.tab[ligne-al_m3][colonne+1] = plateau.tab[ligne-al_m3][colonne+2] = c;
	if(!l_verification(plateau,c)){
	  aff(plateau);
	  printf("Erreur! La verification en L à échoué. Retour au menu test.\n");
	  test();
	}
	plateau.tab[ligne-al_m3][colonne+1] = plateau.tab[ligne-al_m3][colonne+2] = '~';
	plateau.tab[ligne][colonne+1] = plateau.tab[ligne][colonne+2] = c;
	if(!l_verification(plateau,c)){
	  aff(plateau);
	  printf("Erreur! La verification en L à échoué. Retour au menu test.\n");
	  test();
	}
      }
    }
  }
  printf("Le test est réussi.\n");
}


void test_l_v2(Plateau_t plateau){
  char c = 'O';
  int al_m3 = ALIGNER - 3;
  printf("Début du test L v2 (ligne avec ALLIGNER - 2).\n");
  sleep(2);
  for(int ligne = 0; ligne < plateau.ligne; ligne++){
    for(int colonne = al_m3; colonne < plateau.colonne; colonne++){
      formater(plateau);
      for(int i = 0; i < ALIGNER - 2; i++)
	plateau.tab[ligne][colonne-i] = c;
      if(ligne > 1){
	plateau.tab[ligne-1][colonne-al_m3] = plateau.tab[ligne-2][colonne-al_m3] = c;
	if(!l_verification2(plateau,c)){
	  aff(plateau);
	  printf("Erreur! La verification en L à échoué. Retour au menu test.\n");
	  test();
	}
	plateau.tab[ligne-1][colonne-al_m3] = plateau.tab[ligne-2][colonne-al_m3] = '~';
	plateau.tab[ligne-1][colonne] = plateau.tab[ligne-2][colonne] = c;
	if(!l_verification2(plateau,c)){
	  aff(plateau);
	  printf("Erreur! La verification en L à échoué. Retour au menu test.\n");
	  test();
	}
	plateau.tab[ligne-1][colonne] = plateau.tab[ligne-2][colonne] = '~';
      }
      if(ligne < plateau.ligne-2){
	plateau.tab[ligne+1][colonne-al_m3] = plateau.tab[ligne+2][colonne-al_m3] = c;
	if(!l_verification2(plateau,c)){
	  aff(plateau);
	  printf("Erreur! La verification en L à échoué. Retour au menu test.\n");
	  test();
	}
	plateau.tab[ligne+1][colonne-al_m3] = plateau.tab[ligne+2][colonne-al_m3] = '~';
	plateau.tab[ligne+1][colonne] = plateau.tab[ligne+2][colonne] = c;
	if(!l_verification2(plateau,c)){
	  aff(plateau);
	  printf("Erreur! La verification en L à échoué. Retour au menu test.\n");
	  test();
	}
      }
    }
  }
  printf("Le test est réussi.\n");
}
    
    

void test_libre(void){
  Plateau_t plateau = remplir(plateau,LIGNE_PLATEAU,COLONNE_PLATEAU);
  int ligne, colonne;
  char c = 'X';
  while(!gagner(plateau,c) && !match_nul(plateau)){
    printf("\033[H\033[2J");
    aff(plateau);
    printf("Entrez ligne :\n");
    scanf("%d",&ligne);
    ligne--;
    printf("Entrez colonne :\n");
    scanf("%d",&colonne);
    colonne--;
    while(!possible(plateau,colonne) || ligne < 0 || ligne >= plateau.ligne){
      printf("Erreur ligne ou colonne non possible. Rééesayez\n");
      printf("Entrez ligne :\n");
      scanf("%d",&ligne);
      ligne--;
      printf("Entrez colonne :\n");
      scanf("%d",&colonne);
      colonne--;  
    }
    plateau.tab[ligne][colonne] = c;
  }
  printf("\033[H\033[2J");
  aff(plateau);
  if(vertical(plateau,c))
    printf("Vertical test réussie.\n");
  if(horizontal(plateau,c))
    printf("Horizontal test réussie.\n");
  if(rec_ligne(plateau,c))
    printf("Rectancle ligne test réussie.\n");
  if(rec_colonne(plateau,c))
    printf("Rectancle colonne test réussie.\n");
  if(l_verification(plateau,c))
    printf("L v1 verification test réussie.\n");
  if(l_verification2(plateau,c))
    printf("L v2 verification test réussie.\n");
  if(match_nul(plateau))
    printf("Le test résulte à un match nul, une erreur doit être présente dans le code!\n");
  test();
}
      
	  
	  
