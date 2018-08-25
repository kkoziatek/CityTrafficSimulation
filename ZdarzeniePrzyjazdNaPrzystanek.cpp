/* 
 * File:   ZdarzeniePrzyjazdNaPrzystanek.cpp
 * Author: Komputer
 * 
 * Created on 11 luty 2017, 10:31
 */

#include "ZdarzeniePrzyjazdNaPrzystanek.h"

//--- Zaślepka: potrzebna tylko dla MinGW pod Windows zwn na błąd w tamtej implementacji ------------------
template <typename T> string to_string(const T& n) {
    ostringstream stm;
    stm << n;
    return stm.str();
}
//--- Koniec zaślepki ----------------------------------


ZdarzeniePrzyjazdNaPrzystanek::ZdarzeniePrzyjazdNaPrzystanek(int czas, KolejkaZdarzen& kol, Tramwaj* ktozgl, Przystanek* P, int nr): Zdarzenie(czas, kol),
        tramwaj(ktozgl), przystanek(P), nrLinii(nr)
{
}


void ZdarzeniePrzyjazdNaPrzystanek::zajdz() const 
{
    (*tramwaj).przyjazdNaPrzystanek(przystanek, czas);
}

string ZdarzeniePrzyjazdNaPrzystanek::to_stringImpl() const {
    return ::to_string(czas) + ": Zdarzenie przyjazd na przystanek tramwaju linii nr " + ::to_string(nrLinii) + " o numerze " + ::to_string((*tramwaj).dajNrTram()) + " na przystanek " + ::to_string((*przystanek).dajMiejsce()->dajNazwe());
    //return "Zdarzenie[this=" + ::to_string(this) + ": id=" + id + ", czas=" + ::to_string(czas) + ", kto=" + ::to_string(&kto) + ", kol=" + ::to_string(&kol) + "]";
}


ostream& operator<<(ostream& o, const ZdarzeniePrzyjazdNaPrzystanek& z)
{
    o << z.to_stringImpl();
    return o;  
}

