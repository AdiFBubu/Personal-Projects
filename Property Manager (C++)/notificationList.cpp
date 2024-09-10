#include "notificationList.h"
#include <random>
#include <fstream>
#include <iostream>
#include <cstring>
#include <exception>

notificationException::notificationException(string msg): msg{msg} {}

string notificationException::getMessage() const {
    return msg;
}

void notificationList:: clearList()
{
    list.clear();
    notify();
}

void notificationList:: add(const Locatar& el)
{
    list.push_back(el);
    notify();
}

void notificationList:: generate(int nr)
{
    clearList();
    auto v = repo.getAll();
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<> dist(0, v.size()-1);
    int rndNr;
    for (int i = 0; i < nr; i ++)
    {
        rndNr = dist(mt);// numar aleator intre [0,size-1]
        list.push_back(v[rndNr]);
    }
    notify();

}
void notificationList:: exportToCSV(const string& name)
{
    std::ofstream fout(name);
    if (! fout.is_open() )
        throw notificationException("Unable to open the file: " + name);
    for (const auto& el : list)
        fout << el.get_ap() << "," << el.get_nume() << "," << el.get_tip() << "," << el.get_suprafata() << '\n';
    fout.close();
}

void notificationList:: exportToHTML(const string& name)
{
    std::ofstream fout(name);
    if (! fout.is_open() )
        throw notificationException("Unable to open the file: " + name);
    fout << "<html><body>" << '\n';
    fout << "<table border=\"1\" style=\"width:100%\">" << '\n';
    for (const auto& el : list)
    {
        fout << "<tr>" << '\n';
        fout << "<td>" << el.get_ap() << "</td>" << '\n';
        fout << "<td>" << el.get_nume() << "</td>" << '\n';
        fout << "<td>" << el.get_tip() << "</td>" << '\n';
        fout << "<td>" << el.get_suprafata() << "</td>" << '\n';
        fout << "</tr>" << '\n';
    }
    fout << "</table>" << '\n';
    fout << "</body></html>" << '\n';
    fout.close();
}

vector<Locatar> notificationList:: getList()
{
    return list;
}

int notificationList:: size()
{
    return list.size();
}