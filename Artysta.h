/* 
 * File:   Artysta.h
 * Author: Komputer
 *
 * Created on 15 luty 2017, 17:00
 */

#ifndef ARTYSTA_H
#define	ARTYSTA_H

#include <iostream>

#include "Miejsce.h"
#include "Osoba.h"

class Artysta : public Osoba{
    Miejsce* praca[7];
    int poczatekPracy[7];
    int dlugoscPracy[7];
public:
    Artysta();
    Artysta(int, Miejsce*, Miejsce*);
    Artysta(const Artysta& A) = default;
    virtual ~Artysta();
    
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

#endif	/* ARTYSTA_H */

