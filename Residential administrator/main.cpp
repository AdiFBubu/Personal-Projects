#include <iostream>
#include <QApplication>
#include "tests.h"
#include "ui.h"
#include "LocatarGUI.h"
#include "cosGUI.h"
#include "cosGUI2.h"
#include "LocatarGUIModele.h"


int main(int argc, char* argv[]) {

    Tests t;
    t.allTests();

    //LocatarRepo repo;
    try {
        LocatarRepoFile repo("fisier.txt");
        //LocatarRepoDict repo = LocatarRepoDict(0.5);
        Validator val;

        LocatariService serv{repo, val};
        UI ui{serv};

        QApplication a(argc, argv);

        //LocatarGUI gui{serv};
        LocatarGUIModele gui{serv};
        gui.show();
        //cosGUI guiCos{serv};
        //guiCos.show();
        //CosCRUDGUI guiCos2{serv.getNotificationList()};
        //guiCos2.show();

        //CosReadOnlyGUI guiCos3{serv.getNotificationList()};
        //guiCos3.show();
        //ui.startUI();
        a.exec();
    }
    catch (const RepoException& e)
    {
        std::cout << e.getMessage();
    }
    return 0;
}
