/* 
 * File:   ZadaniePodrozCH.cpp
 * Author: Komputer
 * 
 * Created on 16 luty 2017, 15:09
 */

#include "ZadaniePodrozCH.h"
#include "Zadanie.h"

ZadaniePodrozCH::ZadaniePodrozCH(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn, CentrumHandlowe* Cen): kol(ko), nrZ(nn),
          dodajCzas(dC), cel(c), trasa(T), osoba(O), CH(Cen)
{
}

void ZadaniePodrozCH::zajdz(int czas, Miejsce* tutajJestem)
{
    int dzien1 = czas / (24 * 60);
    int dzien2 = (czas + dodajCzas) / (24 * 60);
    if(dzien1 == dzien2)   // chcemy dodawac zdarzenia tylko tego samego dnia
    {
        kol.wstaw(new ZdarzeniePodrozCH(czas + dodajCzas, kol, tutajJestem, cel, trasa, osoba, nrZ, CH));
    }
    
}
