#pragma once
#include "domain.h"
#include <vector>
#include <string>
#include "observer.h"
#include "repo.h"

using std::vector;
using std::string;

class notificationException: public std::exception{
    string msg;
public:
    /*
     * constructorul clasei ValidatorException
     * msg - string, contine mesajul exceptiei
     */
    notificationException(string);

    /*
     * returneaza mesajul exceptiei
     */
    string getMessage() const;
};

class notificationList: public Observable{
private:
    vector<Locatar> list;
    const LocatarAbstractRepo& repo;
public:
    notificationList(const LocatarAbstractRepo& repo): repo{repo} {}
    notificationList(const notificationList& ot) = delete;
    void clearList();
    void add(const Locatar& el);
    void generate(int nr);
    void exportToCSV(const string& name);
    void exportToHTML(const string& name);
    vector<Locatar> getList();
    int size();
};