#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "struct.h"
#include "menu.h"
#include "checkings.h"
#include "account_management.h"
#include "financial_transactions.h"
#include "view.h"
#include "export.h"

char pass[20] = "password"; /// parola de accesare a datelor financiare este: 'password'
char pass_current[20], aux, str[20], msg[100], bin[100];
char user_name[20], account_type[20];
char text1[20], text2[20], letter;
char activity_log[100000]; /// retine toate operatiile realizare de useri
int cmd, nr_clients, p;

int main()
{
    struct clients* c = (struct clients *)malloc(1 * sizeof(struct clients)); /// alocare dinamica de memorie pentru clienti
    while(1)
    {
        if(security() == 1) /// parola
        {
            printf("Enter your name: "); /// nume user
            fgets(user_name, sizeof(user_name), stdin);
            user_name[strlen(user_name) - 1] = '\0';
            while(1)
            {
                menu();
                p = scanf("%d", &cmd);
                while(p == 0) /// citirea corecta a datelor de intrare
                {
                    fgets(bin, sizeof(bin), stdin); /// extragerea textului rezidual
                    printf("You have to enter an integer!\n\n");
                    menu();
                    p = scanf("%d", &cmd);
                }

                /*
                menu();
                fgets(text1, sizeof(text1), stdin);
                text1[strlen(text1) - 1] = '\0';
                letter = text1[0];
                cmd = atoi(text1);
                sprintf(text2, "%d", cmd);
                p = strlen(text2) - strlen(text1);
                while(p != 0 || isdigit(letter) == 0)
                {
                    printf("You have to enter an integer!\n\n");
                    menu();
                    fgets(text1, sizeof(text1), stdin);
                    text1[strlen(text1) - 1] = '\0';
                    letter = text1[0];
                    cmd = atoi(text1);
                    sprintf(text2, "%d", cmd);
                    p = strlen(text2) - strlen(text1);
                }*/
                if(cmd == 1)
                {
                    input_menu();
                    p = scanf("%d", &cmd);
                    while(p == 0)
                    {
                        fgets(bin, sizeof(bin), stdin);
                        printf("You have to enter an integer!\n\n");
                        input_menu();
                        p = scanf("%d", &cmd);
                    }
                    /*
                    input_menu();
                    fgets(text1, sizeof(text1), stdin);
                    text1[strlen(text1) - 1] = '\0';
                    letter = text1[0];
                    cmd = atoi(text1);
                    sprintf(text2, "%d", cmd);
                    p = strlen(text2) - strlen(text1);
                    while(p != 0 || isdigit(letter) == 0)
                    {
                        printf("You have to enter an integer!\n\n");
                        input_menu();
                        fgets(text1, sizeof(text1), stdin);
                        text1[strlen(text1) - 1] = '\0';
                        letter = text1[0];
                        cmd = atoi(text1);
                        sprintf(text2, "%d", cmd);
                        p = strlen(text2) - strlen(text1);
                    }*/

                    if(cmd == 1)
                    {
                        printf("Type of account: ");
                        scanf("%c", &aux);
                        fgets(account_type, sizeof(account_type), stdin); /// citirea intregii linii
                        account_type[strlen(account_type) - 1] = '\0'; /// eliminarea caracterului '\n' de la final
                        //printf("%s\n", account_type);
                        if(validate_accountType(account_type) == 1) /// validarea tipului de cont bancar introdus
                        {
                            int val = nr_clients;
                            create_account(c, user_name, account_type);
                            if(val != nr_clients)
                                c = realloc(c, (nr_clients + 1) * sizeof(struct clients)); /// realocare dinamica de memorie pentru clienti (creste numarul de clienti)
                            //for(int i = 0; i < nr_clients; i ++)
                                //printf("%s de lungime %d\n", c[i].name, strlen(c[i].name));
                        }
                        else
                            printf("The account type must be: 'savings account', 'checking account' or 'credit account'\n");
                    }
                    else if(cmd == 2)
                    {
                        char new_user_name[20];
                        scanf("%c", &aux);
                        printf("Enter the new name: ");
                        fgets(new_user_name, sizeof(new_user_name), stdin);
                        new_user_name[strlen(new_user_name) - 1] = '\0';
                        int o = edit_account(c, user_name, new_user_name);
                        if(o == 1)
                            strcpy(user_name, new_user_name);
                        //printf("%s", c[0].name);
                    }
                    else if(cmd == 3)
                    {
                        printf("Type of account: ");
                        scanf("%c", &aux);
                        fgets(account_type, sizeof(account_type), stdin);
                        account_type[strlen(account_type) - 1] = '\0';
                        if(validate_accountType(account_type) == 1)
                            delete_account(c, user_name, account_type);
                    }
                    else if(cmd == 4)
                    {
                        transactions_menu();
                        p = scanf("%d", &cmd);
                        while(p == 0)
                        {
                            fgets(bin, sizeof(bin), stdin);
                            printf("You have to enter an integer!\n\n");
                            transactions_menu();
                            p = scanf("%d", &cmd);
                        }
                        if(cmd == 1)
                        {
                            printf("Type of account: ");
                            scanf("%c", &aux);
                            fgets(account_type, sizeof(account_type), stdin);
                            account_type[strlen(account_type) - 1] = '\0';
                            double val;

                            printf("Enter the value you want to deposit: ");
                            p = scanf("%lf", &val);
                            while(p == 0)
                            {
                                fgets(bin, sizeof(bin), stdin);
                                printf("You have to enter an integer!\n\n");
                                printf("Enter the value you want to deposit: ");
                                p = scanf("%lf", &val);
                            }
                            scanf("%c", &aux);
                            if(val < 0) /// nu se poate introduce o valoare negativa pentru suma de bani, ea va fi mereu pozitiva si, in functie de operatie (depozitare/extragere), se va inmulti, dupa caz, cu -1 in momentul transmiterii parametrilor functiei de depozitare/extragere
                                printf("You can not enter a negative value!\n");
                            else
                                deposit(c, user_name, account_type, val);
                            //printf("%lf", c[0].accounts[0].balance);
                        }
                        else if(cmd == 2)
                        {
                            printf("Type of account: ");
                            scanf("%c", &aux);
                            fgets(account_type, sizeof(account_type), stdin);
                            account_type[strlen(account_type) - 1] = '\0';
                            double val;
                            printf("Enter the value you want to withdraw: ");
                            p = scanf("%lf", &val);
                            while(p == 0)
                            {
                                fgets(bin, sizeof(bin), stdin);
                                printf("You have to enter an integer!\n\n");
                                printf("Enter the value you want to withdraw: ");
                                p = scanf("%lf", &val);
                            }
                            scanf("%c", &aux);
                            if(val < 0)
                                printf("You can not enter a negative value!\n");
                            else
                                deposit(c, user_name, account_type, val * (-1));
                            //printf("%lf", c[0].accounts[0].balance);
                        }
                        else if(cmd == 3)
                        {
                            printf("Type of account: ");
                            scanf("%c", &aux);
                            fgets(account_type, sizeof(account_type), stdin);
                            account_type[strlen(account_type) - 1] = '\0';
                            printf("Enter the name of the user you want to transfer money to: ");
                            char second_user_name[20], second_account_type[20];
                            fgets(second_user_name, sizeof(second_user_name), stdin);
                            second_user_name[strlen(second_user_name) - 1] = '\0';
                            //printf("%s de lungime %d\n", second_user_name, strlen(second_user_name));
                            printf("Enter the type of account for this user: ");
                            fgets(second_account_type, sizeof(second_account_type), stdin);
                            second_account_type[strlen(second_account_type) - 1] = '\0';
                            double val;
                            printf("Enter the value you want to transfer to the user: ");
                            p = scanf("%lf", &val);
                            while(p == 0)
                            {
                                fgets(bin, sizeof(bin), stdin);
                                printf("You have to enter an integer!\n\n");
                                printf("Enter the value you want to transfer to the user: ");
                                p = scanf("%lf", &val);
                            }
                            scanf("%c", &aux);
                            transfer(c, user_name, account_type, second_user_name, second_account_type, val);
                            //printf("%lf\n", c[0].accounts[0].balance);
                            //printf("%lf\n", c[1].accounts[0].balance);
                        }
                        else if(cmd == 4)
                        {
                            printf("Type of account: ");
                            scanf("%c", &aux);
                            fgets(account_type, sizeof(account_type), stdin);
                            account_type[strlen(account_type) - 1] = '\0';
                            printf("Enter the name of the user you want to transfer money to: ");
                            char second_user_name[20], second_account_type[20];
                            fgets(second_user_name, sizeof(second_user_name), stdin);
                            second_user_name[strlen(second_user_name) - 1] = '\0';
                            printf("Enter the type of account for this user: ");
                            fgets(second_account_type, sizeof(second_account_type), stdin);
                            second_account_type[strlen(second_account_type) - 1] = '\0';
                            double val;
                            printf("Enter the value you want to transfer to the user: ");
                            p = scanf("%lf", &val);
                            while(p == 0)
                            {
                                fgets(bin, sizeof(bin), stdin);
                                printf("You have to enter an integer!\n\n");
                                printf("Enter the value you want to transfer to the user: ");
                                p = scanf("%lf", &val);
                            }
                            scanf("%c", &aux);
                            int k = pay(c, user_name, account_type, second_user_name, second_account_type, val);
                            int nr_customers = c[k].nr_customers;
                            if(k != -1) /// realocare dinamica de memorie pentru clientii user-ului cu numele: user_name si indexul - k - in structura c de tip clients
                                c[k].customers = realloc(c[k].customers, (nr_customers + 1) * sizeof(struct manage_customers));
                        }
                    }
                    else if(cmd == 5)
                    {
                        int index = view_clients(c, user_name);
                        if(index != -1)
                        {
                            while(1)
                            {
                                business_menu();
                                p = scanf("%d", &cmd);
                                while(p == 0)
                                {
                                    fgets(bin, sizeof(bin), stdin);
                                    printf("You have to enter an integer!\n\n");
                                    business_menu();
                                    p = scanf("%d", &cmd);
                                }
                                if(cmd == 1)
                                {
                                    printf("Enter the id of the client you want to enter information about: ");
                                    char info[30];
                                    int id;
                                    p = scanf("%d", &id);
                                    while(p == 0)
                                    {
                                        fgets(bin, sizeof(bin), stdin);
                                        printf("You have to enter an integer!\n\n");
                                        printf("Enter the id of the client you want to enter information about: ");
                                        p = scanf("%d", &id);
                                    }
                                    scanf("%c", &aux);
                                    printf("Enter the information you want to add to the client: ");
                                    fgets(info, sizeof(info), stdin);
                                    info[strlen(info) - 1] = '\0';
                                    add_info(c, index, id, info);
                                    view_clients(c, user_name);
                                }
                                else if(cmd == 2)
                                    break;
                                else
                                    printf("You have to enter '1' or '2'!\n"); /// atentionare user in cazul in care introduce alte numere decat 1 si 2
                            }
                        }
                    }

                    else
                    {
                        printf("You have to enter a number between 1 and 5!");
                        scanf("%c", &aux);
                    }


                }

                else if(cmd == 2)
                {
                    view_menu();
                    p = scanf("%d", &cmd);
                    while(p == 0)
                    {
                        fgets(bin, sizeof(bin), stdin);
                        printf("You have to enter an integer!\n\n");
                        view_menu();
                        p = scanf("%d", &cmd);
                    }

                    if(cmd == 1)
                    {
                        scanf("%c", &aux);
                        printf("Enter the type of account whose statement you want to view: ");
                        fgets(account_type, sizeof(account_type), stdin);
                        account_type[strlen(account_type) - 1] = '\0';
                        view_account_statement(c, user_name, account_type);
                    }

                    else if(cmd == 2)
                    {
                        scanf("%c", &aux);
                        printf("Enter the type of account whose statement you want to view: ");
                        fgets(account_type, sizeof(account_type), stdin);
                        account_type[strlen(account_type) - 1] = '\0';
                        view_balance(c, user_name, account_type);
                    }

                    else if(cmd == 3)
                    {
                        scanf("%c", &aux);
                        printf("Enter the type of account whose statement you want to view: ");
                        fgets(account_type, sizeof(account_type), stdin);
                        account_type[strlen(account_type) - 1] = '\0';
                        view_transaction_register(c, user_name, account_type);
                    }

                    else if(cmd == 4)
                    {
                        scanf("%c", &aux);
                        printf("Enter the type of account whose statement you want to view: ");
                        fgets(account_type, sizeof(account_type), stdin);
                        account_type[strlen(account_type) - 1] = '\0';
                        view_expense_report(c, user_name, account_type);
                    }

                    else
                    {
                        printf("You have to enter a number between 1 and 4!\n");
                        scanf("%c", &aux);
                    }
                }

                else if(cmd == 3)
                    view_activity_log();

                else if(cmd == 4)
                {
                    char file_name[30];
                     export_menu();
                     p = scanf("%d", &cmd);
                     while(p == 0)
                     {
                        fgets(bin, sizeof(bin), stdin);
                        printf("You have to enter an integer!\n\n");
                        export_menu();
                        p = scanf("%d", &cmd);
                     }
                     scanf("%c", &aux);
                     printf("Enter the name of the file: "); /// citire nume fisier in care vor fi exportate datele financiare curente
                     fgets(file_name, sizeof(file_name), stdin);
                     file_name[strlen(file_name) - 1] = '\0';
                     if(cmd == 1) /// in functie de optiune, se va atasa la nume extensia '.csv' (~excel) sau '.txt" (~fisier text)
                     {
                        strcat(file_name, ".csv");
                        export_data(c, file_name);
                     }
                     else if(cmd == 2)
                     {
                        strcat(file_name, ".txt");
                        export_data(c, file_name);
                     }
                     else
                         printf("You have to enter '1' or '2'!\n");
                }

                else if(cmd == 5)
                    break;

                else
                {
                    printf("You have to enter '1', '2', '3' or '4'!\n");
                    scanf("%c", &aux);
                }

            }
        }
        else
            break;
    }
    for(int i = 0; i < nr_clients; i ++)
        free(c[i].customers); /// eliberare spatiu alocat tuturor clientilor user-ilor
    free(c); /// eliberare spatiu alocat tuturor user-ilor
    return 0;
}
