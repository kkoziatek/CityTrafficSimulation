/* 
 * File:   Spektakl.cpp
 * Author: Komputer
 * 
 * Created on 16 luty 2017, 18:29
 */

#include "Spektakl.h"

Spektakl::Spektakl() {
}

Spektakl::Spektakl(int n, int dz, int g, int dl, int lm, Miejsce* M): nr(n), dzienSym(dz), godz(g), dlugSpek(dl), liczMiejsc(lm), miejsce(M)
{
    
}

bool Spektakl::czyWolne()
{
    return (osoba.size() < liczMiejsc);
}

void Spektakl::dodajOsobe(Osoba* O)
{
    osoba.push_back(O);
}

ostream& operator<<(ostream& o, const Spektakl& S)
{
    o << "Nr spektaklu: " << S.nr << ". Dzien symulacji: " << S.dzienSym << ". Godzina: " << (S.godz)/60 << ":" << (S.godz)%60 << ". Dlugosc spektaklu: " << S.dlugSpek << " Liczba miejsc: " << S.liczMiejsc << ". Miejsce: " << (*(S.miejsce)).dajNazwe() << ".";
    return o;  
}

int Spektakl::dajDzienSym()
{
    return dzienSym;
}

int Spektakl::dajGodz()
{
    return godz;
}

Miejsce* Spektakl::dajMiejsce()
{
    return miejsce;
}

int Spektakl::dajDlugSpek()
{
    return dlugSpek;
}