#include "service.h"
#include "domain.h"
#include "domain.h"
#include <iostream>
#include "VectorDinamicTemplate.h"
#include "IteratorVectorT.h"

LocatariService::LocatariService(LocatarAbstractRepo& repo, const Validator& val): repo{repo}, val{val} {

}
void LocatariService:: add(int ap, string nume, string tip, double suprafata)
{
    Locatar l{ap, nume, tip, suprafata};
    val.validareLocatar(l);
    repo.store(l);
    undoActions.push_back(std::make_unique<UndoAdauga>(repo, ap));
}
vector<Locatar> LocatariService:: getAll() const
{
    return repo.getAll();
}
Locatar LocatariService:: sterge(int ap)
{
    val.validareAp(ap);
    //repo.cautare(ap);
    auto l = repo.sterge(ap);
    undoActions.push_back(std::make_unique<UndoSterge>(repo, l));
    return l;}

Locatar LocatariService:: modifica(int ap, string nume, string tip, double suprafata)
{
    Locatar l_nou{ap, nume, tip ,suprafata};
    val.validareLocatar(l_nou);
    auto l = repo.cautare(ap);
    auto lNou = repo.modifica(l_nou);
    undoActions.push_back(std::make_unique<UndoModifica>(repo, l));
    return lNou;
}

Locatar LocatariService:: cautareLocatar(int ap)
{
    val.validareAp(ap);
    return repo.cautare(ap);
}

// nu o mai folosesc
/*
vector<Locatar> LocatariService:: filtrare( function <bool(const Locatar&)> fct )
{
    vector<Locatar> rez;
    for (const auto& l : repo.getAll())
    {
        if (fct(l))
            rez.push_back(l);
    }
    return rez;}
*/

// nu o mai folosesc
/*
vector<Locatar> LocatariService:: sortare( bool(*condSortare)(const Locatar&, const Locatar&), int reversed )
{
    vector<Locatar> rez{repo.getAll()};
    if (rez.empty())
        return rez;
    for (int i = 0; i < rez.size() - 1; i ++)
        for (int j = i + 1; j < rez.size(); j ++)
            if ( reversed == condSortare(rez[i], rez[j]) )
            {
                Locatar aux = rez[i];
                rez[i] = rez[j];
                rez[j] = aux;
            }
    return rez;}
*/

vector<Locatar> LocatariService:: filtrareTip(string tip)
{
    vector<Locatar> rez;
    auto lista = getAll();
    std::copy_if(lista.begin(), lista.end(), std::back_inserter(rez), [&tip](const Locatar& l){
        return l.get_tip() == tip;
    } );
    return rez;}

vector<Locatar> LocatariService:: filtrareSuprafata(double surfMin, double surfMax)
{
    vector<Locatar> rez;
    auto lista = getAll();
    std::copy_if(lista.begin(), lista.end(), std::back_inserter(rez), [&surfMin, &surfMax](const Locatar& l){
        return l.get_suprafata() >= surfMin && l.get_suprafata() <= surfMax;
    } );
    return rez;}

vector<Locatar> LocatariService:: sortareNume(int reversed)
{
    vector<Locatar> rez {getAll()};
    if (reversed == 0)
        std::sort(rez.begin(), rez.end(), [](const Locatar& el1, const Locatar& el2){
            return el1.get_nume() < el2.get_nume();
        });
    else
        std::sort(rez.begin(), rez.end(), [](const Locatar& el1, const Locatar& el2){
            return el1.get_nume() > el2.get_nume();
        });
    return rez;}

vector<Locatar> LocatariService:: sortareSuprafata(int reversed)
{
    vector<Locatar> rez {getAll()};
    if (reversed == 0)
        std::sort(rez.begin(), rez.end(), [](const Locatar& el1, const Locatar& el2){
            return el1.get_suprafata() < el2.get_suprafata();
        });
    else
        std::sort(rez.begin(), rez.end(), [](const Locatar& el1, const Locatar& el2){
            return el1.get_suprafata() > el2.get_suprafata();
        });
    return rez;}

vector<Locatar> LocatariService:: sortareTipSuprafata(int reversed)
{
    vector<Locatar> rez {getAll()};
    if (reversed == 0)
        std::sort(rez.begin(), rez.end(), [](const Locatar& el1, const Locatar& el2){
            return ((el1.get_tip() < el2.get_tip()) ||
                           (el1.get_tip() == el2.get_tip() && el1.get_suprafata() < el2.get_suprafata()));;
        });
    else
        std::sort(rez.begin(), rez.end(), [](const Locatar& el1, const Locatar& el2){
            return ((el1.get_tip() > el2.get_tip()) ||
                    (el1.get_tip() == el2.get_tip() && el1.get_suprafata() > el2.get_suprafata()));;;
        });
    return rez;}

void LocatariService:: clearList()
{
    return notif.clearList();
}

void LocatariService:: addNotif(int ap)
{
    val.validareAp(ap);
    auto lista = getAll();
    for (const auto& el : lista)
        if (el.get_ap() == ap)
            return notif.add(el);
    throw RepoException("Nu exista niciun apartament cu numarul dat!\n");
}

void LocatariService:: generate(int nr)
{
    if (getAll().empty())
        throw RepoException("Momentan, nu este inregistrat niciun apartament!\n");
    return notif.generate(nr);
}

void LocatariService:: exportList(string name, string tip)
{
    if (getNotifList().empty())
        throw RepoException("Nu exista nimic inregistrat in lista de notificari deci nu are rost sa salvezi nimic in fisier!\n");
    val.validareExport(name, tip);
    if (tip == "html")
        notif.exportToHTML(name + "." + tip);
    else
        notif.exportToCSV(name + '.' + tip);
}
vector<Locatar> LocatariService:: getNotifList()
{
    return notif.getList();
}

int LocatariService:: sizeNotifList()
{
    return notif.size();
}

map< string, vector<Locatar> > LocatariService:: getRaport()
{
    map< string, vector<Locatar> > raport;
    const auto& lista = getAll();
    for (const Locatar& el : lista)
        raport[el.get_tip()].push_back(el);
    return raport;}

void LocatariService:: undo()
{
    if (undoActions.empty())
        throw RepoException("Nu mai exista operatii de undo!\n");
    undoActions.back()->doUndo();
    undoActions.pop_back();
}