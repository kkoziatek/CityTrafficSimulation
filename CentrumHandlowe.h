/* 
 * File:   CentrumHandlowe.h
 * Author: Komputer
 *
 * Created on 14 luty 2017, 18:13
 */

#ifndef CENTRUMHANDLOWE_H
#define	CENTRUMHANDLOWE_H

#include <iostream>
#include <vector>
#include <string>

#include "Miejsce.h"

using namespace std;

class CentrumHandlowe {
    int nr;
    Miejsce* miejsce;
    vector <Osoba*> osoba;
    string nazwa;
    
public:
    CentrumHandlowe();
    CentrumHandlowe(int n, Miejsce* miej, string nazw);
    CentrumHandlowe(const CentrumHandlowe& CH) = default;
    virtual ~CentrumHandlowe() = default;
    
    //API
    void dodajOsobe(Osoba* O);
    int dajLiczbeOsob();
    Osoba* dajOsobe(int n);
    void usunOsobe(int n);
    void usunOsobeBezSpr(Osoba* O);
    void wyrzucOsoby();
    string dajNazwe();
    Miejsce* dajMiejsce();
    
private:

};

#endif	/* CENTRUMHANDLOWE_H */

