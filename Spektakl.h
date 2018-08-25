/* 
 * File:   Spektakl.h
 * Author: Komputer
 *
 * Created on 16 luty 2017, 18:29
 */

#ifndef SPEKTAKL_H
#define	SPEKTAKL_H

#include <iostream>
#include <vector>

#include "Osoba.h"


class Spektakl {
    int nr;
    int dzienSym;
    int godz;
    vector <Osoba*> osoba;
    int dlugSpek;
    int liczMiejsc;
    Miejsce* miejsce;

public:
    Spektakl();
    Spektakl(int n, int dz, int g, int dl, int lm, Miejsce* M);
    Spektakl(const Spektakl& S) = default;
    virtual ~Spektakl() = default;
    
    //API
    bool czyWolne();
    void dodajOsobe(Osoba* O);
    friend ostream& operator<<(ostream& o, const Spektakl& S);
    int dajDzienSym();
    int dajGodz();
    Miejsce* dajMiejsce();
    int dajDlugSpek();
    
private:

};

#endif	/* SPEKTAKL_H */

