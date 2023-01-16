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
    MeniuEveniment(evenimente, locatii);
    break;
  case 3:
    MeniuTichet(tichete, evenimente);
    break;
  case 4:
    exit(0);
    break;
  }
}

void Meniu::MeniuLocatie(std::list<Locatie> &locatii) {

#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

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
    break;
  }
}

void Meniu::MeniuEveniment(std::list<Eveniment> &evenimente,
                           std::list<Locatie> &locatii) {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  std::cout << "------ Meniu Eveniment -----\n";
  std::cout << "1. Adauga\n";
  std::cout << "2. Modifica\n";
  std::cout << "3. Afiseaza\n";
  std::cout << "4. Sterge\n";
  std::cout << "5. Exit\n";

  int optiune;
  std::cin >> optiune;

  IEveniment eveniment;

  switch (optiune) {
  case 1:
    std::cout << "Introduceti id-ul locatiei pe care doriti sa o adaugati "
                 "aferenta evenimentului: ";
    int iLocatieID;
    std::cin >> iLocatieID;
    for (auto &pLocatie : locatii) {
      if (pLocatie.getId() == iLocatieID) {
        evenimente.push_back(*eveniment.Adauga(&pLocatie));
        break;
      }
    }

    std::cout << "Acum, evenimentele sunt: " << std::endl;
    for (auto &pEveniment : evenimente) {
      std::cout << pEveniment << std::endl;
    }

    std::cout << "Apasati orice tasta pentru a reveni la meniul principal...";
    std::cin.ignore();
    std::cin.get();
    break;
  case 2:
    std::cout
        << "Introduceti id-ul evenimentului pe care doriti sa il modificati: ";
    int id;
    std::cin >> id;
    for (auto &pEveniment : evenimente) {
      if (pEveniment.getIDEveniment() == id) {
        eveniment.Modifica(&pEveniment);
        break;
      }
    }
    break;
  case 3:
    for (auto &pEveniment : evenimente) {
      std::cout << pEveniment << std::endl;
    }
    break;
  case 4:
    std::cout
        << "Introduceti id-ul evenimentului pe care doriti sa il stergeti: ";
    std::cin >> id;
    for (auto it = evenimente.begin(); it != evenimente.end(); it++) {
      if (it->getIDEveniment() == id) {
        evenimente.erase(it);
        break;
      }
    }
    break;
  case 5:
    break;
  }
}

void Meniu::MeniuTichet(std::list<Tichet> &tichete,
                        std::list<Eveniment> &evenimente) {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  std::cout << "------ Meniu Tichet -----\n";
  std::cout << "1. Cumpara\n";
  std::cout << "2. Afiseaza\n";
  std::cout << "3. Exit\n";

  int optiune;
  std::cin >> optiune;

  ITichet tichet;

  switch (optiune) {
  case 1:
    std::cout << "Introduceti id-ul evenimentului pentru care doriti sa "
                 "cumparati bilet: ";
    int iEvenimentID;
    std::cin >> iEvenimentID;
    for (auto &pEveniment : evenimente) {
      if (pEveniment.getIDEveniment() == iEvenimentID) {
        std::cout << "Eveniment gasit." << std::endl;
        tichete.push_back(*tichet.Adauga(&pEveniment));
        break;
      }
    }

    std::cout << "Ati cumparat urmatorul tichet: " << std::endl;
    std::cout << tichete.back() << std::endl;

    std::cout << "Doriti sa fie salvat sub forma de pdf? (y/n): ";
    char cOptiune;
    std::cin >> cOptiune;

    if (cOptiune == 'y') {
      tichete.back().SaveToPDF();
      std::cout << "Tichetul a fost salvat sub forma de pdf." << std::endl;
    }

    std::cout << "Apasati orice tasta pentru a reveni la meniul principal...";
    std::cin.ignore();
    std::cin.get();

    break;
  case 2:
    for (auto &pTichet : tichete) {
      std::cout << pTichet << std::endl;
    }
    break;
  case 3:
    exit(0);
    break;
  }
}