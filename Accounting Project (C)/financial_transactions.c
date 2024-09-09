#include "financial_transactions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char activity_log[100000], str[20], msg[100];
extern int nr_clients;

int verify_balance(double balance, double val) /// verificarea ca poate avea loc o anumita operatie asupra tipului de cont bancar (nu se poate ca balanta sa fie negativa)
{
    if(balance + val >= 0)
        return 1;
    return 0;
}

void deposit(struct clients *c, char *user_name, char *account_type, double val) /// functionalitatea de depozitare / extragere suma de bani intr-un / dintr-un tip de cont bancar
{
    strcat(activity_log, user_name);

    sprintf(str, "%.2lf", val);

    if(val >= 0)
        strcat(activity_log, " is trying to deposit, from the account type: ");
    else
        strcat(activity_log, " is trying to withdraw, from the account type: ");
    strcat(activity_log, account_type);
    strcat(activity_log, ", the sum: ");
    strcat(activity_log, str);
    strcat(activity_log, " and the message shown is: ");

    for(int i = 0; i < nr_clients; i ++)
        if( strcmp(c[i].name, user_name) == 0 )
        {
            for(int j = 0; j < c[i].nr_accounts; j ++)
                if( strcmp(c[i].accounts[j].type, account_type) == 0 )
                {
                    if(verify_balance(c[i].accounts[j].balance, val) == 1)
                    {
                        c[i].accounts[j].balance += val;
                        sprintf(str, "%.2lf", val);

                        if(val >= 0)
                            strcpy(msg, "Deposit: +"); /// pentru valori pozitive ale lui val -> depozitare
                        else
                            strcpy(msg, "Withdraw: "); /// pentru valori negative ale lui val -> extragere

                        strcat(msg, str);

                        strcat(c[i].accounts[j].transaction_register, msg);
                        strcat(c[i].accounts[j].transaction_register, "\n");
                        ///printf("%s", c[i].accounts[j].transaction_register);

                        strcat(msg, " | Balance: ");
                        sprintf(str, "%.2lf", c[i].accounts[j].balance);
                        strcat(msg, str);
                        strcat(msg, "\n");
                        strcat(c[i].accounts[j].acc_statement, msg);

                        printf("The transaction was completed successfully!\n");

                        strcat(activity_log, "'The transaction was completed successfully!'\n");

                        ///printf(c[i].accounts[j].acc_statement);
                        return;
                    }
                    else
                    {
                        printf("It is not possible to perform the transaction!\n");
                        strcat(activity_log, "'It is not possible to perform the transaction!'\n");
                        return;
                    }
                }
            printf("The client with the name entered does not have the account type entered!\n");
            strcat(activity_log, "'The client with the name entered does not have the account type entered!'\n");
            return;
        }
    printf("There is no client with the name entered!\n");
    strcat(activity_log, "'There is no client with the name entered!'\n");
}

void transfer(struct clients *c, char *user_name, char *account_type, char *second_user_name, char *second_account_type, double val)
{
    /// functionalitatea de transfer de bani - val - de la user-ul cu numele: user_name si tipul de cont: account_type, la user-ul cu numele: second_user_name si tipul de cont: second_account_type

    sprintf(str, "%.2lf", val);

    strcat(activity_log, user_name);
    strcat(activity_log, " is trying to transfer, from the account type: ");
    strcat(activity_log, account_type);
    strcat(activity_log, ", to the account type: ");
    strcat(activity_log, second_account_type);
    strcat(activity_log, ", of the user: ");
    strcat(activity_log, second_user_name);
    strcat(activity_log, " the sum: ");
    strcat(activity_log, str);
    strcat(activity_log, " and the message shown is: ");

    for(int i = 0; i < nr_clients; i ++)
        if( strcmp(c[i].name, user_name) == 0 )
        {
            for(int j = 0; j < c[i].nr_accounts; j ++)
            {
                if(strcmp(c[i].accounts[j].type, account_type) == 0)
                {
                    if(verify_balance(c[i].accounts[j].balance, val * (-1)) == 1)
                    {
                        /// search for the second user
                        //printf("nr_clients = %d\n", nr_clients);
                        for(int k = 0; k < nr_clients; k ++)
                        {
                            //printf("%s si %s\n", c[k].name, second_user_name);
                            if( strcmp(c[k].name, second_user_name) == 0 )
                            {
                                for(int l = 0; l < c[k].nr_accounts; l ++)
                                    if(strcmp(c[k].accounts[l].type, second_account_type) == 0)
                                    {
                                        c[k].accounts[l].balance += val; /// first user gives the money
                                        c[i].accounts[j].balance -= val; /// second user receives the money

                                        sprintf(str, "%.2lf", val);

                                        strcpy(msg, "Transfer: -");
                                        strcat(msg, str);
                                        strcat(msg, " to ");
                                        strcat(msg, second_user_name);

                                        strcat(c[i].accounts[j].transaction_register, msg);
                                        strcat(c[i].accounts[j].transaction_register, "\n");

                                        strcat(msg, " | Balance: ");
                                        sprintf(str, "%.2lf", c[i].accounts[j].balance);
                                        strcat(msg, str);
                                        strcat(msg, "\n");
                                        strcat(c[i].accounts[j].acc_statement, msg);

                                        sprintf(str, "%.2lf", val);
                                        strcpy(msg, "Transfer: +");
                                        strcat(msg, str);
                                        strcat(msg, " from ");
                                        strcat(msg, user_name);

                                        strcat(c[k].accounts[l].transaction_register, msg);
                                        strcat(c[k].accounts[l].transaction_register, "\n");

                                        strcat(msg, " | Balance: ");
                                        sprintf(str, "%.2lf", c[k].accounts[l].balance);
                                        strcat(msg, str);
                                        strcat(msg, "\n");
                                        strcat(c[k].accounts[l].acc_statement, msg);

                                        ///printf("%s", c[i].accounts[j].acc_statement);
                                        ///printf("%s", c[k].accounts[l].acc_statement);

                                        printf("The transfer completed successfully!\n");
                                        strcat(activity_log, "'The transfer completed successfully!'\n");
                                        return;
                                    }
                                printf("The second user does not have the account type it was entered!\n");
                                strcat(activity_log, "'The second user does not have the account type it was entered!'\n");
                                return;
                            }
                        }
                        printf("There is not any user with the second name entered!\n");
                        strcat(activity_log, "'There is not any user with the second name entered!'\n");
                        return;
                    }
                    else
                    {
                        printf("It is not possible to perform the transaction!\n");
                        strcat(activity_log, "'It is not possible to perform the transaction!'\n");
                        return;
                    }
                }
            }
                printf("The first user does not have the account type that was entered!\n");
                strcat(activity_log, "'The first user does not have the account type that was entered!'\n");
                return;
        }
    printf("The first user does not exist!\n");
    strcat(activity_log, "'The first user does not exist!'\n");
}

int pay(struct clients *c, char* user_name, char * account_type, char * second_user_name, char * second_account_type, double val)
{
    /// functionalitate prin care user-ul cu numele: user_name si tipul de cont: account_type plateste user-ului cu numele: second_user_name si tipul de cont: second_account_type, suma - val
    /// si automat, user_name devine clientul lui second_user_name - firma

    sprintf(str, "%.2lf", val);

    strcat(activity_log, user_name);
    strcat(activity_log, " is trying to transfer, from the account type: ");
    strcat(activity_log, account_type);
    strcat(activity_log, ", to the account type: ");
    strcat(activity_log, second_account_type);
    strcat(activity_log, ", of the user-company: ");
    strcat(activity_log, second_user_name);
    strcat(activity_log, " the sum: ");
    strcat(activity_log, str);
    strcat(activity_log, " and the message shown is: ");

    for(int i = 0; i < nr_clients; i ++)
        if( strcmp(c[i].name, user_name) == 0 )
        {
            for(int j = 0; j < c[i].nr_accounts; j ++)
            {
                if(strcmp(c[i].accounts[j].type, account_type) == 0)
                {
                    if(verify_balance(c[i].accounts[j].balance, val * (-1)) == 1)
                    {
                        /// search for the second user
                        //printf("nr_clients = %d\n", nr_clients);
                        for(int k = 0; k < nr_clients; k ++)
                        {
                            //printf("%s si %s\n", c[k].name, second_user_name);
                            if( strcmp(c[k].name, second_user_name) == 0 )
                            {
                                for(int l = 0; l < c[k].nr_accounts; l ++)
                                    if(strcmp(c[k].accounts[l].type, second_account_type) == 0)
                                    {
                                        c[k].accounts[l].balance += val; /// first user gives the money
                                        c[i].accounts[j].balance -= val; /// second user receives the money

                                        sprintf(str, "%.2lf", val);

                                        strcpy(msg, "Transfer: -");
                                        strcat(msg, str);
                                        strcat(msg, " to ");
                                        strcat(msg, second_user_name);

                                        strcat(c[i].accounts[j].expense_rep, msg);
                                        strcat(c[i].accounts[j].expense_rep, "\n");

                                        strcat(msg, " | Balance: ");
                                        sprintf(str, "%.2lf", c[i].accounts[j].balance);
                                        strcat(msg, str);
                                        strcat(msg, "\n");
                                        strcat(c[i].accounts[j].acc_statement, msg);

                                        sprintf(str, "%.2lf", val); /// retinem doar 2 zecimale
                                        strcpy(msg, "Transfer: +");
                                        strcat(msg, str);
                                        strcat(msg, " from ");
                                        strcat(msg, user_name);

                                        strcat(c[k].accounts[l].expense_rep, msg);
                                        strcat(c[k].accounts[l].expense_rep, "\n");

                                        strcat(msg, " | Balance: ");
                                        sprintf(str, "%.2lf", c[k].accounts[l].balance);
                                        strcat(msg, str);
                                        strcat(msg, "\n");
                                        strcat(c[k].accounts[l].acc_statement, msg);

                                        ///printf("%s", c[i].accounts[j].acc_statement);
                                        ///printf("%s", c[k].accounts[l].acc_statement);

                                        /// search for c[i]
                                        for(int m = 0; m < c[k].nr_customers; m ++)
                                            if(strcmp(c[k].customers[m].name, user_name) == 0)
                                            {
                                                c[k].customers[m].nr_payments ++;
                                                printf("The payment completed successfully!\n");
                                                strcat(activity_log, "'The payment completed successfully!'\n");
                                                return -1;
                                            }
                                        int nr_customers = c[k].nr_customers;
                                        c[k].customers[nr_customers].nr_payments = 1;
                                        c[k].customers[nr_customers].message[0] = '\0';
                                        strcpy(c[k].customers[nr_customers].name, user_name);
                                        //printf("%s\n", c[k].customers[nr_customers].name);
                                        c[k].nr_customers ++;
                                        ///c[k].customers = realloc(c[k].customers, (nr_customers + 1) * sizeof(struct manage_customers));

                                        printf("The payment completed successfully!\n");
                                        strcat(activity_log, "'The payment completed successfully!'\n");
                                        return k;
                                    }
                                printf("The second user does not have the account type it was entered!\n");
                                strcat(activity_log, "'The second user does not have the account type it was entered!'\n");
                                return -1;
                            }
                        }
                        printf("There is not any user with the second name entered!\n");
                        strcat(activity_log, "'There is not any user with the second name entered!'\n");
                        return -1;
                    }
                    else
                    {
                        printf("It is not possible to perform the transaction!\n");
                        strcat(activity_log,"'It is not possible to perform the transaction!'\n");
                        return -1;
                    }
                }
            }
                printf("The first user does not have the account type that was entered!\n");
                strcat(activity_log, "'The first user does not have the account type that was entered!'\n");
                return -1;
        }
    printf("The first user does not exist!\n");
    strcat(activity_log, "'The first user does not exist!'\n");
    return -1;
}
