/* 
 * File:   ZdarzeniePrzyjazdNaPrzystanek.h
 * Author: Komputer
 *
 * Created on 11 luty 2017, 10:31
 */

#ifndef ZDARZENIEPRZYJAZDNAPRZYSTANEK_H
#define	ZDARZENIEPRZYJAZDNAPRZYSTANEK_H

#include "Zdarzenie.h"
#include "Obiekt.h"

#include "Tramwaj.h"
#include "Przystanek.h"

using namespace std;

class ZdarzeniePrzyjazdNaPrzystanek : public Zdarzenie
{
Tramwaj *tramwaj;
Przystanek *przystanek;
int nrLinii;
    public:
    // API
    void zajdz() const;             // Niech to zdarzenie zajdzie       // Daje identyfikator zdarzenia
    virtual string to_stringImpl() const;   // Postać tekstowa obiektu, przydatna szczególnie przy debugowaniu. Zwykle używa się nazwy to_string().
    //techniczne
    ZdarzeniePrzyjazdNaPrzystanek(int, KolejkaZdarzen&, Tramwaj*, Przystanek*, int);            // Konstruktor główny
    ZdarzeniePrzyjazdNaPrzystanek()                               = delete;  // Zdarzenia wymagają danych, konstr. bezarg. to nie dla nich!
    ZdarzeniePrzyjazdNaPrzystanek(const ZdarzeniePrzyjazdNaPrzystanek&)               = delete;  // Nie chcemy kopiować zdarzeń
    ~ZdarzeniePrzyjazdNaPrzystanek()                      = default; // Ta deklaracja jest konieczna zwn virtual!
    // bardzo techniczne
    ZdarzeniePrzyjazdNaPrzystanek(ZdarzeniePrzyjazdNaPrzystanek&&)                    = delete;  // Nie omawialiśmy
    ZdarzeniePrzyjazdNaPrzystanek& operator=(ZdarzeniePrzyjazdNaPrzystanek&&)         = delete;  // Nie omawialiśmy
    friend ostream& operator<<(ostream& o, const ZdarzeniePrzyjazdNaPrzystanek& z);
};


#endif	/* ZDARZENIEPRZYJAZDNAPRZYSTANEK_H */

