#include "Meniu.hpp"

// Locatie *
// ILocatie::Adauga(const std::optional<Eveniment> eveniment = std::nullopt) {
//   if (eveniment.has_value()) {
//     std::cout << "Nu se poate adauga un eveniment sau un tichet la o
//     locatie!"
//               << std::endl;
//     return nullptr;
//   }
//   Locatie *newLocatie = new Locatie();
//   std::cin >> *newLocatie;
//   return newLocatie;
// }

// void ILocatie::Modifica(
//     Locatie *locatie, const std::optional<Eveniment> eveniment =
//     std::nullopt) {
//   if (eveniment.has_value()) {
//     return;
//   }

//   std::cin >> *locatie;
// }

// Eveniment *
// IEveniment::Adauga(const std::optional<Locatie> locatie = std::nullopt) {
//   Eveniment *newEveniment = new Eveniment(locatie.value());
//   std::cin >> *newEveniment;
//   return newEveniment;
// }

// void IEveniment::Modifica(Eveniment *eveniment,
//                           const std::optional<Locatie> locatie) {
//   std::cin >> *eveniment;
// }

// Tichet *ITichet::Adauga(const std::optional<Eveniment> eveniment) {
//   Tichet *newTichet = new Tichet((Eveniment &)eveniment.value());
//   std::cin >> *newTichet;
//   return newTichet;
// }

// void ITichet::Modifica(Tichet *tichet,
//                        const std::optional<Eveniment> eveniment) {
//   std::cin >> *tichet;
// }

// void Meniu::Init(std::list<Locatie> &locatii, std::list<Eveniment>
// &evenimente,
//                  std::list<Tichet> &tichete) {
//   ILocatie *iLocatie = new ILocatie();
//   Locatie *newLocatie = iLocatie->Adauga();
//   locatii.push_front(*newLocatie);

//   Locatie pLocatie(*newLocatie);

//   IEveniment *iEv = new IEveniment();
//   Eveniment *nEv = iEv->Adauga(pLocatie);

//   evenimente.push_front(*nEv);

//   ITichet *iTichet = new ITichet();
//   Tichet *nTch = iTichet->Adauga(*nEv);

//   std::cout << *nTch;
// }

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
  ILocatie *iLocatie = new ILocatie();
  Locatie *newLocatie = iLocatie->Adauga();
  locatii.push_front(*newLocatie);

  IEveniment *iEveniment = new IEveniment();
  Eveniment *newEveniment = iEveniment->Adauga(newLocatie);
  evenimente.push_front(*newEveniment);

  ITichet *iTichet = new ITichet();
  Tichet *newTichet = iTichet->Adauga(newEveniment);
  tichete.push_front(*newTichet);

  std::cout << tichete.front();
}