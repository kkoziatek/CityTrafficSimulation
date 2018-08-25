/* 
 * File:   Compare.h
 * Author: Komputer
 *
 * Created on 10 luty 2017, 19:54
 */

#ifndef COMPARE_H
#define	COMPARE_H

#include <iostream>
#include <queue>       // priority_queue

// Dodatkowe sprawdzania
#include <cassert>     // assert

// Generacja liczb losowych
#include <cstdlib>     // srand, rand
#include <ctime>       // time, użyty tylko w srand

// Zaślepka
#include <sstream>     // ostringstream - zaślepka dla to_string

#include<vector>
#include<math.h>

#include "Zdarzenie.h"

class Compare{ // Klasa obiektów porównujących zdarzenia, potrzebna zwn priority_queue
public:
  bool operator()(const Zdarzenie* z1, const Zdarzenie* z2)
  {
      if (z1->dajCzas() > z2->dajCzas())
      {
          return 1;
      }
      if(z1->dajCzas() < z2->dajCzas())
      {
          return 0;
      }
      
      return (z1->dajId() > z2->dajId());
  }
};

#endif	/* COMPARE_H */

