/* 
 * File:   Uniwersytet.cpp
 * Author: Komputer
 * 
 * Created on 16 luty 2017, 09:13
 */

#include "Uniwersytet.h"

Uniwersytet::Uniwersytet() {
}

Uniwersytet::Uniwersytet(int n, Miejsce* miej, string nazw):nr(n), miejsce(miej), nazwa(nazw)
{
    
}

string Uniwersytet::dajNazwe()
{
    return nazwa;
}

Miejsce* Uniwersytet::dajMiejsce()
{
    return miejsce;
}
