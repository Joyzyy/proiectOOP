#include "Tichet.hpp"

Tichet::Tichet(Eveniment& oEveniment) : m_iId((uintptr_t)this) {
  Utils::AllocChar(m_szTipBilet, "N/A");
  m_iNrRand = m_iNrLoc = -1;
  m_oEveniment = &oEveniment;
}

Tichet::Tichet(const char* szTipBilet, Eveniment& oEveniment) : m_iId((uintptr_t)this) {
  Utils::AllocChar(m_szTipBilet, szTipBilet);

  m_oEveniment = &oEveniment;

  auto fcTipBiletNormal = [&](int &iNrRand, int &iNrLoc) -> void {
    bool ok = true;
    for (int i = 0; ok && i < oEveniment.getLocatie().getNrMaximRanduri(); ++i)
      for (int j = 0; ok && j < oEveniment.getLocatie().getNrMaximLocuri(); ++j)
        if (oEveniment.getNrLocuriDisponibile()[i][j] == 1) {
          iNrRand = i;
          iNrLoc = j;
          oEveniment.setOcupaLoc(i, j);
          ok = false;
        }
  };

  auto fcTipBiletVIP = [&](int &iNrRand, int &iNrLoc) -> void {
    bool ok = true;
    for (int i = oEveniment.getLocatie().getNrMaximRanduri() - 1; ok && i > oEveniment.getLocatie().getNrMaximRanduri() - 3; --i)
      for (int j = 0; j < oEveniment.getLocatie().getNrMaximLocuri() && ok; ++j)
        if (oEveniment.getNrLocuriDisponibile()[i][j] == 1) {
          iNrRand = i;
          iNrLoc = j;
          oEveniment.setOcupaLoc(i, j);
          ok = false;
        }
  };

  if (strcmp(szTipBilet, "NORMAL") == 0)
    fcTipBiletNormal(m_iNrRand, m_iNrLoc);
  else if (strcmp(szTipBilet, "VIP") == 0)
    fcTipBiletVIP(m_iNrRand, m_iNrLoc);
}

Tichet::Tichet(const Tichet& tichet) : m_iId((uintptr_t)this) {
  Utils::AllocChar(m_szTipBilet, tichet.m_szTipBilet);
  m_iNrRand = tichet.m_iNrRand;
  m_iNrLoc = tichet.m_iNrLoc;
  m_oEveniment = tichet.m_oEveniment;
}

Tichet::~Tichet() {
  Utils::DeallocChar(m_szTipBilet);
  m_oEveniment = nullptr;
}

Tichet& Tichet::operator=(const Tichet& tichet) {
  if (this != &tichet) {
    Utils::ReallocChar(m_szTipBilet, tichet.m_szTipBilet);
    m_iNrRand = tichet.m_iNrRand;
    m_iNrLoc = tichet.m_iNrLoc;
    m_oEveniment = tichet.m_oEveniment;
  } else
    std::cout << "[ERROR] Auto-assign\n";
  
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Tichet& tichet) {
  out << "ID tichet: " << tichet.m_iId << std::endl;
  out << "Eveniment: " << *tichet.m_oEveniment << std::endl;
  out << "Tip bilet: " << tichet.m_szTipBilet << std::endl;
  out << "Numar rand: " << tichet.m_iNrRand << std::endl;
  out << "Numar loc: " << tichet.m_iNrLoc << std::endl;

  return out;
}

std::istream& operator>>(std::istream& in, Tichet& tichet) {
  int tipBilet;
  std::cout << "****************** Tichete ******************" << std::endl;
  std::cout << "------------ Bilet pentru evenimentul ------------" << std::endl;
  std::cout << "------------ " << tichet.m_oEveniment->getNumeEveniment() << " ------------" << std::endl;
  std::cout << "--- Alegeti tipul biletului: " << std::endl;
  std::cout << '\t' << "1. VIP" << std::endl;
  std::cout << '\t' << "2. NORMAL" << std::endl;
  std::cout << "Alegere: ";
  in >> tipBilet;

  switch (tipBilet) {
  case 1:
      Utils::AllocChar(tichet.m_szTipBilet, "VIP");
      break;
  case 2:
      Utils::AllocChar(tichet.m_szTipBilet, "NORMAL");
      break;
  default:
      break;
  }

  system("cls");
  
  std::cout << "****************** Tichete ******************" << std::endl;
  std::cout << "------------ Bilet pentru evenimentul ------------" << std::endl;
  std::cout << "------------ " << tichet.m_oEveniment->getNumeEveniment() << " ------------" << std::endl;
  std::cout << "------------ Tichet tip" << tichet.getTipBilet() << " ------------" << std::endl;
  std::cout << "Locuri libere pentru " << tichet.getTipBilet() << std::endl;
  
  int nrLoc, nrRand;
  if (strcmp(tichet.getTipBilet(), "VIP") == 0) {
      for (int i = tichet.m_oEveniment->getLocatie().getNrMaximRanduri() - 1; i > tichet.m_oEveniment->getLocatie().getNrMaximRanduri() - 3; --i, printf("\n")) {
          std::cout << '\t';
          for (int j = 0; j < tichet.m_oEveniment->getLocatie().getNrMaximLocuri(); ++j) {
              std::cout << (tichet.m_oEveniment->getNrLocuriDisponibile()[i][j] == 0 ? "I" : "D") << "\t";
          }
      }
      std::cout << "Alege numarul locului dorit: ";
      in >> nrLoc;
  }
  
  return in;
}

const char* Tichet::getTipBilet() {
  return m_szTipBilet;
}

int Tichet::getId() const {
  return m_iId;
}

int Tichet::getNrRand() const {
  return m_iNrRand;
}

int Tichet::getNrLoc() const {
  return m_iNrLoc;
}

Eveniment* Tichet::getEveniment() {
  return m_oEveniment;
}