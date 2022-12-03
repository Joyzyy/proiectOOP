#pragma once

#include "Utils.hpp"
#include "Locatie.hpp"
#include "Eveniment.hpp"

class eSportsTickets {
public:
    eSportsTickets();
    eSportsTickets(const char*, Eveniment&);
    ~eSportsTickets();

    int getNrRand() const;
    int getNrLoc() const;
    Eveniment* getEveniment() const;

private:
    static int  m_iId;
    char*       m_szTipBilet;
    int         m_iNrRand;
    int         m_iNrLoc;
    Eveniment*  m_oEveniment;
};