/* 
 * File:   ZadanieNic.h
 * Author: Komputer
 *
 * Created on 15 luty 2017, 10:01
 */

#ifndef ZADANIENIC_H
#define	ZADANIENIC_H

#include "Miejsce.h"
#include "Zdarzenie.h"

#include "Zadanie.h"

class ZadanieNic : public Zadanie{
public:
    ZadanieNic() = default;
    ZadanieNic(const ZadanieNic& ZC) = default;
    virtual ~ZadanieNic() = default;
    
    //API
    void zajdz(int czas, Miejsce* tutajJestem);
private:

};

#endif	/* ZADANIENIC_H */

