#ifndef MIEJSCE_H
#define	MIEJSCE_H

#include <string>
#include <vector>
#include <iostream>

#include "KolejkaZdarzen.h"

using namespace std;

class Przystanek;
class Osoba;
class Uczen;
class Artysta;
class Pracujacy;
class Student;
class NrLinii;

class Teatr;
class CentrumHandlowe;
class Uniwersytet;

class Spektakl;

class Miejsce;

struct mzl
    {
        Miejsce* miej;
        NrLinii* nrL;
    };
struct miejscezlinia
    {
        vector <mzl> dane;
        int odl;
    };

class Miejsce {
    string nazwa;
    vector <Osoba*> osoba;
    Przystanek* przystanek;
    bool czyTeatr;
    Teatr* teatr;
    bool czyCH;
    CentrumHandlowe* CH;
    Uniwersytet* uniwersytet;
    
public:
    Miejsce();
    Miejsce(string naz);
    Miejsce(const Miejsce& M) = default;
    ~Miejsce() = default;
    
    //API
    string dajNazwe();
    void dodajPrzystanek(Przystanek* P);
    Przystanek* dajPrzystanek();
    void dodajOsobe(Osoba*);
    int dajLiczbeOsob();
    Osoba* dajOsobe(int n);
    void usunOsobe(Osoba*);
    void usunOsobeBezSpr(Osoba*);
    
    void dodajTeatr(Teatr* T);
    void dodajCH(CentrumHandlowe *CenH);
    bool czyJestTeatr();
    Teatr* dajTeatr();
    bool czyJestCH();
    CentrumHandlowe* dajCH();
    void dodajUniwersytet(Uniwersytet* U);
    Uniwersytet* dajUniwersytet();

    friend ostream& operator<<(ostream& o, const Miejsce& M);

};

#endif	/* MIEJSCE_H */

