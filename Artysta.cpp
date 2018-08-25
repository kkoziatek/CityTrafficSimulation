/* 
 * File:   Artysta.cpp
 * Author: Komputer
 * 
 * Created on 15 luty 2017, 17:00
 */

#include "Artysta.h"

Artysta::Artysta() {
}

Artysta::Artysta(int idd, Miejsce* M1, Miejsce* M2): Osoba(idd, M1, M2)
{
}

Artysta::~Artysta() 
{
}

Miejsce* Artysta::dajMiejscePracy(int dzien)
{
    return praca[dzien];
}

Miejsce* Artysta::daj2MiejscePracy(int dzien)
{
    return nullptr;
}

int Artysta::dajPoczatekPracy(int dzien)
{
    return poczatekPracy[dzien];
}

int Artysta::dajDlugoscPracy(int dzien)
{
    return dlugoscPracy[dzien];
}

void Artysta::dodajPoczatekPracy(int dzien, int godz)  //zawsze 8 * 60
{
    poczatekPracy[dzien] = godz;
}

void Artysta::dodajDlugoscPracy(int dzien, int godz)
{
    dlugoscPracy[dzien] = godz;
}

string Artysta::dajKtoJestem()
{
    return "artysta";
}

void Artysta::dodajMiejscePracy(int dzien, Miejsce* M)
{
    praca[dzien] = M;
}

