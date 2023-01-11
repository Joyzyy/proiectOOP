#include "Locatie.hpp"

Locatie::Locatie() : m_iId((std::uintptr_t)this) {
  m_szNumeLocatie = nullptr;
  m_iNrMaximLocuri = -1;
  m_iNrMaximRanduri = -1;
}

Locatie::Locatie(const char *szNumeLocatie, int iNrMaximLocuri,
                 int iNrMaximRanduri)
    : m_iId((std::uintptr_t)this) {
  Utils::AllocChar(m_szNumeLocatie, szNumeLocatie);
  m_iNrMaximLocuri = iNrMaximLocuri;
  m_iNrMaximRanduri = iNrMaximRanduri;
}

Locatie::Locatie(const Locatie &locatie) : m_iId(locatie.m_iId) {
  Utils::AllocChar(m_szNumeLocatie, locatie.m_szNumeLocatie);
  m_iNrMaximLocuri = locatie.m_iNrMaximLocuri;
  m_iNrMaximRanduri = locatie.m_iNrMaximRanduri;
}

Locatie::~Locatie() { Utils::DeallocChar(m_szNumeLocatie); }

Locatie &Locatie::operator=(const Locatie &locatie) {
  if (this != &locatie) {
    Utils::ReallocChar(m_szNumeLocatie, locatie.m_szNumeLocatie);

    m_iNrMaximLocuri = locatie.m_iNrMaximLocuri;
    m_iNrMaximRanduri = locatie.m_iNrMaximRanduri;
  } else {
    std::cout << "Self assignment is not allowed!" << std::endl;
  }

  return *this;
}

Locatie &Locatie::operator++() {
  m_iNrMaximLocuri++;
  m_iNrMaximRanduri++;
  return *this;
}

Locatie Locatie::operator++(int i) {
  Locatie locatie = *this;
  m_iNrMaximLocuri++;
  m_iNrMaximRanduri++;
  return locatie;
}

Locatie &Locatie::operator--() {
  m_iNrMaximLocuri--;
  m_iNrMaximRanduri--;
  return *this;
}

Locatie Locatie::operator--(int i) {
  Locatie locatie = *this;
  m_iNrMaximLocuri--;
  m_iNrMaximRanduri--;
  return locatie;
}

std::ostream &operator<<(std::ostream &out, const Locatie &locatie) {
  out << "ID locatie: " << locatie.m_iId << std::endl;

  (locatie.m_szNumeLocatie != nullptr
       ? (out << "Nume locatie: " << locatie.m_szNumeLocatie << std::endl)
       : (out << "Nume locatie: "
              << "N/A" << std::endl));

  out << "Numar maxim locuri: " << locatie.m_iNrMaximLocuri << std::endl;
  out << "Numar maxim randuri: " << locatie.m_iNrMaximRanduri << std::endl;

  return out;
}

std::istream &operator>>(std::istream &in, Locatie &locatie) {
  std::cout << "Nume locatie: ";
  Utils::ReadFromStdin(locatie.m_szNumeLocatie, in);

  std::cout << "Numar maxim locuri: ";
  in >> locatie.m_iNrMaximLocuri;

  std::cout << "Numar maxim randuri: ";
  in >> locatie.m_iNrMaximRanduri;

  return in;
}

std::string Locatie::getNumeLocatie() const { return m_szNumeLocatie; }

int Locatie::getNrMaximLocuri() const { return m_iNrMaximLocuri; }

int Locatie::getNrMaximRanduri() const { return m_iNrMaximRanduri; }

int Locatie::getId() const { return m_iId; }

void Locatie::setNumeLocatie(const char *szNumeLocatie) {
  Utils::ReallocChar(m_szNumeLocatie, szNumeLocatie, true);
}

void Locatie::setNrMaximLocuri(int iNrMaximLocuri) {
  if (iNrMaximLocuri > 0) {
    m_iNrMaximLocuri = iNrMaximLocuri;
  } else {
    std::cout << "Numarul maxim de locuri trebuie sa fie mai mare decat 0!"
              << std::endl;
  }
}

void Locatie::setNrMaximRanduri(int iNrMaximRanduri) {
  if (iNrMaximRanduri > 0) {
    m_iNrMaximRanduri = iNrMaximRanduri;
  } else {
    std::cout << "Numarul maxim de randuri trebuie sa fie mai mare decat 0!"
              << std::endl;
  }
}
