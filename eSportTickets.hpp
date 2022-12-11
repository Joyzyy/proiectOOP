#pragma once

#include "Utils.hpp"
#include "Locatie.hpp"
#include "Eveniment.hpp"

class eSportsTickets {
public:
    eSportsTickets();
    eSportsTickets(Eveniment&);
    eSportsTickets(const char*, Eveniment&);
    eSportsTickets(const eSportsTickets&);
    ~eSportsTickets();

    eSportsTickets& operator=(const eSportsTickets&);
    friend std::ostream& operator<<(std::ostream&, const eSportsTickets&);
    friend std::istream& operator>>(std::istream&, eSportsTickets&);

    const char* getTipBilet();
    int getNrRand() const;
    int getNrLoc() const;
    int getId() const;
    Eveniment* getEveniment() const;

private:
    static int  iCount;
    char*       m_szTipBilet;
    const int   m_iId;
    int         m_iNrRand;
    int         m_iNrLoc;
    Eveniment*  m_oEveniment;
};