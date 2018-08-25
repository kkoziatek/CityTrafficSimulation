/* 
 * File:   ZdarzenieKonkretne.cpp
 * Author: Komputer
 * 
 * Created on 10 luty 2017, 19:52
 */

#include "ZdarzenieKonkretne.h"

//--- Zaślepka: potrzebna tylko dla MinGW pod Windows zwn na błąd w tamtej implementacji ------------------
template <typename T> string to_string(const T& n) {
    ostringstream stm;
    stm << n;
    return stm.str();
}
//--- Koniec zaślepki ----------------------------------


ZdarzenieKonkretne::ZdarzenieKonkretne(int czas, KolejkaZdarzen& kol, Obiekt& ktozgl): Zdarzenie(czas, kol), kto(ktozgl)
{
}


void ZdarzenieKonkretne::zajdz() const {
    kto.akcja(kol);
}

string ZdarzenieKonkretne::to_stringImpl() const {
    return ::to_string(czas) + ": ZdarzenieKonkretne na Obiecie";
    //return "Zdarzenie[this=" + ::to_string(this) + ": id=" + id + ", czas=" + ::to_string(czas) + ", kto=" + ::to_string(&kto) + ", kol=" + ::to_string(&kol) + "]";
}


ostream& operator<<(ostream& o, const ZdarzenieKonkretne& z)
{
    o << z.to_stringImpl();
    return o;  
}

