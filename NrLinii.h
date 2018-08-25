/* 
 * File:   NrLinii.h
 * Author: Komputer
 *
 * Created on 4 luty 2017, 13:19
 */

#ifndef NRLINII_H
#define	NRLINII_H

#include <vector>
#include <iostream>

#include "Miejsce.h"
#include "Przystanek.h"
#include "Tramwaj.h"

#include "ZdarzeniePrzyjazdNaPrzystanek.h"
#include "ZdarzenieOdjazd.h"

class NrLinii {
    int nr;
    Miejsce* zajezdnia1;
    Miejsce* zajezdnia2;
    int liczPrzyst;  //zakl, ze >=2
    vector <Przystanek*> przyst;
    vector <int> czasPrzejazdu;
    int liczTram;
    int liczTramWeekend;
    vector <Tramwaj*> tramwaj;
    KolejkaZdarzen* kolejka;
public:
    NrLinii();
    NrLinii(int nnr, Miejsce* zaj1, Miejsce* zaj2, int liczP, int liczT, int liczTW, KolejkaZdarzen* kol); 
    NrLinii(const NrLinii& orig) = default;
    ~NrLinii() = default;
    
    //API
    void dodajPrzystanek(Przystanek* P);
    void dodajCzasPrzejazdu(int t);
    void dodajTramwaj(Tramwaj* T);
    int dajLiczbeTramwajow();
    Tramwaj* dajTramwaj(int nrTram);
    int dajLiczbePrzystankow();
    Przystanek* dajPrzystanek(int nrPrzyst);
    Miejsce* innaZajezdniaNizTa(Miejsce* zaj);
    void zniszczTramwaje();
    int dajNr();
    Miejsce* dajKolejneMiejsce(Miejsce* teraz, Miejsce* zajezdnia);
    void ustawTramwaje();
    void ustawTramwajeWeekend();
    void przejazdTamPowrot(int start, int koniec, Miejsce* zajezdniaStart, Tramwaj* T);
    void wyruszamy(int start, int koniec);
    void wyruszamyWeekend(int start, int koniec);
    int dajCzasPolCyklu();
    int czasPrzej(Przystanek*, Przystanek*);
    
    friend ostream& operator<<(ostream& o, const NrLinii& NL);

};

#endif	/* NRLINII_H */

