#include "ui.h"
#include <iostream>
#include <string>
#include <vector>
#include "VectorDinamicTemplate.h"
#include "IteratorVectorT.h"
using std::cout;
using std::cin;
using std::vector;
using std::string;

bool verifyInt(string s)
{
    string t;
    int nr;
    try{
        nr = stoi(s);
        t = std::to_string(nr);
        if (s.size() != t.size())
            throw std::exception();
    }
    catch(const std::exception& e)
    {
        return 0;
    }
    return 1;
}

bool verifyFloat(string s)
{
    string t;
    size_t val;
    double nr;
    try{
        nr = stod(s, &val);
        if (s.size() != val)
            throw std::exception();
    }
    catch(const std::exception& e)
    {
        return 0;
    }
    return 1;
}

UI::UI(LocatariService& serv): serv{serv}{

}
void UI:: startUI()
{
    string s;
    while(1)
    {
        cout << "\nMENIU:\n";
        cout << "0. iesire\n";
        cout << "1. adaugare locatar\n";
        cout << "2. afisare locatari\n";
        cout << "3. stergere\n";
        cout << "4. modificare\n";
        cout << "5. cautare locatar\n";
        cout << "6. filtrare\n";
        cout << "7. sortare\n";
        cout << "8. lista de notificari\n";
        cout << "9. raport dupa tip\n";
        cout << "10. undo\n";

        cout << "comanda: ";
        getline(cin, s);
        if (verifyInt(s) == 0)
        {
            cout << "Nu ai introdus un numar intreg!\n";
            continue;
        }
        int cmd = std::stoi(s);
        if (cmd == 0)
        {
            cout << "Bye!\n";
            break;
        }
        else if(cmd == 1)
        {
            int ap;
            string nume, tip;
            double suprafata;
            cout << "ap: ";
            getline(cin, s);
            if (verifyInt(s) == 0)
            {
                cout << "Nu ai introdus un numar intreg!\n";
                continue;
            }
            ap = std::stoi(s);
            cout << "nume: ";
            getline(cin, nume);
            cout << "tip: ";
            getline(cin, tip);
            cout << "suprafata: ";
            getline(cin, s);
            if (verifyFloat(s) == 0)
            {
                cout << "Nu ai introdus un numar real!\n";
                continue;
            }
            suprafata = std::stod(s);
            Locatar l{ap, nume, tip, suprafata};

            try {
                serv.add(ap, nume, tip, suprafata);
                cout << "Locatar adaugat cu succes!\n";
            }
            catch(const RepoException& e)
            {
                cout << e.getMessage();
            }
            catch(const ValidatorException& e)
            {
                cout << e.getMessage();
            }
        }
        else if (cmd == 2)
        {
            try {
                const vector<Locatar> &list = serv.getAll();
                if (list.empty())
                    cout << "LISTA GOALA!\n";
                else
                    for (const auto &el: list)
                        cout << el;
            }
            catch (const RepoException& e)
            {
                cout << e.getMessage();
            }
        }
        else if (cmd == 3)
        {
            cout << "Lista cu locatari:\n\n";
            const vector<Locatar>& list = serv.getAll();
            int i = 0;
            for (const auto& el : list)
            {
                cout << i << ". " << list[i];
                i ++;
            }
            cout << "Introdu numarul apartamentului pe care vrei sa il stergi: ";
            getline(std::cin, s);
            if (verifyInt(s) == 0)
            {
                cout << "Nu ai introdus un numar intreg!\n";
                continue;
            }
            int ap = stoi(s);
            try {
                Locatar l = serv.sterge(ap);
                cout << "Locatarul: " << l << " a fost sterg cu succes!\n";
            }catch(const RepoException& e)
            {
                cout << e.getMessage();
            }
        }
        else if (cmd == 4)
        {
            cout << "Lista cu locatari:\n\n";
            const vector<Locatar>& list = serv.getAll();
            int i = 0;
            for (const auto& el : list)
            {
                cout << i << ". " << list[i];
                i ++;
            }
            int ap;
            string nume, tip;
            double suprafata;
            cout << "Introdu numarul apartamentului pe care vrei sa il modifici:";
            getline(std::cin, s);
            if (verifyInt(s) == 0)
            {
                cout << "Nu ai introdus un numar intreg!\n";
                continue;
            }
            ap = stoi(s);
            cout << "noul nume: ";
            getline(cin, nume);
            cout << "noul tip: ";
            getline(cin, tip);
            cout << "noua suprafata: ";
            getline(std::cin, s);
            if (verifyFloat(s) == 0)
            {
                cout << "Nu ai introdus un numar real!\n";
                continue;
            }
            suprafata = std::stod(s);

            try{
                const Locatar& l_nou = serv.modifica(ap, nume, tip, suprafata);
                cout << "Actualizarea a avut loc cu succes!!\n Locatarul modificat este: " << l_nou;
            }
            catch(const RepoException& e)
            {
                cout << e.getMessage();
            }
            catch(const ValidatorException& e)
            {
                cout << e.getMessage();
            }
        }
        else if (cmd == 5)
        {
            cout << "Introdu locatarul pe care doresti sa-l cauti:\n";
            int ap;
            cout << "ap: ";
            getline(std::cin, s);
            if (verifyInt(s) == 0)
            {
                cout << "Nu ai introdus un numar intreg!\n";
                continue;
            }
            ap = stoi(s);
            try{
                Locatar l = serv.cautareLocatar(ap);
                cout << "Locatarul a fost gasit: " << l;
            }
            catch (const RepoException& e)
            {
                cout << e.getMessage();
            }
            catch (const ValidatorException& e)
            {
                cout << e.getMessage();
            }
        }
        else if (cmd == 6)
        {
            cout << "Selectati cifra corespunzatoare filtrarii dorite: \n";
            cout << "1. tip apartament\n";
            cout << "2. suprafata\n";
            int opt;
            getline(std::cin, s);
            if (verifyInt(s) == 0)
            {
                cout << "Nu ai introdus un numar intreg!\n";
                continue;
            }
            opt = stoi(s);
            if (opt == 1)
            {
                cout << "Introdu tipul dupa care doresti sa aiba loc filtrarea: ";
                string tip;
                getline(cin, tip);
                const vector<Locatar> &lista_filtrata = serv.filtrareTip(tip);
                cout << "Lista filtrata: \n";
                for (const auto& el : lista_filtrata)
                    cout << el;
            }
            else if (opt == 2)
            {
                cout << "Introdu suprafatele intre care doresti sa aiba loc filtrarea:  ";
                double surfMin, surfMax;
                cout << "suprafata minima: ";
                getline(std::cin, s);
                if (verifyFloat(s) == 0)
                {
                    cout << "Nu ai introdus un numar real!\n";
                    continue;
                }
                surfMin = std::stod(s);

                cout << "suprafata maxima: ";
                getline(std::cin, s);
                if (verifyFloat(s) == 0)
                {
                    cout << "Nu ai introdus un numar real!\n";
                    continue;
                }
                surfMax = std::stod(s);

                if (surfMin > surfMax)
                    cout << "Nu ai introdus valori valide ale suprafetelor!\n";
                else
                {
                    const vector<Locatar>& lista_filtrata = serv.filtrareSuprafata(surfMin, surfMax);
                    cout << "Lista filtrata: \n";
                    for (const auto& el : lista_filtrata)
                        cout << el;
                }
            }
            else cout << "Nu ai introdus o cifra valida!\n";
        }
        else if (cmd == 7)
        {
            cout << "Introdu cifra corespunzatoare sortarii dorite:\n";
            cout << "1. dupa nume proprietar\n";
            cout << "2. dupa suprafata\n";
            cout << "3. dupa tip apartament si suprafata\n";
            int cond, cond2;
            getline(std::cin, s);
            if (verifyInt(s) == 0)
            {
                cout << "Nu ai introdus un numar intreg!\n";
                continue;
            }
            cond = stoi(s);
            if (cond != 1 && cond != 2 && cond != 3)
                cout << "Nu ai introdus o cifra valida!\n";
            else {
                cout << "Cum doresti sa fie sortarea?\n";
                cout << "1. crescatoare\n";
                cout << "2. descrescatoare\n";
                bool reversed;
                getline(std::cin, s);
                if (verifyInt(s) == 0)
                {
                    cout << "Nu ai introdus un numar intreg!\n";
                    continue;
                }
                cond2 = stoi(s);
                if (cond2 == 1)
                    reversed = 0;
                else if (cond2 == 2)
                    reversed = 1;
                else {
                    cout << "Nu ai introdus o cifra valida!\n";
                    continue;
                }

                VectorDinamic<Locatar> lista_sortata;

                if (cond == 1)
                    lista_sortata = serv.sortareNume(reversed);
                else if (cond == 2) {
                    lista_sortata = serv.sortareSuprafata(reversed);
                } else
                    lista_sortata = serv.sortareTipSuprafata(reversed);

                if (lista_sortata.size() == 0)
                    cout << "Lista initiala nu contine niciun locatar!\n";
                else {
                    cout << "Lista sortata este:\n";
                    for (const auto &l: lista_sortata)
                        cout << l;
                }
            }

        }
        else if (cmd == 8)
        {
            listaNotificareUI();
        }
        else if (cmd == 9)
        {
            auto raport = serv.getRaport();
            for (const auto& tip : raport)
            {
                cout << "Tip " << tip.first << ":\n";
                for (const auto &el: tip.second)
                    cout << '\t' << el;
                cout << '\n';
            }
        }
        else if (cmd == 10)
        {
            try{
                serv.undo();
                cout << "Undo realizat cu succes!\n";
            }
            catch (const RepoException& e)
            {
                cout << e.getMessage();
            }
        }
        else cout << "Nu ai introdus o cifra valida!\n";
    }
}

void UI:: listaNotificareUI()
{
    while(1) {
        cout << "===========================================\n";
        cout << "MENIU LISTA DE NOTIFICARI\n";
        cout << "===========================================\n";
        cout << "0. iesire\n";
        cout << "1. goleste lista\n";
        cout << "2. adauga in lista\n";
        cout << "3. genereaza lista\n";
        cout << "4. export\n";

        string s;
        cout << "comanda: ";
        getline(cin, s);
        if (verifyInt(s) == 0) {
            cout << "Nu ai introdus un numar intreg!\n";
            return;
        }
        int cmd = std::stoi(s);
        if (cmd == 1) {
            serv.clearList();
            cout << "Lista a fost stearsa cu succes!\n";
        } else if (cmd == 2) {
            cout << "Lista actuala de apartamente este:\n";
            const auto &lista = serv.getAll();
            for (const auto &el: lista)
                cout << el;
            cout << "\nIntrodu numarul apartamentului pe care doresti sa il adaugi in lista:\n";

            getline(cin, s);
            if (verifyInt(s) == 0) {
                cout << "Nu ai introdus un numar intreg!\n";
                continue;
            }
            int nrAp = std::stoi(s);
            try {
                serv.addNotif(nrAp);
                cout << "Apartament adaugat cu succes in lista de notificari!!\n";
            }
            catch (const RepoException &e) {
                cout << e.getMessage();
            }

        }
        else if (cmd == 3)
        {
            cout << "Introdu numarul de aparamente random pe care doresti sa le aiba lista de notificari:\n";

            getline(cin, s);
            if (verifyInt(s) == 0) {
                cout << "Nu ai introdus un numar intreg!\n";
                continue;
            }
            int nrAp = std::stoi(s);
            try {
                serv.generate(nrAp);
                cout << "Lista de notificari generata cu succes!\n";
            }
            catch (const RepoException& e)
            {
                cout << e.getMessage();
            }
        }
        else if (cmd == 4)
        {
            cout << "Introdu numele fisierului in care doresti sa se salveze lista actuala de notificari:\n";
            string nume, tip;
            getline(cin, nume);
            cout << "Introdu tipul fisierului: (html / csv)\n";
            getline(cin, tip);
            try {
                serv.exportList(nume, tip);
                cout << "Exportare cu succes!\n";
            }
            catch (const ValidatorException& e)
            {
                cout << e.getMessage();
            }
            catch(const RepoException& e)
            {
                cout << e.getMessage();
            }
            catch (const notificationException& e)
            {
                cout << e.getMessage();
            }
        }
        else if (cmd == 0)
        {
            cout << "Revenire meniu principal!!\n";
            break;
        }
        else
            cout << "Nu ai introdus o cifra valida!\n";

        cout << "\n\nLista actuala de notificari are " << serv.sizeNotifList() << " apartamente:\n";
        auto lista = serv.getNotifList();
        for (const auto& el : lista)
            cout << el;
        cout << '\n';
    }
}