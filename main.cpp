#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "Tichet.hpp"

int main() {
    // Mai intai citim locatiile
    std::list<Locatie> locatii;
    std::list<Eveniment> evenimente;
    
    Locatie loc1("Arena Nationala", 10, 10);
    Locatie loc2("AFI Cotroceni", 50, 50);
    Locatie loc3("Plaza Romania", 100, 100);

    locatii.push_back(loc1);
    locatii.push_back(loc2);
    locatii.push_back(loc3);

    Eveniment ev1("FV", "Festivalul de vara", 50.5f, loc1);
    Eveniment ev2("FT", "Festivalul de toamna", 100.5f, loc2);
    Eveniment ev3("FI", "Festivalul de iarna", 20.0f, loc3);

    evenimente.push_back(ev1);
    evenimente.push_back(ev2);
    evenimente.push_back(ev3);

    // @todo: preia locatii / evenimente dintr-un fisier and add them to the list
}