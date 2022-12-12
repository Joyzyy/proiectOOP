#pragma once

#include "Utils.hpp"
#include "Locatie.hpp"
#include "Eveniment.hpp"

class Tichet {
public:
  Tichet(Eveniment&);
  Tichet(const char*, Eveniment&);
  Tichet(const Tichet&);
  ~Tichet();

  Tichet& operator=(const Tichet&);
  bool operator==(const Tichet&);
  bool operator!=(const Tichet&);
  friend std::ostream& operator<<(std::ostream&, const Tichet&);
  friend std::istream& operator>>(std::istream&, Tichet&);

  void setLoc(int);
  void setRand(int);

  const char* getTipBilet();
  int getId() const;
  int getNrLoc() const;
  int getNrRand() const;
  Eveniment* getEveniment();

private:
  const int   m_iId;
  char*       m_szTipBilet;
  int         m_iNrRand;
  int         m_iNrLoc;
  Eveniment*  m_oEveniment;
};