/* 
 * File:   Obiekt.cpp
 * Author: Komputer
 * 
 * Created on 10 luty 2017, 19:51
 */

#include "Obiekt.h"

Obiekt::Obiekt(int id): id(id){
}

void Obiekt::akcja(KolejkaZdarzen& kolZdarzen) {
    cout << "Jest " << kolZdarzen.ktoraGodzina() << endl;
    // Rozsadza mnie energia, niech się coś stanie!
  //  kolZdarzen.wstaw(new Zdarzenie(kolZdarzen.ktoraGodzina() + rand() % 20 + 1, *this, kolZdarzen));
    // Może jeszcze jakiś program napiszę?
    //kolZdarzen.wstaw(new Zdarzenie(kolZdarzen.ktoraGodzina() + rand() % 40 + 1, *this, kolZdarzen));
}

