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
  std::string buffer;
  std::cout << "Nume locatie: ";
  std::cin >> buffer;

  locatie.m_szNumeLocatie = new char[buffer.length() + 1];
  strcpy(locatie.m_szNumeLocatie, buffer.c_str());

  std::cout << "Numar maxim locuri: ";
  in >> locatie.m_iNrMaximLocuri;

  std::cout << "Numar maxim randuri: ";
  in >> locatie.m_iNrMaximRanduri;

  return in;
}

void Locatie::SaveToFile(std::ofstream &ofs) {
  ofs.write((char *)&m_iId, sizeof(m_iId));

  int len = strlen(m_szNumeLocatie);
  ofs.write((char *)&len, sizeof(len));
  ofs.write(m_szNumeLocatie, len);

  ofs.write((char *)&m_iNrMaximLocuri, sizeof(m_iNrMaximLocuri));
  ofs.write((char *)&m_iNrMaximRanduri, sizeof(m_iNrMaximRanduri));
}

bool Locatie::LoadFromFile(std::ifstream &ifs) {
  ifs.read((char *)&m_iId, sizeof(m_iId));

  int len;
  ifs.read((char *)&len, sizeof(len));

  m_szNumeLocatie = new char[len + 1];
  ifs.read(m_szNumeLocatie, len);
  m_szNumeLocatie[len] = '\0';

  ifs.read((char *)&m_iNrMaximLocuri, sizeof(m_iNrMaximLocuri));
  ifs.read((char *)&m_iNrMaximRanduri, sizeof(m_iNrMaximRanduri));

  return ifs.good();
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
