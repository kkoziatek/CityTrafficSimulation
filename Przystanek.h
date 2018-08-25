/* 
 * File:   Przystanek.h
 * Author: Komputer
 *
 * Created on 3 luty 2017, 19:27
 */

#ifndef PRZYSTANEK_H
#define	PRZYSTANEK_H

#include <vector>

#include "Miejsce.h"

class Tramwaj;
class Przystanek;

struct obok
{
    Przystanek* przyst;
    vector <NrLinii*> nrL;
};

class Przystanek {
    Miejsce* miejsce;
    vector <Tramwaj*> tramwaj;
    vector <Osoba*> osoba;
    int liczPrzystObok;  //liczba sasiednich przystankow
    vector <obok> przystObok;
    
public:
    Przystanek();
    Przystanek(Miejsce* M);
    Przystanek(const Przystanek& P) = default;
    ~Przystanek() = default;
    
    // API
    
    Miejsce* dajMiejsce() const;
    void dodajPrzystObok(Przystanek* P, NrLinii* nL);
    int dajLiczPrzystObok();
    int dajLiczLiniiDoPrzyst(Przystanek* P);
    Przystanek* dajPrzystObok(int n);
    int dajNrLiniiDoPrzyst(int n, int m);
    NrLinii* dajLinieDoPrzyst(int n, int m);
    
    void dodajTramwaj(Tramwaj* T);
    void usunTramwaj(Tramwaj* T);
    int dajLiczbeTramwajow();
    
    void dodajOsobe(Osoba*, int czas);
    void usunOsobe(int n);
    int dajLiczbeOsob();
    Osoba* dajOsobe(int n);
    void wyrzucLudzi();


    friend ostream& operator<<(ostream& o, const Przystanek& P);

};

#endif	/* PRZYSTANEK_H */

