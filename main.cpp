#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "Meniu.hpp"
#include "Tichet.hpp"

int main(int argc, char *argv[]) {
  std::list<Locatie> locatii;
  std::list<Eveniment> evenimente;
  std::list<Tichet> tichete;

  if (argc > 1) {
    std::ifstream fdate(argv[1], std::ios::binary);
    while (fdate.peek() != EOF) {
      Tichet tichet;
      tichet.LoadFromFile(fdate);
      tichete.push_back(tichet);
    }
    fdate.close();

    for (auto tichet : tichete) {
      locatii.push_back(tichet.getEveniment()->getLocatie());
      evenimente.push_back(*tichet.getEveniment());
    }
  } else {
    std::ifstream fin("tichete.txt", std::ios::binary);
    while (fin.peek() != EOF) {
      Tichet tichet;
      tichet.LoadFromFile(fin);
      tichete.push_back(tichet);
    }
    fin.close();

    std::ifstream finLocatii("locatii.txt", std::ios::binary);
    while (finLocatii.peek() != EOF) {
      Locatie locatie;
      locatie.LoadFromFile(finLocatii);
      locatii.push_back(locatie);
    }
    finLocatii.close();

    std::ifstream finEvenimente("evenimente.txt", std::ios::binary);
    while (finEvenimente.peek() != EOF) {
      Eveniment eveniment;
      eveniment.LoadFromFile(finEvenimente);
      evenimente.push_back(eveniment);
    }
  }

  std::list<Locatie> locatiiOld;
  std::list<Eveniment> evenimenteOld;
  std::list<Tichet> ticheteOld;

  for (auto locatie : locatii) {
    locatiiOld.push_back(locatie);
  }

  for (auto eveniment : evenimente) {
    evenimenteOld.push_back(eveniment);
  }

  for (auto tichet : tichete) {
    ticheteOld.push_back(tichet);
  }

  Meniu::Init(locatii, evenimente, tichete);

  // comparam daca au fost facute modificari
  if (locatii.size() != locatiiOld.size() ||
      evenimente.size() != evenimenteOld.size() ||
      tichete.size() != ticheteOld.size()) {
    if (locatii.size() != locatiiOld.size()) {
      std::cout << "Au fost facute modificari la locatii.\n";
      std::ofstream foutLocatii("locatii.txt", std::ios::binary);
      for (auto locatie : locatii) {
        locatie.SaveToFile(foutLocatii);
      }
      foutLocatii.close();
    } else if (evenimente.size() != evenimenteOld.size()) {
      std::cout << "Au fost facute modificari la evenimente.\n";
      std::ofstream foutEvenimente("evenimente.txt", std::ios::binary);
      for (auto eveniment : evenimente) {
        eveniment.SaveToFile(foutEvenimente);
      }
      foutEvenimente.close();
    } else if (tichete.size() != ticheteOld.size()) {
      std::cout << "Au fost facute modificari la tichete.\n";
      std::ofstream foutTichete("tichete.txt", std::ios::binary);
      for (auto tichet : tichete) {
        tichet.SaveToFile(foutTichete);
      }
      foutTichete.close();
      std::ofstream foutEvenimenteTichete("eveniment.txt", std::ios::binary);
      for (auto eveniment : evenimente) {
        eveniment.SaveToFile(foutEvenimenteTichete);
      }
      foutEvenimenteTichete.close();
    }
    std::cout << "Modificari facute cu succes." << std::endl;
  } else {
    std::cout << "Nu s-au facut modificari.\n";
  }

  return 0;
}