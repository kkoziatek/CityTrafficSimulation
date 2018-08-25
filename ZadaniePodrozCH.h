/* 
 * File:   ZadaniePodrozCH.h
 * Author: Komputer
 *
 * Created on 16 luty 2017, 15:09
 */

#ifndef ZADANIEPODROZCH_H
#define	ZADANIEPODROZCH_H

#include "Miejsce.h"
#include "Zdarzenie.h"
#include "ZdarzeniePodroz.h"
#include "ZdarzeniePodrozCH.h"

#include "Zadanie.h"

class ZadaniePodrozCH : public Zadanie{
    KolejkaZdarzen& kol;
    int nrZ;              // Zdarzenie o jakim nrZ dodajemy ?
    int dodajCzas;
    Miejsce* start;
    Miejsce* cel;
    miejscezlinia trasa;
    Osoba* osoba;
    CentrumHandlowe* CH;
public:
    ZadaniePodrozCH() = delete;
    ZadaniePodrozCH(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn, CentrumHandlowe* Cen);
    ZadaniePodrozCH(const ZadaniePodrozCH& ZP) = default;
    virtual ~ZadaniePodrozCH() = default;
    
    //API
    void zajdz(int czas, Miejsce* tutajJestem);
private:

};

#endif	/* ZADANIEPODROZCH_H */

