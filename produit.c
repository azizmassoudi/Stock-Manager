#include "produit.h"


void showAllProducts(FILE *f){
    Produit p;

    f= fopen("produit.txt","r");
    int eof =0;
    printf("id\t nom\t\t categorie\t couleur\t prix\t\t quantite\t date\t\t archive\t \n");
    printf("\n");

    while(true){
        eof = fscanf(f,"%lu %s %d %s %s %f %d %d %d %d \n",&(p.code_barre), p.nom_produit, &(p.quantite_produit),p.description_produit.categorie,p.description_produit.couleur,&(p.description_produit.prix_produit),&(p.date.annee),&(p.date.mois), &(p.date.jour), &(p.archive));
        if  (eof == -1) break;
        printf("%lu\t %s\t %s\t\t %s\t\t %f\t %d\t\t %d-%02d-%02d\t %d\t \n",p.code_barre, p.nom_produit ,p.description_produit.categorie,p.description_produit.couleur,p.description_produit.prix_produit,p.quantite_produit,p.date.annee,p.date.mois, p.date.jour,p.archive);
    }
    printf("\n");
    fclose(f);
}

void showAllProductsinStock(FILE *f){
    Produit p;

    f= fopen("produit.txt","r");
    int eof =0;
    printf("id\t nom\t\t categorie\t couleur\t prix\t\t quantite\t date\t\t archive\t \n");
    printf("\n");

    while(true){
        eof = fscanf(f,"%lu %s %d %s %s %f %d %d %d %d \n",&(p.code_barre), p.nom_produit, &(p.quantite_produit),p.description_produit.categorie,p.description_produit.couleur,&(p.description_produit.prix_produit),&(p.date.annee),&(p.date.mois), &(p.date.jour), &(p.archive));
        if  (eof == -1) break;
        if(p.archive==false)
            printf("%lu\t %s\t %s\t\t %s\t\t %f\t %d\t\t %d-%02d-%02d\t %d\t \n",p.code_barre, p.nom_produit ,p.description_produit.categorie,p.description_produit.couleur,p.description_produit.prix_produit,p.quantite_produit,p.date.annee,p.date.mois, p.date.jour,p.archive);
    }
    printf("\n");
    fclose(f);
}

void remplirProduit(Produit *p){


    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    p->date.annee=tm.tm_year + 1900;
    p->date.mois= tm.tm_mon + 1;
    p->date.jour=tm.tm_mday;
    //printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    p->archive=false;

    printf("donnez nom produit: ");
    scanf("%s",p->nom_produit);
    printf("donnez code barre: ");
    scanf("%lu",&(p->code_barre));
    printf("donnez quantite produit: ");
    scanf("%d",&(p->quantite_produit));


    printf("donnez categorie produit: ");
    scanf("%s",p->description_produit.categorie);
    printf("donnez couleur produit: ");
    scanf("%s",p->description_produit.couleur);
    printf("donnez prix produit: ");
    scanf("%f",&(p->description_produit.prix_produit));

    printf("\n***\n");
    printf("\tvotre produit a ajouter ===> nom produit :%s, code barre: %lu, quantite produit: %d\n",p->nom_produit,p->code_barre,p->quantite_produit,p->description_produit.prix_produit);
    printf("\tdescription de produit ===> categorie :%s, couleur: %s, prix produit: %f \n",p->description_produit.categorie,p->description_produit.couleur,p->description_produit.prix_produit);
    printf("\t\tdate d ajout: %d-%02d-%02d\n",p->date.annee,p->date.mois, p->date.jour);
    printf("\n***\n");
}

void ajouterProduit(FILE *f,Produit p,int nombreproduit){

    f= fopen("produit.txt","a+");
    fprintf(f,"%lu %s %d %s %s %f %d %d %d %d \n",p.code_barre, p.nom_produit, p.quantite_produit,p.description_produit.categorie,p.description_produit.couleur,p.description_produit.prix_produit,p.date.annee,p.date.mois, p.date.jour, p.archive);
    fclose(f);

}


void afficherProduit2(FILE *f, int n,long id){
    Produit p;
    rechercheAndReturnPorduit(f,id,&p);
    if (p.code_barre != id)
        printf("produit not found\n");
    else{
        printf("\t\t\t\t categorie\t couleur\t prix\t\t \n");
        printf("\t description produit : %s\t\t %s\t\t %f \n",p.description_produit.categorie,p.description_produit.couleur,p.description_produit.prix_produit);
    }

}

void rechercheAndReturnPorduit(FILE *f,long id,Produit *p){

    f= fopen("produit.txt","r");
    int eof =0;
    while(p->code_barre != id){
        eof = fscanf(f,"%lu %s %d %s %s %f %d %d %d %d \n",&(p->code_barre), p->nom_produit, &(p->quantite_produit),p->description_produit.categorie,p->description_produit.couleur,&(p->description_produit.prix_produit),&(p->date.annee),&(p->date.mois), &(p->date.jour), &(p->archive));
        if  (eof == -1) break;
    }
    fclose(f);
}

void modifierQuantite(FILE *f,FILE *h, int quantite , long id, int c){
    Produit p;
    rechercheAndReturnPorduit(f,id,&p);

    if(c==0){
        p.quantite_produit=p.quantite_produit-quantite;
        modifierPoruitDansFichier(f,&p,id);
        ajouterHistorique(h,&p,quantite,c);
    }
    if(c==1){
        p.quantite_produit=p.quantite_produit+quantite;
        modifierPoruitDansFichier(f,&p,id);
        ajouterHistorique(h,&p,quantite,c);
    }

}


void modifierPoruitDansFichier(FILE *f,Produit *p,long id){

    Produit p2,p3;
    rechercheAndReturnPorduit(f,id,&p2);
    FILE *f2;

    if (p2.code_barre != id)
        printf("produit not found\n");
    else{
        f2 = fopen("newproduit.txt", "a+");
        f  = fopen("produit.txt", "r");
        int eof =0;
        do{
            eof = fscanf(f,"%lu %s %d %s %s %f %d %d %d %d \n",&(p3.code_barre), p3.nom_produit, &(p3.quantite_produit),p3.description_produit.categorie,p3.description_produit.couleur,&(p3.description_produit.prix_produit),&(p3.date.annee),&(p3.date.mois), &(p3.date.jour), &(p3.archive));
            if ((p3.code_barre == id)&&(eof != -1)){
                fprintf(f2,"%lu %s %d %s %s %f %d %d %d %d \n",p->code_barre, p->nom_produit, p->quantite_produit,p->description_produit.categorie,p->description_produit.couleur,p->description_produit.prix_produit,p->date.annee,p->date.mois, p->date.jour, p->archive);
            }
            else if (eof!=-1){
                fprintf(f2,"%lu %s %d %s %s %f %d %d %d %d \n",p3.code_barre, p3.nom_produit, p3.quantite_produit,p3.description_produit.categorie,p3.description_produit.couleur,p3.description_produit.prix_produit,p3.date.annee,p3.date.mois, p3.date.jour, p3.archive);
            }

        }while(eof!=EOF);
        fclose(f2);
        fclose(f);
        remove("produit.txt");
        rename("newproduit.txt", "produit.txt");
    }

}

void ajouterHistorique(FILE *h,Produit *p,int quantite,int c){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    h = fopen("historique.txt", "a+");

    if(c==0)
        fprintf(h,"%lu %s -%d %d-%02d-%02d %02d:%02d:%02d \n",p->code_barre, p->nom_produit,quantite,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    if (c==1)
        fprintf(h,"%lu %s +%d %d-%02d-%02d %02d:%02d:%02d \n",p->code_barre, p->nom_produit,quantite,tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(h);

}


void modifierDescriptionProduit(Produit *p, FILE *f,long id){

    rechercheAndReturnPorduit(f,id,p);
    if (p->code_barre != id){
         printf("produit not found\n");
    }
    else{
       printf("donnez categorie produit: ");
        scanf("%s",p->description_produit.categorie);
        printf("donnez couleur produit: ");
        scanf("%s",p->description_produit.couleur);
        printf("donnez prix produit: ");
        scanf("%f",&(p->description_produit.prix_produit));
        modifierPoruitDansFichier(f,p,id);
    }
}

void archiveProduit(Produit *p, FILE *f,long id){
    rechercheAndReturnPorduit(f,id,p);
    p->archive = true;
    p->quantite_produit =0;
    modifierPoruitDansFichier(f,p,id);
}

void deleteProductPermanently(FILE *f,long id){
    Produit p;
    rechercheAndReturnPorduit(f,id,&p);
    if (p.code_barre != id){
         printf("produit not found\n");
    }else{
    supprimer(f,&p,id);
    }

}
void supprimer(FILE *f,Produit *p,long id){

    Produit p2,p3;
    rechercheAndReturnPorduit(f,id,&p2);
    FILE *f2;

    if (p2.code_barre != id)
        printf("produit not found\n");
    else{
        f2 = fopen("newproduit.txt", "a+");
        f  = fopen("produit.txt", "r");
        int eof =0;
        do{
            eof = fscanf(f,"%lu %s %d %s %s %f %d %d %d %d \n",&(p3.code_barre), p3.nom_produit, &(p3.quantite_produit),p3.description_produit.categorie,p3.description_produit.couleur,&(p3.description_produit.prix_produit),&(p3.date.annee),&(p3.date.mois), &(p3.date.jour), &(p3.archive));
            if ((p3.code_barre != id)&&(eof != -1)){
               fprintf(f2,"%lu %s %d %s %s %f %d %d %d %d \n",p3.code_barre, p3.nom_produit, p3.quantite_produit,p3.description_produit.categorie,p3.description_produit.couleur,p3.description_produit.prix_produit,p3.date.annee,p3.date.mois, p3.date.jour, p3.archive);
            }

        }while(eof!=EOF);
        fclose(f2);
        fclose(f);
        remove("produit.txt");
        rename("newproduit.txt", "produit.txt");
    }

}

void afficherHistorique (FILE *h){

    ProdHistory history;
    h= fopen("historique.txt","r");
    int eof =0;
    printf("id\t nom\t\t quantite\t date\t\t  \n");
    printf("\n");

    while(true){
        eof = fscanf(h,"%lu %s %d %d-%02d-%02d %02d:%02d:%02d \n",&(history.code_barre), history.nom_produit, &(history.quantite),&(history.date.annee),&(history.date.mois), &(history.date.jour), &(history.time.h),&(history.time.m),&(history.time.s));
        if  (eof == -1) break;
        printf("%lu\t %s\t %d\t\t %d-%02d-%02d %02d:%02d:%02d \n",history.code_barre, history.nom_produit, history.quantite,history.date.annee,history.date.mois,history.date.jour, history.time.h,history.time.m,history.time.s);
    }
    printf("\n");
    fclose(h);

}
void recherche_produit(FILE *f, long id){
        f = fopen("produit.txt", "r");
                if (f == NULL) {
                        printf("Impossible d'ouvrir le fichier produit.txt\n");
                }
                Produit p;
                bool found = false;
                while (fscanf(f, "%lu %s %d %s %s %f %d %d %d %d \n", &(p.code_barre), p.nom_produit, &(p.quantite_produit), p.description_produit.categorie, p.description_produit.couleur, &(p.description_produit.prix_produit), &(p.date.annee), &(p.date.mois), &(p.date.jour), &(p.archive)) != EOF) {
                        if (p.code_barre == id) {
                            printf("code barre: %lu\n", p.code_barre);
                            printf("nom produit: %s\n", p.nom_produit);
                            printf("quantite produit: %d\n", p.quantite_produit);
                            printf("categorie: %s\n", p.description_produit.categorie);
                            printf("couleur: %s\n", p.description_produit.couleur);
                            printf("prix produit: %f\n", p.description_produit.prix_produit);
                            printf("quantite: %d\n", p.quantite_produit);
                            printf("date: %d-%02d-%02d\n", p.date.annee, p.date.mois, p.date.jour);
                            printf("archive: %d\n", p.archive);
                            fclose(f);
                            found=true;}}
                if(found==false){
                printf("Le produit est introuvable\n");}
               
}
