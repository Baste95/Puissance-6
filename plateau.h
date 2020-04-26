#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#define LIGNE_PLATEAU 12
#define COLONNE_PLATEAU 10
#define NOMBRE_JOUEUR 3 //Maximum de joueur == 26
#define ALIGNER 6
#define TEST 0 //TEST == 1 le test se lance || TEST == 0 Le jeu se lance


//Structure du plateau 
struct Plateau{
  char ** tab;
  int ligne;
  int colonne;
};
typedef struct Plateau Plateau_t;

Plateau_t remplir(Plateau_t a, int b, int c);
int gagner(Plateau_t a, char c);
int match_nul(Plateau_t a);
void aff(Plateau_t a);
void formater(Plateau_t a);
int possible(Plateau_t a, int c);
int colonne_complete(Plateau_t a, int c);
Plateau_t insertion(Plateau_t a,int b,char c);
void test(void);
void test_automatique(void);
void test_libre(void);
void horizontal_test(Plateau_t a);
void vertical_test(Plateau_t a);
void rec_ligne_test(Plateau_t a);
void rec_colonne_test(Plateau_t a);
void test_l_v1(Plateau_t a);
void test_l_v2(Plateau_t a);
int match_nul(Plateau_t a);
int horizontal(Plateau_t a, char c);
int vertical(Plateau_t a, char c);
int rec_ligne(Plateau_t a, char c);
int rec_colonne(Plateau_t a, char c);
int l_verification2(Plateau_t a, char c);
int l_verification(Plateau_t a, char c);
void jeu(void);
int main(void);

