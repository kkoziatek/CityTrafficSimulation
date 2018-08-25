/* 
 * File:   Obiekt.h
 * Author: Komputer
 *
 * Created on 10 luty 2017, 19:51
 */

#ifndef OBIEKT_H
#define	OBIEKT_H

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
#include "KolejkaZdarzen.h"

using namespace std;

class Obiekt {
    int id;
public:
    // API
    virtual void akcja(KolejkaZdarzen&);
    // techniczne
    explicit Obiekt(int id);                     // explicit, bo chcę konstruktora, ale nie konwersję
    Obiekt()                          = default; // Mam lepszy konstruktor
    Obiekt(const Obiekt&)             = delete;  // Nie chcę kopii
    Obiekt& operator=(const Obiekt&)  = delete;  // j.w.
    virtual ~Obiekt()                 = default; // To jest bardzo ważne zw. virtual
    // bardzo techniczne
    Obiekt(Obiekt&&)                  = delete;  // Nie omawialiśmy
    Obiekt& operator=(Obiekt&&)       = delete;  // Nie omawialiśmy
};

#endif	/* OBIEKT_H */

