#pragma once

#include <list>
#include "Locatie.hpp"
#include "Tichet.hpp"
#include "Eveniment.hpp"

namespace IMeniu {
  namespace ILocatie {
    void Adauga(Locatie);
    void Sterge(Locatie);
    void Modifica(Locatie);
    void Afiseaza(std::list<Locatie>);
    // @todo
  }

  namespace IEveniment {
    void Adauga(Eveniment);
    void Sterge(Eveniment);
    void Modifica(Eveniment);
    void Afiseaza(std::list<Eveniment>);
    // @todo
  }

  namespace ITichet {
    void Adauga(Tichet);
    void Sterge(Tichet);
    void Modifica(Tichet);
    void Afiseaza(std::list<Tichet>);
    // @todo
  }

  void _Init(std::list<Locatie>, std::list<Eveniment>, std::list<Tichet>);
  void _Locatie(std::list<Locatie>);
  void _Eveniment(std::list<Eveniment>);
}