#include "eSportTickets.hpp"
#include <stdlib.h>

int eSportsTickets::iCount = 0;

eSportsTickets::eSportsTickets() : m_iId((uintptr_t)this) {
    m_szTipBilet = nullptr;
    m_iNrRand = -1;
    m_iNrLoc = -1;
    m_oEveniment = nullptr;
}

eSportsTickets::eSportsTickets(Eveniment& oEveniment) : m_iId((uintptr_t)this) {
    m_szTipBilet = nullptr;
    m_iNrRand = -1;
    m_iNrLoc = -1;
    m_oEveniment = &oEveniment;
}

eSportsTickets::eSportsTickets(const char* szTipBilet, Eveniment& oEveniment) : m_iId((uintptr_t)this) {
    Utils::AllocChar(m_szTipBilet, szTipBilet);

    m_oEveniment = &oEveniment;

    if (strcmp(szTipBilet, "NORMAL") == 0) {
        bool ok = true;
        for (int i = 0; ok && i < oEveniment.getLocatie().getNrMaximRanduri(); ++i)
            for (int j = 0; ok && j < oEveniment.getLocatie().getNrMaximLocuri(); ++j)
                if (oEveniment.getNrLocuriDisponibile()[i][j] == 1) {
                    m_iNrRand = i;
                    m_iNrLoc = j;
                    oEveniment.setOcupaLoc(i, j);
                    ok = false;
                }
    } if (strcmp(szTipBilet, "VIP") == 0) {
        bool ok = true;
        for (int i = oEveniment.getLocatie().getNrMaximRanduri() - 1; ok && i > oEveniment.getLocatie().getNrMaximRanduri() - 3; --i) {
            for (int j = 0; j < oEveniment.getLocatie().getNrMaximLocuri() && ok; ++j) {
                if (oEveniment.getNrLocuriDisponibile()[i][j] == 1) {
                    m_iNrRand = i;
                    m_iNrLoc = j;
                    oEveniment.setOcupaLoc(i, j);
                    ok = false;
                }
            }
        }
    }
}

eSportsTickets::eSportsTickets(const eSportsTickets& tickets) : m_iId((uintptr_t)this) {
    Utils::AllocChar(m_szTipBilet, tickets.m_szTipBilet);
    m_iNrRand = tickets.m_iNrRand;
    m_iNrLoc = tickets.m_iNrLoc;
    m_oEveniment = tickets.m_oEveniment;
}

eSportsTickets::~eSportsTickets() {
    Utils::DeallocChar(m_szTipBilet);
}

eSportsTickets& eSportsTickets::operator=(const eSportsTickets& tickets) {
    if (this != &tickets) {
        Utils::ReallocChar(m_szTipBilet, tickets.m_szTipBilet);
        m_iNrRand = tickets.m_iNrRand;
        m_iNrLoc = tickets.m_iNrLoc;
        m_oEveniment = tickets.m_oEveniment;
    } else {
        std::cout << "[ERROR] Auto-assign\n";
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const eSportsTickets& tickets) {
    out << "ID ticket: " << tickets.m_iId << std::endl;

    (tickets.m_oEveniment != nullptr ? (
        out << "Eveniment:\n\t" << *tickets.m_oEveniment << std::endl
    ) : (
        out << "Eveniment:\n\t" << "N/A" << std::endl
    ));

    out << "Tip bilet: " << tickets.m_szTipBilet << std::endl;
    out << "Numar loc: " << tickets.m_iNrLoc << std::endl;
    out << "Numar rand: " << tickets.m_iNrRand << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, eSportsTickets& tickets) {
    int tipBilet;
    std::cout << "****************** eSportsTickets ******************" << std::endl;
    std::cout << "------------ Bilet pentru evenimentul ------------" << std::endl;
    std::cout << "------------ " << tickets.m_oEveniment->getNumeEveniment() << " ------------" << std::endl;
    std::cout << "--- Alegeti tipul biletului: " << std::endl;
    std::cout << '\t' << "1. VIP" << std::endl;
    std::cout << '\t' << "2. NORMAL" << std::endl;
    std::cout << "Alegere: ";
    in >> tipBilet;

    switch (tipBilet) {
    case 1:
        Utils::AllocChar(tickets.m_szTipBilet, "VIP");
        break;
    case 2:
        Utils::AllocChar(tickets.m_szTipBilet, "NORMAL");
        break;
    default:
        break;
    }

    system("cls");
    
    std::cout << "****************** eSportsTickets ******************" << std::endl;
    std::cout << "------------ Bilet pentru evenimentul ------------" << std::endl;
    std::cout << "------------ " << tickets.m_oEveniment->getNumeEveniment() << " ------------" << std::endl;
    std::cout << "------------ Tichet tip" << tickets.getTipBilet() << " ------------" << std::endl;
    std::cout << "Locuri libere pentru " << tickets.getTipBilet() << std::endl;
    
    int nrLoc, nrRand;
    if (strcmp(tickets.getTipBilet(), "VIP") == 0) {
        for (int i = tickets.m_oEveniment->getLocatie().getNrMaximRanduri() - 1; i > tickets.m_oEveniment->getLocatie().getNrMaximRanduri() - 3; --i, printf("\n")) {
            std::cout << '\t';
            for (int j = 0; j < tickets.m_oEveniment->getLocatie().getNrMaximLocuri(); ++j) {
                std::cout << (tickets.m_oEveniment->getNrLocuriDisponibile()[i][j] == 0 ? "I" : "D") << "\t";
            }
        }
        std::cout << "Alege numarul locului dorit: ";
        in >> nrLoc;
    }

    system("pause");

    return in;
}

const char* eSportsTickets::getTipBilet() {
    return (m_szTipBilet != nullptr ? m_szTipBilet : "NONE");
}

int eSportsTickets::getNrLoc() const {
    return m_iNrLoc;
}

int eSportsTickets::getNrRand() const {
    return m_iNrRand;
}

int eSportsTickets::getId() const {
    return m_iId;
}

Eveniment* eSportsTickets::getEveniment() const {
    return m_oEveniment;
}
