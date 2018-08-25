/* 
 * File:   Teatr.cpp
 * Author: Komputer
 * 
 * Created on 14 luty 2017, 17:59
 */

#include "Teatr.h"

Teatr::Teatr() {
}

Teatr::Teatr(int n, Miejsce* miej, string nazw, int liczM):nr(n), miejsce(miej), nazwa(nazw), liczbaMiejsc(liczM)
{
    for(int i = 0; i < 5; i++)
    {
        czyGramy[i] = rand() % 2;
    }
}

void Teatr::dodajOsobe(Osoba* O)
{
    osoba.push_back(O);
}

int Teatr::dajLiczbeOsob()
{
    return osoba.size();
}

Osoba* Teatr::dajOsobe(int n)
{
    if(n >= osoba.size())
    {
        cout << "Blad ! [Teatr::dajOsobe]: Nie ma osoby o nr " << n << " w teatrze. Jest tylko " << osoba.size() << "osob." << endl;
        return nullptr;
    }
    
    return osoba[n];
}

void Teatr::usunOsobe(int n)
{
    if(n >= osoba.size())
    {
        cout << "Blad ! [Teatr::dajOsobe]: Nie ma osoby o nr " << n << " w teatrze. Jest tylko " << osoba.size() << "osob." << endl;
    }
    
    else
    {
        osoba.erase(osoba.begin() + n);
    }
}

void Teatr::usunOsobeBezSpr(Osoba* O)
{
    for(int i = 0; i < osoba.size(); i++)
    {
        if(osoba[i] == O)
        {
            osoba.erase(osoba.begin() + i);
        }
    }
}

void Teatr::wyrzucOsoby()
{
    osoba.clear();
}

string Teatr::dajNazwe()
{
    return nazwa;
}

Miejsce* Teatr::dajMiejsce()
{
    return miejsce;
}

void Teatr::zniszczSpektakle()
{
    for(int i = 0; i < spektakl.size(); i++)
    {
        delete spektakl[i];
    }
    spektakl.clear();
}

void Teatr::odnowSpektakle(int dzienSym, int dzienTyg)
{
    zniszczSpektakle();
    
    wolnySpek = 0;
    
    dzienSym--;
    dzienTyg--;
    
    int dzien = -1;
    int czasPoczDnia;
    int nrSpek = 0;
    while(dzien < 30 - 1)
    {
        dzien++;
        dzienSym++;
        dzienTyg++;
        czasPoczDnia = dzienSym * 24 * 60;
        
        if(dzienTyg % 7 == 0) // nowy tydzien
        {
            dzienTyg = 0;
        }
        
        if((0 <= dzienTyg) && (dzienTyg <= 4))
        {
            if(czyGramy[dzienTyg])
            {
                int dlSpek = (rand() % (2 * 60)) + 1 * 60;
                Spektakl* spek = new Spektakl(nrSpek, dzienSym, 19 * 60, dlSpek, liczbaMiejsc, miejsce);
                spektakl.push_back(spek);
                nrSpek++;
            }
        }
        
        if((5 <= dzienTyg) && (dzienTyg <= 6))
        {
            
            int dlSpek = (rand() % (2 * 60)) + 1 * 60;
            Spektakl* spek = new Spektakl(nrSpek, dzienSym, 17 * 60, dlSpek, liczbaMiejsc, miejsce);
            spektakl.push_back(spek);
            nrSpek++;
            
            dlSpek = (rand() % (2 * 60)) + 1 * 60;
            spek = new Spektakl(nrSpek, dzienSym, 19 * 60, dlSpek, liczbaMiejsc, miejsce);
            spektakl.push_back(spek);
            nrSpek++;
        }
    }
   
}

void Teatr::zapiszOsobe(Osoba* O)
{
    if(wolnySpek < spektakl.size())
    {
        (*spektakl[wolnySpek]).dodajOsobe(O);
        (*O).dodajSpektakl(spektakl[wolnySpek]);
        if(!((*spektakl[wolnySpek]).czyWolne()))
        {
            wolnySpek++;
        }
    }
    else
    {
        (*O).dodajSpektakl(nullptr);
    }
}
   
int Teatr::dajLiczbeMiejsc()
{
    return liczbaMiejsc;
}