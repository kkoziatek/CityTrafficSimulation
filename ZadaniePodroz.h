/* 
 * File:   ZadaniePodroz.h
 * Author: Komputer
 *
 * Created on 14 luty 2017, 22:02
 */

#ifndef ZADANIEPODROZ_H
#define	ZADANIEPODROZ_H

#include "Miejsce.h"
#include "Zdarzenie.h"
#include "ZdarzeniePodroz.h"

#include "Zadanie.h"

class ZadaniePodroz : public Zadanie{
    KolejkaZdarzen& kol;
    int nrZ;              // Zdarzenie o jakim nrZ dodajemy ?
    int dodajCzas;
    Miejsce* start;
    Miejsce* cel;
    miejscezlinia trasa;
    Osoba* osoba;
public:
    ZadaniePodroz() = delete;
    ZadaniePodroz(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn);
    ZadaniePodroz(const ZadaniePodroz& ZP) = default;
    virtual ~ZadaniePodroz() = default;
    
    //API
    void zajdz(int czas, Miejsce* tutajJestem);
private:

};

#endif	/* ZADANIEPODROZ_H */
