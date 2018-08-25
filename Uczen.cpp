/* 
 * File:   Uczen.cpp
 * Author: Komputer
 * 
 * Created on 13 luty 2017, 10:51
 */

#include "Uczen.h"

Uczen::Uczen() {
}

Uczen::Uczen(int idd, Miejsce* M1, Miejsce* M2, Miejsce* S): Osoba(idd, M1, M2), szkola(S)
{
}

Uczen::~Uczen() 
{
}

Miejsce* Uczen::dajMiejscePracy(int dzien)
{
    return szkola;
}

int Uczen::dajPoczatekPracy(int dzien)
{
    return 8 * 60;
}

int Uczen::dajDlugoscPracy(int dzien)
{
    return dlugoscPracy[dzien];
}

Miejsce* Uczen::daj2MiejscePracy(int dzien)
{
    return nullptr;
}

void Uczen::dodajMiejscePracy(int dzien, Miejsce* M)
{
    
}

void Uczen::dodajPoczatekPracy(int dzien, int godz)  //zawsze 8 * 60
{
    
}

void Uczen::dodajDlugoscPracy(int dzien, int godz)
{
    dlugoscPracy[dzien] = godz;
}

string Uczen::dajKtoJestem()
{
    return "uczen";
}
