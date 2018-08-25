/* 
 * File:   CentrumHandlowe.cpp
 * Author: Komputer
 * 
 * Created on 14 luty 2017, 18:13
 */

#include "CentrumHandlowe.h"

CentrumHandlowe::CentrumHandlowe() {
}

CentrumHandlowe::CentrumHandlowe(int n, Miejsce* miej, string nazw): nr(n), miejsce(miej), nazwa(nazw)
{
    
}

void CentrumHandlowe::dodajOsobe(Osoba* O)
{
    osoba.push_back(O);
}

int CentrumHandlowe::dajLiczbeOsob()
{
    return osoba.size();
}

Osoba* CentrumHandlowe::dajOsobe(int n)
{
    if(n >= osoba.size())
    {
        cout << "Blad ! [Teatr::dajOsobe]: Nie ma osoby o nr " << n << " w teatrze. Jest tylko " << osoba.size() << "osob." << endl;
        return nullptr;
    }
    
    return osoba[n];
}

void CentrumHandlowe::usunOsobe(int n)
{
    if(n >= osoba.size())
    {
        cout << "Blad ! [Teatr::dajOsobe]: Nie ma osoby o nr " << n << " w teatrze. Jest tylko " << osoba.size() << "osob." << endl;
    }
    
    else
    {
        osoba.erase(osoba.begin() + n);
    }
}

void CentrumHandlowe::usunOsobeBezSpr(Osoba* O)
{
    for(int i = 0; i < osoba.size(); i++)
    {
        if(osoba[i] == O)
        {
            osoba.erase(osoba.begin() + i);
        }
    }
}

void CentrumHandlowe::wyrzucOsoby()
{
    osoba.clear();
}

string CentrumHandlowe::dajNazwe()
{
    return nazwa;
}

Miejsce* CentrumHandlowe::dajMiejsce()
{
    return miejsce;
}