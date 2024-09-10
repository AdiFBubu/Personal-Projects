#include "domain.h"
#include <iostream>

Locatar:: Locatar (int ap, string nume, string tip, double suprafata): ap{ap}, nume{nume}, tip{tip}, suprafata{suprafata} {

}

Locatar:: Locatar(const Locatar& ot)
{
    //std::cout << "copy constructor\n";
    ap = ot.get_ap();
    nume = ot.get_nume();
    tip = ot.get_tip();
    suprafata = ot.get_suprafata();
}

int Locatar:: get_ap() const
{
    return ap;
}

string Locatar:: get_nume() const
{
    return nume;
}

string Locatar:: get_tip() const
{
    return tip;
}

double Locatar:: get_suprafata() const
{
    return suprafata;
}

std::ostream& operator << (std::ostream& os, const Locatar& ob)
{
    return os << "Ap: " << ob.ap << ", Nume: " << ob.nume << ", Tip: " << ob.tip << ", Suprafata: " << ob.suprafata << '\n';
}

bool Locatar:: operator==(const Locatar& ot) const
{
    return ( ap == ot.get_ap() );

}

void Locatar:: set_ap(int val)
{
    this->ap = val;
}

void Locatar:: set_nume(string nume)
{
    this->nume = nume;
}


void Locatar:: set_tip(string tip)
{
    this->tip = tip;
}

void Locatar:: set_suprafata(double suprafata)
{
    this->suprafata = suprafata;
}


bool cmpNume(const Locatar& a, const Locatar& b)
{
    return a.get_nume() < b.get_nume();
}

bool cmpSuprafata(const Locatar& a, const Locatar& b)
{
    return a.get_suprafata() < b.get_suprafata();
}

bool cmpTipSuprafata(const Locatar& l1, const Locatar& l2)
{
    return ((l1.get_tip() < l2.get_tip()) ||
            (l1.get_tip() == l2.get_tip() && l1.get_suprafata() < l2.get_suprafata()));
}