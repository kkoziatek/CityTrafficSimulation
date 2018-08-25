/* 
 * File:   ZdarzeniePodrozTeatr.h
 * Author: Komputer
 *
 * Created on 14 luty 2017, 19:48
 */

#ifndef ZDARZENIEPODROZTEATR_H
#define	ZDARZENIEPODROZTEATR_H

#include "Zdarzenie.h"
#include "Obiekt.h"
#include "Osoba.h"

#include "Miejsce.h"
#include "Tramwaj.h"
#include "Przystanek.h"

using namespace std;

class ZdarzeniePodrozTeatr : public Zdarzenie // zakladam, ze Osoba jest na miejscu start(w tablicy tego miejsca) i jej tuJestem == start
{
    Miejsce* start;
    Miejsce* cel;
    miejscezlinia trasa;
    Osoba* osoba;
    int nrZ;
    Teatr* teatr;
int nrLinii;
    public:
    // API
    void zajdz() const;             // Niech to zdarzenie zajdzie       // Daje identyfikator zdarzenia
    virtual string to_stringImpl() const;   // Postać tekstowa obiektu, przydatna szczególnie przy debugowaniu. Zwykle używa się nazwy to_string().
    //techniczne
    ZdarzeniePodrozTeatr(int, KolejkaZdarzen&, Miejsce*, Miejsce*, miejscezlinia, Osoba*, int, Teatr*);            // Konstruktor główny
    ZdarzeniePodrozTeatr()                               = delete;  // Zdarzenia wymagają danych, konstr. bezarg. to nie dla nich!
    ZdarzeniePodrozTeatr(const ZdarzeniePodrozTeatr&)               = delete;  // Nie chcemy kopiować zdarzeń
    ~ZdarzeniePodrozTeatr()                      = default; // Ta deklaracja jest konieczna zwn virtual!
    // bardzo techniczne
    ZdarzeniePodrozTeatr(ZdarzeniePodrozTeatr&&)                    = delete;  // Nie omawialiśmy
    ZdarzeniePodrozTeatr& operator=(ZdarzeniePodrozTeatr&&)         = delete;  // Nie omawialiśmy
    friend ostream& operator<<(ostream& o, const ZdarzeniePodrozTeatr& z);
};

#endif	/* ZDARZENIEPODROZTEATR_H */

