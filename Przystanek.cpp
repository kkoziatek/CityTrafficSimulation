/* 
 * File:   Przystanek.cpp
 * Author: Komputer
 * 
 * Created on 3 luty 2017, 19:27
 */

#include "Przystanek.h"
#include "Tramwaj.h"
#include "NrLinii.h"
#include "Osoba.h"
#include "Zadanie.h"

Przystanek::Przystanek() {
    liczPrzystObok = 0;
}

Przystanek::Przystanek(Miejsce* M)
{
    miejsce = M;
    liczPrzystObok = 0;
}

Miejsce* Przystanek::dajMiejsce() const
{
    return miejsce;
}

void Przystanek::dodajPrzystObok(Przystanek* P, NrLinii* nL)
{
    int i;
    for(i = 0; i < przystObok.size(); i++)
    {
        if(przystObok[i].przyst == P)
        {
            przystObok[i].nrL.push_back(nL);
            
            if((*przystObok[i].nrL[0]).czasPrzej(this, P) > (*przystObok[i].nrL[przystObok[i].nrL.size() - 1]).czasPrzej(this, P))
            {
                NrLinii* tym;
                tym = przystObok[i].nrL[0];
                przystObok[i].nrL[0] = przystObok[i].nrL[przystObok[i].nrL.size() - 1];
                przystObok[i].nrL[przystObok[i].nrL.size() - 1] = tym;
            }
            
            break;
        }
    }
    if (i == przystObok.size())
    {
        obok o;
        o.przyst = P;
        o.nrL.push_back(nL);
        przystObok.push_back(o);
        
        liczPrzystObok++;
    }
}

int Przystanek::dajLiczPrzystObok()
{
    return liczPrzystObok;
}
    
int Przystanek::dajLiczLiniiDoPrzyst(Przystanek* P)
{
    int i;
    for(i = 0; i < przystObok.size(); i++)
    {
        if(przystObok[i].przyst == P)
        {
            return(przystObok[i].nrL.size());
        }
    }
    
    return(-1); //brak takiego sasiedniego przystanku
}


Przystanek* Przystanek::dajPrzystObok(int n)
{
    return(przystObok[n].przyst);
}

int Przystanek::dajNrLiniiDoPrzyst(int n, int m)
{
    return((*przystObok[n].nrL[m]).dajNr());
}

NrLinii* Przystanek::dajLinieDoPrzyst(int n, int m)
{
    return przystObok[n].nrL[m];
}

ostream& operator<<(ostream& o, const Przystanek& P)
{
    o << (*(P.dajMiejsce())).dajNazwe();
    return o;  
}

void Przystanek::dodajTramwaj(Tramwaj* T)
{
    tramwaj.push_back(T);
}

void Przystanek::usunTramwaj(Tramwaj* T)
{
    int i;
    bool ok = 0;
    for(i = 0; i < tramwaj.size(); i++)
    {
        if(tramwaj[i] == T)
        {
            tramwaj.erase(tramwaj.begin() + i);
            ok = 1;
            break;
        }
    }
    if (ok == 0)
    {
        // to znaczy, ze tramwaju o adresie T nie ma na zadnym przystanku
        //cout << "Brakuje: nr linii: " << (*(*T).dajLinie()).dajNr() << " nr tram:" << (*T).dajNrTram() << endl;
    }
}

int Przystanek::dajLiczbeTramwajow()
{
    return tramwaj.size();
}

void Przystanek::dodajOsobe(Osoba* O, int czas)
{
    int czasDzien = czas / (24 * 60);
    int czasGodzina = czas / 60 - czasDzien * 24;
    int czasMinuta = czas % 60;
    
    cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta << " : Osoba o id: " << (*O).dajId() << " typu: " << (*O).dajKtoJestem() << " jest na przystanku: " << (*miejsce) << endl << endl;
    if((*O).czyTrasaPusta())
    {
        (*O).ustawJestemTu(miejsce);
        (*miejsce).dodajOsobe(O);
        cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta <<" : Osoba o id: " << (*O).dajId() << " typu: " << (*O).dajKtoJestem() << " dojechala do: " << (*miejsce) << endl << endl;
        (*O).akcjaKonPodr(czas);
        (*((*O).dajZadanie((*O).dajNrZ()))).zajdz(czas, miejsce);
    }
    else
    {
        osoba.push_back(O);
    }
}

int Przystanek::dajLiczbeOsob()
{
    return osoba.size();
}

Osoba* Przystanek::dajOsobe(int n)
{
    return osoba[n];
}

void Przystanek::usunOsobe(int n)
{
    if(n < osoba.size())
    {
        osoba.erase(osoba.begin() + n);
    }
    else
    {
        cout << "Blad ! : [Przystanek::usunOsobe] : Nie ma osoby o numerze: " << n << " na przystanku. Jest tylko: " << osoba.size() << " osob." << endl;
    }
}

void Przystanek::wyrzucLudzi()
{
    osoba.clear();
}