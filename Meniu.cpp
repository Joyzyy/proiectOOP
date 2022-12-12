#include "Meniu.hpp"
#include <iostream>

void Meniu::Init(std::list<Locatie> locatii, std::list<Eveniment> evenimente, std::list<Tichet> tichete) {
  std::cout << "-------- Meniu --------" << std::endl;
  std::cout << "1. Locatie" << std::endl;
  std::cout << "2. Eveniment" << std::endl;
  std::cout << "3. Tichet" << std::endl;

  int optiune;
  std::cout << "Alegeti o optiune: ";
  std::cin >> optiune;

  switch (optiune) {
  case 1:
    std::cout << "Locatie" << std::endl;
    Meniu::GLocatie(locatii);
    break;
  case 2:
    std::cout << "Eveniment" << std::endl;
    break;
  case 3:
    std::cout << "Tichet" << std::endl;
    break;
  default:
    std::cout << "Optiune invalida" << std::endl;
    Meniu::Init(locatii, evenimente, tichete);
    system("cls");
    break;
  }
}

void Meniu::GLocatie(std::list<Locatie> locatii) {
  std::cout << "-------- Locatie --------" << std::endl;
  std::cout << "1. Adauga locatie" << std::endl;
  std::cout << "2. Sterge locatie" << std::endl;
  std::cout << "3. Modifica locatie" << std::endl;
  std::cout << "4. Afiseaza locatii" << std::endl;

  int optiune;
  std::cout << "Alegeti o optiune: ";
  std::cin >> optiune;

  switch (optiune) {
  case 1:
    std::cout << "Adauga locatie" << std::endl;
    break;
  case 2:
    std::cout << "Elimina locatie" << std::endl;
    break;
  case 3:
    std::cout << "Modifica locatie" << std::endl;
    break;
  case 4:
    std::cout << "Afiseaza locatii" << std::endl;
    for (const Locatie& locatie : locatii) {
      std::cout << locatie.getNumeLocatie() << std::endl;
    }
    break;
  default:
    std::cout << "Optiune invalida" << std::endl;
    Meniu::GLocatie(locatii);
    break;
  }
}

void Meniu::GEveniment(std::list<Eveniment> evenimente) {
  std::cout << "-------- Eveniment --------" << std::endl;
  std::cout << "1. Adauga eveniment" << std::endl;
  std::cout << "2. Sterge eveniment" << std::endl;
  std::cout << "3. Modifica eveniment" << std::endl;
  std::cout << "4. Afiseaza evenimente" << std::endl;

  int optiune;
  std::cout << "Alegeti o optiune: ";
  std::cin >> optiune;

  switch (optiune) {
  case 1:
    std::cout << "Adauga eveniment" << std::endl;
    break;
  case 2:
    std::cout << "Elimina eveniment" << std::endl;
    break;
  case 3:
    std::cout << "Modifica eveniment" << std::endl;
    break;
  case 4:
    for (const Eveniment& eveniment : evenimente) {
      std::cout << eveniment.getNumeEveniment() << std::endl;
    }
    break;
  default:
    std::cout << "Optiune invalida" << std::endl;
    Meniu::GEveniment(evenimente);
    break;
  }
}