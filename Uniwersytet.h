/* 
 * File:   Uniwersytet.h
 * Author: Komputer
 *
 * Created on 16 luty 2017, 09:13
 */

#ifndef UNIWERSYTET_H
#define	UNIWERSYTET_H


#include <iostream>
#include <string>

#include "Miejsce.h"

using namespace std;

class Uniwersytet {
    int nr;
    Miejsce* miejsce;
    string nazwa;
    
public:
    Uniwersytet();
    Uniwersytet(int n, Miejsce* miej, string nazw);
    Uniwersytet(const Uniwersytet& U) = default;
    virtual ~Uniwersytet() = default;
    
    //API
    string dajNazwe();
    Miejsce* dajMiejsce();
};

#endif	/* UNIWERSYTET_H */

