#pragma once
#include "Locatie.hpp"
#include "Utils.hpp"
#include <iostream>

class Eveniment {
public:
    Eveniment();
    Eveniment(const char*, const char*, int, int, int);
    Eveniment(const char*, const char*, int, int, int, const Locatie&);
    Eveniment(const Eveniment&);
    ~Eveniment();

    Eveniment& operator=(const Eveniment&);
    friend std::ostream& operator<<(std::ostream&, const Eveniment&);
    friend std::istream& operator>>(std::istream&, Eveniment&);

private:
    static int m_iId;
    char* m_szNumeEveniment;
    char* m_szDetalii;
    int m_iIdEveniment;
    int** m_iNrLocuriDisponibile;
    int* m_iNrLocuriVandute;
    int m_iPretBilet;
    Locatie* m_oLocatie;
};