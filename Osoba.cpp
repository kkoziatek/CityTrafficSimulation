/* 
 * File:   Osoba.cpp
 * Author: Komputer
 * 
 * Created on 12 luty 2017, 18:30
 */

#include "Osoba.h"

Osoba::Osoba() 
{
    konT = nullptr;
    konCH = nullptr;
}

Osoba::Osoba(int idd, Miejsce* M1, Miejsce* M2): id(idd), jestemTu(M1), mieszkamTu(M2)
{
    konT = nullptr;
    konCH = nullptr;
}

Osoba::dajId()
{
    return id;
}

void Osoba::ustawTrasePrzejazdu(miejscezlinia T)
{
    trasaPrzejazdu = T;
}

Miejsce* Osoba::dajKolejneMiejsce()
{
    return trasaPrzejazdu.dane[0].miej;
}

NrLinii* Osoba::dajKolejnaLinie()
{
    return trasaPrzejazdu.dane[0].nrL;
}

void Osoba::usunPoczTrasy()
{
    if(trasaPrzejazdu.dane.size())  // > 0
    {
        trasaPrzejazdu.dane.erase(trasaPrzejazdu.dane.begin());
    }
    else 
    {
        cout << "Blad ! : [Osoba::usunPoczTrasy] : Nie mozna usunac poczatku trasy, bo trasa pusta" << endl;
    }
}

bool Osoba::czyTrasaPusta()
{
    return (trasaPrzejazdu.dane.size() == 0);
}

void Osoba::ustawJestemTu(Miejsce* M)
{
    jestemTu = M;
}

Miejsce* Osoba::dajJestemTu()
{
    return jestemTu;
}

void Osoba::przenies(Miejsce* M)
{
    (*jestemTu).usunOsobe(this);
    ustawJestemTu(M);
    (*jestemTu).dodajOsobe(this);
}

void Osoba::przeniesBezSpr(Miejsce* M) //Moze takiej osoby nie byc na miejscu
{
    (*jestemTu).usunOsobeBezSpr(this);
    ustawJestemTu(M);
    (*jestemTu).dodajOsobe(this);
}

Miejsce* Osoba::dajMieszkamTu()
{
    return mieszkamTu;
}

void Osoba::akcjaKonPodr(int czas)
{
    int czasDzien = czas / (24 * 60);
    int czasGodzina = czas / 60 - czasDzien * 24;
    int czasMinuta = czas % 60;
    
    if(konT != nullptr)
    {
        (*konT).dodajOsobe(this);
        cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta << " : Osoba o id: " << id << " typu: " << dajKtoJestem() << " weszla do teatru: " << (*konT).dajNazwe() << endl << endl;
        konT = nullptr;
    }
    else
    {
        if (konCH != nullptr)
        {
            (*konCH).dodajOsobe(this);
            cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta << " : Osoba o id: " << id << " typu: " << dajKtoJestem() << " weszla do centrum handlowego: " << (*konCH).dajNazwe() << endl << endl;
            konCH = nullptr;
        }
    }
}

void Osoba::akcjaDodajTeatr(Teatr* Tr)
{
    konT = Tr;
}

void Osoba::akcjaDodajCH(CentrumHandlowe* Centr)
{
    konCH = Centr;
}

void Osoba::akcjaUsunTeatr()
{
    konT = nullptr;
}

void Osoba::akcjaUsunCH()
{
    konCH = nullptr;
}

void Osoba::dodajZadaniePodroz(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn)
{
    Zadanie* nowez = new ZadaniePodroz(dC, ko, c, T, O, nn);
    zadanie.push_back(nowez);
}

void Osoba::dodajZadaniePodrozCH(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn, CentrumHandlowe* Cenh)
{
    Zadanie* nowez = new ZadaniePodrozCH(dC, ko, c, T, O, nn, Cenh);
    zadanie.push_back(nowez);
}

void Osoba::dodajZadaniePodrozTeatr(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn, Teatr* tr)
{
    Zadanie* nowez = new ZadaniePodrozTeatr(dC, ko, c, T, O, nn, tr);
    zadanie.push_back(nowez);
}

void Osoba::dodajZadanieNic()
{
    Zadanie* nowez = new ZadanieNic();
    zadanie.push_back(nowez);
}

void Osoba::usunZadania()
{
    for(int i = 0; i < zadanie.size(); i++)
    {
        delete zadanie[i];
    }
    zadanie.clear();
}

void Osoba::ustawNrZ(int n)
{
    nrZ = n;
}

int Osoba::dajNrZ()
{
    return nrZ;
}

Zadanie* Osoba::dajZadanie(int n)
{
    if (n >= zadanie.size())
    {
        cout << "Blad ! : [Osoba::dajZadanie] : Nie ma zadania o nr. " << n <<". Jest tylko " << zadanie.size() << " zadan." << endl;
    }
    return zadanie[n];
}

void Osoba::dodajSpektakl(Spektakl* S)
{
    spektakl = S;
}

Spektakl* Osoba::dajSpektakl()
{
    return spektakl;
}