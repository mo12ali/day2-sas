#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50
typedef struct
{
    char name[MAX_CHAR];
    char telephone[MAX_CHAR];
    char email[MAX_CHAR];
} contact;

typedef struct
{
    contact *contacts;
    int size;
    int capacity;
} carnet;

carnet init_carnet()
{
    carnet init;
    init.contacts = NULL;
    init.size = 0;
    init.capacity = 0;

    return init;
}
contact init_contact(char *name, char *telephone, char *email)
{
    contact ct;
    strcpy(ct.name, name);
    strcpy(ct.telephone, telephone);
    strcpy(ct.email, email);

    return ct;
}
// 1 ajouter contact

void ajouter_contact(carnet *carnet, contact ct)
{
    if(carnet->size == carnet->capacity){
        if(carnet->capacity == 0){
            carnet->capacity = 1;
        }else{
            carnet->capacity *= 2;
        }
        carnet->contacts = realloc(carnet->contacts, sizeof(contact) * carnet->capacity);
    }
    //carnet->contacts = realloc(carnet->contacts, sizeof(contact) * (carnet->capacity * 2));
    carnet->contacts[carnet->size] = ct;
    //printf("in ajouter contact\n");

    carnet->size++;
    
}
// 5 rechercher contact

void afficher_contact(contact ct)
{

    printf("=>      contact name : %s , phone number : %s , email : %s      <=\n",ct.name, ct.telephone, ct.email);
}

void rechercher_contact(carnet cr, char nm[])
{
    for (int i = 0; i < cr.size; i++)
    {
        if (strcmp(cr.contacts[i].name, nm) == 0)
        {
            printf("contact trouve : \n");
            printf("Nom : %s\n", cr.contacts[i].name);
            printf("Telephone : %s\n", cr.contacts[i].telephone);
            printf("Email : %s\n", cr.contacts[i].email);
        }else{
            printf(" \n le contact n'existe pas \n");
        }
    }
}
int rechercher_contact_index(carnet *cr, char nm[])
{
    for (int i = 0; i < cr->size; i++)
    {
        if (strcmp(cr->contacts[i].name, nm) == 0)
        {
            return i;
        }
    }
    return -1;
}
// 2 supprimer contact

void supprimer_contact(carnet *cr, char nm[])
{
    int j = 0;
    if ((j = rechercher_contact_index(cr, nm) ) != -1){
         for (int i = j; i < cr->size; i++)
        {
            cr->contacts[i] = cr->contacts[i + 1];
        }
        printf("le contact existe a la position %d \n",j);
    cr->size--;
    }else{
        printf("le contact n'existe pas\n");
    }
       
}

// 3 modifier contact

void modifier_contact(carnet *cr, char nm[], char *new_email, char *new_phone)
{
    int pos;
    if((pos = rechercher_contact_index(cr, nm)) != -1 ){
            // cr->contacts[pos].email = new_email;
        strcpy(cr->contacts[pos].email, new_email);

        // cr ->contacts[pos].telephone = new_phone;
        strcpy(cr->contacts[pos].telephone, new_phone);
    }else{
        printf("Le contact n'existe pas !\n");
    }
    
}
// 4 afficher contact

void afficher_contacts(carnet cr)
{
     printf("\t");
    printf("------------------------ Liste des contacts : ------------------------------\n");    
   

    for (int i = 0; i < cr.size; i++)
    {
        printf("Contact %d : \n", i + 1);
        afficher_contact(cr.contacts[i]);
    }
    
    
    printf("\t");
    printf("------------------------ Liste des contacts : ------------------------------\n");
}

int main()
{   int choix;
    carnet cr = init_carnet();
    const char *yellow  = "\033[0;33m";
    const char *blue    = "\033[0;34m";
    const char *cyan    = "\033[0;36m";
    const char *green = "\033[0;32m";
    const char *red = "\033[0;31m";
    const char *reset = "\033[0m";



    do{                       
        printf("\t");printf("%s************** MENU *****************%s\n",cyan,reset);
        printf("\t");printf("%s*       1 .  Ajouter contact        *%s\n",blue,reset);
        printf("\t");printf("%s*       2 .  Modifier contact       *%s\n",yellow,reset);
        printf("\t");printf("%s*       3 .  Supprimer contact      *%s\n",blue,reset);
        printf("\t");printf("%s*       4 .  Afficher contact       *%s\n",yellow,reset);
        printf("\t");printf("%s*       5 .  Rechercher contact     *%s\n",blue,reset);
        printf("\t");printf("%s*       6 .  Quitter                *%s\n",yellow,reset);
        printf("\t");printf("%s*       Choisir une option :        *%s\n",cyan,reset);
        printf("\t");printf("%s*************************************%s\n",cyan,reset);
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            /* Ajouter contact */
            char name[MAX_CHAR], telephone[MAX_CHAR], email[MAX_CHAR];
            printf("%sEntrer le nom du contact : %s",green,reset);
            scanf("%s", name);
            printf("%sEntrer le numero de telephone du contact : %s",green,reset);
            scanf("%s", telephone);
            printf("%sEntrer l'email du contact : %s",green,reset);
            scanf("%s", email);
            contact new_contact = init_contact(name, telephone, email);
            ajouter_contact(&cr, new_contact);
            break;
        case 2:
            /* Modifier contact */
            char name_mod[MAX_CHAR],new_phone[MAX_CHAR], new_email[MAX_CHAR];
            printf("%sEntrer le nom du contact a modifier : %s",green,reset);
            scanf("%s", name_mod);
            printf("%sEntrer le nouveau numero de telephone du contact : %s",green,reset);
            scanf("%s", new_phone);
            printf("%sEntrer le nouvel email du contact : %s",green,reset);
            scanf("%s", new_email);
            //contact mod_contact = init_contact(name_mod, "", "");
            modifier_contact(&cr, name_mod, new_email, new_phone);
            break;
        case 3:
            /* Supprimer contact  */
            char name_sup[MAX_CHAR];
            printf("%sEntrer le nom du contact a supprimer : %s",green,reset);
            scanf("%s", name_sup);
            //contact sup_contact = init_contact(name_sup, "", "");
            supprimer_contact(&cr, name_sup);   
            break;
        case 4:
            /* Afficher contact   */
            afficher_contacts(cr);
            break;      
        case 5:
            /* Rechercher contact */
            char name_rech[MAX_CHAR];
            printf("%sEntrer le nom du contact a rechercher : %s",green,reset);
            scanf("%s", name_rech);
            //contact rech_contact = init_contact(name_rech, "", "");
            rechercher_contact(cr, name_rech);
            break;
        case 6:
            /* Quitter le menu */
            exit(0);
            break;          
        default:
            printf("%schoix invalide !!!!\n%s",red,reset);
            break;
        }
    }while(choix >= 1 || choix <= 6);
    //menu
   
    
    /*contact ct1 = init_contact("Alice", "123456789", "alice@alo.alo");
    contact ct2 = init_contact("Bob", "987654321", "bob@bob");
    contact ct3 = init_contact("Charlie", "555555555", "charlie@charlie");*/


    /*
    ajouter_contact(&cr, ct1);
    //printf("after ajouter contact 1\n");
    ajouter_contact(&cr, ct2);
    //printf("after ajouter contact 2\n");
    ajouter_contact(&cr, ct3);
    //printf("after ajouter contact 3\n");
    */
    /*
    afficher_contacts(cr);
    contact ct4 = init_contact("Bob", "", "");
    rechercher_contact(cr, ct4);
    modifier_contact(&cr, ct4, "new_bob@bob", "000000000");
    afficher_contacts(cr);
    supprimer_contact(&cr, ct4);
    afficher_contacts(cr);
    */



    return 0;
}
