#pragma once
#include "Locatie.hpp"
#include "Utils.hpp"
#include <iostream>

class Eveniment {
public:
    Eveniment();
    Eveniment(const char*, const char*, float, const Locatie&);
    Eveniment(const Eveniment&);
    ~Eveniment();

    Eveniment& operator=(const Eveniment&);
    // cast int
    explicit operator int() const;
    // cast float
    explicit operator float() const;
    friend std::ostream& operator<<(std::ostream&, const Eveniment&);
    friend std::istream& operator>>(std::istream&, Eveniment&);

    void setNumeEveniment(const char*);
    void setDetalii(const char*);
    void setOcupaLoc(int, int);
    void setPretBilet(float);
    void setLocatie(const Locatie&);

    const char* getNumeEveniment() const;
    const char* getDetalii() const;
    int getIDEveniment() const;
    int** getNrLocuriDisponibile() const;
    float getPretBilet() const;
    const Locatie& getLocatie() const;
    const Eveniment& getCurrentObject() const;

    static int  m_iId;
private:
    char*       m_szNumeEveniment;
    char*       m_szDetalii;
    int         m_iIdEveniment;
    int**       m_iNrLocuriDisponibile;
    float       m_flPretBilet;
    Locatie*    m_oLocatie;
};