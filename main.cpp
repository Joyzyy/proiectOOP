#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "eSportTickets.hpp"

int main() {
    eSportsTickets ticket1("eSports", "Bucuresti", "01.01.2020", "VIP", 1, 1);

    std::cout << ticket1.getNumeEveniment() << std::endl;

}