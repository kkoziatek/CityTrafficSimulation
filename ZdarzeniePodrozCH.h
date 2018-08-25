/* 
 * File:   ZdarzeniePodrozCH.h
 * Author: Komputer
 *
 * Created on 16 luty 2017, 13:16
 */

#ifndef ZDARZENIEPODROZCH_H
#define	ZDARZENIEPODROZCH_H

#include "Zdarzenie.h"
#include "Obiekt.h"
#include "Osoba.h"

#include "Miejsce.h"
#include "Tramwaj.h"
#include "Przystanek.h"

using namespace std;

class ZdarzeniePodrozCH : public Zdarzenie // zakladam, ze Osoba jest na miejscu start(w tablicy tego miejsca) i jej tuJestem == start
{
    Miejsce* start;
    Miejsce* cel;
    miejscezlinia trasa;
    Osoba* osoba;
    int nrZ;
    CentrumHandlowe* CH;
int nrLinii;
    public:
    // API
    void zajdz() const;             // Niech to zdarzenie zajdzie       // Daje identyfikator zdarzenia
    virtual string to_stringImpl() const;   // Postać tekstowa obiektu, przydatna szczególnie przy debugowaniu. Zwykle używa się nazwy to_string().
    //techniczne
    ZdarzeniePodrozCH(int, KolejkaZdarzen&, Miejsce*, Miejsce*, miejscezlinia, Osoba*, int, CentrumHandlowe*);            // Konstruktor główny
    ZdarzeniePodrozCH()                               = delete;  // Zdarzenia wymagają danych, konstr. bezarg. to nie dla nich!
    ZdarzeniePodrozCH(const ZdarzeniePodrozCH&)               = delete;  // Nie chcemy kopiować zdarzeń
    ~ZdarzeniePodrozCH()                      = default; // Ta deklaracja jest konieczna zwn virtual!
    // bardzo techniczne
    ZdarzeniePodrozCH(ZdarzeniePodrozCH&&)                    = delete;  // Nie omawialiśmy
    ZdarzeniePodrozCH& operator=(ZdarzeniePodrozCH&&)         = delete;  // Nie omawialiśmy
    friend ostream& operator<<(ostream& o, const ZdarzeniePodrozCH& z);
};

#endif	/* ZDARZENIEPODROZCH_H */

