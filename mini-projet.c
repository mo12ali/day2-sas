#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char titre[MAX];
    char auteur[MAX];
    double prix;
    int quantite;
} livre;

typedef struct
{
    livre *livres;
    int capacite;
    int taille;
} stock;

/**
 *                0 1 2 3 4 5 6
 *          stock a b c d e f   taille=7
 */

/**
 *  Ajouter un livre au stock.
    Afficher tous les livres disponibles.
    Rechercher un livre par son titre.
    Mettre à jour la quantité d'un livre.
    Supprimer un livre du stock.
    Afficher le nombre total de livres en stock.
*/

livre init_livre(char titr[], char auteur[], double pr, int qte)
{
    livre new;
    strcpy(new.titre, titr);
    strcpy(new.auteur, auteur);
    new.prix = pr;
    new.quantite = qte;
    return new;
}

/**
 * check if the size is equivalent to the capacity
 *  if so that means the stock is full => add 1 case increase the capacoty by 1 or double it ,
 */
void ajout_livre(stock *s, livre l)
{
    if (s->taille > s->capacite)
        printf("capacite insuffisante");
    if (s->taille == s->capacite)
    {
        s->capacite = s->capacite * 2;
        s->livres = realloc(s->livres, s->capacite);
        s->livres[s->taille++] = l;
    }
    else
    {
        s->livres[s->taille++] = l;
    }
}

void afficher_livre(livre l)
{
    printf("le titre de livre : %s de l'auteur : %s le prix est : %.2f et la quantite disponible : %d \n", l.titre, l.auteur, l.prix, l.quantite);
}

// afficher les livres disponibles
void afficher_tous_les_livres(stock s)
{
    for (int i = 0; i < s.taille; i++)
    {
        afficher_livre(s.livres[i]);
        printf("\n ===================================== \n");
    }
}

int rechercher_un_livre_par_titre(stock st, char tt[])
{
    for (int i = 0; i < st.taille; i++)
    {
        if (strcmp(st.livres[i].titre, tt) == 0)
            return i;
    }
}

// mettre a jour la quantite d'un livre

void mettre_a_jour_la_quantite_dun_livre(stock st, char titre[], int qt)
{
    int indice = rechercher_un_livre_par_titre(st, titre);
    st.livres[indice].quantite = qt;
}

void supprimer_un_livre_du_stock(stock st, char titr[])
{
    int j = rechercher_un_livre_par_titre(st, titr);
    while (j < st.taille)
    {
        st.livres[j] = st.livres[j + 1];
        j++;
    }
    st.taille = st.taille - 1;
}

int nombre_total_des_livres_en_stock(stock st)
{
    int total = 0;
    for (int i = 0; i < st.taille; i++)
    {
        total += st.livres[i].quantite;
    }
    return total;
}
void vider_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
int main()
{
    stock st;
    st.livres = NULL;
    st.capacite = 0;
    st.taille = 0;
    int choix;

    do
    {
        printf("\n===== MENU DE GESTION DE STOCK DE LIVRES =====\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre à jour la quantité d'un livre.\n");
        printf("5. Supprimer un livre du stock.\n");
        printf("6. Afficher le nombre total de livres en stock.\n");
        printf("0. Quitter le programme.\n");
        printf("==============================================\n");
        printf("Veuillez choisir une option : ");
        if (scanf("%d", &choix) != 1)
        {
            printf("Entrée invalide.\n");
            vider_buffer();
            continue;
        }
        vider_buffer();

        switch (choix)
        {
        case 1:
        {
            char tt[MAX], auteur[MAX];
            double prix;
            int qte;
            printf("----- Entrer le titre -----\n");
            fgets(tt, sizeof(tt), stdin);
            printf("----- Entrer le nom de l'auteur -----\n");
            fgets(auteur, sizeof(auteur), stdin);
            printf("----- Entrer le prix -----\n");
            if (scanf("%lf", &prix) != 1)
            {
                printf("Prix invalide.\n");
                vider_buffer();
                break;
            }
            printf("----- Entrer la quantité -----\n");
            if (scanf("%d", &qte) != 1)
            {
                printf("Quantité invalide.\n");
                vider_buffer();
                break;
            }
            vider_buffer();
            livre new = init_livre(tt, auteur, prix, qte);
            ajout_livre(&st, new);
            printf("Livre ajouté au stock.\n");
            break;
        }
        case 2:
            afficher_tous_les_livres(st);
            break;
        case 3:
        {
            char titre0[MAX];
            printf("Entrez le titre du livre à rechercher :\n");
            fgets(titre0, sizeof(titre0), stdin);
            int idx = rechercher_un_livre_par_titre(st, titre0);
            if (idx == -1)
                printf("Livre non trouvé.\n");
            else
            {
                printf("Livre trouvé :\n");
                afficher_livre(st.livres[idx]);
            }
            break;
        }
        case 4:
        {
            char titre1[MAX];
            int nv_qt;
            printf("Entrez le titre du livre à mettre à jour :\n");
            fgets(titre1, sizeof(titre1), stdin);
            printf("Entrez la nouvelle quantité :\n");
            if (scanf("%d", &nv_qt) != 1)
            {
                printf("Quantité invalide.\n");
                vider_buffer();
                break;
            }
            vider_buffer();
            mettre_a_jour_la_quantite_dun_livre(st, titre1, nv_qt);
            break;
        }
        case 5:
        {
            char titre2[MAX];
            printf("Entrez le titre du livre à supprimer :\n");
            fgets(titre2, sizeof(titre2), stdin);
            supprimer_un_livre_du_stock(st, titre2);
            break;
        }
        case 6:
        {
            int total = nombre_total_des_livres_en_stock(st);
            printf("Le nombre total des livres dans le stock est : %d\n", total);
            break;
        }
        case 0:
            printf("Au revoir !\n");
            break;
        default:
            printf("Option invalide, veuillez réessayer.\n");
        }
    } while (choix != 0);

    free(st.livres);
    return 0;
}
