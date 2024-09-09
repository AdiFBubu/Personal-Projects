#pragma once
#include "service.h"

class UI
{
private:
    LocatariService& serv;
public:
    /*
     * constructorul clasei UI
     * serv - LocatariService&, referinta catre un obiect de clasa LocatariService
     */
    UI(LocatariService& serv);

    /*
     * user interface
     */
    void startUI();
    void listaNotificareUI();
};