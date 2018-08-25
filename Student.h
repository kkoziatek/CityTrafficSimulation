/* 
 * File:   Student.h
 * Author: Komputer
 *
 * Created on 16 luty 2017, 09:59
 */

#ifndef STUDENT_H
#define	STUDENT_H

#include <iostream>

#include "Miejsce.h"
#include "Osoba.h"

class Student : public Osoba{
    Miejsce* uniwersytet1;
    Miejsce* uniwersytet2;    // moze byc == nullptr, moze byc takze, ze uniwersytet1 == uniwersytet2
    int poczatekPracy[5];
    int dlugoscPracy[5];
public:
    Student();
    Student(int, Miejsce*, Miejsce*, Miejsce*, Miejsce*);
    Student(const Student& S) = default;
    virtual ~Student();
    
    //API
    string dajKtoJestem();
    Miejsce* dajMiejscePracy(int dzien);
    int dajPoczatekPracy(int dzien);
    int dajDlugoscPracy(int dzien);
    Miejsce* daj2MiejscePracy(int dzien);
    
    void dodajMiejscePracy(int dzien, Miejsce* M);
    void dodajPoczatekPracy(int dzien, int godz);
    void dodajDlugoscPracy(int dzien, int godz);
    
private:

};

#endif	/* STUDENT_H */

