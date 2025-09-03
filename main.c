#include <stdio.h>
#include <string.h>

#define MAX 100
#define TAILLE 50


int main() {
	char titres[MAX][TAILLE];
    char auteurs[MAX][TAILLE];
    float prix[MAX];
    int quantite[MAX];
    int n = 0;

    int choice;

	do{  // Ajuster et expliquer les commandes de programme
		printf("===================================================================================\n");
		printf("\n		 	Gestion de Stock de Librairie\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Mettre a jour la quantite d'un livre\n");
        printf("4. Supprimer un livre\n");
        printf("5. Afficher le nombre total de livres\n");
        printf("0. Quitter\n");
        
        // obtenir l'entrée de l'utilisateur
        printf("Choisissez une option : ");
        scanf("%d", &choice);
        
        // Adjuster les conditions de programme
        if (choice == 1) {
            if (n >= MAX) {  // le Maximum de livres pour ajouter à la librairie est 100
                printf("Stock plein, impossible d'ajouter plus de livres.\n");
        	}else{
        		//  Ajoutons chaque information(data) à son tableau (titre, auteur, prix, quantité)
        		getchar();
                printf("Entrez le titre du livre: ");
                fgets(titres[n], TAILLE, stdin);
                titres[n][strcspn(titres[n], "\n")] = '\0';
                
                printf("Entrez l'auteur du livre: ");
                fgets(auteurs[n], TAILLE, stdin);
                auteurs[n][strcspn(auteurs[n], "\n")] = '\0';
                
                printf("Entrez le prix du livre: ");
                scanf("%f", &prix[n]);

                printf("Entrez la quantite du livre: ");
                scanf("%d", &quantite[n]);

                n++;
				printf("Livre ajoute avec succes !\n");
			}
    }
	else if (choice == 2) {
        if (n == 0) {  // Si n = 0 ça veut dire aucun livre ajouté
            printf("Aucun livre disponible.\n");
		}else {
            printf("\n--- Liste des livres disponibles ---\n");
            for (int i = 0; i < n; i++) {
                printf("%d. Titre: %s | Auteur: %s | Prix: %.2f | Quantite: %d\n", i + 1, titres[i], auteurs[i], prix[i], quantite[i]);
            	}
			}
		}
    else if (choice == 3) {
            char titreRecherche[TAILLE];
            int nouvelleQuantite;
            getchar();
            printf("Entrez le titre du livre a mettre a jour: ");
            fgets(titreRecherche, TAILLE, stdin);
            titreRecherche[strcspn(titreRecherche, "\n")] = '\0';

            int trouve = 0;  // ajouton un variable comme un bull (si trouve=0 est false, si trouve=1 est true)
            for (int i = 0; i < n; i++) {
                if (strcmp(titres[i], titreRecherche) == 0) {
                    printf("Entrez la nouvelle quantite: ");
                    scanf("%d", &nouvelleQuantite);
                    quantite[i] = nouvelleQuantite;
                    printf("Quantite met a jour avec succes.\n");
                    trouve = 1;
                    break;  // Arretons de recherche au autres livres quand trouvons notre livre
                }
            }
            if (!trouve) { // si trouve est false(0), donc n y a aucun livre
                printf("il n y a aucun livre avec ce nom.\n");
            }
        }
    else if (choice == 4) { //  Recherchons le livre exact pour le supprimer
            char titreRecherche[TAILLE];
            getchar();
            printf("Entrez le titre du livre a supprimer : ");
            fgets(titreRecherche, TAILLE, stdin);
            titreRecherche[strcspn(titreRecherche, "\n")] = '\0';

            int trouve = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(titres[i], titreRecherche) == 0) {
                    for (int j = i; j < n - 1; j++) {
                        strcpy(titres[j], titres[j + 1]);
                        strcpy(auteurs[j], auteurs[j + 1]);
                        prix[j] = prix[j + 1];
                        quantite[j] = quantite[j + 1];
                    }
                    n--;
                    printf("Livre est supprime avec succes.\n");
                    trouve = 1;
                    break;   // Casser la loop quand 
                }
            }
            if (!trouve) {
                printf("il n y a aucun livre avec ce nom.\n");
            }
        }
    else if (choice == 5) { // Nombre total
            int total = 0;
            for (int i = 0; i < n; i++) {
                total += quantite[i];
            }
            printf("Nombre total de livres en stock : %d\n", total);
        }
    else if (choice == 0) {
            break; // fermer le programme
        }
    else {
            printf("Option invalide.\n");
        }



        
	printf("===================================================================================\n");

	}while (choice != 0);
    return 0;
}
