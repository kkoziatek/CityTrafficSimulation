/* 
 * File:   Student.cpp
 * Author: Komputer
 * 
 * Created on 16 luty 2017, 09:59
 */

#include "Student.h"

Student::Student() {
}

Student::Student(int idd, Miejsce* M1, Miejsce* M2, Miejsce* U1, Miejsce* U2): Osoba(idd, M1, M2), uniwersytet1(U1), uniwersytet2(U2)
{
}

Student::~Student() 
{
}

Miejsce* Student::dajMiejscePracy(int dzien)
{
    return uniwersytet1;
}

int Student::dajPoczatekPracy(int dzien)
{
    return poczatekPracy[dzien];
}

int Student::dajDlugoscPracy(int dzien)
{
    return dlugoscPracy[dzien];
}

Miejsce* Student::daj2MiejscePracy(int dzien)
{
    return uniwersytet2;
}

void Student::dodajMiejscePracy(int dzien, Miejsce* M)
{
    
}

void Student::dodajPoczatekPracy(int dzien, int godz)  //zawsze 8 * 60
{
    poczatekPracy[dzien] = godz;
}

void Student::dodajDlugoscPracy(int dzien, int godz)
{
    dlugoscPracy[dzien] = godz;
}

string Student::dajKtoJestem()
{
    return "student";
}


