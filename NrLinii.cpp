/* 
 * File:   NrLinii.cpp
 * Author: Komputer
 * 
 * Created on 4 luty 2017, 13:19
 */

#include "NrLinii.h"

NrLinii::NrLinii() 
{
    
}

NrLinii::NrLinii(int nnr, Miejsce* zaj1, Miejsce* zaj2, int liczP, int liczT, int liczTW, KolejkaZdarzen* kol)
{
    nr = nnr;
    zajezdnia1 = zaj1;
    zajezdnia2 = zaj2;
    liczPrzyst = liczP;
    
    liczTram = liczT;
    liczTramWeekend = liczTW;
    
    kolejka = kol;
    
}


void NrLinii::dodajPrzystanek(Przystanek* P)
{
    przyst.push_back(P);
}

void NrLinii::dodajCzasPrzejazdu(int t)
{
    czasPrzejazdu.push_back(t);
}

int NrLinii::dajLiczbeTramwajow()
{
    return(liczTram);
}

Tramwaj* NrLinii::dajTramwaj(int nrTram)
{
    return(tramwaj[nrTram]);
}

int NrLinii::dajLiczbePrzystankow()
{
    return liczPrzyst;
}

Przystanek* NrLinii::dajPrzystanek(int nrPrzyst)
{
    return(przyst[nrPrzyst]);
}

void NrLinii::dodajTramwaj(Tramwaj* T)
{
    tramwaj.push_back(T);
}

Miejsce* NrLinii::innaZajezdniaNizTa(Miejsce* zaj)
{
    if(zaj == zajezdnia1)
    {
        return zajezdnia2;
    }
    if(zaj == zajezdnia2)
    {
        return zajezdnia1;
    }
    
    cout << "Blad, nie ma takiej zajezdni:" << (*zaj).dajNazwe();
    return nullptr;
}

int NrLinii::dajNr()
{
    return nr;
}

Miejsce* NrLinii::dajKolejneMiejsce(Miejsce* teraz, Miejsce* zajezdnia)
{
    if(zajezdnia == zajezdnia2)
    {
        for (int i = 0; i < liczPrzyst; i++)
        {
            if((*przyst[i]).dajMiejsce() == teraz)
            {
                if(i + 1 >= liczPrzyst)
                {
                    cout << "Blad ! [NrLinii::dajKolejneMiejsce] : Wyszlismy za tablice przystankow" << endl;
                    return nullptr;
                }
                return (*przyst[i + 1]).dajMiejsce();
            }
        }
    }
    if(zajezdnia == zajezdnia1)
    {
        for (int i = 0; i < liczPrzyst; i++)
        {
            if((*przyst[i]).dajMiejsce() == teraz)
            {
                if(i - 1 < 0)
                {
                    cout << "Blad ! [NrLinii::dajKolejneMiejsce] : Wyszlismy za tablice przystankow" << endl;
                    return nullptr;
                }
                return (*przyst[i - 1]).dajMiejsce();
            }
        }
    }
    cout << "Blad ! [NrLinii::dajKolejneMiejsce] : Nie ma zajezdni o adresie:" << zajezdnia << endl;
    return nullptr;
}

void NrLinii::ustawTramwaje()
{
    for(int i = 0; i < liczTram; i++)
    {
        (*tramwaj[i]).wyrzucLudzi();
    }
    
    int liczba1, liczba2;
    if(liczTram % 2 == 0)
    {
        liczba1 = liczTram / 2;
        liczba2 = liczTram / 2;
    }
    else
    {
        liczba1 = (liczTram / 2) + 1;
        liczba2 = liczTram / 2;
    }
    for (int i = 0; i < liczba1; i++)
    {
        (*tramwaj[i]).ustawMiejsce(zajezdnia1);
        (*tramwaj[i]).ustawZajezdniaJadeTam(zajezdnia2);       
    }
    
    for (int i = liczba1; i < liczTram; i++)
    {
        (*tramwaj[i]).ustawMiejsce(zajezdnia2);
        (*tramwaj[i]).ustawZajezdniaJadeTam(zajezdnia1);       
    }
}

void NrLinii::ustawTramwajeWeekend()
{
    for(int i = 0; i < liczTram; i++)
    {
        (*tramwaj[i]).wyrzucLudzi();
    }
    
    int liczba1, liczba2;
    if(liczTramWeekend % 2 == 0)
    {
        liczba1 = liczTramWeekend / 2;
        liczba2 = liczTramWeekend / 2;
    }
    else
    {
        liczba1 = (liczTramWeekend / 2) + 1;
        liczba2 = liczTramWeekend / 2;
    }
    for (int i = 0; i < liczba1; i++)
    {
        (*tramwaj[i]).ustawMiejsce(zajezdnia1);
        (*tramwaj[i]).ustawZajezdniaJadeTam(zajezdnia2);       
    }
    
    for (int i = liczba1; i < liczTramWeekend; i++)
    {
        (*tramwaj[i]).ustawMiejsce(zajezdnia2);
        (*tramwaj[i]).ustawZajezdniaJadeTam(zajezdnia1);       
    }
}

void NrLinii::przejazdTamPowrot(int start, int koniec, Miejsce* zajezdniaStart, Tramwaj* T)
{
    int czas;
    czas = start;
    if(zajezdniaStart == zajezdnia1)
    {
        for (int i = 0; i < liczPrzyst - 1; i++)
        {
            if (czas < koniec)
            {
                (*kolejka).wstaw(new ZdarzenieOdjazd(czas, *kolejka, T, przyst[i], nr));
            }
            czas += czasPrzejazdu[i];
            if (czas < koniec)
            {
                (*kolejka).wstaw(new ZdarzeniePrzyjazdNaPrzystanek(czas, *kolejka, T, przyst[i + 1], nr));
            }
        }
        czas +=  czasPrzejazdu[liczPrzyst - 1];
        for (int i = liczPrzyst - 1; i > 0; i--)
        {
            if (czas < koniec)
            {
                (*kolejka).wstaw(new ZdarzenieOdjazd(czas, *kolejka, T, przyst[i], nr));
            }
            czas += czasPrzejazdu[i - 1];
            if (czas < koniec)
            {
                (*kolejka).wstaw(new ZdarzeniePrzyjazdNaPrzystanek(czas, *kolejka, T, przyst[i - 1], nr));
            }            
        }      
    }
    else
    {
        if(zajezdniaStart == zajezdnia2)
        {
            for (int i = liczPrzyst - 1; i > 0; i--)
            {
                if (czas < koniec)
                {
                    (*kolejka).wstaw(new ZdarzenieOdjazd(czas, *kolejka, T, przyst[i], nr));
                }
                czas += czasPrzejazdu[i - 1];
                if (czas < koniec)
                {
                    (*kolejka).wstaw(new ZdarzeniePrzyjazdNaPrzystanek(czas, *kolejka, T, przyst[i - 1], nr));
                }
            } 
            czas +=  czasPrzejazdu[liczPrzyst - 1];
            for(int i = 0; i < liczPrzyst - 1; i++)
            {
                if (czas < koniec)
                {
                    (*kolejka).wstaw(new ZdarzenieOdjazd(czas, *kolejka, T, przyst[i], nr));
                }
                czas += czasPrzejazdu[i];
                if (czas < koniec)
                {
                    (*kolejka).wstaw(new ZdarzeniePrzyjazdNaPrzystanek(czas, *kolejka, T, przyst[i + 1], nr));
                }
            }      
        }
        else 
        {
            cout << "Blad ! : [NrLinii::przejazdTamPowrot] : Nie ma zajezdni o adresie: " << zajezdniaStart << endl;
        }
    }
}

int NrLinii::dajCzasPolCyklu()
{
    int suma = 0;
    for(int i = 0; i < liczPrzyst; i++)
    {
        suma += czasPrzejazdu[i];
    }
    return suma;
}

void NrLinii::wyruszamy(int start, int koniec)
{
    int liczba1, liczba2;
    if(liczTram % 2 == 0)
    {
        liczba1 = liczTram / 2;
        liczba2 = liczTram / 2;
    }
    else
    {
        liczba1 = (liczTram / 2) + 1;
        liczba2 = liczTram / 2;
    }
    
    int czas = start;
    int czasPolCyklu = dajCzasPolCyklu();
    while(czas < koniec)
    {
        for(int i = 0; i < liczba1; i++)
        {
            przejazdTamPowrot(czas + (i * czasPolCyklu)/liczba1, koniec, zajezdnia1, tramwaj[i]);
        }
        for(int i = 0; i < liczba2; i++)
        {
            przejazdTamPowrot(czas + (i * czasPolCyklu)/liczba2, koniec, zajezdnia2, tramwaj[liczba1 + i]);
        }
        czas += 2 * czasPolCyklu;
    }
    
}

void NrLinii::wyruszamyWeekend(int start, int koniec)
{
    int liczba1, liczba2;
    if(liczTramWeekend % 2 == 0)
    {
        liczba1 = liczTramWeekend / 2;
        liczba2 = liczTramWeekend / 2;
    }
    else
    {
        liczba1 = (liczTramWeekend / 2) + 1;
        liczba2 = liczTramWeekend / 2;
    }
    
    int czas = start;
    int czasPolCyklu = dajCzasPolCyklu();
    while(czas < koniec)
    {
        for(int i = 0; i < liczba1; i++)
        {
            przejazdTamPowrot(czas + (i * czasPolCyklu)/liczba1, koniec, zajezdnia1, tramwaj[i]);
        }
        for(int i = 0; i < liczba2; i++)
        {
            przejazdTamPowrot(czas + (i * czasPolCyklu)/liczba2, koniec, zajezdnia2, tramwaj[liczba1 + i]);
        }
        czas += 2 * czasPolCyklu;
    }
   

}
void NrLinii::zniszczTramwaje()
{
    for(int i = 0; i < liczTram; i++)
    {
        delete tramwaj[i];
    }
}

int NrLinii::czasPrzej(Przystanek* P1, Przystanek* P2)
{
    for(int i = 0; i < liczPrzyst; i++)
    {
        if(P1 == przyst[i])
        {
            if((i < liczPrzyst) && (P2 == przyst[i + 1]))
            {
                return czasPrzejazdu[i];
            }
            cout << "Blad ! : [NrLinii::czasPrzejazdu] : Nie ma obok siebie przystankow o adresach: " << P1 << ", " << P2 << endl;
            return -1;
        }
        if(P2 == przyst[i])
        {
            if((i < liczPrzyst) && (P1 == przyst[i + 1]))
            {
                return czasPrzejazdu[i];
            }
            cout << "Blad ! : [NrLinii::czasPrzejazdu] : Nie ma obok siebie przystankow o adresach: " << P1 << ", " << P2 << endl;
            return -1;
        }
    }
    cout << "Blad ! : [NrLinii::czasPrzejazdu] : Nie ma obok siebie przystankow o adresach: " << P1 << ", " << P2 << endl;
    return -1;
}

ostream& operator<<(ostream& o, const NrLinii& NL)
{
    o << "Liczba tramwajow: " << NL.liczTram << endl;
    o << "Przystanki z czasami dojazdu: " << endl;
    for(int i = 0; i < NL.liczPrzyst; i++)
    {
        cout << (*((*(NL.przyst[i])).dajMiejsce())).dajNazwe() << " " <<  NL.czasPrzejazdu[i] << endl;
    }
    return o;  
}