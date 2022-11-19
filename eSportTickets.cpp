#include "eSportTickets.hpp"
#include "Utils.hpp"

int eSportsTickets::m_iId = 0;

eSportsTickets::eSportsTickets() {
    m_iId++;
    m_szNumeEveniment = nullptr;
    m_szLocatie = nullptr;
    m_szData = nullptr;
    m_szCategorie = nullptr;
    m_iIdTicket = m_iId;
    m_iNumarLoc = -1;
    m_iNumarRand = -1;
}

eSportsTickets::eSportsTickets(const char* szNumeEveniment, const char* szLocatie, const char* szData, const char* szCategorie, int iNumarLoc, int iNumarRand) {
    m_iId++;

    Utils::AllocChar(m_szNumeEveniment, szNumeEveniment);
    Utils::AllocChar(m_szLocatie, szLocatie);
    Utils::AllocChar(m_szData, szData);
    Utils::AllocChar(m_szCategorie, szCategorie);

    m_iIdTicket = m_iId;
    m_iNumarLoc = iNumarLoc;
    m_iNumarRand = iNumarRand;
}

eSportsTickets::eSportsTickets(const eSportsTickets& e) {
    m_iId++;

    Utils::AllocChar(m_szNumeEveniment, e.m_szNumeEveniment);
    Utils::AllocChar(m_szLocatie, e.m_szLocatie);
    Utils::AllocChar(m_szData, e.m_szData);
    Utils::AllocChar(m_szCategorie, e.m_szCategorie);

    m_iIdTicket = m_iId;
    m_iNumarLoc = e.m_iNumarLoc;
    m_iNumarRand = e.m_iNumarRand;
}

eSportsTickets::~eSportsTickets() {
    Utils::DeallocChar(m_szNumeEveniment);
    Utils::DeallocChar(m_szLocatie);
    Utils::DeallocChar(m_szData);
    Utils::DeallocChar(m_szCategorie);
}

eSportsTickets& eSportsTickets::operator=(const eSportsTickets& e) {
    if (this != &e) {
        Utils::ReallocChar(m_szNumeEveniment, e.m_szNumeEveniment);
        Utils::ReallocChar(m_szLocatie, e.m_szLocatie);
        Utils::ReallocChar(m_szData, e.m_szData);
        Utils::ReallocChar(m_szCategorie, e.m_szCategorie);

        m_iNumarLoc = e.m_iNumarLoc;
        m_iNumarRand = e.m_iNumarRand;
    } else {
        std::cout << "Self assignment!" << std::endl;
    }

    return *this;
}

std::string eSportsTickets::getNumeEveniment() const {
    return m_szNumeEveniment;
}

std::string eSportsTickets::getLocatie() const {
    return m_szLocatie;
}

std::string eSportsTickets::getData() const {
    return m_szData;
}

std::string eSportsTickets::getCategorie() const {
    return m_szCategorie;
}

int eSportsTickets::getIdTicket() const {
    return m_iIdTicket;
}

int eSportsTickets::getNumarLoc() const {
    return m_iNumarLoc;
}

int eSportsTickets::getNumarRand() const {
    return m_iNumarRand;
}

std::ostream& operator<<(std::ostream& out, const eSportsTickets& ticket) {
    out << "ID: " << ticket.m_iIdTicket << std::endl;

    (ticket.m_szNumeEveniment != nullptr ? (
        out << "Nume eveniment: " << ticket.m_szNumeEveniment << std::endl
    ) : (
        out << "Nume eveniment: " << "N/A" << std::endl
    ));

    (ticket.m_szLocatie != nullptr ? (
        out << "Locatie: " << ticket.m_szLocatie << std::endl
    ) : (
        out << "Locatie: " << "N/A" << std::endl
    ));

    (ticket.m_szData != nullptr ? (
        out << "Data: " << ticket.m_szData << std::endl
    ) : (
        out << "Data: " << "N/A" << std::endl
    ));

    (ticket.m_szCategorie != nullptr ? (
        out << "Categorie: " << ticket.m_szCategorie << std::endl
    ) : (
        out << "Categorie: " << "N/A" << std::endl
    ));

    (ticket.m_iNumarLoc != -1 ? (
        out << "Numar loc: " << ticket.m_iNumarLoc << std::endl
    ) : (
        out << "Numar loc: " << "N/A" << std::endl
    ));

    (ticket.m_iNumarRand != -1 ? (
        out << "Numar rand: " << ticket.m_iNumarRand << std::endl
    ) : (
        out << "Numar rand: " << "N/A" << std::endl
    ));

    return out;
}

std::istream& operator>>(std::istream& in, eSportsTickets& ticket) {
    std::cout << "Nume eveniment: ";
    Utils::ReadFromStdin(ticket.m_szNumeEveniment, in);

    std::cout << "Locatie: ";
    Utils::ReadFromStdin(ticket.m_szLocatie, in);

    std::cout << "Data: ";
    Utils::ReadFromStdin(ticket.m_szData, in);

    std::cout << "Categorie: ";
    Utils::ReadFromStdin(ticket.m_szCategorie, in);

    std::cout << "Numar loc: ";
    in >> ticket.m_iNumarLoc;

    std::cout << "Numar rand: ";
    in >> ticket.m_iNumarRand;

    return in;
}