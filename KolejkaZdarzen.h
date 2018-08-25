/* 
 * File:   KolejkaZdarzen.h
 * Author: Komputer
 *
 * Created on 10 luty 2017, 19:43
 */

#ifndef KOLEJKAZDARZEN_H
#define	KOLEJKAZDARZEN_H

#include <iostream>
#include <queue>       // priority_queue

// Dodatkowe sprawdzania
#include <cassert>     // assert

// Generacja liczb losowych
#include <cstdlib>     // srand, rand
#include <ctime>       // time, użyty tylko w srand

// Zaślepka
#include <sstream>     // ostringstream - zaślepka dla to_string

#include<vector>
#include<math.h>

#include <string>

#include "Zdarzenie.h"
#include "Compare.h"

using namespace std;

class KolejkaZdarzen {
    priority_queue<const Zdarzenie*, std::vector<const Zdarzenie*>, Compare> zdarzenia;  // Mam kolejkę zdarzeń i nie zawaham się jej użyć
    int czas;                                                                            // Aktualny czas symulacji
public:
    // API
    virtual void wstaw(const Zdarzenie*);             // Wstawia zdarzenie do wykonania w przyszłości
    virtual int ktoraGodzina();                       // Która jest właściwie teraz godzina?
    virtual void niechSieDzieje(int koniecSwiata);    // Wykonuj zdarzenia do wskazanego czasu
    void czyszczenieKolejki();                        // Czysci kolejke ze zdarzen, ktore pozostaly
    // techniczne
    KolejkaZdarzen();                                            // Zaczynamy o godzinie 0 z pustą kolejką zdarzeń
    KolejkaZdarzen(const KolejkaZdarzen&)             = delete;  // Nie kopiuj mnie, proszę. A nawet nalegam.
    KolejkaZdarzen& operator=(const KolejkaZdarzen&)  = delete;  // Patrz konstr. kop.
    virtual ~KolejkaZdarzen()                         = default; // Nie mam wskaźników, więc default mi pasuje!
    // bardzo techniczne
    KolejkaZdarzen(KolejkaZdarzen&&)                  = delete; // Nie omawialiśmy
    KolejkaZdarzen& operator=(KolejkaZdarzen&&)       = delete; // Nie omawialiśmy
};

#endif	/* KOLEJKAZDARZEN_H */

