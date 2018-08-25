/* 
 * File:   ZdarzenieKonkretne.h
 * Author: Komputer
 *
 * Created on 10 luty 2017, 19:52
 */

#ifndef ZDARZENIEKONKRETNE_H
#define	ZDARZENIEKONKRETNE_H

#include "Zdarzenie.h"
#include "Obiekt.h"

using namespace std;

class ZdarzenieKonkretne : public Zdarzenie
{
Obiekt& kto;
    public:
    // API
    void zajdz() const;             // Niech to zdarzenie zajdzie       // Daje identyfikator zdarzenia
    virtual string to_stringImpl() const;   // Postać tekstowa obiektu, przydatna szczególnie przy debugowaniu. Zwykle używa się nazwy to_string().
    //techniczne
    ZdarzenieKonkretne(int, KolejkaZdarzen&, Obiekt&);            // Konstruktor główny
    ZdarzenieKonkretne()                               = delete;  // Zdarzenia wymagają danych, konstr. bezarg. to nie dla nich!
    ZdarzenieKonkretne(const ZdarzenieKonkretne&)               = delete;  // Nie chcemy kopiować zdarzeń
    ~ZdarzenieKonkretne()                      = default; // Ta deklaracja jest konieczna zwn virtual!
    // bardzo techniczne
    ZdarzenieKonkretne(ZdarzenieKonkretne&&)                    = delete;  // Nie omawialiśmy
    ZdarzenieKonkretne& operator=(ZdarzenieKonkretne&&)         = delete;  // Nie omawialiśmy
    friend ostream& operator<<(ostream& o, const ZdarzenieKonkretne& z);
};


#endif	/* ZDARZENIEKONKRETNE_H */

