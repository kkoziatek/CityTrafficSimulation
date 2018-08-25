/* 
 * File:   Zdarzenie.h
 * Author: Komputer
 *
 * Created on 10 luty 2017, 19:46
 */

#ifndef ZDARZENIE_H
#define	ZDARZENIE_H

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

using namespace std;

class KolejkaZdarzen;
class Obiekt;

class Zdarzenie {
protected:    
    static int idNo;      // Zmienna klasowa, numer kolejnego zdarzenia
    int czas;             // Kiedy ma nastąpić zdarzenie?
    KolejkaZdarzen& kol;  // W jakiej jestem kolejce?
    int id;            // Identyfikator zdarzenia, tylko na potrzeby przykładu. Wystarczyłby też typ int.
public:
    // API
    virtual void zajdz() const = 0;             // Niech to zdarzenie zajdzie
    virtual int dajCzas() const;            // Daje czas zdarzenia
    virtual int dajId() const;           // Daje identyfikator zdarzenia
    virtual string to_stringImpl() const;   // Postać tekstowa obiektu, przydatna szczególnie przy debugowaniu. Zwykle używa się nazwy to_string().
    //techniczne
    Zdarzenie(int, KolejkaZdarzen&);            // Konstruktor główny
    Zdarzenie()                               = delete;  // Zdarzenia wymagają danych, konstr. bezarg. to nie dla nich!
    Zdarzenie(const Zdarzenie&)               = delete;  // Nie chcemy kopiować zdarzeń
    Zdarzenie& operator=(const Zdarzenie&)    = delete;  // P. wyżej/
    virtual ~Zdarzenie()                      = default; // Ta deklaracja jest konieczna zwn virtual!
    // bardzo techniczne
    Zdarzenie(Zdarzenie&&)                    = delete;  // Nie omawialiśmy
    Zdarzenie& operator=(Zdarzenie&&)         = delete;  // Nie omawialiśmy
    friend ostream& operator<<(ostream& o, const Zdarzenie& z);
};

#endif	/* ZDARZENIE_H */

