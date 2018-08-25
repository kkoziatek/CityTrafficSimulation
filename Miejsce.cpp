/* 
 * File:   Miejsce.cpp
 * Author: Komputer
 * 
 * Created on 3 luty 2017, 14:33
 */

#include "Miejsce.h"

Miejsce::Miejsce() 
{
    czyTeatr = 0;
    czyCH = 0;
    uniwersytet = nullptr;
}

Miejsce::Miejsce(string naz):nazwa(naz)
{
    czyTeatr = 0;
    czyCH = 0;
    uniwersytet = nullptr;
}

string Miejsce::dajNazwe()
{
    return(nazwa);
}

void Miejsce::dodajPrzystanek(Przystanek* P)
{
    przystanek = P;
}

Przystanek* Miejsce::dajPrzystanek()
{
    return przystanek;
}

ostream& operator<<(ostream& o, const Miejsce& M)
{
    o << M.nazwa;
    return o;  
}

void Miejsce::dodajOsobe(Osoba* O)
{
    osoba.push_back(O);
}

int Miejsce::dajLiczbeOsob()
{
    return osoba.size();
}

Osoba* Miejsce::dajOsobe(int n)
{
    return(osoba[n]);
}

void Miejsce::usunOsobe(Osoba* O)
{
    bool ok = 0;
    for(int i = 0; i < osoba.size(); i++)
    {
        if(osoba[i] == O)
        {
            osoba.erase(osoba.begin() + i);
            ok = 1;
        }
    }
    if(ok == 0)
    {
        cout << "Blad ! : [Miejsce::usunOsobe] : Nie ma osoby o adresie: " << O << endl;
    }
}

void Miejsce::usunOsobeBezSpr(Osoba* O) // Moze nie byc takiej osoby na miejscu
{
    bool ok = 0;
    for(int i = 0; i < osoba.size(); i++)
    {
        if(osoba[i] == O)
        {
            osoba.erase(osoba.begin() + i);
            ok = 1;
        }
    }
    if(ok == 0)
    {
        // Nie bylo takiej osoby
    }
}

bool Miejsce::czyJestTeatr()
{
    return czyTeatr;
}
    
Teatr* Miejsce::dajTeatr()
{
    return teatr;
}

bool Miejsce::czyJestCH()
{
    return czyCH;
}

CentrumHandlowe* Miejsce::dajCH()
{
    return CH;
}

void Miejsce::dodajTeatr(Teatr* T)
{
    teatr = T;
    czyTeatr = 1;
}

void Miejsce::dodajCH(CentrumHandlowe *CenH)
{
    CH = CenH;
    czyCH = 1;
}

void Miejsce::dodajUniwersytet(Uniwersytet* U)
{
    uniwersytet = U;
}

Uniwersytet* Miejsce::dajUniwersytet()
{
    return uniwersytet;
}