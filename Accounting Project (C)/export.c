#include "export.h"
#include <stdio.h>
#include <string.h>

extern int nr_clients;

void export_data(struct clients* c, char *file_name) /// exportarea datelor financiare -> nume client, balantele corespunzatoare tuturor tipurilor de cont bancar (sau mesajul 'doesn't exist' daca user-ul nu are tipul respectiv de cont bancar) si numarul de clienti ai uesr-ului - firma
{
    FILE *file = fopen(file_name, "w");
    if(file == NULL) /// daca are loc o eroare la deschiderea fisierului
    {
        perror("Error opening the file for writing!");
        return;
    }
    fprintf(file, "Name, Balance - savings account, Balance - checking account, Balance - credit account, Nr. customers\n");
    char acc[3][20]; /// vector de cuvinte (3 cuvinte, un cuvant are maxim 19 litere + caracterul NULL)
    strcpy(acc[0], "savings account");
    strcpy(acc[1], "checking account");
    strcpy(acc[2], "credit account");
    for(int i = 0; i < nr_clients; i ++)
    {
        fprintf(file, "%s", c[i].name);
        for(int k = 0; k < 3; k ++)
        {
            int found = 0;
            for(int j = 0; j < c[i].nr_accounts && found == 0; j ++)
                if(strcmp(c[i].accounts[j].type, acc[k]) == 0)
                    fprintf(file, ", %.2lf", c[i].accounts[j].balance), found = 1;
            if(found == 0) /// user_name nu si-a facut pana in acest moment tipul - acc[k] - de cont bancar
                fprintf(file, ", %s", "doesn't have");
        }
        fprintf(file, ", %d\n", c[i].nr_customers);
    }

    fclose(file); /// inchidere fisier
}
