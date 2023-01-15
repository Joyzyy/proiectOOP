#include "Meniu.hpp"

Locatie *ILocatie::Adauga(const Eveniment *ev = nullptr) {
  if (ev != nullptr) {
    return nullptr;
  }

  Locatie *newLocatie = new Locatie();
  std::cin >> *newLocatie;
  return newLocatie;
}

void ILocatie::Modifica(Locatie *locatie) { std::cin >> *locatie; }

Eveniment *IEveniment::Adauga(const Locatie *locatie) {
  Eveniment *newEveniment = new Eveniment(*locatie);
  std::cin >> *newEveniment;
  return newEveniment;
}

void IEveniment::Modifica(Eveniment *eveniment) { std::cin >> *eveniment; }

Tichet *ITichet::Adauga(const Eveniment *eveniment) {
  Tichet *newTichet = new Tichet(*eveniment);
  std::cin >> *newTichet;
  return newTichet;
}

void ITichet::Modifica(Tichet *tichet) { std::cin >> *tichet; }

void Meniu::Init(std::list<Locatie> &locatii, std::list<Eveniment> &evenimente,
                 std::list<Tichet> &tichete) {
  std::cout << "------ Meniu -----\n";
  std::cout << "1. Locatie\n";
  std::cout << "2. Eveniment\n";
  std::cout << "3. Tichet\n";
  std::cout << "4. Exit\n";

  int optiune;
  std::cin >> optiune;

  switch (optiune) {
  case 1:
    MeniuLocatie(locatii);
    break;
  case 2:
    MeniuEveniment(evenimente);
    break;
  case 3:
    MeniuTichet(tichete);
    break;
  case 4:
    exit(0);
    break;
  }
}

void Meniu::MeniuLocatie(std::list<Locatie> &locatii) {
  std::cout << "------ Meniu Locatie -----\n";
  std::cout << "1. Adauga\n";
  std::cout << "2. Modifica\n";
  std::cout << "3. Afiseaza\n";
  std::cout << "4. Sterge\n";
  std::cout << "5. Exit\n";

  int optiune;
  std::cin >> optiune;

  ILocatie locatie;

  switch (optiune) {
  case 1:
    locatii.push_back(*locatie.Adauga());
    break;
  case 2:
    std::cout << "Introduceti id-ul locatiei pe care doriti sa o modificati: ";
    int id;
    std::cin >> id;
    for (auto &pLocatie : locatii) {
      if (pLocatie.getId() == id) {
        locatie.Modifica(&pLocatie);
        break;
      }
    }
    break;
  case 3:
    for (auto &pLocatie : locatii) {
      std::cout << pLocatie << std::endl;
    }
    break;
  case 4:
    std::cout << "Introduceti id-ul locatiei pe care doriti sa o stergeti: ";
    std::cin >> id;
    for (auto it = locatii.begin(); it != locatii.end(); it++) {
      if (it->getId() == id) {
        locatii.erase(it);
        break;
      }
    }
    break;
  case 5:
    exit(0);
    break;
  }
}

void Meniu::MeniuEveniment(std::list<Eveniment> &evenimente) { exit(0); }

void Meniu::MeniuTichet(std::list<Tichet> &tichete) { exit(0); }