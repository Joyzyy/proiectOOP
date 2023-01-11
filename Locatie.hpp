#pragma once
#include <iostream>

#include "Utils.hpp"

class Locatie {
public:
  Locatie();
  Locatie(const char *, int, int);
  Locatie(const Locatie &);
  ~Locatie();

  Locatie &operator=(const Locatie &);
  // operator++
  Locatie &operator++();
  Locatie operator++(int);
  // operator--
  Locatie &operator--();
  Locatie operator--(int);
  friend std::ostream &operator<<(std::ostream &, const Locatie &);
  friend std::istream &operator>>(std::istream &, Locatie &);

  std::string getNumeLocatie() const;
  int getNrMaximLocuri() const;
  int getNrMaximRanduri() const;
  int getId() const;

  void setNumeLocatie(const char *);
  void setNrMaximLocuri(int);
  void setNrMaximRanduri(int);

private:
  const int m_iId;
  char *m_szNumeLocatie;
  int m_iNrMaximLocuri;
  int m_iNrMaximRanduri;

  // friend class Eveniment;
  // friend class eSportTickets;
};