#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{int jj,mm,aa;
}Date;
typedef struct
{
char idrdv[50];
char cin[50];
char nom[50];
char prenom[50];
char telephone[50];
char sexe[50];
Date daterdv;
char cr[50];
char type[50];
char idetab[50];
Date dateprrdv;
}rdv;
int ajouter_rdv(rdv r);
int modifier_rdv(rdv r2);
int supprimer_rdv(char id[]);
void chercher_rdvparcr(GtkTreeView *liste,char cr[]);
void chercher_rdvpardate(GtkTreeView *liste,Date d);
void afficher_rdv(GtkTreeView *liste);
rdv* chercher_rdv(char id[]);
int chercherpardate(Date d);
int chercherparcr(char cr[]);
#endif
