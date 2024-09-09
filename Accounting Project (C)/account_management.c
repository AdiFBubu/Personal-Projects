#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "account_management.h"

extern int nr_clients;
extern char activity_log[100000], str[20];

void create_account(struct clients *c, char *user_name, char *account_type) /// creeaza un cont bancar si/sau un tip de cont bancar asociat
{
    /// verific daca exista deja clientul cu numele si tipul dat

    int index = -1;
    for(int i = 0; i < nr_clients; i ++)
    {
        if(strcmp(c[i].name, user_name) == 0)
        {
            index = i; /// exista, la pozitia: index
            for(int i_account = 0; i < c[i].nr_accounts; i ++)
                if(strcmp(c[i].accounts[i_account].type, account_type) == 0)
                {
                    strcat(activity_log, user_name);
                    strcat(activity_log, " tried to create an account type: ");
                    strcat(activity_log, account_type);
                    strcat(activity_log, ", but received the message: 'You already have that type of account'\n");

                    printf("You already have that type of account!\n");
                    return;
                }
        }
    }
    if(index != -1) /// exista deja un client inregistrat, care are cel putin un tip de cont bancar
    {
        int nr_accounts = c[index].nr_accounts;
        strcpy(c[index].accounts[nr_accounts].type, account_type);
        c[index].accounts[nr_accounts].balance = 0;
        c[index].accounts[nr_accounts].acc_statement[0] = '\0';
        c[index].accounts[nr_accounts].transaction_register[0] = '\0';
        c[index].accounts[nr_accounts].expense_rep[0] = '\0';
        c[index].nr_accounts ++;

        strcat(activity_log, user_name);
        strcat(activity_log, " has created another account type: ");
        strcat(activity_log, account_type);
        strcat(activity_log, "\n");

        printf("Another account type created!\n");
    }
    else /// clientul nu e inregistrat
    {
        c[nr_clients].nr_accounts = 0;
        c[nr_clients].nr_customers = 0;
        c[nr_clients].customers = (struct manage_customers *)malloc(sizeof(struct manage_customers));
        c[nr_clients].customers[0].nr_payments = 0;
        int nr_accounts = c[nr_clients].nr_accounts;
        strcpy(c[nr_clients].name, user_name);
        strcpy(c[nr_clients].accounts[nr_accounts].type, account_type);
        c[nr_clients].accounts[nr_accounts].balance = 0;
        c[nr_clients].accounts[nr_accounts].acc_statement[0] = '\0';
        c[nr_clients].accounts[nr_accounts].transaction_register[0] = '\0';
        c[nr_clients].accounts[nr_accounts].expense_rep[0] = '\0';
        c[nr_clients].nr_accounts ++;
        nr_clients ++;
        printf("First account type created!\n");

        strcat(activity_log, user_name);
        strcat(activity_log, " has created the first account type: ");
        strcat(activity_log, account_type);
        strcat(activity_log, "\n");
    }
}

int edit_account(struct clients *c, char *user_name, char *new_user_name) /// inlocuirea numelui user-ului cu un nou nume: new_user_name
{

    strcat(activity_log, user_name);
    strcat(activity_log, " is trying to edit the user name to: ");
    strcat(activity_log, new_user_name);
    strcat(activity_log, " and the message shown is: ");

    for(int i = 0; i < nr_clients; i ++)
        if( strcmp(c[i].name, user_name) == 0)
        {
            strcpy(c[i].name, new_user_name);

            strcat(activity_log, "'Editing was successful!'\n");

            printf("Editing was successful!\n");
            return 1;
        }
    printf("There is not any client with the name entered!\n");

    strcat(activity_log, "'There is not any client with the name entered!'\n");
    return 0;
}

void delete_account(struct clients *c, char *user_name, char *account_type) /// stergerea tipului de cont bancar: account_type asociat clientului cu numele: user_name
{

    strcat(activity_log, user_name);
    strcat(activity_log, " is trying to delete the account type: ");
    strcat(activity_log, account_type);
    strcat(activity_log, " and the message shown is: ");

    for(int i = 0; i < nr_clients; i ++)
        if( strcmp(c[i].name, user_name) == 0 )
        {
            for(int j = 0; j < c[i].nr_accounts; j ++)
                if( strcmp(c[i].accounts[j].type, account_type) == 0 ) /// a fost gasit clientul cu numele: user_name si tipul de cont: account_type
                {
                    for(int k = j; k < c[i].nr_accounts - 1; k ++)
                        c[i].accounts[k] = c[i].accounts[k + 1];
                    c[i].nr_accounts --;

                    strcat(activity_log, "'Deletion was successful!'\n");

                    printf("Deletion was successful!\n");
                    return;
                }
            printf("The client with the name entered does not have the account type entered!\n");
            strcat(activity_log, "'The client with the name entered does not have the account type entered!'\n");
            return;
        }
    printf("There is not any client with the name entered!\n");
    strcat(activity_log, "'There is not any client with the name entered!'\n");

}

void add_info(struct clients* c, int index, int id_client, char *info) /// adaugarea unui mesaj - info - user-ului cu id-ul: id_client, de catre user-ul cu id-ul: index
{
    strcat(activity_log, "The user-company with the index: ");

    sprintf(str, "%d", index);
    strcat(activity_log, str);

    strcat(activity_log, " is trying to add the message: '");
    strcat(activity_log, info);
    strcat(activity_log, "' to the client with the index: ");

    sprintf(str, "%d", id_client);
    strcat(activity_log, str);

    if(id_client >= c[index].nr_customers) /// id_client nu e inregistrat in baza de date
    {
        printf("Incorrect ID!\n");
        strcat(activity_log, " and the message shown is: 'Incorrect ID!'\n");
        return;
    }
    strcpy(c[index].customers[id_client].message, info);
    strcat(activity_log, " successfully!\n");
}
