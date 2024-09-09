#ifndef FINANCIALTRANSACTIONS_H
#define FINANCIALTRANSACTIONS_H

#include "struct.h"

int verify_balance(double balance, double val); /// verificarea ca poate avea loc o anumita operatie asupra tipului de cont bancar (nu se poate ca balanta sa fie negativa)

void deposit(struct clients *c, char *user_name, char *account_type, double val); /// functionalitatea de depozitare / extragere suma de bani intr-un / dintr-un tip de cont bancar

void transfer(struct clients *c, char *user_name, char *account_type, char *second_user_name, char *second_account_type, double val);


int pay(struct clients *c, char* user_name, char * account_type, char * second_user_name, char * second_account_type, double val);

#endif // FINANCIALTRANSACTIONS_H
