/* 
 * File:   ZadaniePodroz.cpp
 * Author: Komputer
 * 
 * Created on 14 luty 2017, 22:02
 */

#include "ZadaniePodroz.h"
#include "Zadanie.h"

ZadaniePodroz::ZadaniePodroz(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn): kol(ko), nrZ(nn),
          dodajCzas(dC), cel(c), trasa(T), osoba(O)
{
}

void ZadaniePodroz::zajdz(int czas, Miejsce* tutajJestem)
{
    int dzien1 = czas / (24 * 60);
    int dzien2 = (czas + dodajCzas) / (24 * 60);
    if(dzien1 == dzien2)   // chcemy dodawac zdarzenia tylko tego samego dnia
    {
        kol.wstaw(new ZdarzeniePodroz(czas + dodajCzas, kol, tutajJestem, cel, trasa, osoba, nrZ));
    }
    
}

