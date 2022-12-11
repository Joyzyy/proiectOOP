#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "Tichet.hpp"

int main() {
    Eveniment ev2("LOL Championship", "Finala LOL", 250, Locatie("Arena Nationala", 10, 10));
    Tichet tichet(ev2);

    std::cin >> tichet;

    std::cout << tichet;
}