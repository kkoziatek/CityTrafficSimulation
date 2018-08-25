/* 
 * File:   ZadaniePodrozTeatr.cpp
 * Author: Komputer
 * 
 * Created on 16 luty 2017, 21:38
 */

#include "ZadaniePodrozTeatr.h"

#include "Zadanie.h"

ZadaniePodrozTeatr::ZadaniePodrozTeatr(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn, Teatr* Te): kol(ko), nrZ(nn),
          dodajCzas(dC), cel(c), trasa(T), osoba(O), teatr(Te)
{
}

void ZadaniePodrozTeatr::zajdz(int czas, Miejsce* tutajJestem)
{
    int dzien1 = czas / (24 * 60);
    int dzien2 = (czas + dodajCzas) / (24 * 60);
    if(dzien1 == dzien2)   // chcemy dodawac zdarzenia tylko tego samego dnia
    {
        kol.wstaw(new ZdarzeniePodrozTeatr(czas + dodajCzas, kol, tutajJestem, cel, trasa, osoba, nrZ, teatr));
    }
    
}

