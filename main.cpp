#include <iostream>
#include <queue>       // priority_queue

// Dodatkowe sprawdzania
#include <cassert>     // assert

// Generacja liczb losowych
#include <cstdlib>     // srand, rand
#include <ctime>       // time, uĹĽyty tylko w srand

// ZaĹ›lepka
#include <sstream>     // ostringstream - zaĹ›lepka dla to_string

#include<vector>
#include<math.h>

#include <string>

#include "Miejsce.h"
#include "Przystanek.h"
#include "Tramwaj.h"
#include "NrLinii.h"

#include "Compare.h"
#include "KolejkaZdarzen.h"
#include "Obiekt.h"
#include "Zdarzenie.h"
#include "ZdarzenieKonkretne.h"
#include "ZdarzeniePrzyjazdNaPrzystanek.h"
#include "ZdarzenieOdjazd.h"
#include "ZdarzeniePodroz.h"
#include "ZdarzeniePodrozTeatr.h"
#include "ZdarzeniePodrozCH.h"

#include "CentrumHandlowe.h"
#include "Teatr.h"
#include "Uniwersytet.h"
#include "Spektakl.h"

#include "Osoba.h"
#include "Uczen.h"
#include "Artysta.h"
#include "Pracownik.h"
#include "Student.h"


using namespace std;

int Zdarzenie::idNo=0;    // Zmienna klasowa z Zdarzenie


// ------------------- deklaracja zmiennych globalnych ------------------------------

int liczbaDniSymulacji;
int liczPrac, liczStud, liczArt, liczUcz;
double prawdWyjazd; // prawd. wyjazdu pracujacego w ciagu dnia
double prawdZakupowTyg;  // prawd. dla osoby zakupĂłw w tygodniu
int procStud2;  // procent studentow z 2-ma miejscami studiow
int procZmnTramWeekend;  //procent zmniejszenia tramwajow w weekend
double prawdTeatrP, prawdTeatrS, prawdTeatrA, prawdTeatrU;

int liczbaMiejsc;
vector <Miejsce*> miejsce;
vector <Przystanek*> przystanek;
vector <Tramwaj*> tram;
int liczLiniiTram;
vector <NrLinii*> nrlinii;
vector <Osoba*> uczen;
vector <Osoba*> artysta;
vector <Osoba*> pracownik;
vector <Osoba*> student;
int pojTramwaju;
int liczbaTeatrow;
vector <Teatr*> teatr;
int liczbaUniwersytetow;
vector <Uniwersytet*> uniwersytet;
int liczbaCH;
vector <CentrumHandlowe*> centrumhandlowe;


//zmienne pomocnicze
int maksCzasPrzejazdu = 0;  //najbardziej czasochlonny przejazd miedzy dwoma sasiednimi przystankami

int dzienSymulacji;
int miesiacSymulacji;
int tydzienSymulacji;
int dzienMiesiaca;
int dzienTygodnia;

int liczStud2;  // liczba studentow z 2-ma miejscami studiow

// -------------------- funkcje ------------------------------------------

Miejsce* dajMiejsce(string nazwa)
{
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        if((*miejsce[i]).dajNazwe() == nazwa)
        {
            return(miejsce[i]);
        }
    }
    cout << "Blad ! Nie ma takiego miejsca: " << nazwa << endl;

}

Przystanek* dajPrzystanek(string nazwa)
{
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        if((*(*przystanek[i]).dajMiejsce()).dajNazwe() == nazwa)
        {
            return(przystanek[i]);
        }
    }
    cout << "Blad ! Nie ma takiego przystanku: " << nazwa << endl;
}

int ktoryPrzystanek(Przystanek* P)
{
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        if(przystanek[i] == P)
        {
            return i ;
        }
    }
    cout << "Blad ! Nie ma przystanku o adresie: " << P << endl;
}

int ktoreMiejsce(Miejsce* M)
{
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        if(miejsce[i] == M)
        {
            return i ;
        }
    }
    cout << "Blad ! Nie ma miejsca o adresie: " << M << endl;
}

void ustawieniePoczatkowe()
{
    for(int i = 0; i < uczen.size(); i++)
    {
        Miejsce* miejzam = (*uczen[i]).dajMieszkamTu();
        (*uczen[i]).przeniesBezSpr(miejzam);
        (*uczen[i]).akcjaUsunTeatr();
        (*uczen[i]).akcjaUsunCH();
        (*uczen[i]).usunZadania();
    }
    for(int i = 0; i < artysta.size(); i++)
    {
        Miejsce* miejzam = (*artysta[i]).dajMieszkamTu();
        (*artysta[i]).przeniesBezSpr(miejzam);
        (*artysta[i]).akcjaUsunTeatr();
        (*artysta[i]).akcjaUsunCH();
        (*artysta[i]).usunZadania();
    }
    for(int i = 0; i < pracownik.size(); i++)
    {
        Miejsce* miejzam = (*pracownik[i]).dajMieszkamTu();
        (*pracownik[i]).przeniesBezSpr(miejzam);
        (*pracownik[i]).akcjaUsunTeatr();
        (*pracownik[i]).akcjaUsunCH();
        (*pracownik[i]).usunZadania();
    }
    for(int i = 0; i < student.size(); i++)
    {
        Miejsce* miejzam = (*student[i]).dajMieszkamTu();
        (*student[i]).przeniesBezSpr(miejzam);
        (*student[i]).akcjaUsunTeatr();
        (*student[i]).akcjaUsunCH();
        (*student[i]).usunZadania();
    }
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        (*przystanek[i]).wyrzucLudzi();
    }
    
    for(int i = 0; i < liczLiniiTram; i++)
    {
        (*nrlinii[i]).ustawTramwaje();
    }
    
    for(int i = 0; i < liczbaTeatrow; i++)
    {
        (*teatr[i]).wyrzucOsoby();
    }
    
    for(int i = 0; i < liczbaCH; i++)
    {
        (*centrumhandlowe[i]).wyrzucOsoby();
    }
    
}

void ustawieniePoczatkoweWeekend()
{
    for(int i = 0; i < uczen.size(); i++)
    {
        Miejsce* miejzam = (*uczen[i]).dajMieszkamTu();
        (*uczen[i]).przeniesBezSpr(miejzam);
        (*uczen[i]).akcjaUsunTeatr();
        (*uczen[i]).akcjaUsunCH();
        (*uczen[i]).usunZadania();
    }
    for(int i = 0; i < artysta.size(); i++)
    {
        Miejsce* miejzam = (*artysta[i]).dajMieszkamTu();
        (*artysta[i]).przeniesBezSpr(miejzam);
        (*artysta[i]).akcjaUsunTeatr();
        (*artysta[i]).akcjaUsunCH();
        (*artysta[i]).usunZadania();
    }
    for(int i = 0; i < pracownik.size(); i++)
    {
        Miejsce* miejzam = (*pracownik[i]).dajMieszkamTu();
        (*pracownik[i]).przeniesBezSpr(miejzam);
        (*pracownik[i]).akcjaUsunTeatr();
        (*pracownik[i]).akcjaUsunCH();
        (*pracownik[i]).usunZadania();
    }
    for(int i = 0; i < student.size(); i++)
    {
        Miejsce* miejzam = (*student[i]).dajMieszkamTu();
        (*student[i]).przeniesBezSpr(miejzam);
        (*student[i]).akcjaUsunTeatr();
        (*student[i]).akcjaUsunCH();
        (*student[i]).usunZadania();
    }
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        (*przystanek[i]).wyrzucLudzi();
    }
    
    for(int i = 0; i < liczLiniiTram; i++)
    {
        (*nrlinii[i]).ustawTramwajeWeekend();
    }
    
    for(int i = 0; i < liczbaTeatrow; i++)
    {
        (*teatr[i]).wyrzucOsoby();
    }
    
    for(int i = 0; i < liczbaCH; i++)
    {
        (*centrumhandlowe[i]).wyrzucOsoby();
    }
}


int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

bool losowanie(double p)
{
    int k = round(p * 1000);
    int l = rand() % 1000 + 1;
    if(l <= k)
    {
        return 1;
    }
    
    return 0;
    
}

// ------------------- funkcja stan programu ------------------------------

void stanProgramu();

// ---------------- Program gĹ‚Ăłwny -----------------------

int main(int, char**) {
    cout << "Start programu" << endl;
    srand(time(nullptr)); // Inicjuje gen. liczb losowych - przy szukaniu bĹ‚Ä™dĂłw lepiej tÄ™ instrukcjÄ™ wykomentowaÄ‡ (za kaĹĽdym razem bÄ™dzie wtedy ten sam ciÄ…g liczb losowych)

    KolejkaZdarzen* kolejka = new KolejkaZdarzen();

 // ========================================================================

// ------------------- wczytywanie ------------------------------
    
    cin >> liczbaDniSymulacji;
    cin >> liczPrac;
    cin >> liczStud;
    cin >> liczArt;
    cin >> liczUcz;
    cin >> prawdWyjazd;
    cin >> prawdZakupowTyg;
    cin >> procStud2;
    cin >> procZmnTramWeekend;
    cin >> prawdTeatrP >>prawdTeatrS >> prawdTeatrA >> prawdTeatrU;
    cin >> pojTramwaju;
    cin >> liczbaMiejsc;
    
    for (int i = 0; i < liczbaMiejsc; i++)
    {
        string nazwa_miejsca;
        cin >> nazwa_miejsca;
        Miejsce* M = new Miejsce(nazwa_miejsca);
        miejsce.push_back(M);        // dodawanie wsk do miejsc
        
        Przystanek* P = new Przystanek(miejsce[i]);
        przystanek.push_back(P);
        
        (*miejsce[i]).dodajPrzystanek(P);
        
    }
    
    cin >> liczLiniiTram;
    
    
    for(int i = 0; i < liczLiniiTram; i++)
    {
        int liczTram;
        cin >> liczTram;
        
        string wiersz;
        getline(cin, wiersz);
        
        stringstream strWiersz(wiersz);

        string nazwPrzyst;
        int czasPostoju;
        int j = 0;
        vector <string> nazw;
        vector <int> czas;
        while ((strWiersz >> nazwPrzyst) && (strWiersz >> czasPostoju)) 
        {
            nazw.push_back(nazwPrzyst);
            czas.push_back(czasPostoju);
            j++;
        }
       
        double sto = 100;    // zeby udalo sie podzielic z wynikiem zmiennoprzecinkowym ponizej
        double ulamek = procZmnTramWeekend/sto;
        NrLinii* NL = new NrLinii(i, dajMiejsce(nazw[0]), dajMiejsce(nazw[nazw.size() - 1]), nazw.size(), liczTram, round((1 - ulamek) * liczTram), kolejka);
        nrlinii.push_back(NL);
        
        for(int j = 0; j < liczTram; j++)
        {
            Tramwaj* T = new Tramwaj(dajMiejsce(nazw[0]), dajMiejsce(nazw[nazw.size() - 1]), i, j, pojTramwaju);
            tram.push_back(T);
            (*nrlinii[i]).dodajTramwaj(T);
            (*T).dodajLinie(nrlinii[i]);           
            (*(*dajMiejsce(nazw[0])).dajPrzystanek()).dodajTramwaj(T);
        }
        
        
        for(int j = 0; j < nazw.size(); j++)
        {
           
            (*nrlinii[i]).dodajPrzystanek(dajPrzystanek(nazw[j]));
            (*nrlinii[i]).dodajCzasPrzejazdu(czas[j]);
            if ((j < nazw.size() - 1) && (maksCzasPrzejazdu < czas[j]))
            {
                maksCzasPrzejazdu = czas[j];  //aktualizujemy maks. czas. przejazdu miedzy przyst.
            }
        }
        

        // dodawanie sasiadow przystankow
        
        (*((*nrlinii[i]).dajPrzystanek(0))).dodajPrzystObok((*nrlinii[i]).dajPrzystanek(1), nrlinii[i]);
        
        for(int j = 1; j < (*nrlinii[i]).dajLiczbePrzystankow() - 1; j++)
        {
            (*((*nrlinii[i]).dajPrzystanek(j))).dodajPrzystObok((*nrlinii[i]).dajPrzystanek(j - 1), nrlinii[i]);
            (*((*nrlinii[i]).dajPrzystanek(j))).dodajPrzystObok((*nrlinii[i]).dajPrzystanek(j + 1), nrlinii[i]);
        }
        
        (*((*nrlinii[i]).dajPrzystanek((*nrlinii[i]).dajLiczbePrzystankow() - 1))).dodajPrzystObok((*nrlinii[i]).dajPrzystanek((*nrlinii[i]).dajLiczbePrzystankow() - 2), nrlinii[i]);
   
    }

// ----------------- tworzenie teatrow i centr handlowych, i uniwersytetow ------------------------
    
    cin >> liczbaUniwersytetow;
    
    if (liczbaUniwersytetow > liczbaMiejsc)
    {
        cout << "Blad ! Zgodnie z danymi jest wiecej Uniwersytetow(" << liczbaUniwersytetow << ") niz miejsc(" << liczbaMiejsc << ")." << endl;
    }
    
    for(int i = 0; i < liczbaUniwersytetow; i++)
    {
        string nazw;
        string miej;
        cin >> nazw >> miej;
        Miejsce* M = dajMiejsce(miej);
        Uniwersytet* U = new Uniwersytet(i, M, nazw);
        uniwersytet.push_back(U);
        (*M).dodajUniwersytet(U);
    }
    
    cin >> liczbaTeatrow;
    
    for(int i = 0; i < liczbaTeatrow; i++)
    {
        string nazw;
        string miej;
        int liczmiej;
        cin >> nazw >> miej >> liczmiej;
        Miejsce* M = dajMiejsce(miej);
        Teatr* T = new Teatr(i, M, nazw, liczmiej);
        teatr.push_back(T);
        (*M).dodajTeatr(T);
    }
    
    cin >> liczbaCH;
    
    for(int i = 0; i < liczbaCH; i++)
    {
        string nazw;
        string miej;
        cin >> nazw >> miej;
        Miejsce* M = dajMiejsce(miej);
        CentrumHandlowe* CH = new CentrumHandlowe(i, M, nazw);
        centrumhandlowe.push_back(CH);
        (*M).dodajCH(CH);
    }
    
    
// -------------- tworzenie osob ----------------------------------------
    
    for(int i = 0; i < liczUcz; i++)
    {
        int nrDomu = rand() % liczbaMiejsc;
        int nrSzkoly = rand() % liczbaMiejsc;
        Osoba* O = new Uczen(i, miejsce[nrDomu], miejsce[nrDomu], miejsce[nrSzkoly]);   //na poczatku kazdy uczen w swoim domu
        uczen.push_back(O);
        (*miejsce[nrDomu]).dodajOsobe(O);
    }
    for(int i = 0; i < liczArt; i++)
    {
        int nrDomu = rand() % liczbaMiejsc;
        Osoba* O = new Artysta(i + liczUcz, miejsce[nrDomu], miejsce[nrDomu]);   //na poczatku kazdy atysta w swoim domu
        artysta.push_back(O);
        (*miejsce[nrDomu]).dodajOsobe(O);
    }
    for(int i = 0; i < liczPrac; i++)
    {
        int nrDomu = rand() % liczbaMiejsc;
        int nrPracy = rand() % liczbaMiejsc;
        Osoba* O = new Pracownik(i + liczUcz + liczArt, miejsce[nrDomu], miejsce[nrDomu], miejsce[nrPracy]);   //na poczatku kazdy pracownik w swoim domu
        pracownik.push_back(O);
        (*miejsce[nrDomu]).dodajOsobe(O);
    }
    
    liczStud2 = round((1.0 * procStud2 * liczStud) / 100);   // mnozymy przez 1.0, zeby zmienic arg. round na liczbe zmiennoprzecinkowa
    
    for(int i = 0; i < liczStud; i++)
    {
        int nrDomu = rand() % liczbaMiejsc;
        int nrUni1 = rand() % liczbaUniwersytetow;
        Miejsce* uni1 = (*uniwersytet[nrUni1]).dajMiejsce();
        Miejsce* uni2 = nullptr;
        if(i < liczStud2)      
        {
            int nrUni2 = rand() % liczbaUniwersytetow;       // szukamy 2. uniwersytetu
            uni2 = (*uniwersytet[nrUni2]).dajMiejsce();
        }
        Osoba* O = new Student(i, miejsce[nrDomu], miejsce[nrDomu], uni1, uni2);   //na poczatku student w swoim domu
        student.push_back(O);
        (*miejsce[nrDomu]).dodajOsobe(O);
    }
    
// ------- tworzymy tabelke najkrotszych tras miedzy miejscami --------------
    
    
    miejscezlinia** trasa = new miejscezlinia*[liczbaMiejsc];  //trasa[i][j] to tablica z miejscami, w ktorych bedziemy jadac z miejsca i do j
    for (int i = 0; i < liczbaMiejsc; i++)
    {
        trasa[i] = new miejscezlinia[liczbaMiejsc];
    }
    
    
    int nsk = maksCzasPrzejazdu * liczbaMiejsc + 1;// taka nieskonczonosc
    
    for (int i = 0; i < liczbaMiejsc; i++)
    {
        int* sciezkaZrobiona = new int[liczbaMiejsc];
        int liczZrobS = 0; //liczba zrobionych sciezek od i
        
        for (int j = 0; j < liczbaMiejsc; j++)
        {
            sciezkaZrobiona[j] = 0;
            trasa[i][j].odl = nsk; 
        }
        
        trasa[i][i].odl = 0;
        
        
        while(liczZrobS < liczbaMiejsc)
        {
            int minindeks = 0;
            
            //ustawiamy kandydata na minindeks
            for(int j = 0; j < liczbaMiejsc; j++)
            {
                if (sciezkaZrobiona[j] == 0)
                {
                    minindeks = j;
                    break;
                }
            }
            // znajdujemy wierzcholek o najmniejszej odleglosci z tych, ktorym pozostalo do wyznaczenia trasy
            for(int j = 0; j < liczbaMiejsc; j++)
            {
                if((sciezkaZrobiona[j] == 0) && (trasa[i][j].odl < trasa[i][minindeks].odl))
                {
                    minindeks = j;
                }
            }
            sciezkaZrobiona[minindeks] = 1;
            liczZrobS++;
            int lpo = (*przystanek[minindeks]).dajLiczPrzystObok();
            for(int k = 0; k < lpo; k++)
            {
                Przystanek* sasiad = (*przystanek[minindeks]).dajPrzystObok(k);
                NrLinii* nrLinObok = (*przystanek[minindeks]).dajLinieDoPrzyst(k, 0);
                int odlegl = (*nrLinObok).czasPrzej(przystanek[minindeks], sasiad);
                
                int ktory = ktoryPrzystanek(sasiad);
                if((sciezkaZrobiona[ktory] == 0) && (trasa[i][ktory].odl > odlegl + trasa[i][minindeks].odl))
                {
                    trasa[i][ktory].odl = trasa[i][minindeks].odl + odlegl;
                    trasa[i][ktory].dane.clear();
                    trasa[i][ktory].dane = trasa[i][minindeks].dane;
                    mzl nastepny;
                    nastepny.miej = miejsce[ktory];
                    nastepny.nrL = (*przystanek[minindeks]).dajLinieDoPrzyst(k, 0);
                    trasa[i][ktory].dane.push_back(nastepny);    
                }
                
            }
           
            
        }
        
        
        
        delete[] sciezkaZrobiona;
    }
    
  /*  cout << "Tabelka odleglosci: " << endl;
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        for(int j = 0; j < liczbaMiejsc; j++)
        {
            cout << trasa[i][j].odl << " ";
        }
        cout << endl;
    }*/
    
    
    //test trasa - wypisuje trase z miejsca do miejsca
   /* int ii = 0;
    int jj = 1;
    cout << "Trasa z " << (*miejsce[ii]).dajNazwe() << " do " << (*miejsce[jj]).dajNazwe() << endl;
    for (int k = 0; k < trasa[ii][jj].dane.size(); k++)
    {
        cout << "nr" << (*(trasa[ii][jj].dane[k].nrL)).dajNr() << " " << (*(trasa[ii][jj].dane[k].miej)).dajNazwe() << "  ";
    }
    cout << endl;*/
    
// --------------------- Dzieje sie --------------------------------------
   
    ustawieniePoczatkowe();

// ---------------------- Planowanie dni ----------------------------------
    
    for(int i = 0; i < liczUcz; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int dlZaj = rand() % (5 * 60);
            (*uczen[i]).dodajDlugoscPracy(j, dlZaj);
            
           // cout << dlZaj / 60 << " " << dlZaj % 60 << endl;
        }     
       // cout << endl;
    }
    for(int i = 0; i < liczArt; i++)
    {
        int liczMiejscPracy = (rand() % 3) + 1;
        Miejsce* praca[3];
        praca[0] = nullptr;
        praca[1] = nullptr;
        praca[2] = nullptr;
        for(int j = 0; j < liczMiejscPracy; j++)
        {
            int nrMscPracy = rand() % liczbaMiejsc;
            praca[j] = miejsce[nrMscPracy];
        }
        
        for(int j = 0; j < 7; j++)
        {
            int nrPracy = rand() % liczMiejscPracy;
            (*artysta[i]).dodajMiejscePracy(j, praca[nrPracy]);
            int poczPrac = (rand() % (16 * 60)) + 6 * 60;  // losujemy godzine rozpoczecia pracy miedzy 6*60 a 22*60
            (*artysta[i]).dodajPoczatekPracy(j, poczPrac);
            int dlZaj = rand() % (23 * 60 - poczPrac);   // losujemy dlugosc pracy, zeby powrot byl w przedziale [poczPrac, 23 * 60]
            (*artysta[i]).dodajDlugoscPracy(j, dlZaj);
            
         //   cout << nrPracy << *praca[nrPracy] << " " << poczPrac / 60 << " " << poczPrac % 60 << " " << dlZaj / 60 << " " << dlZaj % 60 << endl;
        }     
       // cout << endl;
    }
    
    for(int i = 0; i < liczPrac; i++)
    {
        int poczPracy = (rand() % (4 * 60)) + 6 * 60;
        (*pracownik[i]).dodajPoczatekPracy(0, poczPracy);
       
        //cout << poczPracy / 60 << " " << poczPracy % 60 << endl;     
    }
    
    for(int i = 0; i < liczStud; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int poczZaj = (rand() % (8 * 60)) + 8 * 60;
            int dlMax = min(8 * 60, 20 * 60 - poczZaj - 2 * 60);   // przedzial, z jakiego losujemy dlugosc zajec, zeby ani nie przekroczyc 10 godzin nauki, ani godziny 20:00
            int dlZaj = (rand() % dlMax) + 2 * 60;
            (*student[i]).dodajPoczatekPracy(j, poczZaj);
            (*student[i]).dodajDlugoscPracy(j, dlZaj);
            
            //cout << poczZaj / 60 << " " << poczZaj % 60 << " " << dlZaj / 60 << " " << dlZaj % 60 << endl;
        }     
        //cout << endl;
    }
    
    
// ------------------------ petla zycia ---------------------------------
    dzienSymulacji = -1;
    miesiacSymulacji = -1;
    tydzienSymulacji = -1;
    dzienMiesiaca =  -1;
    dzienTygodnia = -1;
    
    int czasPoczDnia = 0;
    while(dzienSymulacji < liczbaDniSymulacji - 1)
    {
        dzienSymulacji++;
        dzienMiesiaca++;
        dzienTygodnia++;
        czasPoczDnia = dzienSymulacji * 24 * 60;
        
        if(dzienMiesiaca % 30 == 0) // nowy miesiac
        {
            miesiacSymulacji++;
            dzienMiesiaca = 0;
            
            int dzTyg = dzienTygodnia % 7;
            
            for(int i = 0; i < liczbaTeatrow; i++)
            {
                (*teatr[i]).odnowSpektakle(dzienSymulacji, dzTyg);
            }            
            
            for(int i = 0; i < liczUcz; i++)
            {
                if(losowanie(prawdTeatrU))
                {
                    int nrTeatr = rand() % liczbaTeatrow;
                    (*teatr[nrTeatr]).zapiszOsobe(uczen[i]);
                    
                    if((*uczen[i]).dajSpektakl() != nullptr)
                    {
                       // cout << (*(*uczen[i]).dajSpektakl()) << endl;
                    }
                    
                }
                
            }
            
            cout << endl << endl;
            cout << "Miesiac nr " << miesiacSymulacji << endl << endl << endl << endl;
        }
        
        if(dzienTygodnia % 7 == 0) // nowy tydzien
        {
            tydzienSymulacji++;
            dzienTygodnia = 0;
            
            cout << endl;
            cout << "Tydzien nr " << tydzienSymulacji << endl << endl << endl;
        }
        
        cout << "Dzien symulacji: " << dzienSymulacji << ". Dzien miesiaca: " << dzienMiesiaca << ". Dzien tygodnia: " << dzienTygodnia  << "." << endl << endl; 
        
        if((0 <= dzienTygodnia) &&( dzienTygodnia <= 4))  // dni robocze
        {
            ustawieniePoczatkowe();
            
            // uczniowie
            for (int i = 0; i < liczUcz; i++)
            {
                Miejsce* tujes = (*uczen[i]).dajJestemTu();
                Miejsce* szkol = (*uczen[i]).dajMiejscePracy(dzienTygodnia);
                int dlugZajec = (*uczen[i]).dajDlugoscPracy(dzienTygodnia);
                int h = ktoreMiejsce(tujes);
                int c = ktoreMiejsce(szkol);
                miejscezlinia T = trasa[h][c];
                int wyruszWczesniej = trasa[h][c].odl + 10;
                if(wyruszWczesniej > (8 - 6) * 60)
                {
                        cout << "Upsss ! Uczen o id: " << (*uczen[i]).dajId() << " moze spoznic sie na zajecia." << endl;
                }
            
                // do szkoly
                (*kolejka).wstaw(new ZdarzeniePodroz(czasPoczDnia + 8 * 60 - wyruszWczesniej, *kolejka, tujes, szkol, T, uczen[i], 0));
            
                Spektakl* spek = (*uczen[i]).dajSpektakl();
                if((spek != nullptr) && ((*spek).dajDzienSym() == dzienSymulacji))
                {
                    Miejsce* tenTeatr = (*spek).dajMiejsce();
                    Teatr* tT = (*tenTeatr).dajTeatr();
                    int dlugSpek = (*spek).dajDlugSpek();
                    int d = ktoreMiejsce(tenTeatr);
                    miejscezlinia T2 = trasa[c][d];
                    int godz = (*spek).dajGodz();
                    // do teatru
                    (*uczen[i]).dodajZadaniePodrozTeatr(dlugZajec, *kolejka, tenTeatr, T2, uczen[i], 1, tT);
                    
                    // powrot
                    miejscezlinia T3 = trasa[d][h];
                    (*uczen[i]).dodajZadaniePodroz(godz + dlugSpek - (8 * 60 + dlugZajec + trasa[c][d].odl), *kolejka, miejsce[h], T3, uczen[i], 2);
                    (*uczen[i]).dodajZadanieNic(); 
                    
                }
                else
                {
                    // powrot
                    T = trasa[c][h];
                    (*uczen[i]).dodajZadaniePodroz(dlugZajec, *kolejka, miejsce[h], T, uczen[i], 1);
                    (*uczen[i]).dodajZadanieNic(); 
                }
            }
            
            //artysci
            for (int i = 0; i < liczArt; i++)
            {
                Miejsce* tujes = (*artysta[i]).dajJestemTu();
                Miejsce* praca = (*artysta[i]).dajMiejscePracy(dzienTygodnia);
                int poczPracy = (*artysta[i]).dajPoczatekPracy(dzienTygodnia);
                int dlugPracy = (*artysta[i]).dajDlugoscPracy(dzienTygodnia);
                int h = ktoreMiejsce(tujes);
                int c = ktoreMiejsce(praca);
                miejscezlinia T = trasa[h][c];
                int wyruszWczesniej = trasa[h][c].odl + 10;
                if(wyruszWczesniej > poczPracy - 6 * 60)
                {
                        cout << "Upsss ! Artysta o id: " << (*artysta[i]).dajId() << "moze spoznic sie do pracy." << endl;
                }
            
                // do pracy
                (*kolejka).wstaw(new ZdarzeniePodroz(czasPoczDnia + poczPracy - wyruszWczesniej, *kolejka, tujes, praca, T, artysta[i], 0));
            
                if(losowanie(prawdZakupowTyg))
                {
                    // na zakupy
                    int nrCH = rand() % liczbaCH;
                    Miejsce* cenh = (*centrumhandlowe[nrCH]).dajMiejsce();
                    int dlZak = (rand() % (2 * 60)) + 1 * 60; // tyle jestesmy na zakupach
                    miejscezlinia T2 = trasa[c][nrCH];
                    (*artysta[i]).dodajZadaniePodrozCH(dlugPracy, *kolejka, cenh, T2, artysta[i], 1, centrumhandlowe[nrCH]);

                    // powrot do domu
                    miejscezlinia T3 = trasa[nrCH][h];
                    (*artysta[i]).dodajZadaniePodroz(dlZak, *kolejka, miejsce[h], T3, artysta[i], 2);
                    (*artysta[i]).dodajZadanieNic();
                }
                
                else
                {
                    // powrot
                    miejscezlinia T3 = trasa[c][h];
                    (*artysta[i]).dodajZadaniePodroz(dlugPracy, *kolejka, miejsce[h], T3, artysta[i], 1);
                    (*artysta[i]).dodajZadanieNic();
                }
            }
            
            // pracownicy
            for (int i = 0; i < liczPrac; i++)
            {
                Miejsce* tujes = (*pracownik[i]).dajJestemTu();
                Miejsce* praca = (*pracownik[i]).dajMiejscePracy(dzienTygodnia);
                int poczPracy = (*pracownik[i]).dajPoczatekPracy(dzienTygodnia);
                int h = ktoreMiejsce(tujes);
                int c = ktoreMiejsce(praca);
                miejscezlinia T = trasa[h][c];
                int wyruszWczesniej = trasa[h][c].odl + 10;
                if(wyruszWczesniej > poczPracy - 6 * 60)
                {
                        cout << "Upsss ! Pracownik o id: " << (*pracownik[i]).dajId() << " moze spoznic sie do pracy." << endl << endl;
                }
            
                // do pracy
                (*kolejka).wstaw(new ZdarzeniePodroz(czasPoczDnia + poczPracy - wyruszWczesniej, *kolejka, tujes, praca, T, pracownik[i], 0));
            
                bool czyPodroz = losowanie(prawdWyjazd);
                
                if(czyPodroz)
                {
                    int doNr = rand() % liczbaMiejsc;
                    Miejsce* doMiejsca = miejsce[doNr];
                    
                    T = trasa[c][doNr];
                    (*pracownik[i]).dodajZadaniePodroz(4.5 * 60, *kolejka, miejsce[doNr], T, pracownik[i], 1);   //tam
                    
                    T = trasa[doNr][c];
                    (*pracownik[i]).dodajZadaniePodroz(0, *kolejka, miejsce[c], T, pracownik[i], 2);   //powrot
                    
                    if(losowanie(prawdZakupowTyg))
                    {
                        // na zakupy
                        int nrCH = rand() % liczbaCH;
                        Miejsce* cenh = (*centrumhandlowe[nrCH]).dajMiejsce();
                        int dlZak = (rand() % (2 * 60)) + 1 * 60; // tyle jestesmy na zakupach
                        miejscezlinia T2 = trasa[c][nrCH];
                        (*pracownik[i]).dodajZadaniePodrozCH(4.5 * 60, *kolejka, cenh, T2, pracownik[i], 3, centrumhandlowe[nrCH]);

                        // powrot do domu
                        miejscezlinia T3 = trasa[nrCH][h];
                        (*pracownik[i]).dodajZadaniePodroz(dlZak, *kolejka, miejsce[h], T3, pracownik[i], 4);
                        (*pracownik[i]).dodajZadanieNic();
                    }
                    else
                    {
                        // powrot do domu
                        T = trasa[c][h];
                        (*pracownik[i]).dodajZadaniePodroz(4.5 * 60, *kolejka, miejsce[h], T, pracownik[i], 3);
                        (*pracownik[i]).dodajZadanieNic();
                    }
                }
                else
                {
                    if(losowanie(prawdZakupowTyg))
                    {
                        // na zakupy
                        int nrCH = rand() % liczbaCH;
                        Miejsce* cenh = (*centrumhandlowe[nrCH]).dajMiejsce();
                        int dlZak = (rand() % (2 * 60)) + 1 * 60; // tyle jestesmy na zakupach
                        miejscezlinia T2 = trasa[c][nrCH];
                        (*pracownik[i]).dodajZadaniePodrozCH(9 * 60, *kolejka, cenh, T2, pracownik[i], 1, centrumhandlowe[nrCH]);

                        // powrot do domu
                        miejscezlinia T3 = trasa[nrCH][h];
                        (*pracownik[i]).dodajZadaniePodroz(dlZak, *kolejka, miejsce[h], T3, pracownik[i], 2);
                        (*pracownik[i]).dodajZadanieNic();
                    }
                    
                    else
                    {
                        // powrot do domu
                        miejscezlinia T2 = trasa[c][h];
                        (*pracownik[i]).dodajZadaniePodroz(9 * 60, *kolejka, miejsce[h], T2, pracownik[i], 1);
                        (*pracownik[i]).dodajZadanieNic(); 
                    }
                } 
            }
            
            //studenci
            for (int i = 0; i < liczStud; i++) 
            {
                Miejsce* tujes = (*student[i]).dajJestemTu();
                Miejsce* uni1 = (*student[i]).dajMiejscePracy(dzienTygodnia);
                Miejsce* uni2 = (*student[i]).daj2MiejscePracy(dzienTygodnia);
                int poczZajec = (*student[i]).dajPoczatekPracy(dzienTygodnia);
                int dlugZajec = (*student[i]).dajDlugoscPracy(dzienTygodnia);
                int h = ktoreMiejsce(tujes);
                int c = ktoreMiejsce(uni1);
                miejscezlinia T = trasa[h][c];
                int wyruszWczesniej = trasa[h][c].odl + 10;
                if(wyruszWczesniej > poczZajec - 6 * 60)
                {
                        cout << "Upsss ! Student o id: " << (*student[i]).dajId() << " moze spoznic sie na zajecia." << endl;
                }
            
                // do uniwersytetu
                (*kolejka).wstaw(new ZdarzeniePodroz(czasPoczDnia + poczZajec - wyruszWczesniej, *kolejka, tujes, uni1, T, student[i], 0));
            
                if(i < liczStud2)
                {
                    // do 2. uniwersytetu
                    int d = ktoreMiejsce(uni2);
                    miejscezlinia T2 = trasa[c][d];
                    (*student[i]).dodajZadaniePodroz(dlugZajec / 2, *kolejka, miejsce[d], T2, student[i], 1);
                    
                    if(losowanie(prawdZakupowTyg))
                    {
                        // na zakupy
                        int nrCH = rand() % liczbaCH;
                        Miejsce* cenh = (*centrumhandlowe[nrCH]).dajMiejsce();
                        int dlZak = (rand() % (2 * 60)) + 1 * 60; // tyle jestesmy na zakupach
                        miejscezlinia T3 = trasa[d][nrCH];
                        (*student[i]).dodajZadaniePodrozCH(dlugZajec / 2, *kolejka, cenh, T3, student[i], 2, centrumhandlowe[nrCH]);

                        // powrot do domu
                        miejscezlinia T4 = trasa[nrCH][h];
                        (*student[i]).dodajZadaniePodroz(dlZak, *kolejka, miejsce[h], T4, student[i], 3);
                        (*student[i]).dodajZadanieNic();
                    }
                    
                    else
                    {
                        // powrot
                        miejscezlinia T3 = trasa[d][h];
                        (*student[i]).dodajZadaniePodroz(dlugZajec / 2, *kolejka, miejsce[h], T3, student[i], 2);
                        (*student[i]).dodajZadanieNic();
                    }
                    
                }
                else
                {
                    if(losowanie(prawdZakupowTyg))
                    {
                        // na zakupy
                        int nrCH = rand() % liczbaCH;
                        Miejsce* cenh = (*centrumhandlowe[nrCH]).dajMiejsce();
                        int dlZak = (rand() % (2 * 60)) + 1 * 60; // tyle jestesmy na zakupach
                        miejscezlinia T2 = trasa[c][nrCH];
                        (*student[i]).dodajZadaniePodrozCH(dlugZajec, *kolejka, cenh, T2, student[i], 1, centrumhandlowe[nrCH]);

                        // powrot do domu
                        miejscezlinia T3 = trasa[nrCH][h];
                        (*student[i]).dodajZadaniePodroz(dlZak, *kolejka, miejsce[h], T3, student[i], 2);
                        (*student[i]).dodajZadanieNic();
                    }
                    else
                    {
                        // powrot do domu
                        miejscezlinia T2 = trasa[c][h];
                        (*student[i]).dodajZadaniePodroz(dlugZajec, *kolejka, miejsce[h], T2, student[i], 1);
                        (*student[i]).dodajZadanieNic();
                    }
                }
            }
            
            for(int i = 0; i < liczLiniiTram; i++)
            {
                (*nrlinii[i]).wyruszamy(czasPoczDnia + 6 * 60, czasPoczDnia + 23 * 60);
            }
            (*kolejka).niechSieDzieje(czasPoczDnia + 24 * 60);
            
        }
        if((5 <= dzienTygodnia) &&( dzienTygodnia <= 6))  // weekend
        {
            ustawieniePoczatkoweWeekend();
            
            //artysci do pracy
            for (int i = 0; i < liczArt; i++)
            {
                Miejsce* tujes = (*artysta[i]).dajJestemTu();
                Miejsce* praca = (*artysta[i]).dajMiejscePracy(dzienTygodnia);
                int poczPracy = (*artysta[i]).dajPoczatekPracy(dzienTygodnia);
                int dlugPracy = (*artysta[i]).dajDlugoscPracy(dzienTygodnia);
                int h = ktoreMiejsce(tujes);
                int c = ktoreMiejsce(praca);
                miejscezlinia T = trasa[h][c];
                int wyruszWczesniej = trasa[h][c].odl + 10;
                if(wyruszWczesniej > poczPracy - 6 * 60)
                {
                        cout << "Upsss ! Artysta o id: " << (*artysta[i]).dajId() << "moze spoznic sie do pracy." << endl;
                }
            
                // do pracy
                (*kolejka).wstaw(new ZdarzeniePodroz(czasPoczDnia + poczPracy - wyruszWczesniej, *kolejka, tujes, praca, T, artysta[i], 0));
                
                // na zakupy
                int nrCH = rand() % liczbaCH;
                Miejsce* cenh = (*centrumhandlowe[nrCH]).dajMiejsce();
                int dlZak = (rand() % (2 * 60)) + 1 * 60;   // tyle jestesmy na zakupach
                miejscezlinia T2 = trasa[c][nrCH];
                (*artysta[i]).dodajZadaniePodrozCH(dlugPracy, *kolejka, cenh, T2, artysta[i], 1, centrumhandlowe[nrCH]);
                
                // powrot do domu
                miejscezlinia T3 = trasa[nrCH][h];
                (*artysta[i]).dodajZadaniePodroz(dlZak, *kolejka, miejsce[h], T3, artysta[i], 2);
                (*artysta[i]).dodajZadanieNic();  
            }
            
            // pracownicy na zakupy
            for (int i = 0; i < liczPrac; i++)
            {
                Miejsce* tujes = (*pracownik[i]).dajJestemTu();
                int nrCH = rand() % liczbaCH;
                Miejsce* cenh = (*centrumhandlowe[nrCH]).dajMiejsce();
                int wyjazd = (rand() % (3 * 60)) + 10 * 60;    // wyjezdzamy o tej na zakupy
                int dlZak = (rand() % (2 * 60)) + 1 * 60;   // tyle jestesmy na zakupach
                int h = ktoreMiejsce(tujes);
                int c = ktoreMiejsce(cenh);
                miejscezlinia T = trasa[h][c];
            
                // do CH
                (*kolejka).wstaw(new ZdarzeniePodrozCH(czasPoczDnia + wyjazd, *kolejka, tujes, cenh, T, pracownik[i], 0, centrumhandlowe[nrCH]));
            
                // powrot do domu
                T = trasa[c][h];
                (*pracownik[i]).dodajZadaniePodroz(dlZak, *kolejka, miejsce[h], T, pracownik[i], 1);   
                (*pracownik[i]).dodajZadanieNic(); 
               
            }
            
            // studenci na zakupy
            for (int i = 0; i < liczStud; i++)
            {
               Miejsce* tujes = (*student[i]).dajJestemTu();
                int nrCH = rand() % liczbaCH;
                Miejsce* cenh = (*centrumhandlowe[nrCH]).dajMiejsce();
                int wyjazd = (rand() % (3 * 60)) + 10 * 60;    // wyjezdzamy o tej na zakupy
                int dlZak = (rand() % (2 * 60)) + 1 * 60;   // tyle jestesmy na zakupach
                int h = ktoreMiejsce(tujes);
                int c = ktoreMiejsce(cenh);
                miejscezlinia T = trasa[h][c];
            
                // do CH
                (*kolejka).wstaw(new ZdarzeniePodrozCH(czasPoczDnia + wyjazd, *kolejka, tujes, cenh, T, student[i], 0, centrumhandlowe[nrCH]));
            
                // powrot do domu
                T = trasa[c][h];
                (*student[i]).dodajZadaniePodroz(dlZak, *kolejka, miejsce[h], T, student[i], 1);   
                (*student[i]).dodajZadanieNic(); 
               
            }
            
            // uczniowie do teatru
            for (int i = 0; i < liczUcz; i++)
            {
                Spektakl* spek = (*uczen[i]).dajSpektakl();
                if((spek != nullptr) && ((*spek).dajDzienSym() == dzienSymulacji))
                {
                    Miejsce* tujes = (*uczen[i]).dajJestemTu();
                    Miejsce* tenTeatr = (*spek).dajMiejsce();
                    Teatr* tT = (*tenTeatr).dajTeatr();
                    int dlugSpek = (*spek).dajDlugSpek();
                    int h = ktoreMiejsce(tujes);
                    int c = ktoreMiejsce(tenTeatr);
                    miejscezlinia T = trasa[h][c];
                    int wyruszWczesniej = trasa[h][c].odl + 10;
                    int godz = (*spek).dajGodz();
                    if (wyruszWczesniej > godz - 6 * 60) {
                        cout << "Upsss ! Uczen o id: " << (*uczen[i]).dajId() << " moze spoznic sie na spektakl." << endl;
                    }

                    // do teatru
                    (*kolejka).wstaw(new ZdarzeniePodrozTeatr(czasPoczDnia + godz - wyruszWczesniej, *kolejka, tujes, tenTeatr, T, uczen[i], 0, tT));

                    // powrot
                    T = trasa[c][h];
                    (*uczen[i]).dodajZadaniePodroz(dlugSpek, *kolejka, miejsce[h], T, uczen[i], 1);
                    (*uczen[i]).dodajZadanieNic();
                }
            }
            
            for(int i = 0; i < liczLiniiTram; i++)
            {
                (*nrlinii[i]).wyruszamyWeekend(czasPoczDnia + 6 * 60, czasPoczDnia + 23 * 60);
            }
            (*kolejka).niechSieDzieje(czasPoczDnia + 24 * 60);
        }
        
        
    } // koniec glowniej petli
     
 // ---------------------------------------------------------------------   
 //   stanProgramu();
    
    ustawieniePoczatkowe();
    
    // ------------------- wypisywanie wczytanych danych ---------------------
    
    cout << endl << endl << endl << "Oto wczytane dane:" << endl << endl;
    
    cout << "Liczba dni symulacji: " << liczbaDniSymulacji << endl;
    cout << "Liczba pracujacych: " << liczPrac << endl;
    cout << "Liczba studentow: " << liczStud << endl;
    cout << "Liczba artystow: " << liczArt << endl;
    cout << "Liczba uczniow: " << liczUcz << endl;
    cout << "Prawdopodobienstwo wyjazdu w ciagu dnia dla pracujacego: " << prawdWyjazd << endl;
    cout << "Prawdopodobienstwo zakupow w tygodniu: " << prawdZakupowTyg << endl;
    cout << "Procet studentow z dwoma kierunkami studiow: " << procStud2 << endl;
    cout << "Procent zmniejszenia liczby tramwajow w weekendy: " << procZmnTramWeekend << endl;
    cout << "Prwdopodobienstwo pojscia do teatru kolejno dla Pracujacych, Studentow, Artystow, Uczniow: " << prawdTeatrP << " " << prawdTeatrS << " " << prawdTeatrA << " " << prawdTeatrU << endl;
    cout << "Pojemnosc tramwaju: " << pojTramwaju << endl;
    cout << "Liczba miejsc: " << liczbaMiejsc << endl;
    
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        cout << (*miejsce[i]) << endl;
    }
    
    cout << "Liczba linii tramwajowych: " << liczLiniiTram << endl;
    for(int i = 0; i < liczLiniiTram; i++)
    {
        cout << (*nrlinii[i]) << endl;
    }
    cout << "Liczba uniwersytetow: " << liczbaUniwersytetow << endl;
    for(int i = 0; i < liczbaUniwersytetow; i++)
    {
        cout << (*uniwersytet[i]).dajNazwe() << " " << *((*uniwersytet[i]).dajMiejsce()) << endl;
    }
    cout << endl << "Liczba teatrow: " << liczbaTeatrow << endl;
    for(int i = 0; i < liczbaTeatrow; i++)
    {
        cout << (*teatr[i]).dajNazwe() << " " << *((*teatr[i]).dajMiejsce()) << " " << (*teatr[i]).dajLiczbeMiejsc() << endl;
    }
    cout << endl << "Liczba centrow handlowych: " << liczbaCH << endl;
    for(int i = 0; i < liczbaCH; i++)
    {
        cout << (*centrumhandlowe[i]).dajNazwe() << " " << *((*centrumhandlowe[i]).dajMiejsce()) << endl;
    }
    cout << endl;
    
   // stanProgramu();
    //------------------- zwalnianie pamieci ----------------------
    
    for (int i = 0; i < liczbaMiejsc; i++)
    {
        delete miejsce[i];
        delete przystanek[i];
    }
    
    
    for (int i = 0; i < liczbaMiejsc; i++)
    {
        delete trasa[i];
    }
 
    delete trasa;
    
   
    for (int i = 0; i < liczLiniiTram; i++)
    {
        (*nrlinii[i]).zniszczTramwaje();
        delete nrlinii[i];
    }


    
    (*kolejka).czyszczenieKolejki();
    delete kolejka;
    
    
    for(int i = 0; i < liczUcz; i++)
    {
        delete uczen[i];
    }
    
    for(int i = 0; i < liczArt; i++)
    {
        delete artysta[i];
    }
    
    for(int i = 0; i < liczPrac; i++)
    {
        delete pracownik[i];
    }
    
    for(int i = 0; i < liczStud; i++)
    {
        delete student[i];
    }
    
    for(int i = 0; i < liczbaUniwersytetow; i++)
    {
        delete uniwersytet[i];
    }
    
    for(int i = 0; i < liczbaTeatrow; i++)
    {
        (*teatr[i]).zniszczSpektakle();
        delete teatr[i];
    }
    
    for(int i = 0; i < liczbaCH; i++)
    {
        delete centrumhandlowe[i];
    }

    cout << "Koniec programu" << endl;
    
}



// ------------------- funkcja stan programu ------------------------------

void stanProgramu()
{
    
    cout << liczbaMiejsc << " miejsc i przystankow:" << endl;
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        cout << (*miejsce[i]).dajNazwe() << ", " << (*(*przystanek[i]).dajMiejsce()).dajNazwe() << endl;
    }
    
    cout << endl << liczLiniiTram << " linii tramwajowych:" << endl;
    for(int i = 0; i < liczLiniiTram; i++)
    {
        cout << "Nr " << i << ", liczba tramwajow: " << (*nrlinii[i]).dajLiczbeTramwajow() << endl;
        cout << "Tramwaje tej linii:" << endl;
        for(int j = 0; j < (*nrlinii[i]).dajLiczbeTramwajow(); j++)
        {
            cout << (*((*nrlinii[i]).dajTramwaj(j))).dajNrTram() << ((j < (*nrlinii[i]).dajLiczbeTramwajow() - 1) ? ", " : "");
//            cout << (*nrlinii[i]).dajTramwaj(j) << ((j < (*nrlinii[i]).dajLiczbeTramwajow() - 1) ? ", " : ""); //wypisuje adresy tramwajow

        }
        cout << endl << endl;
        
        cout << "Przystanki:" << endl;
        for(int j = 0; j < (*nrlinii[i]).dajLiczbePrzystankow(); j++)
        {
            cout << (*(*((*nrlinii[i]).dajPrzystanek(j))).dajMiejsce()).dajNazwe() << ((j < (*nrlinii[i]).dajLiczbePrzystankow() - 1) ? ", " : "");
        }
    }  
    cout << endl;
    for (int i = 0; i < przystanek.size(); i++)
    {
        cout << "Przystanek " << (*(*przystanek[i]).dajMiejsce()).dajNazwe() << " ma obok:" << endl;
        for (int j = 0; j < (*przystanek[i]).dajLiczPrzystObok(); j++)
        {
            cout << (*(*((*przystanek[i]).dajPrzystObok(j))).dajMiejsce()).dajNazwe() << "  Nr linii: ";
            for (int k = 0; k < (*przystanek[i]).dajLiczLiniiDoPrzyst((*przystanek[i]).dajPrzystObok(j)); k++)
            {
                cout << (*przystanek[i]).dajNrLiniiDoPrzyst(j, k) << ", ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    cout << endl;
    
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        cout << (*miejsce[i]) << ": ";
        for(int j = 0; j < (*miejsce[i]).dajLiczbeOsob(); j++)
        {
            cout << ((*miejsce[i]).dajOsobe(j))->dajId() << " ";
        }
        cout << endl;
    }
    cout << endl;
   
    for(int i = 0; i < liczbaMiejsc; i++)
    {
        if ((*miejsce[i]).dajUniwersytet() != nullptr)
        {
                cout << (*miejsce[i]) << ": " << (*((*miejsce[i]).dajUniwersytet())).dajNazwe() << endl;
        }
    }
    cout << endl;
    
    
}
