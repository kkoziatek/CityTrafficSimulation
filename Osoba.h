/* 
 * File:   Osoba.h
 * Author: Komputer
 *
 * Created on 12 luty 2017, 18:30
 */

#ifndef OSOBA_H
#define	OSOBA_H

#include <iostream>

#include "Miejsce.h"

#include "Zadanie.h"
#include "ZadaniePodroz.h"
#include "ZadaniePodrozCH.h"
#include "ZadaniePodrozTeatr.h"
#include "ZadanieNic.h"

#include "Teatr.h"
#include "CentrumHandlowe.h"

class Osoba {
protected:
    int id;
    Miejsce* jestemTu;
    Miejsce* mieszkamTu;
    
    miejscezlinia trasaPrzejazdu;
    
    Teatr* konT;
    CentrumHandlowe* konCH;
    
    int nrZ;
    
    vector <Zadanie*> zadanie;
    Spektakl* spektakl;
    
public:
    Osoba();
    Osoba(int, Miejsce*, Miejsce*);
    Osoba(const Osoba& O) = default;
    virtual ~Osoba() = default;
    
    //API
    int dajId();
    virtual string dajKtoJestem() = 0;
    virtual Miejsce* dajMiejscePracy(int dzien) = 0;
    virtual int dajPoczatekPracy(int dzien) = 0;
    virtual int dajDlugoscPracy(int dzien) = 0;
    virtual Miejsce* daj2MiejscePracy(int dzien) = 0;
    
    virtual void dodajMiejscePracy(int dzien, Miejsce* M) = 0;
    virtual void dodajPoczatekPracy(int dzien, int godz) = 0;
    virtual void dodajDlugoscPracy(int dzien, int godz) = 0;
    
    void ustawTrasePrzejazdu(miejscezlinia T);
    Miejsce* dajKolejneMiejsce();
    NrLinii* dajKolejnaLinie();
    void usunPoczTrasy();
    bool czyTrasaPusta();
    void ustawJestemTu(Miejsce* M);
    Miejsce* dajJestemTu();
    void przenies(Miejsce* M); 
    void przeniesBezSpr(Miejsce* M);
    Miejsce* dajMieszkamTu();
    void dodajSpektakl(Spektakl* S);
    Spektakl* dajSpektakl();
    
    void akcjaKonPodr(int czas);
    void akcjaDodajTeatr(Teatr* Tr);
    void akcjaDodajCH(CentrumHandlowe* Centr);
    void akcjaUsunTeatr();
    void akcjaUsunCH();
    
    void dodajZadaniePodroz(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn);
    void dodajZadaniePodrozCH(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn, CentrumHandlowe* Cen);
    void dodajZadaniePodrozTeatr(int dC, KolejkaZdarzen& ko, Miejsce* c, miejscezlinia T, Osoba* O, int nn, Teatr* tr);
    void dodajZadanieNic();
    void usunZadania();
    void ustawNrZ(int n);
    int dajNrZ();
    Zadanie* dajZadanie(int n);
    
private:

};

#endif	/* OSOBA_H */

