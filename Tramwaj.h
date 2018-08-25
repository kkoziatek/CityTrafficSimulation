/* 
 * File:   Tramwaj.h
 * Author: Komputer
 *
 * Created on 4 luty 2017, 13:06
 */

#ifndef TRAMWAJ_H
#define	TRAMWAJ_H

#include <vector>

#include "Miejsce.h"
#include "Przystanek.h"

class NrLinii;

class Tramwaj {
    Miejsce* miejsce;
    Miejsce* zajezdniaJadeTam;
    NrLinii* linia;
    vector <Osoba*> osoba;
    int nrLinii;
    int nrTram;
    int pojemnosc;

public:
    Tramwaj();
    Tramwaj(Miejsce* miej, Miejsce* zaj, int nrL, int nrT, int poj);
    Tramwaj(const Tramwaj& T) = default;
    ~Tramwaj() = default;
    
    //API
    Miejsce* dajMiejsce();
    Miejsce* dajZajezdniaJadeTam();
    void dodajLinie(NrLinii*);
    NrLinii* dajLinie();
    int dajNrTram();
    void ustawMiejsce(Miejsce* M);
    void ustawZajezdniaJadeTam(Miejsce* Z);
    void przyjazdNaPrzystanek(Przystanek*, int czas);
    void odjazd(int czas);
    void dodajOsobe(Osoba*);
    void usunOsobe(int ktora);
    void wyrzucLudzi();
      
private:

};

#endif	/* TRAMWAJ_H */

