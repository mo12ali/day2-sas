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

    //printf("in init carnet\n");
    return init;
}
contact init_contact(char *name, char *telephone, char *email)
{
    contact ct;
    strcpy(ct.name, name);
    strcpy(ct.telephone, telephone);
    strcpy(ct.email, email);
    //printf("in init contact\n");

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
    printf("in ajouter contact\n");

    carnet->size++;
    
}
// 5 rechercher contact
/**
 * @brief Le programme permet à l'utilisateur de rechercher un contact par son nom.
 *
  Si le contact est trouvé, ses détails (nom, numéro de téléphone,
   adresse e-mail) sont affichés.
 *
 */

void afficher_contact(contact ct)
{

    printf("=>      contact name : %s , phone number : %s , email : %s      <=\n",ct.name, ct.telephone, ct.email);
}

void rechercher_contact(carnet cr, contact ct)
{
    for (int i = 0; i < cr.size; i++)
    {
        if (strcmp(cr.contacts[i].name, ct.name) == 0)
        {
            printf("contact trouve : \n");
            printf("Nom : %s\n", cr.contacts[i].name);
            printf("Telephone : %s\n", cr.contacts[i].telephone);
            printf("Email : %s\n", cr.contacts[i].email);
        }
    }
}
int rechercher_contact_index(carnet *cr, contact ct)
{
    for (int i = 0; i < cr->size; i++)
    {
        if (strcmp(cr->contacts[i].name, ct.name) == 0)
        {
            return i;
        }
    }
    return -1;
}
// 2 supprimer contact

/*
    0 1 2 3
    a b c d
*/
void supprimer_contact(carnet *cr, contact ct)
{
    int j = 0;
    // for(int i = 0; i<cr->size ; i++){
    if ((j = rechercher_contact_index(cr, ct) ) != -1)
        for (int i = j; i < cr->size - 1; i++)
        {
            cr->contacts[i] = cr->contacts[i + 1];
        }
    cr->size--;
}

// 3 modifier contact
void modifier_contact(carnet *cr, contact ct, char *new_email, char *new_phone)
{

    int pos = rechercher_contact_index(cr, ct);
    // cr->contacts[pos].email = new_email;
    strcpy(cr->contacts[pos].email, new_email);

    // cr ->contacts[pos].telephone = new_phone;
    strcpy(cr->contacts[pos].telephone, new_phone);
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
    //const char *red     = "\033[0;31m";
    //const char *green   = "\033[0;32m";
    const char *yellow  = "\033[0;33m";
    const char *blue    = "\033[0;34m";
    //const char *magenta = "\033[0;35m";
    const char *cyan    = "\033[0;36m";
    const char *reset   = "\033[0m";

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
            printf("Entrer le nom du contact : ");
            scanf("%s", name);
            printf("Entrer le numero de telephone du contact : ");
            scanf("%s", telephone);
            printf("Entrer l'email du contact : ");
            scanf("%s", email);
            contact new_contact = init_contact(name, telephone, email);
            ajouter_contact(&cr, new_contact);
            break;
        case 2:
            /* Modifier contact */
            char name_mod[MAX_CHAR],new_phone[MAX_CHAR], new_email[MAX_CHAR];
            printf("Entrer le nom du contact a modifier : ");
            scanf("%s", name_mod);
            printf("Entrer le nouveau numero de telephone du contact : ");
            scanf("%s", new_phone);
            printf("Entrer le nouvel email du contact : ");
            scanf("%s", new_email);
            contact mod_contact = init_contact(name_mod, "", "");
            modifier_contact(&cr, mod_contact, new_email, new_phone);
            break;
        case 3:
            /* Supprimer contact  */
            char name_sup[MAX_CHAR];
            printf("Entrer le nom du contact a supprimer : ");
            scanf("%s", name_sup);
            contact sup_contact = init_contact(name_sup, "", "");
            supprimer_contact(&cr, sup_contact);   
            break;
        case 4:
            /* Afficher contact   */
            afficher_contacts(cr);
            break;      
        case 5:
            /* Rechercher contact */
            char name_rech[MAX_CHAR];
            printf("Entrer le nom du contact a rechercher : ");
            scanf("%s", name_rech);
            contact rech_contact = init_contact(name_rech, "", "");
            rechercher_contact(cr, rech_contact);
            break;
        case 6:
            exit(0);
            break;          
        default:
            printf("choix invalide\n");
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
