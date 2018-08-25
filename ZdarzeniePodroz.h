/* 
 * File:   ZdarzeniePodroz.h
 * Author: Komputer
 *
 * Created on 14 luty 2017, 14:00
 */

#ifndef ZDARZENIEPODROZ_H
#define	ZDARZENIEPODROZ_H

#include "Zdarzenie.h"
#include "Obiekt.h"
#include "Osoba.h"

#include "Miejsce.h"
#include "Tramwaj.h"
#include "Przystanek.h"

using namespace std;

class ZdarzeniePodroz : public Zdarzenie // zakladam, ze Osoba jest na miejscu start(w tablicy tego miejsca) i jej tuJestem == start
{
    Miejsce* start;
    Miejsce* cel;
    miejscezlinia trasa;
    Osoba* osoba;
    int nrZ;
int nrLinii;
    public:
    // API
    void zajdz() const;             // Niech to zdarzenie zajdzie       // Daje identyfikator zdarzenia
    virtual string to_stringImpl() const;   // Postać tekstowa obiektu, przydatna szczególnie przy debugowaniu. Zwykle używa się nazwy to_string().
    //techniczne
    ZdarzeniePodroz(int, KolejkaZdarzen&, Miejsce*, Miejsce*, miejscezlinia, Osoba*, int);            // Konstruktor główny
    ZdarzeniePodroz()                               = delete;  // Zdarzenia wymagają danych, konstr. bezarg. to nie dla nich!
    ZdarzeniePodroz(const ZdarzeniePodroz&)               = delete;  // Nie chcemy kopiować zdarzeń
    ~ZdarzeniePodroz()                      = default; // Ta deklaracja jest konieczna zwn virtual!
    // bardzo techniczne
    ZdarzeniePodroz(ZdarzeniePodroz&&)                    = delete;  // Nie omawialiśmy
    ZdarzeniePodroz& operator=(ZdarzeniePodroz&&)         = delete;  // Nie omawialiśmy
    friend ostream& operator<<(ostream& o, const ZdarzeniePodroz& z);
};

#endif	/* ZDARZENIEPODROZ_H */
