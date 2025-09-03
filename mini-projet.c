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
         *
         *
         *
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
         *
         *
         *
         * check if the size is equivalent to the capacity
         *  if so that means the stock is full => add 1 case increase the capacoty by 1 or double it ,
         */
        void ajout_livre(stock *s, livre l)
        {
            if(s->taille > s->capacite)
                printf("capacite insuffisante");
            if(s->taille == s->capacite){
                s->capacite = s->capacite *2;
                s->livres = realloc(s->livres, s->capacite);
                s->livres[ s->taille ++] = l;
            }else{
                s->livres[s->taille ++] = l; 
            }
        }

        void afficher_livre(livre l)
        {
            printf("le titre de livre : %s de l'auteur : %s le prix est : %.2f et la quantite disponible : %d \n", l.titre, l.auteur, l.prix, l.quantite);
        }


        //afficher les livres disponibles
        void afficher_tous_les_livres(stock s)
        {
            for (int i = 0; i < s.taille; i++)
            {
                afficher_livre(s.livres[i]);
                printf("\n ===================================== \n");
            }
        }

        int rechercher_un_livre_par_titre(stock st, char tt[]){
            for(int i = 0 ; i < st.taille ; i++){
                if(strcmp(st.livres[i].titre,tt) == 0)
                    //printf("le livre existe à la postion %d \n",i);
                    return i;
            }
        }

        //mettre a jour la quantite d'un livre

        void mettre_a_jour_la_quantite_dun_livre(stock st,char titre[] , int qt){
            int indice = rechercher_un_livre_par_titre(st,titre);
            st.livres[indice].quantite = qt;
        }

        void supprimer_un_livre_du_stock(stock st, char titr[]){
            int j = rechercher_un_livre_par_titre(st,titr) ;
            /*for(i = 0; i < st->taille ; i++){
                if(strcmp(st->livres[i].titre, titr) == 0){
                    j = i;
                }
            }*/


            while( j < st.taille){
                st.livres[j] = st.livres[j+1];
                j++;
            }
            st.taille --;

        }

        int nombre_total_des_livres_en_stock(stock st){
            int total = 0;
            for(int i = 0 ; i < st.taille ; i++){
                total += st.livres[i].quantite;
            }
            return total;
        }
        int main()
        {

            stock st;
            st.livres = NULL;
            st.capacite = 0;
            st.taille = 0;
            livre l1 = init_livre("learn c", "her", 2.00, 40);
            livre l2 = init_livre("learn c++", "his", 12.00, 106);
            livre l3 = init_livre("learn java", "who", 25.00, 15);
            livre l4 = init_livre("learn shell", "him", 288.00, 70);
            afficher_livre(l1);
            ajout_livre(&st, l1);
            ajout_livre(&st, l2);
            ajout_livre(&st, l3);
            ajout_livre(&st, l4);
            printf("affichage de stock \n");
            afficher_tous_les_livres(st);
            printf("\n--------------------------------------\n");
            rechercher_un_livre_par_titre(st,"learn java");
            printf("\n--------------------------------------\n");
            mettre_a_jour_la_quantite_dun_livre(st,"learn java",7);
            printf("\n--------------------------------------\n");
            afficher_tous_les_livres(st);
            printf("\n--------------------------------------\n");
            supprimer_un_livre_du_stock(st,"learn c++");
            printf("\n--------------------------------------\n");
            afficher_tous_les_livres(st);
            printf("\n--------------------------------------\n");
            printf("le nombre total des livres dans le stock est : %d",nombre_total_des_livres_en_stock(st));

            return 0;
        }
