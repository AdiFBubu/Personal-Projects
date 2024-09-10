#pragma once
#include <string>
using std::string;

class Locatar
{

private:

    int ap;
    string nume;
    string tip;
    double suprafata;

    /*
     * functie prietena clasei Locatari, ce supraincarca operatorul <<
     * os - std::ostream&, obiect standard de flux de iesire
     * ob - const Locatar&, referinta unui obiect al clasei Locatar, ce se doreste a se afisa
     * impune ce se va afisa in cazul apelarii operatorului << pentru un obiect de clasa Locatar si returneaza referinta la operatorul de iesire, oferind posibilitatea apelarii in lant a operatorului <<
     */
    friend std::ostream& operator << (std::ostream& os, const Locatar& ob);

public:

    /*
     * contructorul clasei Locatar
     * ap - int, numarul apartamentului
     * nume - string, numele proprietarului
     * tip - string, tipul apartamentului
     * suprafata - double, suprafata apartamentului
     */
    Locatar() = default;

    Locatar (int, string, string, double);

    Locatar(const Locatar& ot);

    /*
     * returneaza apartamentul obiectului de clasa Locatar
     */
    int get_ap() const;

    /*
     * returneaza numele proprietarului ce apartine obiectului de clasa Locatar
     */
    string get_nume() const;

    /*
     * returneaza tipul apartamentului ce apartine obiectului de clasa Locatar
     */
    string get_tip() const;

    /*
     * returneaza suprafata ce apartine obiectului de clasa Locatar
     */
    double get_suprafata() const;

    /*
     * seteaza o valoare campului apartament al obiectului de clasa Locatar
     */
    void set_ap(int);

    /*
     * seteaza o valoare campului nume al obiectului de clasa Locatar
     */
    void set_nume(string);

    /*
     * seteaza o valoare campului tip al obiectului de clasa Locatar
     */
    void set_tip(string);

    /*
     * seteaza o valoare campului suprafata al obiectului de clasa Locatar
     */
    void set_suprafata(double);

    /*
     * functie ce supraincarca operatorul == al clasei Locatar
     * ot - const Locatar&, referinta la un obiect al clasei Locatar
     * stabileste ce va reprezenta == in cazul obiectelor de clasa Locatar si returneaza validitatea (bool) conditiei stabilite
     */
    bool operator==(const Locatar& ot) const;
};

bool cmpNume(const Locatar&, const Locatar&);
bool cmpSuprafata(const Locatar&, const Locatar&);
bool cmpTipSuprafata(const Locatar&, const Locatar&);
