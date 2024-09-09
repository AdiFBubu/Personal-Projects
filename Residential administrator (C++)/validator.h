#pragma once

#include "domain.h"

class ValidatorException: public std::exception{
    string msg;
public:
    /*
     * constructorul clasei ValidatorException
     * msg - string, contine mesajul exceptiei
     */
    ValidatorException(string);

    /*
     * returneaza mesajul exceptiei
     */
    string getMessage() const;
};

class Validator{
public:
    /*
     * returneaza daca un anumit locatar are compuri valide
     * l - const Locatar&, locatarul de validat
     * returneaza true daca are toate campurile valide
     * @ arunca exceptie daca exista cel putin un camp invalid
     */
    bool validareLocatar(const Locatar&) const;

    bool validareAp(int ap) const;

    bool validareExport(string nume, string tip) const;
};