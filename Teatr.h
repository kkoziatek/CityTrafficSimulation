/* 
 * File:   Teatr.h
 * Author: Komputer
 *
 * Created on 14 luty 2017, 17:59
 */

#ifndef TEATR_H
#define	TEATR_H

#include <iostream>
#include <string>
#include <math.h>

#include "Miejsce.h"
#include "Spektakl.h"

using namespace std;

class Teatr {
    int nr;
    Miejsce* miejsce;
    vector <Osoba*> osoba;
    string nazwa;
    int liczbaMiejsc;
    bool czyGramy[5];
    vector <Spektakl*> spektakl;
    int wolnySpek;
    
public:
    Teatr();
    Teatr(int n, Miejsce* miej, string nazw, int liczM);
    Teatr(const Teatr& T) = default;
    virtual ~Teatr() = default;
    
    //API
    void dodajOsobe(Osoba* O);
    int dajLiczbeOsob();
    Osoba* dajOsobe(int n);
    void usunOsobe(int n);
    void usunOsobeBezSpr(Osoba* O);
    void wyrzucOsoby();
    string dajNazwe();
    Miejsce* dajMiejsce();
    void odnowSpektakle(int dzienSym, int dzienTyg);
    void zniszczSpektakle();
    void zapiszOsobe(Osoba* O);
    int dajLiczbeMiejsc();
    
private:

};

#endif	/* TEATR_H */

