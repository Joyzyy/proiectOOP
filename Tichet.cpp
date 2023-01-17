#include "Tichet.hpp"
#include <Python.h>

Tichet::Tichet() : m_iId((std::uintptr_t)this) {
  Utils::AllocChar(m_szTipBilet, "N/A");
  m_iNrRand = m_iNrLoc = -1;
  m_oEveniment = nullptr;
}

Tichet::Tichet(const Eveniment &oEveniment) : m_iId((std::uintptr_t)this) {
  Utils::AllocChar(m_szTipBilet, "N/A");
  m_iNrRand = m_iNrLoc = -1;
  m_oEveniment = (Eveniment *)(&oEveniment);
}

Tichet::Tichet(const char *szTipBilet, Eveniment &oEveniment)
    : m_iId((std::uintptr_t)this) {
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
    for (int i = oEveniment.getLocatie().getNrMaximRanduri() - 1;
         ok && i > oEveniment.getLocatie().getNrMaximRanduri() - 3; --i)
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

Tichet::Tichet(const Tichet &tichet) : m_iId(tichet.m_iId) {
  Utils::AllocChar(m_szTipBilet, tichet.m_szTipBilet);
  m_iNrRand = tichet.m_iNrRand;
  m_iNrLoc = tichet.m_iNrLoc;
  m_oEveniment = tichet.m_oEveniment;
}

Tichet::~Tichet() {
  Utils::DeallocChar(m_szTipBilet);
  m_oEveniment = nullptr;
}

Tichet &Tichet::operator=(const Tichet &tichet) {
  if (this != &tichet) {
    Utils::ReallocChar(m_szTipBilet, tichet.m_szTipBilet);
    m_iNrRand = tichet.m_iNrRand;
    m_iNrLoc = tichet.m_iNrLoc;
    m_oEveniment = tichet.m_oEveniment;
  } else
    std::cout << "[ERROR] Auto-assign\n";

  return *this;
}

bool Tichet::operator==(const Tichet &tichet) { return m_iId == tichet.m_iId; }

bool Tichet::operator!=(const Tichet &tichet) { return m_iId != tichet.m_iId; }

std::ostream &operator<<(std::ostream &out, const Tichet &tichet) {
  out << "ID tichet: " << tichet.m_iId << std::endl;
  out << "Eveniment: \n" << *tichet.m_oEveniment << std::endl;
  out << "Tip bilet: " << tichet.m_szTipBilet << std::endl;
  out << "Numar rand: " << tichet.m_iNrRand + 1 << std::endl;
  out << "Numar loc: " << tichet.m_iNrLoc + 1 << std::endl;

  return out;
}

std::istream &operator>>(std::istream &in, Tichet &tichet) {
  int tipBilet;
  std::cout << "****************** Tichete ******************" << std::endl;
  std::cout << "------------ Bilet pentru evenimentul ------------"
            << std::endl;
  std::cout << "------------ " << tichet.m_oEveniment->getNumeEveniment()
            << " ------------" << std::endl;
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
  std::cout << "------------ Bilet pentru evenimentul ------------"
            << std::endl;
  std::cout << "------------ " << tichet.m_oEveniment->getNumeEveniment()
            << " ------------" << std::endl;
  std::cout << "------------ Tichet tip" << tichet.getTipBilet()
            << " ------------" << std::endl;
  std::cout << "Locuri libere pentru " << tichet.getTipBilet() << std::endl;
  std::cout << "\t[INFO]: D - Disponibil\n\t[INFO]: I - Indisponibil"
            << std::endl;
  std::cout << "\t[CODIFICARE]: [NumarRand, NumarLoc]" << std::endl;

  auto InputLoc = [&](int iRand, int iLoc) -> void {
    std::cout << "Alege numarul randului dorit: ";
    in >> iRand;
    tichet.setRand(iRand - 1);

    std::cout << "Alege numarul locului dorit: ";
    in >> iLoc;
    tichet.setLoc(iLoc - 1);

    tichet.m_oEveniment->setOcupaLoc(tichet.getNrRand(), tichet.getNrLoc());
    std::cout << "Selectia a fost facuta cu succes! Multumim!\n" << std::endl;
  };

  int nrLoc, nrRand;
  if (strcmp(tichet.getTipBilet(), "VIP") == 0) {
    for (int i = tichet.m_oEveniment->getLocatie().getNrMaximRanduri() - 2;
         i < tichet.m_oEveniment->getLocatie().getNrMaximRanduri();
         ++i, printf("\n")) {
      std::cout << '\t';
      for (int j = 0; j < tichet.m_oEveniment->getLocatie().getNrMaximLocuri();
           ++j) {
        if (tichet.m_oEveniment->getNrLocuriDisponibile()[i][j] == 0) {
          std::cout << "I\t";
        } else {
          std::cout << "D [" << i + 1 << ", " << j + 1 << "]\t";
        }
      }
    }

    InputLoc(nrRand, nrLoc);
  } else if (strcmp(tichet.getTipBilet(), "NORMAL") == 0) {
    for (int i = 0;
         i < tichet.m_oEveniment->getLocatie().getNrMaximRanduri() - 2;
         ++i, printf("\n")) {
      printf("\t");
      for (int j = 0; j < tichet.m_oEveniment->getLocatie().getNrMaximLocuri();
           ++j) {
        if (tichet.m_oEveniment->getNrLocuriDisponibile()[i][j] == 0) {
          std::cout << "I\t";
        } else {
          std::cout << "D [" << i + 1 << ", " << j + 1 << "]\t";
        }
      }
    }

    InputLoc(nrRand, nrLoc);
  }

  return in;
}

bool Tichet::SaveToPDF() {
  PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *pResult;

  Py_Initialize();

  PyObject *sysPath = PySys_GetObject((char *)"path");
  PyList_Append(sysPath, PyUnicode_FromString((char *)"."));

  pName = PyUnicode_FromString((char *)"createPdf");
  pModule = PyImport_Import(pName);

  if (pModule == NULL) {
    PyErr_Print();
    printf("Failed to load");
    return false;
  }

  pDict = PyModule_GetDict(pModule);
  pFunc = PyDict_GetItemString(pDict, (char *)"someFunction");

  if (PyCallable_Check(pFunc)) {
    std::string data = std::to_string(m_iId + 1);
    data += ";";
    data += m_szTipBilet;
    data += ";";
    data += std::to_string(m_iNrRand + 1);
    data += ";";
    data += std::to_string(m_iNrLoc + 1);
    data += ";";
    data += m_oEveniment->getNumeEveniment();
    data += ";";
    data += m_oEveniment->getLocatie().getNumeLocatie();
    pValue = Py_BuildValue("(z)", data.c_str());
    PyErr_Print();
    pResult = PyObject_CallObject(pFunc, pValue);
    PyErr_Print();
  } else {
    PyErr_Print();
    return false;
  }

  Py_DECREF(pValue);
  Py_DECREF(pModule);
  Py_DECREF(pName);

  Py_Finalize();

  return true;
}

void Tichet::SaveToFile(std::ofstream &ofs) {
  ofs.write((char *)&m_iId, sizeof(m_iId));

  int iTipBiletLength = strlen(m_szTipBilet);
  ofs.write((char *)&iTipBiletLength, sizeof(iTipBiletLength));
  ofs.write(m_szTipBilet, iTipBiletLength);

  ofs.write((char *)&m_iNrRand, sizeof(m_iNrRand));
  ofs.write((char *)&m_iNrLoc, sizeof(m_iNrLoc));

  m_oEveniment->SaveToFile(ofs);
}

bool Tichet::LoadFromFile(std::ifstream &ifs) {
  ifs.read((char *)&m_iId, sizeof(m_iId));

  int iLen;
  ifs.read((char *)&iLen, sizeof(iLen));
  m_szTipBilet = new char[iLen + 1];
  ifs.read(m_szTipBilet, iLen);
  m_szTipBilet[iLen] = '\0';

  ifs.read((char *)&m_iNrRand, sizeof(m_iNrRand));
  ifs.read((char *)&m_iNrLoc, sizeof(m_iNrLoc));

  m_oEveniment = new Eveniment();
  m_oEveniment->LoadFromFile(ifs);

  return ifs.good();
}

void Tichet::setRand(int iRand) {
  if (iRand > this->m_oEveniment->getLocatie().getNrMaximRanduri()) {
    std::cout << "[EROARE]: Nr rand introdus ( " << iRand
              << ") este mai mare decat nr. maxim de randuri posibile al "
                 "locatiei ( "
              << this->m_oEveniment->getLocatie().getNrMaximRanduri() << ") !"
              << std::endl;
    return;
  }
  m_iNrRand = iRand;
}

void Tichet::setLoc(int iLoc) {
  if (iLoc > this->m_oEveniment->getLocatie().getNrMaximLocuri()) {
    std::cout << "[EROARE]: Nr loc introdus ( " << iLoc
              << ") este mai mare decat nr. maxim de locuri posibile al "
                 "locatiei ( "
              << this->m_oEveniment->getLocatie().getNrMaximLocuri() << ") !"
              << std::endl;
  }
  m_iNrLoc = iLoc;
}

const char *Tichet::getTipBilet() {
  return m_szTipBilet != nullptr ? m_szTipBilet : "N/A";
}

int Tichet::getId() const { return m_iId; }

int Tichet::getNrRand() const { return m_iNrRand; }

int Tichet::getNrLoc() const { return m_iNrLoc; }

Eveniment *Tichet::getEveniment() { return m_oEveniment; }
