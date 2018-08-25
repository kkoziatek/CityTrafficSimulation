/* 
 * File:   Uczen.h
 * Author: Komputer
 *
 * Created on 13 luty 2017, 10:51
 */

#ifndef UCZEN_H
#define	UCZEN_H

#include <iostream>

#include "Miejsce.h"
#include "Osoba.h"

class Uczen : public Osoba{
    Miejsce* szkola;
    int dlugoscPracy[5];
public:
    Uczen();
    Uczen(int, Miejsce*, Miejsce*, Miejsce*);
    Uczen(const Uczen& U) = default;
    virtual ~Uczen();
    
    //API
    string dajKtoJestem();
    Miejsce* dajMiejscePracy(int dzien);
    int dajPoczatekPracy(int dzien);
    int dajDlugoscPracy(int dzien);
    Miejsce* daj2MiejscePracy(int dzien);
    
    void dodajMiejscePracy(int dzien, Miejsce* M);
    void dodajPoczatekPracy(int dzien, int godz);
    void dodajDlugoscPracy(int dzien, int godz);
    
private:

};

#endif	/* UCZEN_H */

