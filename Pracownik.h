/* 
 * File:   Pracownik.h
 * Author: Komputer
 *
 * Created on 15 luty 2017, 19:33
 */

#ifndef PRACOWNIK_H
#define	PRACOWNIK_H

#include <iostream>

#include "Miejsce.h"
#include "Osoba.h"

class Pracownik : public Osoba{
    Miejsce* praca;
    int poczatekPracy;
public:
    Pracownik();
    Pracownik(int, Miejsce*, Miejsce*, Miejsce*);
    Pracownik(const Pracownik& P) = default;
    virtual ~Pracownik();
    
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

#endif	/* PRACOWNIK_H */

