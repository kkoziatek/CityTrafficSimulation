/* 
 * File:   Zadanie.h
 * Author: Komputer
 *
 * Created on 14 luty 2017, 21:48
 */

#ifndef ZADANIE_H
#define	ZADANIE_H

#include "Miejsce.h"
#include "Zdarzenie.h"

class Zadanie {
public:
    Zadanie() = default;
    Zadanie(const Zadanie& Z) = default;
    virtual ~Zadanie() = default;
    
    //API
    virtual void zajdz(int czas, Miejsce* tutajJestem) = 0;
private:

};

#endif	/* ZADANIE_H */

