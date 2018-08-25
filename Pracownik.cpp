/* 
 * File:   Pracownik.cpp
 * Author: Komputer
 * 
 * Created on 15 luty 2017, 19:33
 */

#include "Pracownik.h"

Pracownik::Pracownik() {
}

Pracownik::Pracownik(int idd, Miejsce* M1, Miejsce* M2, Miejsce* P): Osoba(idd, M1, M2), praca(P)
{
}

Pracownik::~Pracownik() 
{
}

Miejsce* Pracownik::dajMiejscePracy(int dzien)
{
    return praca;
}

int Pracownik::dajPoczatekPracy(int dzien)
{
    return poczatekPracy;
}

int Pracownik::dajDlugoscPracy(int dzien)
{
    return 9;
}

Miejsce* Pracownik::daj2MiejscePracy(int dzien)
{
    return nullptr;
}

void Pracownik::dodajMiejscePracy(int dzien, Miejsce* M)
{
    
}

void Pracownik::dodajPoczatekPracy(int dzien, int godz)  //zawsze 8 * 60
{
    poczatekPracy = godz;
}

void Pracownik::dodajDlugoscPracy(int dzien, int godz)
{
    
}

string Pracownik::dajKtoJestem()
{
    return "pracownik";
}

