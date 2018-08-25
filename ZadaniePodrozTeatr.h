/* 
 * File:   ZadaniePodrozTeatr.h
 * Author: Komputer
 *
 * Created on 16 luty 2017, 21:38
 */

#ifndef ZADANIEPODROZTEATR_H
#define	ZADANIEPODROZTEATR_H

#include "Miejsce.h"
#include "Zdarzenie.h"
#include "ZdarzeniePodroz.h"
#include "ZdarzeniePodrozTeatr.h"

#include "Zadanie.h"

class ZadaniePodrozTeatr : public Zadanie{
    KolejkaZdarzen& kol;
    int nrZ;              // Zdarzenie o jakim nrZ dodajemy ?
    int dodajCzas;
    Miejsce* start;
    Miejsce* cel;
    miejscezlinia trasa;
    Osoba* osoba;
    Teatr* teatr;
public:
    ZadaniePodrozTeatr() = delete;
    ZadaniePodrozTeatr(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn, Teatr* Te);
    ZadaniePodrozTeatr(const ZadaniePodrozTeatr& ZP) = default;
    virtual ~ZadaniePodrozTeatr() = default;
    
    //API
    void zajdz(int czas, Miejsce* tutajJestem);
private:

};

#endif	/* ZADANIEPODROZTEATR_H */

