/* 
 * File:   ZdarzenieOdjazd.cpp
 * Author: Komputer
 * 
 * Created on 12 luty 2017, 11:30
 */

#include "ZdarzenieOdjazd.h"

//--- Zaślepka: potrzebna tylko dla MinGW pod Windows zwn na błąd w tamtej implementacji ------------------
template <typename T> string to_string(const T& n) {
    ostringstream stm;
    stm << n;
    return stm.str();
}
//--- Koniec zaślepki ----------------------------------


ZdarzenieOdjazd::ZdarzenieOdjazd(int czas, KolejkaZdarzen& kol, Tramwaj* ktozgl, Przystanek* P, int nr): Zdarzenie(czas, kol),
        tramwaj(ktozgl), przystanek(P), nrLinii(nr)
{
}


void ZdarzenieOdjazd::zajdz() const 
{
    (*tramwaj).odjazd(czas);
}

string ZdarzenieOdjazd::to_stringImpl() const {
    return ::to_string(czas) + ": Zdarzenie odjazd tramwaju linii nr " + ::to_string(nrLinii) + " o numerze " + ::to_string((*tramwaj).dajNrTram()) + " z przystanku " + ::to_string((*przystanek).dajMiejsce()->dajNazwe());
    //return "Zdarzenie[this=" + ::to_string(this) + ": id=" + id + ", czas=" + ::to_string(czas) + ", kto=" + ::to_string(&kto) + ", kol=" + ::to_string(&kol) + "]";
}


ostream& operator<<(ostream& o, const ZdarzenieOdjazd& z)
{
    o << z.to_stringImpl();
    return o;  
}


