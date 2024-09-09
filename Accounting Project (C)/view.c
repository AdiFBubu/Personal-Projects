#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char activity_log[100000], str[20];
extern int nr_clients;

int view_clients(struct clients *c, char *user_name) /// afisarea tuturor clientilui user-ului cu numele: user_name
{

    strcat(activity_log, user_name);
    strcat(activity_log, " is trying to view his clients' list");

    for(int i = 0; i < nr_clients; i ++)
        if(strcmp(c[i].name, user_name) == 0)
        {
            if(c[i].nr_customers == 0)
            {
                printf("The user does not have any customer!\n");
                strcat(activity_log, " and the message shown is: 'The user does not have any customer!'\n");
                return -1;
            }
            for(int j = 0; j < c[i].nr_customers; j ++)
                printf("ID. %d: %s, with %d payments and info: %s\n", j, c[i].customers[j].name, c[i].customers[j].nr_payments, c[i].customers[j].message);
            /// pentru fiecare client se afiseaza numele, numarul de plati efectuate catre user_name si informatia pe care user_name i-a atribuit-o clientului in functie de numarul de plati efectuate
            strcat(activity_log, " successfully!\n");

            return i;
        }
    printf("The user with the user name entered does not exist!\n");
    strcat(activity_log, " and the message shown is: 'The user with the user name entered does not exist!'\n");

    return -1;
}

void view_account_statement(struct clients* c, char* user_name, char* account_type) /// afisarea tuturor operatiilor efectuate la nivelul tipului de cont: account_type, asociat user-ului cu numele: user_name
{
    strcat(activity_log, user_name);
    strcat(activity_log, " is trying to view the account statement for the account type: ");
    strcat(activity_log, account_type);

    for(int i = 0; i < nr_clients; i ++)
        if(strcmp(c[i].name, user_name) == 0)
        {
            for(int j = 0; j < c[i].nr_accounts; j ++)
                if(strcmp(c[i].accounts[j].type, account_type) == 0)
                {
                    if(strlen(c[i].accounts[j].acc_statement) == 0) /// daca nu a avut loc nicio operatie la nivelul tipului de cont: account_type
                    {
                        printf("There is no operation registered for this account type!\n");
                        strcat(activity_log, " and the message shown is: 'There is no operation registered for this account type!'\n");
                    }
                    else
                    {
                        printf(c[i].accounts[j].acc_statement);
                        strcat(activity_log, " successfully!\n");
                    }
                    return;
                }
            printf("The user does not have the account type that was entered!\n");
            strcat(activity_log, " and the message shown is: 'The user does not have the account type that was entered!'\n");
            return;
        }
    printf("The user with the user name entered does not exist!\n");
    strcat(activity_log, " and the message shown is: 'The user with the user name entered does not exist!'\n");
    return;
}

void view_balance(struct clients*c, char *user_name, char *account_type) ///afisarea balantei curente a tipului de cont: account_type, asociat clientului cu numele: user_name
{
    strcat(activity_log, user_name);
    strcat(activity_log, " is  trying to view the balance for the account type: ");
    strcat(activity_log, account_type);

    for(int i = 0; i < nr_clients; i ++)
        if(strcmp(c[i].name, user_name) == 0)
        {
            for(int j = 0; j < c[i].nr_accounts; j ++)
                if(strcmp(c[i].accounts[j].type, account_type) == 0)
                {
                    printf("%.2lf\n", c[i].accounts[j].balance); /// 2 zecimale
                    strcat(activity_log, " and that is: ");

                    sprintf(str, "%.2lf", c[i].accounts[j].balance); /// transformare numar real (c[i].accounts[j].balance) in sir de caractere (str) pentru a putea afisa intr-un mesaj valoarea numarului

                    strcat(activity_log, str);
                    strcat(activity_log, "\n");

                    return;
                }
            printf("The user does not have the account type that was entered!\n");
            strcat(activity_log, " and the message shown is: 'The user does not have the account type that was entered!'\n");
            return;
        }
    printf("The user with the user name entered does not exist!\n");
    strcat(activity_log, " and the message shown is: 'The user with the user name entered does not exist!'\n");
    return;
}

void view_transaction_register(struct clients*c, char *user_name, char *account_type) /// afisare registru de tranzactii - depozitare/ extragere/ transfer
{

    strcat(activity_log, user_name);
    strcat(activity_log, " is trying to view the transaction register for the account type: ");
    strcat(activity_log, account_type);

    for(int i = 0; i < nr_clients; i ++)
        if(strcmp(c[i].name, user_name) == 0)
        {
            for(int j = 0; j < c[i].nr_accounts; j ++)
                if(strcmp(c[i].accounts[j].type, account_type) == 0)
                {
                    if(strlen(c[i].accounts[j].transaction_register) == 0)
                    {
                        printf("There is no transaction registered for this account type!\n");
                        strcat(activity_log, " and the message shown is: 'There is no transaction registered for this account type!'\n");
                    }
                    else
                    {
                        printf("%s", c[i].accounts[j].transaction_register);
                        strcat(activity_log, " successfully!\n");
                    }
                    return;
                }
            printf("The user does not have the account type that was entered!\n");
            strcat(activity_log, " and the message shown is: 'The user does not have the account type that was entered!'\n");
            return;
        }
    printf("The user with the user name entered does not exist!\n");
    strcat(activity_log, " and the message shown is: 'The user with the user name entered does not exist!'\n");
    return;
}

void view_expense_report(struct clients*c, char *user_name, char *account_type) /// afisare raport de cheltuieli -> payments catre firme
{
    strcat(activity_log, user_name);
    strcat(activity_log, " is trying to view the expense report for the account type: ");
    strcat(activity_log, account_type);

    for(int i = 0; i < nr_clients; i ++)
        if(strcmp(c[i].name, user_name) == 0)
        {
            for(int j = 0; j < c[i].nr_accounts; j ++)
                if(strcmp(c[i].accounts[j].type, account_type) == 0)
                {
                    if(strlen(c[i].accounts[j].expense_rep) == 0)
                    {
                        printf("There is no expense registered for this account type!\n");
                        strcat(activity_log, " and the message shown is: 'There is no expense registered for this account type!'\n");
                    }
                    else
                    {
                        printf("%s", c[i].accounts[j].expense_rep);
                        strcat(activity_log, "successfully!\n");
                    }
                    return;
                }
            printf("The user does not have the account type that was entered!\n");
            strcat(activity_log, " and the message shown is: 'The user does not have the account type that was entered!'\n");
            return;
        }
    printf("The user with the user name entered does not exist!\n");
    strcat(activity_log, " and the message shown is: 'The user with the user name entered does not exist!'\n");
    return;
}

void view_activity_log() /// afisarea tuturor operatiilor efectuate de catre toti userii, de la inceputul rularii
{
    printf(activity_log);
}
