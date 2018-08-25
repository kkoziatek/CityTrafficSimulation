/* 
 * File:   KolejkaZdarzen.cpp
 * Author: Komputer
 * 
 * Created on 10 luty 2017, 19:43
 */

#include "KolejkaZdarzen.h"

KolejkaZdarzen::KolejkaZdarzen(): zdarzenia(), czas(0) {
}

void KolejkaZdarzen::wstaw(const Zdarzenie* z) {
    assert(czas <= z->dajCzas());
    zdarzenia.push(z);
}

int KolejkaZdarzen::ktoraGodzina() {
    return czas;
}

void KolejkaZdarzen::niechSieDzieje(int koniecSwiata) {
    while (!zdarzenia.empty() and czas < koniecSwiata) {
        const Zdarzenie* z = zdarzenia.top();
       // cout << czas << ": " << z->dajId() << endl;
        if (z->dajCzas() >= koniecSwiata)
        {  
            break;    //jesli czas zdarzenia jest >= czas konca, to przerywamy dzialanie
        }
        czas = z->dajCzas();
  
      //  cout << (*z).dajId() << ":" << *z << endl << endl; // Ta linijka może się przydać przy debugowaniu
        z->zajdz();
        zdarzenia.pop();  // Dla obiektów (tu są wskaźniki, więc ich to nie dotyczy) woła destruktor elementu usuwanego z kolejki
        delete z;
    }

    // czyszczenie kolejki - żeby nie zostawiać w kolejce śmieci
}

void KolejkaZdarzen::czyszczenieKolejki()
{
    while (!zdarzenia.empty())
    {
        const Zdarzenie* z = zdarzenia.top();
        zdarzenia.pop();
        delete z;
    }
}

