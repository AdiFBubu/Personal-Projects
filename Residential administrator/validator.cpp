#include "validator.h"
#include <iostream>
#include <cstring>

ValidatorException:: ValidatorException(string msg): msg{msg}{
}

string ValidatorException:: getMessage() const
{
    return msg;
}

bool Validator:: validareLocatar(const Locatar& l) const
{
    string msg;
    if (l.get_ap() < 0)
        msg += "Numar apartament gresit!\n";
    if (l.get_nume() == "")
        msg += "Nume proprietar invalid!\n";
    if (l.get_tip() == "")
        msg += "Tip apartament invalid!\n";
    if (l.get_suprafata() < 0)
        msg += "Suprafata invalida!\n";
    if (msg.length() != 0)
        throw (ValidatorException(msg));
    return true;
}

bool Validator:: validareAp(int ap) const
{
    if (ap < 0)
        throw ValidatorException("Numar apartament gresit!\n");
    return true;
}

bool Validator::validareExport(string nume, string tip) const
{
    string msg;
    if (nume.empty())
        msg += "Nume invalid!\n";
    if (tip.empty())
        msg += "Tip invalid!\n";
    else if (tip != "csv" && tip != "html")
        msg += "Tipul poate fi doar 'csv' sau 'html'!\n";
    if (strchr(nume.c_str(), '.') != NULL)
        msg += "Numele nu poate avea caracterul '.' in componenta!\n";
    if (!msg.empty())
        throw ValidatorException(msg);
    return true;
}