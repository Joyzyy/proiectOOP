#include "Eveniment.hpp"

int Eveniment::m_iId = 0;

Eveniment::Eveniment() {
    m_szNumeEveniment = nullptr;
    m_szDetalii = nullptr;
    m_iNrLocuriDisponibile = nullptr;
    m_iIdEveniment = m_iId++;
    m_flPretBilet = 0;
    m_oLocatie = nullptr;
}

Eveniment::Eveniment(const char* szNumeEveniment, const char* szDetalii, float flPretBilet, const Locatie& oLocatie) {
    Utils::AllocChar(m_szNumeEveniment, szNumeEveniment);
    Utils::AllocChar(m_szDetalii, szDetalii);

    m_iIdEveniment = m_iId++;

    m_iNrLocuriDisponibile = new int*[oLocatie.getNrMaximRanduri()];
    for (int i = 0; i < oLocatie.getNrMaximRanduri(); ++i)
        m_iNrLocuriDisponibile[i] = new int[oLocatie.getNrMaximLocuri()];
    
    for (int i = 0; i < oLocatie.getNrMaximRanduri(); ++i)
        for (int j = 0; j < oLocatie.getNrMaximLocuri(); ++j)
            m_iNrLocuriDisponibile[i][j] = 1;

    m_flPretBilet = flPretBilet;
    m_oLocatie = new Locatie(oLocatie);
}

Eveniment::Eveniment(const Eveniment& ev) {
    Utils::AllocChar(m_szNumeEveniment, ev.m_szNumeEveniment);
    Utils::AllocChar(m_szDetalii, ev.m_szDetalii);

    m_iIdEveniment = m_iId++;

    m_iNrLocuriDisponibile = new int*[ev.m_oLocatie->getNrMaximRanduri()];
    for (int i = 0; i < ev.m_oLocatie->getNrMaximRanduri(); ++i)
        m_iNrLocuriDisponibile[i] = new int[ev.m_oLocatie->getNrMaximLocuri()];
    
    for (int i = 0; i < ev.m_oLocatie->getNrMaximRanduri(); ++i)
        for (int j = 0; j < ev.m_oLocatie->getNrMaximLocuri(); ++j)
            m_iNrLocuriDisponibile[i][j] = ev.m_iNrLocuriDisponibile[i][j];

    m_flPretBilet = ev.m_flPretBilet;
    m_oLocatie = new Locatie(*ev.m_oLocatie);
}

Eveniment::~Eveniment() {
    Utils::DeallocChar(m_szNumeEveniment);
    Utils::DeallocChar(m_szDetalii);
    delete m_oLocatie;
}

Eveniment& Eveniment::operator=(const Eveniment& ev) {
    if (this != &ev) {
        Utils::ReallocChar(m_szNumeEveniment, ev.m_szNumeEveniment);
        Utils::ReallocChar(m_szDetalii, ev.m_szDetalii);
        m_flPretBilet = ev.m_flPretBilet;
        m_oLocatie = new Locatie(*ev.m_oLocatie);
    } else {
        std::cout << "Self assignment!" << std::endl;
    }

    return *this;
}

Eveniment ::operator int() const {
    return m_iIdEveniment;
}

Eveniment ::operator float() const {
    return m_flPretBilet;
}

std::ostream& operator<<(std::ostream& out, const Eveniment& ev) {
    out << "ID: " << ev.m_iIdEveniment << std::endl;

    (ev.m_szNumeEveniment != nullptr ? (
        out << "Nume eveniment: " << ev.m_szNumeEveniment << std::endl
    ) : (
        out << "Nume eveniment: " << "N/A" << std::endl
    ));

    (ev.m_szDetalii != nullptr ? (
        out << "Detalii: " << ev.m_szDetalii << std::endl
    ) : (
        out << "Detalii: " << "N/A" << std::endl
    ));

    if (ev.m_oLocatie != nullptr) {
        out << "Locuri disponibile: \n";
        for (int i = 0; i < ev.m_oLocatie->getNrMaximRanduri(); ++i, printf("\n"))
            for (int j = 0; j < ev.m_oLocatie->getNrMaximLocuri(); ++j, printf("\t"))
                out << (ev.m_iNrLocuriDisponibile[i][j] == 1 ? "D" : "I") << ' ';

        out << *ev.m_oLocatie;
    } else {
        out << "Locatie: " << "N/A" << std::endl;
    }

    return out;
}

void Eveniment::setNumeEveniment(const char* szNumeEveniment) {
    Utils::ReallocChar(m_szNumeEveniment, szNumeEveniment);
}

void Eveniment::setDetalii(const char* szDetalii) {
    Utils::ReallocChar(m_szDetalii, szDetalii);
}

void Eveniment::setOcupaLoc(int iRand, int iLoc) {
    if (iRand < m_oLocatie->getNrMaximRanduri() && iLoc < m_oLocatie->getNrMaximLocuri())
        if (m_iNrLocuriDisponibile[iRand][iLoc] == 1)
            m_iNrLocuriDisponibile[iRand][iLoc] = 0;
        else
            std::cout << "Locul este deja ocupat!" << std::endl;
    else
        std::cout << "Locul nu exista!" << std::endl;
}

void Eveniment::setPretBilet(float flPretBilet) {
    m_flPretBilet = flPretBilet > 0 ? flPretBilet : m_flPretBilet;
}

void Eveniment::setLocatie(const Locatie& oLocatie) {
    if (&oLocatie != nullptr) {
        delete m_oLocatie;
        m_oLocatie = new Locatie(oLocatie);
    }
}

const char* Eveniment::getNumeEveniment() const {
    return m_szNumeEveniment;
}

const char* Eveniment::getDetalii() const {
    return m_szDetalii;
}

int Eveniment::getIDEveniment() const {
    return m_iIdEveniment;
}

int** Eveniment::getNrLocuriDisponibile() const {
    return m_iNrLocuriDisponibile;
}

float Eveniment::getPretBilet() const {
    return m_flPretBilet;
}

const Locatie& Eveniment::getLocatie() const {
    return *m_oLocatie;
}

