#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "Meniu.hpp"
#include "Tichet.hpp"

int main() {
  // @todo -> pentru faza 2 meniu si nebunii XD

  // Mai intai citim locatiile
  // std::vector<Locatie> locatii;
  // std::list<Eveniment> evenimente;

  std::list<Locatie> locatii;
  std::list<Eveniment> evenimente;
  std::list<Tichet> tichete;

  Meniu::Init(locatii, evenimente, tichete);

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

  // std::ifstream fin("locatii.txt");
  // while (!fin.eof()) {
  //   std::string nume;
  //   int nrLocuri;
  //   int nrRanduri;
  //   fin >> nume >> nrLocuri >> nrRanduri;
  //   Locatie* newLoc = new Locatie(nume.c_str(), nrLocuri, nrRanduri);
  //   locatii.push_back(*newLoc);
  // }
  // fin.close();

  // for (const auto l : locatii) {
  //   std::cout << l << '\n';
  // }

  // std::ifstream fev("evenimente.txt");
  // int k = 0;
  // while (!fev.eof()) {
  //   std::string nume;
  //   std::string descriere;
  //   float pret;
  //   // int idLocatie;

  //   fev >> nume >> descriere >> pret;

  //   std::cout << nume << " " << descriere << " " << (float)pret;

  //   Locatie loc = locatii.at(0);
  //   Eveniment* newEv = new Eveniment(nume.c_str(), descriere.c_str(), 10.f,
  //   loc); std::cout << *newEv << std::endl;
  // }
  // fev.close();

  // for (const Eveniment ev : evenimente) {
  //   std::cout << ev << std::endl;
  // }
  // @todo: preia locatii / evenimente dintr-un fisier and add them to the list
}