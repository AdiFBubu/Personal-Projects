#ifndef ACCOUNTMANAGEMENT_H
#define ACCOUNTMANAGEMENT_H

#include "struct.h"

void create_account(struct clients *c, char *user_name, char *account_type); /// creeaza un cont bancar si/sau un tip de cont bancar asociat


int edit_account(struct clients *c, char *user_name, char *new_user_name); /// inlocuirea numelui user-ului cu un nou nume: new_user_name


void delete_account(struct clients *c, char *user_name, char *account_type); /// stergerea tipului de cont bancar: account_type asociat clientului cu numele: user_name

void add_info(struct clients* c, int index, int id_client, char *info); /// adaugarea unui mesaj - info - user-ului cu id-ul: id_client, de catre user-ul cu id-ul: index



#endif // ACCOUNTMANAGEMENT_H
