#include <stdio.h>
#include <string.h>

#include "checkings.h"

extern char pass[20], pass_current[20], aux;
extern int activity_log[100000];

int security() /// functie ce se ocupa de verificarea corectitudinii parolei introduse de user
{
    while(1)
    {
        printf("(write 'x' to shut down)\n"); /// 'x' -> oprire rulare consola
        printf("Password is: ");
        scanf("%s", pass_current);
        if(strcmp(pass_current, "x") == 0)
            return 0;
        scanf("%c", &aux);
        if(strcmp(pass, pass_current) == 0)
        {
            strcat(activity_log, "Someone logged in!\n");
            printf("Access granted!\n");
            return 1;
        }
        else
            printf("Incorrect password! Try again!\n\n"); /// bucla pana la introducerea unei parole corecte sau pana la introducerea literei 'x'
    }
}

int validate_accountType(char *account_type) /// validator tip de cont bancar
{
    if(strcmp(account_type, "savings account") == 0 ||
       strcmp(account_type, "checking account") == 0 ||
       strcmp(account_type, "credit account") == 0)
        return 1;
    return 0;
}
