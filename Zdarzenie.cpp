/* 
 * File:   Zdarzenie.cpp
 * Author: Komputer
 * 
 * Created on 10 luty 2017, 19:46
 */

#include "Zdarzenie.h"

//--- Zaślepka: potrzebna tylko dla MinGW pod Windows zwn na błąd w tamtej implementacji ------------------
template <typename T> string to_string(const T& n) {
    ostringstream stm;
    stm << n;
    return stm.str();
}
//--- Koniec zaślepki ----------------------------------

Zdarzenie::Zdarzenie(int czas, KolejkaZdarzen& kol)
: czas(czas), kol(kol), id(idNo) {
    idNo++;
}

int Zdarzenie::dajCzas() const {
    return czas;
}

int Zdarzenie::dajId() const {
    return id;
}

string Zdarzenie::to_stringImpl() const {
    return "Zdarzenie ogolne";
  //  return "Zdarzenie[this=" + ::to_string(this) + ": id=" + id + ", czas=" + ::to_string(czas) + ", kol=" + ::to_string(&kol) + "]";
}

ostream& operator<<(ostream& o, const Zdarzenie& z)
{
    o << z.to_stringImpl();
    return o;  
}
