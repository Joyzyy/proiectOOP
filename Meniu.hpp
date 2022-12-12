#pragma once

#include <list>
#include "Locatie.hpp"
#include "Tichet.hpp"
#include "Eveniment.hpp"

namespace Meniu {
  void Init(std::list<Locatie>, std::list<Eveniment>, std::list<Tichet>);
  void GLocatie(std::list<Locatie>);
  void GEveniment(std::list<Eveniment>);
}