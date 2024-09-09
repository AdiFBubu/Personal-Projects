#ifndef EXPORT_H
#define EXPORT_H

#include "struct.h"

void export_data(struct clients* c, char *file_name); /// exportarea datelor financiare -> nume client, balantele corespunzatoare tuturor tipurilor de cont bancar (sau mesajul 'doesn't exist' daca user-ul nu are tipul respectiv de cont bancar) si numarul de clienti ai uesr-ului - firma

#endif // EXPORT_H
