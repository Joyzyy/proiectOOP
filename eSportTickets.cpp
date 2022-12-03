#include "eSportTickets.hpp"

int eSportsTickets::m_iId = 0;

eSportsTickets::eSportsTickets() {
    m_szTipBilet = nullptr;
    m_iNrRand = -1;
    m_iNrLoc = -1;
}

eSportsTickets::eSportsTickets(const char* szTipBilet, Eveniment& oEveniment) {
    Utils::AllocChar(m_szTipBilet, szTipBilet);

    m_oEveniment = &oEveniment;

    bool ok = true;
    for (int i = 0; i < m_oEveniment->getLocatie().getNrMaximRanduri() && ok; i++) {
        for (int j = 0; j < m_oEveniment->getLocatie().getNrMaximLocuri() && ok; j++) {
            if (m_oEveniment->getNrLocuriDisponibile()[i][j] == 1) {
                m_iNrRand = i;
                m_iNrLoc = j;
                m_oEveniment->setOcupaLoc(m_iNrRand, m_iNrLoc);
                ok = false;
            }
        }
    }
}

eSportsTickets::~eSportsTickets() {
    Utils::DeallocChar(m_szTipBilet);
}

int eSportsTickets::getNrLoc() const {
    return m_iNrLoc;
}

int eSportsTickets::getNrRand() const {
    return m_iNrRand;
}

Eveniment* eSportsTickets::getEveniment() const {
    return m_oEveniment;
}
