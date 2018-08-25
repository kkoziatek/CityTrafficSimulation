/* 
 * File:   ZdarzenieOdjazd.h
 * Author: Komputer
 *
 * Created on 12 luty 2017, 11:30
 */

#ifndef ZDARZENIEODJAZD_H
#define	ZDARZENIEODJAZD_H

#include "Zdarzenie.h"
#include "Obiekt.h"

#include "Tramwaj.h"
#include "Przystanek.h"

using namespace std;

class ZdarzenieOdjazd : public Zdarzenie
{
Tramwaj *tramwaj;
Przystanek *przystanek;
int nrLinii;
    public:
    // API
    void zajdz() const;             // Niech to zdarzenie zajdzie       // Daje identyfikator zdarzenia
    virtual string to_stringImpl() const;   // Postać tekstowa obiektu, przydatna szczególnie przy debugowaniu. Zwykle używa się nazwy to_string().
    //techniczne
    ZdarzenieOdjazd(int, KolejkaZdarzen&, Tramwaj*, Przystanek*, int);            // Konstruktor główny
    ZdarzenieOdjazd()                               = delete;  // Zdarzenia wymagają danych, konstr. bezarg. to nie dla nich!
    ZdarzenieOdjazd(const ZdarzenieOdjazd&)               = delete;  // Nie chcemy kopiować zdarzeń
    ~ZdarzenieOdjazd()                      = default; // Ta deklaracja jest konieczna zwn virtual!
    // bardzo techniczne
    ZdarzenieOdjazd(ZdarzenieOdjazd&&)                    = delete;  // Nie omawialiśmy
    ZdarzenieOdjazd& operator=(ZdarzenieOdjazd&&)         = delete;  // Nie omawialiśmy
    friend ostream& operator<<(ostream& o, const ZdarzenieOdjazd& z);
};

#endif	/* ZDARZENIEODJAZD_H */

