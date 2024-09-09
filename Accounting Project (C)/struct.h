#ifndef STRUCT_H
#define STRUCT_H

struct manage_customers /// structura ce retine detalii despre clientii unei companii
{
    char name[20];
    int nr_payments;
    char message[20];
};

struct financial_account /// structura ce retine detalii despre un tip de cont bancar
{
    char type[20], acc_statement[400], transaction_register[400], expense_rep[400];
    /// transaction_register retine tot ce e legat de depozitare/extragere/transfer
    /// expense_rep  retine tot ce e legat de payments
    double balance;
    //char *record = (char *)malloc(20 * sizeof(char));
};

struct clients /// structura ce retine detalii despre un client
{
    char name[20];
    int nr_accounts, nr_customers;
    struct financial_account accounts[3]; /// sunt 3 tipuri de conturi bancare
    struct manage_customers* customers; /// numar necunoscut de clienti, poate fi si 0

};

#endif // STRUCT_H
