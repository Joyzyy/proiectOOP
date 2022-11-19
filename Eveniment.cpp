#include "Eveniment.hpp"

int Eveniment::m_iId = 0;

Eveniment::Eveniment() {
    m_iId++;

    m_szNumeEveniment = nullptr;
    m_szData = nullptr;
    m_szOra = nullptr;
    m_szDescriere = nullptr;

    m_iIdEveniment = m_iId;
    m_iNrLocuriDisponibile = -1;
    m_iNrLocuriVandute = -1;
    m_iPretBilet = -1;

    m_oLocatie = new Locatie();
}

Eveniment::Eveniment(const char* szNumeEveniment, const char* szData, const char* szOra, const char* szDescriere, int iNrLocuriDisponibile, int iNrLocuriVandute, int iPretBilet) {
    m_iId++;

    Utils::AllocChar(m_szNumeEveniment, szNumeEveniment);
    Utils::AllocChar(m_szData, szData);
    Utils::AllocChar(m_szOra, szOra);
    Utils::AllocChar(m_szDescriere, szDescriere);

    m_iIdEveniment = m_iId;
    m_iNrLocuriDisponibile = iNrLocuriDisponibile;
    m_iNrLocuriVandute = iNrLocuriVandute;
    m_iPretBilet = iPretBilet;

    m_oLocatie = new Locatie();
}

Eveniment::Eveniment(const char* szNumeEveniment, const char* szData, const char* szOra, const char* szDescriere, int iNrLocuriDisponibile, int iNrLocuriVandute, int iPretBilet, const Locatie& oLocatie) {
    m_iId++;

    Utils::AllocChar(m_szNumeEveniment, szNumeEveniment);
    Utils::AllocChar(m_szData, szData);
    Utils::AllocChar(m_szOra, szOra);
    Utils::AllocChar(m_szDescriere, szDescriere);

    m_iIdEveniment = m_iId;
    m_iNrLocuriDisponibile = iNrLocuriDisponibile;
    if (iNrLocuriDisponibile < oLocatie.getNrMaximLocuri()) {
        m_iNrLocuriDisponibile = oLocatie.getNrMaximLocuri();
    } else {
        m_iNrLocuriDisponibile = iNrLocuriDisponibile;
    }

    iNrLocuriDisponibile < oLocatie.getNrMaximLocuri()
    || iNrLocuriDisponibile < 0 ?
        m_iNrLocuriDisponibile = oLocatie.getNrMaximLocuri() :
        m_iNrLocuriDisponibile = iNrLocuriDisponibile;

    m_iNrLocuriVandute = iNrLocuriVandute;
    m_iPretBilet = iPretBilet;

    m_oLocatie = new Locatie(oLocatie);
}

Eveniment::Eveniment(const Eveniment& ev) {
    m_iIdEveniment++;

    Utils::AllocChar(m_szNumeEveniment, ev.m_szNumeEveniment);
    Utils::AllocChar(m_szData, ev.m_szData);
    Utils::AllocChar(m_szOra, ev.m_szOra);
    Utils::AllocChar(m_szDescriere, ev.m_szDescriere);

    m_iIdEveniment = ev.m_iIdEveniment;
    m_iNrLocuriDisponibile = ev.m_iNrLocuriDisponibile;
    m_iNrLocuriVandute = ev.m_iNrLocuriVandute;
    m_iPretBilet = ev.m_iPretBilet;

    m_oLocatie = ev.m_oLocatie;
}

Eveniment::~Eveniment() {
    Utils::DeallocChar(m_szNumeEveniment);
    Utils::DeallocChar(m_szData);
    Utils::DeallocChar(m_szOra);
    Utils::DeallocChar(m_szDescriere);
    delete m_oLocatie;
}

Eveniment& Eveniment::operator=(const Eveniment& ev) {
    if (this != &ev) {
        Utils::ReallocChar(m_szNumeEveniment, ev.m_szNumeEveniment);
        Utils::ReallocChar(m_szData, ev.m_szData);
        Utils::ReallocChar(m_szOra, ev.m_szOra);
        Utils::ReallocChar(m_szDescriere, ev.m_szDescriere);

        m_iNrLocuriDisponibile = ev.m_iNrLocuriDisponibile;
        m_iNrLocuriVandute = ev.m_iNrLocuriVandute;
        m_iPretBilet = ev.m_iPretBilet;

        m_oLocatie = ev.m_oLocatie;
    } else {
        std::cout << "Self assignment!" << std::endl;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Eveniment& ev) {
    out << "ID: " << ev.m_iIdEveniment << std::endl;

    (ev.m_szNumeEveniment != nullptr ? (
        out << "Nume eveniment: " << ev.m_szNumeEveniment << std::endl
    ) : (
        out << "Nume eveniment: " << "N/A" << std::endl
    ));

    (ev.m_szData != nullptr ? (
        out << "Data: " << ev.m_szData << std::endl
    ) : (
        out << "Data: " << "N/A" << std::endl
    ));

    (ev.m_szOra != nullptr ? (
        out << "Ora: " << ev.m_szOra << std::endl
    ) : (
        out << "Ora: " << "N/A" << std::endl
    ));

    (ev.m_szDescriere != nullptr ? (
        out << "Descriere: " << ev.m_szDescriere << std::endl
    ) : (
        out << "Descriere: " << "N/A" << std::endl
    ));

    out << "Locuri disponibile: " << ev.m_iNrLocuriDisponibile << std::endl;
    out << "Locuri vandute: " << ev.m_iNrLocuriVandute << std::endl;
    out << "Pret bilet: " << ev.m_iPretBilet << std::endl;

    out << *ev.m_oLocatie;

    return out;
}