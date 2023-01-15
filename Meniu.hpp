#pragma once

#include <list>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "Tichet.hpp"

template <class T, class U> class IMeniu {
public:
  virtual T *Adauga(const U *) = 0;
  virtual void Modifica(T *) = 0;
};

class ILocatie : public IMeniu<Locatie, Eveniment> {
public:
  Locatie *Adauga(const Eveniment *) override;
  void Modifica(Locatie *) override;
};

class IEveniment : public IMeniu<Eveniment, Locatie> {
public:
  Eveniment *Adauga(const Locatie *) override;
  void Modifica(Eveniment *) override;
};

class ITichet : public IMeniu<Tichet, Eveniment> {
public:
  Tichet *Adauga(const Eveniment *) override;
  void Modifica(Tichet *) override;
};

namespace Meniu {
void Init(std::list<Locatie> &locatii, std::list<Eveniment> &evenimente,
          std::list<Tichet> &tichete);
void MeniuLocatie(std::list<Locatie> &locatii);
void MeniuEveniment(std::list<Eveniment> &evenimente,
                    std::list<Locatie> &locatii);
void MeniuTichet(std::list<Tichet> &tichete, std::list<Eveniment> &evenimente);
} // namespace Meniu