#include "tests.h"
#include "domain.h"
#include <cassert>
#include "service.h"
#include "repo.h"
#include <iostream>
#include <fstream>
#include "validator.h"
#include "notificationList.h"
using std::cout;

void Tests:: allTests()
{
    domainTest();
    validatorTest();
    storeTest();
    addTest();
    stergeTest();
    modificaTest();
    modificaRepoTest();
    cautareLocatarTest();
    filtrareTest();
    sortareTest();
    undoTest();

    clearListTest();
    addNotifTest();
    generateTest();
    exportTest();

    clearListServTest();
    addNotifServTest();
    generateServTest();
    exportListServTest();

    raportTest();
    repoFileTest();

    repoProbTest();

}

void Tests:: domainTest()
{
    Locatar l1{12, "a", "b", 120.33};
    assert(l1.get_ap() == 12 && l1.get_nume() == "a");
    assert(l1.get_tip() == "b" && l1.get_suprafata() == 120.33);
    Locatar l2{12, "a", "b", 120.33};
    assert(l1 == l2);
    Locatar l3{14, "a", "b", 120.33};
    assert( !(l1 == l3) );
    l1.set_ap(20);
    l1.set_nume("zaza");
    l1.set_suprafata(20.20), l1.set_tip("oaoa");
    assert(l1.get_ap() == 20 && l1.get_suprafata() == 20.20);
    assert(l1.get_tip() == "oaoa" && l1.get_nume() == "zaza");

    assert (cmpNume(l1, l2) == false);
    assert (cmpSuprafata(l1,l2) == true);
    l1.set_tip("a");
    assert (cmpTipSuprafata(l1, l2) == true);
}

void Tests:: addTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    serv.add(12, "a", "b", 120.33);
    const auto& list = serv.getAll();
    assert(list.size() == 1);
    try {
        serv.add(12, "a", "b", 120.33);
        assert(false);
    }catch(const RepoException& ){
        assert(true);
    }
    try{
        serv.add(12, "a", "b", -120.33);
        assert(false);
    }catch(const ValidatorException&)
    {
        assert(true);
    }
}

void Tests:: validatorTest()
{
    Validator val;
    Locatar l1{12, "a", "b", 120.33};
    assert( val.validareLocatar(l1) == true );
    Locatar l2{12, "", "b", 120.33};
    try{
        val.validareLocatar(l2);
        assert(false);
    }catch(ValidatorException& e){
        assert(e.getMessage() == "Nume proprietar invalid!\n");
    }
    Locatar l3{12, "aa", "b", -120.33};
    try{
        val.validareLocatar(l3);
        assert(false);
    }catch(ValidatorException&){
        assert(true);
    }
    Locatar l4{-12, "aa", "", 120.33};
    try{
        val.validareLocatar(l4);
        assert(false);
    }catch(const ValidatorException&){
        assert(true);
    }

    assert (val.validareAp(51) == true);
    try{
        val.validareAp(-50);
        assert(false);
    }
    catch(const ValidatorException& e)
    {
        assert (true);
    }

    assert( val.validareExport("mamaliga", "html") == true);
    try{
        val.validareExport("", "aaa");
        assert(false);
    }
    catch(const ValidatorException& e)
    {
        assert(e.getMessage() == "Nume invalid!\nTipul poate fi doar 'csv' sau 'html'!\n");
    }

    try{
        val.validareExport("mamali.ga", "");
        assert(false);
    }
    catch(const ValidatorException& e)
    {
        assert(e.getMessage() == "Tip invalid!\nNumele nu poate avea caracterul '.' in componenta!\n");
    }
}

void Tests::storeTest() {
    LocatarRepo repo;
    Locatar l1{12,"abc","dcb",120};
    repo.store(l1);
    Locatar l2{123,"azbc","dcfb",1220};
    Locatar l4{12,"abfc","dcb",1250};
    Locatar l3{125,"abfc","dcb",1250};
    repo.store(l2), repo.store(l3);
    try
    {
        repo.store(l4);
        assert (false);
    }
    catch (const RepoException& e)
    {
        assert (true);
    }
    vector<Locatar> list = repo.getAll();
    assert(list.size() == 3);
    assert(list[1].get_suprafata() == 1220);
    try{
        repo.store(l1);
        assert(false);
    }catch(const RepoException&){
        assert(true);
    }
}

void Tests:: stergeTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    Locatar l1{12,"abc","dcb",120};
    repo.store(l1);
    Locatar l2{123,"azbc","dcfb",1220};
    Locatar l3{125,"abfc","dcb",1250};
    repo.store(l2), repo.store(l3);
    try {
        serv.sterge(2);
        assert(false);
    }
    catch (const RepoException& e)
    {
        assert(e.getMessage() == "Apartamentul cu id-ul dat nu exista!\n");
    }
    Locatar l4 = serv.sterge(125);
    assert(l3 == l4);
    vector<Locatar> list = serv.getAll();
    assert(list.size() == 2);
    try{
        serv.sterge(125);
        assert(false);
    }
    catch(const RepoException&)
    {
        assert(true);
    }
    try{
        serv.sterge(-42);
        assert(false);
    }
    catch(const ValidatorException&)
    {
        assert(true);
    }
}

void Tests:: modificaTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    Locatar l1{12,"abc","dcb",120};
    repo.store(l1);
    Locatar l2{123,"azbc","dcfb",1220};
    Locatar l3{125,"abfc","dcb",1250};
    repo.store(l2), repo.store(l3);
    try {
        serv.modifica(200, "aaa", "bbb", 200.20);
    }
    catch(const RepoException& e)
    {
        assert (e.getMessage() == "Apartamentul cu id-ul dat nu exista!\n");
    }
    try {
        serv.modifica(200, "", "bbb", -200.20);
    }
    catch(const ValidatorException& e)
    {
        assert (e.getMessage() == "Nume proprietar invalid!\nSuprafata invalida!\n");
    }
    Locatar l_nou = serv.modifica(123, "rufus", "mircus", 2929);
    vector<Locatar> list = serv.getAll();
    assert(list[1] == l_nou);
    Locatar l5{-3,"a","b",20.2};
    try{
        serv.modifica(-3,"a","b",20.2);
        assert(false);
    }
    catch(const ValidatorException& )
    {
        assert(true);
    }
    try{
        serv.modifica(3,"a","z",200);
        assert(false);
    }
    catch(const RepoException& )
    {
        assert(true);
    }
}

void Tests:: modificaRepoTest()
{
    LocatarRepo repo;
    Locatar l1{12,"abc","dcb",120};
    repo.store(l1);
    Locatar l2{123,"azbc","dcfb",1220};
    Locatar l3{125,"abfc","dcb",1250};
    repo.store(l2), repo.store(l3);
    Locatar l4{12,"q","r", 9.22};
    Locatar l_nou = repo.modifica(l4);
    vector<Locatar>list = repo.getAll();
    assert(list[0] == l_nou);
    Locatar l5{3,"a","b",90};
    try
    {
        repo.modifica(l5);
        assert(false);
    }
    catch(const RepoException& e)
    {
        assert(e.getMessage() == "Apartamentul cu id-ul dat nu exista!\n");
    }
}

void Tests:: cautareLocatarTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    Locatar l1{12,"abc","dcb",120};
    repo.store(l1);
    Locatar l2{123,"azbc","dcfb",1220};
    Locatar l3{125,"abfc","dcb",1250};
    repo.store(l2), repo.store(l3);
    Locatar l = serv.cautareLocatar(123);
    assert(l == l2);
    try {
        serv.cautareLocatar(15);
        assert (false);
    }
    catch (const RepoException& e)
    {
        assert (e.getMessage() == "Apartamentul cu id-ul dat nu exista!\n");
    }
    try{
        serv.cautareLocatar(-5);
        assert (false);
    }
    catch(const ValidatorException& e)
    {
        assert (e.getMessage() == "Numar apartament gresit!\n");
    }
    l = serv.cautareLocatar(12);
    assert (l == l1);
}

void Tests:: filtrareTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    Locatar l1{12,"abc","dcb",120};
    repo.store(l1);
    Locatar l2{123,"azbc","dcfb",1220};
    Locatar l3{125,"abfc","dcb",1250};
    Locatar l4{20, "aaa", "dcb", 92.22};
    repo.store(l2), repo.store(l3);
    repo.store(l4);
    string tip = "dcb";

    vector<Locatar> lista_filtrata = serv.filtrareTip(tip);
    assert(lista_filtrata.size() == 3);
    assert(lista_filtrata[0] == l1 && lista_filtrata[1] == l3 && lista_filtrata[2] == l4);

    int surfMin = 100, surfMax = 1230;
    lista_filtrata = serv.filtrareSuprafata(surfMin, surfMax);
    assert(lista_filtrata.size() == 2);
    assert(lista_filtrata[0] == l1 && lista_filtrata[1] == l2);
}

void Tests:: sortareTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};

    vector<Locatar> lista_sortata;

    lista_sortata = serv.sortareNume(0);
    assert (lista_sortata.empty());

    Locatar l1{12,"abc","dcb",120};
    repo.store(l1);
    Locatar l2{123,"azbc","dcfb",1220};
    Locatar l3{125,"abfc","dcb",1250};
    Locatar l4{20, "aaa", "dcb", 92.22};
    repo.store(l2), repo.store(l3);
    repo.store(l4);

    lista_sortata = serv.sortareNume(0);
    assert (lista_sortata[0] == l4 && lista_sortata[1] == l1 &&
    lista_sortata[2] == l3 && lista_sortata[3] == l2);

    lista_sortata = serv.sortareNume(1);
    assert (lista_sortata[3] == l4 && lista_sortata[2] == l1 &&
            lista_sortata[1] == l3 && lista_sortata[0] == l2);

    lista_sortata = serv.sortareSuprafata(0);
    assert (lista_sortata[0] == l4 && lista_sortata[1] == l1 &&
    lista_sortata[2] == l2 && lista_sortata[3] == l3);

    lista_sortata = serv.sortareSuprafata(1);
    assert (lista_sortata[3] == l4 && lista_sortata[2] == l1 &&
            lista_sortata[1] == l2 && lista_sortata[0] == l3);

    lista_sortata = serv.sortareTipSuprafata(0);
    assert (lista_sortata[0] == l4 && lista_sortata[1] == l1 &&
    lista_sortata[2] == l3 && lista_sortata[3] == l2);

    lista_sortata = serv.sortareTipSuprafata(1);
    assert (lista_sortata[3] == l4 && lista_sortata[2] == l1 &&
            lista_sortata[1] == l3 && lista_sortata[0] == l2);
}

void Tests:: clearListTest()
{
    LocatarRepo repo;
    notificationList notif{repo};
    Locatar l{1,"w","q",3};
    Locatar l1{2,"wa","qs",33};
    Locatar l2{3,"ww","zq",35};
    repo.store(l); repo.store(l1); repo.store(l2);
    notif.add(l);
    notif.add(l1);
    notif.add(l2);
    assert(notif.getList().size() == 3);
    notif.clearList();
    assert(notif.getList().size() == 0);
}

void Tests:: addNotifTest()
{
    LocatarRepo repo;
    notificationList notif{repo};
    Locatar l{1,"w","q",3};
    Locatar l1{2,"wa","qs",33};
    Locatar l2{3,"ww","zq",35};
    repo.store(l), repo.store(l1), repo.store(l2);
    assert(notif.size() == 0);
    notif.add(l);
    notif.add(l1);
    assert(notif.size() == 2);
    notif.add(l2);
    assert(notif.size() == 3);
    auto lista = notif.getList();
    assert (lista[0] == l && lista[1] == l1 && lista[2] == l2);
}

void Tests:: generateTest()
{
    LocatarRepo repo;
    vector<Locatar> v;
    Locatar l{1,"w","q",3};
    Locatar l1{2,"wa","qs",33};
    Locatar l2{3,"ww","zq",35};
    repo.store(l); repo.store(l1); repo.store(l2);
    notificationList notif{repo};
    notif.generate(5);
    assert (notif.getList().size() == 5);
}

void Tests:: exportTest()
{
    LocatarRepo repo;
    notificationList notif{repo};
    Locatar l{1,"w","q",3};
    Locatar l1{2,"wa","qs",33};
    Locatar l2{3,"ww","zq",35};
    repo.store(l); repo.store(l1); repo.store(l2);
    notif.add(l), notif.add(l1), notif.add(l2);
    notif.exportToHTML("mamaliga.html");
    std::ifstream fin("mamaliga.html");
    assert (fin.is_open());
    fin.close();

    notif.exportToCSV("mamaliga.csv");
    fin.open("mamaliga.csv");
    string s;
    int nrLinii = 0;
    while (! fin.eof())
    {
        fin >> s;
        nrLinii ++;
    }
    assert (nrLinii == 4); // 3 + 1 goala
    try{
        notif.exportToHTML("test/mamaliga.html");
        assert (false);
    }
    catch (const notificationException& e)
    {
        assert (e.getMessage() == "Unable to open the file: test/mamaliga.html");
    }

    try{
        notif.exportToCSV("a/b/c/mamaliga.csv");
        assert (false);
    }
    catch (const notificationException& e)
    {
        assert (e.getMessage() == "Unable to open the file: a/b/c/mamaliga.csv");
    }
}

void Tests:: clearListServTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    serv.add(1,"w","q",3);
    serv.add(2,"wa","qs",33);
    serv.add(3,"ww","zq",35);
    serv.addNotif(2);
    serv.addNotif(1);
    serv.addNotif(3);
    assert(serv.sizeNotifList() == 3);
    serv.clearList();
    assert(serv.sizeNotifList() == 0);
}

void Tests:: addNotifServTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    serv.add(1,"w","q",3);
    serv.add(2,"wa","qs",33);
    serv.add(3,"ww","zq",35);
    serv.addNotif(2);
    serv.addNotif(1);
    serv.addNotif(3);
    auto lista = serv.getNotifList();
    assert(lista[0].get_suprafata() == 33 && lista[1].get_nume() == "w" && lista[2].get_tip() == "zq");
    try{
        serv.addNotif(55);
        assert(false);
    }
    catch(const RepoException& e)
    {
        assert(e.getMessage() == "Nu exista niciun apartament cu numarul dat!\n");
    }
}

void Tests:: generateServTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    try
    {
        serv.generate(3);
        assert(false);
    }
    catch(const RepoException& e)
    {
        assert(e.getMessage() == "Momentan, nu este inregistrat niciun apartament!\n");
    }
    serv.add(1,"w","q",3);
    serv.add(2,"wa","qs",33);
    serv.add(3,"ww","zq",35);
    serv.addNotif(2);
    serv.addNotif(1);
    serv.addNotif(3);
    serv.generate(5);
    assert(serv.sizeNotifList() == 5);
}

void Tests:: exportListServTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    try{
        serv.exportList("mamaliga", "html");
        assert(false);
    }
    catch(const RepoException& e)
    {
        assert(e.getMessage() == "Nu exista nimic inregistrat in lista de notificari deci nu are rost sa salvezi nimic in fisier!\n");
    }
    serv.add(1,"w","q",3);
    serv.add(2,"wa","qs",33);
    serv.add(3,"ww","zq",35);

    serv.addNotif(1);
    serv.addNotif(2);
    serv.addNotif(3);
    try{
        serv.exportList("", "atse");
        assert(false);
    }
    catch(const ValidatorException& e)
    {
        assert(e.getMessage() == "Nume invalid!\nTipul poate fi doar 'csv' sau 'html'!\n");
    }

    try{
        serv.exportList("rara.er", "csv");
        assert(false);
    }
    catch(const ValidatorException& e)
    {
        assert(e.getMessage() == "Numele nu poate avea caracterul '.' in componenta!\n");
    }
    serv.exportList("mamaliga", "html");
    std::ifstream fin("mamaliga.html");
    assert (fin.is_open());
    fin.close();

    serv.exportList("mamaliga", "csv");
    fin.open("mamaliga.csv");
    string s;
    int nrLinii = 0;
    while (! fin.eof())
    {
        fin >> s;
        nrLinii ++;
    }
    assert (nrLinii == 4); // 3 + 1 goala
    try{
        serv.exportList("test/mamaliga","html");
        assert (false);
    }
    catch (const notificationException& e)
    {
        assert (e.getMessage() == "Unable to open the file: test/mamaliga.html");
    }

    try{
        serv.exportList("a/b/c/mamaliga", "csv");
        assert (false);
    }
    catch (const notificationException& e)
    {
        assert (e.getMessage() == "Unable to open the file: a/b/c/mamaliga.csv");
    }
}

void Tests::raportTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    serv.add(23, "e", "A", 55);
    serv.add(90, "mc", "B", 3);
    serv.add(56, "TTT", "K", 2);
    serv.add(253, "Rufus", "A", 535);
    serv.add(213, "Magda", "A", 155);
    auto raport = serv.getRaport();
    assert(raport["A"].size() == 3 &&
            raport["B"].size() == 1 &&
            raport["K"].size() == 1);
    assert( raport.find("C") == raport.end() );
}

void Tests::repoFileTest()
{
    std::ofstream fout("testFile.txt");
    fout.close();
    LocatarRepoFile repo{"testFile.txt"};
    Locatar l1{23,"e","A",56};
    repo.store(l1);
    LocatarRepoFile repo2{"testFile.txt"};
    assert(repo2.cautare(23) == l1);
    assert(repo2.getAll().size() == 1);
    Locatar l2{23,"z","Z",100};
    repo2.modifica(l2);
    assert(repo2.cautare(23) == l2);
    assert(repo2.getAll().size() == 1);
    try{
        repo2.modifica(Locatar{20,"z","a",100});
        assert (false);
    }
    catch (const RepoException& e){
        assert (true);
    }
    assert( repo2.sterge(23) == l1 );
    assert (repo2.getAll().empty());
    try{
        repo2.cautare(23);
        assert (false);
    }
    catch(const RepoException& e){
    }

    try{
        repo2.sterge(23);
        assert (false);
    }
    catch(const RepoException& e){
    }

    LocatarRepoFile repo3{"testFile.txt"};
    assert (repo3.getAll().size() == 0);

    try{
        LocatarRepoFile repo4("testFileInexistent.txt");
        assert (false);
    }
    catch (const RepoException& e){
    }

}

void Tests::undoTest()
{
    LocatarRepo repo;
    Validator val;
    LocatariService serv{repo, val};
    Locatar l1{23, "e", "A", 55};
    Locatar l2{90, "mc", "B", 3};
    Locatar l3{23, "AZA", "BZB", 90};
    serv.add(23, "e", "A", 55);
    serv.add(90, "mc", "B", 3);
    assert(serv.getAll().size() == 2);
    serv.modifica(23,"AZA","BZB",90);
    assert(serv.cautareLocatar(23) == l3);
    serv.undo();
    assert(serv.getAll().size() == 2);
    assert(serv.cautareLocatar(23) == l1);
    serv.undo();
    assert(serv.getAll().size() == 1);
    assert(serv.cautareLocatar(23) == l1);
    try{
        serv.cautareLocatar(90);
        assert (false);
    }
    catch (const RepoException& e)
    {
        assert (true);
    }
    serv.sterge(23);
    assert(serv.getAll().empty());
    serv.undo();
    assert(serv.getAll().size() == 1);
    assert(serv.cautareLocatar(23) == l1);
    serv.undo();
    assert(serv.getAll().empty());
    try{
        serv.undo();
        assert (false);
    }
    catch (const RepoException& e)
    {
        assert (e.getMessage() == "Nu mai exista operatii de undo!\n");
    }
}

void Tests:: repoProbTest()
{
    LocatarRepoDict repo = LocatarRepoDict(0);
    try{
        repo.cautare(2);
        assert (false);
    }
    catch (const RepoException& e)
    {
        assert(e.getMessage() == "Ghinion! Nu s-a putut efectua operatia dorita! (ai avut ghinion)\n");
    }
    repo = LocatarRepoDict(1);
    assert (repo.getAll().empty());
    Locatar l1{23, "e", "A", 55};
    Locatar l2{90, "mc", "B", 3};
    Locatar l3{123, "AZA", "BZB", 90};
    repo.store(l1);
    repo.store(l2);
    repo.store(l3);
    assert (repo.getAll().size() == 3);
    assert (repo.cautare(90) == l2);
    try {
        repo.cautare(100);
    }
    catch (const RepoException& e)
    {
        assert (true);
    }
    Locatar l4{23, "UUU", "RRR", 1.90};
    Locatar l5{111, "UUU", "RRR", 1.90};
    repo.modifica(l4);
    assert(repo.cautare(23) == l4);
    try{
        repo.modifica(l5);
        assert (false);
    }
    catch (const RepoException& e)
    {
        assert (true);
    }
    assert (repo.sterge(23) == l4);
    assert (repo.getAll().size() == 2);
    try{
        repo.sterge(1000);
        assert (false);
    }
    catch (const RepoException& e)
    {
        assert (true);
    }
}
