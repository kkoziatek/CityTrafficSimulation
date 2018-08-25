/* 
 * File:   ZdarzeniePodroz.cpp
 * Author: Komputer
 * 
 * Created on 14 luty 2017, 14:00
 */

#include "ZdarzeniePodroz.h"
#include "Teatr.h"
#include "CentrumHandlowe.h"

//--- Zaślepka: potrzebna tylko dla MinGW pod Windows zwn na błąd w tamtej implementacji ------------------
template <typename T> string to_string(const T& n) {
    ostringstream stm;
    stm << n;
    return stm.str();
}
//--- Koniec zaślepki ----------------------------------


ZdarzeniePodroz::ZdarzeniePodroz(int czas, KolejkaZdarzen& kol, Miejsce* s, Miejsce* c, miejscezlinia T, Osoba* O, int nn): Zdarzenie(czas, kol),
         start(s), cel(c), trasa(T), osoba(O), nrZ(nn)
{
}


void ZdarzeniePodroz::zajdz() const 
{
    (*osoba).ustawTrasePrzejazdu(trasa);
    (*osoba).ustawNrZ(nrZ);
    if((*start).czyJestTeatr())
    {
        (*((*start).dajTeatr())).usunOsobeBezSpr(osoba);
    }
    if((*start).czyJestCH())
    {
        (*((*start).dajCH())).usunOsobeBezSpr(osoba);
    }
    (*start).usunOsobe(osoba);
    (*((*start).dajPrzystanek())).dodajOsobe(osoba, czas);
    
}

string ZdarzeniePodroz::to_stringImpl() const {
    return ::to_string(czas) + ": Zdarzenie podroz osoby o id: " + ::to_string((*osoba).dajId()) + " z miejsca " + ::to_string(start) + " do miejsca " + ::to_string((*cel).dajNazwe());
    //return "Zdarzenie[this=" + ::to_string(this) + ": id=" + id + ", czas=" + ::to_string(czas) + ", kto=" + ::to_string(&kto) + ", kol=" + ::to_string(&kol) + "]";
}


ostream& operator<<(ostream& o, const ZdarzeniePodroz& z)
{
    o << z.to_stringImpl();
    return o;  
}


