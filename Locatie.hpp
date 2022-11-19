class Locatie {
    Locatie();
    ~Locatie();
private:
    static int m_iIdLocatie;
    char* m_szNumeLocatie;
    char* m_szAdresa;
    char* m_szOras;
    char* m_szTara;
    int m_iNrMaximLocuri;
    int m_iNrMaximRanduri;
    int m_iNrMaximEtaje;

    friend class Eveniment;
    friend class eSportTickets;
};