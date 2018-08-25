/* 
 * File:   Tramwaj.cpp
 * Author: Komputer
 * 
 * Created on 4 luty 2017, 13:06
 */

#include "Tramwaj.h"
#include "NrLinii.h"
#include "Osoba.h"

Tramwaj::Tramwaj() {
}

Tramwaj::Tramwaj(Miejsce* miej, Miejsce* zaj, int nrL, int nrT, int poj)
{
    miejsce = miej;
    zajezdniaJadeTam = zaj;
    nrLinii = nrL;
    nrTram = nrT;
    pojemnosc = poj;
}

Miejsce* Tramwaj::dajMiejsce()
{
    return miejsce;
}

Miejsce* Tramwaj::dajZajezdniaJadeTam()
{
    return zajezdniaJadeTam;
}

void Tramwaj::dodajLinie(NrLinii* NL)
{
    linia = NL;
}

NrLinii* Tramwaj::dajLinie()
{
    return linia;
}

int Tramwaj::dajNrTram()
{
    return(nrTram);
}


void Tramwaj::przyjazdNaPrzystanek(Przystanek* P, int czas)
{
    int czasDzien = czas / (24 * 60);
    int czasGodzina = czas / 60 - czasDzien * 24;
    int czasMinuta = czas % 60;
    
    miejsce = (*P).dajMiejsce();
    (*(*miejsce).dajPrzystanek()).dodajTramwaj(this);
    
    cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta << " : Zdarzenie przyjazd na przystanek tramwaju linii nr " << nrLinii << " o numerze " << nrTram << " na przystanek " << *miejsce << endl << endl;
    
    bool toZajezdnia = 0;
    if(miejsce == zajezdniaJadeTam)
    {        
        Miejsce* nowZaj = (*linia).innaZajezdniaNizTa(zajezdniaJadeTam);
        zajezdniaJadeTam = nowZaj;
        toZajezdnia = 1;
    }
    
    
    for(int i = 0; i < osoba.size(); i++)
    {
        (*osoba[i]).usunPoczTrasy();
        (*osoba[i]).ustawJestemTu(miejsce);
    }
    
    Miejsce* MT = (*linia).dajKolejneMiejsce(miejsce, zajezdniaJadeTam);
    for(int i = 0; i < osoba.size(); i++)
    {
        Miejsce* M = (*osoba[i]).dajKolejneMiejsce();
        NrLinii* NL = (*osoba[i]).dajKolejnaLinie();
        
        //wysiadanie
        if(toZajezdnia)
        {
            cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta << " : Osoba o id: " << (*osoba[i]).dajId() << " typu: " << (*osoba[i]).dajKtoJestem() << " wysiadla z tramwaju o nr. linii: " << nrLinii << " o numerze " << nrTram << " na przystanku " <<(*miejsce) << endl << endl;
            (*(*miejsce).dajPrzystanek()).dodajOsobe(osoba[i], czas);
            usunOsobe(i);
            i--;
        }
        else 
        {
            if(!((M == MT) && (NL == linia)))
            {
                cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta << " : Osoba o id: " << (*osoba[i]).dajId() << " typu: " << (*osoba[i]).dajKtoJestem() << " wysiadla z tramwaju o nr. linii: " << nrLinii << " o numerze " << nrTram << " na przystanku " <<(*miejsce) << endl << endl;
                (*(*miejsce).dajPrzystanek()).dodajOsobe(osoba[i], czas);
                usunOsobe(i);
                i--;
            }
        }
        
    }
    
}

void Tramwaj::odjazd(int czas)
{
    int czasDzien = czas / (24 * 60);
    int czasGodzina = czas / 60 - czasDzien * 24;
    int czasMinuta = czas % 60;
    
    Przystanek* P = (*miejsce).dajPrzystanek();
    Miejsce* MT = (*linia).dajKolejneMiejsce(miejsce, zajezdniaJadeTam);
    
    //wsiadanie
    int k = 0;
    while ((osoba.size() < pojemnosc) && (k < (*P).dajLiczbeOsob()))
    {
        
        Miejsce* M = (*((*P).dajOsobe(k))).dajKolejneMiejsce();
        NrLinii* NL = (*((*P).dajOsobe(k))).dajKolejnaLinie();
        
        if((M == MT) && (NL == linia))
        {
            cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta << " : Osoba o id: " << (*((*P).dajOsobe(k))).dajId() << " typu: " << (*((*P).dajOsobe(k))).dajKtoJestem() << " wsiadla do tramwaju o nr. linii: " << nrLinii << " o numerze " << nrTram << " na przystanku " <<(*miejsce) << endl << endl;
            dodajOsobe((*P).dajOsobe(k));
            (*P).usunOsobe(k);
            
        
            // nie powiekszamy k, bo usunelismy k-ta osobe z przystanku, w jej miejsce weszla k+1-sza
        }
        else
        {
            k++;
        }
    }
    cout << czasDzien << ": " << czasGodzina << ":" << czasMinuta << " : Zdarzenie odjazd tramwaju linii nr " << nrLinii << " o numerze " << nrTram << " z przystanku " << *miejsce << endl << endl;
    (*(*miejsce).dajPrzystanek()).usunTramwaj(this);

}

void Tramwaj::ustawMiejsce(Miejsce* M)
{
    (*(*miejsce).dajPrzystanek()).usunTramwaj(this);
    miejsce = M;
    (*(*miejsce).dajPrzystanek()).dodajTramwaj(this);
}

void Tramwaj::ustawZajezdniaJadeTam(Miejsce* Z)
{
    zajezdniaJadeTam = Z;
}

void Tramwaj::dodajOsobe(Osoba* O)
{
    osoba.push_back(O);
}

void Tramwaj::usunOsobe(int ktora)
{
    if(ktora >= osoba.size())
    {
        cout << "Blad ! : [Tramwaj::usunOsobe] : Nie ma osoby o nr. " << ktora << " Jest tylko " << osoba.size() << " osob." << endl;
    }
    else
    {
        osoba.erase(osoba.begin() + ktora);
    }
}

void Tramwaj::wyrzucLudzi()
{
    osoba.clear();
}