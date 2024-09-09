#include "repo.h"
#include <string>
#include "VectorDinamicTemplate.h"
#include "IteratorVectorT.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;
using std::find_if;
using std::find;

void LocatarRepo:: store(const Locatar& el)
{
    if ( find(list.begin(), list.end(), el) != list.end() )
        throw RepoException("Locatar deja introdus!");
    list.push_back(el);
}

vector<Locatar> LocatarRepo:: getAll() const
{
    return list;
}

RepoException::RepoException(std::string msg): msg{msg}{
}

string RepoException::getMessage() const{
    return msg;
}

Locatar LocatarRepo:: sterge(int ap)
{
    Locatar l = cautare(ap);
    auto it = find(list.begin(), list.end(), l);
    list.erase(it);
    return l;}

Locatar LocatarRepo:: modifica(const Locatar& l_nou)
{
    int ap = l_nou.get_ap();
    auto it = find_if(list.begin(), list.end(), [&ap](const Locatar& ob){
        return ob.get_ap() == ap;
    });
    if (it == list.end())
        throw RepoException("Apartamentul cu id-ul dat nu exista!\n");
    *it = l_nou;
    return l_nou;
}

Locatar LocatarRepo:: cautare(int ap)
{
    auto it = find_if(list.begin(), list.end(), [&ap](const Locatar& ob){
        return ob.get_ap() == ap;
    });
    if (it == list.end())
        throw RepoException("Apartamentul cu id-ul dat nu exista!\n");
    return *it;
}

LocatarRepoFile:: LocatarRepoFile(string numeFisier): LocatarRepo(), numeFisier{numeFisier}{
    loadFromFile();
}

void LocatarRepoFile:: loadFromFile()
{
    std::ifstream fin(numeFisier);
    if ( !fin.is_open() )
        throw RepoException("Unable to open file: " + numeFisier);
    string linie;
    int ap;
    string nume, tip;
    double suprafata;
    while ( getline(fin, linie) )
    {
        std::stringstream ss(linie);
        string word;
        vector<string> lista;
        while ( getline(ss, word, '/') )
            lista.push_back(word);
        ap = stoi(lista[0]);
        nume = lista[1], tip = lista[2];
        suprafata = stod(lista[3]);
        Locatar l{ap, nume, tip, suprafata};
        LocatarRepo:: store(l);
    }
    fin.close();
}

void LocatarRepoFile:: writeToFile()
{
    std::ofstream fout(numeFisier);
    if ( ! fout.is_open() )
        throw RepoException("Unable to open file: " + numeFisier);

    for (const auto& l : getAll())
        fout << l.get_ap() << '/' << l.get_nume() << '/' << l.get_tip() << '/' << l.get_suprafata() << '\n';
    fout.close();
}

void LocatarRepoFile:: store(const Locatar& el) {
    LocatarRepo:: store(el);
    writeToFile();
}

Locatar LocatarRepoFile::sterge (int ap) {
    auto l = LocatarRepo::sterge(ap);
    writeToFile();
    return l;}

Locatar LocatarRepoFile:: modifica(const Locatar& el)
{
    auto l = LocatarRepo::modifica(el);
    writeToFile();
    return l;}

LocatarRepoDict::LocatarRepoDict(double prob): prob{prob} {}

void LocatarRepoDict::det_prob() const {
    int sansa = int(prob * 10);
    srand(time(0));
    int nr = rand() % 10 + 1;
    if (nr <= sansa)
        return;
    throw RepoException("Ghinion! Nu s-a putut efectua operatia dorita! (ai avut ghinion)\n");
}

void LocatarRepoDict:: store(const Locatar& el)
{
    det_prob();
    auto it = m.find(el.get_ap());
    if (it != m.end())
        throw RepoException("Locatar deja introdus!");
    m.insert({el.get_ap(), el});
}

vector<Locatar> LocatarRepoDict:: getAll() const
{
    det_prob();
    vector<Locatar> v;
    for (const auto& el : m)
        v.push_back(el.second);
    return v;
}

Locatar LocatarRepoDict:: sterge(int ap)
{
    det_prob();
    auto it = m.find(ap);
    if (it == m.end())
        throw RepoException("Apartamentul cu id-ul dat nu exista!\n");
    Locatar elem = it->second;
    m.erase(it);
    return elem;
}

Locatar LocatarRepoDict:: modifica(const Locatar& el)
{
    det_prob();
    auto it = m.find(el.get_ap());
    if (it == m.end())
        throw RepoException("Apartamentul cu id-ul dat nu exista!\n");
    it->second = el;
    return el;
}

Locatar LocatarRepoDict:: cautare(int ap)
{
    det_prob();
    auto it = m.find(ap);
    if (it == m.end())
        throw RepoException("Apartamentul cu id-ul dat nu exista!\n");
    return it->second;
}