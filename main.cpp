#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <list>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "Tichet.hpp"

int main() {

    // @todo -> pentru faza 2 meniu si nebunii XD

    // Mai intai citim locatiile
    std::list<Locatie> locatii;
    std::list<Eveniment> evenimente;
    
    // Locatie loc1("Arena Nationala", 10, 10);
    // Locatie loc2("AFI Cotroceni", 50, 50);
    // Locatie loc3("Plaza Romania", 100, 100);

    // locatii.push_back(loc1);
    // locatii.push_back(loc2);
    // locatii.push_back(loc3);

    // for (const auto loc : locatii) {
    //     std::cout << loc.getId() << std::endl;
    // }

    // Eveniment ev("F", "asd", 10.f, loc1);
    // evenimente.push_back(ev);

    // for (const auto c : evenimente) {
    //     std::cout << c << std::endl;
    // }

    std::ifstream fin("locatii.txt");
    while (!fin.eof()) {
        std::string nume;
        int nrLocuri;
        int nrRanduri;
        fin >> nume >> nrLocuri >> nrRanduri;
        Locatie* newLoc = new Locatie(nume.c_str(), nrLocuri, nrRanduri);
        locatii.push_back(*newLoc);
    }
    fin.close();

    for (const auto l : locatii) {
        std::cout << l << '\n';
    }

    locatii.clear();

    std::ifstream fev("evenimente.txt");
    int k = 0;
    while (!fev.eof()) {
        std::string nume;
        std::string descriere;
        float pret;
        //int idLocatie;

        fev >> nume >> descriere >> pret;

        std::cout << nume << " " << descriere << " " << (float)pret;

        ++k;
        for (const Locatie locatie : locatii) {
            Eveniment* newEv = new Eveniment(nume.c_str(), descriere.c_str(), (float)pret, locatie);
            std::cout << newEv << std::endl;
            evenimente.push_back(*newEv);
        }
    }
    fev.close();

    for (const Eveniment ev : evenimente) {
        std::cout << ev << std::endl;
    }

    // @todo: preia locatii / evenimente dintr-un fisier and add them to the list
/*
    // read from file
    std::ifstream fin("locatii.txt");
    while (!fin.eof()) {
        std::string nume;
        int nrLocuri;
        int nrRanduri;
        fin >> nume >> nrLocuri >> nrRanduri;
        Locatie loc(nume.c_str(), nrLocuri, nrRanduri);
        locatii.push_back(loc);
    }
    fin.close();

    std::ifstream fin_ev("evenimente.txt");
    while (!fin_ev.eof()) {
        std::string nume;
        std::string desc;
        float pret;
        int idLocatie;

        fin_ev >> nume >> desc >> pret >> idLocatie;

        Locatie locatie;
        for (const Locatie& loc : locatii) {
            if (loc.getId() == idLocatie) {
                locatie = loc;
                break;
            }
        }
        Eveniment ev(nume.c_str(), desc.c_str(), pret, locatie);
        evenimente.push_back(ev);
    }
    fin_ev.close();
*/
}