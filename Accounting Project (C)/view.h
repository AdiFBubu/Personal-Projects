#ifndef VIEW_H
#define VIEW_H

#include "struct.h"

int view_clients(struct clients *c, char *user_name); /// afisarea tuturor clientilui user-ului cu numele: user_name

void view_account_statement(struct clients* c, char* user_name, char* account_type); /// afisarea tuturor operatiilor efectuate la nivelul tipului de cont: account_type, asociat user-ului cu numele: user_name


void view_balance(struct clients*c, char *user_name, char *account_type); ///afisarea balantei curente a tipului de cont: account_type, asociat clientului cu numele: user_name


void view_transaction_register(struct clients*c, char *user_name, char *account_type); /// afisare registru de tranzactii - depozitare/ extragere/ transfer


void view_expense_report(struct clients*c, char *user_name, char *account_type); /// afisare raport de cheltuieli -> payments catre firme


void view_activity_log(); /// afisarea tuturor operatiilor efectuate de catre toti userii, de la inceputul rularii

#endif // VIEW_H
