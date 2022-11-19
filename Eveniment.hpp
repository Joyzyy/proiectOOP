class Eveniment {
public:
    Eveniment();
    ~Eveniment();

private:
    static int m_iIdEveniment;
    char* m_szNumeEveniment;
    char* m_szData;
    char* m_szOra;
    char* m_szDescriere;
    int m_iNrLocuriDisponibile;
    int m_iNrLocuriVandute;
    int m_iPretBilet;
    Locatie m_oLocatie;
    
    friend class eSportTickets;
};