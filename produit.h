#ifndef PRODUIT_H_INCLUDED
#define PRODUIT_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct date {
    int jour;
    int mois;
    int annee;
}Date;

typedef struct time {
    int h;
    int m;
    int s;
}Time;

typedef struct Description {
    char categorie[20];
    char couleur[20];
    float prix_produit;
}Description;

typedef struct Produit {
    long code_barre;
    char nom_produit[20];
    int quantite_produit;
    Description description_produit;
    Date date;
    bool archive;
}Produit;



typedef struct ProdHistory{

    long code_barre;
    char nom_produit[20];
    int quantite;
    Date date;
    Time time;
}ProdHistory;


void showproducts(FILE *f);
void remplirProduit(Produit *p);
void ajouterProduit(FILE *f,Produit p,int nombreproduit);
void afficherProduit2(FILE *f, int n,long id);
void rechercheAndReturnPorduit(FILE *f, long id,Produit *p);
void recherche_produit(FILE *f, long id);
void modifierQuantite(FILE *f,FILE *h, int n , long id,int c);
void modifierDescriptionProduit(Produit *p, FILE *f,long id);
void archiveProduit(Produit *p, FILE *f,long id);
void deleteProductPermanently(FILE *f,long id);
void afficherHistorique (FILE *h);

void modifierProduit2(Produit *p, FILE *f,long id,int n);

#endif
