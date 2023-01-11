#pragma once

#include <list>
#include <optional>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "Tichet.hpp"

// template <class T, class U, class V> class IMeniu {
// public:
//   virtual T *Adauga(const std::optional<U>, const std::optional<V>) = 0;
//   virtual void Modifica(T *, const std::optional<U>,
//                         const std::optional<V>) = 0;
// };

// class ILocatie : public IMeniu<Locatie, Eveniment, Tichet> {
// public:
//   Locatie *Adauga(const std::optional<Eveniment>,
//                   const std::optional<Tichet>) override;
//   void Modifica(Locatie *, const std::optional<Eveniment>,
//                 const std::optional<Tichet>) override;
// };

// class IEveniment : public IMeniu<Eveniment, Locatie, Tichet> {
// public:
//   Eveniment *Adauga(const std::optional<Locatie>,
//                     const std::optional<Tichet>) override;
//   void Modifica(Eveniment *, const std::optional<Locatie>,
//                 const std::optional<Tichet>) override;
// };

// class ITichet : public IMeniu<Tichet, Eveniment, Locatie> {
// public:
//   Tichet *Adauga(const std::optional<Eveniment> eveniment,
//                  const std::optional<Locatie> locatie) override;
//   void Modifica(Tichet *, const std::optional<Eveniment>,
//                 const std::optional<Locatie> locatie) override;
// };

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
}