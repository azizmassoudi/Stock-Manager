#include "produit.h"


int main()
{

    int choice;

    Produit *listProduit[100];
    Produit p;
    Produit p2;
    int nombreproduit=0;
    int confirmer=-1;
    long idproduit;
    Produit *ptr;
    FILE *f,*h;
    int quantite;
    printf("\t\t\t Welcome to projectName \n");
    showAllProducts(f);
    while (1) {
        // affichez le menu ici
        printf("*******************************************\n");
        printf("\t0. afficher tous les produits\n");
        printf("\t1. Ajouter un produit\n");
        printf("\t2. Afficher la description d'un produit\n");
        printf("\t3. diminuer la quantite d'un produit.\n");
        printf("\t4. Modifier la description d'un produit\n");
        printf("\t5. Rechercher un produit\n");
        printf("\t6. archive produit\n");
        printf("\t7. afficher tous les produits dans le stock\n");
        printf("\t8. supprimer produit definitivement\n");
        printf("\t9. augmenter la quantite d'un produit \n");
        printf("\t10. afficher l'historique \n");
        printf("\t11. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                showAllProducts(f);
                break;
            case 1:
                remplirProduit(&p);
                printf("Voulez vous confirmer: 1. OUI, 2. NON ");
                scanf("%d",&confirmer);
                if(confirmer==1){
                    ajouterProduit(f,p,nombreproduit);
                    printf("Produit ajouter avec succes \n");
                    nombreproduit++;
                    confirmer=-1;
                }
                break;
            case 2:
                printf("donnez le code_barre de produit: ");
                scanf("%lu",&idproduit);
                afficherProduit2(f,nombreproduit,idproduit);

                break;
            case 3:
                printf("donnez le code_barre de produit: ");
                scanf("%lu",&idproduit);
                printf("donnez la quantite a diminuer: ");
                scanf("%lu",&quantite);
                modifierQuantite(f,h,quantite ,idproduit,0);
                break;
            case 4:
                printf("donnez le code barre de produit a modifier: ");
                fflush(stdin);
                scanf("%lu",&idproduit);
                modifierDescriptionProduit(&p,f,idproduit);
                break;
            case 5:
            	printf("donner le code barre de produit a rechercher");
            	scanf("%lu",&idproduit);
				recherche_produit(f,idproduit);
				break;    
            case 6:
                printf("donnez le code barre de produit: ");
                scanf("%lu",&idproduit);
                archiveProduit(&p,f,idproduit);
                break;
            case 7:
                showAllProductsinStock(f);
                break;
            case 8:
                printf("donnez le code barre de produit: ");
                scanf("%lu",&idproduit);
                deleteProductPermanently(f,idproduit);
                break;
            case 9:
                printf("donnez le code_barre de produit: ");
                scanf("%lu",&idproduit);
                printf("donnez la quantite a augmenter: ");
                scanf("%lu",&quantite);
                modifierQuantite(f,h,quantite ,idproduit,1);
                break;
            case 10:
                afficherHistorique (h);
                break;

    return 0;
    }
}


    return 0;
}
