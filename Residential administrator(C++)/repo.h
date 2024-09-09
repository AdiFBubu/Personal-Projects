#pragma once
#include <vector>
#include "domain.h"
#include <string>
#include "VectorDinamicTemplate.h"
#include <map>

using std::vector;
using std::string;
using std::map;

class RepoException:public std::exception{
    string msg;
public:
    /*
     * constructorul clasei RepoException
     * msg - string, mesajul exceptiei
     */
    RepoException(string msg);
    /*
     * functie ce returneaza mesajul exceptiei
     */
    string getMessage() const;
};

class LocatarAbstractRepo{
public:
    LocatarAbstractRepo() = default;
    virtual void store(const Locatar& el) = 0;
    virtual  vector<Locatar> getAll() const = 0;
    virtual Locatar sterge(int) = 0;
    virtual Locatar modifica(const Locatar&) = 0;
    virtual Locatar cautare(int) = 0;
    virtual ~LocatarAbstractRepo() = default;

};

class LocatarRepo: public LocatarAbstractRepo
{
private:
    vector<Locatar> list;
public:

    /*
     * oprim crearea de copii la obiecte de clasa LocatarRepo
     */
    LocatarRepo(const LocatarRepo& ot) = delete;
    /*
     * constructorul default al clasei LocatarRepo
     */
    LocatarRepo() = default;

    /*
     * stocheaza un locatar in lista
     * el - const Locatar&, locatarul de adaugat
     * @ arunca exceptie daca locatarul e deja introdus
     */
    virtual void store(const Locatar& el) override;

    /*
     * returneaza lista curenta de locatari
     */
     vector<Locatar> getAll() const override;

    /*
     * sterge locatarul de pe o anumita pozitie si il returneaza
     * poz - int, pozitia de la care e sterg locatarul
     * returneaza locatarul sters
     * @ arunca exceptie daca pozitia nu e valida
     */
    virtual Locatar sterge(int) override;

    /*
     * modifica campurile unui locatar de pe o anumtia pozitie si returneaza locatarul actualizat
     * l - const Locatar&, locatarul cu noile campuri
     * poz - int, pozitia la care se doreste actualizarea campurilor
     * @ arunca exceptie daca pozitia e invalida
     */
    virtual Locatar modifica(const Locatar&) override;

    /*
     * cauta in lista de locatari, un anumit locatar
     * l - const Locatar&, locatarul de cautat
     * returneaza pozitia pe care se afla locatarul in lista sau -1 daca acesta nu apare in lista
     */
    Locatar cautare(int) override;
    virtual ~LocatarRepo() = default;

};

class LocatarRepoFile: public LocatarRepo{

private:
    string numeFisier;
    void loadFromFile();
    void writeToFile();

public:
    LocatarRepoFile(string);
    void store(const Locatar& el) override;
    Locatar sterge(int) override;
    Locatar modifica(const Locatar&) override;
};

class LocatarRepoDict: public LocatarAbstractRepo{
private:
    map<int,Locatar> m;
    //vector<Locatar> v;
    double prob;
    void det_prob() const;
public:
    LocatarRepoDict(double);
    void store(const Locatar& el) override;
    vector<Locatar> getAll() const override;
    Locatar sterge(int) override;
    Locatar modifica(const Locatar&) override;
    Locatar cautare(int) override;
};