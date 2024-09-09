#pragma once

#include "repo.h"
#include "validator.h"
#include "notificationList.h"
#include <vector>
#include <functional>
#include <map>
#include <memory>
#include "undo.h"
using std::unique_ptr;

using std::vector;
using std::function;
using std::map;

class LocatariService
{
private:
    LocatarAbstractRepo& repo;
    const Validator& val;
    notificationList notif{repo};

    vector<unique_ptr<ActiuneUndo>> undoActions;

public:
    /*
     * constructorul clasei LocatariService
     * repo - LocatarRepo&, referinta catre repository-ul de locatari
     * val - const Validator&, referinta catre validator
     */
    LocatariService(LocatarAbstractRepo& repo, const Validator& val);

    /*
     * se interzice crearea de copii de obiecte de clasa LocatariService
     */
    LocatariService(const LocatariService& ot) = delete;

    /*
     * adauga un locatar in lista de locatari
     * ap - int, numarul apartamentului
     * nume - string, numele proprietarului
     * tip - string, tipul apartamentului
     * suprafata - double, suprafata apartamentului
     * @ arunca exceptie daca aceste campuri sunt invalide
     * @ arunca exceptie daca exista deja in lista un locatar cu exact aceleasi campuri
     */
    void add(int, string, string, double);

    /*
     * returneaza lista cu toti locatarii
     */
    vector<Locatar> getAll() const;

    /*
     * sterge locatarul de pe o anumita pozitie
     * poz - int, pozitia de la care se doreste stergerea locatarului
     * returneaza locatarul sters
     * @ arunca exceptie daca pozitia e invalida
     */
    Locatar sterge(int);

    /*
     * modifica campurile locatarului de pe o anumtia pozitie
     * poz - int, pozitia locatarului de actualizat
     * ap - int, numarul apartamentului
     * nume - string, numele proprietarului
     * tip - string, tipul apartamentului
     * suprafata - double, suprafata apartamentului
     * returneaza locatarul actualizat
     * @ arunca exceptie daca noile campuri ale locatarului sunt invalide
     * @ arunca exceptie daca pozitia e invalida
     */
    Locatar modifica(int, string, string, double);

    /*
     * cauta un locatar in lista de locatari
     * ap - int, numarul apartamentului
     * nume - string, numele proprietarului
     * tip - string, tipul apartamentului
     * suprafata - double, suprafata apartamentului
     * returneaza pozitia pe care se afla locatarul de cautat sau -1 daca acesta nu se afla in lista
     * @ arunca exceptie in cazul in care campurile locatarului sunt invalide
     */
    Locatar cautareLocatar(int);

    /*
     * filtreaza o lista de locatari pe baza unei functii
     * fct - bool(const Locatar&), functie ce contine conditia de filtrare
     * returneaza o lista cu locatarii care respecta conditia de filtrare
     */
     vector<Locatar> filtrare( function <bool(const Locatar&)> fct );

    /*
     * sorteaza lista curenta de locatari, pe baza unei conditii de sortare
     * condSortare - bool(const Locatar&, const Locatar&), functie ce returneaza conditia de sortare
     * reversed - int, este 0 daca se doreste sortare crescatoare si 1 pentru sortare descrescatoare
     * returneaza lista sortata de locatari sau o lista vida daca lista initiala de locatari este vida
     */
    vector<Locatar> sortare( bool(*condSortare)(const Locatar&, const Locatar&), int );

    vector<Locatar> sortareNume(int);
    vector<Locatar> sortareSuprafata(int);
    vector<Locatar> sortareTipSuprafata(int);

    vector<Locatar> filtrareTip(string tip);

    vector<Locatar> filtrareSuprafata(double surfMin, double surfMax);

    void clearList();
    void addNotif(int ap);
    void generate(int nr);
    void exportList(string name, string tip);
    vector<Locatar> getNotifList();
    int sizeNotifList();

    map< string, vector<Locatar> > getRaport();

    void undo();
    notificationList& getNotificationList(){
        return notif;
    }

};